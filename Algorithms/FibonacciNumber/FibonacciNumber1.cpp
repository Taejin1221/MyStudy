// FibonacciNumber1.cpp
/* case 1: Fibonacci with Recursion*/
/* Time: O(2^n), Space: O(n) */
int Fibonacci( int n ) {
	if ( n < 3 )
		return 1;
	else
		return ( Fibonacci( n - 1 ) + Fibonacci( n - 2 ) );
}