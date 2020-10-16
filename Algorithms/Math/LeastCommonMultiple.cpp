// LeastCommonMultiple.cpp
int LCM( int a, int b ) {
	if ( a > b )
		return ( a * b / GCD( a, b ) );
	else
		return ( a * b / GCD( b, a ) );
}