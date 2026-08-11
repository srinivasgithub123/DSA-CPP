// class Solution {
// public:
//     int mySqrt(int x) {
//         long long mid, l=0, r=x/2+1, ans;
//         while(l<=r){
//             mid=(l+r)/2;
//             if(mid*mid==x)
//             return mid;
//             else if((mid*mid)>x)
//             r=mid-1;
//             else{
//                 ans=mid;
//                 l=mid+1;
//             }
//         }
//         return ans;
        
//     }
// };














class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        int left = 0, right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (1LL * mid * mid > x) {
                right = mid - 1;
            } 
            else {
                ans = mid;
                left = mid + 1;
            }
        }

        return ans;
    }
};