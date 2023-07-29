#include <iostream>

using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;

    while(n > 0)
    {
        if(n % 5 == 0)
        {
            n -= 5;
            res++;
        }
        else if(n % 3 ==0)
        {
            n -= 3;
            res++;
        }
        else if(n > 5)
        {
            n -= 5;
            res++;
        }
        else
        {
            res = -1;
            break;
        }
    }

    cout << res;

    return 0;
}