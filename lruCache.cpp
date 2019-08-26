//todo leetcode 146 LRU cache: LRU problem
#include <list>
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
    int capacity;
    list<int> lru;
    unordered_map<int, list<int>::iterator> kpos;
    unordered_map<int, int> kvalue;

    void updateLRU(int key) {
        if(kvalue.count(key) > 0) {
            lru.erase(kpos[key]);
        }
        lru.push_front(key);
        kpos[key] = lru.begin();
    }

    void del() {
        int key = lru.back();
        lru.pop_back();
        kpos.erase(key);
        kvalue.erase(key);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(kvalue.count(key) == 0) return -1;
        updateLRU(key);
        return kvalue[key];
    }

    void put(int key, int value) {
        if(kvalue.size() == capacity && kvalue.count(key) == 0) {
            del();
        }
        updateLRU(key);
        kvalue[key] = value;
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
}
//todo 快排非递归 最大上升子序列 树的序列化与反序列化
