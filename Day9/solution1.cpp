#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <inttypes.h>
#include <unordered_map>

using namespace std;


int getY(vector<vector<int>> arr, int r, int i) {
	int val = arr[r][i];
	int v = 0;
	if((r - 1) < 0) {
		v = r+1;
		if(val == 9) {
			return 0;
		}
		if(arr[r+1][i] <= val) {
			return 0;
		}
	} else if(r + 1 >= arr.size()) {
		v = r-1;
		if(val == 9) {
			return 0;
		}
		if(arr[r-1][i] <= val) {
			return 0;
		}
		
	} else {
		if(arr[r-1][i] <= val || arr[r+1][i] <= val) {
			return 0;
		} else {
			return 1;
		}
	}
	if(arr[v][i] <= val) {
		return 0;
	}
	return 1;
}


int getX(vector<vector<int>> arr, int r, int i) {
	int val = arr[r][i];	
	int v = 0;	
	if(i - 1 < 0) {
		if(val == 9) {
			return 0;
		}
		if(arr[r][i+1] <= val) {
			return 0;
		}
		v = i + 1;
	} else if(i + 1 >= arr[r].size()) {
		if(val == 9) {
			return 0;
		}
		if(arr[r][i-1] <= val) {
			return 0;
		}
		v = i - 1;
	} else {
		if(arr[r][i-1] <= val || arr[r][i+1] <= val) {
			return 0;
		} else {
			return 1;
		}	
	}
	if(arr[r][v] <= val) {
		return 0;
	}
	return 1;
}


int main(int argc, char **argv) {
	if(argc != 2) {
		cout << argv[1] << " " << "filename " << endl;
		return 1;
	}
	ifstream file(argv[1]);
	string line;
	vector<vector<int>> arr;
	while(getline(file, line)) {
		vector<int> tmp;
		for(int i=0; i<line.size();i++) {
			tmp.push_back((int)line[i]-48);
		}
		arr.push_back(tmp);
	}
	vector<int> elms;
	for(int r = 0; r<arr.size();r++) {
		for(int i=0; i<arr[r].size();i++) {
			if(getX(arr, r, i)) {
				if(getY(arr, r, i)) {
					elms.push_back(arr[r][i]);
				}
			}
		}
	}
	int sum = 0;
	for(int i=0; i<elms.size();i++) {
		sum += elms[i] + 1;
	}
	cout << sum << endl;
	return 0;
}
