#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

using queue_t = pair<list<int>::iterator, list<int>::iterator>;
struct compare {
    bool operator()(const queue_t l1, const queue_t l2) {
        return *l1.first > *l2.first;
    }
};

//使用优先队列
//复杂度n*log(k)，n为最长的list的长度，k为list集合的个数
list<int> intersectionQ(vector<list<int>> input) {
    const int n = input.size();
    list<int> rslt;

    priority_queue<queue_t , vector<queue_t>, compare> pq;
    int x = INT_MIN;
    int count = 0;
    for(int i = 0;i < n;i++) {
        if(!input[i].empty()) {
            pq.push({input[i].begin(), input[i].end()});
        }
    }

    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        if(*node.first == x) {
            count++;
        } else {
            x = *node.first;
            count = 1;
        }
        if(count == n) {
            rslt.push_back(x);
        }
        node.first++;
        if(node.first != node.second) {
            pq.push(node);
        }

        if(count + pq.size() < n)
            break;
    }
    return rslt;
}

//直接挑最大
//复杂度n*k，n为最长的list的长度，k为list集合的个数
list<int> intersection(vector<list<int>> input) {
    const int n = input.size();
    list<int> rslt;
    vector<list<int>::iterator> pointers(n);
    for(int i = 0;i < n;i++) {
        pointers[i] = input[i].begin();
    }

    for(;;) {
        int count = 0;
        for(int i = 0;i < n;i++) {
            if(pointers[i] != input[i].end())
                count++;
        }

        if(count < n)
            return rslt;

        int maxv = *pointers[0];
        for(int i = 1;i < n;i++) {
            if(maxv < *pointers[i]) {
                maxv = *pointers[i];
            }
        }

        int curcount = 0;
        for(int i = 0;i < n;i++) {
            if(*pointers[i] == maxv) {
                curcount++;
            } else {
                pointers[i]++;
            }
        }

        if(curcount == n) {
            rslt.push_back(maxv);
            for(int i = 0;i < n;i++) {
                pointers[i]++;
            }
        }
    }
}


int main() {
    vector<list<int>>  input = {
            {1,2,3,4,5,6,7,8},
            {-1,3,4,6,7},
            {-1,3,5,6,7,9},
    };

    auto rslt = intersectionQ(input);
    for(const auto & it : rslt) {
        cout << it << " ";
    }

    return 0;
}