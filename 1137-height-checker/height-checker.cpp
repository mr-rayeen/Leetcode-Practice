class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        
        int result = 0;
        for(int x : heights)  expected.push_back(x);
        sort(expected.begin(),expected.end());
        for(int i = 0; i<heights.size(); i++){
            if(heights[i] != expected[i])   result++;
            // for(int j = 0; j<heights.size(); j++){
                
            // }
        }
        return result;
    }
};