class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i],i});
        }

        while(k--){
            pair<int, int> x = pq.top();
            int min = x.first;
            min = min*multiplier;
            pair<int, int> updated;
            updated.first = min;
            updated.second = x.second;
            nums[updated.second] = updated.first;
            pq.pop();
            pq.push(updated);

        }

        return nums;

    }
};