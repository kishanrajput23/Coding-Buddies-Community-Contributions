#include <bits/stdc++.h>
using namespace std;

// #include <cmath>
// One of the hardest question I found on the internet . 
// this question was not available on any of the platform 
// I found it only on coding ninjas website. 
// time complexity: O(V^4)
// space complexity: O(V^2)
int findDeterminant(vector<vector<int>> Matrix)
{
    // Variable to store the determinant value
    static int det = 0;
    if (Matrix.size() == 1)
    {
        return Matrix[0][0];
    }

    else if (Matrix.size() == 2)
    {
        det = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
        return det;
    }
    else if (Matrix.size() == 3)
    {
        return ((Matrix[0][0] * (Matrix[1][1] * Matrix[2][2] - Matrix[2][1] * Matrix[1][2])) - (Matrix[0][1] * (Matrix[1][0] * Matrix[2][2] - Matrix[2][0] * Matrix[1][2])) + (Matrix[0][2] * (Matrix[1][0] * Matrix[2][1] - Matrix[2][0] * Matrix[1][1])));
    }
    else
    {

        for (int p = 0; p < Matrix[0].size(); p++)
        {
            vector<vector<int>> tempMatrix;
            for (int i = 1; i < Matrix.size(); i++)
            {
                vector<int> row;
                for (int j = 0; j < Matrix[i].size(); j++)
                {
                    if (j != p)
                    {
                        row.push_back(Matrix[i][j]);
                    }
                }

                if (row.size() > 0)
                {
                    tempMatrix.push_back(row);
                }
            }

            det = det + Matrix[0][p] * pow(-1, p) * findDeterminant(tempMatrix);
        }

        return det;
    }
}

int spanningTrees(vector<vector<int>> &adjMatrix, int n, int m)
{

    // Degree of each node will be stored in this
    int degree[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                // Calculating degree of each node
                degree[i]++;
            }
        }
    }

    // Updating the values of primary diagonal with degree of the node
    for (int i = 0; i < n; i++)
    {
        adjMatrix[i][i] = degree[i];
    }

    // Replacing all 1 in the matrix which are not present on primary diagonal with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i != j) and adjMatrix[i][j] == 1)
            {
                adjMatrix[i][j] = -1;
            }
        }
    }

    // Submatrix of size (n-1)*(n-1) in which 1st row and 1st column values will not be there
    vector<vector<int>> submatrix(n - 1, vector<int>(n - 1));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            submatrix[i - 1][j - 1] = adjMatrix[i][j];
        }
    }

    // This will be the answer as (-1)^(1+1) will be equal to 1 only
    return findDeterminant(submatrix);
}

int main()
{
    vector<vector<int>> stg = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}

    };
    int n = stg.size();
    int numberOfSpanningTrees = spanningTrees(stg, n, n);
    cout << numberOfSpanningTrees;

    return 0;
}

// this function
// this is written by me after seeing from coding ninjas
// int findDET(vector<vector<int>> &m){
//     static int det = 0;
//     if(m.size() == 1){
//         return m[0][0];
//     }
//     else if(m.size() == 2){
//         return (m[0][0]*m[1][1] - m[1][0]*m[0][1]);
//     }
//     else if(m.size() == 3){
//         return ((m[0][0]*(m[1][1]*m[2][2] - m[2][1]*m[1][2])) - (m[0][1]*(m[1][0]*m[2][2] - m[2][0]*m[1][2])) + (m[0][2]*(m[1][0]*m[2][1] - m[2][0]*m[1][1])));
//     }
//     else {
//         for(int  p = 0;p<m.size();p++){
//             vector<vector<int>> tempm;
//             for(int i = 1;i<m.size();i++){
//                 vector<int> insidetempm;
//                 for(int j = 0;j<m.size();j++){
//                     if(p != j){
//                         insidetempm.push_back(m[i][j]);
//                     }
//                 }
//                 if(insidetempm.size() >0){
//                     tempm.push_back(insidetempm);
//                 }
//             }

//             det = det + pow(-1, p)*m[0][p]*findDET(tempm);
//         }
//     }
//     return det;
// }
// int NofST(vector<vector<int>> &stg){
//     int n = stg.size();

//     // copying all elements to new matrix .
//     vector<vector<int>> mat(n, vector<int> (n));
//     for(int i = 0;i<stg.size();i++){
//         for(int j = 0;j<stg[i].size();j++){
//             mat[i][j] = stg[i][j];
//         }
//     }

//     // calculating indegree
//     vector<int> indegree;
//     for(int i = 0;i<mat.size();i++){
//         int counter= 0;
//         for(int j =0;j<mat[i].size();j++){
//             if(mat[i][j] == 1){
//                 counter++;
//             }
//         }
//         indegree.push_back(counter);
//     }

//     // indegree contributes to all the diagonal elements
//     for(int i = 0;i<n;i++){
//         mat[i][i] = indegree[i];
//     }

//     // set other with edges to 1
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<n;j++){
//             if(i != j and mat[i][j] == 1){
//                 mat[i][j] = -1;
//             }
//         }
//     }

//     vector<vector<int>> m(n-1, vector<int> (n-1));
//     for(int i = 1;i<n;i++){
//         for(int j = 1;j<n;j++){
//             m[i-1][j-1] = mat[i][j];
//         }
//     }
//     // int det = 0;
//     int ans = findDET(m);
//     return ans;
// }
