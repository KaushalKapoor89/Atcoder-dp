#include<bits/stdc++.h>
using namespace std;
int a[30000],b[40000];
int n,w;
int dp[104][100003];
long long int knapsack(int r, int i){
  if(i==n&&r>0)
  return INT_MAX;
   if(r==0)
   return 0;
    if(dp[i][r]!=-1)
    return dp[i][r];
   long long  int ans;
   if(b[i]<=r)
   ans=min(a[i]+knapsack(r-b[i],i+1), knapsack(r,i+1));
   else
   ans=knapsack(r,i+1);
   return dp[i][r]=ans;

}
long long int solve(long long int V){
    for(long long int i=V; i>=0; i--){
        if(knapsack(i,0)<=w)
        return i;
    }
    return 0;
}
int main(){
    cin>>n>>w;
        memset(dp,-1,sizeof(dp));
    long long int v=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        cin>>b[i];
        v=v+b[i];
    }
 cout<<solve(v)<<endl;
 return 0;
}