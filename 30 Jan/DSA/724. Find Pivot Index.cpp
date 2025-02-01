#include <iostream>
#include <vector>
using namespace std;

class PivotIndex {
public:
    // Approach 1: Using Prefix Sum (Brute Force Method)
    int pivotIndexPrefixSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        // Precompute the total sum of the array
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;
        // Check for each index if the left sum equals the right sum
        for (int i = 0; i < n; i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;  // Pivot index found
            }
            leftSum += nums[i];
        }

        return -1;  // No pivot index found
    }

    // Approach 2: Optimized Approach (Single Pass)
    int pivotIndexOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        int totalSum = 0, leftSum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // Traverse through the array and calculate the left sum dynamically
        for (int i = 0; i < n; i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;  // Pivot index found
            }
            leftSum += nums[i];  // Update the left sum for the next iteration
        }

        return -1;  // No pivot index found
    }

    // Approach 3: Using a HashMap (Space Complexity O(n))
    int pivotIndexHashMap(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        // Use a hashmap to store the sum of elements up to each index
        vector<int> prefixSum(n + 1, 0);
        
        // Compute prefix sum of the array
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Check if any prefix sum satisfies the condition for pivot index
        for (int i = 0; i < n; i++) {
            if (prefixSum[i] == prefixSum[n] - prefixSum[i + 1]) {
                return i;
            }
        }

        return -1;  // No pivot index found
    }

    // Driver function to test all approaches
    void solve(vector<int>& nums) {
        // Approach 1: Using Prefix Sum (Brute Force Method)
        int result = pivotIndexPrefixSum(nums);
        cout << "Approach 1 (Prefix Sum): " << result << endl;

        // Reset nums for next approach
        nums = {1, 7, 3, 6, 5, 6};

        // Approach 2: Optimized Approach (Single Pass)
        result = pivotIndexOptimized(nums);
        cout << "Approach 2 (Optimized): " << result << endl;

        // Reset nums for next approach
        nums = {1, 7, 3, 6, 5, 6};

        // Approach 3: Using a HashMap (Space Complexity O(n))
        result = pivotIndexHashMap(nums);
        cout << "Approach 3 (Using HashMap): " << result << endl;
    }
};

int main() {
    PivotIndex pi;
    vector<int> nums = {1, 7, 3, 6, 5, 6};  // Example input
    
    pi.solve(nums);  // Call the solve function to test all approaches

    return 0;
}
