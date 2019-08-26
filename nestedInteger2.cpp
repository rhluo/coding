#include <string>
#include <stack>
#include <iostream>
#include "vector"

using namespace std;

class NestedInteger {
    int value;
    bool isInt;
    vector<NestedInteger> lists;

public:
    // Constructor initializes an empty nested list.
    NestedInteger() {
        isInt = false;
    }
    // Constructor initializes a single integer.
    NestedInteger(int value) {
        isInt = true;
        this->value = value;
    }
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return isInt;
    }
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return value;
    }
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        this->value = value;
    }
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        lists.push_back(ni);
    }
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return lists;
    }
};

NestedInteger deserialize(string s) {
    stack<NestedInteger> st;
    st.push(NestedInteger());
    int n = s.size();
    for(int i = 0;i < n;) {
        if(isdigit(s[i]) || s[i] == '-') {
            int j = i;
            while(j < n && (isdigit(s[j]) || s[j] == '-')) {
                j++;
            }
            int val = stoi(s.substr(i,j-i));
            st.top().add(NestedInteger(val));
            i = j;
        } else {
            if(s[i] == '[') {
                st.push(NestedInteger());
            } else if(s[i] == ']') {
                auto temp = st.top();
                st.pop();
                st.top().add(temp);
            }
            i++;
        }
    }

    auto rslt = st.top().getList().front();
    return rslt;
}

void print(NestedInteger ni) {
    if(ni.isInteger()) {
        cout << ni.getInteger() << endl;
    } else {
        cout << "[" << endl;
        for(const auto & it : ni.getList()) {
            print(it);
        }
        cout << "]" << endl;
    }
}

int main(){
    string s = "123";
    NestedInteger ni = deserialize(s);
    print(ni);
}
/*
2
5 8
2 8 5 1 10
1 2 5
1 3 9
3 4 5
2 5 6
3 2 2
1 3 8
5 3 4
4 1 8
5 8
7 2 9 10 3
1 2 8
1 3 6
1 4 4
2 5 3
4 5 2
2 4 9
3 5 3
5 4 2

 */