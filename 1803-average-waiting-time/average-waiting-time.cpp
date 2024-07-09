class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        double TotalWaiting = 0;
        int currTime = 0;

        for(auto &vec : customers){
            int arrivalTime = vec[0];
            int cookTime = vec[1];

            if(arrivalTime > currTime) currTime = arrivalTime;

            int waitTime = currTime + cookTime - arrivalTime;

            TotalWaiting += waitTime;
            currTime += cookTime;
        }

        return TotalWaiting/n;
    }
};