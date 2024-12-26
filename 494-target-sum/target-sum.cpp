class Solution {
public:
    int solve(vector<int>& nums, int target, int i, int currSum, unordered_map<string, int>&mp){
        if(i == nums.size()){
            if(currSum == target){
                return 1; // we found one way to reach target
            }else{
                return 0;
            }
        }

        string key = to_string(i) + "_"+to_string(currSum);

        if(mp.count(key)){
            return mp[key];
        }

        int plus  = solve(nums, target, i+1, currSum + nums[i], mp);
        int minus  = solve(nums, target, i+1, currSum - nums[i], mp);

        return mp[key] = plus + minus; // Total ways to reach Target
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;
        return solve(nums, target, 0, 0, mp);
    }
};