# Problem Solutions

This repository contains solutions to various coding problems, including their approaches, time complexities (TC), space complexities (SC), and important points to remember.

---

## 1. **Two Sum**

| **Approach to Solve the Problem** | **Time Complexity (TC)** | **Space Complexity (SC)** | **Important Point of Approach** |
|-----------------------------------|--------------------------|---------------------------|---------------------------------|
| **Brute Force (Nested Loops)**    | O(n^2)                   | O(1)                      | Simple but inefficient for large input sizes. |
| **HashMap (Using Hashing)**       | O(n)                     | O(n)                      | Efficient approach, uses extra space for storing elements. |
| **Two-pointer after Sorting**     | O(n log n)               | O(1)                      | Good for sorted arrays, requires sorting first. |

---

## 2. **Maximum Subarray**

| **Approach to Solve the Problem** | **Time Complexity (TC)** | **Space Complexity (SC)** | **Important Point of Approach** |
|-----------------------------------|--------------------------|---------------------------|---------------------------------|
| **Brute Force (Naive)**           | O(n^3)                   | O(1)                      | Too slow for large inputs, checks all subarrays. |
| **Prefix Sum Array**              | O(n^2)                   | O(n)                      | Uses prefix sum to calculate sum of subarrays, better than brute force. |
| **Kadane’s Algorithm**            | O(n)                     | O(1)                      | Optimal approach, uses dynamic programming and maintains running sum. |

---

## 3. **Plus One**

| **Approach to Solve the Problem** | **Time Complexity (TC)** | **Space Complexity (SC)** | **Important Point of Approach** |
|-----------------------------------|--------------------------|---------------------------|---------------------------------|
| **Brute Force (Naive)**           | O(n)                     | O(1)                      | Simple, adds 1 at the last digit, handles carry-over. |
| **Optimized Approach**            | O(n)                     | O(1)                      | Efficient handling of carry without needing extra space. |

---

## 4. **Find Pivot Index**

| **Approach to Solve the Problem** | **Time Complexity (TC)** | **Space Complexity (SC)** | **Important Point of Approach** |
|-----------------------------------|--------------------------|---------------------------|---------------------------------|
| **Prefix Sum (Brute Force)**      | O(n)                     | O(1)                      | Precompute the total sum, then calculate left and right sums. |
| **Optimized Approach (Single Pass)** | O(n)                  | O(1)                      | More efficient, calculates left sum dynamically. |
| **Prefix Sum Array (HashMap)**    | O(n)                     | O(n)                      | Uses extra space but makes prefix sum calculations easier. |

---

## 5. **Check if a Matrix is Symmetric**

| **Approach to Solve the Problem** | **Time Complexity (TC)** | **Space Complexity (SC)** | **Important Point of Approach** |
|-----------------------------------|--------------------------|---------------------------|---------------------------------|
| **Naive Approach (Brute Force)**  | O(n^2)                   | O(1)                      | Simple but inefficient for large matrices. |
| **Optimized Approach**            | O(n^2)                   | O(1)                      | Compare symmetric elements only, reduces unnecessary checks. |

---

## 6. **Count the Number of Islands in a Binary Matrix**

| **Approach to Solve the Problem** | **Time Complexity (TC)** | **Space Complexity (SC)** | **Important Point of Approach** |
|-----------------------------------|--------------------------|---------------------------|---------------------------------|
| **DFS (Depth First Search)**      | O(n * m)                 | O(n * m)                  | Traverses the matrix and marks visited cells. |
| **BFS (Breadth First Search)**    | O(n * m)                 | O(n * m)                  | Alternative to DFS, uses queue for exploration. |
| **Union-Find (Disjoint Set)**     | O(n * m)                 | O(n * m)                  | Uses disjoint set data structure to group connected components. |

---

## 7. **Search an Element in a Row-Wise and Column-Sorted Matrix**

| **Approach to Solve the Problem** | **Time Complexity (TC)** | **Space Complexity (SC)** | **Important Point of Approach** |
|-----------------------------------|--------------------------|---------------------------|---------------------------------|
| **Brute Force (Linear Search)**   | O(n * m)                 | O(1)                      | Checks every element, inefficient for large matrices. |
| **Optimal (Start from top-right corner)** | O(n + m)            | O(1)                      | Efficient method by moving left or down depending on comparison. |

---

### Conclusion:
- Each approach presented above has trade-offs between time and space complexities.
- **Optimized** approaches are usually the best in coding interviews, and it's important to demonstrate understanding of both time and space efficiency.

---
