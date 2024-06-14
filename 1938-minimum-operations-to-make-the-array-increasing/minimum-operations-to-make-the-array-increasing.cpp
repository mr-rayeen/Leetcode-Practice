class Solution {
public:
    int minOperations(vector<int>& nums) {
        int moves = 0;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i-1] >= nums[i]){    
                int move = nums[i-1] - nums[i]; //  Diff nikal rhe hai fir 1 add kar denge isme
                nums[i] += abs(move) + 1;   //  Array ko b update kar rhe hai q ki jab i agye badh jaega toh previous se compare karega next ko
                moves += abs(move) + 1;
            }
            
        }
        return moves;
    }
};