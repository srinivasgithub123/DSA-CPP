class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int totalKeys = 0;
        int srow = 0, scol = 0;

        // Find start position and count keys
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    totalKeys++;

                if (grid[i][j] == '@') {
                    srow = i;
                    scol = j;
                }
            }
        }

        int finalMask = (1 << totalKeys) - 1;

        int n = grid.size();       // rows
        int m = grid[0].size();    // columns

        // visited[row][col][mask]
        vector<vector<vector<bool>>> visited(
            n,
            vector<vector<bool>>(m, vector<bool>(1 << totalKeys, false))
        );

        queue<tuple<int, int, int>> q;
        q.push({srow, scol, 0});
        visited[srow][scol][0] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [row, col, mask] = q.front();
                q.pop();

                if (mask == finalMask)
                    return steps;

                for (int i = 0; i < 4; i++) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    char cell = grid[nr][nc];

                    if (cell == '#')
                        continue;

                    int newMask = mask;

                    // Pick up a key
                    if (cell >= 'a' && cell <= 'f') {
                        int key = cell - 'a';
                        newMask |= (1 << key);
                    }

                    // Check if door can be opened
                    if (cell >= 'A' && cell <= 'F') {
                        int key = cell - 'A';
                        if ((mask & (1 << key)) == 0)
                            continue;
                    }

                    if (!visited[nr][nc][newMask]) {
                        visited[nr][nc][newMask] = true;
                        q.push({nr, nc, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};