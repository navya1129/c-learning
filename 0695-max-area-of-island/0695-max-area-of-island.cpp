class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int cnt = 1;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        auto [a,b] = q.front();
                        q.pop();
                        if(a+1 < n && grid[a+1][b] == 1 && vis[a+1][b] == 0){
                            q.push({a+1,b});
                            vis[a+1][b] = 1;
                            cnt++;
                        }
                        if(b+1 < m && grid[a][b+1] == 1 && vis[a][b+1] == 0){
                            q.push({a,b+1});
                            vis[a][b+1] = 1;
                            cnt++;
                        }
                        if(a-1 >= 0 && grid[a-1][b] == 1 && vis[a-1][b] == 0){
                            q.push({a-1,b});
                            vis[a-1][b] = 1;
                            cnt++;
                        }
                        if(b-1 >= 0 && grid[a][b-1] == 1 && vis[a][b-1] == 0){
                            q.push({a,b-1});
                            vis[a][b-1] = 1;
                            cnt++;
                        }
                    }
                    ans = max(ans,cnt);
                }

            }
        }
        return ans;
    }
};