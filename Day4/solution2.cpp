
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

using namespace std;

vector<string> filterWhile(vector<string> arr) {
	vector<string> ret;	
	for(int i=0;i<arr.size();i++) {
		if(arr[i] != "") {
			ret.push_back(arr[i]);
		}
	}
	return ret;
}

int checkc(vector<vector<string>> arr, int j) {
	for(int i=0;i<arr.size();i++) {
		if(arr[i][j] != " ") {
			return 0;
		}
	}
	return 1;
}

int checkCol(vector<vector<string>> arr, string str=" ") {
	int r = arr[0].size();
	for(int i=0;i<r;i++) {
		if(checkc(arr, i)) {
			return 1;
		}
	}
	return 0;
}


int getSum(vector<vector<string>> arr) {
	int sum = 0;	
	for(int i=0;i<arr.size();i++) {
		for(int j=0; j<arr.size();j++) {
			if(arr[i][j] != " ") {
				sum += stoi(arr[i][j]);
			}
		}
	}
	return sum;
}

int checkr(vector<string> arr) {
	for(int i=0; i<arr.size();i++) {
		if(arr[i] != " ") {
			return 0;
		}
	}
	return 1;
}


int checkRow(vector<vector<string>> arr, string str=" ") {
	for(int i=0; i<arr.size();i++) {
		for(int j = 0; j<arr[i].size();j++) {
			if(checkr(arr[i])) {
				return 1;
			}
		}
	}
	return 0;
}

void makeA(vector<vector<string>> arr, string value) {
	for(int i=0; i<arr.size();i++) {
		for(int j = 0; j<arr.size();j++) {
			if(arr[i][j] == value) {
				arr.at(i).at(j) = " ";
			}
		}
	}
}


int main(int argc, char **argv) {
	if(argc != 2) {
		return 1;
	}
	string line;
	vector<string> ints;
	ifstream file(argv[1]);
	getline(file, line);
  boost::split(ints, line, boost::is_any_of(","));	
	int i=-1;	
	vector<vector<vector<string>>> arr;	
	while(getline(file, line)) {
		vector<string> tmp;	
		if(line == "") {
				vector<vector<string>> sub;
				arr.push_back(sub);
				i++;
				getline(file, line);
		}
  	boost::split(tmp, line, boost::is_any_of(" "));	
		tmp = filterWhile(tmp);
		arr[i].push_back(tmp);
	}
	
	int sum;
	int called;
	vector<int> wins;	
	for(i = 0; i<ints.size();i++) {
		string curr = ints[i];	
		for(int j=0;j<arr.size();j++) {
			
			for(int z=0; z<arr[j].size();z++) {
				for(int f = 0; f<arr[j][z].size();f++) {
					if(arr[j][z][f] == curr) {
						arr[j][z][f] = " ";	
					}
				}
			}

			
			if(checkRow(arr[j]) || checkCol(arr[j])) {
					if(find(wins.begin(), wins.end(), j) == wins.end()) {
						wins.push_back(j);
						sum = getSum(arr[j]);
						called = stoi(curr);
					}
				}
				if(wins.size() == arr.size()) {
					goto A;
				}
			}
		}
A:
	cout << sum << " " << called << endl;
	cout << "Answer: " << called * sum << endl;
	return 0;
}
