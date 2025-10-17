// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sw) {
//         int c0=0, c1=0, n=sw.size();
//         for(int i=0; i<students.size(); i++){
//             if(students[i]==0)
//             c0+=1;
//             else
//             c1+=1;
//         }
//         int i=0;
//         for(int i=0; i<n; i++){
//             if(sw[i]==0){
//                 if(c0==0)
//                 break;
//                 c0--;
//             }else{
//                 if(c1==0)
//                 break;
//                 c1--;
//             }
//         }
//         return c0+c1;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sw) {
        queue<int> q;
        stack<int> s;
        
        // Push students into queue
        for(int stu : students) q.push(stu);
        // Push sandwiches into stack (top = 0th index)
        for(int i = sw.size() - 1; i >= 0; i--) s.push(sw[i]);

        int rotations = 0; // count consecutive students passing without eating

        while(!q.empty() && rotations < q.size()) {
            if(q.front() == s.top()) {
                q.pop();
                s.pop();
                rotations = 0; // reset rotations since someone ate
            } else {
                q.push(q.front());
                q.pop();
                rotations++;
            }
        }

        return q.size(); // students who could not eat
    }
};
