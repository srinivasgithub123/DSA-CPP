class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sw) {
        int c0=0, c1=0, n=sw.size();
        for(int i=0; i<students.size(); i++){
            if(students[i]==0)
            c0+=1;
            else
            c1+=1;
        }
        int i=0;
        for(int i=0; i<n; i++){
            if(sw[i]==0){
                if(c0==0)
                break;
                c0--;
            }else{
                if(c1==0)
                break;
                c1--;
            }
        }
        return c0+c1;
    }
};