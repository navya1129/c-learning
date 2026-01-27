class Solution {
public:
    bool fun(vector<int>& weights, int days,int mid){
        int d = 1;
        int cap = 0;
        for(int i =0 ;i < weights.size();i++){
            if(cap + weights[i] > mid){
                d++;
                cap = 0;
            }
            cap += weights[i];
        }
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxi = 0;
        for(int i = 0;i < weights.size();i++){
            sum += weights[i];
            maxi = max(maxi,weights[i]);
        }
        int low = maxi,high = sum;
        cout << sum;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(fun(weights,days,mid)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};