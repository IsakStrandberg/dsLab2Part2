#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

int computeSmallest(vector<int> x) {
	if (x.size() <= 5) {
		int smallest;
		smallest = x[0];
		for (int i = 0; i < x.size() - 1; i++) {
			if (x[i] < smallest) {
				smallest = x[i];
			}
		}
		return(x[3]);
	}

	//cout << "size is = " << x.size() << "\n";
	int div = x.size() / 5;
	int rest = x.size() % 5;
	cout << "div is = " << div << "\n";
	cout << "rest is = " << rest << "\n";

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

	for (int i = 0; i <= x.size() - 1; i++) {//added - 1 .... :)
		if (x[i] < medianMedian) {
			left.push_back(x[i]);
		}
		else {
			right.push_back(x[i]);
		}
	}

	int leftCap = left.size();


	if (leftCap == 3) {
		return(medianMedian);//found it
	}

	if (leftCap >= 4) {
		int smallest;
		smallest = left[0];
		for (int i = 0; i < left.size() - 1; i++) {
			if (left[i] < smallest) {
				smallest = left[i];
			}
		}
		//return(left[3]);
		computeSmallest(left);
	}
	else {
		int smallest;
		smallest = right[0];
		for (int i = 0; i < right.size() - 1; i++) {
			if (right[i] < smallest) {
				smallest = right[i];
			}
		}
		//return(right[3 - leftCap]);
		computeSmallest(right);
	}
	return(0);
}


void main() {
	vector<int> x;
	srand(time(0));
	int size = rand() % (10 - 4) + 4;
	cout << size << "\n";
	for (int i = 0; i <= size; i++) {
		int random = rand() % (1000 - 100) + 100;
		cout << random << "\n";
		x.push_back(random);
	}
	
	int smol = computeSmallest(x);
	cout << "\n\nthe 4th smallest number is: " << smol;

}