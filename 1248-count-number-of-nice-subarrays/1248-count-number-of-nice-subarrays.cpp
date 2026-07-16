class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> m;
        int n = nums.size();
        m[0] = 1;
        int ans = 0;
        int pre = 0;
        for(int i = 0;i < n;i++){
            if(nums[i]%2 == 1) pre++;
            if(m.find(pre-k) != m.end()) ans += m[pre-k];
            m[pre]++;
        }
        return ans;
    }
};