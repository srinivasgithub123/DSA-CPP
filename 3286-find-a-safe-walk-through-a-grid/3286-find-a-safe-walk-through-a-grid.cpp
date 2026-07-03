class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        queue<pair<pair<int, int>, int>> q;

        int m = grid.size(), n = grid[0].size();

        // Stores the maximum remaining health at each cell
        vector<vector<int>> best(m, vector<int>(n, -1));

        if (grid[0][0] == 1)
            health--;

        if (health <= 0)
            return false;

        q.push({{0, 0}, health});
        best[0][0] = health;

        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int thealth = q.front().second;
            q.pop();

            if (row == m - 1 && col == n - 1)
                return true;

            // Up
            if (row - 1 >= 0) {
                int newHealth = thealth - grid[row - 1][col];

                if (newHealth > 0 && newHealth > best[row - 1][col]) {
                    best[row - 1][col] = newHealth;
                    q.push({{row - 1, col}, newHealth});
                }
            }

            // Right
            if (col + 1 < n) {
                int newHealth = thealth - grid[row][col + 1];

                if (newHealth > 0 && newHealth > best[row][col + 1]) {
                    best[row][col + 1] = newHealth;
                    q.push({{row, col + 1}, newHealth});
                }
            }

            // Down
            if (row + 1 < m) {
                int newHealth = thealth - grid[row + 1][col];

                if (newHealth > 0 && newHealth > best[row + 1][col]) {
                    best[row + 1][col] = newHealth;
                    q.push({{row + 1, col}, newHealth});
                }
            }

            // Left
            if (col - 1 >= 0) {
                int newHealth = thealth - grid[row][col - 1];

                if (newHealth > 0 && newHealth > best[row][col - 1]) {
                    best[row][col - 1] = newHealth;
                    q.push({{row, col - 1}, newHealth});
                }
            }
        }

        return false;
    }
};