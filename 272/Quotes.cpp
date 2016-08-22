#include <iostream>
#include <string>
#include <vector>

int main(void) {
	std::string line;
	std::vector<std::string> v1; 
	int count = 0;

	while (std::getline(std::cin,line)) {
		count = 0;
		v1.clear();
		v1.push_back(line);
		
		//Try if the input is correct 
		//for (int i = 0; i < v1.size(); i++)
		//	std::cout << v1[i];
		//std::cout << std::endl;
	
		for (int i = 0; i < v1.size(); i++) {
			if ( == 0) {
				count++;
				if (count % 2) 
					std::cout << "``";
				else
					std::cout << "''";
			} else {
				std::cout << v1[i];
			}
		}
		std::cout << std::endl;
		
	} 

	return 0;
} 
