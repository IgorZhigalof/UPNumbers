#include <iostream>
#include "BigInt.h"

int main() {
	using namespace std;
	BigInt* a = new BigInt(std::string(20000, '1'));
	BigInt* b = new BigInt(std::string(20000, '1'));
	BigInt* c = (*a * *b);
	cout << c->toString();
}