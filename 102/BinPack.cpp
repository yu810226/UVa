#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	long long firstBrown, firstGreen, firstClear;
	long long secondBrown, secondGreen, secondClear;
	long long thirdBrown, thirdGreen, thirdClear;

	while(cin >> firstBrown >> firstGreen >> firstClear) {
		cin >> secondBrown >> secondGreen >> secondClear;
		cin >> thirdBrown >> thirdGreen >> thirdClear;

		// Test if cin works correctly
		//cout << firstBrown <<endl;

		unsigned count1st, count, least;
		string res;
		// BCG, BGC
		// For Brown in the first bucket 
		count1st = (secondBrown + thirdBrown);
		// CG
		count = (firstClear + thirdClear);
		count += (firstGreen + secondGreen);
		least = count + count1st;
		res = "BCG";
		
		// GC
		count = (firstGreen + thirdGreen);
		count += (firstClear + secondClear);
		if ( (count + count1st) < least) { 
			least = count + count1st;
			res = "BGC";
		}

		// CBG, CGB
		// For Clear in the first bucket 
		count1st = (secondClear + thirdClear);
		// BG
		count = (firstBrown + thirdBrown);
		count += (firstGreen + secondGreen);
		if ( (count + count1st) < least) { 
			least = count + count1st;
			res = "CBG";
		}
		
		// GB
		count = (firstGreen + thirdGreen);
		count += (firstBrown + secondBrown);
		if ( (count + count1st) < least) { 
			least = count + count1st;
			res = "CGB";
		}
		
		// GBC, GCB
		// For Green in the first bucket 
		count1st = (secondGreen + thirdGreen);
		// BC
		count = (firstBrown + thirdBrown);
		count += (firstClear + secondClear);
		if ( (count + count1st) < least) { 
			least = count + count1st;
			res = "GBC";
		}
		
		// CB
		count = (firstClear + thirdClear);
		count += (firstBrown + secondBrown);
		if ( (count + count1st) < least) { 
			least = count + count1st;
			res = "GCB";
		}
		
		cout << res << " " << least << "\n";

	}
	return 0;
}
