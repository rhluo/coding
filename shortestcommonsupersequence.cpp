//todo leetcode 1092 : dp
#include <iostream>
#include <vector>

using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<pair<int, int>>> pre(n+1, vector<pair<int, int>>(m+1, pair<int, int>(-1, -1)));
    for(int i = 1;i <= n;i++) {
        pre[i][0].first = i-1;
        pre[i][0].second = 0;
        dp[i][0] = i;
    }
    for(int j = 1;j <= m;j++) {
        dp[0][j] = j;
        pre[0][j].first = 0;
        pre[0][j].second = j-1;
    }

    for(int i = 1;i <= n; i++) {
        for(int j = 1;j <= m;j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                pre[i][j].first = i-1;
                pre[i][j].second = j-1;
            } else {
                if(dp[i-1][j] < dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j] + 1;
                    pre[i][j].first = i-1;
                    pre[i][j].second = j;
                } else {
                    dp[i][j] = dp[i][j-1] + 1;
                    pre[i][j].first = i;
                    pre[i][j].second = j-1;
                }
            }
        }
    }

    cout << dp[n][m] << endl;
    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= m;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= m;j++) {
            cout << "<" <<pre[i][j].first << "," <<  pre[i][j].second << ">" << " ";
        }
        cout << endl;
    }

    string rslt = "";
    pair<int, int> cur = {n, m};
    pair<int, int> next = pre[n][m];
    while(cur.first != 0 || cur.second != 0) {
        if(next.first == cur.first-1 && next.second == cur.second-1) {
            rslt = str1[cur.first-1] + rslt;
        } else if(next.first == cur.first-1) {
            rslt = str1[cur.first-1] + rslt;
        } else {
            rslt = str2[cur.second-1] + rslt;
        }

        cout << cur.first << " " << cur.second << endl;
        cout << next.first << " " << next.second << endl;
        cout << rslt << endl;

        cur = next;
        next = pre[cur.first][cur.second];
    }

    return rslt;
}

int main() {
    string s1 = "bbbaaaba";
    string s2 = "bbababbb";

    cout << shortestCommonSupersequence(s1, s2) << endl;

    return 1;
}

