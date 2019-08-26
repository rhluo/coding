#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<unsigned int> save;

int wy1() {
    int q;

    cin >> q;

    vector<int> arr;
    for (int i = 0 ; i < q; i++) {
        int op, num;
        cin >> op >> num;

        if(op == 1) {
            for(const auto & it : arr) {
                int temp = it | num;
                if(save.count(temp) == 0) {
                    save.insert(temp);
                }
            }
            if(save.count(num) == 0) {
                save.insert(num);
            }

            arr.push_back(num);
        } else {
            if(save.count(num) > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    }

    return 0;
}
/*
9
1 4
2 5
1 9
1 15
2 4
1 11
2 10
2 7
2 9

*/


int wy2() {
    int n, q;

    cin >> n >> q;

    vector<int> arr;
    for (int i = 0 ; i < n ; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i = 0;i < q; i++) {
        int x;
        cin >> x;

        int count = 0;
        for(int j = 0;j < n; j++) {
            if(arr[j] >= x) {
                arr[j]--;
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
/*
4 3
1 2 3 4
4
3
1



*/

int wy3() {
    int n;

    cin >> n;
    vector<int> stu;
    for (int i = 0 ; i < n ; i++) {
        int temp;
        cin >> temp;
        stu.push_back(temp);
    }

    vector<int> count(151, 0);
    for(const auto & it : stu) {
        count[it]++;
    }

    vector<int> pre(151, 0);
    pre[0] = count[0];
    for(int i = 1;i <= 150; i++) {
        pre[i] = pre[i-1] + count[i];
    }

    int q;
    cin >> q;
    for(int i = 0;i < q; i++) {
        int req;
        cin >> req;
        double rslt = (pre[stu[req-1]] - 1 - 0.0)/n * 100;
        printf("%.6lf\n", rslt);
        // cout << solve(req) << endl;
    }

    return 0;
}

bool match(int n, int m, int x, int y) {
    if(n >= x && m >= y) return true;
    if(n >= y && m >= x) return true;
    return false;
}

int wy4() {
    int t;

    cin >> t;
    for (int i = 0 ; i < t ; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<bool>> input(n, vector<bool>(m, true));

        for(int j = 0;j < k;j++) {
            int x, y;
            cin >> x >> y;
            input[x-1][y-1] = false;
        }

        int needx, needy;
        cin >> needx >> needy;
        if(needx > needy)
            swap(needx, needy);

        vector<vector<int>> count(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m; j++) {
                if(!input[i][j]) continue;
                count[i][j]++;
                if(j > 0)
                    count[i][j] += count[i][j-1];
            }
        }

        bool ism = false;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                int maxl = count[i][j];
                int len = 1;

                if(match(maxl, len, needx, needy)) {
                    ism = true;
                    break;
                }

                for(int q = i-1;q >= 0;q--) {
                    maxl = min(maxl, count[q][j]);
                    len++;

                    if(match(maxl, len, needx, needy)) {
                        ism = true;
                        break;
                    }
                }
            }
        }

        if(ism)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}