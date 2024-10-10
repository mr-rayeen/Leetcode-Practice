class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxIndex) return false;

            // [2,3,1,1,4]
            //  0 1 2 3 4


            maxIndex = max(maxIndex, i+nums[i]);
        }
        return true;
    }
};