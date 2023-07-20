#include <iostream>

using namespace std;

int inOrder[100001];
int postOrder[100001];
int tmp[100001];

void preOrder(int inFirst, int inEnd, int postFirst, int postEnd)
{
    if(inFirst > inEnd || postFirst > postEnd)  return;
    int root = postOrder[postEnd];
    int idx = tmp[root];
    int leftCnt = idx - inFirst;

    cout << root << " ";

    preOrder(inFirst, idx - 1, postFirst, postFirst + leftCnt - 1);
    preOrder(idx + 1, inEnd, postFirst + leftCnt, postEnd - 1);
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> inOrder[i];

    for(int i = 0; i < n; i++)
        cin >> postOrder[i];

    for(int i = 0; i < n; i++)
        tmp[inOrder[i]] = i;

    preOrder(0, n - 1, 0, n - 1);

    return 0;
}