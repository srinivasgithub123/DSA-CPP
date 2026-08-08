class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; i<=100; i++){
            int prod=1;
            int num=i;
            while(num!=0){
            int digit= num%10;
            num=num/10;
            prod= prod*digit;
            }

            if(prod%t==0){
                return i;
            }
        }
    
        return 0;
    }
};