// GreatestCommonDivisior.cpp
int GCD( int a, int b ) {
	return ( ( a % b ) ? GCD( a, b ) : b );
}