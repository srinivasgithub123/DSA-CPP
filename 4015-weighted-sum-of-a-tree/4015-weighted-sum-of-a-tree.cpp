class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> tree(n);

        // Build tree
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        vector<int> depth(n);
        depth[0] = 1;

        int height = 0;

        while (!q.empty()) {
            int size = q.size();
            height++;

            while (size--) {
                int node = q.front();
                q.pop();

                for (int child : tree[node]) {
                    depth[child] = depth[node] + 1;
                    q.push(child);
                }
            }
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += 1LL * nums[i] * (height - depth[i] + 1);
        }

        return sum;
    }
};