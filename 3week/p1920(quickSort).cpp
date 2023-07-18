#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int target)
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

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main()
{
    int n;
    cin >> n;

    int arr[n]; 
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    qsort(arr, n, sizeof(int), compare);

    int x;
    cin >> x;

    int tar[x];
    for(int i = 0; i < x; i++)
        cin >> tar[i];
    
    for(int i = 0; i < x; i++)
        cout << binarySearch(arr,n,tar[i]) << "\n";
    
    return 0;
}