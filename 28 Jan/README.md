# DSA and DBMS Problems

## 📌 DSA 

<details>
<summary>1⃣ Find Diagonal Sum of Matrix</summary>

**Problem Statement:** Given an NxN matrix, find the sum of its diagonals.

**Approaches to Solve:**

1. **Brute Force:** Iterate through the matrix and sum up diagonal elements.

```cpp
int diagonalSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}
```

2. **Optimized Approach:** Sum diagonal elements in a single loop.

```cpp
int diagonalSumOptimized(vector<vector<int>>& matrix) {
    int n = matrix.size(), sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
        if (i != n - i - 1) sum += matrix[i][n - i - 1];
    }
    return sum;
}
```

</details>

<details>
<summary>2⃣ Find First Non-Repeating Character</summary>

**Problem Statement:** Given a string, find the first character that appears only once.

**Approaches to Solve:**

1. **Brute Force Approach (Nested Loops):**

```cpp
char firstUniqCharBrute(string s) {
    for (int i = 0; i < s.size(); i++) {
        bool unique = true;
        for (int j = 0; j < s.size(); j++) {
            if (i != j && s[i] == s[j]) {
                unique = false;
                break;
            }
        }
        if (unique) return s[i];
    }
    return '_';
}
```

2. **Hash Map Approach (Two Passes):**

```cpp
char firstUniqChar(string s) {
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    for (char c : s) if (count[c] == 1) return c;
    return '_';
}
```

3. **Optimized Approach (Using Fixed-Size Array):**

```cpp
char firstUniqCharOptimized(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    for (char c : s) if (freq[c - 'a'] == 1) return c;
    return '_';
}
```

4. **Optimized Approach Using Queue (Single Pass):**

```cpp
char firstUniqCharQueue(string s) {
    queue<char> q;
    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
        q.push(c);
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }
    }
    return q.empty() ? '_' : q.front();
}
```

</details>

<details>
<summary>3⃣ Transpose of a Matrix</summary>

**Problem Statement:** Given an NxM matrix, find its transpose.

**Approaches to Solve:**

1. **Brute Force (Extra matrix):**

```cpp
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}
```

2. **In-Place Transpose (Only for Square Matrices):**

```cpp
void transposeInPlace(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
```

</details>

## 📌 DBMS 

<details>
<summary>1⃣ Leetcode 595 - Big Countries</summary>

**Problem Statement:** Find country names, populations, and areas where area > 3 million or population > 25 million.

**Approach:** Use SQL `WHERE` clause.

```sql
SELECT name, population, area FROM World 
WHERE area > 3000000 OR population > 25000000;
```

</details>