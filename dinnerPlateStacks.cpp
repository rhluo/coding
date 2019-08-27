//todo leetcode 1172. Dinner Plate Stacks
//todo hash map
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;


class DinnerPlates {
    int c;
    map<int, vector<int>> m;
    set<int> avaiable;
public:
    DinnerPlates(int capacity) {
        this->c = capacity;
    }

    void push(int val) {
        if(avaiable.size() == 0) {
            avaiable.insert(m.size());
        }
        m[*avaiable.begin()].push_back(val);
        if(m[*avaiable.begin()].size() == c)
            avaiable.erase(avaiable.begin());
    }

    int pop() {
        if(m.size() == 0)
            return -1;
        return popAtStack(m.rbegin()->first);
    }

    int popAtStack(int index) {
        if(m.size() == 0)
            return -1;
        int val = m[index].back();
        m[index].pop_back();
        avaiable.insert(index);
        if(m[index].size() == 0)
            m.erase(index);
        return val;
    }
};

int main() {
    DinnerPlates D = DinnerPlates(2);  // Initialize with capacity = 2
    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5);         // The stacks are now:  2  4
                                         //    1  3  5
                                         //    ﹈ ﹈ ﹈
    cout << D.popAtStack(0);   // Returns 2.  The stacks are now:     4
                                                             //    1  3  5
                                                             //    ﹈ ﹈ ﹈
    D.push(20);        // The stacks are now: 20  4
                                         //    1  3  5
                                         //    ﹈ ﹈ ﹈
    D.push(21);        // The stacks are now: 20  4 21
                                        //    1  3  5
                                        //    ﹈ ﹈ ﹈
    cout << D.popAtStack(0);   // Returns 20.  The stacks are now:     4 21
                                                              //    1  3  5
                                                              //    ﹈ ﹈ ﹈
    cout << D.popAtStack(2);   // Returns 21.  The stacks are now:     4
                                                              //    1  3  5
                                                              //    ﹈ ﹈ ﹈
    cout << D.pop();            // Returns 5.  The stacks are now:      4
                                                               //    1  3
                                                               //    ﹈ ﹈
    cout << D.pop();            // Returns 4.  The stacks are now:   1  3
                                                               //    ﹈ ﹈
    cout << D.pop();            // Returns 3.  The stacks are now:   1
                                                               //    ﹈
    cout << D.pop();            // Returns 1.  There are no stacks.
    cout << D.pop();            // Returns -1.  There are still no stacks.
    return 0;
}
