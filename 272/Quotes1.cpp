#include <iostream>
#include <string>

//this machine is okay with this, but UVa should add this line.
#include <string.h>


int main(void) {
	std::string line;
	int count = 0;

	while (std::getline(std::cin,line)) {
		//count = 0;
		char *cstr;
		cstr = new char[line.size()+1]; 
		//c_str() 是將一個 AnsiString 的字串轉換成以NULL結尾的字串
		strcpy(cstr, line.c_str());

		//Try if the input is correct 
		//for (int i = 0; i < line.size(); i++)
		//	std::cout << cstr[i];
		//std::cout << std::endl;
	
		for (int i = 0; i < line.size(); i++) {
			if (cstr[i] == '\"') {
				count++;
				if (count % 2) 
					std::cout << "``";
				else
					std::cout << "''";
			} else {
				std::cout << cstr[i];
			}
		}
		std::cout << std::endl;

		delete [] cstr;
	} 

	return 0;
} 
