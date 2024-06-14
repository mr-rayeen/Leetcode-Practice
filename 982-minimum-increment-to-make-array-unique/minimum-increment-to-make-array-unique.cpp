class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        //  This question is same as Q. 1827 
        
        sort(nums.begin(), nums.end());

        int moves = 0;

        for(int i = 1; i<nums.size(); i++){

            if(nums[i] <= nums[i-1]){
                int move = nums[i-1] - nums[i] + 1;
                nums[i] += move;
                moves += move;
            }
        }
        return moves;
    }
};