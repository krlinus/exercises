#include <vector>
#include <iostream>
template<typename T>
void ilist(std::initializer_list<T> vals) {
	//for(auto p=vals.begin(); p!= vals.end(); ++p) 
	for(auto p : vals)
		std::cout << p << std::endl;
}

int main() {
	char c{7};
	std::vector<int> n{2,3,4,5,6};
	for(auto m : n) {
		std::cout << m << std::endl;
	}
	ilist({"Hello","How","do","you","do"});
	return 0;
}

