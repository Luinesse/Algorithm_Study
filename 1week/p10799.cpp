#include <iostream>
#include <cstring>

using namespace std;

int stack[200000] = {0,};
int top = 0;

int main()
{
    int res = 0;
    char input[100001];
    cin >> input;

    int length = strlen(input);

    for(int i = 0; i < length; ++i)
    {
        if(top > 0)
        {
            if(input[i] == '(')
            {
                stack[top++] = 1;
                res++;
            }
            if(input[i] == ')' && input[i-1] == '(')
            {
                res--;
                stack[--top] = 0;
                res += top;
            }
            if(input[i] == ')' && input[i-1] == ')')
            {
                stack[--top] = 0;
            }

        }
        else
        {
            stack[top++] = 1;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}