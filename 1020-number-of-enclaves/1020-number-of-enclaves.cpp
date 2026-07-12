class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;

        //traverse the first row and last row
        for(int j=0; j<m; j++){
            if(grid[0][j]==1 && !vis[0][j]){
                q.push({0, j});
                vis[0][j]=1;
            }

            if(grid[n-1][j]==1 && !vis[n-1][j]){
                q.push({n-1, j});
                vis[n-1][j]=1;
            }
        }

        //traverse the first coloumn and last coloumn
        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && !vis[i][0]){
                q.push({i, 0});
                vis[i][0]=1;
            }

            if(grid[i][m-1]==1 && !vis[i][m-1]){
                q.push({i, m-1});
                vis[i][m-1]=1;
            }
        }

        int dr[]={-1, 0, 1, 0};
        int dc[]= {0,1,0,-1};

        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nr= row+dr[i];
                int nc= col+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    q.push({nr, nc});
                    vis[nr][nc]=1;
                }
            }


        }

        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
    return count;    
    }
};