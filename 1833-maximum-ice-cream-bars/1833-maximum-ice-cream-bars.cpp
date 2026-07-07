// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         vector<int>count(100001, 0);

//         for(int cost:costs){
//             count[cost]++;
//         }
//     int ans=0;
//     for (int i = 1; i < count.size(); i++) {
//     if (count[i] > 0 && coins >= i) {
//         int buy = min(count[i], coins / i);
//         ans += buy;
//         coins -= buy * i;
//     }
// }
//     return ans;  
//     }
// };










class Solution{
public:
    int maxIceCream(vector<int>& costs, int coins){
        int ans=0;
        sort(costs.begin(), costs.end());
        if(costs[0]>coins){
            return 0;
        }
        for(int i=0; i<costs.size(); i++){
            if(coins>=costs[i]){
                ans++;
                coins=coins-costs[i];
            }
        }
        return ans;
    }

};