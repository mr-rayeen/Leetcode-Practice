class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        //    This Ques is same as 2952. Minimum Number of Coins to be Added
        
        int patch = 0; // Counter for the number of patches added
        int i = 0; // Index to iterate through the array
        long long int maxReach = 0; // Maximum reach of the current sequence of numbers

        while(maxReach < n){ // While the maximum reach is less than n
            if(i < nums.size() && nums[i] <= maxReach+1){ // Check if the current number can be reached by adding it to the sequence
                maxReach += nums[i]; // Update the maximum reach by adding the current number
                i++; // Move to the next number
            } else{ // If the current number cannot be reached by adding it to the sequence
                // Patch number = (maxReach + 1)
                maxReach += (maxReach + 1); // Update the maximum reach by adding the next patch number
                patch++; // Increment the patch counter
            }
        }

        return patch; // Return the minimum number of patches required
    }

//     Working of the Code
// Initialization: The solution initializes counters for the number of patches added (patch), the index to iterate through the array (i), and the maximum reach of the current sequence of numbers (maxReach). The maximum reach represents the largest number that can currently be formed by summing elements in the array.
// Main Loop: The main loop continues until the maximum reach encompasses the target range [1, n]. Inside this loop, the solution checks whether the current number in the array can be reached by adding it to the sequence.
// Adding Numbers: If the current number can be reached by adding it to the sequence, it is added to the maximum reach, and the iteration moves to the next number in the array.
// Patching: If the current number cannot be reached by adding it to the sequence, a patch is added to the maximum reach. This patch is calculated as (maxReach + 1) and represents the smallest number that can be added to the sequence to reach the target range. After adding a patch, the patch counter is incremented.
// Completion: The loop terminates when the maximum reach is greater than or equal to n, meaning the target range [1, n] can be covered by the sum of some elements in the array. The function returns the minimum number of patches required to achieve this.

};
