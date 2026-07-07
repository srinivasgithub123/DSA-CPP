// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         arr[0]=1;
//         for(int i=1; i<arr.size(); i++){
//             if(abs(arr[i]-arr[i-1])>1){
//                 arr[i]= arr[i-1]+1;
//             }
//         }
//         int ans = *max_element(arr.begin(), arr.end());
//         return ans;
//     }
// };










class Solution{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr){
        sort(arr.begin(), arr.end());
        arr[0]=1;
            for(int i=1; i<arr.size(); i++){
                if(abs(arr[i]-arr[i-1])>1){
                    arr[i]=arr[i-1]+1;
                }
            }
        int max_elem= INT_MIN;
        for(int i=0; i<arr.size(); i++){
            max_elem= max(max_elem, arr[i]);
        }

        return max_elem;
    }
};