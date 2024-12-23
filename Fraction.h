#include "Number.h"

class Fraction : public Number<long long> {
public:
  Fraction(long numerator, long denominator);
  ~Fraction() = default;
  std::string toString() const override;
  void eval(std::string) override;
  double toReal() const override;
  Fraction *operator+(Number &other) override;
  Fraction*operator-(Number &other) override;
  Fraction*operator*(Number &other) override;
  Fraction*operator/(Number &other) override;
  Fraction*operator-() override;
  Fraction* operator+(long long& other) override;
  Fraction* operator-(long long& other) override;
  Fraction* operator*(long long& other) override;
  Fraction* operator/(long long& other) override;

private:
  long numerator;
  long denominator;
};