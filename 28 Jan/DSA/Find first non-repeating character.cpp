//Brute Force Approach (Nested Loops)

#include <iostream>
using namespace std;

int firstNonRepeatingCharacter(string s) {
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        bool unique = true;
        for (int j = 0; j < n; j++) {
            if (i != j && s[i] == s[j]) {
                unique = false;
                break;
            }
        }
        if (unique)
            return i;
    }
    
    return -1;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    int index = firstNonRepeatingCharacter(s);
    if (index == -1)
        cout << "No non-repeating character found\n";
    else
        cout << "First non-repeating character is at index: " << index << endl;
    
    return 0;
}


//Hash Map Approach (Two Passes)
#include <iostream>
#include <unordered_map>
using namespace std;

int firstNonRepeatingCharacter(string s) {
    unordered_map<char, int> freq;

    // Count frequency of each character
    for (char ch : s)
        freq[ch]++;

    // Find the first character with frequency 1
    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i]] == 1)
            return i;
    }

    return -1;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    int index = firstNonRepeatingCharacter(s);
    if (index == -1)
        cout << "No non-repeating character found\n";
    else
        cout << "First non-repeating character is at index: " << index << endl;
    
    return 0;
}


// Optimized Approach (Using Fixed-Size Array)
#include <iostream>
#include <climits>
using namespace std;

int firstNonRepeatingCharacter(string s) {
    int charCount[256] = {0}; // ASCII character count
    int charIndex[256];       // Store first occurrence index
    
    fill(charIndex, charIndex + 256, INT_MAX);
    
    for (int i = 0; i < s.length(); i++) {
        charCount[s[i]]++;
        if (charIndex[s[i]] == INT_MAX)
            charIndex[s[i]] = i;
    }

    int minIndex = INT_MAX;
    for (int i = 0; i < 256; i++) {
        if (charCount[i] == 1)
            minIndex = min(minIndex, charIndex[i]);
    }

    return (minIndex == INT_MAX) ? -1 : minIndex;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    int index = firstNonRepeatingCharacter(s);
    if (index == -1)
        cout << "No non-repeating character found\n";
    else
        cout << "First non-repeating character is at index: " << index << endl;
    
    return 0;
}


//Optimized Approach Using Queue (Single Pass)
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int firstNonRepeatingCharacter(string s) {
    unordered_map<char, int> freq;
    queue<int> q;

    for (int i = 0; i < s.length(); i++) {
        freq[s[i]]++;
        if (freq[s[i]] == 1)
            q.push(i);

        while (!q.empty() && freq[s[q.front()]] > 1)
            q.pop();
    }

    return q.empty() ? -1 : q.front();
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    int index = firstNonRepeatingCharacter(s);
    if (index == -1)
        cout << "No non-repeating character found\n";
    else
        cout << "First non-repeating character is at index: " << index << endl;
    
    return 0;
}


