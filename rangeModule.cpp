//todo leetcode 715 : segment tree or map
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class RangeModule {
public:
    map<int, int> m;
    RangeModule() {

    }

    void addRange(int left, int right) {
        removeRange(left, right);
        m[left] = right;
        auto it = m.find(left);
        if (it != m.begin() && prev(it)->second == left) {//[10, 15),#[15, 20)#=>[10, 20)
            it--;
            it->second = right;
            m.erase(left);
        }
        if (it != prev(m.end()) && next(it)->first == right) {//#[10, 15)#,[15, 20)=>[10, 20)
            it->second = next(it)->second;
            m.erase(next(it));
        }
    }

    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (m.empty() || it == m.begin()) return false;
        it--;
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        if (m.empty()) return;
        auto it = m.lower_bound(left);
        if (it != m.begin()) it--;
        vector<int> v;
        while (it != m.end() && it->first < right) {
            if (it->first < left && it->second > left) {//it->first < left < (it->second < right || right < it->second)
                int tmp = it->second;
                it->second = left;
                if (tmp > right) {
                    m[right] = tmp;
                }
            } else if (it->first >= left) {//left < it->first < (it->second < right || right < it->second)
                v.push_back(it->first);
                if (it->second > right) {
                    m[right] = it->second;
                }
            }
            it++;
        }
        for (int i : v) m.erase(i);
    }
};

int main() {
    RangeModule module;
    module.addRange(10, 20);
    module.removeRange(14, 16);
    cout << (module.queryRange(10, 14) == true) << endl;
    cout << (module.queryRange(13, 15) == false) << endl;
    cout << (module.queryRange(16, 17) == true) << endl;
}