#include "Int.h"

Int::Int(int value) { this->value = value; };

std::string Int::toString() const { return std::to_string(this->value); };

void Int::eval(std::string str) { this->value = std::stod(str); };

double Int::toReal() const { return (double)value; }

Int *Int::operator+(Number &other) {
  return new Int(this->toReal() + other.toReal());
};
Int*Int::operator-(Number &other) {
  return new Int(this->toReal() - other.toReal());
};
Int*Int::operator*(Number &other) {
  return new Int(this->toReal() * other.toReal());
};
Int*Int::operator/(Number &other) {
  return new Int(this->toReal() / other.toReal());
};
Int* Int::operator+(long long& other) {
	return new Int(this->toReal() + other);
};
Int* Int::operator-(long long& other) {
	return new Int(this->toReal() - other);
};
Int* Int::operator*(long long& other) {
	return new Int(this->toReal() * other);
};
Int* Int::operator/(long long& other) {
	return new Int(this->toReal() / other);
};

Int*Int::operator-() { return new Int(this->toReal() * -1); };
