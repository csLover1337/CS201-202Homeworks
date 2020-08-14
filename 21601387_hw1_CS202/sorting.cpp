/*
* Title : Algorithm Efficiency and Sorting
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 1
* Description : Source file of sorting methods and analysis method
*/

#include "sorting.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

void sorting::selectionSort(int *arr, int size, int &compCount, int &moveCount) {
	int maxLoc;
	int temp;

	for (int i = 0; i < size - 1; i++) {
		maxLoc = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[j] > arr[maxLoc])
				maxLoc = j;
			compCount++;
		}

		temp = arr[maxLoc];
		arr[maxLoc] = arr[i];
		arr[i] = temp;
		moveCount = moveCount + 3;
	}
}

void sorting::mergeSort(int *arr, int size, int &compCount, int &moveCount) {
	if (size > 1) {
		int leftSize = size / 2;
		int rightSize = size - leftSize;

		mergeSort(arr, leftSize, compCount, moveCount);
		mergeSort(arr + leftSize, rightSize, compCount, moveCount);

		merge(arr, 0, leftSize - 1, size - 1, compCount, moveCount);
	}
}

void sorting::merge(int *arr, int left, int med, int right, int &compCount, int &moveCount) {
	int leftArrLen = med - left + 1;
	int rightArrLen = right - med;
	int *leftArr = new int[leftArrLen];
	int *rightArr = new int[rightArrLen];
	
	for (int i = 0; i < leftArrLen; i++) {
		leftArr[i] = arr[left + i];
		moveCount++;
	}
	for (int i = 0; i < rightArrLen; i++) {
		rightArr[i] = arr[med + i + 1];
		moveCount++;
	}
	
	int leftArrMoved = 0;
	int rightArrMoved = 0;
	int moved = 0;

	for (; leftArrMoved < leftArrLen && rightArrMoved < rightArrLen; moved++) {

		if (leftArr[leftArrMoved] >= rightArr[rightArrMoved]) {
			arr[moved + left] = leftArr[leftArrMoved];
			leftArrMoved++;
		}
		else {
			arr[moved + left] = rightArr[rightArrMoved];
			rightArrMoved ++;
		}
		compCount++;
		moveCount++;
	}

	for (; leftArrMoved < leftArrLen; moved++)
	{
		arr[moved + left] = leftArr[leftArrMoved];
		leftArrMoved++;
		moveCount++;
	}
	for (; rightArrMoved < rightArrLen; moved++)
	{
		arr[moved + left] = rightArr[rightArrMoved];
		rightArrMoved++;
		moveCount++;
	}

	delete[] leftArr;
	delete[] rightArr;
}

void sorting::quickSort(int *arr, int size, int &compCount, int &moveCount) { 
	if (size > 1) {
		int pivot = arr[0];
		moveCount++;
		int smallerIndex = size;
		for (int i = size - 1; i > 0; i--) {
			if (arr[i] <= pivot) {  
				smallerIndex--;
				int temp = arr[smallerIndex];
				arr[smallerIndex] = arr[i];
				arr[i] = temp;
				moveCount += 3;
			}
			compCount++;
		}
		arr[0] = arr[smallerIndex - 1];
		arr[smallerIndex - 1] = pivot;
		moveCount = moveCount + 2;

		quickSort(arr, smallerIndex - 1, compCount, moveCount);
		quickSort(arr + smallerIndex - 1, size - smallerIndex, compCount, moveCount);
	}
}

