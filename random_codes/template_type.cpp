/* TEMPLATE FUNCTIONS */
#include <iostream>

// Generic typing for a function
template<typename CheckLowerGeneric>
CheckLowerGeneric CheckLower(CheckLowerGeneric a, CheckLowerGeneric b) {
	return a < b ? a : b;
}

int main() {
	int a = 4;
	int b = 5;

	float c = 12.32;
	float d = 14.32;

	int lower = CheckLower<int>(a, b);
	float lowerFloat = CheckLower<float>(c, d);

	std::cout << "Int: " << lower << std::endl;
	std::cout << "Float: " << lowerFloat << std::endl;
	return 0;
}