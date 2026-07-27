class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // If k is large enough, we can go straight to the destination.
        if (k >= n + m - 2)
            return n + m - 2;

        vector<vector<vector<bool>>> visited(
            n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));

        queue<pair<pair<int, int>, pair<int, int>>> q;
        // {{row, col}, {steps, obstaclesLeft}}

        q.push({{0, 0}, {0, k}});
        visited[0][0][k] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int row = cur.first.first;
            int col = cur.first.second;
            int steps = cur.second.first;
            int obstaclesLeft = cur.second.second;

            if (row == n - 1 && col == m - 1)
                return steps;

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // Empty cell
                if (grid[nr][nc] == 0 &&
                    !visited[nr][nc][obstaclesLeft]) {

                    visited[nr][nc][obstaclesLeft] = true;
                    q.push({{nr, nc}, {steps + 1, obstaclesLeft}});
                }

                // Obstacle
                else if (grid[nr][nc] == 1 &&
                         obstaclesLeft > 0 &&
                         !visited[nr][nc][obstaclesLeft - 1]) {

                    visited[nr][nc][obstaclesLeft - 1] = true;
                    q.push({{nr, nc}, {steps + 1, obstaclesLeft - 1}});
                }
            }
        }

        return -1;
    }
};