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
                i++;
                if(i < n) left = max(left,height[i]);
            }
            else{
                ans += max(0,right - height[j]);
                j--;
                if(j >= 0) right = max(right,height[j]);
            }
        }
        return ans;
    }
};