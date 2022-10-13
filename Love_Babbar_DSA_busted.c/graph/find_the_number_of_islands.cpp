#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// time complexity: O(N*M)
// space complexity: O(N*M)
void dfs(int n, int m, int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<int> &di, vector<int> &dj)
{
    vis[i][j] = 1;
    for (int indx = 0; indx < 8; indx++)
    {
        int ni = i + di[indx];
        int nj = j + dj[indx];
        if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1 && vis[ni][nj] == 0)
        {
            // cout << indx << endl;
            dfs(n, m, ni, nj, vis, grid, di, dj);
        }
    }
}
int numberOfIslands(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> di = {0, -1, -1, -1, 0, 1, 1, 1};
    vector<int> dj = {-1, -1, 0, 1, 1, 1, 0, -1};
    int islandsCount = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                islandsCount++;
                dfs(n, m, i, j, vis, grid, di, dj);
            }
        }
    }
    return islandsCount;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = numberOfIslands(n, m, grid);
    cout << ans;
    return 0;
}