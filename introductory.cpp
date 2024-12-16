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
