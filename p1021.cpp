#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main()
{
    int idx, tmp;
    int n, m, cnt = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        dq.push_back(i);

    for(int i = 0; i < m; ++i)
    {
        cin >> tmp;

        for (int k = 0; k < dq.size(); ++k)
		{
			if (tmp == dq[k])
			{
				idx = k;
				break;
			}
		}

        if(idx <= dq.size() / 2)
        {
            while(1)
            {
                if(tmp == dq.front())
                {
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            while(1)
            {
                if(tmp == dq.front())
                {
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << cnt << endl;

    return 0;
}