class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        health -= grid[0][0];
        if (health <= 0)
            return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;

        best[0][0] = health;
        q.push({{0, 0}, health});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int curHealth = q.front().second;
            q.pop();

            if (row == m - 1 && col == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newHealth = curHealth - grid[nr][nc];

                if (newHealth <= 0)
                    continue;

                if (best[nr][nc] >= newHealth)
                    continue;

                best[nr][nc] = newHealth;
                q.push({{nr, nc}, newHealth});
            }
        }

        return false;
    }
};