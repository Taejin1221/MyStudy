# MergeSort.py
def MergeSort( arr, left, right ):
	if left >= right: return
	else:
		mid = ( left + right ) // 2
		MergeSort( arr, left, mid )
		MergeSort( arr, mid + 1, right )
		Merge( arr, left, mid, right )

def Merge( arr, left, mid, right ):
	leftCopy = arr[ left : mid + 1 ]
	rightCopy = arr[ mid + 1 : right + 1 ]

	lenLeft, lenRight = len( leftCopy ), len( rightCopy )
	idxLeft, idxRight, idxOrigin = 0, 0, left

	while ( ( idxLeft < lenLeft ) and ( idxRight < lenRight ) ):
		leftVal, rightVal = leftCopy[idxLeft], rightCopy[idxRight]

		if leftVal < rightVal:
			arr[idxOrigin] = leftVal
			idxLeft += 1
		else:
			arr[idxOrigin] = rightVal
			idxRight += 1

		idxOrigin += 1

	while ( idxLeft < lenLeft ):
		arr[idxOrigin] = leftCopy[idxLeft]
		idxOrigin += 1; idxLeft += 1

	while ( idxRight < lenRight ):
		arr[idxOrigin] = rightCopy[idxRight]
		idxOrigin += 1; idxRight += 1
