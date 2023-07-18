#include <iostream>

using namespace std;

int binarySearch(int* arr, int l, int r, int target)
{
    int mid;

    while(l < r)
    {
        mid = (l + r) / 2;
        if(arr[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

int main()
{
    int n, tmp, idx = 0;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n; i++)
    {
        cin >> tmp;

        if(i == 0)  arr[0] = tmp;

        if(tmp > arr[idx])
            arr[++idx] = tmp;
        else
            arr[binarySearch(arr,0,idx,tmp)] = tmp;
    }

    cout << idx + 1 << endl;

    return 0;

    return 0;
}