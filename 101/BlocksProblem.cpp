#include <iostream>
#include <string>
//#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main (void) {
	
	int n;

	//declaration container and iterator
	//map<int, vector<int>> mapBlock;
	//map<int, vector<int>>::iterator iter;
	//map<int, vector<int>>::reverse_iterator iter_r;
	
	while (cin >> n) {
		if (0 < n && n < 25) {
			int first, second;
			string command, prep;

			vector<int> bvec[25];
			vector<int>::iterator iter;
			vector<int>::reverse_iterator riter;

			cout <<"initialize data" <<endl;
			for (int i = 0; i < n; i++) {
				bvec[i].push_back(i);
					
				cout << i <<":";
				for ( iter = bvec[i].begin(); iter != bvec[i].end(); iter++)
					cout << " " << *iter;
				cout << endl;
			}
			cout << "===============================" <<endl;

			while (cin >> command) {
		
				if (command == "quit") {
					//Exit and print status
					for (int i = 0; i < n; i++) {
						cout << i <<":";
						for ( iter = bvec[i].begin(); iter != bvec[i].end(); iter++)
							cout << " " << *iter;
						cout << endl;
					}
					//break;
				} else { 
					cin >> first;
					cin >> prep;
					cin >> second;
					if (first != second) {
						if (command == "move") {
							cout << " move    ";
							for ( riter = bvec[first].rbegin(); 
							      riter != bvec[first].rend(); 
							      ++riter) {
								// 將first上的積木放回原來的位罝
								cout << "a: "<< first <<endl;
								int originalIndex = *riter;
								cout << "box on a: "<< originalIndex <<endl;
								if (originalIndex != first) {
									cout << "Push back "<<originalIndex<<endl;	
									bvec[originalIndex].push_back(originalIndex);
									bvec[first].pop_back();
								}
							}

							if (prep == "onto") {
								cout << " onto    ";
								for ( riter = bvec[second].rbegin(); 
								      riter != bvec[second].rend(); 
								      ++riter) {
									// 將second上的積木放回原來的位罝
									cout << "b: "<< second <<endl;
									int originalIndex = *riter;
									cout << "box on b: "<<originalIndex <<endl;
									if (originalIndex != second) {
										cout << "Push back "<<originalIndex<<endl;	
										bvec[originalIndex].push_back(originalIndex);
										bvec[second].pop_back();
									}
								}
							}

							//把first搬到second上
							cout << "Push " <<first << " to "<<second<<endl;	
							bvec[second].push_back(first);
							iter = find(bvec[first].begin(), bvec[first].end(), first); 
							if (iter != bvec[first].end() )
								bvec[first].erase(iter);

						} else if (command == "pile") {
							cout << " pile    ";
							if (prep == "onto") {
								cout << " onto    ";
								for ( riter = bvec[second].rbegin(); 
								      riter != bvec[second].rend(); 
								      ++riter) {
									// 將second上的積木放回原來的位罝
									int originalIndex = *riter;
									cout <<"box on b: "<< originalIndex <<endl;
									if (originalIndex != second) {
										cout << "Push back "<<originalIndex<<endl;	
										bvec[originalIndex].push_back(originalIndex);
										bvec[second].pop_back();
									}
								}
							}

							// 將first上的積木全放到second上
							for ( riter = bvec[first].rbegin(); 
							      riter != bvec[first].rend(); 
							      ++riter) {
								int originalIndex = *riter;
								cout << originalIndex <<endl;
								cout << "Push " << originalIndex << " to " <<second<<endl;	
								bvec[second].push_back(originalIndex);
								bvec[first].pop_back();
							}

						}
					}
				}
			}
		}
	}
}
