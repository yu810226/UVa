#include <iostream>
#include <vector>

using namespace std;

int main (void) {
	int n;
	cin >> n;
	vector<int> bvec[n];

	int num1 = 10;
	int num2 = 20;
	int num3 = 30;
	
	bvec[0].push_back(num1);
	bvec[0].push_back(num2);
	bvec[1].push_back(num3);

	for(int iy; iy < n; ++iy){
		vector<int>::iterator iter = bvec[iy].begin();
		cout << iy << ": ";
		for(int ix = 0; iter != bvec[iy].end(); ++iter, ++ix){
			cout << *iter <<" ";
		}
		cout << endl;
	}
}
