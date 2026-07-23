class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int cnt = 0;
        while(n > 0){
            cnt++;
            n = n/2;
        }
        return pow(2,cnt);
    }
};