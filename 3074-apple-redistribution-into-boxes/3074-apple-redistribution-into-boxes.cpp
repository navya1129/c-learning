class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int j = 0;
        int cnt =0;
        int sum  =0;
        for(int i = 0;i < n;i++){
            sum += apple[i];
        }
        int pre  =0;
        sort(capacity.begin(),capacity.end());
        for(int i = m-1;i >= 0;i--){
            cnt++;
            pre += capacity[i];
           if(pre >= sum) return cnt;
        }
        return cnt;
    }
};