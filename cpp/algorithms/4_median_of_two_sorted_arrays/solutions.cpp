class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0.0;
        int m = nums1.size();
        int n = nums2.size();
        vector<int> A,B;
        if ( m <= n) {
            A = nums1;
            B = nums2;
        } else {
            A = nums2;
            B = nums1;
            int temp = m;
            m = n;
            n = temp;
        }
        int i, j, imin = 0, imax = m;
        while ( imin <= imax ) {
            i = (imin + imax) / 2;
            j = (m + n - 2*i + 1) / 2;
            // cout << i << " " << j << endl;
            if ( i < m && A[i] < B[j-1] ) {
                imin = i + 1;
            } else if ( i > 0 && B[j] < A[i-1] ){
                imax = i - 1;
            } else {
                int left_max, right_min;
                if ( i == 0 ) {
                    left_max = B[j-1];
                } else if ( j == 0 ) {
                    left_max = A[i-1];
                } else {
                    left_max = (A[i-1] > B[j-1] ? A[i-1] : B[j-1]);
                }

                if ( i == m ) {
                    right_min = B[j];
                } else if ( j == n ) {
                    right_min = A[i];
                } else {
                    right_min = (A[i] < B[j] ? A[i] : B[j]);
                }

                if ((m + n) % 2 == 0)
                    median = (double)(left_max + right_min) / 2;
                else
                    median = left_max;
                break;
            }
        }
        return median;
    }
};
