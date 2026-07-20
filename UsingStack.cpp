#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);  
    int n=s.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else { 
            st.pop();

            if (st.empty()) {
                st.push(i);
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << longestValidParentheses(s) << endl;
    return 0;
}

// T.C.- O(N)
// S.C.- O(N)
