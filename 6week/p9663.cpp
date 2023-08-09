#include <iostream>

using namespace std;

int res = 0, n;
int locate[15];

bool check(int x)
{
    for(int i = 0; i < x; i++)
    {
        if(locate[i] == locate[x] || abs(locate[x] - locate[i]) == x - i)
            return false;
    }

    return true;
}

void Queen(int x)
{
    if(x == n)
        res++;
    else
    {
        for(int i = 0; i < n; i++)
        {
            locate[x] = i;
            if(check(x))
                Queen(x+1);
        }
    }
}

int main()
{
    cin >> n;

    Queen(0);
    cout << res;

    return 0;
}