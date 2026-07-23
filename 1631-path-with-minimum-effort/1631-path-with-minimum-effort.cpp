// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {

//         //{dist, {row, col}}
//         priority_queue<
//         pair<int, pair<int,int>>,
//         vector<pair<int, pair<int,int>>>,
//         greater<pair<int, pair<int,int>>>> pq;
//         int n= heights.size();
//         int m= heights[0].size();

//         vector<vector<int>>dist(n, vector<int>(m, 1e9));
//         dist[0][0]=0;
//         pq.push({0,{0,0}});
//         int dr[]={-1, 0, 1, 0};
//         int dc[]={0,1,0,-1};
//         while(!pq.empty()){
//             auto it= pq.top();
//             pq.pop();

//             int diff= it.first;
//             int row= it.second.first;
//             int col= it.second.second;

//             if(row==n-1 && col==m-1){
//                 return diff;
//             }
//             //row-1,col
//             //row, col+1
//             //row+1, col
//             //row, col-1
//             for(int i=0; i<4; i++){
//                 int newr= row+dr[i];
//                 int newc= col+dc[i];
//                 if(newr>=0 && newc>=0 && newr<n && newc<m){
//                     int neweffort= max(abs(heights[row][col]-heights[newr][newc]), diff);
//                     if(neweffort< dist[newr][newc]){
//                         dist[newr][newc]= neweffort;
//                         pq.push({neweffort, {newr, newc}});
//                     }
//                 }
//             }
//         }
//     return 0;
//     }
// };



// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int n= heights.size();
//         int m= heights[0].size();
//         vector<vector<int>>dist(n, vector<int>(m, 1e9));
//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
//         pq.push({0,{0,0}});
//         dist[0][0]=0;
//         vector<int>dr={-1, 0, 1, 0};
//         vector<int>dc= {0, -1, 0, 1};

//         while(!pq.empty()){
//             int ht= pq.top().first;
//             int row= pq.top().second.first;
//             int col= pq.top().second.second;
//             pq.pop();

//             if(row==n-1 && col==m-1){
//                 return ht;
//             }

//             for(int i=0; i<4; i++){
//                 int newr= row+dr[i];
//                 int newc= col+dc[i];
//                 if(newr>=0 && newc>=0&& newr<n && newc<m){
//                 int diff=max(ht, abs(heights[row][col]- heights[newr][newc]));
//                 if(diff < dist[newr][newc]){
//                     dist[newr][newc]= diff;
//                     pq.push({diff, {newr, newc}});
//                 }
//             }
//             }
//         }

//         return 0;
//     }};













class Solution{
public:
    int minimumEffortPath(vector<vector<int>>& heights){
        int n= heights.size(), m= heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        dist[0][0]=0;
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,0}});
        int dr[]={-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        while(!pq.empty()){
            int dis= pq.top().first;
            int row= pq.top().second.first;
            int col= pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1){
                return dis;
            }

            for(int i=0; i<4; i++){
                int nr= row+dr[i];
                int nc= col+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int neweffort= max(abs(heights[nr][nc]-heights[row][col]), dis);
                    if(neweffort<dist[nr][nc]){
                        dist[nr][nc]= neweffort;
                        pq.push({neweffort, {nr, nc}});
                    }
                }
            }
        }
    return 0;       
    }
};



