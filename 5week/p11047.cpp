#include <iostream>

using namespace std;

int main()
{
    int n, k, res = 0;
    cin >> n >> k;

    int value[n];

    for(int i = 0; i < n; i++)
        cin >> value[i];

    for(int i = n - 1; i >= 0; i--)
    {
        if(k >= value[i])
        {
            res += k / value[i];
            k %= value[i];
        }
    }

    cout << res << endl;
}