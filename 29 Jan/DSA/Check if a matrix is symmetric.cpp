#include <iostream>
#include <vector>
using namespace std;

class MatrixSymmetry {
public:
    // 1. Brute Force Approach: Compare each element with its transpose
    bool isSymmetricBruteForce(vector<vector<int>>& matrix) {
        int n = matrix.size(); // assuming the matrix is n x n
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    // 2. Using Transpose Method (One Pass Comparison)
    bool isSymmetricUsingTranspose(vector<vector<int>>& matrix) {
        int n = matrix.size(); // assuming the matrix is n x n
        // Compare the elements directly without creating a full transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    // 3. Optimized Approach (Check upper triangle and directly compare with the lower triangle)
    bool isSymmetricOptimized(vector<vector<int>>& matrix) {
        int n = matrix.size(); // assuming the matrix is n x n
        // Compare elements in the upper triangle and lower triangle
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    // 4. Using Explicit Transpose
    bool isSymmetricWithTranspose(vector<vector<int>>& matrix) {
        int n = matrix.size(); // assuming the matrix is n x n
        vector<vector<int>> transpose(n, vector<int>(n));

        // Calculate the transpose of the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                transpose[i][j] = matrix[j][i];
            }
        }

        // Compare original matrix with its transpose
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != transpose[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    // Sample matrix for testing
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };

    MatrixSymmetry ms;
    
    // Test each approach
    if (ms.isSymmetricBruteForce(matrix)) {
        cout << "Matrix is symmetric (Brute Force Approach)" << endl;
    } else {
        cout << "Matrix is not symmetric (Brute Force Approach)" << endl;
    }

    if (ms.isSymmetricUsingTranspose(matrix)) {
        cout << "Matrix is symmetric (Using Transpose Method)" << endl;
    } else {
        cout << "Matrix is not symmetric (Using Transpose Method)" << endl;
    }

    if (ms.isSymmetricOptimized(matrix)) {
        cout << "Matrix is symmetric (Optimized Approach)" << endl;
    } else {
        cout << "Matrix is not symmetric (Optimized Approach)" << endl;
    }

    if (ms.isSymmetricWithTranspose(matrix)) {
        cout << "Matrix is symmetric (Using Explicit Transpose)" << endl;
    } else {
        cout << "Matrix is not symmetric (Using Explicit Transpose)" << endl;
    }

    return 0;
}
