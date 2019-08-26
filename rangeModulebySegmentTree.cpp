//todo leetcode 715 : segment tree or map
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct NodeNode {
    int start;
    int end;
    int val;

    bool isSet;

    NodeNode* left;
    NodeNode* right;

    NodeNode(int start, int end, int val, bool isSet): start(start), end(end), val(val), isSet(isSet), left(nullptr), right(nullptr) {}
};

class RangeModule {
public:
    NodeNode* root;

    void update(NodeNode* root, int start, int end, int val) {
        if(!root || end < root->start || start > root->end) return;

        if(start <= root->start && end >= root->end) {
            root->val = val;
            root->isSet = true;
            return;
        }

        int mid = root->start + (root->end - root->start)/2;
        if(!root->left)
            root->left = new NodeNode(root->start, mid, root->val, true);
        if(!root->right)
            root->right = new NodeNode(mid + 1, root->end, root->val, true);

        if(root->isSet) {
            update(root->left, root->start, mid, root->val);
            update(root->right, mid + 1, root->end, root->val);
            root->isSet = false;
        }

        update(root->left, start, end, val);
        update(root->right, start, end, val);
    }

    int sum = 0;
    void query(NodeNode* root, int start, int end) {
        if(!root || end < root->start || start > root->end) return;
        if(root->isSet) {
            sum += (min(end, root->end) - max(start, root->start) + 1)*root->val;
            return;
        }
        query(root->left, start, end);
        query(root->right, start, end);
    }

    void print(NodeNode* root, string pre) {
        if(!root) return;
        cout << pre << "<" << root->start << "," << root->end << ">, " << root->val << ", " << root->isSet << endl;
        print(root->left, pre + "-");
        print(root->right, pre + "-");
    }
public:
    RangeModule() {
        root = new NodeNode(0, 1e9, 0, true);
    }

    void addRange(int left, int right) {
        update(root, left, right, 1);
    }

    bool queryRange(int left, int right) {
        sum = 0;
        query(root, left, right);
        return sum == right - left;
    }

    void removeRange(int left, int right) {
        update(root, left, right, 0);
    }
};

int main() {
    RangeModule module;
    module.addRange(10, 20);
    module.print(module.root, "");
    module.removeRange(14, 16);
    cout << (module.queryRange(10, 14) == true) << endl;
    cout << (module.queryRange(13, 15) == false) << endl;
    cout << (module.queryRange(16, 17) == true) << endl;
}