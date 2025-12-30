class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int left_cnt = 0;
        int right_cnt = 0;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] <= right){
                cnt++;
            }
            else cnt = 0;
            right_cnt += cnt;
        }
        cnt = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] < left){
                cnt++;
            }
            else cnt =0;
            left_cnt += cnt;
        }
        return right_cnt - left_cnt;
    }
};