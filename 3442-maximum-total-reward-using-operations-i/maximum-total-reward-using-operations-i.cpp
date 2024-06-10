class Solution {
public:

    // Global variable to store the maximum total reward
int ans = 0;

// Dynamic programming table to avoid recomputation
bool dp[2001][2001];

// Recursive function to calculate the maximum total reward
void calculateMaxReward(int i, int x, vector<int>& rewards) {
    // Base case: Either reached the end of the rewards array or exceeded the maximum reward limit
    if(i == rewards.size() || x >= 2000) {
        ans = max(ans, x); // Update the maximum total reward if necessary
        return;
    }

    // Avoid recomputing the same state
    if(dp[i][x]) return;

    // If the current reward is less than or equal to the current total reward, skip adding it
    if(rewards[i] <= x) {
        calculateMaxReward(i+1, x, rewards); // Move to the next reward without adding the current one
    } else {
        // Otherwise, consider adding the current reward to the total
        calculateMaxReward(i+1, x + rewards[i], rewards); // Add the current reward and move to the next
        calculateMaxReward(i+1, x, rewards); // Also consider moving to the next reward without adding the current one
    }

    // Mark the current state as computed to avoid recomputation
    dp[i][x] = true;
}

// Main function to compute the maximum total reward
int maxTotalReward(vector<int>& rewardValues) {
    // Reset the global variables
    ans = 0;
    memset(dp, 0, sizeof(dp)); // Initialize the dynamic programming table

    // Sort the rewards to process them in increasing order
    sort(rewardValues.begin(), rewardValues.end());

    // Calculate the maximum total reward
    calculateMaxReward(0, 0, rewardValues);

    // Return the maximum total reward
    return ans;

    //  Explanation:
//     Global Variables: ans stores the maximum total reward found so far, and dp is a 2D boolean array used to memoize states to avoid redundant computations.
// Recursive Function calculateMaxReward:
// This function recursively explores all possible ways to select rewards, considering whether to add the current reward to the total or skip it.
// It uses memoization (dp[i][x]) to prevent revisiting the same state, improving efficiency.
// The base cases are reaching the end of the rewards array or exceeding the maximum reward limit (2000 in this case).
// Main Function maxTotalReward:
// Resets ans and initializes dp.
// Sorts the rewardValues to process them in ascending order, allowing for efficient selection based on the current total reward.
// Calls calculateMaxReward starting with the first reward and a total reward of 0.
// Returns the maximum total reward found.
}
};