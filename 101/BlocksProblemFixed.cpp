#include <iostream>
#include <string>
//#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct findBlockInfo{
	vector<int>::iterator iterInBlock;
	int idx;
};

void print (vector<int> vec[], int size);
//struct findBlockInfo* findBlock(vector<int> vec[], int size, int key);
struct findBlockInfo findBlock(vector<int> vec[], int size, int key);
void moveback(vector<int> vec[], int destIndex, vector<int>::iterator destIter, int key);
void moveto(vector<int> vec[], int oriIndex, int oriKey, vector<int>::iterator oriIter, int destKey, int destIndex);

int n = 0;

int main (void) {
	
	//int n;

	while (cin >> n) {
		if (0 < n && n < 25) {
			int first, second;
			string command, prep;

			vector<int> bvec[25];

			//cout <<"initialize data" <<endl;
			for (int i = 0; i < n; i++) {
				bvec[i].push_back(i);
			}

			//print(bvec, n);
			//cout << "===============================" <<endl;

			while (cin >> command) {
				//cout << command;
				if (command == "quit") {
					//Exit and print status
					//cout << '\n';
					print(bvec, n);
					break;
				} else { 
					cin >> first;
					cin >> prep;
					cin >> second;
					//cout <<" " <<first <<" " <<prep <<" " <<second <<endl;
					if (first != second) {
						struct findBlockInfo info4First = findBlock(bvec, n, first);
						struct findBlockInfo info4Sec = findBlock(bvec, n, second);
						//cout << "First on box: "<< (info4First.idx) <<'\n'; 
						//cout << "Second on box: "<< (info4Sec.idx) <<'\n'; 
						if (info4First.idx != info4Sec.idx) {
							if (command == "move") {
								//cout << " move    "<<endl;
								if (info4First.idx != -1) {
									moveback(bvec, info4First.idx,
										 info4First.iterInBlock, first);
								}

								if (prep == "onto") {
									//cout << " onto    "<<endl;
									if (info4Sec.idx != -1) {
										moveback(bvec, info4Sec.idx,
										 	info4Sec.iterInBlock, 
											second);
									}
								}

								//把first搬到second上
								//cout << "Push " <<first << " to "<<second<<endl;
								//Fixed: should push on to where second is 
								//bvec[second].push_back(first);
								bvec[(info4Sec.idx)].push_back(first);
								bvec[(info4First.idx)].pop_back();
								
								//print(bvec, n);

							} else if (command == "pile") {
								//cout << " pile    "<<endl;
								if (prep == "onto") {
									//cout << " onto    "<<endl;
									if (info4Sec.idx != -1) {
										moveback(bvec, info4Sec.idx,
										 	info4Sec.iterInBlock, 
											second);
									}
								}

								// 將first上的積木全放到second上
								if (info4First.idx != -1) {
									moveto(bvec, info4First.idx, 
										first, info4First.iterInBlock, 
										second, info4Sec.idx);
								}
								
								//print(bvec, n);
							
							}
						}
					}
				}
			}
        }
	}
	return 0;
}

void print (vector<int> vec[], int size) {
	for (int i = 0; i < size; i++) {
		cout << i <<":";
		for ( vector<int>::iterator iter = vec[i].begin(); iter != vec[i].end(); iter++)
			cout << " " << *iter;
		cout << '\n';
	}
}

struct findBlockInfo findBlock(vector<int> vec[], int size, int key) {
	struct findBlockInfo info;
	for (int i = 0; i < size; i++) { 
		vector<int>::iterator iter = find(vec[i].begin(), vec[i].end(), key);
		if (iter != vec[i].end() ) {
			//cout << key << " on box " <<i <<'\n';
			info.iterInBlock = iter;
			info.idx = i;
			//break;
			return info;
		} else {
			//info.iterInBlock = __null;
			info.idx = -1;
		}
	}
	return info;
}

void moveback(vector<int> vec[], int destIndex, vector<int>::iterator destIter,int key){
	//for ( vector<int>::reverse_iterator riter = vec[destIndex].rbegin(); riter != destIter; ++riter) {
	//for ( vector<int>::reverse_iterator riter = vec[destIndex].rbegin(); 
	//      riter != vec[destIndex].rend(); ++riter) {
	//for ( vector<int>::iterator iter = destIter; 
	//      iter != vec[destIndex].end(); ++iter) {
	//cout << "In moveback\n";	
	for ( vector<int>::iterator iter = destIter+1; 
	      iter != vec[destIndex].end(); ) {
		//if (vec[destIndex].empty())
		//	break;
		// 將key上的積木放回原來的位罝
		//cout << "key: "<< key <<endl;
		int originalIndex = *iter;
		//cout << "box on key: "<< originalIndex <<endl;
		//cout << "Push back "<<originalIndex<< " to " << originalIndex <<endl;	
		vec[originalIndex].push_back(originalIndex);
		//Fixed: Use erase
		//cout << "Iter: "<< *iter<<'\n';
		iter = vec[destIndex].erase(iter);
		//cout << "Iter after erase: "<< *iter<<'\n';
	}
	//print(vec, n);
	//cout << "------------------------------\n";	
}

void moveto(vector<int> vec[], int oriIndex, int oriKey, vector<int>::iterator oriIter, int destKey, int destIndex){
	//for ( vector<int>::reverse_iterator riter = vec[oriIndex].rbegin(); 
	//      riter != vec[oriIndex].rend(); ++riter) {
	//for ( vector<int>::iterator iter = oriIter; 
	//      iter != vec[oriIndex].end(); ++iter) {
	for ( vector<int>::iterator iter = oriIter; 
	      iter != vec[oriIndex].end(); ) {
		int originalIndex = *iter;
		//cout << originalIndex <<endl;
		//cout << "Push " << originalIndex << " to " <<destKey<<endl;	
		vec[destIndex].push_back(originalIndex);
		//Fixed: Use erase
		iter = vec[oriIndex].erase(iter);
	}
	
	//cout << "In moveto\n";	
	//print(vec, n);
	//cout << "------------------------------\n";	
}
