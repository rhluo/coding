//
// Created by huazai on 2019/6/14.
//
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int item;
    Node* next;
};

class PersistentStack {
    Node* root;
    int _size;
public:
    PersistentStack() {
        root = nullptr;
        _size = 0;
    }

    PersistentStack(Node* root, int size) {
        this->root = root;
        this->_size = size;
    }

    PersistentStack* pop() {
        if(size() == 0)
            return new PersistentStack();
        return new PersistentStack(root->next, _size - 1);
    }

    PersistentStack* push(int value) {
        Node* newRoot = new Node();
        newRoot->next = root;
        newRoot->item = value;
        return new PersistentStack(newRoot, _size + 1);
    }

    int top() {
        if(size() == 0)
            return -1;
        return root->item;
    }

    Node* getRoot() {
        return root;
    }

    int size() {
        return _size;
    }
};

int main() {
    vector<PersistentStack*> op;
    op.push_back(new PersistentStack());
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int action, value;
        cin >> action >> value;
        if(action == 1) {
            auto ret = op.back()->push(value);
            op.push_back(ret);
        } else if(action == 2){
            auto ret = op.back()->pop();
            op.push_back(ret);
        } else {
            auto root = op[value]->getRoot();
            while(root != nullptr) {
                cout << root->item << " ";
                root = root->next;
            }
            cout << endl;
        }
    }
}
/*
5
1 1
1 2
2 0
1 3
3 3

5
1 1
1 2
2 0
1 3
3 2
 */