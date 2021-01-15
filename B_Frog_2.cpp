#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll int n,k;
    cin>>n>>k;
    ll int a[n+2];
    for(ll int i=1; i<=n;i++)
    cin>>a[i];
   ll int dp[n+2];
    memset(dp,1000004,sizeof(dp));
    dp[0]=INT_MAX;
    dp[1]=0;
    dp[2]=abs(a[2]-a[1]);
    for(ll int i=3; i<=n; i++){
        for(ll int j=i-k; j<=i-1; j++){
       dp[i]=min(dp[i], dp[j]+abs(a[i]-a[j]));
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}