class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans =0;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            int temp = ((i+1)*(n-i));
            if(temp%2 == 0) ans += (temp/2)*arr[i];
            else ans += ((temp+1)/2) * arr[i];
        }
        return ans;
    }
};