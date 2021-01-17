#include<bits/stdc++.h>
using namespace std;
string lcs(string x, string y, int n, int m){
  int dp[n+1][m+1];
  for(int i=0; i<=n; i++){
      for(int j=0; j<=m; j++){
          if(i==0||j==0)
          dp[i][j]=0;
          else if(x[i-1]==y[j-1])
          dp[i][j]=1+dp[i-1][j-1];
          else{
              dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
          }
      }
  }
  string s="";
  int i=n, j=m;
  while(i>0&&j>0){
      if(x[i-1]==y[j-1]){
          s.push_back(x[i-1]);
          i--;j--;
      }
      else{
          if(dp[i-1][j]>dp[i][j-1]){
              i--;
          }
          else
          {
              j--;
          }
          
      }
  }
  reverse(s.begin(),s.end());
  return s;
}
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    cout<<lcs(x,y,n,m)<<endl;
    return 0;
}