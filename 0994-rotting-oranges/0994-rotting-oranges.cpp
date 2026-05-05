class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int pre = q.size();
        int cnt = 0;
        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();
            if(a+1 < n && grid[a+1][b] == 1 && vis[a+1][b] == 0){
                vis[a+1][b] = 1;
                q.push({a+1,b});
            }
            if(a-1 >= 0 && grid[a-1][b] == 1 && vis[a-1][b] == 0){
                vis[a-1][b] = 1;
                q.push({a-1,b});
            }
            if(b+1 < m && grid[a][b+1] == 1 && vis[a][b+1] == 0){
                vis[a][b+1] = 1;
                q.push({a,b+1});
            }
            if(b-1 >= 0 && grid[a][b-1] == 1 && vis[a][b-1] == 0){
                vis[a][b-1] = 1;
                q.push({a,b-1});
            }
            pre--;
            if(pre == 0) {
                pre = q.size();
                cnt++;
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1) return -1;
            }
        }
        if(cnt == 0) return 0;
        return cnt-1;
    }
};