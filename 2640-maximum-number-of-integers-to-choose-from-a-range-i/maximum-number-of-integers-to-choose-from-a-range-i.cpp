class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;
        int sum = 0;

        for(int i = 1; i <= n; i++ ){
            auto it = find(banned.begin(), banned.end(), i);
            if(it == banned.end()){
                if(sum + i <= maxSum){
                    sum += i;
                    count++;
                }else{
                    break;
                }
            }
        }

        return count;
    }
};