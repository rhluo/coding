//todo kick start: Yogurt
//todo acWing 552 酸奶: https://www.acwing.com/problem/content/554/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 5010;
vector<int> s(M, 0);

int main() {
    int T;
    cin >> T;
    for(int cases = 1;cases <= T; cases++) {
        int n, k;
        cin >> n >> k;
        for(int i = 0;i < n; i++) cin >> s[i];
        sort(s.begin(), s.begin()+n);
        // for(int i = 0;i < n; i++) {
        //     cout << s[i] << " ";
        // }
        // cout << endl;

        int rslt = 0;
        //贪心的每一天尽可能的多吃，并且每一天尽可能吃快过期的，所以排序之后，从后往前吃即可
        for(int day = 1, pos = 0;day <= n && pos < n; day++) {
            while(pos < n && s[pos] < day) pos++;
            rslt += min(k, n - pos);
            pos += k;
        }

        printf("Case #%d: %d\n", cases, rslt);
    }
    return 0;
}
/*
4
2 1
1 1
5 1
3 2 3 2 3
2 2
1 1
6 2
1 1 1 7 7 7

Case #1: 1
Case #2: 3
Case #3: 2
Case #4: 5
 */