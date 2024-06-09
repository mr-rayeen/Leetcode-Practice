class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //  Approach 1: Brute force TC: O(n^3)
        // int count = 0;
        // int n = nums.size();

        // for(int i = 0; i<n; i++){    // Ye n time lega
        //     int sum = nums[i];
        //     if(abs(sum)%k == 0){
        //             count++;
        //         }
        //     for(int j = i+1; j<n; j++){  // Ye n time lega
        //         sum += nums[j];      // Ye n time lega
        //         if(abs(sum)%k == 0){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        ////////////////////////////////////////////////////////

        // Approach 2: Brute force TC: O(n^2)
        //  Yaha par hum commulative sum nikalenge
        //  matlb sum karke ussi array me store kar lenge
        //  [4,5,0,-2,-3,1]
        //  Cummulative sum array : [4,9,9,7,4,5]

        // int count = 0;
        // int n = nums.size();

        // for(int i = 1; i<n; i++){
        //     nums[i] += nums[i-1];
        // }

        // for(int i = 0; i<n; i++){
            
        //     for(int j = i; j<n; j++){
                
        //         //  Yaha hum sum nikal rhe hai i se j tak ka 
        //         //  [4,9,9, 7, 4,5] --> Sum array hai
        //         //  [4,5,0,-2,-3,1] --> Original array
        //         //     i       j
        //         int sum = (i == 0)? nums[j] : nums[j] - nums[i-1];
                
        //         if(abs(sum)%k == 0){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        ////////////////////////////////////////////////////////

        //  Approach 3: Using Hashmap TC = O(n);
        //  Isme Humne Modulo ka concept lagaya hai
        //  Isme hum remainder or uske count ko store karenge map me

        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;

        mp[sum] = 1;

        int result = 0;

        for(int i = 0; i<n; i++){
            sum += nums[i];

            int remainder = sum % k;

            //  Jab remainder -ve hoga toh usme hum k ko add kar denge
            if(remainder < 0){
                remainder += k;
            }
            //  Agar remainder map me nahi hai to store karenge
            if(mp.find(remainder) != mp.end()){
                result += mp[remainder];
            }
            //  Fir uska count badhaenge
            mp[remainder]++;
        }
        return result;
    }
};