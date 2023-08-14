#include <iostream>

using namespace std;

int v, e, a, b, c;
int INF = 1e9;
int graph[401][401];

void floyd() {
    for(int i = 1; i <= v; i++) {
        for(int k = 1; k <= v; k++) {
            for(int l = 1; l <= v; l++) {
                if(graph[k][l] > graph[k][i] + graph[i][l])
                    graph[k][l] = graph[k][i] + graph[i][l];
            }
        }
    }
}

int main() {

    cin >> v >> e;

    for(int i = 1; i <= v; i++) {
        for(int k = 1; k <= v; k++) {
            if(i!=k) {
                graph[i][k] = INF;
            } else {
                graph[i][k] = 0;
            }
        }
    }

    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    floyd();

    int res = INF;
    for(int i = 1; i <= v; i++) {
        for(int k = 1; k <= v; k++) {
            if(i == k)  continue;
            res = min(res, graph[i][k] + graph[k][i]);
        }
    }
    cout << ((res == INF) ? -1 : res);

    return 0;
}