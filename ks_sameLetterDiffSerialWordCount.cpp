//todo kick start: same Letter different serialize word count
//todo acWing 555. 相同字母异序词: https://www.acwing.com/problem/content/557/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<cstring>

using namespace std;
//通常k进制，这个进制数取131或者13331
const int p = 131;
typedef unsigned long long ULL;

//本质上是模2^64,即unsigned long long的长度
ULL get_hash(int arr[]) {
    ULL rslt = 0;
    for(int i = 0;i < 26; i++) rslt = rslt*p + arr[i];
    return rslt;
}


int main() {
    int T;
    cin >> T;
    for(int cases = 1;cases <= T; cases++) {
        int n;
        cin >> n;
        string A, B;
        cin >> A >> B;

        //本质上就是给定两个数组，比较A数组中的数是否在B数组中出现过
        unordered_set<ULL> s;

        int count[26];
        for(int i = 0;i < n; i++) {
            for(int j = i;j < n;j++) {
                memset(count, 0, sizeof(count));
                for(int k = i;k <= j;k++) count[B[k] - 'A']++;
                s.insert(get_hash(count));
            }
        }

        int rslt = 0;
        for(int i = 0; i < n;i++) {
            for(int j = i;j < n; j++) {
                memset(count, 0, sizeof(count));
                for(int k = i;k <= j;k++) count[A[k] - 'A']++;
                if(s.count(get_hash(count)) > 0) rslt++;
            }
        }

        printf("Case #%d: %d\n", cases, rslt);
    }

    return 0;

}
/*
6
3
ABB
BAB
3
BAB
ABB
6
CATYYY
XXXTAC
9
SUBXXXXXX
SUBBUSUSB
4
AAAA
AAAA
19
PLEASEHELPIMTRAPPED
INAKICKSTARTFACTORY


Case #1: 5
Case #2: 6
Case #3: 6
Case #4: 6
Case #5: 10
Case #6: 9
 */