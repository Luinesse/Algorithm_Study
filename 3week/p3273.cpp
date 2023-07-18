#include <iostream>

using namespace std;

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main()
{
    int n, x, res = 0;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    cin >> x;

    qsort(arr,n,sizeof(int),compare);

    int lp = 0, rp = n-1;

    while(lp < rp)
    {
        if(arr[lp] + arr[rp] < x)
            lp++;
        else if(arr[lp] + arr[rp] > x)
            rp--;
        else
        {
            lp++;
            rp--;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}