class Solution {
public:
    int fun(vector<int> nums,int goal){
        if(goal == -1) return 0;
        int i = 0,res = 0,sum = 0;
        for(int j = 0;j < nums.size();j++){
            goal -= nums[j];
            while(goal < 0 && i <= j) goal += nums[i++];
            res += j-i+1;
        }
        cout << res << " ";
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal) - fun(nums,goal-1);
    }

};