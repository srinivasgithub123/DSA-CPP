class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        int total= nb, empty= nb;
        while(empty>=ne){
            nb=empty/ne;
            total+=nb;
            empty=(empty%ne)+nb;
        }
        return total;
        
    }
};