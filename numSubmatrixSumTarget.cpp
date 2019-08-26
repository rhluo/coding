//todo leetcode 1074. Number of Submatrices That Sum to Target: dp

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> sum(n, vector<int>(m, 0));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(j == 0) {
                sum[i][j] = matrix[i][j];
            } else {
                sum[i][j] = sum[i][j-1] + matrix[i][j];
            }
        }
    }

//         for(int i = 0;i < n;i++) {
//             for(int j = 0;j < m;j++) {
//                 cout << sum[i][j] << " ";
//             }
//             cout << endl;
//         }

    int rslt = 0;
    for(int i = 0;i < m;i++) {
        for(int j = i;j < m;j++) {
            unordered_map<int, int> counter;
            counter[0] = 1;
            int temp = 0;
            for(int k = 0;k < n;k++) {
                temp += sum[k][j] - (i>0? sum[k][i-1] : 0);
                rslt += counter[temp - target];
                counter[temp]++;
                //cout << i << " " << j << " " << k << " : " << temp << endl;
            }
        }
    }

    return rslt;
}

/*
 * x i 0 j x x
 * x i 1 j x x
 * x i 2 j x x
 * x i 3 j x x
 * if k = 3, temp = V, and k = 0, temp = V - target, then k = 1-3, sum = target
 */

int main() {
    vector<vector<int>> matrix = {{0,1,0},{1,1,1},{0,1,0}};
    int target = 0;

    cout << numSubmatrixSumTarget(matrix, target) << endl;

    return 1;
}