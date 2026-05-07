class Solution {
public:
    bool fun(vector<int> &nums,int tot,int curr,int i,int n,bool ans,vector<vector<int>> &dp){
        if(ans) return ans;
        if(curr == tot) return true;
        if(i >= n) return false;
        if(dp[i][curr] != -1) return dp[i][curr];
        ans = fun(nums,tot,curr+nums[i],i+1,n,ans,dp);
        if(ans) return ans;
        ans = fun(nums,tot,curr,i+1,n,ans,dp);
        return dp[i][curr] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(n,vector<int> (20000,-1));
        return fun(nums,sum/2,0,0,n,false,dp);
    }
};