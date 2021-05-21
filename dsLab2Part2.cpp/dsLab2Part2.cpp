#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

int computeSmallest(vector<int> x, int search) {
	if (x.size() <= 5) {
		/*for (int i = 0; i < x.size(); i++) {
			cout << "\n x is : " << x[i];
		}
		int smaller;
		smaller = x[0];
		cout << "\n aaaaa " << x[0];
		for (int i = 0; i < x.size() - 1; i++) {
			if (x[i] <= smaller) {
				int temp = x[i];
				smaller = x[i];
				x[i + 1] = temp;
			}
		}*/
		for(int j = 0; j < x.size() - 1; j++){
			if (x[j] > x[j + 1]) {
				int temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;

				j = -1;
			}
		}

		return(x[3]);
	}

	//cout << "size is = " << x.size() << "\n";
	int div = x.size() / 5;
	int rest = x.size() % 5;
	//cout << "div is = " << div << "\n";
	//cout << "rest is = " << rest << "\n";

	int sel = 0;
	int median = 0;
	int medianMedian = 0;
	//int *array = new int(div);
	vector<int> medianSave;
	for (int i = 0; i <= div - 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (x[j + sel] > x[j + sel + 1]) {
				int temp = x[j + sel];
				x[j + sel] = x[j + sel + 1];
				x[j + sel + 1] = temp;
				j = -1;
			}
		}
		//median 1,2,3.... = x[2 + sel]
		medianSave.push_back(x[2 + sel]);
		sel = sel + 5;
	}
	
	int zeroCheck = medianSave.size();
	int half = 0;
	if (zeroCheck % 2 == 0) {
		int half = medianSave.size() / 2 + (medianSave.size() -1) / 2;
	}
	else {
		int half = medianSave.size() / 2;
	}

	medianMedian = medianSave[half];

	vector<int> left;
	vector<int> right;

	left.push_back(medianMedian);//adds median to left, important

	for (int i = 0; i <= x.size() - 1; i++) {//added - 1 .... :)
		if (x[i] < medianMedian) {
			left.push_back(x[i]);
		}
		else {
			right.push_back(x[i]);
		}
	}

	int leftCap = left.size();


	if (leftCap == search) {
		return(medianMedian);//found it
	}

	if (leftCap >= 4) {
		/*int smallest;
		smallest = left[0];
		for (int i = 0; i < left.size() - 1; i++) {
			if (left[i] < smallest) {
				smallest = left[i];
			}
		}*/
		//return(left[3]);
		return(computeSmallest(left, 3));
	}
	else {
		/*int smallest;
		smallest = right[0];
		for (int i = 0; i < right.size() - 1; i++) {
			if (right[i] < smallest) {
				smallest = right[i];
			}
		}*/
		//return(right[3 - leftCap]);
		return(computeSmallest(right, 3 - leftCap));
	}
	//return(0);
}


void main() {
	vector<int> x;
	srand(time(0));
	int size = rand() % (100 - 4) + 4;
	cout << size << "\n";
	for (int i = 0; i <= size; i++) {
		int random = rand() % (1000 - 100) + 100;
		cout << random << "\n";
		x.push_back(random);
	}
	
	int smol = computeSmallest(x, 3);
	cout << "\n\nthe 4th smallest number is: " << smol;

}