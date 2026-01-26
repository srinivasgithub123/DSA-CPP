class Solution {
public:

    int dfs(int row, int col, int n, int m, vector<vector<int>>& grid){
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0){
            return 0;
        }
        grid[row][col]=0;
        return 1+dfs(row-1, col, n, m, grid)+dfs(row, col+1, n, m, grid)+
        dfs(row+1, col, n, m, grid)+
        dfs(row, col-1, n, m, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result=0;
        int n= grid.size();
        int m= grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                result=max(result,dfs(i, j, n, m, grid));
                
            }
        }
    return result;    
    }
};