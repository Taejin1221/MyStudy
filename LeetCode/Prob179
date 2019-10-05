char* largestNumber(int nums[], int numsSize) {
	// Change numbers into strings
	int totalSize = 0;
	char** numsStrings = malloc(sizeof(char*) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		char* tempString = calloc(10, sizeof(char));
		sprintf(tempString, "%d", nums[i]);

		totalSize += strlen(tempString);
		numsStrings[i] = tempString;
	}
	char* rtrnString = calloc(totalSize + 1, sizeof(char));

	// Bubble Sort
	for (int i = numsSize - 1; i >= 0; i--) {
		for (int j = 0; j < i ; j++) {
			int front = j, back = j + 1;
			if (numsStrings[front][0] < numsStrings[back][0]) {
				char* temp = numsStrings[front];
				numsStrings[front] = numsStrings[back];
				numsStrings[back] = temp;
			}
			// if first digit is equal
			else if (numsStrings[front][0] == numsStrings[back][0]) {
				// if front num and back num are same then, continue
				if (! strcmp(numsStrings[front], numsStrings[back])) continue;

				int idx_front, idx_back;
				int digit_front = strlen(numsStrings[front]), digit_back = strlen(numsStrings[back]);
				// search non-duplicated nums
				for (idx_front = 1, idx_back = 1;
					numsStrings[front][idx_front] == numsStrings[back][idx_back];
					idx_front++, idx_back++);

				int swap = 0, run;
				// if both nums are not null
				if (numsStrings[front][idx_front] && numsStrings[back][idx_back]) {
					if (numsStrings[front][idx_front] < numsStrings[back][idx_back])
						swap = 1;
				} else if (digit_front < digit_back) {
					run = 1, swap = 0;
					while (run && idx_back < digit_back) {
						idx_front = 0;
						while (idx_front < digit_front) {
							if (numsStrings[front][idx_front] < numsStrings[back][idx_back]) {
								swap = 1, run = 0;
								break;
							} else if (numsStrings[front][idx_front] > numsStrings[back][idx_back]) {
								run = 0;
								break;
							}
							idx_front++;
						}
						idx_back++;
					}
				} else if (digit_front > digit_back) {
					run = 1; swap = 1;
					while (run && idx_front < digit_front) {
						idx_back = 0;
						while (idx_back < digit_back) {
							if (numsStrings[front][idx_front] > numsStrings[back][idx_back]) {
								swap = 0, run = 0;
								break;
							} else if (numsStrings[front][idx_front] < numsStrings[back][idx_back]) {
								swap = 1, run = 0;
								break;
							}
							idx_back++;
						}
						idx_front++;
					}
				}

				// if swap is 1 then, swap front and back
				if (swap) {
					char* temp = numsStrings[front];
					numsStrings[front] = numsStrings[back];
					numsStrings[back] = temp;
				}
			}
		}
	}

	// Delete duplicated zeroes(0)
	int start = 0;
	while ( (start + 1 < numsSize) && (numsStrings[start + 1][0] == '0') && (numsStrings[start][0] == '0') ) start++;

	// Concatenate sorted strings
	for ( ; start < numsSize; start++)
		strcat(rtrnString, numsStrings[start]);

	return rtrnString;
}

