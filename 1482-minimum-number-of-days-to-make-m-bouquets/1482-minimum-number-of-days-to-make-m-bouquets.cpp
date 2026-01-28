class Solution {
public:
    bool fun(vector<int>& bloomDay, int mid, int n,int k,int m){
        int temp = m;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else cnt = 0;
            if(cnt == k) {
                temp--;
                cnt = 0;
            }
            if(temp == 0) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();
        if(1LL*m*k > n) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0;i < n;i++){
            mini = min(bloomDay[i],mini);
            maxi = max(bloomDay[i],maxi);
        }
        int low = mini,high = maxi,ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            cout << mid;
            if(fun(bloomDay,mid,n,k,m)){
                high = mid-1;
                // ans = mid;
            }
            else low = mid+1;
            
        }

        return low;
    }
};