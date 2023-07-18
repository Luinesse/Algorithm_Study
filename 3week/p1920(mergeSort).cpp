#include <iostream>

using namespace std;

int binarySearch(int* arr, int n, int target)
{
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(target > arr[mid])
            left = mid + 1;
        else if(target < arr[mid])
            right = mid - 1;
        else
            return 1;
    }

    return 0;
}

void mergeSort(int* arr, int start, int end)
{
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    int i = start;
    int j = mid + 1;
    int k = 0;
    int* list = (int*)malloc(sizeof(int) * end + 1);

    while(i <= mid && j <= end)
    {
        (arr[i] < arr[j]) ? list[k++] = arr[i++] : list[k++] = arr[j++];
    }

    while(i <= mid)
        list[k++] = arr[i++];
    while(j <= end)
        list[k++] = arr[j++];

    for(int i = start; i <= end; i++)
        arr[i] = list[i - start];

    free(list);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr,0,n-1);

    int x;
    cin >> x;

    int tar[x];
    for(int i = 0; i < x; i++)
        cin >> tar[i];
    
    for(int i = 0; i < x; i++)
        cout << binarySearch(arr,n,tar[i]) << "\n";
    
    return 0;
}