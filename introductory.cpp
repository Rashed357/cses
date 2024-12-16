*ways to place two knights on k*k chessboard.
void solve(){
 
  ll m;
  cin>>m;
 
  for(ll k=1; k<=m; k++){
 
  ll n = k*k;
 
  n = n*(n-1)/2;
 
  ll np = 4*(k-1)*(k-2);
 
  cout<<n-np<<endl;
}
 


**Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
  void solve(){
 
  ll n;
  cin>>n;
 
  ll sum = (n*(n+1))/2;
 
  if(sum%2){
    no;
    return;
  }
 
  yes;
 
  set<ll>a,b;
 
  for(int i=1; i<=n; i++)
    a.insert(i);
 
  ll need = sum/2;
 
  ll large = n;
 
  while(a.find(need)==a.end() and need>0){
    b.insert(large);
    a.erase(large);
    need -= large;
    large--;
  }
 
  if(need>0){
    b.insert(need);
    a.erase(need);
  }
 
  cout<<a.size()<<endl;
  for(auto it:a)
    cout<<it<<' ';
 
  cout<<endl<<b.size()<<endl;
 
  for(auto it:b)
    cout<<it<<' ';
  cout<<endl;
 
}



**Your task is to calculate the number of trailing zeros in the factorial n!.
ll legendre(ll n, ll p){
  ll cnt = 0;
 
  while(p<=n){
    cnt += n/p;
    p *= 5;
  }
 
  return cnt;
}
 
 
void solve(){
 
  ll n;
  cin>>n;
 
  cout<<legendre(n,5)<<endl;
 
}


**You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.

void solve(){
 
  ll a,b;
  cin>>a>>b;
 
  if(a>b)
    swap(a,b);
 
  if(2*a<b or (a+b)%3 != 0)
    no;
  else
    yes;
 
}


**Your task is to create a Gray code for a given length n.
vector<string> f(int n){
 
  if(n==1){
    return {"0","1"};
  }
 
  vector<string> prev = f(n-1);
  vector<string> cur;
 
  for(int i=0; i<prev.size(); i++)
    cur.push_back("0"+prev[i]);
 
  for(int i=prev.size()-1; i>=0; i--)
    cur.push_back("1"+prev[i]);
 
  return cur;
}
 
 
void solve(){
 
  int n;
  cin>>n;
 
  vector<string> v = f(n);
 
  for(auto it:v)
    cout<<it<<endl;
}

**tower of hanoi
void f(int n, int a, int b, int c){
  if(n==0){
    //cout<<a<<' '<<c<<endl;
    return;
  }
 
  f(n-1,a,c,b);
  cout<<a<<' '<<c<<endl;
  f(n-1,b,a,c);
}
 
 
void solve(){
 
  int n;
  cin>>n;
 
  cout<<(1<<n)-1<<endl;
 
  f(n,1,2,3);
}

**divide the array with minimum sum difference
ll f(int i,ll temp, int n, vector<int>& v, ll sum){
 
  if(i>=n){
   // cout<<temp<<endl;
    return abs(sum - 2*temp);
  }
 
  ll x = 1e18, y = 1e18;
 
  x = f(i+1,temp,n,v,sum);
  y = f(i+1,temp+v[i],n,v,sum);
 
  return min(x,y);
}


** place eight queens on a chessboard so that no two queens are attacking each other
const int N = 8;
vector<string> chess;
bool col[N],lfd[2*N],rtd[2*N];
int cnt = 0;
 
 
void f(int r){
 
  if(r==N){
    cnt++;
    return;
  }
 
  for(int c=0; c<N; c++){
    int x = r+c;
    int y = r-c+N-1;
 
    if(!col[c] and !rtd[x] and !lfd[y] and chess[r][c]=='.'){
      col[c] = rtd[x] = lfd[y] = 1;
      f(r+1);
 
      col[c] = rtd[x] = lfd[y] = 0;
    }
  }
}
 
void mockingbird() {
 
  rep(i,0,N){
    string s;
    cin>>s;
    chess.push_back(s);
  }
 
  f(0);
 
  cout<<cnt<<endl;
}

** digit at position k in the string
const int mod = 1e9+7;
const int mx = 1e5+5;
 
vector<vector<int>> a, b;
 
 
 
 
ll mod_pow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base);
        base = (base * base);
        exp /= 2;
    }
    return res;
}
 
void solve() {
 
    ll k;
    cin>>k;
 
    if(k<10){
        cout<<k<<endl;
        return;
    }
 
    
   //1234567891011121314151617181920212223242
 
    ll sum = 0;  
    ll n=0;
 
    while(sum<k){
        n++;
 
        sum += (n*9*mod_pow(10,n-1));
    }
 
   ll last = mod_pow(10,n)-1;
 
   ll move = sum - k;
 
   last -= (move)/n;
 
   int r = move%n;
 
   string s = to_string(last);
 
   reverse(all(s));
 
   cout<<s[r]<<endl;
}
 
int main(){
  fastio;
 
  int t; cin>>t; while(t--)
  solve();
 
  return 0;
}



