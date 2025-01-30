#include<bits/stdc++.h>
using namespace std;

int countFreq(int arr[], int n) {
    unordered_map<int, int> freq;

    for(auto it : arr) {
        
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

    countFreq(arr, n);

    return 0;
}