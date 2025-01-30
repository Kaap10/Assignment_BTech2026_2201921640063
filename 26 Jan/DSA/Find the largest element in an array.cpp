#include<bits/stdc++.h>
using namespace std;

// int findLargestUsingMax(int arr[], int n) {
//     int result = *max_element(arr, arr+n);
//     return result;
// }

int findLargestUsingSorting(int arr[], int n) {
    sort(arr, arr+n);
    return arr[n-1];
}

int findLargest(int arr[], int n) {
    int maxi = INT_MIN;
    for(int i=0; i<n; i++) {
        if(maxi < arr[i]) {
            maxi = arr[i];
        }
    }
    return maxi;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter Numbers: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = findLargest(arr, n);
    cout << "Largest Number: " << ans;
    return 0;
}

/*
    Enter size: 5 
    Enter Numbers: 21 89 76 78 2
    Largest Number: 89
*/