#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

//题目链接
//https://www.acwing.com/problem/content/734/

using queue_t = int;
struct compare {
    bool operator()(const queue_t l1, const queue_t l2) {
        return l1 < l2;
    }
};

long long dp(vector<int> costs) {
    sort(costs.begin(), costs.end());
    const int n = costs.size();
    if(n <= 1)
        return -1;
    else if(n == 2)
        return costs[1];

    vector<long long> arr(n, 0);
    arr[0] = INT_MAX;
    arr[1] = costs[1];
    arr[2] = costs[2];

    for(int i = 3;i < n;i++) {
        //arr[i] = min(arr[i], arr[i-1] + costs[i] + costs[1]);
        arr[i] = min(arr[i], arr[i-1] + costs[i] + costs[1]);
        if(i > 3)
            arr[i] = min(arr[i], arr[i-2] + costs[2] + costs[1] + costs[i] + costs[2]);
        if(i > 4)
            arr[i] = min(arr[i], arr[i-3] + costs[2] + costs[1] + costs[3] + costs[1] + costs[i] + costs[3]);
    }

//    for(int i = 0;i < n;i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;

    return arr[n-1];
}

int crossRiver(vector<int> costs) {
    const int n = costs.size();
    if(n <= 1)
        return -1;
    else if(n == 2)
        return max(costs[0], costs[1]);

    int rslt = 0;

    auto mait = min_element(costs.begin(), costs.end());
    int ma = *mait;
    swap(*mait, *costs.begin());

    auto mbit = min_element(costs.begin()+1, costs.end());
    int mb = *mbit;
    swap(*mbit, *(costs.begin()+1));

    auto mcit = min_element(costs.begin()+2, costs.end());
    int mc = *mcit;
    swap(*mcit, *(costs.begin()+2));

    //cout << ma << " " << mb << " " << mc << endl;

    //rslt += mc + mb;

    priority_queue<queue_t, vector<queue_t >, compare> maxHeap;
    for(auto it = costs.begin()+3;it != costs.end();it++) {
        maxHeap.push(*it);
    }


    while(maxHeap.size() >= 2) {
        auto max1 = maxHeap.top();
        maxHeap.pop();
        auto max2 = maxHeap.top();
        maxHeap.pop();

        rslt += mc + mb + max1 + mc;
    }

    if(maxHeap.size() == 0) {
        rslt += mc;
    } else {
        rslt += mc + mb + maxHeap.top();
    }

    return rslt;
}


string removeDuplicates(string S) {
    stack<char> st;

    string rslt = "";
    int n = S.size();
    int i = 0;
    while(i < n) {
        char c = S[i];
        cout << "t: " << c << endl;
        if(st.size() == 0 || st.top() != c) {
            st.push(c);
        } else {
            st.pop();
        }
        i++;
    }

    while(!st.empty()) {
        char c = st.top();
        rslt = c + rslt;
        st.pop();
    }

    return rslt;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;
}


//int main() {
//    int n;
//    cin >> n;
//    for(int i = 0;i < n;i++) {
//        int num;
//        cin >> num;
//
//        vector<int> input;
//        for(int j = 0;j < num;j++) {
//            int temp;
//            cin >> temp;
//            input.push_back(temp);
//        }
//
//        cout << dp(input) << endl;
//        //cout << crossRiver(input) << endl;
//    }
////    auto rslt = crossRiver(costs);
////    cout << rslt << endl;
//    return 0;
//}
/*
2
2
1 2
4
1 1 1 1

3
5
2 1 4 2 1
9
3 1 1 1 2 3 3 1 2
8
1 4 4 3 1 2 1 1

answer:
10
16
15

1
5
1 2 3 4 6



 */