# DSA, DBMS and OOPS Problems (26 Jan 2025)

## 📌 DSA 

<details>
<summary>1️⃣ Find the Largest Element in an Array (GFG) </summary>

**Problem Statement:** Given an array of size N, find the largest element in the array.

**Approaches to Solve:**
1. **Brute Force:** Traverse the array and keep track of the maximum element.

```cpp
int findLargest(int arr[], int n) {
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}
```

2. **Using Sorting:** Sort the array and return the last element.

```cpp
#include <algorithm>
int findLargestSorted(int arr[], int n) {
    sort(arr, arr + n);
    return arr[n - 1];
}
```

3. **Using Inbuilt Function:** Use `max_element()` function.

```cpp
#include <algorithm>
int findLargestInbuilt(int arr[], int n) {
    return *max_element(arr, arr + n);
}
```

**Time & Space Complexity:**
- Brute Force: O(N) time, O(1) space
- Sorting: O(N log N) time, O(1) space
- Inbuilt Function: O(N) time, O(1) space

</details>

<details>
<summary>2️⃣ Move All Zeroes to the End (GFG)</summary>

**Problem Statement:** Given an array, move all zeroes to the end while maintaining the relative order of non-zero elements.

**Approaches to Solve:**
1. **Brute Force:** Create a new array and insert non-zero elements first, then zeroes.

```cpp
void moveZeroes(int arr[], int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) temp.push_back(arr[i]);
    }
    while (temp.size() < n) temp.push_back(0);
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}
```

2. **Two-Pointer Approach:** Swap zeroes with non-zero elements in-place.

```cpp
void moveZeroesOptimized(int arr[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
```

**Time & Space Complexity:**
- Brute Force: O(N) time, O(N) space
- Two-Pointer: O(N) time, O(1) space

</details>

<details>
<summary>3️⃣ Check if an Array is Sorted (GFG)</summary>

**Problem Statement:** Given an array, determine whether it is sorted in non-decreasing order.

**Approaches to Solve:**
1. **Iterative Approach:** Traverse the array and check if `arr[i] > arr[i+1]`.

```cpp
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}
```

2. **Recursive Approach:** Check for each element recursively.

```cpp
bool isSortedRecursive(int arr[], int n) {
    if (n == 1) return true;
    return (arr[n - 2] <= arr[n - 1]) && isSortedRecursive(arr, n - 1);
}
```

**Time & Space Complexity:**
- Iterative: O(N) time, O(1) space
- Recursive: O(N) time, O(N) space (for recursion stack)

</details>

## 📌 DBMS 

<details>
<summary>1️⃣ 1757. Recyclable and Low Fat Products (LeetCode) </summary>

**Problem Statement:** Write an SQL query to find products that are recyclable and have low fat content.

**Approaches to Solve:**
1. **Using WHERE Clause:** Select products where `recyclable = 'Yes'` and `low_fat = 'Yes'`.

```sql
SELECT product_id 
FROM Products 
WHERE recyclable = 'Yes' AND low_fat = 'Yes';
```

</details>

## 📌 OOPS

<details>
<summary>1️⃣ What is Object-Oriented Programming?</summary>

**Problem Statement:** Explain the four pillars of OOPS.

**Approach to Solve:**
- **Encapsulation**: Binding data and methods together.
- **Abstraction**: Hiding implementation details.
- **Inheritance**: Reusing code by deriving new classes.
- **Polymorphism**: Ability to take multiple forms (overloading & overriding).

</details>

<details>
<summary>2️⃣ Difference Between Class and Object</summary>

**Problem Statement:** Explain the difference between a class and an object.

**Approach to Solve:**
- **Class:** A blueprint/template.
- **Object:** An instance of a class with actual values.

```cpp
class Car {
   public:
       string brand;
       void show() { cout << brand; }
};

int main() {
    Car c;
    c.brand = "Tesla";
    c.show();
}
```

</details>

<details>
<summary>3️⃣ Explain Constructor and Destructor</summary>

**Problem Statement:** What are constructors and destructors in C++?

**Approach to Solve:**
- **Constructor:** Special method called when an object is created.
- **Destructor:** Special method called when an object is destroyed.

```cpp
class Demo {
  public:
    Demo() { cout << "Constructor Called"; }
    ~Demo() { cout << "Destructor Called"; }
};

int main() {
    Demo d; // Constructor is called
} // Destructor is called automatically
```

</details>


