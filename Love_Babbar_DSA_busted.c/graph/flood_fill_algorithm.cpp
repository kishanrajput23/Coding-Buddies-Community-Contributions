#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;

void floodFillUtil(int i, int j, vector<vector<int>> &a, int dx[], int dy[], int colr, vector<vector<int>> &visited, int n, int srcolr)
{
    a[i][j] = colr;
    visited[i][j] = 1;
    for (int indx = 0; indx < 4; indx++)
    {
        int ni = i + dx[indx];
        int nj = j + dy[indx];
        if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj] && a[ni][nj] == srcolr)
        {
            floodFillUtil(ni, nj, a, dx, dy, colr, visited, n, srcolr);
        }
    }
}
void floodFill(vector<vector<int>> &a, int n, int colr, ipair src)
{
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int dx[] = {0, -1, 0, +1};
    int dy[] = {-1, 0, +1, 0};
    int srcolr = a[src.first][src.second];
    floodFillUtil(src.first, src.second, a, dx, dy, colr, vis, n, srcolr);
}
int main()
{
    vector<vector<int>> a =
        {
            {1, 1, 1, 1, 1, 1, 0, 2},
            {1, 1, 1, 1, 1, 1, 0, 0},
            {1, 0, 0, 1, 1, 0, 1, 1},
            {1, 2, 2, 2, 2, 0, 1, 0},
            {1, 1, 1, 2, 2, 0, 1, 0},
            {1, 1, 1, 2, 2, 2, 2, 0},
            {1, 1, 1, 1, 1, 2, 1, 1},
            {1, 1, 1, 1, 1, 2, 2, 1},
        };
    ipair src = {4, 4};
    int colr = 3;
    int n = 8;
    floodFill(a, n, colr, src);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}