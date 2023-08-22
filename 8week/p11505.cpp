#include <iostream>

using namespace std;

const int MOD = 1000000007;
long long int arr[1000001];
long long int seg[4000001];

long long int Init(int start, int end, int nodeNum) {
    if(start == end)
        return seg[nodeNum] = arr[start];

    int mid = (start + end) / 2;
    return seg[nodeNum] = (Init(start, mid, nodeNum * 2) * Init(mid + 1, end, nodeNum * 2 + 1)) % MOD;
}

long long int Multiply(int start, int end, int nodeNum, int left, int right) {
    if(left > end || right < start)
        return 1;
    
    if(left <= start && right >= end)
        return seg[nodeNum];

    int mid = (start + end) / 2;
    return (Multiply(start, mid, nodeNum * 2, left, right) * Multiply(mid + 1, end, nodeNum * 2 + 1, left, right)) % MOD;
}

void update(int start, int end, int nodeNum, int targetIdx, int val) {
    if(targetIdx < start || targetIdx > end)
        return;

    if(start == end)
    {
        seg[nodeNum] = val;
        return;
    }
        
    int mid = (start + end) / 2;
    update(start, mid, nodeNum * 2, targetIdx, val);
    update(mid + 1, end, nodeNum * 2 + 1, targetIdx, val);
    seg[nodeNum] = (seg[nodeNum * 2] * seg[nodeNum * 2 + 1]) % MOD;
}

int main() {
    int n, m, k;
    int a, b, c;

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Init(0, n-1, 1);

    for(int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            update(0, n-1, 1, b - 1, c);
        } else {
            cout << Multiply(0, n-1, 1, b-1, c-1) << "\n";
        }
    }


    return 0;
}