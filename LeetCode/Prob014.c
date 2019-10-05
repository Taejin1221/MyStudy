char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0)
		return "";

	int len = strlen(strs[0]);
	char* returnStr = calloc(len + 1, sizeof(char));

	int idx = 0, returnIdx = 0;
	bool run = true;

	while (run && strs[0][idx]) {
		for (int i = 1; i < strsSize; i++) {
			if (strs[0][idx] != strs[i][idx]) {
				run = false;
				break;
			}
		}
		if (run)
			returnStr[returnIdx++] = strs[0][idx++];
	}

	return returnStr;
}
