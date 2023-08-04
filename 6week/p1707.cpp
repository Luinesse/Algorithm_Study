#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[20001];
int visited[20001] = {0,};
int n, v, e, x, y;

void dfs(int start)
{
    if(!visited[start])
        visited[start] = 1;

    int gSize = graph[start].size();
    for(int i = 0; i < gSize; i++)
    {
        int next = graph[start][i];
        if(!visited[next])
        {
            if(visited[start] == 1)
                visited[next] = 2;
            else if(visited[start] == 2)
                visited[next] = 1;
            dfs(next);
        }
    }
}

bool isPos()
{
    for(int k = 1; k <= v; k++)
        {
            int gSize = graph[k].size();
            for(int l = 0; l < gSize; l++)
            {
                int next = graph[k][l];
                if(visited[k] == visited[next])
                    return false;
            }
        }
        return true;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> v >> e;

        for(int k = 0; k < e; k++)
        {
            cin >> x >> y;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int k = 0; k < v; k++)
        {
            if(!visited[k])
                dfs(k);
        }

        if(isPos())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        for(int k = 0; k <= v; k++)
            graph[k].clear();

        for(int k = 0; k < 20001; k++)
            visited[k] = 0;
    }

    return 0;
}