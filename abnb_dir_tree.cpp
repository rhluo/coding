#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;


struct Node{
    int value;
    string name;
    vector<struct Node *> nodes;
    bool operator < (const Node & oth){
        return this->name < oth.name;
    }
    Node(){}
    Node(int val, const string & n):value(val), name(n){}
    Node * find(const string & s){
        for(const auto & ptr:nodes)
            if(ptr->name == s)
                return ptr;
        return NULL;
    }
};

class Tree{
public:
    Node * root;
    Tree & operator = (const Tree & ) = delete;
    Tree(const Tree& ) = delete;-
    Tree(){
        root = new Node(-1, "/");
    }
    void split(vector<string> & vec, const string & s){
        vec.clear();
        for(const auto & c:s){
            if(c== '/')
                vec.push_back("");
            else
                vec.back().push_back(c);
        }
    }

    Node * find(const string & path){
        vector<string> vec;
        split(vec, path);
        Node * now = root;
        for(int index = 0;index < vec.size(); index++){
            now = now->find(vec[index]);
            if(now == NULL) 
                return NULL;
        }
        return now;
    }

    bool create(const string & path, int value){
        vector<string> vec;
        split(vec, path);
        Node * now = root;
        for(int index = 0;index + 1 < vec.size(); index++){
            now = now->find(vec[index]);
            if(now == NULL) 
                return false;
        }
        if(now->find(vec.back()) != NULL)
            return false;
        now->nodes.push_back(new Node(value, vec.back()));
        return true;
    }
    bool set(const string &path, int value){
        Node * now = this->find(path);
        if(now == NULL)
            return false;
        now->value = value;
        return true;
    }

    int get(const string & path){
        Node * now = this->find(path);
        if(now == NULL)
            return -1;
        return now->value;
    }
};


int main(){
    Tree tree;
    cout<< tree.create("/abc/de", 2) << endl;
    cout<< tree.create("/abc", 1) << endl;
    cout << tree.create("/abc/de", 2) << endl;
    cout<<tree.set("/abc", 10) << endl;
    cout<<tree.get("/abc/de")<<endl;
    cout<<tree.get("/abc")<<endl;
    return 0;
}