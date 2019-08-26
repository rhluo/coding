//todo kick start: swinging walk
//todo 832 546 摇摆行走: https://www.acwing.com/problem/content/834/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int N = 50010, INF = 1e9;

set<pair<int, int>> row[N], col[N];

void insert(set<pair<int, int>>& map, int x) {
    auto left = map.lower_bound({x, x});
    auto right = left--;
    bool l = false, r = false;
    if(left->second == x-1) l = true;
    if(right->first == x+1) r = true;

//    cout << x << " " << l << " " << r << endl;

    if(l && r) {
        map.insert({left->first, right->second});
        map.erase(left);
        map.erase(right);
    } else if(l) {
        map.insert({left->first, x});
        map.erase(left);
    } else if(r) {
        map.insert({x, right->second});
        map.erase(right);
    } else {
        map.insert({x, x});
    }
}

int move(set<pair<int, int>>& map, int x, int dir) {
    auto left = map.lower_bound({x, x});
    auto right = left--;
    if(dir == 1) {
        return (right->first == x+1)?right->second+1:x+1;
    } else {
        return (left->second == x-1)?left->first-1:x-1;
    }
}

int main() {
    int T;
    cin >> T;
    for(int cases = 1 ;cases <= T; cases++) {
        int n,r,c;

        int x, y;
        cin >> n >> r >> c >> x >> y;

        for(int i = 1;i <= r;i++) {
            row[i].clear();
            row[i].insert({-INF, -INF});
            row[i].insert({INF,INF});
        }

        for(int i = 1;i <= c;i++) {
            col[i].clear();
            col[i].insert({-INF, -INF});
            col[i].insert({INF, INF});
        }

//        cout << x << " " << y << endl;
//
//        insert(row[x], y);
//        insert(col[y], x);

        for(int i = 0; i < n; i++) {
            char ops;
            cin >> ops;

            int dx, dy;

            if(ops == 'N') {
                dy = y;
                dx = move(col[y], x, -1);
            } else if(ops == 'S') {
                dy = y;
                dx = move(col[y], x, +1);
            } else if(ops == 'W') {
                dx = x;
                dy = move(row[x], y, -1);
            } else {
                dx = x;
                dy = move(row[x], y, +1);
            }

//            cout << x << " " << y << endl;

            insert(row[x], y);
            insert(col[y], x);

            x = dx, y = dy;
        }

        printf("Case #%d: %d %d\n", cases, x, y);
    }


    return 0;
}
/*
3
5 3 6 2 3
EEWNS
4 3 3 1 1
SESE
11 5 8 3 4
NEESSWWNESE

1
5 3 6 2 3
EEWNS

 */