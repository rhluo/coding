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


int main() {

    int line;

    cin >> line;

    for (int i = 0 ; i < line ; i++) {
        int t,n;
        cin >> t >> n;

//        cout << "n&q: " << n << " " << q << endl;

        vector<int> arr(n, 0);
        vector<int> w(n-1, 1);
        for(int j = 0;j < n;j++) {
            cin >> arr[j];
        }

        vector<int> cost(n, 0);
        for(int j = 0;j < n; j++) {
            cin >> cost[j];
        }

        int minv = INT_MAX;
        for(int i = 0;i < n;i++) {
            auto pos = arr[i];
            vector<int> temp;
            for(int k = 0;k < n; k++) {
                if(k != i) {
                    int v = cost[k] + (int)abs(pos-arr[k]);
                    temp.push_back(v);
                }
            }
            minv = min(minv, package(w, temp, t));
        }
        cout << "Case #" << i+1 << ": " << minv << endl;
    }

    return 0;
}
/*
3
2 4
1 2 3 10
100 70 80 20
1 5
150 300 301 400 700
8 35 26 5 2
6 7
22 21 20 23 26 25 24
10 10 10 10 10 10 10


 */

