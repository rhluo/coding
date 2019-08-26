//todo 剑指offer 38 : dfs
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> rslt;

typedef unsigned long long ULL;

const int P = 131;

unordered_set<ULL> save;

ULL toKey(vector<bool> visited) {
    ULL res = 0;
    for(const auto & it : visited) {
        res = res*P + it;
    }
    return res;
}

string toString(vector<bool> visited) {
    string rslt = "";
    for(const auto & it : visited) {
        if(it) {
            rslt += '1';
        } else {
            rslt += '0';
        }
    }
    return rslt;
}

void dfs(string pre, string& input, vector<bool>& visited, int m, unordered_set<string>& duplicate) {
    if(m == 0) {
        //cout << pre << endl;
        auto key = toString(visited);
        if(duplicate.count(key) == 0) {
            rslt.push_back(pre);
            duplicate.insert(key);
        }
        return;
    }

    int n = input.size();

    for(int i = 0;i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(pre + input[i], input, visited, m - 1, duplicate);
            visited[i] = false;
        }
    }
}

int main() {
    string str = "abc";

    int n = str.size();
    vector<bool> visited(n, false);

    for(int i = 1;i <= n; i++) {
        unordered_set<string> duplicate;
        dfs("", str, visited, i, duplicate);
    }

    for(const auto & item : rslt) {
        cout << item << endl;
    }
    return 1;
}
