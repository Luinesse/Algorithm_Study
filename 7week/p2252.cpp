#include <iostream>
#include <queue>

using namespace std;

int n, m, a, b;
vector<int> graph[32001];
queue<int> q;
int visited[32001], indgree[32001];

void BFS(int n) {
    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int idx = q.front();
        q.pop();

        cout << idx << " ";

        for (int i = 0; i < graph[idx].size(); i++) {
            if(indgree[graph[idx][i]] == 1)
                q.push(graph[idx][i]);
            if(indgree[graph[idx][i]] > 0)
                indgree[graph[idx][i]]--;
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indgree[b]++;
    }

    BFS(n);

    return 0;
}