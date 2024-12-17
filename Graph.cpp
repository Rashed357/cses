**You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
 
const int mx = 1007;
bool vis[mx][mx];
vector<string>v(mx);
int n,m;
 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
 
void dfs(int x, int y){
   
    vis[x][y] = 1;
 
    for(int i=0; i<4; i++){
        
        int nx = x+dx[i];
        int ny = y+dy[i];
 
        if(nx>=0 and nx<n and ny>=0 and ny<m and v[nx][ny]=='.' and !vis[nx][ny])
            dfs(nx,ny);
    }
}
 
 
void solve() {
 
    cin>>n>>m;
 
    for(int i=0; i<n; i++)
        cin>>v[i];
 
    int cnt = 0;
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]=='.' and !vis[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }
 
    cout<<cnt<<endl;
}
 
int main() {
    fastio;
 
    solve();
 
    return 0;
}

**You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
 
const int mx = 1007;
bool vis[mx][mx];
int dist[mx][mx];
pair<int,int> parent[mx][mx];
vector<string>v(mx);
int n,m;
pair<int,int> loc_a, loc_b;
 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char path[] = {'D','U','R','L'};
 
bool valid(int x, int y){
 
    return (x>=0 && x<n && y>=0 && y<m && dist[x][y]==-1 && v[x][y]!='#');
}
 
 
 
void solve() {
 
    cin>>n>>m;
 
    for(int i=0; i<n; i++)
        cin>>v[i];
 
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]=='A'){
                loc_a.first = i;
                loc_a.second = j;
            }
 
            if(v[i][j] == 'B'){
                loc_b.first = i;
                loc_b.second = j;
            }
        }
    }
 
    memset(dist,-1,sizeof(dist));
    dist[loc_a.first][loc_a.second] = 0;
    parent[loc_a.first][loc_a.second] = loc_a;
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
 
    pq.push({0,loc_a});
 
    while(!pq.empty()){
 
        auto it = pq.top();
        pq.pop();
 
        int cur_dist = it.first;
        int x = it.second.first;
        int y = it.second.second;
 
        if(x==loc_b.first && y==loc_b.second)
            break;
 
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
 
            if(valid(nx,ny)){
                dist[nx][ny] = cur_dist+1;
                parent[nx][ny] = {x,y};
                pq.push({cur_dist+1,{nx,ny}});
            }
        }
    }
 
    if(dist[loc_b.first][loc_b.second]==-1){
        cout<<"NO"<<endl;
        return;
    }
 
    cout<<"YES"<<endl;
    cout<<dist[loc_b.first][loc_b.second]<<endl;
 
    string way = "";
 
    pair<int,int> cur = loc_b;
 
    while(cur!=loc_a){
 
        pair<int,int>prev = parent[cur.first][cur.second];
 
        for(int i=0; i<4; i++){
            if(prev.first+dx[i]==cur.first && prev.second+dy[i]==cur.second){
                way += path[i];
                break;
            }
        }
 
        cur = prev;
    }
 
    reverse(way.begin(),way.end());
 
    cout<<way<<endl;
 
    
}
 
int main() {
    fastio;
 
    solve();
 
    return 0;
}

**Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int mod = 1e9 + 7;
 
int n,m;
const int mx = 2e5+7;
vector<int>adj[mx];
bool vis[mx];
 
 
 
void dfs(int node){
    vis[node] = 1;
 
    for(auto it:adj[node]){
        if(!vis[it])
            dfs(it);
    }
}
 
void solve(){
 
    cin>>n>>m;
 
    for(int i=1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1);
 
    vector<int>ans;
 
    for(int i=2; i<=n; i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
 
    cout<<ans.size()<<endl;
 
    for(auto it:ans)
        cout<<1<<' '<<it<<endl;
}
 
 
int main() {
 
    solve();
 
    return 0;
}


**Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
Syrjälä's network has n computers and m
connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
  #include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int mod = 1e9 + 7;
 
int n,m;
const int mx = 2e5+7;
vector<int>adj[mx];
bool vis[mx];
int parent[mx];
int dist[mx];
 
 
 
 
void solve(){
 
    cin>>n>>m;
 
    for(int i=1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    memset(parent,-1,sizeof(parent));
    fill(dist, dist + mx, 1e8);
 
 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 
    pq.push({0,1});
    dist[1] = 0;
 
    while(!pq.empty()){
 
        auto p = pq.top();
        pq.pop();
 
        int wt = p.first;
        int node = p.second;
 
        if(wt>dist[node])
            continue;
 
        if(node==n)
            break;
 
        for(auto it:adj[node]){
            if(dist[it]>wt+1){
                dist[it] = wt+1;
                pq.push({dist[it],it});
                parent[it] = node;
            }
        }
    }
 
    if(dist[n]==1e8){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
 
    vector<int>path;
    path.push_back(n);
 
    while(parent[n] != -1){
        n = parent[n];
        path.push_back(n);
    }
 
    reverse(path.begin(),path.end());
 
    cout<<path.size()<<endl;
 
    for(auto it:path)
        cout<<it<<' ';
    cout<<endl;
 
   // cout<<parent[1];
}
 
 
int main() {
 
    solve();
 
    return 0;
}
Share code to others




**There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int mod = 1e9 + 7;
 
int n,m;
const int mx = 2e5+7;
vector<int>adj[mx];
bool vis[mx];
int parent[mx];
int col[mx];
bool flag = true;
 
void dfs(int node, int c){
    col[node] = c;
    for(auto it:adj[node]){
        if(col[it]==0)
            dfs(it,3-c);
 
        else if(col[it]==col[node]){
            flag = false;
            return;
        }
    }
}
 
void solve(){
 
    cin>>n>>m;
 
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i=1; i<=n; i++){
        if(col[i]==0){
            dfs(i,1);
        }
    }
 
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
 
    for(int i=1; i<=n; i++)
        cout<<col[i]<<' ';
    cout<<endl;
}
 
 
int main() {
 
    solve();
 
    return 0;
}



**Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int mod = 1e9 + 7;
 
int n,m;
const int mx = 2e5+7;
vector<int>adj[mx];
bool vis[mx];
int parent[mx];
int col[mx];
bool flag = true;
 
int st=-1,en = -1;
 
void dfs(int node, int par){
    vis[node] = 1;
    parent[node] = par;
 
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,node);
            if(st!=-1)
                return;
        }
 
        else if(it != par){
            st = it;
            en = node;
            return;
        }
    }
}
 
void solve(){
 
    cin>>n>>m;
 
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
 
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i,-1);
 
            if(st!=-1)
                break;
        }
    }
 
    if(st==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
 
 
    vector<int>path;
    path.push_back(st);
 
    while(en != st){
        path.push_back(en);
        en = parent[en];
    }
 
    path.push_back(st);
 
    reverse(path.begin(),path.end());
 
    cout<<path.size()<<endl;
 
    for(auto it:path)
        cout<<it<<' ';
 
    cout<<endl;
    
}
 
 
int main() {
 
    solve();
 
    return 0;
}


You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
 
const int mx = 1007;
char grid[mx][mx];
int dist[mx][mx]; // Distance from each cell
pair<int, int> parent[mx][mx]; // Parent tracking for path reconstruction
 
int n, m; // Dimensions of the grid
 
int dx[] = {-1, 1, 0, 0}; // Directions for movement
int dy[] = {0, 0, -1, 1};
char drc[] = {'U', 'D', 'L', 'R'}; // Directions corresponding to dx and dy
 
queue<pair<int, int>> q; // Queue for BFS
pair<int, int> src, dest; // Start (A) and destination (exit) points
bool possible = false; // Flag to indicate if a path is possible
bool me = false; // Flag to indicate BFS state
 
