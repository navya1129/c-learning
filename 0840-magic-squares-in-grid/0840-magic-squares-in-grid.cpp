class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 1;i < n-1;i++){
            for(int j = 1;j < m-1;j++){
                if(grid[i][j] == 5){
                    int flag = 0;
                    map<int,int> mp;
                    if((i-1 >= 0 && i+1 < n && grid[i-1][j] + grid[i+1][j] == 10)){
                        flag++;
                        mp[grid[i-1][j]]++;
                        mp[grid[i+1][j]]++;
                    }
                    if((j-1 >= 0 && j+1 < m && grid[i][j-1] + grid[i][j+1] == 10)){
                        flag++;
                        mp[grid[i][j-1]]++;
                        mp[grid[i][j+1]]++;
                    }
                    if((i-1 >= 0 && j-1 >= 0 && i+1 < n && j+1 < m && grid[i-1][j-1] + grid[i+1][j+1] == 10)){
                        flag++;
                        mp[grid[i-1][j-1]]++;
                        mp[grid[i+1][j+1]]++;
                    }
                    if((i+1 < n && j-1 >= 0 && i-1 >= 0 && j+1 < m && grid[i-1][j+1] + grid[i+1][j-1] == 10)){
                        flag++;
                        mp[grid[i-1][j+1]]++;
                        mp[grid[i+1][j-1]]++;
                    }
                    if((i-1 >= 0 && j-1 >= 0 && j+1 < m && grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] == 15)){
                        flag++;
                    }
                    if((i-1 >= 0 && i+1 < n && j+1 <m && grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1] == 15)){
                        flag++;
                    }
                    if(flag == 6 && mp.size() == 8) cnt++;
                }
                
            }
        }
        return cnt;
    }
};