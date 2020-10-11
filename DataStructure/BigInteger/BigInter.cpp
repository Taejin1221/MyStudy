// BigInterget.cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInteger {
public:
	vector<int> digits;

	BigInteger() {}
	BigInteger(string& s1) {
		for ( int i = s1.size() - 1; i >= 0; i-- )
			digits.push_back( s1[i] - '0' );
	}

	BigInteger operator+( BigInteger& b2 ) {
		vector<int>& a = digits;
		vector<int>& b = b2.digits;
		BigInteger result;
		vector<int>& c = result.digits;

		int bound = min( a.size(), b.size() );
		int idx, carry = 0;
		for ( idx = 0; idx < bound; idx++ ) {
			int value = a[idx] + b[idx] + carry;
			c.push_back( value % 10 );
			carry = value / 10;
		}

		for ( ; idx < a.size(); idx++ ) {
			int value = a[idx] + carry;
			c.push_back( value % 10 );
			carry = value / 10;
		}

		for ( ; idx < b.size(); idx++ ) {
			int value = b[idx] + carry;
			c.push_back( value % 10 );
			carry = value / 10;
		}

		if ( carry )
			c.push_back( carry );

		return result;
	}

	void PrintValue() {
		for ( int i = digits.size() - 1; i >= 0; i-- )
			cout << digits[i];
		cout << '\n';
	}
};