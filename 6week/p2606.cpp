#include <iostream>
#include <vector>

using namespace std;

int n, network, res = 0;
int visited[101] = {0,};
vector<int> graph[101];

void dfs(int start) {
    if(!visited[start])
        visited[start] = 1;

    int gSize = graph[start].size();
    for(int i = 0; i < gSize; i++) {
        int next = graph[start][i];
        if(!visited[next]) {
            visited[next] = 1;
            res++;
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> network;

    for(int i = 0; i < network; i++) {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    dfs(1);
    cout << res;

    return 0;
}