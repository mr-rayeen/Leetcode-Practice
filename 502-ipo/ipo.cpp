class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size(); // Number of projects

    vector<pair<int, int>> vec(n); // Vector to store projects with their capital requirements and profits

    for(int i = 0; i < n; i++){
        vec[i] = {capital[i], profits[i]}; // Fill the vector with project details
    }

    sort(begin(vec), end(vec)); // Sort the vector based on capital requirements

    int i = 0; // Initialize index for iterating through the sorted vector

    priority_queue<int> pq; // Max-priority queue to store profits of feasible projects

    while(k--){ // While there are projects left to select
        while(i < n && vec[i].first <= w){ // Find projects that can be started with current capital
            pq.push(vec[i].second); // Add the profit of the project to the priority queue
            i++; // Move to the next project
        }

        if(pq.empty()) break; // If no more projects can be started, break the loop

        w += pq.top(); // Select the project with the highest profit and add its profit to the total capital
        pq.pop(); // Remove the selected project from the priority queue
    }
    return w; // Return the final maximized capital
}

};