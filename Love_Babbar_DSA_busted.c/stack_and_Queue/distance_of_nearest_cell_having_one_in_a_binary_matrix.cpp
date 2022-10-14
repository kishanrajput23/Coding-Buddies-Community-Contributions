#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

// This question is similar to the rotten eggs problem 
// we wil use BFS approach to solve this problem \
// time complexity: O(N)
// space complexity: O(1)

bool isValid(int i, int j)
{
    if (i >= 0 && j >= 0 && i < R && j < C)
    {
        return true;
    }
    return false;
}

struct ele
{
    int x;
    int y;
};

bool isDelim(ele temp)
{
    if (temp.x == -1 && temp.y == -1)
    {
        return true;
    }
    return false;
}

void minimumDistance(int arr[][C])
{
    int n = 3;
    int m =3;
    queue<ele> q;
    ele temp;
    int ans[n][m];
    int minDistance = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 1)
            {
                temp.x = i;
                temp.y = j;
                q.push(temp);
            }
        }
    }

    temp.x = -1;
    temp.y = -1;
    q.push(temp);

    while (!q.empty())
    {

        while (!isDelim(q.front()))
        {
            temp = q.front();
            ans[temp.x][temp.y] = minDistance;

            if (isValid(temp.x + 1, temp.y) && arr[temp.x + 1][temp.y] == 0)
            {

                arr[temp.x + 1][temp.y] = 1;
                temp.x++;
                q.push(temp);
                temp.x--;
            }
            if (isValid(temp.x - 1, temp.y) && arr[temp.x - 1][temp.y] == 0)
            {
                arr[temp.x - 1][temp.y] = 1;
                temp.x--;
                q.push(temp);
                temp.x++;
            }
            if (isValid(temp.x, temp.y + 1) && arr[temp.x][temp.y + 1] == 0)
            {
                arr[temp.x][temp.y + 1] = 1;
                temp.y++;
                q.push(temp);
                temp.y--;
            }
            if (isValid(temp.x, temp.y - 1) && arr[temp.x][temp.y - 1] == 0)
            {

                arr[temp.x][temp.y - 1] = 1;
                temp.y--;
                q.push(temp);
                temp.y++;
            }
            q.pop();
        }

        q.pop();
        if (!q.empty())
        {
            temp.x = -1;
            temp.y = -1;
            q.push(temp);
        }
        minDistance++;
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int arr[][C] = {{0, 1, 0},
                    {0, 0, 0},
                    {1, 0, 0}};

   minimumDistance(arr);

    return 0;
}
