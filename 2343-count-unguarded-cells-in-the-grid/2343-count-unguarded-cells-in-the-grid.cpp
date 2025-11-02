    class Solution {
    public:

        void dfs(int r, int c, string dir, vector<vector<int>>& vis, map<pair<int, int>, int>& mp){
            int n = vis.size();
            int m = vis[0].size();

            if(r<0||c<0||r>=n||c>=m){
                return;
            }
            if(mp.find({r,c})!=mp.end()){
                return;
            }

            vis[r][c]=1;
            if(dir=="r"){
                dfs(r,c+1, "r", vis, mp);
            }
            else if(dir=="l"){
                dfs(r,c-1, "l", vis, mp);
            }
            else if(dir=="d"){
                dfs(r+1,c, "d", vis, mp);
            }
            else if(dir=="u"){
                dfs(r-1,c, "u", vis, mp);
            }
        }

        int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
            vector<vector<int>> vis(m, vector<int>(n));
            map<pair<int, int>, int>mp;

            //process for guards
            for(int i=0; i<guards.size(); i++){
                int r=guards[i][0];
                int c= guards[i][1];
                mp[{r,c}]++;
                vis[r][c]=1;
            }

            //process for walls
            for(int i=0; i<walls.size(); i++){
                int r= walls[i][0];
                int c= walls[i][1];
                mp[{r,c}]++;
                vis[r][c]=1;
            }

            //DFS for each guard
            for(int i=0; i<guards.size(); i++){
                int r= guards[i][0];
                int c= guards[i][1];

                dfs(r, c+1, "r", vis, mp);
                dfs(r, c-1, "l", vis, mp);
                dfs(r+1, c, "d", vis, mp);
                dfs(r-1, c, "u", vis, mp);
            }

            int cnt=0;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(vis[i][j]==0){
                        cnt++;
                    }
                }
            }

        return cnt; 
        }
    };