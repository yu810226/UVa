#include <iostream>

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int threeNPlusOne(int val) {
	if (val == 1) {
		return 1;
	} else if (val % 2 != 0){
		return 3 * val + 1;
	} else {
		return val/2; 
	}
} 

int countTimes(int val) {
	int c = 1;

	while (val != 1) {
		val = threeNPlusOne(val);
		c++;
	}

	return c;
}

int main(void) {
	int i,j;
	
	while (std::cin >> i >> j) {
		std::cout << i << " " << j << " ";
		
		int n = 0;
		int cycleLen = 0;

		if ( i > j) 
			swap(i,j);

		for (int k = i; k <= j; k++ ) {
			n = countTimes(k);
			if (cycleLen < n) 
				cycleLen = n;
		}
	
		std::cout << cycleLen << std::endl;		
	}
} 
