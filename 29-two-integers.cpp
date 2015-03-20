class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)
			return 0;
		if (dividend < divisor)
			return 0;

		int res = 0;
		int absDividend = abs(dividend);
		int absDivisor = abs(divisor);
		bool flagDividend = dividend & 0x80000000;
		bool flagDivisor = divisor & 0x80000000;
		while (absDividend > absDivisor)
		{
			absDividend = absDividend - absDivisor;
			res++;
		}
		return res & ((flagDivisor | flagDividend) << 31);
	}
};