class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int cnt =0;
        while(!q.empty()){
            int temp = q.size();
            for(int i = 0;i < temp;i++){
                auto [a,b] = q.front();
                q.pop();
                if(a-1 >= 0 && grid[a-1][b] == 1 && vis[a-1][b] != 1){
                    q.push({a-1,b});
                    vis[a-1][b] = 1;
                }
                if(b-1 >= 0 && grid[a][b-1] == 1 && vis[a][b-1] != 1){
                    q.push({a,b-1});
                    vis[a][b-1] = 1;
                }
                if(a+1 < n && grid[a+1][b] == 1 && vis[a+1][b] != 1){
                    q.push({a+1,b});
                    vis[a+1][b] = 1;
                }
                if(b+1 < m && grid[a][b+1] == 1 && vis[a][b+1] != 1){
                    q.push({a,b+1});
                    vis[a][b+1] = 1;
                }
            }
            if(q.size() != 0) cnt++;
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1) return -1;
            }
        }
        return cnt;
    }
};