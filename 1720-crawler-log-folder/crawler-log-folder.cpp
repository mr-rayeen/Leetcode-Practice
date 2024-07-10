class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;

        for(auto &log:logs){
            if(log == "./"){
                continue;
            }else if(log =="../"){
                steps = max(0,steps - 1);
            }else{
                steps = steps + 1;
            }
        }
        return steps;
    }
};