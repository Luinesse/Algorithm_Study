#include <iostream>

using namespace std;

long long int arr[1000001];
long long segTree[4000004];

long long int Init(int start, int end, int nodeNum)
{
    if(start == end)
        return segTree[nodeNum] = arr[start];

    int mid = (start + end) / 2;
    return segTree[nodeNum] = Init(start,mid, nodeNum * 2) + Init(mid + 1, end, nodeNum * 2 + 1);
}

long long int subSum(int start, int end, int nodeNum, int left, int right)
{
    if(left > end || right < start)
        return 0;

    if(left <= start && end <= right)
        return segTree[nodeNum];
    int mid = (start + end) / 2;
    return subSum(start, mid, nodeNum * 2, left, right) + subSum(mid + 1, end, nodeNum * 2 + 1, left, right);
}

void update(int start, int end, int nodeNum, int targetIdx, long long int val)
{
    if(targetIdx < start || end < targetIdx)
        return;

    segTree[nodeNum] += val;
    if(start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, nodeNum * 2, targetIdx, val);
    update(mid + 1, end, nodeNum * 2 + 1, targetIdx, val);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Init(0, n - 1, 1);

    long long int a, b, c;
    for(int i = 0; i < m + k; i++)
    {
        cin >> a >> b >> c;
        if(a == 1)
        {
            long long int tmp = c - arr[b - 1];
            arr[b - 1] = c;
            update(0, n - 1, 1, b - 1, tmp);
        }
        else
        {
            cout << subSum(0, n - 1, 1, b - 1, c - 1) << endl;
        }
    } 

    return 0;
}