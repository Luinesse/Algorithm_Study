#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

deque<int> dq;

int main()
{
    int n, tmp;
    char opCode[20];
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> opCode;
        if(strcmp(opCode,"push_front") == 0)
        {
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if(strcmp(opCode,"push_back") == 0)
        {
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if(strcmp(opCode, "pop_front") == 0)
        {
            if(dq.empty())
                cout << "-1" << endl;
            else
            {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if(strcmp(opCode, "pop_back") == 0)
        {
            if(dq.empty())
                cout << "-1" << endl;
            else
            {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if(strcmp(opCode, "size") == 0)
        {
            cout << dq.size() << endl;
        }
        else if(strcmp(opCode, "empty") == 0)
        {
            if(dq.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else if(strcmp(opCode, "front") == 0)
        {
            if(dq.empty())
                cout << "-1" << endl;
            else
                cout << dq.front() << endl;
        }
        else if(strcmp(opCode, "back") == 0)
        {
            if(dq.empty())
                cout << "-1" << endl;
            else
                cout << dq.back() << endl;
        }
    }

    return 0;
}