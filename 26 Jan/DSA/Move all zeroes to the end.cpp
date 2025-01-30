#include<bits/stdc++.h>
using namespace std;

void moveZeroes(int arr[], int n) {
    vector<int> result;

    for(int i=0; i<n; i++) {
        if(arr[i] != 0) {
            result.push_back(arr[i]);
        }
    }

    int m = result.size();

    for(int i=m; i<n; i++) {
        int ans = 0;
        result.push_back(ans);
    }

    for(int i=0; i<n; i++) {
        arr[i] = result[i];
    }
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

    cout << "Zeroes have been moved to left: ";
    moveZeroes(arr, n);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    Enter size: 6
    Enter Numbers: 0 1 0 2 0 4
    Zeroes have been moved to left: 1 2 4 0 0 0 
*/