class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        // //  Approach 1: Using Counting Sort. TC: O(nlogn);
        // // Step 1: Count occurrences of each element in arr1 using a map
        // map<int, int> mp; // Map to store element-frequency pairs
    
        // for(int &num: arr1){ // Iterate over arr1 to populate the map
        //     mp[num]++;
        // }

        // int i = 0; // Index to insert elements from arr2 into arr1
        // for(int &num : arr2){ // Iterate over arr2 to reorder elements in arr1
        //     while(mp[num]-- > 0){ // Deplete the count of the current element in arr1
        //         arr1[i++] = num; // Insert the element from arr2 into arr1
        //     }
        // }

        // // Step 2: Insert remaining elements from arr1 that were not part of arr2
        // for(auto &it: mp){ // Iterate over the map to handle elements not in arr2
        //     int freq = it.second; // Frequency of the current element
        //     while(freq > 0){ // Insert the element into arr1 as many times as its frequency
        //         arr1[i++] = it.first; // Insert the element
        //         freq--; // Decrease the frequency
        //     }
        // }
        // return arr1; // Return the sorted arr1

        //-------------------------------------------------------//

        // Approach 2: Making own Custom sort. T.C. = O(nlogn);

        // Step 1: Create a mapping of arr2 elements to their indices
    unordered_map<int, int> mp; // Map to store arr2 elements and their indices
    
    for(int i = 0; i < arr2.size(); i++){ // Populate the map with arr2 elements and their indices
        mp[arr2[i]] = i;
    }

    // Step 2: Extend the map to include elements from arr1 not present in arr2
    for(int &num : arr1){ // Iterate over arr1 to extend the map
        if(!mp.count(num)) mp[num] = 1e9; // Assign a large value (1e9) to elements not in arr2
    }

    // Step 3: Define a custom comparison lambda function for sorting
    auto lambda = [&](int &num1, int &num2){ // Lambda function for comparing two numbers
        if(mp[num1] == mp[num2]){   // Compare elements based on their assigned large value (1e9) if they have the same index in arr2
            return num1 < num2; // Default comparison for elements not in arr2
        }

        return mp[num1] < mp[num2]; // Compare elements based on their index in arr2
    };

    // Step 4: Sort arr1 using the custom comparison lambda function
    sort(begin(arr1), end(arr1), lambda); // Sort arr1 according to the custom criteria defined by lambda

    return arr1; // Return the sorted arr1

    }
};