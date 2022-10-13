#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// Prints the path in dfs manner. 
void printPath(map<ipair, ipair> parent, ipair u){
    if(u.first == 0 && u.second == 0){
        cout<<0<<" "<<0<<endl;
        return;
    }
    printPath(parent, parent[u]);
    cout<<u.first<<" "<<u.second<<endl;
}

// This is water jug problem 
// It's really a hard level problem 
// There is no resource on you tube to see this question 
// checkout geeks for geeks article to see if forgot. 
// we need to do bfs in it with provided conditions making them as adjacent. 
// we can do this question either with bfs as well as dfs I had done this with bfs here. 
// It's normal bfs 
// as we need to deal with the pairs so we had made pairs 
// visited map, parent map : for path, queue pair: for bfs 
// code written on gfg is very helpful 
// ** we had print the path with dfs just because there will be many reduntant solutions so we had print them while backtracking. dry run to understand better.**
// time compelxity: O(V+E)
// space complexity: O(V)
void bfs(int a, int b, int target){
    bool isSolvable = false;
    map<ipair, int> vis;
    map<ipair, ipair> parent;
    queue<ipair> q;
    q.push({0, 0});
    vis[{0, 0}] = 1;
    while(!q.empty()){

        auto u = q.front();
        q.pop();
        int WaterInJug1 = u.first;
        int WaterInJug2 = u.second;

        // not possible conditions. 
        if(WaterInJug1> a || WaterInJug2>b || WaterInJug1<0 || WaterInJug2<0){
            continue;
        }

        // if we found the target 
        if(WaterInJug1 == target || WaterInJug2 == target){
            isSolvable = true;
            printPath(parent, u);
            if(WaterInJug1 == target){
                if(WaterInJug2 !=0){
                    cout<<WaterInJug1<<" "<<0<<endl;
                }
            }
            else{
                if(WaterInJug1 != 0){
                    cout<<0<<" "<<WaterInJug2<<endl;
                }
            }
            return;
        }

        // ** checking all the possible conditions.**

        // filling jug1
        if(!vis[{a, WaterInJug2}]){
            vis[{a, WaterInJug2}] = 1;
            q.push({a, WaterInJug2});
            parent[{a, WaterInJug2}] = u;
        }

        // filling jug2 
        if(!vis[{WaterInJug1, b}]){
            vis[{WaterInJug1, b}] = 1;
            q.push({WaterInJug1, b});
            parent[{WaterInJug1, b}] = u;
        }

        // pouring water from jug 1 to jug 2
        int d = b - WaterInJug2;
        if(d> WaterInJug1){
            int c = WaterInJug1 + WaterInJug2;
            if(!vis[{0, c}]){
                vis[{0, c}] = 1;
                q.push({0, c});
                parent[{0, c}] = u;
            }
        }
        else{
            int c = WaterInJug1 - d;
            if(!vis[{c, b}]){
                vis[{c, b}] = 1;
                q.push({c, b});
                parent[{c, b}] = u;
            }
        }

        // jug 2 to jug1 
        d = a- WaterInJug1;
        if(d > WaterInJug2){
            int c = WaterInJug2 + WaterInJug1;
            if(!vis[{c, 0}]){
                vis[{c, 0}] = 1;
                q.push({c, 0});
                parent[{c, 0}] = u;
            }
        }
        else{
            int c = WaterInJug2 - d;
            if(!vis[{a, c}]){
                vis[{a, c}] = 1;
                q.push({a, c});
                parent[{a, c}] = u;
            }
        }

        // emptying jug 1 
        if(!vis[{0, WaterInJug2}]){
            vis[{0, WaterInJug2}] = 1;
            q.push({0, WaterInJug2});
            parent[{0, WaterInJug2}] = u;
        }

        // emptying jug 2
        if(!vis[{WaterInJug1, 0}]){
            vis[{WaterInJug1, 0}] = 1;
            q.push({WaterInJug1, 0});
            parent[{WaterInJug1, 0}] = u;
        }
    }
    if(!isSolvable){
        cout<<"Not possible "<<endl;
    }
}
int main()
{
    int jug1 = 5;
    int jug2 = 7;
    int target = 3;
    cout<<"Path from intial stage to the solution state is "<<endl;
    bfs(jug1, jug2, target);
    return 0;
}