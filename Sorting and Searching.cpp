**There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
  void solve() {
 
    ll n,m;
    cin>>n>>m;
 
    multiset<int> st;
 
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        st.insert(x);
    }
 
    while(m--){
        
        int x;
        cin>>x;
 
        auto it = st.upper_bound(x);
 
        if(it==st.begin())
            cout<<-1<<endl;
        else{
            cout<<*(--it)<<endl;
            st.erase(it);
        }
    }
 
   
}


**You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
void solve() {
 
    int n;
    cin>>n;
 
    vector<pair<int,int>> v;
 
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b,-1});
    }
 
    sort(all(v));
 
    int cur = 0, mx = 0;
 
    n = v.size();
 
    rep(i,0,n){
        cur += v[i].second;
        mx = max(cur,mx);
    }
 
    cout<<mx<<endl;
 
   
}


**You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<pair<int, int>> v(n);
    rep(i, 0, n) {
        int a;
        cin >> a;
        v[i] = {a, i + 1};
    }
 
    // Sort array based on values, keeping original indices
    sort(all(v));
 
    rep(i, 0, n) {
        int nxt = x - v[i].first;
 
        // Use binary search to find the complement
        auto it = lower_bound(v.begin() + i + 1, v.end(), make_pair(nxt,-1));
 
        // Check if the element found matches `nxt`
        if (it != v.end() && it->first == nxt) {
            cout << v[i].second << ' ' << it->second << endl;
            return;
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
}


**collecting numbers in increasing order
void solve() {
 
    int n,m;
    cin>>n>>m;
 
    ll a[n+3],pos[n+3];
 
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pos[a[i]] = i;
    }
 
    int ans = 1;
 
    for(int i=1; i<n; i++)
        ans += pos[i]>pos[i+1];
 
    while(m--){
        int l,r;
        cin>>l>>r;
 
        int x = a[l];
        int y = a[r];
 
        set<pair<int,int>>st;
 
        if(x>1)
            st.insert({x-1,x});
        if(x<n)
            st.insert({x,x+1});
        if(y>1)
            st.insert({y-1,y});
        if(y<n)
            st.insert({y,y+1});
 
    for(auto it:st){
        ans -= (pos[it.first]>pos[it.second]);
    }
 
    swap(a[l],a[r]);
    pos[a[l]] = l;
    pos[a[r]] = r;
 
    for(auto it:st)
        ans += pos[it.first]>pos[it.second];
 
    cout<<ans<<endl;
}


** longest sequence of successive songs where each song is unique?
void solve() {
 
int n;
cin>>n;
 
int a[n+1];
rep(i,1,n+1)
cin>>a[i];
 
int ans = 0;
 
map<int,int>mp;
 
int st = 1;
 
rep(i,1,n+1){
 
    if(mp[a[i]]>=st){
 
       // cout<<st<<' '<<i<<endl;
        ans = max(ans,i-st);
        st = mp[a[i]]+1;
    }
 
    mp[a[i]] = i;
}
 
 
 
ans = max(ans,n-st+1);
 
cout<<ans<<endl;
 
}

**the minimum number of towers.
void solve() {
 
    int n;
    cin>>n;
    vector<int>v;
    int x;
    cin>>x;
    v.push_back(x);
 
    for(int i=1; i<n; i++){
        cin>>x;
        int idx = upper_bound(all(v),x)-v.begin();
        if(idx!=v.size())
            v[idx] = x;
        else
            v.push_back(x);
    }
 
    cout<<v.size()<<endl;
 
}

**Your task is to calculate the length of the longest passage without traffic lights after each addition.
void solve() {
 
    int x,n;
    cin>>x>>n;
 
    multiset<pair<int,int>> st;
    st.insert({x,0});
 
    int ans = 0;
 
    multiset<int> dist;
    dist.insert(x-0);
 
    rep(i,0,n){
        cin>>x;
        auto it = st.upper_bound(make_pair(x,-1));
        int l = it->second;
        int r = it->first;
 
        int old = r-l;
        dist.insert(x-l);
        dist.insert(r-x);
        dist.erase(dist.find(old));
 
        st.insert({x,l});
        st.insert({r,x});
        st.erase(it);
 
        cout<<*(--dist.end())<<endl;
    }
 
}


**Given n ranges, your task is to determine for each range if it contains some other range and if some other range contains it.
bool cmp(const pair<int,int>&a, const pair<int,int>&b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}
 
void solve() {
 
    int n;
    cin>>n;
 
    vector<pair<int,int>> v(n);
    map<pair<int,int>,int> mp;
 
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v[i] = {x,y};
        mp[{x,y}] = i;
    }
 
    sort(all(v),cmp);
 
    int cnt = 0;
 
    int r = v[n-1].second;
 
    vector<int> ans(n,0),ans2(n,0);
 
    for(int i=n-2; i>=0; i--){
        
        ans[mp[v[i]]] = v[i].second>=r;
        r = min(v[i].second,r);
    }
 
   r = v[0].second;
 
   for(int i=1; i<n; i++){
    ans2[mp[v[i]]] = v[i].second<=r;
    r = max(r,v[i].second);
   }
 
   rep(i,0,n)
   cout<<ans[i]<<' ';
   cout<<endl;
 
   rep(i,0,n)
   cout<<ans2[i]<<' ';
   cout<<endl;
}
 
