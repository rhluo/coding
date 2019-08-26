//todo leetcode 1043 Partition Array for Maximum Sum : dp
#include <iostream>
#include <vector>

using namespace std;

int maxSumAfterPartitioning(vector<int>& input, int K) {
    int n = input.size();
    vector<int> dp(n, 0);
    dp[0] = input[0];
    for(int i = 1;i < n; i++) {
        int maxnum = input[i];
        int currmax = maxnum + dp[i - 1];
        for(int k = 1;k < K && i - k >= 0; k++) {
            maxnum = max(maxnum, input[i-k]);
            currmax = max(currmax, maxnum * (k + 1) + (i-k-1>=0?dp[i-k-1]:0));
        }
        dp[i] = currmax;
    }

//    for(const auto item : dp) {
//        cout << item << " ";
//    }

    return dp[n-1];
}

int main() {
    vector<int> A = {1,15,7,9,2,5,10}; // result : 84
    int K = 3;

    auto rslt = maxSumAfterPartitioning(A, K);

    cout << rslt << endl;

    return 0;
}