class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();

        int half = (n + m + 1) / 2;

        int left = 0;
        int right = n;

        while (left <= right) {

            int partitionA = left + (right - left) / 2;
            int partitionB = half - partitionA;

            int A_left = (partitionA == 0)
                       ? INT_MIN
                       : nums1[partitionA - 1];

            int A_right = (partitionA == n)
                        ? INT_MAX
                        : nums1[partitionA];

            int B_left = (partitionB == 0)
                       ? INT_MIN
                       : nums2[partitionB - 1];

            int B_right = (partitionB == m)
                        ? INT_MAX
                        : nums2[partitionB];

            if (A_left <= B_right && B_left <= A_right) {

                if ((n + m) % 2 == 1) {
                    return max(A_left, B_left);
                }

                return (max(A_left, B_left) +
                        min(A_right, B_right)) / 2.0;
            }

            else if (A_left > B_right) {
                right = partitionA - 1;
            }

            else {
                left = partitionA + 1;
            }
        }

        return 0.0;
    }
};