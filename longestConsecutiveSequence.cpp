//todo leetcode 128: union find
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> f;

int find(int x) {
    if(f[x] != x) {
        f[x] = find(f[x]);
    }
    return f[x];
}

void uni(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px != py)
        f[px] = py;
}

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    f.resize(n, 0);

    unordered_map<int, int> dict;
    for(int i = 0;i < n; i++) {
        f[i] = i;
        if(dict.count(nums[i]) == 0) {
            dict[nums[i]] = i;
        }
    }

    for(int i = 0;i < n; i++) {
        if(dict.count(nums[i] - 1) > 0) {
            uni(dict[nums[i]], dict[nums[i] - 1]);
        }

        if(dict.count(nums[i] + 1) > 0) {
            uni(dict[nums[i]], dict[nums[i] + 1]);
        }
    }

    vector<int> count(n, 0);
    int rslt = 0;

    for(int i = 0;i < n;i++) {
        int root = find(i);
        count[root]++;
        rslt = max(rslt, count[root]);
    }

    return rslt;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << longestConsecutive(nums) << endl;

    return 1;
}