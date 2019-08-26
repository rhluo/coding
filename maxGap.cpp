//todo leetcode 164 : Maximum Gap
//todo radix sort(bucket sort)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void countSort(vector<int>& nums, const int exp) {
    vector<int> count(10, 0);
    for(auto num : nums) {
        count[(num/exp)%10]++;
    }

    for(int i = 1;i < 10;i++) {
        count[i] += count[i-1];
    }

    vector<int> temp(nums.size(), 0);
    for(int i = nums.size()-1;i >= 0;i--) {
        temp[count[(nums[i]/exp)%10] - 1] = nums[i];
        count[(nums[i]/exp)%10]--;
    }

    nums = temp;
}

void radixSort(vector<int>& nums) {
    int maxv = *max_element(nums.begin(), nums.end());

    //cout << maxv << endl;

    for(int i = 1;maxv/i>0;i*=10) {
        countSort(nums, i);
    }
}

int maximumGap(vector<int>& nums) {
    if(nums.size() < 2) return 0;

    radixSort(nums);

    // for(auto num : nums) {
    //     cout << num << " ";
    // }
    // cout << endl;

    int rslt = INT_MIN;
    int pre = nums[0];
    for(int i = 1;i < nums.size();i++) {
        rslt = max(rslt, nums[i] - pre);
        pre = nums[i];
    }

    return rslt;
}

int main() {
    vector<int> test = {3,6,9,1};
    //result : 3
    cout << maximumGap(test) << endl;

    return 0;
}