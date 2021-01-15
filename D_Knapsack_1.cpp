#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll int dp[104][100004];
ll int knapsack(ll int a[], ll int b[], ll int n, ll int w){
    if(n==0||w==0){
        return 0;
    }
    if(dp[n][w]!=-1)
    return dp[n][w];
    ll int ans;
    if(a[n-1]<=w){
       ans= max(knapsack(a,b,n-1,w-a[n-1])+b[n-1], knapsack(a,b,n-1,w));
    }
    else{
        ans=knapsack(a,b,n-1,w);
    }
    return dp[n][w]=ans;
}
int main(){
    ll int n,w;
    cin>>n>>w;
    ll int weight[n+1];
    ll int value[n+1];
    for(ll int i=0; i<n; i++){
        cin>>weight[i];
        cin>>value[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(weight,value,n,w)<<endl;
    return 0;
}