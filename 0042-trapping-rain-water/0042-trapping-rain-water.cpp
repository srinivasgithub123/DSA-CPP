class Solution {
public:
    int trap(vector<int>& height) {
        // int ans=0, n=height.size();
        // vector<int> lmax(n, 0);
        // vector<int> rmax(n, 0);
        // lmax[0]=height[0];
        // rmax[n-1]=height[n-1];

        // for(int i=1; i<n; i++)
        // lmax[i]=max(lmax[i-1], height[i]);

        // for(int i=n-2; i>=0; i--)
        // rmax[i]= max(rmax[i+1], height[i]);

        // for(int i=0; i<n; i++){
        //     ans+=min(lmax[i], rmax[i])-height[i];
        // }
        
        // return ans;

        int total=0, n= height.size();
        int left= 0, right= n-1, lmax=0, rmax=0;

        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=lmax){
                    lmax= height[left];
                }else{
                    total+=lmax-height[left];
                }

                left++;
            }else{
                if(height[right]>=rmax){
                    rmax= height[right];
                }else{
                    total+=rmax-height[right];
                }

                right--;
            }
        }

    return total;    
        
    }
};