void sorting::performanceAnalysis(int size) {
	int *arr1 = new int[size];
	int *arr2 = new int[size];
	int *arr3 = new int[size];
	int *arr4 = new int[size];
	int *arr5 = new int[size];
	int *arr6 = new int[size];
	int *arr7 = new int[size];
	int *arr8 = new int[size];
	int *arr9 = new int[size];
	int *arr10 = new int[size];
	int *arr11 = new int[size];
	int *arr12 = new int[size];
	int compCount1 = 0;
	int moveCount1 = 0;
	int compCount2 = 0;
	int moveCount2 = 0;
	int compCount3 = 0;
	int moveCount3 = 0;
	int compCount4 = 0;
	int moveCount4 = 0;
	int compCount5 = 0;
	int moveCount5 = 0;
	int compCount6 = 0;
	int moveCount6 = 0;
	int compCount7 = 0;
	int moveCount7 = 0;
	int compCount8 = 0;
	int moveCount8 = 0;
	int compCount9 = 0;
	int moveCount9 = 0;
	int compCount10 = 0;
	int moveCount10 = 0;
	int compCount11 = 0;
	int moveCount11 = 0;
	int compCount12 = 0;
	int moveCount12 = 0;
	double time1;
	double time2;
	double time3;
	double time4;
	double time5;
	double time6;
	double time7;
	double time8;
	double time9;
	double time10;
	double time11;
	double time12;

	for (int i = 0; i < size; i++) {
		arr1[i] = rand() % 1000;
		arr2[i] = rand() % 1000;
		arr3[i] = rand() % 1000;
	}
	for (int i = 0; i < size; i++) {
		arr4[i] = i + 1;
		arr5[i] = i + 1;
		arr6[i] = i + 1;
	}
	for (int i = 0; i < size; i++) {
		arr7[i] = size - i;
		arr8[i] = size - i;
		arr9[i] = size - i;
	}
	for (int i = 0; i < size / 2; i++) {
		arr10[i] = i + 1;
		arr11[i] = i + 1;
		arr12[i] = i + 1;
	}
	for (int i = size / 2; i < size; i++) {
		arr10[i] = size + (size / 2) - i;
		arr11[i] = size + (size / 2) - i;
		arr12[i] = size + (size / 2) - i;
	}

	clock_t t = clock();
	selectionSort(arr1, size, compCount1, moveCount1);
	t = clock() - t;
	time1 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	selectionSort(arr4, size, compCount4, moveCount4);
	t = clock() - t;
	time4 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	selectionSort(arr7, size, compCount7, moveCount7);
	t = clock() - t;
	time7 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	selectionSort(arr10, size, compCount10, moveCount10);
	t = clock() - t;
	time10 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	mergeSort(arr2, size, compCount2, moveCount2);
	t = clock() - t;
	time2 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	mergeSort(arr5, size, compCount5, moveCount5);
	t = clock() - t;
	time5 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	mergeSort(arr8, size, compCount8, moveCount8);
	t = clock() - t;
	time8 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	mergeSort(arr11, size, compCount11, moveCount11);
	t = clock() - t;
	time11 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	quickSort(arr3, size, compCount3, moveCount3);
	t = clock() - t;
	time3 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	quickSort(arr6, size, compCount6, moveCount6);
	t = clock() - t;
	time6 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	quickSort(arr9, size, compCount9, moveCount9);
	t = clock() - t;
	time9 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	t = clock();
	quickSort(arr12, size, compCount12, moveCount12);
	t = clock() - t;
	time12 = ((double)t * 1000) / (double)CLOCKS_PER_SEC;

	cout << "Performance analysis for arrays of size " << size << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;	cout << "Random integers               Elapsed time   compCount   moveCount" << endl;
	cout << "Selection sort                   " << time1 << "          " << compCount1 << "          " << moveCount1 << endl;
	cout << "Merge sort                       " << time2 << "          " << compCount2 << "          " << moveCount2 << endl;
	cout << "Quick sort                       " << time3 << "          " << compCount3 << "          " << moveCount3 << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "Ascending integers            Elapsed time   compCount   moveCount" << endl;
	cout << "Selection sort                   " << time4 << "          " << compCount4 << "          " << moveCount4 << endl;
	cout << "Merge sort                       " << time5 << "          " << compCount5 << "          " << moveCount5 << endl;
	cout << "Quick sort                       " << time6 << "          " << compCount6 << "          " << moveCount6 << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "Descending integers           Elapsed time   compCount   moveCount" << endl;
	cout << "Selection sort                   " << time7 << "          " << compCount7 << "          " << moveCount7 << endl;
	cout << "Merge sort                       " << time8 << "          " << compCount8 << "          " << moveCount8 << endl;
	cout << "Quick sort                       " << time9 << "          " << compCount9 << "          " << moveCount9 << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "Ascending/descending integers Elapsed time   compCount   moveCount" << endl;
	cout << "Selection sort                   " << time10 << "          " << compCount10 << "          " << moveCount10 << endl;
	cout << "Merge sort                       " << time11 << "          " << compCount11 << "          " << moveCount11 << endl;
	cout << "Quick sort                       " << time12 << "          " << compCount12 << "          " << moveCount12 << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;
	delete[] arr8;
	delete[] arr9;
	delete[] arr10;
	delete[] arr11;
	delete[] arr12;
}
