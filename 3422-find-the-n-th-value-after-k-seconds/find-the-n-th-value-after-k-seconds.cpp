class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector <int> arr(n, 1);
        int mod = 1e9 + 7;

        while(k--){
            int curr = 0;
            for(int j = 0; j<n; j++){
                curr += arr[j];
                curr = curr % mod;
                arr[j] = curr;
            }
        }

        return arr[n-1];
    }
};