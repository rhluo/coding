#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> reverseAndToNum(string input) {
    vector<int> rslt;
    for(int i = input.size()-1;i >= 0;i--) {
        int num = input[i] - '0';
        rslt.push_back(num);
    }

    return rslt;
}

string toStrAndReverse(vector<int> input) {
    string rslt = "";
    for(int i = 0;i < input.size();i++) {
        char ch = input[i] + '0';
        rslt = ch + rslt;
    }

    return rslt;
}

string multiply(string str1, string str2) {
    auto num1 = reverseAndToNum(str1);
    auto num2 = reverseAndToNum(str2);

    int n = num1.size();
    int m = num2.size();
    vector<int> vals(n + m, 0);

    for(int i = 0;i < n; i++) {
        for(int j = 0;j < m;j++) {
            vals[i+j] += num1[i] * num2[j];
        }
    }

//    for(const auto & it : vals) {
//        cout << it << " ";
//    }
//    cout << endl;

    int c = 0;
    for(int i = 0;i < vals.size(); i++) {
        vals[i] += c;
        c = vals[i]/10;
        vals[i] = vals[i]%10;

//        cout << vals[i] << " " << c << endl;
    }
//    cout << endl;


    int point = vals.back();
    while(point == 0) {
        vals.pop_back();
        point = vals.back();
    }

    return toStrAndReverse(vals);
}

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}

int main() {
    string s1 = "99999";
    string s2 = "99999";
    cout << multiply(s1, s2) << endl;
    return 1;
}
