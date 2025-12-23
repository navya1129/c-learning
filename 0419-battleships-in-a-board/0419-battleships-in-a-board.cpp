class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        int cnt =0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j] == 'X' && vis[i][j] == 0){
                    q.push({i,j});
                    while(!q.empty()){
                        auto [a,b] = q.front();
                        q.pop();
                        if(a+1 < n && board[a+1][b] == 'X' && vis[a+1][b] == 0){
                            q.push({a+1,b});
                            vis[a+1][b] = 1;
                        }
                        else if(b+1 < m && board[a][b+1] == 'X' && vis[a][b+1] == 0){
                            q.push({a,b+1});
                            vis[a][b+1] = 1;
                        }
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
};