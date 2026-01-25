class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int j = 0;
        for(int i = k-1;i < nums.size();i++){
            mini = min(mini,nums[i]-nums[j]);
            j++;
        }
        return mini;
    }
};