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

int checkCol(vector<vector<string>> arr, string str=" ") {
	int r = arr[0].size();
	for(int i=0;i<r;i++) {
		for(int j=0; j<arr.size(); j++) {
			if(arr[j][i] != str) {
				return 0;
			}
		}
	}
	return 1;
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


int checkRow(vector<string> arr, string str=" ") {
	for(int i=0; i<arr.size();i++) {
		if(arr[i] != str) {
			return 0;
		}
	}
	return 1;
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
	for(i = 0; i<ints.size();i++) {
		string curr = ints[i];	
		for(int j=0;j<arr.size();j++) {
			for(int z = 0;z<arr[j].size();z++) {
				for(int f = 0;f<arr[j][z].size();f++) {
					if(arr[j][z][f] == curr) {
						arr[j][z][f] = " "; 
					}
				}
				if(checkRow(arr[j][z]) || checkCol(arr[j])) {
					sum = getSum(arr[j]);
					called = stoi(curr);
					goto A;	
				}	
			}
		}

	}
A:
	cout << "checked" << " " << sum << " " << called << " " << endl;
	cout << sum * called << endl;
	return 0;
}
