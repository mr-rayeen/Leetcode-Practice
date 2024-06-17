class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        // Approach 1: Brute force
        int results = 0;

        for(int i = 0; i<hours.size(); i++){

            for(int j = i + 1; j<hours.size(); j++){

                int day = hours[i] + hours[j];

                if(day%24 == 0){
                    results++;
                }

            }
        }
        return results;


    }
};