//Brute Force (Extra matrix)
#include <iostream>
using namespace std;

void transposeMatrix(int matrix[][100], int N, int M) {
    int transpose[100][100];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transpose of Matrix:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cout << "Enter rows and columns: ";
    cin >> N >> M;
    int matrix[100][100];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];

    transposeMatrix(matrix, N, M);

    return 0;
}


//In-Place Transpose (Only for Square Matrices)
#include <iostream>
using namespace std;

void inPlaceTranspose(int matrix[][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    cout << "In-Place Transpose of Matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter size of square matrix: ";
    cin >> N;
    int matrix[100][100];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];

    inPlaceTranspose(matrix, N);

    return 0;
}


//Using STL (Vector)
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int M = matrix[0].size();
    
    vector<vector<int>> transpose(M, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

int main() {
    int N, M;
    cout << "Enter rows and columns: ";
    cin >> N >> M;
    
    vector<vector<int>> matrix(N, vector<int>(M));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];

    vector<vector<int>> result = transposeMatrix(matrix);

    cout << "Transpose of Matrix:\n";
    for (const auto& row : result) {
        for (int elem : row)
            cout << elem << " ";
        cout << endl;
    }

    return 0;
}
