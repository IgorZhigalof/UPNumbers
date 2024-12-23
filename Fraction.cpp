#include "Fraction.h"
#include <typeinfo>


Fraction::Fraction(long numerator, long denominator) {
  this->numerator = numerator;
  this->denominator = denominator;
};

std::string Fraction::toString() const {
  return std::to_string(this->numerator) + "/" +
         std::to_string(this->denominator);
};

void Fraction::eval(std::string str) { this->numerator = std::stol(str); };

double Fraction::toReal() const {
  return ((double)this->numerator) / ((double)this->denominator);
}

Fraction *Fraction::operator+(Number &other) {
    const Fraction& otherFraction = dynamic_cast<const Fraction&>(other);
    return new Fraction(this->numerator * otherFraction.denominator +
        otherFraction.numerator * this->denominator,
        this->denominator * otherFraction.denominator);
};

Fraction *Fraction::operator-(Number &other) {
  const Fraction& otherFraction = dynamic_cast<const Fraction&>(other);
  return new Fraction(this->numerator * otherFraction.denominator -
      otherFraction.numerator * this->denominator,
      this->denominator * otherFraction.denominator);
};

Fraction *Fraction::operator*(Number &other) {
  const Fraction& otherFraction = dynamic_cast<const Fraction&>(other);
  return new Fraction(this->numerator * otherFraction.numerator,
      this->denominator * otherFraction.denominator);
};
Fraction *Fraction::operator/(Number &other) {
  const Fraction& otherFraction = dynamic_cast<const Fraction&>(other);
  return new Fraction(this->numerator * otherFraction.denominator,
      this->denominator * otherFraction.denominator);
};


Fraction* Fraction::operator+(long long& other) {
    return new Fraction(this->numerator +
        other * this->denominator,
        this->denominator);
};

Fraction* Fraction::operator-(long long& other) {
    return new Fraction(this->numerator -
        other * this->denominator,
        this->denominator);
};

Fraction* Fraction::operator*(long long& other) {
    return new Fraction(this->numerator * other,
        this->denominator);
};
Fraction* Fraction::operator/(long long& other) {
    return new Fraction(this->numerator,
        this->denominator * other);
};

Fraction *Fraction::operator-() {
  return new Fraction(this->toReal() * -1, this->denominator);
};
