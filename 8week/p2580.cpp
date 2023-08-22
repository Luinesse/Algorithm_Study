#include <iostream>
#include <vector>

using namespace std;

bool isPos(int table[9][9], int row, int col, int val) {
    for(int i = 0; i < 9; i++) {
        if(table[row][i] == val && i != col)
            return false;
        if(table[i][col] == val && i != row)
            return false;
    }

    int minR = (row / 3) * 3;
    int maxR = minR + 2;
    int minC = (col / 3) * 3;
    int maxC = minC + 2;

    for(int i = minR; i <= maxR; i++) {
        for(int k = minC; k <= maxC; k++) {
            if(table[i][k] == val && (i != row && k != col))
                return false;
        }
    } 

    return true;
}

bool solve(vector<pair<int, int>> zero, int table[9][9], int complete) {
    if(zero.size() == complete)
        return true;

    int row = zero[complete].first;
    int col = zero[complete].second;

    for(int i = 1; i <= 9; i++) {
        if(isPos(table,row,col,i)) {
            table[row][col] = i;

            if(solve(zero, table, complete + 1))
                return true;
        }
    }

    table[row][col] = 0;
    return false;
}

int main() {
    vector<pair<int, int>> zero;
    int table[9][9];

    for(int i = 0; i < 9; i++) {
        for(int k = 0; k < 9; k++) {
            cin >> table[i][k];

            if(table[i][k] == 0)
                zero.push_back({i, k});
        }
    }

    solve(zero,table,0);
    
    for(int i = 0; i < 9; i++) {
        for(int k = 0; k < 9; k++) {
            cout << table[i][k] << " ";
        }
        cout << "\n";
    }

    return 0;
}