// GreatestCommonDivisior.cpp
int GCD( int a, int b ) {
	return ( b ? GCD( b, a % b ) : a );
}
