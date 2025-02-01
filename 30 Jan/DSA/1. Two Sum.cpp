#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class TwoSum {
public:
    // Approach 1: Brute Force (Two nested loops)
    vector<int> bruteForce(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }

    // Approach 2: Using HashMap (Optimal Solution)
    vector<int> hashMapApproach(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {}; // No solution found
    }

    // Approach 3: Sorting + Two Pointers (O(nlogn) time)
    vector<int> twoPointerApproach(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums;
        
        // Store numbers with their original indices
        for (int i = 0; i < n; i++) {
            indexedNums.push_back({nums[i], i});
        }

        // Sort the array based on the values
        sort(indexedNums.begin(), indexedNums.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;
            if (sum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {}; // No solution found
    }

    // Approach 4: Optimized with a single loop and HashSet for tracking visited elements (Alternative Hashing)
    vector<int> hashSetApproach(vector<int>& nums, int target) {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.find(complement) != seen.end()) {
                return {i, find(nums.begin(), nums.end(), complement) - nums.begin()};
            }
            seen.insert(nums[i]);
        }
        return {}; // No solution found
    }
};

int main() {
    TwoSum ts;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Approach 1: Brute Force
    vector<int> result = ts.bruteForce(nums, target);
    if (!result.empty()) {
        cout << "Brute Force: Indices are " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "Brute Force: No solution found!" << endl;
    }

    // Approach 2: HashMap Approach
    result = ts.hashMapApproach(nums, target);
    if (!result.empty()) {
        cout << "HashMap: Indices are " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "HashMap: No solution found!" << endl;
    }

    // Approach 3: Sorting + Two Pointers
    result = ts.twoPointerApproach(nums, target);
    if (!result.empty()) {
        cout << "Two Pointers: Indices are " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "Two Pointers: No solution found!" << endl;
    }

    // Approach 4: HashSet Approach
    result = ts.hashSetApproach(nums, target);
    if (!result.empty()) {
        cout << "HashSet: Indices are " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "HashSet: No solution found!" << endl;
    }

    return 0;
}
