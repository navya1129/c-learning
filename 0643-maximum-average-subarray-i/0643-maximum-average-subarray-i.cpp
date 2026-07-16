class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double sum = 0;
        int n = nums.size();
        for(int i = 0;i < k;i++){
            sum += nums[i];
        }
        // cout << -1/1;
        ans = max(ans,sum/k);
        cout << sum << " " << k << " " << ans;
        int i = 0;
        int j = k;
        while(j < n){
            sum -= nums[i];
            sum += nums[j];
            i++;
            j++;
            ans = max(ans,sum/k);
        }
        return ans;
    }
};