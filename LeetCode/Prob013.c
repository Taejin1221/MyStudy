int romanToInt(char* s) {
	int idx = 0;
	int result = 0;

	while (s[idx] == 'M') {
		result += 1000; idx++;
	}

	if (s[idx] == 'C' && s[idx + 1] == 'M') {
		result += 900; idx += 2;
	}
	
	if (s[idx] == 'D') {
		result += 500; idx++;
	}

	if (s[idx] == 'C' && s[idx + 1] == 'D') {
		result += 400; idx += 2;
	}
	
	while (s[idx] == 'C') {
		result += 100; idx++;
	}

	if (s[idx] == 'X' && s[idx + 1] == 'C') {
		result += 90; idx += 2;
	}

	if (s[idx] == 'L') {
		result += 50; idx++;
	}

	if (s[idx] == 'X' && s[idx + 1] == 'L') {
		result += 40; idx += 2;
	}

	while (s[idx] == 'X') {
		result += 10; idx++;
	}

	if (s[idx] == 'I' && s[idx + 1] == 'X') {
		result += 9; idx += 2;
	}
	
	if (s[idx] == 'V') {
		result += 5; idx++;
	}

	if (s[idx] == 'I' && s[idx + 1] == 'V') {
		result += 4; idx += 2;
	}

	while (s[idx] == 'I') {
		result++; idx++;
	}

	return result;
}
