/*
* Title : Heaps and AVL Trees

* Author : Ömer Fatih Çelik
* ID : 21601387

* Section : 1
* Assignment : 3

* Description : main class to demonstrate permutation function

*/


#include <fstream>

#include "MaxHeap.h"

#include <iostream>

#include <string>

using namespace std;


int main() {
	
	ifstream file;

	file.open("input.txt");

	if (!file) {

		cout << "File not found";

		return 1;

	}

	
int heapSize;

	file >> heapSize;

	MaxHeap heap = MaxHeap(heapSize);

	for (int i = heapSize; i > 0; i--) {

		int a;

		file >> a;

		heap.insert(a);

	}
	int swap = 0;

	int permute = 0;

	heap.permutation(heap.getSize() / 2, heap.getSize() - 1, swap, permute);


	double swapAvg = (double)swap / permute;

	string outMsg = "Taking 20 TL is a better option";

	if (swapAvg > 2) {

		outMsg = "10 TL per swap is a better option";

	}


	cout << "The total number of swaps is " << swap << ".\nThe average number of swaps per permutation is " << permute << ".\n" << outMsg << endl;

	file.close();

	return 0;

}