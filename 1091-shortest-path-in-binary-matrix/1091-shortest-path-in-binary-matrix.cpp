// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
//             return -1;

//         vector<vector<int>> dist(n, vector<int>(m, 1e9));
//         priority_queue<
//             pair<int, pair<int,int>>,
//             vector<pair<int, pair<int,int>>>,
//             greater<pair<int, pair<int,int>>>
//         > pq;

//         pq.push({1, {0, 0}});
//         dist[0][0] = 1;

//         vector<int> dr = {-1,-1,-1, 0, 0, 1, 1, 1};
//         vector<int> dc = {-1, 0, 1,-1, 1,-1, 0, 1};

//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();

//             int sp = it.first;
//             int row = it.second.first;
//             int col = it.second.second;

//             if(row == n-1 && col == m-1)
//                 return sp;

//             for(int i = 0; i < 8; i++){
//                 int newr = row + dr[i];
//                 int newc = col + dc[i];

//                 if(newr >= 0 && newc >= 0 && newr < n && newc < m && grid[newr][newc] == 0){
//                     int nsp = sp + 1;
//                     if(nsp < dist[newr][newc]){
//                         dist[newr][newc] = nsp;
//                         pq.push({nsp, {newr, newc}});
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // blocked start or end
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1;   // distance = 1 (also marks visited)

        vector<int> dr = {-1,-1,-1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1,-1, 1,-1, 0, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int dist = grid[r][c];

            if (r == n-1 && c == n-1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = dist + 1;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};

