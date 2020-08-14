#include <iostream>
#include "MaxSubsequenceSumFinder.h"
#include <cmath>
#include <ctime>

using namespace std;

int main() {
	double duration;
	clock_t startTime;
	MaxSubsequenceSumFinder finder;
	vector<int> arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10, arr11, arr12;

	for (int i = 0; i < 9; i++) {   
		arr1.push_back((rand() % 100));
	}
	for (int i = 0; i < 27; i++) {
		arr2.push_back((rand() % 100));
	}
	for (int i = 0; i < 81; i++) {
		arr3.push_back((rand() % 100));
	}
	for (int i = 0; i < 243; i++) {
		arr4.push_back((rand() % 100));
	}
	for (int i = 0; i < 729; i++) {
		arr5.push_back((rand() % 100));
	}
	for (int i = 0; i < 2187; i++) {
		arr6.push_back((rand() % 100));
	}
	for (int i = 0; i < 6561; i++) {
		arr7.push_back((rand() % 100));
	}
	for (int i = 0; i < 19683; i++) {
		arr8.push_back((rand() % 100));
	}
	for (int i = 0; i < 59049; i++) {
		arr9.push_back((rand() % 100));
	}
	for (int i = 0; i < 177147; i++) {
		arr10.push_back((rand() % 100));
	}
	for (int i = 0; i < 531441; i++) {
		arr11.push_back((rand() % 100));
	}
	for (int i = 0; i < 1594323; i++) {
		arr12.push_back((rand() % 100));
	}

	startTime = clock();
	finder.maxSubSum1(arr1);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr1/algorithm1 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum2(arr1);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr1/algorithm2 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum3(arr1);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr1/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr1);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr1/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum1(arr2);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr2/algorithm1 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum2(arr2);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr2/algorithm2 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum3(arr2);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr2/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr2);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr2/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum1(arr3);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr3/algorithm1 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum2(arr3);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr3/algorithm2 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum3(arr3);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr3/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr3);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr3/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum1(arr4);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr4/algorithm1 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum2(arr4);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr4/algorithm2 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum3(arr4);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr4/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr4);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr4/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum1(arr5);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr5/algorithm1 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum2(arr5);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr5/algorithm2 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum3(arr5);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr5/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr5);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr5/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum2(arr6);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr6/algorithm2 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum3(arr6);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr6/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr6);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr6/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum2(arr7);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr7/algorithm2 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum3(arr7);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr7/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr7);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr7/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum3(arr8);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr8/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr8);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr8/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum3(arr9);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr9/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr9);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr9/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum3(arr10);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr10/algorithm3 took " << duration << " milliseconds." << endl;

	startTime = clock();
	finder.maxSubSum4(arr10);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr10/algorithm4 took " << duration << " milliseconds." << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum4(arr11);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr11/algorithm4 took " << duration << " milliseconds." << endl;

	/////////////////////////////////////////////////////////////////////////////////

	startTime = clock();
	finder.maxSubSum4(arr12);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "arr12/algorithm4 took " << duration << " milliseconds." << endl << endl;
}