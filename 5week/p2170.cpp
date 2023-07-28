#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, res = 0;
    cin >> n;
    pair<int,int> lines[n];

    for(int i = 0; i < n; i++)
        cin >> lines[i].first >> lines[i].second;

    sort(lines,lines + n);

    int start = lines[0].first;
    int end = lines[0].second;

    for(int i = 1; i < n; i++)
    {
        if(lines[i].first > end)
        {
            res += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
        else
            end = max(end, lines[i].second);
    }
    
    res += end -start;
    cout << res;

    return 0;
}