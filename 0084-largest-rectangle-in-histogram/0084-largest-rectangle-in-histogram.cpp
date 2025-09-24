class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n= h.size();
        vector<int> right(n, 0);//right smaller nearest
        vector<int> left(n, 0);//left smaller nearest
        stack<int> s;

        //right smaller nearest
        for(int i=n-1; i>=0; i--){
            while(s.size()>0 && h[s.top()]>=h[i])
            s.pop();

            if(s.empty()){
                right[i]= n;
            }
            else{
                right[i]= s.top();
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        //left smaller nearest
        for(int i=0; i<n; i++){
            while(s.size()>0 && h[s.top()]>=h[i])
            s.pop();

            if(s.empty()){
                left[i]= -1;
            }else{
                left[i]=s.top();
            }
            s.push(i);
        }

        int ans=0;
        for(int i=0; i<n; i++){
            int width= right[i]-left[i]-1;
            int currArea= h[i]*width;
            ans=max(ans, currArea);
        }
        return ans; 
    }
};