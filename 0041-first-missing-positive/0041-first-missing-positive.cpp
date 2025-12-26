class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i < nums.size();i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        cout << nums[0];
        if(nums[0] != 1) return 1;
        for(int i =0;i < n;i++){
            cout << nums[i] << " " << i+1 << "\n";
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};