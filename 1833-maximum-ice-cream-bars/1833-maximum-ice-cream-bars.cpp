class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>count(100001, 0);

        for(int cost:costs){
            count[cost]++;
        }
    int ans=0;
    for (int i = 1; i < count.size(); i++) {
    if (count[i] > 0 && coins >= i) {
        int buy = min(count[i], coins / i);
        ans += buy;
        coins -= buy * i;
    }
}
    return ans;  
    }
};