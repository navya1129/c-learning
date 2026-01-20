class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j < nums[i]; j++){
                if(int(j | (j+1)) == nums[i]) {
                    ans.push_back(j);
                    break;
                }
                
            }
            if(nums[i] == 2) ans.push_back(-1);

        }
        return ans;
        
    }
};