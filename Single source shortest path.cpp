#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>


using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
int n,m; // n= no of node,m = no of nodes
vector<int> g[(int)1e5];
bool visited[(int)1e5];//for keeping track of visited and unvisited componet
//initialize graph
int dist[(int)1e5];
void gInsert(int a,int b){
  g[a].push_back(b);
  g[b].push_back(a);
}
//dfs using recursion
void dfs(int v,int distance){
  // cout<<v<<"->";
  dist[v]=distance;
  visited[v]=true;
  for(int i=0;i<g[v].size();i++){
      if(!visited[g[v][i]]){
        dfs(g[v][i],dist[v]+1);

      }
  }
}
int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    cin>>n>>m;
    while(m--){
      int a,b;
      cin>>a>>b;
      gInsert(a,b);

    }
    // int  connected_comoponent =0;
    //   for(int i=1;i<=n;i++){
    //       if(!visited[i]){
    //         connected_comoponent++;
    //         dfs(i,0);
            
    //       }
    //   }

    dfs(1,0);
      for(int i=1;i<=n;i++){
        cout<<dist[i]<<endl;
      }
    
    

 return 0;
}