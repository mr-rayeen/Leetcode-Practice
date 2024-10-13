class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort intervals via starting point
        sort(begin(intervals), end(intervals));

        priority_queue<int , vector<int>, greater<int>> pq;

        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if(!pq.empty() && start > pq.top()) {
                pq.pop();
            }

            pq.push(end);
        }

        return pq.size();
    }
};