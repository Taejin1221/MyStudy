// FibonacciNumber4.cpp
/* case 4: Fibonacci with Sliding Window */
/* Time: O(n), Space: O(1) */
int Fibonacci( int n ) {
	int fib0 = 0, fib1 = 1, fib2;

	for ( int i = 2; i <= n; i++ ) {
		fib2 = fib0 + fib1;
		fib0 = fib1;
		fib1 = fib2;
	}

	return fib2;
}