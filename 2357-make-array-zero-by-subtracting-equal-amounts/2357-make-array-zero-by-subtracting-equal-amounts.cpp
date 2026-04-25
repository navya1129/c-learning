class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sum = 0,cnt = 0;
        map<int,int> m;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != 0) {
                m[nums[i]]++;
            }
        }
        return m.size();
    }
};