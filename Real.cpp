#include "Real.h"

Real::Real(double value) { this->value = value; };

std::string Real::toString() const { return std::to_string(this->value); };

void Real::eval(std::string str) { this->value = std::stod(str); };

double Real::toReal() const { return this->value; }

Real* Real::operator+(Number &other) {
  return new Real(this->toReal() + other.toReal());
};

Real* Real::operator-(Number &other) {
  return new Real(this->toReal() - other.toReal());
};

Real* Real::operator*(Number &other) {
  return new Real(this->toReal() * other.toReal());
};

Real* Real::operator/(Number &other) {
  return new Real(this->toReal() / other.toReal());
};

Real* Real::operator-() { return new Real(this->toReal() * -1); };

Real* Real::operator+(double& other) {
	return new Real(this->toReal() + other);
};

Real* Real::operator-(double& other) {
	return new Real(this->toReal() - other);
};

Real* Real::operator*(double& other) {
	return new Real(this->toReal() * other);
};

Real* Real::operator/(double& other) {
	return new Real(this->toReal() / other);
};