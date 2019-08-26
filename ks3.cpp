#include <vector>
#include <iostream>
#include "limits.h"
#include "algorithm"

using namespace std;

int dp(vector<int> distants, vector<int> costs, int K){
    int res = INT_MAX;
    for (int i = 0; i < costs.size() ; i++) {
        vector<vector<int>> dp(costs.size()-1, vector<int>(K+1, 0));
//        int[][] dp = new int[costs.size()-1][K+1];
        vector<int> distants2(costs.size()-1), costs2(costs.size()-1);
//        int[] distants2 = new int[costs.size()-1];
//        int[] costs2 = new int[costs.length-1];
        for (int j = 0, k=0; j < costs.size() ; j++) {
            if(j!=i) {
                distants2[k] = distants[j];
                costs2[k] = costs[j];
                k++;
            }
        }

        for (int j = 0; j < dp.size(); j++) {
            for (int k = 1; k <= j+1&&k<=K ; k++) {
                if(j==0) dp[j][1] = costs2[j] + abs(distants2[j]-distants[i]);
                else if(dp[j-1][k]!=0) dp[j][k] = min(dp[j-1][k], dp[j-1][k-1]+costs2[j]+abs(distants2[j]-distants[i]));
                else  dp[j][k] = dp[j-1][k-1]+costs2[j]+abs(distants2[j]-distants[i]);
            }
        }
        res = min(dp[dp.size()-1][K]+costs[i], res);
    }
    return res;
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


        int rslt = dp(arr, cost, t);
        cout << "Case #" << i+1 << ": " << rslt << endl;
    }

    return 0;
}
/*
1


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