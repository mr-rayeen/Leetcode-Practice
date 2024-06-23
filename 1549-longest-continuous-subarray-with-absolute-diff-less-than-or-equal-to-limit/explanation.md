# Explanation of the Code 
# Approach 1: Sliding Window and heap

### 1\. Heaps Initialization: 
Two heaps, `maxPq` and `minPq`, are initialized to store elements and their indices. The max heap is used to keep track of the maximum elements encountered so far within the window, while the min heap is used similarly for the minimum elements.

### 2\. Sliding Window: 
The solution maintains a sliding window represented by indices `i` and `j`. Initially, `i` is set to 0, and `j` is set to 0, indicating that the window starts at the beginning of the array.

### 3\. Window Expansion: 
As `j` slides through the array, elements are pushed onto both heaps. If the difference between the maximum and minimum elements in the window exceeds the limit, the window is contracted from the left by adjusting `i`.

### 4\. Contracting the Window: 
To contract the window, elements outside the new window bounds are popped from both heaps. This ensures that the heaps only contain elements within the current window.

### 5\. Updating maxLength: 
After adjusting the window, `maxLength` is updated if the current window is longer than any previously seen valid window.

### 6\. Loop Termination: 
The loop continues until `j` reaches the end of the array, ensuring that all possible windows have been considered.

## Time Complexity:

The time complexity of this solution is \(O(n \log n)\). This is because each insertion and removal operation on a heap takes \(O(\log n)\) time, and in the worst case, every element might be inserted and removed once from the heaps. Therefore, the total time complexity is proportional to the number of operations, which is linear in the size of the input array.

## Space Complexity:

The space complexity of this solution is \(O(n)\). This is due to the storage required for the heaps, which in the worst case, might store all elements of the array. Additionally, the sliding window mechanism requires space to store the indices of the elements, contributing to the linear space complexity.

# Approach 2: Using Multiset

### Explanation of the Code

#### 1\. Multiset Initialization

A multiset named `st` is initialized to store the elements of the array. A multiset allows duplicate elements and keeps them sorted, which is useful for efficiently managing the elements within the sliding window.

#### 2\. Sliding Window

The solution maintains a sliding window represented by indices `i` and `j`. Initially, `i` is set to 0, and `j` is set to 0, indicating that the window starts at the beginning of the array.

#### 3\. Window Expansion

As `j` slides through the array, the current element is inserted into the multiset. If the difference between the maximum and minimum elements in the window exceeds the limit, the window is contracted from the left by removing the element at the start of the window from the multiset and incrementing `i`.

#### 4\. Contracting the Window

By erasing the element at the start of the window from the multiset, the window is effectively contracted. This ensures that the multiset only contains elements within the current window.

#### 5\. Updating maxLength

After adjusting the window, `maxLength` is updated if the current window is longer than any previously seen valid window.

#### 6\. Loop Termination

The loop continues until `j` reaches the end of the array, ensuring that all possible windows have been considered.

### Time Complexity

The time complexity of this solution is O(n log n). This is because each insertion and removal operation on a multiset takes O(log n) time, and in the worst case, every element might be inserted and removed once from the multiset. Therefore, the total time complexity is proportional to the number of operations, which is linear in the size of the input array.

### Space Complexity

The space complexity of this solution is O(n). This is due to the storage required for the multiset, which in the worst case, might store all elements of the array. Additionally, the sliding window mechanism requires space to store the indices of the elements, contributing to the linear space complexity.
