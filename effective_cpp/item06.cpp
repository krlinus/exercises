#include <string>

template<typename T>
class NamedObject{
	std::string&nameValue;
	const T objectValue;
	public:
	NamedObject(std::string&name,const T&value):
		nameValue(name), objectValue(value){}
};
int main() {
	std::string newDog("Persephone");
	std::string oldDog("Satch");
	NamedObject<int> p(newDog, 2);
	NamedObject<int> s(oldDog, 36);

	p = s; // what should happen to p's data members?
	return 0;
}
/* Error:
item06.cpp: In member function ‘NamedObject<int>& NamedObject<int>::operator=(co        nst NamedObject<int>&)’:
item06.cpp:4:7: error: non-static reference member ‘std::string& NamedObject<int        >::nameValue’, can’t use default assignment operator
 class NamedObject{
       ^
item06.cpp:4:7: error: non-static const member ‘const int NamedObject<int>::obje        ctValue’, can’t use default assignment operator
item06.cpp: In function ‘int main()’:
item06.cpp:17:4: note: synthesized method ‘NamedObject<int>& NamedObject<int>::o        perator=(const NamedObject<int>&)’ first required here
  p = s; // what should happen to p's data members?
    ^
*/
