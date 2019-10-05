int thirdMax(int* nums, int numsSize) {
	int max1Idx, max2Idx;

	int maxIdx = 0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[maxIdx] < nums[i])
			maxIdx = i;
	}
	max1Idx = maxIdx;


	maxIdx = 0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[maxIdx] == nums[max1Idx]) {
			maxIdx++; continue;
		}
		if (nums[i] == nums[max1Idx]) continue;
		if (nums[maxIdx] < nums[i])
			maxIdx = i;
	}
	max2Idx = maxIdx;

	maxIdx = 0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[maxIdx] == nums[max1Idx] || nums[maxIdx] == nums[max2Idx]) {
			maxIdx++; continue;
		}		
		if (nums[i] == nums[max1Idx] || nums[i] == nums[max2Idx]) continue;
		if (nums[maxIdx] < nums[i])
			maxIdx = i;
	}

	if (nums[max1Idx] == nums[maxIdx] || nums[max2Idx] == nums[maxIdx])
		return nums[max1Idx];

	return nums[maxIdx];
}
