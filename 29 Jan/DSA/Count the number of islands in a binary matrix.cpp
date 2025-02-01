#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class IslandCounter {
public:
    // DFS approach
    void dfs(vector<vector<int>>& matrix, int i, int j) {
        // Check if out of bounds or water
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 0)
            return;
        
        // Mark the current cell as visited (water)
        matrix[i][j] = 0;

        // Explore all 8 neighbors
        dfs(matrix, i + 1, j);     // Down
        dfs(matrix, i - 1, j);     // Up
        dfs(matrix, i, j + 1);     // Right
        dfs(matrix, i, j - 1);     // Left
        dfs(matrix, i + 1, j + 1); // Down-Right
        dfs(matrix, i - 1, j - 1); // Up-Left
        dfs(matrix, i + 1, j - 1); // Down-Left
        dfs(matrix, i - 1, j + 1); // Up-Right
    }

    int countIslandsDFS(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int islandCount = 0;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                // If a land cell is found, perform DFS and mark the entire island
                if (matrix[i][j] == 1) {
                    islandCount++;
                    dfs(matrix, i, j);
                }
            }
        }
        return islandCount;
    }

    // BFS approach
    void bfs(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        matrix[i][j] = 0; // Mark as visited
        
        // Directions: Up, Down, Left, Right, and Diagonal neighbors
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Check all neighbors
            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && matrix[newX][newY] == 1) {
                    matrix[newX][newY] = 0; // Mark as visited
                    q.push({newX, newY});
                }
            }
        }
    }

    int countIslandsBFS(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int islandCount = 0;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                // If a land cell is found, perform BFS and mark the entire island
                if (matrix[i][j] == 1) {
                    islandCount++;
                    bfs(matrix, i, j);
                }
            }
        }
        return islandCount;
    }

    // Union-Find approach
private:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }

public:
    int countIslandsUnionFind(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        parent.resize(n * m);
        size.resize(n * m, 1);
        
        // Initialize union-find
        for (int i = 0; i < n * m; i++) {
            parent[i] = i;
        }

        // Directions: Up, Down, Left, Right, and Diagonal neighbors
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    int current = i * m + j;
                    for (auto dir : directions) {
                        int newX = i + dir.first;
                        int newY = j + dir.second;
                        
                        if (newX >= 0 && newX < n && newY >= 0 && newY < m && matrix[newX][newY] == 1) {
                            int neighbor = newX * m + newY;
                            unionSets(current, neighbor);
                        }
                    }
                }
            }
        }

        // Count the number of distinct components (islands)
        int islandCount = 0;
        for (int i = 0; i < n * m; i++) {
            if (parent[i] == i && matrix[i / m][i % m] == 1) {
                islandCount++;
            }
        }
        return islandCount;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    IslandCounter ic;
    
    // DFS Approach
    vector<vector<int>> matrixDFS = matrix;
    int numIslandsDFS = ic.countIslandsDFS(matrixDFS);
    cout << "Number of islands (DFS): " << numIslandsDFS << endl;

    // BFS Approach
    vector<vector<int>> matrixBFS = matrix;
    int numIslandsBFS = ic.countIslandsBFS(matrixBFS);
    cout << "Number of islands (BFS): " << numIslandsBFS << endl;

    // Union-Find Approach
    vector<vector<int>> matrixUnionFind = matrix;
    int numIslandsUnionFind = ic.countIslandsUnionFind(matrixUnionFind);
    cout << "Number of islands (Union-Find): " << numIslandsUnionFind << endl;

    return 0;
}
