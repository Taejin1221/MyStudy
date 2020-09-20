// FibonacciNumber3.cpp
/* case 3: Fibonacci with Dynamic Programming */
/* Time: O(n), Space O(n) */
int Fibonacci( int n ) {
	int* dp = new int[n + 1];

	dp[0] = 0, dp[1] = 1;
	for ( int i = 2; i <= n; i++ )
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}