class Solution {
public:
    bool isSubsequence(string s, string t) {
        // int i =0, j = 0;

      

        // while(i < s.size() && j < s.size()){
        //     if(s[i] == t[j]){
        //         i++;
        //     }
        //     j++;
        // }
       
        // return s.size() == i;
        int sLength = s.size(), tLength = t.size(); // Store lengths of both strings.
        int sIndex = 0, tIndex = 0; // Initialize indices for both strings.

        // Loop through both strings.
        for (; sIndex < sLength && tIndex < tLength; ++tIndex) {
            // If characters match, move to the next character in 's'.
            if (s[sIndex] == t[tIndex]) {
                ++sIndex;
            }
        }

        // If we have gone through the entire 's' string, it is a subsequence of 't'.
        return sIndex == sLength;
    }
};