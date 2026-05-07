class Solution {
public:
    int fun(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i == m-1 && j == n-1) return 1;
        if(i >= m ||j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res1 = 0,res2 = 0;
        res1 = fun(m,n,i+1,j,dp);
        res2 = fun(m,n,i,j+1,dp);
        return dp[i][j] = res1 + res2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return fun(m,n,0,0,dp);
    }
};