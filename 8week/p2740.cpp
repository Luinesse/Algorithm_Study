#include <iostream>

using namespace std;

int matA[101][101];
int matB[101][101];
int res[101][101];

int main() {
    int n, m, k;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matA[i][j];
        }
    }

    cin >> m >> k;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            cin >> matB[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            for(int l = 0; l < m; l++) {
                res[i][j] += matA[i][l] * matB[l][j];
            }
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}