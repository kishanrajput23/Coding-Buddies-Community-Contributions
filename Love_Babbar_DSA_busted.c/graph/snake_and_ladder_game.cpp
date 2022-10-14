#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// see video of codebix for better understanding. 
// this is snake ladder problem difficult to convert it into the graph problem 
// it's reducible to normal bfs shortest path in an undirected graph with the help of bfs . 
// the two challenges in this question are: 
// 1. to convert the given question into an understandable way to graph 
// 2. find the coordinates of the vector with the help of the numbers given 1, 2, ....
// time complexity: O(V+E)
// space complexity: O(v+E)
ipair findCoordinates(int x, int n){
    ipair p;
    int r = ((n-1) - ((x-1)/n));
    int c;
    if(n%2 == 0){
        if(r%2 ==0){
            c = ((n-1) - ((x-1)%n));
        }
        else{
            c = ((x-1)%n);
        }
    }
    else{
        if(r%2 == 0){
            c = ((x-1)%n);
        }
        else{
            c= ((n-1) - ((x-1)%n));
        }
    }
    p.first = r;
    p.second = c;
    return p;
}
int snake_and_ladder(vector<vector<int>> &graph, int n){
    vector<vector<int>> vis(n, vector<int> (n, 0));
    queue<int> q;
    q.push(1);
    vis[n-1][0] = 1;
    int steps = 0;
    while(!q.empty()){
        int size = q.size();
        for(int j = 0;j<size;j++){

            int curr = q.front();
            q.pop();
            if(curr == n*n) {
                // cout<<"hi"<<endl;
                return steps;
            }

            for(int i = 1;i<= 6;i++){
                int temp = curr + i;
                if(temp > n*n) break;
                ipair graphCoor = findCoordinates(temp, n);
                int r = graphCoor.first;
                int c = graphCoor.second;
                if(!vis[r][c]){
                    vis[r][c] = 1;
                    if(graph[r][c]== -1){
                        q.push(temp);
                    }
                    else{
                        // vis[r][c] = 1;
                        q.push(graph[r][c]);
                    }
                }
            }
        }
        steps++;
        // cout<<steps<<endl;
    }
    // cout<<"hi";
    return -1;
}
int main()
{

    vector<vector<int>> graph = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };
    int n = graph.size();
    int minimumSteps = snake_and_ladder(graph, n);
    cout<<minimumSteps<<endl;
    return 0;
}