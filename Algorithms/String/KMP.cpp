/*
 * File Name: KMP.cpp
 * Author: Taejin, An
 * Date: 01/03/2021
 * Description: C++ code of Knuth-Morris-Pratt Algorithm
*/

vector<int> KMP( string text, string pattern ) {
	int textSize = text.size(), patternSize = pattern.size();

	vector<int> fail ( patternSize );
	for ( int i = 1, j = 0; i < patternSize; i++ ) {
		while ( j > 0 && pattern[i] != pattern[j] )
			j = fail[j - 1];

		if ( pattern[i] == pattern[j] )
			fail[i] = ++j;
	}

	vector<int> indexes;
	for ( int i = 0; j = 0; i < textSize; i++ ) {
		while ( j > 0 && text[i] != pattern[j] )
			j = fail[j - 1];

		if ( text[i] == pattern[j] ) {
			j++;
			if ( j == patternSize ) {
				indexes.push_back( i - patternSize + 1 );
				j = fail[j - 1];
			}	
		}
	}

	return indexes;
}
