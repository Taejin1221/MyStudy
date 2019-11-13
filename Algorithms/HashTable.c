/* HashTable.c */
#include <stdio.h>

int HashFunction_Linear(int value, int i, int size) {
	return ((value % size) + i) % size;
}

int HashFunction_Quadratic(int value, int i, int size) {
	return (value + i * i) % size;
}

int HashFunction_Double(int value, int i, int size, int size2, int num, char ope) {
	switch (ope) {
		case '+':
			return ((value % size) + i * (num + value % size2)) % size ;
		case '-':
			return ((value % size) + i * (num - value % size2)) % size ;
	}
}

void PushTable(int hashTable[], int size, int value, int (*HashFunction)(int, int, int)) {
	int idx, i = 0;
	do {
		idx = HashFunction(value, i++, size);
	 } while (hashTable[idx] != 0);
	 hashTable[idx] = value;
}

void PushTable_Double(int hashTable[], int size, int size2, int num, int value, char ope, int (*HashFunction)(int, int, int, int, int, char)) {
	int idx, i = 0;
	do {
		idx = HashFunction(value, i++, size, size2, num, ope);
	 } while (hashTable[idx] != 0);
	 hashTable[idx] = value;
}

void PrintTable(int hashTable[], int size) {
	for (int i = 0; i < size; i++)
		printf("[%d: %d] ", i, hashTable[i]);
	printf("end\n");
}

void InitTable(int hashTable[], int size) {
	for (int i = 0; i < size; i++)
		hashTable[i] = 0;
}

int main(void) {
	int elements[] = { 10, 20, 30, 40, 33, 46, 50, 60 };
	int elementsSize = sizeof(elements) / sizeof(int);
	int hashTable[13] = { 0, };
	int hashSize = 13, secondSize = 11, num = 1;

	for (int i = 0; i < elementsSize; i++)
		PushTable(hashTable, hashSize, elements[i], HashFunction_Linear);
	PrintTable(hashTable, hashSize); InitTable(hashTable, hashSize);

	for (int i = 0; i < elementsSize; i++)
		PushTable(hashTable, hashSize, elements[i], HashFunction_Quadratic);
	PrintTable(hashTable, hashSize); InitTable(hashTable, hashSize);

	for (int i = 0; i < elementsSize; i++)
		PushTable_Double(hashTable, hashSize, secondSize, num, elements[i], '+', HashFunction_Double);
	PrintTable(hashTable, hashSize); InitTable(hashTable, hashSize);

	////////////////////////////////////////////////////////////////////////////
	int elements2[] = { 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5 };
	int elementsSize2 = sizeof(elements2) / sizeof(int);
	int hashTable2[11] = { 0, };
	int hashSize2 = 11, secondSize2 = 7, num2 = 7;

	for (int i = 0; i < elementsSize2; i++)
		PushTable(hashTable2, hashSize2, elements2[i], HashFunction_Linear);
	PrintTable(hashTable2, hashSize2); InitTable(hashTable2, hashSize2);

	for (int i = 0; i < elementsSize2; i++)
		PushTable(hashTable2, hashSize2, elements2[i], HashFunction_Quadratic);
	PrintTable(hashTable2, hashSize2); InitTable(hashTable2, hashSize2);

	for (int i = 0; i < elementsSize2; i++)
		PushTable_Double(hashTable2, hashSize2, secondSize2, num2, elements2[i], '-', HashFunction_Double);
	PrintTable(hashTable2, hashSize2); InitTable(hashTable2, hashSize2);

	return 0;
}