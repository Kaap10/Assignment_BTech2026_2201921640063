#include <iostream>
#include <vector>
using namespace std;

class PlusOne {
public:
    // Approach 1: Simple Approach (From Right to Left)
    vector<int> plusOneSimple(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            // If the current digit is less than 9, just add 1 and return the result
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // If the current digit is 9, set it to 0 and continue the process
            digits[i] = 0;
        }
        
        // If the loop finishes, all digits were 9, so we need to add a 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }

    // Approach 2: Optimized Approach (Handling Carry Propagation)
    vector<int> plusOneOptimized(vector<int>& digits) {
        int n = digits.size();
        // Start from the last digit and handle carry
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;  // Set to 0 and carry over
        }
        // After the loop, if we have a carry left, insert 1 at the start
        digits.insert(digits.begin(), 1);
        return digits;
    }

    // Approach 3: Using a Helper Function to Reverse (Less Efficient but More Generalized)
    vector<int> plusOneWithReverse(vector<int>& digits) {
        int n = digits.size();
        bool carry = true;
        
        // Start from the rightmost digit and propagate the carry
        for (int i = n - 1; i >= 0; i--) {
            if (carry) {
                if (digits[i] == 9) {
                    digits[i] = 0;  // Carry over
                } else {
                    digits[i]++;
                    carry = false;  // No carry left, stop
                }
            }
        }

        // If there is still a carry left after the loop, we need to add a 1 at the front
        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }

    // Driver function to test all approaches
    void solve(vector<int>& digits) {
        // Approach 1: Simple Approach (From Right to Left)
        vector<int> result = plusOneSimple(digits);
        cout << "Approach 1 (Simple): ";
        for (int num : result) cout << num;
        cout << endl;

        // Reset digits for next approach
        digits = {9, 9, 9};

        // Approach 2: Optimized Approach (Handling Carry Propagation)
        result = plusOneOptimized(digits);
        cout << "Approach 2 (Optimized): ";
        for (int num : result) cout << num;
        cout << endl;

        // Reset digits for next approach
        digits = {9, 9, 9};

        // Approach 3: Using a Helper Function to Reverse (Less Efficient)
        result = plusOneWithReverse(digits);
        cout << "Approach 3 (With Reverse): ";
        for (int num : result) cout << num;
        cout << endl;
    }
};

int main() {
    PlusOne po;
    vector<int> digits = {1, 2, 3};  // Example input
    
    po.solve(digits);  // Call the solve function to test all approaches

    return 0;
}
