#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int matrix[n][2], dp[n][n] = {0,};
    for(int i = 0; i < n; ++i)
        cin >> matrix[i][0] >> matrix[i][1];

    for(int i = 1; i < n; i++)
    {
        for(int k = 0; k + i < n; k++)
        {
            int end = i + k;

            dp[k][end] = 1e9;
            for(int j =  k; j < end; j++)
            {
                int last = matrix[k][0] * matrix[j][1] * matrix[end][1];
                int front = dp[k][j] + dp[j + 1][end] + last;

                dp[k][end] = min(dp[k][end], front);
            }
        }
    }

    cout << dp[0][n-1] << endl;

    return 0;
}