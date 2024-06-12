class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;

        for(auto num : nums){
            mp[num]++;
        }
        
        int i = 0;
        for(auto &num : mp){
            while(num.second--){
                nums[i] = num.first;
                i++;
            }
        }
    }
};