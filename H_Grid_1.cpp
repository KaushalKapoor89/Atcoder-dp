#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main(){
    int n,m;
    cin>>n>>m;
    int grid[n+1][m+1];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin>>c;
            if(c=='#')
            grid[i][j]=1;
            else
            {
                grid[i][j]=0;
            }
            
        }
    }
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1; i<n; i++)
    {
        if(grid[i][0]==1)
        break;
        else
        {
            dp[i][0]=1;
        }
        
    }
    for(int i=1; i<m; i++)
    {
        if(grid[0][i]==1)
        break;
        else
        {
            dp[0][i]=1;
        }
        
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(grid[i][j]==1){
                continue;
            }
        else{
            dp[i][j]=(dp[i-1][j]%M+dp[i][j-1]%M)%M;
        }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
    }