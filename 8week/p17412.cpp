#include <iostream>
#include <queue>

using namespace std;

int n, p, ans;
int flow[401][401];
int capacity[401][401];
vector<vector<int>> adj;
const int src = 1, dst = 2;

void edmonds() {
    while(1) {
        queue<int> q;
        q.push(src);
        vector<int> parent(n + 1, -1);
        int minFlow = 1e9;

        while(!q.empty()) {             //BFS 탐색
            int cur = q.front();
            q.pop();

            for(int next : adj[cur]) {              //루프를 돌때마다 adj[cur]의 원소를 next에 대입.
                if(capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
                    if(next == dst) break;
                }
            }
        }

        if(parent[dst] == -1) break;

        for(int i = dst; i != src; i = parent[i]) {
            minFlow = min(minFlow, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        for(int i = dst; i != src; i = parent[i]) {
            flow[parent[i]][i] += minFlow;
            flow[i][parent[i]] -= minFlow;
        }
        ans += minFlow;
    }

    return;
}

int main() {

    cin >> n >> p;

    adj.resize(n + 1);

    for(int i = 0; i < p; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
        capacity[from][to] = 1;
    }

    edmonds();

    cout << ans;

    return 0;
}