#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class MaximumSubarray {
public:
    // Approach 1: Brute Force (Check all subarrays)
    int bruteForce(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        // Iterate over all subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int currentSum = 0;
                // Sum the elements in the subarray
                for (int k = i; k <= j; k++) {
                    currentSum += nums[k];
                }
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }

    // Approach 2: Kadane's Algorithm (Optimal Solution)
    int kadaneAlgorithm(vector<int>& nums) {
        int maxSum = nums[0];  // Initialize maxSum to the first element
        int currentSum = nums[0];  // Initialize currentSum to the first element

        // Traverse through the array from the second element
        for (int i = 1; i < nums.size(); i++) {
            // Update currentSum either by adding current element or starting fresh
            currentSum = max(nums[i], currentSum + nums[i]);
            // Update maxSum if the currentSum is greater
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }

    // Approach 3: Prefix Sum with Divide and Conquer (O(n log n) time)
    int divideAndConquer(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;
        int leftMax = divideAndConquer(nums, left, mid);
        int rightMax = divideAndConquer(nums, mid + 1, right);
        
        int crossMax = findMaxCrossingSubarray(nums, left, mid, right);
        
        return max({leftMax, rightMax, crossMax});
    }

    // Helper function to find maximum sum of subarray crossing the mid point
    int findMaxCrossingSubarray(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN, rightSum = INT_MIN;
        int sum = 0;

        // Find the maximum sum of the left half that includes the middle element
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0;
        // Find the maximum sum of the right half that includes the middle element
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        // Return the sum of the left and right maximums
        return leftSum + rightSum;
    }

    // Approach 4: Dynamic Programming (Bottom-up approach)
    int dynamicProgramming(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); // dp[i] stores the maximum subarray sum ending at index i
        dp[0] = nums[0];
        int maxSum = nums[0];

        // Fill dp array by calculating max sum at each index
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }

    // Driver function to call each approach
    void solve(vector<int>& nums) {
        // Approach 1: Brute Force
        int result = bruteForce(nums);
        cout << "Brute Force: " << result << endl;

        // Approach 2: Kadane's Algorithm
        result = kadaneAlgorithm(nums);
        cout << "Kadane's Algorithm: " << result << endl;

        // Approach 3: Divide and Conquer
        result = divideAndConquer(nums, 0, nums.size() - 1);
        cout << "Divide and Conquer: " << result << endl;

        // Approach 4: Dynamic Programming
        result = dynamicProgramming(nums);
        cout << "Dynamic Programming: " << result << endl;
    }
};

int main() {
    MaximumSubarray ms;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};  // Example input

    ms.solve(nums);  // Call the solve function to test all approaches

    return 0;
}
