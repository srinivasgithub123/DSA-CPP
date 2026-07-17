class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven=0, sumodd=0;
        n=n*2;
        int i=1;
        while(n!=0){
            if(i%2==0){
                sumeven+=i;
            }else{
                sumodd+=i;
            }
        i++;
        n--;    
        }
        while(sumeven!=0){
            int rem= sumodd%sumeven;
            sumodd= sumeven;
            sumeven=rem;
        }  
    return sumodd;      
        
    }
};