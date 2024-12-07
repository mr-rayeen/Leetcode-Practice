class Solution {
public:
   /**
 * Checks if it's possible to make all numbers in the array less than or equal to 'mid' 
 * with the given number of operations 'maxOps'.
 * 
 *  nums The input array of numbers.
 *  maxOps The maximum number of operations allowed.
 *  mid The target maximum value for the numbers in the array.
 *  return True if it's possible to make all numbers less than or equal to 'mid' with 'maxOps', false otherwise.
 */
bool isPossible(vector<int>& nums, int maxOps, int mid) {
    int totalOps = 0; // Total number of operations required to bring each number <= mid

    // Iterate over each number in the array
    for(int &num : nums) {
        // Calculate the number of operations required to bring 'num' <= 'mid'
        int ops = num / mid;

        // If 'num' is a multiple of 'mid', we need one less operation
        if(num % mid == 0) {
            ops -= 1;
        }

        // Add the operations required for 'num' to the total operations
        totalOps += ops;
    }

    // Return true if the total operations required is less than or equal to 'maxOps', false otherwise
    return totalOps <= maxOps;
}

/**
 * Finds the minimum size of the array such that all numbers can be made less than or equal to 
 * the minimum size with the given number of operations.
 * 
 *  nums The input array of numbers.
 *  maxOperations The maximum number of operations allowed.
 *  The minimum size of the array.
 */
int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1; // Lower bound for the binary search
    int r = *max_element(begin(nums), end(nums)); // Upper bound for the binary search
    
    int result = r; // Initialize the result with the upper bound

    // Perform binary search to find the minimum size
    // Time complexity: O(n * log(MAX))
    while(l <= r) {
        int mid = l + (r-l)/2; // Calculate the mid value for the current range

        // Check if it's possible to make all numbers less than or equal to 'mid' with 'maxOperations'
        if(isPossible(nums, maxOperations, mid) == true) {
            // If possible, update the result and move the upper bound to 'mid-1'
            result = mid;
            r = mid-1;
        } else {
            // If not possible, move the lower bound to 'mid+1'
            l = mid+1;
        }
    }

    // Return the minimum size found
    return result;
}
};