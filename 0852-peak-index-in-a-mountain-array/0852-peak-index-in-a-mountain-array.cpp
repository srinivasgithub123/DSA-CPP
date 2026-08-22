// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int n=arr.size();
//         int st=1,end=n-2,mid;
//         while(st<=end){
//             mid=st+(end-st)/2;
//             if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])
//             return mid;
//             if(arr[mid+1]<arr[mid-1])
//             end=mid-1;
//             else
//             st=mid+1;
//         }
//          return -1;
//     }
   
// };




















class Solution{
public:
    int peakIndexInMountainArray(vector<int>& arr){
        int left=0, right= arr.size()-1;
        while(left<right){
            int mid= left+(right-left)/2;

            if(arr[mid]<arr[mid+1]){
                left= mid+1;
            }else{
                right= mid;
            }
        }

    return left;    
    }
};