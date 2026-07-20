#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
    int left = 0, right = 0;
    int maxLen = 0;

    for (char ch : s) {
        if (ch == '(')
            left++;
        else
            right++;

        if (left == right)
            maxLen = max(maxLen, 2 * right);
        else if (right > left)
            left = right = 0;
    }

    left = right = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '(')
            left++;
        else
            right++;

        if (left == right)
            maxLen = max(maxLen, 2 * left);
        else if (left > right)
            left = right = 0;
    }

    return maxLen;
}

int main() {
    string s;
    cin >> s;

    cout << longestValidParentheses(s) << endl;

    return 0;
}

// T.C. O(N)
// S.C. O(1)
