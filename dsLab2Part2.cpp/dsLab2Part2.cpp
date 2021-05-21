#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;
int comp = 0;

int computeSmallest(vector<int> x, int search) {
	if (x.size() <= 5) {
		
		for(int j = 0; j < x.size() - 1; j++){
			if (x[j] > x[j + 1]) {
				int temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;

				j = -1;
				comp++;
			}
		}

		return(x[search]);
	}

	int div = x.size() / 5;

	int sel = 0;
	int medianMedian = 0;
	vector<int> medianSave;
	for (int i = 0; i <= div - 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (x[j + sel] > x[j + sel + 1]) {
				int temp = x[j + sel];
				x[j + sel] = x[j + sel + 1];
				x[j + sel + 1] = temp;
				j = -1;
				comp++;
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

	for (int i = 0; i <= x.size() - 1; i++) {
		if (x[i] < medianMedian) {
			left.push_back(x[i]);
		}
		else {
			right.push_back(x[i]);
		}
	}

	int leftCap = left.size();


	if (leftCap == search) {
		comp++;
		return(medianMedian);
	}

	if (leftCap >= 4) {
		comp++;
		return(computeSmallest(left, 3));
	}
	else {
		comp++;
		return(computeSmallest(right, 3 - leftCap));
	}
}


void main() {
	vector<int> x;
	x[0] = 3;
	x[1] = 66;
	x[2] = 20;
	//srand(time(0));
	/*int size = rand() % (10000) + 4;
	cout << size << "\n";
	for (int i = 0; i <= size; i++) {
		int random = rand() % (1000 - 100) + 100;
		cout << random << "\n";
		x.push_back(random);
	}*/
	
	int smol = computeSmallest(x, 3);
	cout << "\n\nthe 4th smallest number is: " << smol;
	cout << "\n comparisons = " << comp;
}