class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        vector<vector<vector<long long>>> dist(
            m,
            vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX))
        );

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        priority_queue<
            tuple<long long, int, int, int>,
            vector<tuple<long long, int, int, int>>,
            greater<tuple<long long, int, int, int>>
        > pq;

        // parity = 1 means next action is odd
        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        while (!pq.empty()) {

            auto [cost, row, col, parity] = pq.top();
            pq.pop();

            if (cost != dist[row][col][parity])
                continue;

            // Move transitions
            for (int dir = 0; dir < 4; dir++) {

                int nr = row + dr[dir];
                int nc = col + dc[dir];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                bool allowed = false;

                if (parity == 1) {
                    // Odd action -> Right or Down
                    allowed = (dir == 1 || dir == 2);
                } else {
                    // Even action -> Up or Left
                    allowed = (dir == 0 || dir == 3);
                }

                long long newCost = cost + 1LL * (nr + 1) * (nc + 1);

                if (!allowed)
                    newCost += penalty[row][col];

                int nextParity = !parity;

                if (newCost < dist[nr][nc][nextParity]) {
                    dist[nr][nc][nextParity] = newCost;
                    pq.push({newCost, nr, nc, nextParity});
                }
            }

            // Wait transition
            int nextParity = !parity;
            long long waitCost = cost + penalty[row][col];

            if (waitCost < dist[row][col][nextParity]) {
                dist[row][col][nextParity] = waitCost;
                pq.push({waitCost, row, col, nextParity});
            }
        }

        return min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
};