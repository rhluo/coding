//todo leetcode 1049 : Last Stone Weight II : dp 0-1package
#include <vector>
#include <iostream>

using namespace std;

int package(vector<int>& w, vector<int>& v, int maxw) {
    int n = w.size();
    int m = maxw;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0;i <= n;i++) {
        dp[i][0] = 0;
    }

    for(int j = 0;j <= m;j++) {
        dp[0][j] = 0;
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= w[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - w[i-1]] + v[i-1]);
            }
        }
    }

//    for(int i = 0;i <= n;i++) {
//        for(int j = 0;j <= m;j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    return dp[n][m];
}

int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for(const auto it : stones) {
        sum += it;
    }

//    cout << sum << " " << sum/2 << endl;

    int half = sum/2;
    auto rslt = package(stones, stones, half);
    return sum - rslt - rslt;
}

int main() {
    vector<int> stones = {2,7,4,1,8,1};
    cout << lastStoneWeightII(stones) << endl;
    return 1;
}