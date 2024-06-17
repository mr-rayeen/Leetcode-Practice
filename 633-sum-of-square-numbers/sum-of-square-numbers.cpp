#define long long ll
class Solution {
public:
    bool judgeSquareSum(int c) {
    // Create an unordered map to store the squares of numbers
    unordered_map<int, int> mp;

    // Iterate from 0 to the square root of c
    for(int i = 0; i <= sqrt(c); i++){
        // Store the square of i in the map
        mp[i*i]++;

        // Calculate the remaining value b = c - i*i
        int b = c - i*i;

        // Check if b is already in the map
        if(mp[b]) {
            // If b is in the map, it means we found two integers a and b such that a^2 + b^2 = c
            return true;
        }
    }
    
    // If we didn't find any such pair, return false
    return false;
}
};