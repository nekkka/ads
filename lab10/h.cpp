#include <bits/stdc++.h>
using namespace std;

int rows, cols, cnt;

void dfs(string mtr[], int i, int j)
{
    if (i >= rows or j >= cols or i < 0 or j < 0 or mtr[i][j] == '0')
        return;
    mtr[i][j] = '0';
    dfs(mtr, i + 1, j);
    dfs(mtr, i - 1, j);
    dfs(mtr, i, j + 1);
    dfs(mtr, i, j - 1);
}

int main()
{
    cin >> rows >> cols;
    string matrix[rows];
    for (int i = 0; i < rows; i++)
    {
        cin>>matrix[i];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
            {
                dfs(matrix, i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}