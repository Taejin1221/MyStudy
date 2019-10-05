#include <stdio.h>
#include "Data.h"

Data CreateData(int num) {
	Data temp = { num };

	return temp;
}

void PrintData(Data data) {
	printf("[%d] -> ", data.num);
}

int CompareData(Data data1, Data data2) {
	return (data1.num - data2.num);
}
