// FibonacciNumber2.cpp
/* case 2: Fibonacci with Memoization */
/* Time: O(n), Space: O(n) */
int fib[100] = { 0, 1, 1, };
int Fibonacci( int n ) {
	if ( n == 0 || fib[n] )
		return fib[n];
	else {
		fib[n] = Fibonacci( n - 1 ) + Fibonacci( n - 2 );

		return fib[n];
	}
}