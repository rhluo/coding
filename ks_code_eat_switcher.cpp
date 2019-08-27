//todo kick start E: Code-Eat Switcher
//todo greedy

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<unordered_map>
using namespace std;

const int N = 1e5 + 10;

struct slot {
    long long c;
    long long e;
}slots[N];

static bool cmp(slot s1, slot s2) {
    return s1.c * s2.e > s1.e * s2.c;
}

long long sa[N], sb[N];
int d, s;

bool cal2(long long wantC, long long wantE) {
    if (wantC > sa[s] || wantE > sb[s])
        return false;

    int l = 1, r = s;
    while (l < r) {
        int m = (l + r) >> 1;
        if (sa[m] >= wantC) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    /* double c = sb[n] - sb[l] + (sa[l] - a) / p[l].x * p[l].y - b; */
    long long cc = (sb[s] - sb[l]) * slots[l].c + (sa[l] - wantC) * slots[l].e - wantE * slots[l].c;
    if (cc >= 0)
        return true;
    return false;
}

int main() {
    int T;
    cin >> T;

    for(int cases = 1;cases <= T; cases++) {
        cin >> d >> s;

        for(int i = 1;i <= s;i++) {
            cin >> slots[i].c >> slots[i].e;
        }

        sort(slots+1, slots+s+1, cmp);


        for(int i = 1;i <= s; i++) {
            sa[i] = sa[i-1] + slots[i].c;
            sb[i] = sb[i-1] + slots[i].e;
        }

        string rslt = "";
        for(int j = 0;j < d;j++) {
            long long wantC, wantE;
            cin >> wantC >> wantE;
            if(cal2(wantC, wantE)) rslt += "Y";
            else rslt += "N";
        }

        printf("Case #%d: %s\n", cases, rslt.c_str());
    }

    return 0;
}
/*
2
4 2
3 8
6 10
0 18
3 13
10 0
7 3
1 2
4 4
4 4
0 0

1
4 2
3 8
6 10
0 18
3 13
10 0
7 3

1
1 2
3 8
6 10
10 0

 */