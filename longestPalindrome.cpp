#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestPalindrome(string s)
{
    string manaStr = "$#";
    for (int i=0;i<s.size();i++) //首先构造出新的字符串
    {
        manaStr += s[i];
        manaStr += '#';
    }
    vector<int> rd(manaStr.size(), 0);//用一个辅助数组来记录最大的回文串长度，注意这里记录的是新串的长度，原串的长度要减去1
    int pos = 0, mx = 0;
    int start = 0, maxLen = 0;
    for (int i = 1; i < manaStr.size(); i++)
    {
        rd[i] = i < mx ? min(rd[2 * pos - i], mx - i) : 1;
        while (i+rd[i]<manaStr.size() && i-rd[i]>0 && manaStr[i + rd[i]] == manaStr[i - rd[i]])//这里要注意数组越界的判断，源代码没有注意，release下没有报错
            rd[i]++;
        if (i + rd[i] > mx) //如果新计算的最右侧端点大于mx,则更新pos和mx
        {
            pos = i;
            mx = i + rd[i];
        }
        if (rd[i] - 1 > maxLen)
        {
            start = (i - rd[i]) / 2;
            maxLen = rd[i] - 1;

            cout << i << " " << manaStr[i] << " " << rd[i] << " : " << " " << start << " " << maxLen << endl;
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    string test = "aaaba";
    cout << longestPalindrome(test) << endl;
    return 0;
}
//ref: https://www.cnblogs.com/mini-coconut/p/9074315.html