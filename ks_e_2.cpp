#include <iostream>
#include <math.h>

using namespace std;

const int N = 1e6+10 + 5;
int oddCount[N], evenCount[N];

pair<int, int> cal(int num) {
    int odd = 0, even = 0;

    int snum = sqrt(num);
    for(int i = 1;i <= snum; i++) {
        if(num%i == 0) {
            if(i & 1)
                odd++;
            else
                even++;

            int j = num/i;
            if(i == j) continue;
            if(j & 1)
                odd++;
            else even++;
        }
    }

    return {odd, even};
}

int main() {
    for(int i = 1;i < N;i++) {
        auto temp = cal(i);
        oddCount[i] = temp.first;
        evenCount[i] = temp.second;
    }

//    for(int i = 1;i <= 10;i++) {
//        cout << i <<  ": " << oddCount[i] << " " << evenCount[i] << endl;
//    }

    int T;
    cin >> T;
    for(int cases = 1; cases <= T;cases++) {
        int l,r;
        cin >> l >> r;

        int count = 0;
        for(int k = l;k <= r;k++) {
            if(oddCount[k] - evenCount[k] >= -2 && oddCount[k] - evenCount[k] <= 2) {
                count++;
            }
        }

        printf("Case #%d: %d\n", cases, count);
    }

    return 0;
}
/*
2
5 10
102 102


 */