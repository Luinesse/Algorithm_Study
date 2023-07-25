#include <iostream>

using namespace std;

int city[201];
int res[1001] = {0,};

int Find(int key)
{
    if(key == city[key])    return key;
    else return city[key] = Find(city[key]);
}

void Union(int a, int b)
{
    int ta = Find(a);
    int tb = Find(b);
    if(ta != tb)    city[ta] = tb;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int tmp;

    for(int i = 1; i <= 200; i++)
        city[i] = i;

    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= n; k++)
        {
            cin >> tmp;
            if(tmp)
                Union(i,k);
        }
    }

    int prev = 0;
    for(int i = 1; i <= m; i++)
    {
        cin >> tmp;
        res[i] = Find(tmp);
        if(i == 1)
            prev = Find(tmp);
        else
        {
            if(prev != res[i])
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}