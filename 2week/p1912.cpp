#include <iostream>

using namespace std;

int arr[100001] = {0,};
int DP[100001] = {0,};

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    DP[0] = arr[0];

    for(int i = 1; i < n; ++i)
    {
        if(arr[i] + DP[i - 1] > arr[i])
            DP[i] = arr[i] + DP[i - 1];
        else
            DP[i] = arr[i];
    }

    int max = DP[0];

    for(int i = 1; i < n; ++i)
    {
        if(max < DP[i])
            max = DP[i];
    }

    cout << max << endl;

    return 0;
}