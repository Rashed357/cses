**subtree size
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int mx = 2e5+7;
vector<int>adj[mx];
int sz[mx];
int vis[mx];
 
void dfs(int node){
   
   for(auto it:adj[node]){
    dfs(it);
    sz[node] += (1+sz[it]);
   }
 
}
 
void solve() {
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
 
    dfs(1);
 
    for(int i=1; i<=n; i++)
        cout<<sz[i]<<' ';
    cout<<endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
   // int t;cin>>t;while(t--)
    solve();
 
    return 0;
}


**You are given a tree consisting of n nodes.
A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?
#include <bits/stdc++.h>
using namespace std;
 
const int mx = 2e5+7;
vector<int>adj[mx];
long long dp[mx][2];
 
void dfs(int node, int parent){
 
    dp[node][0] = dp[node][1] = 0;
 
    for(auto it:adj[node]){
        if(it==parent)
            continue;
        dfs(it,node);
    }
 
    for(auto it:adj[node]){
        if(it==parent)
            continue;
        dp[node][0] += max(dp[it][0],dp[it][1]);
    }
 
    for(auto it:adj[node]){
        if(it==parent)
            continue;
        dp[node][1] = max(dp[node][1], 1+dp[it][0]+dp[node][0]-max(dp[it][0],dp[it][1]));
    }
}
 
void solve(){
 
    int n;
    cin>>n;
 
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1,-1);
 
    cout<<max(dp[1][0],dp[1][1])<<endl;
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}


**diameter
#include <bits/stdc++.h>
using namespace std;
 
const int mx = 2e5+7;
vector<int>adj[mx];
int dist[mx][2];
int f;
int mxx,x;
 
void dfs(int node, int parent){
 
   for(auto it:adj[node]){
    if(it==parent)
        continue;
    dist[it][f] = 1+dist[node][f];
    if(dist[it][f]>mxx){
        x = it;
        mxx = dist[it][f];
    }
    dfs(it,node);
   }
}
 
void solve(){
 
    int n;
    cin>>n;
 
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
   dfs(1,-1);
   f = 1;
   dfs(x,-1);
 
   cout<<mxx<<endl;
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}


**You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.
#include <bits/stdc++.h>
using namespace std;
 
const int mx = 2e5+7;
vector<int>adj[mx];
int dist[mx][3];
int nod[3];
int mxx = 0, st, en;
 
void dfs(int node, int p, int t){
 
    for(auto it:adj[node]){
        if(it==p)
            continue;
 
        dist[it][t] = dist[node][t] + 1;
 
        if(dist[it][t]>mxx){
            nod[t] = it;
            mxx = dist[it][t];
        }
 
        dfs(it,node,t);
    }
}
 
void solve(){
 
    int n;
    cin>>n;
 
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
  dfs(1,-1,0);
  mxx = 0;
  dfs(nod[0],-1,1);
  mxx = 0;
  dfs(nod[1],-1,2);
 
  //cout<<nod[0]<<' '<<nod[1]<<endl;
 
  for(int i=1; i<=n; i++)
    cout<<max(dist[i][1],dist[i][2])<<' ';
cout<<endl;
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}

**You are given a tree consisting of n nodes.
Your task is to determine for each node the sum of the distances from the node to all other nodes.

#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 5;
 
vector<int> adj[MAXN];
int subtree[MAXN];     // Size of the subtree rooted at a node
long long dist_sum[MAXN]; // Sum of distances from a node to all other nodes
int n;
 
// First DFS: Compute subtree sizes and distance sum for the root
void dfs1(int u, int parent) {
    subtree[u] = 1; // The node itself counts as size 1
    for (int v : adj[u]) {
        if (v == parent) continue; // Skip the parent to avoid cycles
        dfs1(v, u);
        subtree[u] += subtree[v]; // Add the size of the child's subtree
        dist_sum[1] += dist_sum[v] + subtree[v]; // Add distances from the root
    }
}
 
// Second DFS: Re-root the tree and compute dist_sum for all nodes
void dfs2(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue; // Skip the parent
        // Update dist_sum for child using the parent's dist_sum
        dist_sum[v] = dist_sum[u] + (n - 2 * subtree[v]);
        dfs2(v, u);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
 
    // Read tree edges
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    // Step 1: Perform the first DFS
    dfs1(1, -1);
 
    // Step 2: Perform the second DFS
    dfs2(1, -1);
 
    // Output the result
    for (int i = 1; i <= n; i++) {
        cout << dist_sum[i] << " ";
    }
    cout << endl;
 
    return 0;
}
