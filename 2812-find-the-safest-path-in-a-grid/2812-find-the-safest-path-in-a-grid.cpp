class Solution {
public:

    bool canReach(int k, int n, vector<vector<int>> &dist){
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        visited[0][0]= true;
        if(dist[0][0]<k){
            return false;
        }
        queue<pair<int, int>>reach;
        reach.push({0,0});
        while(!reach.empty()){
            int row= reach.front().first;
            int col= reach.front().second;
            reach.pop();
            if (row+1<n && visited[row+1][col]==false && dist[row+1][col]>=k){
                visited[row+1][col]=true;
                reach.push({row+1, col});
            }
            if(col+1<n && visited[row][col+1]==false && dist[row][col+1]>=k){
                visited[row][col+1]=true;
                reach.push({row, col+1});

            }
            if(row-1>=0 && visited[row-1][col]==false && dist[row-1][col]>=k){
                visited[row-1][col]=true;
                reach.push({row-1, col});
            }
            if(col-1>=0 && visited[row][col-1]==false && dist[row][col-1]>=k){
                visited[row][col-1]= true;
                reach.push({row, col-1});
            }
        }
    return visited[n-1][n-1];
        
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row - 1 >= 0 && dist[row - 1][col] == 1e9) {
                dist[row - 1][col] = dist[row][col] + 1;
                q.push({row - 1, col});
            }

            if (col + 1 < n && dist[row][col + 1] == 1e9) {
                dist[row][col + 1] = dist[row][col] + 1;
                q.push({row, col + 1});
            }

            if (row + 1 < n && dist[row + 1][col] == 1e9) {
                dist[row + 1][col] = dist[row][col] + 1;
                q.push({row + 1, col});
            }

            if (col - 1 >= 0 && dist[row][col - 1] == 1e9) {
                dist[row][col - 1] = dist[row][col] + 1;
                q.push({row, col - 1});
            }
        }

        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                high = max(high, dist[i][j]);
            }
        }

        int low = 0;
int ans = 0;

while (low <= high) {
    int mid = low + (high - low) / 2;

    if (canReach(mid, n, dist)) {
        ans = mid;
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}

return ans;
    }
};