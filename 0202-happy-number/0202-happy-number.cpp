class Solution {
public:

    int next(int num){
        int sum=0;
        while(num>0){
            int digit= num% 10;
            sum=sum+digit*digit;
            num=num/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow= next(n);
        int fast= next(next(n));

        while(slow!=fast){
            if(fast==1)
            return true;

            slow= next(slow);
            fast= next(next(fast));
        }

    return slow==1;    
    }
};