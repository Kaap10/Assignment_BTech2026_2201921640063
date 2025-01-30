#include<bits/stdc++.h>
using namespace std;

bool isSorted(int n, int arr[]) {
    for(int i=1; i<n; i++) {
        if(arr[i-1] > arr[i]) {
            return false;
        }
    }
    return true;
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

    int ans = isSorted(n, arr);
    if(ans==true) {
        cout << "Array is sorted!";
    } else {
        cout << "Array is not sorted!";
    }

    return 0;
}
/*
Enter size: 6
Enter Numbers: 20 21 45 89 89 90
Array is sorted!

Enter size: 6
Enter Numbers: 21 20 45 89 89 90
Array is not sorted!
*/