int main() {
    fastio;
    solve();
    return 0;
}


**Given n ranges, your task is to count for each range how many other ranges it contains and how many other ranges contain it.

#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
bool cmp(const pair<int,int>&a, const pair<int,int>&b){
    if(a.first==b.first)
    return a.second>b.second;
    return a.first<b.first;
}
 
void solve() {
    int n;
    cin>>n;
//  cout<<n<<endl;
    
    vector<pair<int,int>> v(n);
    map<pair<int,int>,int>mp;
    
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v[i] = {x,y};
        mp[v[i]] = i;
    }
    
  sort(v.begin(),v.end(),cmp);
  
  vector<int>ans(n,0);
  ordered_set<pair<int,int>> st;
  
  for(int i=n-1; i>=0; i--){
    ans[mp[v[i]]] = st.order_of_key({v[i].second,i});
    st.insert({v[i].second,-i});
  }
  
  for(int i=0; i<n; i++)
  cout<<ans[i]<<' ';
  cout<<endl;
  
  vector<int>ans2(n,0);
  st.clear();
  
  for(int i=0; i<n; i++){
    ans2[mp[v[i]]] = st.size() - st.order_of_key({v[i].second,-i});
    st.insert({v[i].second,i});
  }
  
  for(int i=0; i<n; i++)
  cout<<ans2[i]<<' ';
  cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    solve();
        
     return 0;
}


**Room Allocation
struct man
{
    int enter, exit, index;
};
 
 
bool cmp (const man& a, const man& b){
    return a.enter<b.enter;
}
 
 
void solve() {
 
    int n;
    cin>>n;
 
    vector<man>v(n);
 
    rep(i,0,n){
        cin>>v[i].enter;
        cin>>v[i].exit;
        v[i].index = i;
    }
 
    sort(all(v),cmp);
 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 
    int room = 1;
 
    vector<int>ans(n,0);
    ans[v[0].index] = 1;
 
    pq.push({v[0].exit,room});
 
 
    for(int i=1; i<n; i++){
 
        auto p = pq.top();
 
        if(v[i].enter>p.first){
            pq.pop();
            pq.push({v[i].exit,p.second});
            ans[v[i].index] = p.second;
        }
 
        else{
            pq.push({v[i].exit,++room});
            ans[v[i].index] = room;
        }
    }
 
    cout<<room<<endl;
    for(auto it:ans)
        cout<<it<<' ';
    cout<<endl;
}
 
int main() {
    fastio;
    solve();
    return 0;
}


