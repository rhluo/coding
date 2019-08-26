//todo leetcode 1131 : dp manhattan distance
// |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

#include "vector"
#include "iostream"

using namespace std;

int maxAbsValExpr(vector<int>& x, vector<int>& y) {
    int res = 0, n = x.size(), closest, cur;
    for (int p : {1, -1}) {
        for (int q : {1, -1}) {
            closest = p * x[0] + q * y[0] + 0;
            for (int i = 1; i < n; ++i) {
                cur = p * x[i] + q * y[i] + i;
                res = max(res, cur - closest);
                closest = min(closest, cur);
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr1 = {1,2,3,4};
    vector<int> arr2 = {-1,4,5,6};
    cout << maxAbsValExpr(arr1, arr2) << endl;
    return 0;
}