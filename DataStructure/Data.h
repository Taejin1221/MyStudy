#ifndef DATA_H
#define DATA_H

typedef struct _Data {
	int num;
} Data;

Data CreateData(int num);
void PrintData(Data data);
int CompareData(Data data1, Data data2);

#endif
