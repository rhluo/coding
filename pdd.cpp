#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

int cal(vector<bool>& input) {
    int n = input.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    int count = 0;
    for(int i = 0;i < n; i++) {
        left[i] = i > 0 ? left[i-1] + count : count;
        if(input[i]) count++;
    }

    count = 0;
    for(int i = n-1;i >= 0; i--) {
        right[i] = i < n-1? right[i+1] + count : count;
        if(input[i]) count++;
    }

    int rslt = INT_MAX;
    for(int i = 0;i < n; i++) {
        rslt = min(rslt, left[i] + right[i]);
    }

    return rslt;
}

int main() {
    int l, n;
    cin >> l >> n;
    vector<bool> test(l, false);

    for(int i = 0;i < n; i++) {
        int pos;
        cin >> pos;
        test[pos] = true;
    }

    cout << cal(test) << endl;
    return 0;
}
/*
1000 4
1 4 998 995

 */

//int cal(vector<vector<int>>& input) {
//    int n = input.size();
//    int rslt = 0;
//    vector<int> count(n, 0);
//    for(const auto & it : input) {
//        for(const auto & next : it) {
//            count[next]++;
//        }
//    }
//
//    queue<int> path;
//
//    vector<bool> visit(n, false);
//    int visitCount = 0;
//
//    for(int i = 0;i < count.size(); i++) {
//        if(count[i] == 0) {
//            rslt++;
//            path.push(i);
//            visit[i] = true;
//            visitCount++;
//        }
//    }
//
//    while(visitCount < n) {
//        int len = path.size();
//        for(int i = 0;i < len; i++) {
//            auto node = path.front();
//            path.pop();
//            for(const auto & next : input[node]) {
//                if(!visit[next]) {
//                    visit[next] = true;
//                    path.push(next);
//                    visitCount++;
//                }
//            }
//        }
//
//        if(path.size() == 0 && visitCount < n) {
//            for(int num = 0;num < n;num++) {
//                if(visit[num]) {
//                    continue;
//                } else {
//                    visit[num] = true;
//                    visitCount++;
//                    rslt++;
//                    path.push(num);
//                    break;
//                }
//            }
//        }
//    }
//
//    return rslt;
//}

//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> test(n, vector<int>(0));
//    for(int i = 0; i < m; i++) {
//        int from, to;
//        cin >> from >> to;
//
////        cout << from << " " << to << endl;
//        test[from-1].push_back(to-1);
//    }
//
////    for(const auto it : test) {
////        for(const auto item : it) {
////            cout << item << " ";
////        }
////        cout << endl;
////    }
//
//
////    vector<vector<int>> test = {{2},{2},{3, 4},{},{}, {6}, {7}, {5}};
//    cout << cal(test) << endl;
//    return 0;
//}
/*
8 7
1 3
2 3
3 4
3 5
6 7
7 8
8 6


 */