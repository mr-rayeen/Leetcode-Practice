class RecentCounter {
private:
    queue<int> q; // Queue to store timestamps of requests

public:
    RecentCounter() {
        // Constructor initializes the counter with an empty queue
    }

    int ping(int t) {
        // Calculate the start of the 3000ms window
        int ti = t - 3000;
        
        // Push the current timestamp onto the queue
        q.push(t);
        
        // Remove timestamps from the front of the queue that are older than the start of the 3000ms window
        while (!q.empty() && q.front() < ti) {
            q.pop();
        }
        
        // Return the number of requests in the current 3000ms window
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */