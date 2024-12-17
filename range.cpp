**Given an array of n integers, your task is to process q queries of the following types:

update the value at position k to u
what is the sum of values in range [a,b]?

#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
const int mx = 2e5+7;
int a[mx];
ll sum[4*mx];
int n,q;
 
void build_seg(int node, int low, int high){
 
    if(low==high){
        sum[node] = a[low];
        return;
    }
 
    int left = 2*node;
    int right = left+1;
    int mid = (low+high)/2;
 
    build_seg(left, low, mid);
    build_seg(right, mid+1, high);
 
    sum[node] = sum[left] + sum[right];
}
 
 
void update(int node, int low, int high, int idx, int val){
 
    if(low==high){
        sum[node] = val;
        return;
    }
 
    int left = 2*node;
    int right = left+1;
    int mid = (low+high)/2;
 
    if(idx<=mid)
        update(left,low,mid,idx,val);
    else
        update(right,mid+1,high,idx,val);
 
    sum[node] = sum[left]+sum[right];
}
 
 
ll query(int node, int low, int high, int l, int r){
 
 
    int left = 2*node;
    int right = left+1;
    int mid = (low+high)/2;
 
    if(high<l or low>r)
        return 0;
 
    if(low>=l and high<=r)
        return sum[node];
 
    return query(left,low,mid,l,r) + query(right,mid+1,high,l,r);
}
 
 
void solve(){
    cin>>n>>q;
 
    for(int i=1; i<=n; i++)
        cin>>a[i];
 
    build_seg(1,1,n);
 
    while(q--){
        int k;
        cin>>k;
 
        if(k==1){
            int idx, val;
            cin>>idx>>val;
            update(1,1,n,idx,val);
        }
 
        else{
            int l,r;
            cin>>l>>r;
 
            ll x = query(1,1,n,l,r);
            cout<<x<<endl;
        }
    }
}
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}

**Given an array of n integers, your task is to process q queries of the following types:

increase each value in range [a,b] by u
what is the value at position k?

#include <bits/stdc++.h>
using namespace std;
 
const int mx = 2e5 + 7;
long long tree[4 * mx], lazy[4 * mx];
vector<int> arr(mx);
int n, q;
 
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
    }
}
 
void propagate(int node, int start, int end) {
    tree[node] += lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}
 
void update(int node, int start, int end, int l, int r, int x) {
    if (start > r || end < l) {
        return;
    }
    if (start >= l && end <= r) {
        lazy[node] += x;
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, x);
    update(2 * node + 1, mid + 1, end, l, r, x);
}
 
long long query(int node, int start, int end, int k) {
    if (lazy[node] != 0) propagate(node, start, end);
    if (start == end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    if (k <= mid) {
        return query(2 * node, start, mid, k);
    } else {
        return query(2 * node + 1, mid + 1, end, k);
    }
}
 
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else if (type == 2) {
            int k;
            cin >> k;
            cout << query(1, 1, n, k) << '\n';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}


**You are given an n \times n grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).
Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
void solve() {
 
    int n,q;
    cin>>n>>q;
 
    vector<string>v(n+1);
 
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        s = '#'+s;
        v[i] = s;
    }
 
    vector<vector<ll>> pf(n+1,vector<ll>(n+1));
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            pf[i][j] = (v[i][j] == '*');
 
            pf[i][j] += (pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1]);
        }
    }
 
    while(q--){
 
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
 
        ll ans = pf[x2][y2] - pf[x1-1][y2]-pf[x2][y1-1]+pf[x1-1][y1-1];
 
        cout<<ans<<endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}


**There are n hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.
The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
const int mx = 2e5+7;
int a[mx];
ll tree[4*mx];
int n,q,ans;
 
void build_seg(int node, int low, int high){
 
    if(low==high){
        tree[node] = a[low];
        return;
    }
 
    int left = 2*node;
    int right = left+1;
    int mid = (low+high)/2;
 
    build_seg(left, low, mid);
    build_seg(right, mid+1, high);
 
    tree[node] = max(tree[left] , tree[right]);
}
 
 
void update(int node, int low, int high, int val){
 
    if(low==high){
        if(tree[node]<val){
            ans = 0;
            return;
        }
 
        tree[node] -= val;
        ans = low;
        return;
    }
 
    int left = 2*node;
    int right = left+1;
    int mid = (low+high)/2;
 
    if(val<=tree[left])
        update(left,low,mid,val);
    else 
        update(right,mid+1,high,val);
    
    tree[node] = max(tree[left],tree[right]);
}
 
 
ll query(int node, int low, int high, int l, int r){
 
 
    int left = 2*node;
    int right = left+1;
    int mid = (low+high)/2;
 
    if(high<l or low>r)
        return INT_MAX;
 
    if(low>=l and high<=r)
        return tree[node];
 
    return max(query(left,low,mid,l,r) , query(right,mid+1,high,l,r));
}
 
 
void solve(){
    cin>>n>>q;
 
    for(int i=1; i<=n; i++)
        cin>>a[i];
 
    build_seg(1,1,n);
 
    while(q--){
        
        int r;
        cin>>r;
 
        update(1,1,n,r);
        cout<<ans<<endl;
    }
}
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}
