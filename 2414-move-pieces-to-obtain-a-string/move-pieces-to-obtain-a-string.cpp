class Solution {
public:
    bool canChange(string start, string target) {
    int n = start.length(); // Get the length of the strings
    int i = 0; // Pointer for the start string
    int j = 0; // Pointer for the target string

    // Loop until we have processed all characters in both strings
    while(i < n || j < n) {
        // Move the pointer i to the next non-blank character in start
        while(i < n && start[i] == '_') {
            i++;
        }

        // Move the pointer j to the next non-blank character in target
        while(j < n && target[j] == '_') {
            j++;
        }

        // If we reach the end of either string, check if both are at the end
        if(i == n || j == n) {
            return i == n && j == n; // Both must be at the end to be valid
        }

        // If the characters at the current positions do not match, return false
        if(start[i] != target[j]) {
            return false;
        }

        // If the current character is 'L', it can only move left, so check positions
        if(start[i] == 'L' && i < j) {
            return false; // 'L' cannot move to the right
        }

        // If the current character is 'R', it can only move right, so check positions
        if(start[i] == 'R' && i > j) {
            return false; // 'R' cannot move to the left
        }

        // Move to the next characters in both strings
        i++;
        j++;
    }

    // If we successfully matched all characters, return true
    return true;
}
};