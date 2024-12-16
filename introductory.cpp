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


