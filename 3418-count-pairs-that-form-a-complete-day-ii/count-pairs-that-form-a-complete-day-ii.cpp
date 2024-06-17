class Solution {
public:
    #define ll long long // Define long long type alias for convenience

long long countCompleteDayPairs(vector<int>& hours) {
    int n = hours.size(); // Size of the input array
    unordered_map<ll, ll> freq; // Frequency map to store the count of each hour modulo 24
    ll count = 0; // Counter for the number of valid pairs

    for(int j = 0; j < n; j++){ // Iterate through each element in the array
        ll r = hours[j] % 24; // Calculate the remainder when the current hour is divided by 24

        if(r == 0){ // If the remainder is 0, it means the hour is exactly divisible by 24
            count += freq[0]; // Add the count of hours that are multiples of 24 to the total count
        } else { // Otherwise, calculate the count of pairs that can form a complete day with the current hour
            count += freq[24 - r]; // Add the count of hours that, when combined with the current hour, form a complete day
        }
        freq[r]++; // Increment the count of the current hour modulo 24 in the frequency map
    }
    return count; // Return the total count of valid pairs
}


    //  Explanation
//     Frequency Map Initialization: The solution initializes a frequency map freq to keep track of the count of each hour modulo 24. 
//This is done because a complete day is defined as a multiple of 24 hours, so focusing on the remainder when hours are divided by 24 simplifies the calculation.
// Iteration Over Hours: The solution iterates over each hour in the input array. For each hour, it calculates the remainder r when the hour is divided by 24.
// Pair Count Calculation:
// If r is 0, it means the hour is exactly divisible by 24, indicating a full day. In this case, the count of pairs is incremented by the count of hours that are multiples of 24, stored in freq[0].
// If r is not 0, it calculates the count of pairs that can form a complete day with the current hour. This is done by adding the count of hours that, when combined with the current hour, result in a multiple of 24. 
//These hours are found in freq[24 - r], as combining the current hour with an hour that is 24 - r hours away will result in a complete day.
// Frequency Map Update: For each hour processed, the count of its remainder r modulo 24 is incremented in the frequency map.
// Result: The function returns the total count of valid pairs that form a complete day.

};