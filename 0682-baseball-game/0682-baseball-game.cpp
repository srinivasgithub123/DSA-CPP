class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for(int i=0; i<op.size(); i++){
            if(op[i]=="C" && st.size()>0){
                st.pop();
            }else if(op[i]=="D" && st.size()>0){
                st.push(st.top()*2);
            }else if(op[i]=="+" && st.size()>1){
                int s1=st.top();
                st.pop();
                int s2=st.top();
                st.push(s1);
                st.push(s1+s2);
            }else{
            st.push(stoi(op[i]));
            }
        }
        int sum=0;
        while(st.size()!=0){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};