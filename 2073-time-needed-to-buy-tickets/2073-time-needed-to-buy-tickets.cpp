class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int n = tickets.size();
        for(int i = 0;i < n;i++){
            q.push({i,tickets[i]});
        }
        int cnt = 1;
        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();
            b--;
            if(b == 0 && a == k) return cnt;
            else if(b > 0) q.push({a,b});
            cnt++;
        }
        return cnt;
    }
};