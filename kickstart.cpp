#include<iostream>
#include <climits>
#include "vector"
#include "algorithm"
using namespace std;

int countOne(int m)
{
    int count = 0;
    while (m)
    {
        m = m&(m - 1);
        count++;
    }
    return count;
}


struct SegmentTreeNode
{
    int start, end, sum, len;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b):start(a),end(b),sum(0),len(0),left(nullptr),right(nullptr){}
};

class NumArray {
private:
    SegmentTreeNode* root;
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end)
    {
        if(start > end) return nullptr;
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        if(start == end)
        {
            root->sum = nums[start];
            if(countOne(root->sum)%2 == 0)
                root->len = 1;
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum ^ root->right->sum;
        if(countOne(root->sum)%2 == 0) {
            root->len = root->end - root->start + 1;
        }
        return root;
    }

    int modifyTree(int i, int val, SegmentTreeNode* root)
    {
        if(root == nullptr) return 0;
        int diff;
        if(root->start == i && root->end == i)
        {
            diff = val ^ root->sum;
            root->sum = root->sum ^ diff;
            if(countOne(root->sum)%2 == 0) {
                root->len = 1;
            } else {
                root->len = 0;
            }
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if(i > mid) diff = modifyTree(i,val,root->right);
        else diff = modifyTree(i,val,root->left);
        root->sum = root->sum ^ diff;
        if(countOne(root->sum)%2 == 0) {
            root->len = root->end - root->start + 1;
        } else {
            root->len = 0;
        }
        return diff;
    }

    int maxRight(SegmentTreeNode* root) {
//        cout << "maxR:" << root->start << " " << root->end << " " << root->len << endl;
        if(!root) return 0;
        if(root && root->len > 0) return root->len;
        if(root->right) {
            return maxRight(root->right);
        }
        return 0;
    }

    int maxLeft(SegmentTreeNode* root) {
        if(!root) return 0;
        if(root && root->len > 0) return root->len;
        if(root->left) {
            return maxLeft(root->left);
        }
        return 0;
    }

    int sum = 0;
    void queryTree(SegmentTreeNode* root)
    {
        if(root == nullptr) return;
        sum = max(sum, root->len);
        sum = max(sum, maxRight(root->left) + maxLeft(root->right));
//        cout << "maxR : " << maxRight(root->left) << endl;
//        cout << "maxL : " << maxLeft(root->right) << endl;
//        cout << root->start << " " << root->end << " " << sum << endl;

        if(root->left && sum < root->left->end - root->left->start + 1)
            queryTree(root->left);
        if(root->right && sum < root->right->end - root->right->start + 1)
            queryTree(root->right);

//        cout << root->start << " " << root->end << " " << sum << endl;
    }
    void print(SegmentTreeNode* root, string pre) {
        if(!root) return;
        cout << pre << "<" << root->start << "," << root->end << ">, " << root->sum << ", " << root->len << endl;
        print(root->left, pre + "-");
        print(root->right, pre + "-");
    }
public:
    NumArray(vector<int> nums) {
        root = buildTree(nums,0,nums.size()-1);
    }

    void update(int i, int val) {
        modifyTree(i,val,root);
    }

    int sumRange() {
        sum = 0;
        queryTree(root);
        return sum;
    }

    void print() {
        print(root, "");
    }
};

//int main() {
//    vector<int> test = {10, 21, 3, 7};
//    NumArray* t = new NumArray(test);
//    cout << t->sumRange() << endl;
//    t->print();
//    cout << "-----" << endl;
//
//    t->update(1, 13);
//    cout << t->sumRange() << endl;
//    t->print();
//    cout << "-----" << endl;
//
//    t->update(0, 32);
//    cout << t->sumRange() << endl;
//    t->print();
//}

int main() {

    int line;

    cin >> line;

    for (int i = 0 ; i < line ; i++) {
        int n,q;
        cin >> n >> q;

//        cout << "n&q: " << n << " " << q << endl;

        vector<int> arr(n, 0);
        for(int j = 0;j < n;j++) {
            cin >> arr[j];
        }

        NumArray* obj = new NumArray(arr);

        vector<int> rslt;
        for(int j = 0;j < q;j++) {
            int a,b;
            cin >> a >> b;
//            cout << "a&b : " << a << " " << b << endl;
            obj->update(a, b);
            rslt.push_back(obj->sumRange());
        }

        cout << "Case #" << i+1 << ":";
        for(int i = 0; i < rslt.size(); i++) {
            cout << " " << rslt[i];
        }
        cout << endl;
    }

    return 0;
}
/*
2
4 3
0 1 0 0
1 13
0 32
2 22
5 1
14 1 15 20 26
4 26

Case #1: 4 3 4
Case #2: 4

 */