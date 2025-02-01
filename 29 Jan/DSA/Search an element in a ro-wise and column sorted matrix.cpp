#include <iostream>
#include <vector>
using namespace std;

class MatrixSearch {
public:
    // Approach 1: Binary Search on each row
    bool binarySearchRowWise(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                }
                if (matrix[i][mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }

    // Approach 2: Binary Search on entire matrix (treating it as a 1D array)
    bool binarySearchWholeMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = n * m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / m][mid % m];
            if (midValue == target) {
                return true;
            }
            if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    // Approach 3: Start from top-right corner of the matrix
    bool searchFromTopRight(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;

        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                row++;
            }
            else {
                col--;
            }
        }
        return false;
    }

    // Approach 4: Start from bottom-left corner of the matrix
    bool searchFromBottomLeft(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n - 1, col = 0;

        while (row >= 0 && col < m) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                col++;
            }
            else {
                row--;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    
    int target = 5;
    
    MatrixSearch ms;
    
    // Approach 1: Binary Search on each row
    if (ms.binarySearchRowWise(matrix, target)) {
        cout << "Element " << target << " found using binary search on rows!" << endl;
    } else {
        cout << "Element " << target << " not found using binary search on rows!" << endl;
    }

    // Approach 2: Binary Search on whole matrix
    if (ms.binarySearchWholeMatrix(matrix, target)) {
        cout << "Element " << target << " found using binary search on whole matrix!" << endl;
    } else {
        cout << "Element " << target << " not found using binary search on whole matrix!" << endl;
    }

    // Approach 3: Search from top-right corner
    if (ms.searchFromTopRight(matrix, target)) {
        cout << "Element " << target << " found starting from top-right!" << endl;
    } else {
        cout << "Element " << target << " not found starting from top-right!" << endl;
    }

    // Approach 4: Search from bottom-left corner
    if (ms.searchFromBottomLeft(matrix, target)) {
        cout << "Element " << target << " found starting from bottom-left!" << endl;
    } else {
        cout << "Element " << target << " not found starting from bottom-left!" << endl;
    }

    return 0;
}
