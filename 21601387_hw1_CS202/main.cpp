/*
* Title : Algorithm Efficiency and Sorting
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 1
* Description : test of analysis methods
*/

#include "sorting.h"
#include <iostream>
using namespace std;

int main() {
	int num;
	sorting test = sorting();
	test.performanceAnalysis(1000);
	cout << endl << endl;
	test.performanceAnalysis(6000);
	cout << endl << endl;
	test.performanceAnalysis(12000);
	cout << endl << endl;
	test.performanceAnalysis(18000);
	return 0;
}