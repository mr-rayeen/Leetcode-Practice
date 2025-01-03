class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        for(int x : nums){
            sum += x;
        }

        int count=0;
        long long leftSum = 0;
        long long rightSum = 0;

        for(int i = 0; i < n-1; i++){
            leftSum += nums[i];
            rightSum = sum - leftSum;
            if(leftSum >= rightSum){
                count++;
            }
        }
        return count;
    }
};