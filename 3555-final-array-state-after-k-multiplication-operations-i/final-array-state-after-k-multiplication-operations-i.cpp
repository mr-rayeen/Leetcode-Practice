class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for(int i = 0; i < k; i++){
         // Find the minimum element in the array
        auto minIt = min_element(nums.begin(), nums.end());
        *minIt *= multiplier; // Update the minimum element directly
        }

        return nums;

    }
};