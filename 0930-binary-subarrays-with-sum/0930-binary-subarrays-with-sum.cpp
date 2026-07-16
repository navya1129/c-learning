class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> m;
        int n = nums.size();
        int pre = 0;
        int ans = 0;
        m[0] = 1;
        for(int i = 0;i < n;i++){
            pre += nums[i];
            if(m.find(pre-goal) != m.end()) ans += m[pre-goal];
            m[pre]++;
        }
        return ans;
    }
};