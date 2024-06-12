class Solution {
public:
    void sortColors(vector<int>& nums) {
        //    Used Counting sort:
        map<int, int> mp;
        //    Ye humko number of 0's, 1's, 2's. Dedega
        for(auto num : nums){
            mp[num]++;
        }
        //    Yaha map par iterate karenge jitni baar jo aya hoga utni baar usko 
        //    nums me overwrite kar denge
        int i = 0;
        for(auto &num : mp){
            while(num.second--){
                nums[i] = num.first;
                i++;
            }
        }
    }
};
