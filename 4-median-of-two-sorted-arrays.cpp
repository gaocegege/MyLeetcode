#include <iostream>

using namespace std;

class Solution {
public:
	double findKthElement(int A[], int m, int B[], int n, int k) {
        int i = (int)((double)m / (m+n) * (k-1));
        int j = (k-1) - i;
        // invariant: i + j = k-1
        // Note: A[-1] = -INF and A[m] = +INF to maintain invariant
        int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
        int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
        int Ai   = ((i == m) ? INT_MAX : A[i]);
        int Bj   = ((j == n) ? INT_MAX : B[j]);

        if (Bj_1 <= Ai && Ai <= Bj)
            return Ai;
        else if (Ai_1 <= Bj && Bj <= Ai)
            return Bj;

        // if none of the cases above, then it is either:
        if (Ai < Bj)
        // exclude Ai and below portion
        // exclude Bj and above portion
            return findKthElement(A+i+1, m-i-1, B, j, k-i-1);
        else /* Bj < Ai */
        // exclude Ai and above portion
        // exclude Bj and below portion
            return findKthElement(A, i, B+j+1, n-j-1, k-j-1);
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	int k = (m + n + 1) / 2;
        if ((m + n) % 2 == 1)
            return findKthElement(A, m, B, n, k);
        else
        {
            return ((double) findKthElement(A, m, B, n, k) + (double) findKthElement(A, m, B, n, k + 1)) / 2.0;
        }
    }

};

int main()
{
    int *A = new int[1];
    int *B = new int[1];
    A[0] = B[0] = A[1] = B[1] = 1;

    Solution s;
    double result = s.findMedianSortedArrays(A, 2, B, 2);
    cout << result << endl;
}