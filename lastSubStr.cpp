#include <iostream>
#include <vector>

using namespace std;

string lastSubstring(string s) {
    int n = s.size();
    vector<vector<int>> dp(26, vector<int>(0));

    for(int i = 0;i < n;i++) {
        dp[s[i] - 'a'].push_back(i);
    }

    string rslt = "";
    int curl = 0;
    while(curl < n-1) {
        for (int pos = 25; pos >= 0; pos--) {
            char c = 'a' + pos;
            auto item = lower_bound(dp[pos].begin(), dp[pos].end(), curl);
            if (item != dp[pos].end()) {
                cout << c << " " << *item << " " << curl << endl;
                rslt += c;
                curl = (*item) + 1;
                break;
            }
        }
    }

    return rslt;
}

int main() {
    string test = "abab";
    cout << lastSubstring(test) << endl;
    return 0;
}

