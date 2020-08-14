/*
* Title : Algorithm Efficiency and Sorting
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 1
* Description : Header file of sorting methods and analysis method
*/

class sorting {
public:
	void selectionSort(int *arr, int size, int &compCount, int &moveCount);
	void mergeSort(int *arr, int size, int &compCount, int &moveCount);
	void merge(int *arr, int left, int med, int right, int &compCount, int &moveCount);
	void quickSort(int *arr, int size, int &compCount, int &moveCount);
	void performanceAnalysis(int size);};