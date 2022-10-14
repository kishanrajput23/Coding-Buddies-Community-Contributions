// #include <bits/stdc++.h>
// using namespace std;
// const int n = 4;
// // find all the paths to reach the a[n-1][n-1] position
// // see the code library video for better understanding.
// // time complexity: O((V^2)^4)
// // space complexity: O(V^2)
//***********the better approach is written downward by striver*********
// void searchMazeUtil(int i, int j, int a[n][n], int visited[n][n], string s, vector<string> &res)
// {
//     if (a[0][0] == 0 || a[n - 1][n - 1] == 0)
//     {
//         cout << "Not possible " << endl;
//         return;
//     }
//     if (i < 0 or j > n - 1 or j < 0 or i > n - 1)
//         return;

//     if (visited[i][j] || a[i][j] == 0)
//         return;

//     if (i == n - 1 && j == n - 1)
//     {
//         res.push_back(s);
//         return;
//     }

//     visited[i][j] = 1;

//     searchMazeUtil(i + 1, j, a, visited, s + 'D', res);
//     searchMazeUtil(i - 1, j, a, visited, s + 'U', res);
//     searchMazeUtil(i, j + 1, a, visited, s + 'R', res);
//     searchMazeUtil(i, j - 1, a, visited, s + 'L', res);
//     visited[i][j] = 0;
// }
// vector<string> searchMaze(int a[n][n])
// {
//     int visited[n][n];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             visited[i][j] = 0;
//         }
//     }
//     vector<string> res;
//     string s = "";

//     searchMazeUtil(0, 0, a, visited, s, res);
//     return res;
// }

// int main()
// {
//     int a[n][n];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> a[i][j];
//         }
//     }

//     vector<string> res = searchMaze(a);
//     sort(res.begin(), res.end());
//     cout<<"The number of paths are : "<<res.size()<<endl;
//     for (int i = 0; i < res.size(); i++)
//     {
//         cout << res[i] << " ";
//     }

//     return 0;
// }

// see striver code wrting part 
//this is preffered method as in the first method before backtracking we were giving function calls , so there is a possibility that you might get stack overflow in it. 
//in this mehtod we are only calling the relevant functions 
// and also learnt a new concept of creating the arrays. 
// time complexity: O(N^2)
// space complexity: O(N^2)
#include <bits/stdc++.h>
using namespace std;
const int n = 4;

void ratMazeUtil(int x, int y, vector<vector<int>> &maze, vector<int> &dx, vector<int> &dy, string s, vector<vector<int>> &visited, vector<string> &res)
{

    if (x == n - 1 && y == n - 1)
    {
        res.push_back(s);
        return;
    }

    string st = "DLRU";
    for (int i = 0; i < 4; i++)
    {
        int nxc = x + dx[i];
        int nyc = y + dy[i];
        if (nxc >= 0 && nyc >= 0 && nxc < n && nyc < n && !visited[nxc][nyc] && maze[nxc][nyc])
        {
            visited[x][y] = 1;
            ratMazeUtil(nxc, nyc, maze, dx, dy, s + st[i], visited, res);
            visited[x][y] = 0;
        }
    }
}

vector<string> ratMaze(vector<vector<int>> &maze)
{
    vector<string> res;
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    string s = "";
    vector<vector<int>>  visited(n, vector<int> (n, 0));

    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
    {
        return res;
    }

    ratMazeUtil(0, 0, maze, dx, dy, s , visited, res);
    return res;
}
int main()
{
    vector<vector<int>> maze = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};
    
    vector<string> res = ratMaze(maze);
    cout<<"The number of possible paths are: "<<res.size()<<endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}