**Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
void solve() {
 
    int n,x;
    cin>>n>>x;
 
    vector<int>dp(x+1,mx);
    vector<int>coins(n);
    rep(i,0,n)
    cin>>coins[i];
 
    dp[0] = 0;
 
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i>=coins[j])
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
        }
    }
 
  cout<<(dp[x]==mx? -1:dp[x])<<endl;
}

**Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
void solve() {
 
    int n,x;
    cin>>n>>x;
 
    vector<int>dp(x+1);
    vector<int>coins(n);
    rep(i,0,n)
    cin>>coins[i];
 
    dp[0] = 1;
 
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i>=coins[j])
                dp[i] = (dp[i] + dp[i-coins[j]]) % mod;
        }
    }
 
    cout<<dp[x]<<endl;
}


**Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<int> dp(x + 1, 0);
    dp[0] = 1; // One way to make 0: use no coins.
 
    vector<int> coins(n);
    rep(i, 0, n) {
        cin >> coins[i];
    }
 
    // For each coin
    for (int j = 0; j < n; j++) {
        // Update the dp array for sums from the coin value to x
        for (int i = coins[j]; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }
 
    cout << dp[x] << endl; // Output the number of ways to make x
}

**You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
const int mod = 1e9 + 7;
 
void solve() {
 
    int n;
    cin>>n;
 
    vector<int> ans(n+1);
 
    for(int i=1; i<=n; i++){
        int temp = i, mn = 1e8;
        while(temp){
            int dig = temp%10;
            temp/=10;
            if(dig!=0)
                mn = min(mn,1+ans[i-dig]);
        }
 
        ans[i] = mn;
    }
 
    cout<<ans[n]<<endl;
}

**You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
void solve() {
 
    int n,x;
    cin>>n>>x;
 
    vector<vector<int>> ans(n+1,vector<int>(x+1));
 
   
    vector<int>price(n+1),pages(n+1);
 
    rep(i,1,n+1)
    cin>>price[i];
    rep(i,1,n+1)
    cin>>pages[i];
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            ans[i][j] = ans[i-1][j];
            if(j>=price[i])
                ans[i][j] = max(ans[i-1][j],ans[i-1][j-price[i]]+pages[i]);
        }
    }
 
    cout<<ans[n][x]<<endl;
 
 
 
}


**You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.
Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.
const int mod = 1e9+7;
const int mx = 1e7+5;
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    int a[n + 1];
    rep(i, 1, n + 1) cin >> a[i];
 
    int dp[n + 3][m + 3];
    memset(dp, 0, sizeof(dp));
 
    // Initialize the first row of dp
    if (a[1] == 0) {
        rep(i, 1, m + 1)
            dp[1][i] = 1;
    } else {
        dp[1][a[1]] = 1;
    }
 
    for (int i = 2; i <= n; i++) {
        for (int x = 1; x <= m; x++) {
            if (a[i] == 0 || a[i] == x) {
                dp[i][x] = dp[i - 1][x]; // Current value is the same
                if (x > 1) {
                    dp[i][x] = (dp[i][x] + dp[i - 1][x - 1]) % mod; // Previous value is one less
                }
                if (x < m) {
                    dp[i][x] = (dp[i][x] + dp[i - 1][x + 1]) % mod; // Previous value is one more
                }
            } else {
                dp[i][x] = 0; // Not possible to fill this position
            }
        }
    }
 
    ll ans = 0;
 
    for (int j = 1; j <= m; j++)
        ans = (ans + dp[n][j]) % mod;
 
    cout << ans << endl;
}

**The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:

Add one character to the string.
Remove one character from the string.
Replace one character in the string.
  
void solve() {
 
    string a,b;
    cin>>a>>b;
 
    int n = a.size();
    int m = b.size();
 
    a = '#'+a;
    b = '#'+b;
 
 
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
 
    //cout<<f(n,m,a,b,dp)<<endl;
 
    rep(i,0,n+1)
    dp[i][0] = i;
 
    rep(j,0,m+1)
    dp[0][j] = j;
 
    rep(i,1,n+1){
        rep(j,1,m+1){
 
            if(a[i]==b[j])
                dp[i][j] = dp[i-1][j-1];
 
            else{
 
                int mn = INT_MAX;
 
                mn = min(mn, dp[i-1][j-1]);
                mn = min(mn, dp[i][j-1]);
                mn = min(mn,dp[i-1][j]);
 
                dp[i][j] = mn+1;
            }
        }
    }
 
    cout<<dp[n][m]<<endl;
}


**Given an a \times b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?
void solve(){
 
   int a,b;
   cin>>a>>b;
 
   int dp[a+1][b+1];
 
   for(int i=1; i<=a; i++){
 
      for(int j=1; j<=b; j++){
 
         if(i==j){
            dp[i][j] = 0;
            continue;
         }
 
         int ans = 1e9;
 
         for(int x=1; x<i; x++)
            ans = min(ans, dp[i-x][j]+dp[x][j]+1);
 
         for(int y = 1; y<j; y++)
            ans = min(ans, dp[i][j-y]+dp[i][y]+1);
 
         dp[i][j] = ans;
      }
   }
 
   cout<<dp[a][b]<<endl;
}

**You have n coins with certain values. Your task is to find all money sums you can create using these coins.
void solve(){
 
   int n;
   cin>>n;
 
   vector<int> v(n);
 
   rep(i,0,n)
   cin>>v[i];
 
   set<int> st;
 
   st.insert(v[0]);
 
   rep(i,1,n){
      set<int> tmp;
 
      for(auto it:st){
         int x = it+v[i];
         tmp.insert(x);
      }
 
      for(auto it:tmp)
         st.insert(it);
      
      st.insert(v[i]);
   }
 
   cout<<st.size()<<endl;
   for(auto it:st)
      cout<<it<<' ';
   cout<<endl;
}
 

