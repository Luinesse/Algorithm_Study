#include <iostream>

using namespace std;

int arr[1001] = {0,};
int dp[1001] = {0,};

int main()
{
    int max = 0;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;

        for(int k = 0; k < i; k++)
        {
            if(arr[i] > arr[k] && dp[i] < dp[k] + 1)
                dp[i] = dp[k] + 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(max < dp[i])
            max = dp[i];
    }

    cout << max << endl;

    return 0;
}