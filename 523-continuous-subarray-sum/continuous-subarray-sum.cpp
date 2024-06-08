class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //  Approach 1:
        //  This is direct brute force gives TLE. TC: O(n^2).
        // for(int i = 0; i < nums.size(); i++){
        //     int sum = nums[i];
        //     for(int j = i+1; j< nums.size(); j++){
        //         sum += nums[j];
        //         if(sum % k == 0){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        //  Approach 2:
        //  Isme hum modulo ka concept lagaenge
        int n = nums.size();

        unordered_map<int, int> mp;

        mp[0]=-1;
        int sum = 0;

        if(n < 2) return false;

        for(int i = 0; i<n; i++){
            sum += nums[i];

            int remainder = sum%k;

            //  Check karo remainder pahele se hi map me hai ya nahi
            //  agar nahi hai toh isko hum nahi le sakte question 
            //  me given hai toh fir hum remainder ko as a key 
            //  store karenge current index ko value me store karenge
            if(mp.find(remainder) != mp.end()){
                // Yaha check karo ki subarray is >= 2 hai ya nahi 
                if(i - mp[remainder] >= 2) return true;


            }else{
                    mp[remainder] = i;
                }
        }
        return false;

    }
};