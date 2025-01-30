# DSA, DBMS and OOPs (27 Jan 2025)


## 🔍 Table of Contents

- [Data Structures and Algorithms](#data-structures-and-algorithms)
- [Database Management System](#database-management-system)
- [Object-Oriented Programming](#object-oriented-programming)

## Data Structures and Algorithms

### 1. Frequency of Elements

**Problem**: Count the frequency of each element in an array.

**Solutions**:

1. Using Unordered Map (Hash Table):
```cpp
int frequencyCount(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr) freq[num]++;
    for (auto it : freq) cout << it.first << " -> " << it.second << endl;
}
```

2. Using Sorting:
```cpp
int frequencyCount(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int count = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1]) {
            count++;
        } else {
            cout << arr[i-1] << " -> " << count << endl;
            count = 1;
        }
    }
    cout << arr[arr.size()-1] << " -> " << count << endl;
}
```

**Complexity**:
- Unordered Map: O(N) time, O(N) space
- Sorting: O(N log N) time, O(1) space

### 2. Anagram Check

**Problem**: Determine if two strings are anagrams.

**Solutions**:

1. Sorting Method:
```cpp
bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
```

2. Character Frequency Count:
```cpp
bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    unordered_map<char, int> count;
    for (char ch : s1) count[ch]++;
    for (char ch : s2) {
        if (count.find(ch) == count.end() || count[ch] == 0) return false;
        count[ch]--;
    }
    return true;
}
```

**Complexity**:
- Sorting: O(N log N) time, O(1) space
- Hashing: O(N) time, O(N) space

### 3. String Reversal

**Problem**: Reverse a given string.

**Solutions**:

1. Two-pointer Approach:
```cpp
string reverseString(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) swap(s[l++], s[r--]);
    return s;
}
```

2. Stack Method:
```cpp
string reverseString(string s) {
    stack<char> st;
    for (char ch : s) st.push(ch);
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}
```

**Complexity**:
- Two-pointer: O(N) time, O(1) space
- Stack: O(N) time, O(N) space

## Database Management System

### Find Customer Referral

**Problem**: Find customers who are not referred by anyone.

**Solution**:
```sql
SELECT name 
FROM Customer 
WHERE referee_id IS NULL OR referee_id != 2;
```

## Object-Oriented Programming

### Method Overloading

**Example**:
```cpp
class Display {
public:
    void show(int a) {
        cout << "Integer: " << a << endl;
    }
    void show(double a) {
        cout << "Double: " << a << endl;
    }
    void show(string a) {
        cout << "String: " << a << endl;
    }
};
