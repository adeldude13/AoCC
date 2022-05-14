#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <inttypes.h>
#include <unordered_map>


using namespace std;

#define DAYS 256

int main(int argc, char **argv) {
	if(argc != 3) {
		cout << argv[1] << " " << "filename " << endl;
		return 1;
	}
	ifstream file(argv[1]);
	string line;
	unordered_map<uint64_t, uint64_t> umap;
	for(int i=0; i<=8;i++) {
		umap[i] = 0;
	}
	getline(file, line);
	vector<string> temp;
	vector<uint8_t> fishes;
	boost::split(temp, line, boost::is_any_of(","));
	for(int i=0; i<temp.size();i++) {
		fishes.push_back(stoi(temp[i]));
	}
	for(int i=0; i<fishes.size();i++) {
		umap[fishes[i]] += 1;
	}
	uint64_t count = fishes.size();
	int j = 0;
	while(j < DAYS) {
		uint64_t tmp = umap[0];
		umap[0] = 0;
		for(int i=1;i<=8;i++) {
				umap[i-1] += umap[i];
				umap[i] = 0;
		}
		count += tmp;
		umap[8] += tmp;
		umap[6] += tmp;
		j++;
	}
	
	cout << count;	
	return 0;
}
