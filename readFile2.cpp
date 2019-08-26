#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, string> kv;

void solve(string line) {
    string key;
    int n = line.size();
    int i;
    for(i = 0;i < n;i++) {
        if(line[i] != '=') {
            key = key + line[i];
        } else {
            break;
        }
    }
    string value = line.substr(i+1);
    cout << stoi(value) << endl;
    cout << atoi(value.c_str()) << endl;
    kv.insert({key, value});
}

void GetNext(string p, vector<int>& next) {
    int pLen = p.length();
    next.resize(pLen, 0);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        //p[k]表示前缀，p[j]表示后缀
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int main() {
    string test = "ABCDABD";
    vector<int> next;
    GetNext(test, next);
    for(const auto & it : next) {
        cout << it << " ";
    }
}

//int main() {
//    ifstream infile;
//    infile.open("test.in");
//
//    ofstream outfile;
//    outfile.open("test.out");
//
//    string find = "name3";
//
//    string line;
//    for(int i = 0;i < 3;i++) {
//        infile >> line;
//        solve(line);
//    }
//
//    if(kv.count(find) > 0)
//        outfile << kv[find] << endl;
//    else
//        outfile << "NULL" << endl;
//
//    return 0;
//}