void bfs() {
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
 
        int x = p.first; // Current x-coordinate
        int y = p.second; // Current y-coordinate
 
        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // New x-coordinate
            int ny = y + dy[i]; // New y-coordinate
 
            // Check boundaries and ensure it's not a wall
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && grid[nx][ny] != '#') {
                int nw_dist = dist[x][y] + 1; // New distance from source
 
                // If found a shorter path
                if (nw_dist < dist[nx][ny]) {
                    dist[nx][ny] = nw_dist; // Update distance
                    q.push({nx, ny}); // Add to queue for BFS
                    parent[nx][ny] = {x, y}; // Set parent for path reconstruction
                }
            }
        }
 
        // Check if we reached the boundary
        if (me) {
            if (x==1 or x==n or y==1 or y==m) {
                possible = true; // Path to exit found
                dest = {x, y}; // Set destination
                return; // Exit BFS
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
 
    // Initialize grid and distances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j]; // Read the grid character
 
            dist[i][j] = INT_MAX; // Initialize distance to "infinity"
 
            // Start BFS for monsters
            if (grid[i][j] == 'M') {
                q.push({i, j}); // Push monster's position
                dist[i][j] = 0; // Distance from monster is 0
            }
 
            // Capture starting point of 'A'
            if (grid[i][j] == 'A') {
                src = {i, j}; // Set source position
            }
        }
    }
 
    bfs(); // BFS for monsters
 
    // // Mark cells adjacent to monsters as unsafe for A
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         if (grid[i][j] == 'M') {
    //             for (int d = 0; d < 4; d++) {
    //                 int nx = i + dx[d];
    //                 int ny = j + dy[d];
    //                 // Mark adjacent cells as walls if they are not the boundaries
    //                 if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && grid[nx][ny] == '.') {
    //                     grid[nx][ny] = '#'; // Block this cell for 'A'
    //                 }
    //             }
    //         }
    //     }
    // }
 
    me = true; // Now perform BFS for 'A'
    q.push(src); // Push 'A' starting point to queue
 
    dist[src.first][src.second] = 0; // Distance to itself is 0
    parent[src.first][src.second] = {-1, -1}; // Initialize parent for 'A'
 
    bfs(); // BFS for 'A'
 
    // If no path is found
    if (!possible) {
        cout << "NO" << endl;
        return;
    }
 
    cout<<"YES"<<endl;
 
    string way; // To hold the directions of the path
    pair<int, int> cur = dest; // Start from the destination
 
   // pair<int,int> pp = parent[dest.first][dest.second];
 
   // cout<<pp.first<<' '<<pp.second<<endl;
 
    // Path reconstruction
    while (cur != src) {
        pair<int, int> prev = parent[cur.first][cur.second]; // Get the parent
 
        // Find the direction from the parent to current cell
        for (int i = 0; i < 4; i++) {
            int nx = prev.first + dx[i];
            int ny = prev.second + dy[i];
 
            // If the current cell matches the new coordinates
            if (cur.first == nx && cur.second == ny) {
                way += drc[i]; // Add the direction to the path
            }
        }
 
        cur = prev; // Move to the previous node
    }
 
    reverse(all(way)); // Reverse the path to get it from 'A' to destination
 
    cout << dist[dest.first][dest.second] << endl; // Print distance to destination
    cout << way << endl; // Print the path
}
 
int main() {
    fastio; // Optimize input/output
    solve(); // Execute the solution
}


**There are n cities and m flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define endl '\n'
#define ll long long
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
 
 const int mx = 1e5+5;
// const ll mod = 1e9+7;
 
 vector<pair<int,int>>adj[mx];
 
 class Dijkstra
 {
 public:
   
   vector<ll> solve(int n, int st){
 
      vector<ll> dist(n+1,1e16);
      dist[st] = 0;
 
      priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
 
      pq.push({0,st});
 
      while(!pq.empty()){
 
          auto p = pq.top();
          pq.pop();
 
          int u = p.second;
          ll u_dist = p.first;
 
          if(dist[u]<u_dist)
            continue;
 
          for(auto it: adj[u]){
 
              int v = it.first;
              ll w = it.second;
 
              ll cur_dist = u_dist+w;
 
              if(dist[v]>cur_dist){
 
                  dist[v] = cur_dist;
                  pq.push({dist[v],v});
              }
          }
      }
 
      return dist;
   }
   
 };
 
 
 
void solve(int t, int cs) {
 
    int n,m;
    cin>>n>>m;
 
    rep(i,0,m){
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      //adj[v].push_back({u,w});
    }
 
    Dijkstra obj;
 
    vector<ll> ans = obj.solve(n,1);
 
    for(int i=1; i<=n; i++)
      cout<<ans[i]<<' ';
 
    cout<<endl;
}
 
int main() {
    fastio;
   // int t; cin>>t;
    int t=1;
    for(int tt = 1; tt <= t; tt++)
        solve(t, tt);
    return 0;
}


**There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define endl '\n'
#define ll long long
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
 
 
// const int mx = 2e5+7;
// vector<int> adj[mx];
// bool vis[mx];
// int n,m,cnt=0,st,x=0,y=0;
 
ll inf = 1e16;
 
 
void solve(){
 
    int n,m,q;
    cin>>n>>m>>q;
 
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,inf));
 
    for(int i=1; i<=n; i++)
        dist[i][i] = 0;
 
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }
 
 
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
 
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==inf)
            cout<<-1<<endl;
        else
            cout<<dist[a][b]<<endl;
    }
}
 
 
int main() {
 
   fastio;
  // int t; cin>>t; while(t--)
   solve();
}


**Time limit: 1.00 s
Memory limit: 512 MB



