// FibonacciNumber5.cpp
/* case 5: Fibonacci with Matrix Exponential*/
/* Time: O(log n), Space: O(log n) */
#define MOD 1'000'000'007

typedef long long ll;

ll* MatrixExponential( ll n ) {
	if ( n == 1 ) {
		return ( new ll[4]{ 1, 1, 1, 0 } );
	} else if ( n == 2 ) {
		return ( new ll[4]{ 2, 1, 1, 1 } );
	} else if ( n % 2 ) {
		ll* matrix = MatrixExponential( n / 2 );

		ll temp[4];
		temp[0] = matrix[0] * matrix[0] + matrix[1] * matrix[2];
		temp[1] = matrix[0] * matrix[1] + matrix[1] * matrix[3];
		temp[2] = matrix[2] * matrix[0] + matrix[3] * matrix[2];
		temp[3] = matrix[2] * matrix[1] + matrix[3] * matrix[3];
		for ( int i = 0; i < 4; i++ )
			temp[i] %= (ll)MOD;

		delete[] matrix;

		ll* expMat = new ll[4];
		expMat[0] = temp[0] + temp[1];
		expMat[1] = temp[0];
		expMat[2] = temp[2] + temp[3];
		expMat[3] = temp[2];

		for ( int i = 0; i < 4; i++ )
			expMat[i] %= (ll)MOD;

		return expMat;
	} else {
		ll* matrix = MatrixExponential( n / 2 );

		ll* expMat = new ll[4];
		expMat[0] = matrix[0] * matrix[0] + matrix[1] * matrix[2];
		expMat[1] = matrix[0] * matrix[1] + matrix[1] * matrix[3];
		expMat[2] = matrix[2] * matrix[0] + matrix[3] * matrix[2];
		expMat[3] = matrix[2] * matrix[1] + matrix[3] * matrix[3];

		delete[] matrix;

		for ( int i = 0; i < 4; i++ )
			expMat[i] %= (ll)MOD;

		return expMat;
	}
}

int Fibonacci( ll n ) {
	if ( n < 3 )
		return 1;
	else {
		ll* matrix = MatrixExponential( n - 1 );
		int ans = matrix[0];
		delete[] matrix;

		return ans;
	}
}