//todo leetcode 300. Longest Increasing Subsequence: dp O(n2) and O(nlgn)
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int n = nums.size();
    vector<int> dp(n, 1);

    int rslt = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= i;j++) {
            if(nums[j] >= nums[i]) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
        rslt = max(dp[i], rslt);
    }

    return rslt;
}

int lengthOfLTSByBinarySearch(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int n = nums.size();
    vector<int> dp;

    for(int i = 0;i < n;i++) {
        auto item = lower_bound(dp.begin(), dp.end(), nums[i]);
        if(item == dp.end()) dp.push_back(nums[i]);
        else *item = nums[i];
    }

    return dp.size();
}

int main() {
    vector<int> test = {10,9,2,5,3,7,101,18};
    cout << "normal : " << lengthOfLIS(test) << endl;
    cout << "quick : " << lengthOfLTSByBinarySearch(test) << endl;
    return 0;
}
