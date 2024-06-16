class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {

        // This question is similar to 330. Patching Array

        int patch = 0; 
        int i = 0; 
        long long int maxReach = 0; 
        sort(begin(coins), end(coins));

        while(maxReach < target){ 
            if(i < coins.size() && coins[i] <= maxReach+1){ 
                maxReach += coins[i]; 
                i++; 
            } else{ 
                maxReach += (maxReach + 1); 
                patch++; 
            }
        }

        return patch;
    }
};