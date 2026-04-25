class Solution {
public:
    int fun(vector<int> &nums,int k){
        int i = 0,res = 0;
        for(int j = 0;j < nums.size();j++){
            k -= nums[j]%2;
            while(k < 0){
                k += nums[i++]%2;
            }
            res += j-i+1;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return fun(nums,k) - fun(nums,k-1);
    }
};