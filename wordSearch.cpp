//
// Created by huazai on 2019/6/13.
//
#include <string>
#include <iostream>
#include <vector>

//todo leetcode
using namespace std;

struct TreeNode {
    string word;
    bool isword;
    TreeNode* children[26] = {nullptr};
    TreeNode() {
        isword = false;
    };
};

TreeNode* root;
vector<string> rslt;

vector<vector<int>> dis = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void makeTree(vector<string> words) {
    root = new TreeNode();

    for(const auto & word : words) {
        auto point = root;
        for(const auto & c : word) {
            int id = c - 'a';
            if(point->children[id] == nullptr) {
                point->children[id] = new TreeNode();
            }
            point = point->children[id];
        }
        point->word = word;
        point->isword = true;
    }
}

void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited, TreeNode* curnode) {
    if(curnode->isword) {
        rslt.push_back(curnode->word);
        curnode->isword = false;
    }

    int n = board.size();
    int m = board[0].size();

    for(int i = 0;i < 4;i++) {
        int nx = x + dis[i][0];
        int ny = y + dis[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!visited[nx][ny] && curnode->children[board[nx][ny] - 'a']) {
            visited[nx][ny] = true;
            dfs(nx, ny, board, visited, curnode->children[board[nx][ny] - 'a']);
            visited[nx][ny] = false;
        }
    }
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    makeTree(words);
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(!visited[i][j] && root->children[board[i][j] - 'a']) {
                visited[i][j] = true;
                dfs(i, j, board, visited, root->children[board[i][j] - 'a']);
                visited[i][j] = false;
            }
        }
    }

    return rslt;
}

int main() {
    vector<vector<char>> board = {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'}
            };
    vector<string> words = {"oath","pea","eat","rain"};
    auto list = findWords(board, words);
    for(const auto & str : list) {
        cout << str << endl;
    }
    return 0;
}

/*
Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 */