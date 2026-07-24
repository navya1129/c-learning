class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,int> m;
        unordered_map<int,int> unique;
        int n = nums.size();
        vector<int> temp;
        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                unique[nums[i]^nums[j]]++;
            }
        }
        int x = 0;
        for(auto i:unique){
            for(int j= 0;j < n;j++){
                m[i.first^nums[j]]++;
            }
            x++;
        }
        return m.size();
    }
};