#include <iostream>

using namespace std;

int main()
{
    int n, i = 0, tmp, cnt = 0;
    cin >> n;

    while(n != cnt)
    {
        i++;
        tmp = i;

        while(tmp != 0)
        {
            if(tmp % 1000 == 666)
            {
                cnt++;
                break;
            }
            else
                tmp /= 10;
        }
    }

    cout << i;

    return 0;
}