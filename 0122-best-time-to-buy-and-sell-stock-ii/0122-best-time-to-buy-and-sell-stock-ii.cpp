class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0;
        int prev = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(prev > nums[i]) prev = nums[i];
            if(prev < nums[i]) {
                ans += nums[i]-prev;
                prev = nums[i];
            }
        }
        return ans;
    }
};