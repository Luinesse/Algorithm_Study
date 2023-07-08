#include <iostream>
#include <cstring>

using namespace std;

int stack[100] = {0,};
int top = 0;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        char temp[51];
        bool isFault = false;
        cin >> temp;
        int length = strlen(temp);
        for(int k = 0; k < length; ++k)
        {
            if(temp[k] == '(')
            {
                stack[top] = 1;
                top++;
            }
            if(temp[k] == ')')
            {
                if(top > 0)
                {
                    stack[top] = 0;
                    top--;
                }
                else
                {
                    cout << "NO" << endl;
                    isFault = true;
                    break;
                }
            }
        }
        if(top > 0 && !isFault)
            cout << "NO" << endl;
        else if(top == 0 && !isFault)
            cout << "YES" << endl;

        top = 0;
    }

    return 0;
}