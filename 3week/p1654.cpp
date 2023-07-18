#include <iostream>

using namespace std;

bool isPos(int* arr, int n, long long int mid, int tar)
{
    int tmp = 0;
    for(int i = 0; i < n; i++)
        tmp += arr[i] / mid;

    return (tmp >= tar);
}

long long int binarySearch(int* arr, int n, int last, int tar)
{
    long long int mid;
    long long int left = 1, right = last;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(isPos(arr,n,mid,tar))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left - 1;
}

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main()
{
    int n,k,max = 0;
    cin >> n >> k;

    int lan[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> lan[i];
        max = (lan[i] > max) ? lan[i] : max;
    }

    qsort(lan,n,sizeof(int),compare);

    cout << binarySearch(lan,n,max,k) << "\n";

    return 0;
}