//todo kick start B : Building Palindromes
//todo presum

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N = 100010;

int presum[26][N];
int n, q;

int main() {
    int T;
    cin >> T;
    for(int cases = 1;cases <= T;cases++) {
        cin >> n >> q;
        string str;
        cin >> str;
        memset(presum, 0, sizeof presum);
        for(int i = 1;i <= n;i++) {
            for(int j = 0;j < 26;j++) {
                presum[j][i] += presum[j][i-1];
            }
            presum[str[i-1] - 'A'][i]++;
        }

        int rslt = 0;
        for(int i = 0;i < q;i++) {
            int l, r;
            cin >> l >> r;

            int count = 0;
            for(int j = 0;j < 26;j++) {
                if((presum[j][r] - presum[j][l-1]) & 1) count++;
            }
            //cout << l << " " << r << " " << count << endl;
            if(count <= 1) rslt++;
        }

        printf("Case #%d: %d\n", cases, rslt);
    }
}
