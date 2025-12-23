class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        long long sum = 0;
        long long ans = 0;
        int j = 0;
        for(int i = 0;i < k;i++){
            sum += nums[i];
            m[nums[i]]++;
        }
        if(m.size() == k) ans = max(ans,sum);
        for(int i = k;i < nums.size();i++){
            sum -= nums[j];
            sum += nums[i];
            m[nums[j]]--;
            if(m[nums[j]] == 0) m.erase(nums[j]);
            m[nums[i]]++;
            if(m.size() == k && ans < sum) ans = sum;
            j++;
        }
        return ans;
    }
};