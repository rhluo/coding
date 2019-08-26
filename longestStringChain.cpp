//todo leetcode 1048 : longest string chain : dp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

static bool compare(const string& s1, const string&s2) {
    return s1.size() < s2.size();
}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), compare);
    unordered_map<string, int> prenum;
    for(const auto & word : words) {
        int maxv = 0;
        for(int i = 0;i < word.size(); i++) {
            string temp = word.substr(0, i) + word.substr(i + 1);
            maxv = max(maxv, prenum[temp] + 1);
        }

        prenum[word] = maxv;
    }

    int rslt = 0;
    for(const auto & item : prenum) {
        rslt = max(rslt, item.second);
    }
    return rslt;
}

int main() {
    vector<string> words = {"a","b","ba","bca","bda","bdca"};

    cout << longestStrChain(words) << endl;

    return 1;
}