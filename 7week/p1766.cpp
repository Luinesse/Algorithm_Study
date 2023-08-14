#include <iostream>
#include <queue>

using namespace std;

vector<int> graph[32001];
priority_queue<int, vector<int>, greater<int>> q;
int n, m, a, b;
int indgree[32001];

void BFS(int size) {
    for(int i = 1; i <= size; i++) {
        if(indgree[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int idx = q.top();
        q.pop();

        cout << idx << " ";

        for(int i = 0; i < graph[idx].size(); i++) {
            if(indgree[graph[idx][i]] == 1)
                q.push(graph[idx][i]);
            if(indgree[graph[idx][i]] > 0)
                indgree[graph[idx][i]]--;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indgree[b]++;
    }

    BFS(n);

    return 0;
}