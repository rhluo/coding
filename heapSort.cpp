//todo heap Sort: build heap complex : O(n)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int left(int root) {
    return (root+1)*2 - 1;
}

int right(int root) {
    return (root+1)*2;
}

void adjust(vector<int>& arr, int len, int pos) {
    int l = left(pos);
    int r = right(pos);

    int maxPos = pos;
    if(l < len && arr[l] > arr[maxPos]) {
        maxPos = l;
    }
    if(r < len && arr[r] > arr[maxPos]) {
        maxPos = r;
    }

    if(maxPos != pos) {
        swap(arr[maxPos], arr[pos]);
        adjust(arr, len, maxPos);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = n/2 - 1; i>= 0; i--) {
        adjust(arr, n, i);
    }

    for(int len = n - 1; len > 0; len--) {
        swap(arr[0], arr[len]);
        adjust(arr, len, 0);
    }
}

int main() {
    vector<int> test = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(test);

    for(const auto & it : test) {
        cout << it << " ";
    }

    return 0;
}