**You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n);
    for(int i=0; i<n; i++)
    cin>>v[i];
    
    map<ll,pair<ll,ll>>mp;
    
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            if(mp.count(x-v[i]-v[j])){
                cout<<mp[x-v[i]-v[j]].first+1<<" ";
                cout<<mp[x-v[i]-v[j]].second+1<<" ";
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
        }
        
        for(ll j=0; j<i; j++){
            mp[v[i]+v[j]]={i,j};
        }
    }
    
    cout<<"IMPOSSIBLE"<<endl;
}


**Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.
void solve() {
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++)
    cin>>v[i];
    
    stack<pair<ll,ll>>st;
    
    for(int i=0; i<n; i++){
        while(st.size()>0 && st.top().first>=v[i]){
            st.pop();
        }
        if(st.size()>0)
        cout<<st.top().second<<" ";
        else
        cout<<0<<" ";
        st.push({v[i],i+1});
    }
}

**Given an array of n positive integers, your task is to count the number of subarrays having sum x.
void solve() {
    ll n,x;
    cin>>n>>x;
    ll sum=0;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    cin>>v[i];
    
    ll j=0,cnt=0;
    for(int i=0; i<n; i++){
        while(sum<x && j<n){
            sum+=v[j];
            j++;
        }
        if(sum==x){
            cnt++;
        }
        
        sum-=v[i];
    }
    cout<<cnt<<endl;
}

**Given an array of n integers, your task is to count the number of subarrays having sum x.
void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n);
    for(int i=0; i<n; i++)
    cin>>v[i];
    
    ll sum=0,ans=0;
    map<ll,ll>seen;
    
    seen[0]++;
    for(int i=0; i<n; i++){
        sum+=v[i];
        ans+=seen[sum-x];
        seen[sum]++;
    }
    cout<<ans<<endl;
}

**Given an array of n integers, your task is to calculate the number of subarrays that have at most k distinct values.
  void solve(){
  
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
 
  ll ans=0;
  map<int,int>mp;
  int i=0,j=0;
  
    while(j<n){
        while(j<n and mp.size()<=k){
            mp[a[j]]++;
            if(mp.size()<=k){
                ans+=j-i+1;
                j++;
            }
 
            else
                break;
        }
 
        while(mp.size()>k){
            mp[a[i]]--;
            if(mp[a[i]]==0){
                mp.erase(a[i]);
                i++;
                ans+=j-i+1;
                j++;
                break;
            }
            i++;
        }
    }
 
  cout<<ans<<endl;
 
}

**You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
#define ll long long int
#define INF (ll)1e16
 
bool isvalid(ll mid,ll n,ll k, ll a[]){
    ll sum=0, group=0;
    for(ll i=0; i<n; i++){
        if(a[i]>mid)
        return false;
        if(sum+a[i]>mid){
            group++;
            sum=0;
        }
        sum+=a[i];
    }
    if(sum>k)
    group++;
    return group<=k;
}
 
void binary(ll a[],ll n, ll k, ll sum){
    ll lo=0, hi=sum,ans=0;
    while(lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(isvalid(mid,n,k,a)){
            ans=mid;
            hi=mid-1;
        }
        else
        lo=mid+1;
    }
    cout<<ans<<endl;
}
 
void solve() {
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll sum=0;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        
        sum+=a[i];
    }
    binary(a,n,k,sum);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    solve();
        
     return 0;
}


**You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.
The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
 
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>v(n);
    ordered_set<pair<ll,ll>>st; 
    for(ll i=0; i<n; i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    for(ll i=0; i<k; i++){
        st.insert(v[i]);
    }
    cout<<st.find_by_order((k-1)/2)->first<<" "; 
    for(ll i=k; i<n; i++){
        st.erase(v[i-k]);
        st.insert(v[i]);
        cout<<st.find_by_order((k-1)/2)->first<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    solve();
        
     return 0;
}
