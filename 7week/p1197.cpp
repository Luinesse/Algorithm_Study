#include <iostream>
#include <queue> 

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;            //넣을 값, 컨테이너(pop, push 등을 위한), 비교함수
vector<pair<int, int>> graph[10001];
bool visited[10001];

int v, e, a, b, weight;

int Prim(int start) {
    int res = 0;
    minHeap.push({0, start});
    while(!minHeap.empty()) {
        int start = minHeap.top().second;
        int value = minHeap.top().first;
        minHeap.pop();

        if(visited[start])
            continue;

        visited[start] = true;
        res += value;
        for(int i = 0; i < graph[start].size(); i++) {
            pair<int, int> next = graph[start][i];
            if(visited[next.first])
                continue;
            minHeap.push({next.second, next.first});
        }
    }

    return res;
}

int main() {

    cin >> v >> e;

    for(int i = 0; i < e; i++) {
        cin >> a >> b >> weight;
        graph[a].push_back({b, weight});
        graph[b].push_back({a, weight});
    }

    cout << Prim(1);

    return 0;
}