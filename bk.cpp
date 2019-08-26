#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double T = 10.0/9;

int cal(vector<int>& input) {
    sort(input.begin(), input.end());
    int count = 0;
    for(auto it = input.begin();it < input.end(); it++) {
        //cout << "value : " << *it*T << endl;
        auto bigger = upper_bound(input.begin(), input.end(), *it*T);
        count += (bigger - it) - 1;
        //cout << it-input.begin() << " : " << count << endl;
    }

    return count;
}


int func(vector<int>& arr){
    int res = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        int cur = 0;
        int left = 0;
        for (int j = 0; j < i; j++) {
            int temp = max(left - arr[j] + 1, 0);
            cur += temp;
            left = temp + arr[j];

//            cout << arr[j] <<  " " << left << endl;
        }
//        cout << endl;
        int right = 0;
        for (int j = arr.size()-1; j>i ; j--) {
            int temp = max(right - arr[j] + 1, 0);
            cur += temp;
            right = temp + arr[j];

//            cout << arr[j] << " " <<  right << endl;
        }
//        cout << endl;
        cur += max(max(left, right) + 1 - arr[i], 0);

        cout << i << "  " << left << " : " << right << " : " << cur << endl;
        res = min(res, cur);
    }
    return res;
}

int main() {
    vector<int> test = {1, 4, 3, 2, 5};
    cout << func(test) << endl;
//    cout << "result : " << cal(test) << endl;

    return 0;
}