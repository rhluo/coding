//todo kick start: Circuit Board
//todo acWing 833 电路板: https://www.acwing.com/problem/content/835/

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 310;
int arr[N][N];
int minv[N][N];
int maxv[N][N];

/**
 * 三层for循环，分别是子矩阵的长度，子矩阵开始位置的列数，子矩阵开始位置的行数
 * minv/maxv分别表示在arr[j][i]位置开始长度为len的子数组中的最小最大值
 * @return
 */
int main() {
    int T;
    cin >> T;
    for(int cases = 1;cases <= T; cases++) {
        int r,c,k;
        cin >> r >> c >> k;
        for(int i = 0;i < r;i++) {
            for(int j = 0;j < c;j++) {
                cin >> arr[i][j];
            }
        }

        int rslt = r;
        for(int len = 1;len <= c;len++) {
            for(int i = 0;i <= c-len;i++) {
                for(int j = 0, count = 0;j < r;j++) {

                    if(len == 1) {
                        minv[j][i] = maxv[j][i] = arr[j][i];
                    } else {
                        minv[j][i] = min(minv[j][i], arr[j][i+len-1]);
                        maxv[j][i] = max(maxv[j][i], arr[j][i+len-1]);
                    }

                    if(maxv[j][i] - minv[j][i] <= k) {
                        // cout << j << " " << i << " " << count << " " << len << endl;
                        count++;
                        rslt = max(rslt, count*min(len, c-i));
                    } else {
                        count = 0;
                    }

                }
            }
        }

        printf("Case #%d: %d\n", cases, rslt);
    }

    return 0;
}
/*
3
1 4 0
3 1 3 3
2 3 0
4 4 5
7 6 6
4 5 0
2 2 4 4 20
8 3 3 3 12
6 6 3 3 3
1 6 8 6 4

Case #1: 2
Case #2: 2
Case #3: 6

3
1 4 2
3 1 3 3
3 3 2
0 5 0
8 12 3
7 10 1
4 4 8
20 10 20 10
10 4 5 20
20 5 4 10
10 20 10 20

Case #1: 4
Case #2: 3
Case #3: 4
 */