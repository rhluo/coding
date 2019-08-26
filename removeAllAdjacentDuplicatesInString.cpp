//todo leetcode 1047: Remove All Adjacent Duplicates In String: stack

#include <iostream>
#include <stack>

using namespace std;

string removeDuplicates(string S) {
    stack<char> st;
    int n = S.size();
    for(int i = 0;i < n;i++) {
        char c = S[i];
        if(st.size() == 0 || st.top() != c) {
            st.push(c);
        } else {
            st.pop();
        }
    }

    string rslt = "";
    while(st.size() > 0) {
        rslt = st.top() + rslt;
        st.pop();
    }

    return rslt;
}

int main() {
    string input = "abbaca";
    cout << removeDuplicates(input) << endl;
    return 1;
}
