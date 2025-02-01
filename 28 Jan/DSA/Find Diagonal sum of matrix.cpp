//brute force
#include <iostream>
using namespace std;

int diagonalSum(int matrix[][100], int N) {
    int primarySum = 0, secondarySum = 0;

    // Calculate primary diagonal sum
    for (int i = 0; i < N; i++) {
        primarySum += matrix[i][i];
    }

    // Calculate secondary diagonal sum
    for (int i = 0; i < N; i++) {
        secondarySum += matrix[i][N - i - 1];
    }

    // If N is odd, subtract the middle element (as it's counted twice)
    if (N % 2 == 1) {
        secondarySum -= matrix[N / 2][N / 2];
    }

    return primarySum + secondarySum;
}

int main() {
    int N;
    cout << "Enter the size of matrix: ";
    cin >> N;
    int matrix[100][100];

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];

    cout << "Diagonal Sum: " << diagonalSum(matrix, N) << endl;
    return 0;
}


//optimized approach (single loop)
#include <iostream>
using namespace std;

int diagonalSumOptimized(int matrix[][100], int N) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += matrix[i][i];  // Primary diagonal
        sum += matrix[i][N - i - 1];  // Secondary diagonal
    }

    // If N is odd, subtract the middle element (it was counted twice)
    if (N % 2 == 1) {
        sum -= matrix[N / 2][N / 2];
    }

    return sum;
}

int main() {
    int N;
    cout << "Enter the size of matrix: ";
    cin >> N;
    int matrix[100][100];

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];

    cout << "Diagonal Sum: " << diagonalSumOptimized(matrix, N) << endl;
    return 0;
}

