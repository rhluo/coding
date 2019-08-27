//todo leetcode 1171. Remove Zero Sum Consecutive Nodes from Linked List

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeZeroSumSublists(ListNode* head) {
    //cout << "???" << endl;
    unordered_map<int, pair<ListNode*, int>> presum;
    ListNode* vhead = new ListNode(0);
    vhead->next = head;
    presum.insert({0, {vhead, 0}});

    int delpos = 0;

    int ps = 0;
    auto point = vhead->next;
    int curpos = 0;
    while(point != nullptr) {
        curpos++;
        ps += point->val;

        //cout << ps << " " << curpos << " " << endl;
        if(presum.count(ps) > 0 && presum[ps].second >= delpos) {
            presum[ps].first->next = point->next;
            delpos = curpos;
            presum[ps] = {presum[ps].first, curpos};
        } else {
            presum[ps] = {point, curpos};
        }

        point = point->next;
    }

    return vhead->next;
}

ListNode* removeZeroSumSublists2(ListNode* head) {
    //cout << "???" << endl;
    unordered_map<int, ListNode*> presum;
    ListNode* vhead = new ListNode(0);
    vhead->next = head;
    presum.insert({0, vhead});

    int ps = 0;
    auto point = vhead->next;
    while(point != nullptr) {
        ps += point->val;

        if(presum.count(ps) > 0 ) {
            presum[ps]->next = point->next;
            return removeZeroSumSublists2(vhead->next);
        } else {
            presum[ps] = point;
        }
        point = point->next;
    }

    return vhead->next;
}

ListNode* create(vector<int>& arr) {
    ListNode* vhead = new ListNode(-1);
    auto p = vhead;
    for(const auto & it : arr) {
        p->next = new ListNode(it);
        p = p->next;
    }
    return vhead->next;
}

void print(ListNode* root) {
    while(root != nullptr) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main() {
//    vector<int> test = {1,2,3,-3,4};
    vector<int> test = {1,2,3,-3,-2};
    auto tree = create(test);
    auto rslt = removeZeroSumSublists2(tree);
    print(rslt);

    return 0;
}