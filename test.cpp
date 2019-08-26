#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    int start;
    int end;
    int sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b): start(a), end(b), sum(0), left(nullptr), right(nullptr) {}
};

SegmentTreeNode* treeRoot;

SegmentTreeNode* buildTree(vector<int>& arr, int start, int end) {
    if(start > end) return nullptr;
    SegmentTreeNode* root = new SegmentTreeNode(start, end);
    if(start == end) {
        root->sum = arr[start];
        return root;
    }

    int mid = start + (end - start)/2;
    root->left = buildTree(arr, start, mid);
    root->right = buildTree(arr, mid+1, end);
    root->sum = root->left->sum + root->right->sum;
    return root;
}

int modifyTree(int pos, int newval, SegmentTreeNode* root) {
    if(root == nullptr) return 0;
    int diff;
    if(root->start == pos && root->end == pos) {
        diff = newval - root->sum;
        root->sum = newval;
        return diff;
    }
    int mid = root->start + (root->end - root->start)/2;
    if(pos <= mid) diff = modifyTree(pos, newval, root->left);
    else diff = modifyTree(pos, newval, root->right);
    return diff;
}

int queryTree(int from, int to, SegmentTreeNode* root) {
    if(root == nullptr) return 0;
    if(root->start == from && root->end == to) {
        return root->sum;
    }
    int mid = root->start + (root->end - root->start)/2;
    if(from > mid) return queryTree(from, to, root->right);
    else if(to <= mid) return queryTree(from, to, root->left);
    return queryTree(from, mid, root->left) + queryTree(mid+1, to, root->right);
}

