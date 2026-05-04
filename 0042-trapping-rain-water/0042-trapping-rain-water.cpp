class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = height[0];
        int right = height[n-1];
        int i = 0,j = n-1;
        int ans = 0;
        while(i <= j){
            if(left <= right){
                ans += max(0,left-height[i]);
                if(i < n) left = max(left,height[i]);
                i++;
            }
            else{
                ans += max(0,right - height[j]);
                if(j >= 0) right = max(right,height[j]);
                j--;
            }
        }
        return ans;
    }
};