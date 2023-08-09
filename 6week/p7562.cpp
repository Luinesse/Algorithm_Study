#include <iostream>
#include <queue>

using namespace std;

int n, l;
int res[300][300];
int visited[300][300];
queue<pair<int, int>> q;

int knightX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int knightY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void BFS(int tarX, int tarY)
{
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = 1;
        q.pop();
        if(x == tarX && y == tarY)
        {
            cout << res[x][y] << '\n';
            return;
        }

        for(int i = 0; i < 8; i++)
        {
            int nextX = x + knightX[i];
            int nextY = y + knightY[i];

            if(nextX >= 0 && nextX < l && nextY >= 0 && nextY < l && visited[nextX][nextY] == 0)
            {
                visited[nextX][nextY] = 1;
                res[nextX][nextY] = res[x][y] + 1;
                q.push({nextX, nextY});
            }
        }
    }
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> l;
        int curX, curY;
        int targetX, targetY;
        cin >> curX >> curY;
        cin >> targetX >> targetY;

        q.push({curX, curY});
        BFS(targetX, targetY);

        for(int i = 0; i < 300; i++)
        {
            for(int k = 0; k < 300; k++)
            {
                visited[i][k] = 0;
                res[i][k] = 0;
            }
        }
        
        while(!q.empty())
            q.pop();
    }

    return 0;
}