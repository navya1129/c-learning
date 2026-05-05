class Solution {
public:
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>> &q,int n,int m, vector<vector<int>> &mat1){
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int a = p.first;
            int b = p.second;

            if(b - 1 >= 0 && heights[a][b-1] >= heights[a][b] && mat1[a][b-1] == 0){
                mat1[a][b-1] = 1;
                q.push({a,b-1});
            }
            if(a - 1 >= 0 && heights[a-1][b] >= heights[a][b] && mat1[a-1][b] == 0){
                mat1[a-1][b] = 1;
                q.push({a-1,b});
            }
            if(a + 1 < n && heights[a+1][b] >= heights[a][b] && mat1[a+1][b] == 0){
                mat1[a+1][b] = 1;
                q.push({a+1,b});
            }
            if(b + 1 < m && heights[a][b+1] >= heights[a][b] && mat1[a][b+1] == 0){
                mat1[a][b+1] = 1;
                q.push({a,b+1});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> que1;
        queue<pair<int,int>> que2;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> mat1(n, vector<int>(m, 0));
        vector<vector<int>> mat2(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            que1.push({i,0});
            mat1[i][0] = 1;
            que2.push({i,m-1});
            mat2[i][m-1] = 1;
        }
        for(int i = 0;i < m;i++){
            que1.push({0,i});
            mat1[0][i] = 1;
            que2.push({n-1,i});
            mat2[n-1][i] = 1;
        }
        bfs(heights,que1,n,m,mat1);
        bfs(heights,que2,n,m,mat2);
        vector<vector<int>> ans;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat1[i][j] == mat2[i][j] && mat1[i][j] == 1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};