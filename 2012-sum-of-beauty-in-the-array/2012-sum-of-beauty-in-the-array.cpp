class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[n-1];
        for(int i =1;i < n-1;i++){
            pre[i] = maxi;
            maxi = max(maxi,nums[i]);
        }
        for(int i = n-1;i >= 1;i--){
            suf[i] = mini;
            mini = min(mini,nums[i]);
        }
        int sum = 0;
        for(int i = 1;i < n-1;i++){
            if(pre[i] < nums[i] && nums[i] < suf[i]) sum += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) sum += 1;
        }
        return sum;
    }
};