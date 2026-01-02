class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        map<int,int> m;
        for(int i = 0;i < 2*n;i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second  > 1) return i.first;
        }
        return 0;
    }
};