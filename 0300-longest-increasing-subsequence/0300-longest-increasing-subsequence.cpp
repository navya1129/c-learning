class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis;
        for(int i = 0; i < n; i++){
            
            if(lis.size() == 0) lis.push_back(nums[i]);
            else{
                if(lis[lis.size()-1] < nums[i]) lis.push_back(nums[i]);
                else{
                    int idx = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                    if(idx < lis.size()) lis[idx] = nums[i];
                }
            }
        }
        return lis.size();
    }
};