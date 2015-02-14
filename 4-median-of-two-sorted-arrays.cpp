#include <iostream>

using namespace std;

class Solution {
public:
	double findKthElement(int A[], int startA, int endA, int B[], int startB, int endB, int k) {
        if (endB < startB)
            return A[startA + k - 1];
        if (endA < startA)
            return B[startB + k - 1];
		int middleA = (startA + endA) / 2;
        int middleB = (startB + endB) / 2;

        if (middleB - startB + middleA - startA + 2 > k)
        {
            if (A[middleA] > B[middleB])
            {
                return findKthElement(A, startA, middleA - 1, B, startB, endB, k);
            }
            else
            {
                return findKthElement(A, startA, endA, B, startB, middleB - 1, k);
            }
        }
        else
        {
            if (A[middleA] > B[middleB])
            {
                return findKthElement(A, startA, endA, B, middleB + 1, endB, k - (middleB - startB + 1));
            }
            else
            {
                return findKthElement(A, middleA + 1, endA, B, startB, endB, k - (middleA - startA + 1));
            }
        }
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	int k = (m + n + 1) / 2;
        if ((m + n) % 2 == 1)
            return findKthElement(A, 0, m - 1,B,0,n - 1, k);
        else
        {
            // cout << findKthElement(A, 0, m-1, B, 0, n - 1, k + 1) << endl;
            return ((double) findKthElement(A, 0, m-1, B, 0, n - 1, k) + (double) findKthElement(A, 0, m - 1, B, 0, n - 1, k + 1)) / 2.0;
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