#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp                      //이 부분은 연산자 오버로딩과 우선순위 큐 라이브러리의 관계를 알아야 이해가 더 쉬울것같다.
{
    bool operator()(int n1, int n2)
    {
        if(abs(n1) > abs(n2))
            return true;
        else if(abs(n1) == abs(n2))
        {
            if(n1 > n2)
                return true;
            else
                return false;
        }
        return false;
    }
};

int main()
{
    priority_queue<int, vector<int>, cmp> pq;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x != 0)
        {
            pq.push(x);
        }
        else
        {
            if(pq.size() > 0)
            {
                cout << pq.top() << endl;
                pq.pop();
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}