class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        // Define the maximum possible profit
    const int mxProfit = 100000;
    
    // Use a bitset to represent the current profit states
    bitset<mxProfit + 1> currentProfit;
    
    // Initialize the bitset to indicate that a profit of 0 is possible
    currentProfit[0] = 1;

    // Sort the reward values to process them in ascending order
    sort(rewardValues.begin(), rewardValues.end());

    // Process each reward value
    for(int i = 0; i < rewardValues.size(); i++) {
        // Calculate the shift amount based on the current reward value
        int x = (mxProfit - (rewardValues[i] - 1));

        // Perform bitwise operations to update the current profit states
        currentProfit |= (currentProfit << x >> x << rewardValues[i]);
    }

    // Search backward through the bitset to find the highest profit achieved
    for(int profit = mxProfit; profit >= 0; profit--) {
        // If a profit of 'profit' is achievable, return it
        if(currentProfit[profit]) return profit;
    }

    // If no profitable combination is found, return -1
    return -1;


    //Explanation:
//     Bitset Usage: A bitset named currentProfit is used to represent the current state of profits that can be achieved. Each bit in the bitset corresponds to a potential profit level, and setting a bit indicates that achieving that profit level is possible.
// Initialization: The bitset is initialized with currentProfit[0] = 1 to indicate that achieving a profit of 0 is always possible.
// Sorting Rewards: The rewardValues array is sorted to ensure that smaller rewards are considered first, allowing for more flexibility in choosing larger rewards later.
// Processing Rewards: For each reward value, the code calculates a shift amount x based on the reward value. This shift amount determines how much the bitset needs to be shifted to incorporate the current reward value into the calculation of possible profits.
// Bitwise Operations: The core of the solution lies in the bitwise operations performed within the loop. These operations dynamically update the bitset to reflect the cumulative effect of including the current reward value in the total reward. Specifically, (currentProfit << x >> x) shifts the bits in currentProfit by x positions to the left and then back to the right by x positions, effectively incorporating the current reward value into the consideration of possible profits.
// Finding Maximum Profit: After processing all reward values, the code searches backward through the bitset to find the highest profit level that is marked as achievable. This is done by iterating from mxProfit down to 0 and checking if currentProfit[profit] is set, indicating that achieving a profit of profit is possible.
// Returning Result: If a profitable combination is found, the corresponding profit level is returned. If no profitable combinations are found, -1 is returned to indicate failure.
// This solution cleverly uses bitwise operations to efficiently explore all possible combinations of rewards, ensuring that the maximum total reward is calculated accurately and efficiently.
    }
};