#include "Number.h"

class Int : public Number<long long> {
public:
  Int(int value);
  ~Int() = default;
  std::string toString() const override;
  void eval(std::string) override;
  double toReal() const override;
  Int *operator+(Number &other) override;
  Int*operator-(Number &other) override;
  Int*operator*(Number &other) override;
  Int*operator/(Number &other) override;
  Int*operator-() override;
  Int* operator+(long long& other) override;
  Int* operator-(long long& other) override;
  Int* operator*(long long& other) override;
  Int* operator/(long long& other) override;

private:
  int value;
};