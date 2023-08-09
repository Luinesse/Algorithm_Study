#include <iostream>
#include <vector>

using namespace std;

int n;
int score[20][20];
bool check[20];
int minValue = 99999;

void team(int idx, int cnt) {
    vector<int> start;
    vector<int> link;
    int stScore = 0;
    int liScore = 0;
    if(cnt == (n / 2)) {
        for(int i = 0; i < n; i++) {
            if(check[i])
                start.push_back(i);
            else
                link.push_back(i);
        }
        for(int i = 0; i < (n/2); i++) {
            for(int k = 0; k < (n/2); k++) {
                stScore += score[start[i]][start[k]];
                liScore += score[link[i]][link[k]];
            }
        }
        if(abs(stScore - liScore) < minValue)
            minValue = abs(stScore - liScore);
        return;
    }

    for(int i = idx; i < n; i++) {
        if(check[i])
            continue;
        else {
            check[i] = true;                        // i번째 사람을 팀에 포함시킴.
            team(i,cnt+1);                          // 재귀적으로 반복하며 절반의 사람을 같은팀으로 포함시킴.
            check[i] = false;                       // 위 함수가 끝나고 다시 false로 대입하여 다음 i번째팀원부터 절반의 사람을 포함시킨 경우로 시행.
        }
    }
}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            cin >> score[i][k];
        }
    }
    team(0,0);
    cout << minValue;

    return 0;
}