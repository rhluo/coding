//todo quickSort method include template
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

template <class T>
int partition1(vector<T>& arr, int start, int end) {
    int x = arr[end];
    int i = start - 1;
    int j = start;
    for (; j < end; ++j)
        if (arr[j] <= x)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[j]);
    return i + 1;
}

template <class T>
int partition2(vector<T>& arr, int start, int end) {
    int x = arr[start];
    int i = start + 1;
    int j = end;
    while (i <= j) {
        while (arr[j] > x) j--;
        while (arr[i] < x) i++;
        if (i >= j)
            break;
        swap(arr[i++], arr[j--]);
    }
    swap(arr[j], arr[start]);
    return j;
}

//O(n)
int searchK(vector& a, int i, int j, int k)
{
    int m = partition1(a, i, j);
    if (k==m-i+1)  return a[m];
    else if (k<m-i+1)
    {
        return partition1(a, i, m-1,k );
    }
        //后半段
    else
    {
        return partition1(a, m+1, j, k-(m-i+1));
    }
}

template <class T>
void quickSort(vector<T>& arr, int start, int end) {
    if(start < end) {
        int j = partition1(arr, start, end);
        quickSort(arr, start, j-1);
        quickSort(arr, j+1, end);
    }
}

template <class T>
void quickSortNoRecursion(vector<T>& arr, int start, int end) {
    queue<T> st;
    if(start<end)
    {
        int mid = partition2(arr,start,end);
        if(start < mid-1)
        {
            st.push(start);
            st.push(mid-1);
        }
        if(mid+1 < end)
        {
            st.push(mid+1);
            st.push(end);
        }
        while(!st.empty())
        {
            T q=st.front();
            st.pop();
            T p=st.front();
            st.pop();
            mid=partition2(arr,q,p);
            if(q<mid-1)
            {
                st.push(q);
                st.push(mid-1);
            }
            if(mid+1<p)
            {
                st.push(mid+1);
                st.push(p);
            }
        }
    }
}

int main() {
    vector<int> test = {1,8,2,4,5,1,2,8,2,4,5,2,3,4,2,3,5,6};
    quickSort(test,0,17);
    cout << "first: " << endl;
    for(int i=0;i<18;i++)
    {
        cout<<test[i]<<" ";
    }
    cout << endl;

    vector<int> test2 = {1,8,2,4,5,1,2,8,2,4,5,2,3,4,2,3,5,6};
    quickSortNoRecursion(test2,0,17);
    cout << "second: " << endl;
    for(int i=0;i<18;i++)
    {
        cout<<test2[i]<<" ";
    }
    cout << endl;
    return 0;

}
