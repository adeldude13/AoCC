
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <inttypes.h>
#include <unordered_map>

using namespace std;

int maxv(vector<int> arr) {
	int ret = -12031;
	for(int i=0; i<arr.size();i++) {
		if(arr[i] > ret) {
			ret = arr[i];
		}
	}
	return ret;
}

int main(int argc, char **argv) {
	if(argc != 2) {
		cout << argv[1] << " " << "filename " << endl;
		return 1;
	}
	ifstream file(argv[1]);
	string line;
	unordered_map<uint64_t, uint64_t> umap;
	getline(file, line);
	vector<string> temp;
	vector<int> arr;
	boost::split(temp, line, boost::is_any_of(","));
	for(int i=0; i<temp.size();i++) {
		arr.push_back(stoi(temp[i]));
	}
	int leastMin = 2147483647;
	int mx = maxv(arr);
	for(int i=0; i<mx;i++) {
		int min = 0;
		uint16_t v = i;	
		for(int j=0; j<arr.size();j++) {
			if(v > arr[j]) {
				int a = 1;
				int p = arr[j];
				while(p < v) {
					min+=a;
					a++;
					p++;	
				}
			} else if(v < arr[j]) {
				int a = 1;
				int p = v;
				while(p < arr[j]) {
					min+=a;
					a++;
					p++;	
				}
			}
		}
		if(min < leastMin) {
			leastMin = min;
		}
	}
	cout << (leastMin);
	return 0;
}
