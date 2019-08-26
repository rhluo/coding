#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

int getMatrix() {
    vector<vector<int>> input;

    int n;
    cin >> n;

    for(int i = 0;i < n;i++) {
        vector<int> b;
        int num;
        while (cin >> num) {
            b.push_back(num);
            if (cin.get() == '\n')   //遇到回车，终止
                break;
        }
        input.push_back(b);
    }

    for(const auto & it : input) {
        for(const auto & item : it) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}

int main() {
    string line;
    while(getline(cin, line)) {
        cout<<line<<endl;
    }
}
/*
3
1 2 3 5
4 3 5
7 6 5

1
2 3 5

fasdfafndsakjfnas
asdfasfasdfasdfasfasdf
asdfasdf


 */