//Approach-1 (Using sliding window + heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
     typedef pair<int, int> P; // Typedef for pair<int, int> for convenience

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(); // Size of the input array
        priority_queue<P> maxPq; // Max heap to store elements and their indices
        priority_queue<P, vector<P>, greater<P>> minPq; // Min heap to store elements and their indices

        int i = 0; // Start index of the sliding window
        int j = 0; // End index of the sliding window
        int maxLength = 0; // Length of the longest valid subarray

        while (j < n) { // Slide the window
            maxPq.push({nums[j], j}); // Push the current element onto the max heap
            minPq.push({nums[j], j}); // Push the current element onto the min heap

            while (maxPq.top().first - minPq.top().first > limit) { // While the difference exceeds the limit
                i = min(maxPq.top().second, minPq.top().second) + 1; // Adjust the start index of the window

                // Pop elements from the heaps that are outside the adjusted window
                while (maxPq.top().second < i) {
                    maxPq.pop();
                }
                while (minPq.top().second < i) {
                    minPq.pop();
                }
            }

            // Update maxLength with the length of the current valid window
            maxLength = max(maxLength, j - i + 1);
            j++; // Slide the window forward
        }

        return maxLength; // Return the length of the longest valid subarray
    }
};


//Approach-2 (Using sliding window + multiset)
//T.C : O(nlogn)
//S.C : O(n)
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         int n = nums.size(); // Size of the input array

//         multiset<int> st; // Multiset to store elements
//         int i = 0; // Start index of the sliding window
//         int j = 0; // End index of the sliding window
//         int maxLength = 0; // Length of the longest valid subarray

//         while (j < n) { // Slide the window
//             st.insert(nums[j]); // Insert the current element into the multiset

//             while (*st.rbegin() - *st.begin() > limit) { // While the difference between the maximum and minimum elements exceeds the limit
//                 st.erase(st.find(nums[i])); // Remove the element at the start of the window from the multiset
//                 ++i; // Adjust the start index of the window
//             }

//             maxLength = max(maxLength, j - i + 1); // Update maxLength with the length of the current valid window
//             j++; // Slide the window forward
//         }

//         return maxLength; // Return the length of the longest valid subarray
//     }
// };
