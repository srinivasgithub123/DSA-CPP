class Solution {
public:
    int smallestNumber(int n) {
        int num;
        for(int i=1; i<=n; i++){
            num= pow(2,i);
            if(num>n)
            break;
        }
        return  num-1;
    }
};