You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
Your task is to walk from room 1 to room n. What is the maximum score you can get?
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
 
const int mod = 1e9+7;
const int mx = 3e3;
const ll inf = -1e16;
 
void solve() {
    
    int n,m;
    cin>>n>>m;
 
    vector<pair<pair<int,int>,ll>> edge;
 
    for(int i=0; i<m; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edge.push_back({{a,b},c});
    }
 
    vector<ll>dist(n+1,inf);
    dist[1] = 0;
    vector<bool>connected(n+1,false);
    connected[n] = true;
 
    for(int i=1; i<n; i++){
        for(auto it:edge){
            int a = it.first.first;
            int b = it.first.second;
            ll c = it.second;
 
            if(dist[a] != inf and dist[a]+c>dist[b])
                dist[b] = dist[a]+c;
 
            if(connected[b])
                connected[a] = true;
        }
    }
 
 
 
 
    bool cycle = false;
 
    for(auto it:edge){
        int a = it.first.first;
        int b = it.first.second;
        ll c = it.second;
 
        if(dist[a]!=inf and dist[a]+c>dist[b] and connected[a]){
            cycle = true;
            break;
        }
    }
 
 
    if(cycle)
        cout<<-1<<endl;
    else
        cout<<dist[n]<<endl;
 
 
}
 
int main() {
    fastio;
    solve();
    return 0;
}


Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.
When you use the discount coupon for a flight whose price is x, its price becomes \lfloor x/2 \rfloor (it is rounded down to an integer).
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define endl '\n'
#define ll long long
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
 
 
// const int mx = 2e5+7;
// vector<int> adj[mx];
// bool vis[mx];
// int n,m,cnt=0,st,x=0,y=0;
 
ll inf = 1e16;
 
const int mx = 1e6+7;
const int mod = 1e9+7;
 
 
 
 
 
void solve(){
 
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> adj[n+1];
 
  rep(i,0,m){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
  }
 
  priority_queue<pair<ll,pair<int,int>> , vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> pq;
 
  vector<vector<ll>> dist(n+1,vector<ll>(2,inf));
 
  dist[1][0] = 0;
 
  pq.push({0,{1,0}});
 
  while(!pq.empty()){
 
        auto p = pq.top();
        pq.pop();
 
        ll d = p.first;
        int node = p.second.first;
        int used = p.second.second;
 
        if(d>dist[node][used])
            continue;
 
        for(auto it : adj[node]){
 
            int child = it.first;
            int wt = it.second;
 
            ll new_dist = d+wt;
 
            if(dist[child][used]>new_dist){
                dist[child][used] = new_dist;
                pq.push({dist[child][used],{child,used}});
            }
 
            new_dist = d+wt/2;
 
            if(!used and dist[child][!used]>new_dist){
                dist[child][!used] = new_dist;
                pq.push({dist[child][!used], {child,!used}});
            }
        }
  }
 
  cout<<min(dist[n][0],dist[n][1])<<endl;
 
}
 
 
int main() {
 
 
   fastio;
  // int t; cin>>t; while(t--)
   solve();
}


**You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll INF = 1e18;
 
struct triplet {
    int u,v;
    ll wt;
};
 
 
vector<triplet>v;
vector<ll>dist;
vector<int>parent;
int n,m;
 
 
void Bellman_ford(){
 
    int last;
    for(int i=1; i<=n; i++){
        
        last = -1;
 
        for(auto it : v){
 
            int u = it.u;
            int v = it.v;
            ll wt = it.wt;
 
            if(dist[v]>dist[u]+wt){
                dist[v] = dist[u]+wt;
                parent[v] = u;
                last = v;
            }
        }
    }
 
    if(last==-1){
        cout<<"NO"<<endl;
        return;
    }
 
    for(int i=1; i<=n; i++)
        last = parent[last];
 
    vector<int> cycle;
 
    for(int x = last; ; x = parent[x]){
        cycle.push_back(x);
        if(x==last and cycle.size()>1)
            break;
    }
 
    reverse(cycle.begin(),cycle.end());
 
    cout<<"YES"<<endl;
 
    for(auto it:cycle)
        cout<<it<<' ';
    cout<<endl;
}
 
 
void solve(){
 
    cin>>n>>m;
 
    v.resize(m);
    dist.resize(n+1);
    parent.resize(n+1,-1);
 
 
    for(int i=0; i<m; i++){
        cin>>v[i].u>>v[i].v>>v[i].wt;
    }
 
    Bellman_ford();
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}
