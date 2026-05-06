class Solution {
public:
    int fun(int i,vector<int> &nums, int n, vector<int> &dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + fun(i+2,nums,n,dp);
        int notpick = fun(i+1,nums,n,dp);

        return dp[i] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return fun(0,nums,n,dp);
    }
};