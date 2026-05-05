class Solution {
public:
    void fun(queue<pair<int,int>> &q,vector<vector<char>> &copy,vector<vector<char>> &board,vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size(); 
                                                        
        while(!q.empty()){
                    auto [a,b] = q.front();
                    q.pop();
                      
                    if(a+1 < n && board[a+1][b] == 'O' && vis[a+1][b] == 0){
                        vis[a+1][b] = 1;
                        copy[a+1][b] = 'O';
                        q.push({a+1,b});
                    }
                    
                    if(a-1 >= 0 && board[a-1][b] == 'O' && vis[a-1][b] == 0){
                        vis[a-1][b] = 1;
                        copy[a-1][b] = 'O';
                        q.push({a-1,b});
                    }
                    
                    if(b+1 < m && board[a][b+1] == 'O' && vis[a][b+1] == 0){
                        vis[a][b+1] = 1;
                        copy[a][b+1] = 'O';
                        q.push({a,b+1});
                    }
                    
                    if(b-1 >= 0 && board[a][b-1] == 'O' && vis[a][b-1] == 0){
                        vis[a][b-1] = 1;
                        copy[a][b-1] = 'O';
                        q.push({a,b-1});
                    }
                }
    }
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> copy(n,vector<char>(m,'X'));
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i = 0;i < n;i++){
            if(board[i][0] == 'O' && vis[i][0] == 0){
                copy[i][0] = 'O';
                q.push({i,0});
                fun(q,copy,board,vis);
            }
        }
        for(int i = 0;i < m;i++){
            if(board[0][i] == 'O' && vis[0][i] == 0){
                copy[0][i] = 'O';
                q.push({0,i});
                fun(q,copy,board,vis);
            }
        }
        for(int i = 0;i < n;i++){
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0){
                copy[i][m-1] = 'O';
                q.push({i,m-1});
                fun(q,copy,board,vis);
            }
        }
        for(int i =0 ;i < m;i++){
            if(board[n-1][i] == 'O' && vis[n-1][i] == 0){
                copy[n-1][i] = 'O';
                q.push({n-1,i});
                fun(q,copy,board,vis);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                board[i][j] = copy[i][j];
            }
        }
    }
};