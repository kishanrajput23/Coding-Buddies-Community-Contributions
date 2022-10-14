#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 5

// time complexity: O(N) here N is the no. of elements in the matrix
// space complexity: O(1)
// see gfg article to understand the algorithm and the code and the tech dose you  tube channel for revision

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

bool checkall(int arr[][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 1)
            {
                return true;
            }
        }
    }
    return false;
}

bool isDelim(ele temp)
{
    if (temp.x == -1 && temp.y == -1)
    {
        return true;
    }
    return false;
}

int rotOranges(int arr[][C])
{
    queue<ele> q;
    ele temp;
    int ans = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                q.push(temp);
            }
        }
    }

    temp.x = -1;
    temp.y =  -1;
    q.push(temp);

    while (!q.empty())
    {
        bool flag = false;

        while (!isDelim(q.front()))
        {
            temp = q.front();
            if (isValid(temp.x + 1, temp.y) && arr[temp.x + 1][temp.y] == 1)
            {
                if (!flag)
                {
                    ans++;
                }
                flag = true;
                arr[temp.x+1][temp.y]= 2;
                temp.x++;
                q.push(temp);
                temp.x--;
            }
            if (isValid(temp.x - 1, temp.y) && arr[temp.x - 1][temp.y] == 1)
            {
                if (!flag)
                {
                    ans++;
                }
                flag = true;
                arr[temp.x-1][temp.y]= 2;
                temp.x--;
                q.push(temp);
                temp.x++;
            }
            if (isValid(temp.x, temp.y + 1) && arr[temp.x][temp.y + 1] == 1)
            {
                if (!flag)
                {
                    ans++;
                }
                flag = true;
                arr[temp.x][temp.y+1]= 2;
                temp.y++;
                q.push(temp);
                temp.y--;
            }
            if (isValid(temp.x, temp.y - 1) && arr[temp.x][temp.y - 1] == 1)
            {
                if (!flag)
                {
                    ans++;
                }
                flag = true;
                arr[temp.x][temp.y-1]= 2;
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
    }
    if (checkall(arr))
    {
        return -1;
    }
    else
    {
        return ans;
    }
}


int main()
{
    int arr[][C] = {{2, 1, 0, 2, 1},
                    {1, 0, 1, 2, 1},
                    {1, 0, 0, 2, 1}};

    int ans = rotOranges(arr);
    if (ans == -1)
    {
        cout << "Cannot rot all oranges " << endl;
    }
    else
    {
        cout << "The oranges are rotten in the time frame " << ans << endl;
    }
    return 0;
}

