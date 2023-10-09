#include <iostream>

using namespace std;

void setDepth(int a, int* parent, int* depth)
{
    if(parent[a] == 0)
        return;
    else
    {
        setDepth(parent[a], parent, depth);
        depth[a] = depth[parent[a]] + 1;
    }
}

int LCA(int x, int y, int* parent, int* depth)
{
    while(depth[x] > depth[y])
        x = parent[x];

    while(depth[x] < depth[y])
        y = parent[y];

    while(x != y)
    {
        x = parent[x];
        y = parent[y];
    }

    return x;
}

int main()
{
    int t;
    cin >> t;

    int parent[10001] = {0,};
    int depth[10001];

    for(int i = 0; i < 10001; i++)
        depth[i] = 1;

    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        for(int k = 0; k < n - 1; k++)
        {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
        }

        for(int k = 1; k <= n; k++)
            setDepth(k, parent, depth);

        int t1, t2;
        cin >> t1 >> t2;

        cout << LCA(t1, t2, parent, depth) << endl;

        for(int k = 0; k < 10001; k++)
        {
            depth[k] = 1;
            parent[k] = 0;
        }
    }

    return 0;
}