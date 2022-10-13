#include <bits/stdc++.h>
using namespace std;

//QUESTION:
// In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.
// We can describe the problem input as an array of numbers/characters representing persons in the party. We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. How can we solve the problem.

//Algorithm:

// Create a stack and push all the id’s in the stack.
// Run a loop while there are more than 1 element in the stack.
// Pop top two element from the stack (represent them as A and B)
// If A knows B, then A can’t be a celebrity and push B in stack. Else if A doesn’t know B, then B can’t be a celebrity push A in stack.
// Assign the remaining element in the stack as the celebrity.
// Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.

// Time complexity: O(N)
// space complexity: O(N)
//stack approach 
// int celebrity(vector<vector<int>> &v)
// {
//     stack<int> s;

//     for (int i = 0; i < v.size(); i++)
//     {
//         s.push(i);
//     }
//     while (s.size() != 1)
//     {
//         int temp1 = s.top();
//         s.pop();

//         int temp2 = s.top();
//         s.pop();

//         if (v[temp1][temp2])
//         {
//             s.push(temp2);
//         }
//         else
//         {
//             s.push(temp1);
//         }
//     }

//     int shayad_celeb = s.top();

//     for (int i = 0; i < v.size(); i++)
//     {
//         if (shayad_celeb == i)
//         {
//             continue;
//         }

//         if (v[shayad_celeb][i] == 1)
//         {
//             return -1;
//         }

//         if (v[i][shayad_celeb] == 0)
//         {
//             return -1;
//         }
//     }
//     return shayad_celeb;
// }


// The most efficient approach to solve this problem 
// approach: instead of using stack as an extra we could maintain two indexes which will tell which could be the shayad_celeb look at the code for further information . 
// time complexity: O(N)
// space complexity: O(1)
int celebrity(vector<vector<int>> &v)
{
    int a = 0;
    int b = (v.size() - 1);

    while (a < b)
    {
        if (v[a][b] == 1)
        {
            a++;
        }
        else
        {
            b--;
        }
    }

    int shayad_celeb = a;

    for (int i = 0; i < v.size(); i++)
    {
        if (shayad_celeb == i)
        {
            continue;
        }

        if (v[shayad_celeb][i] == 1)
        {
            return -1;
        }

        if (v[i][shayad_celeb] == 0)
        {
            return -1;
        }
    }
    return shayad_celeb;
}
int main()
{
    vector<vector<int>> v =
        {
            {0, 1, 0, 1, 0, 0},
            {1, 0, 0, 1, 1, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {1, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 1, 0},

        };

    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout<<endl;
    // }

    int success = celebrity(v);
    if (success == -1)
    {
        cout << "Celebrity does not exist " << endl;
    }
    else
    {
        cout << "Person " << success << " is the celebrity at the party " << endl;
    }
    return 0;
}