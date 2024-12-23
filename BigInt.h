#include "Number.h"
#include <vector>


class BigInt : public Number<long long> {
public:
  BigInt(long long value);
  BigInt(std::string str);
  BigInt(std::vector<short> value, bool sign);
  std::string toString() const override;
  void eval(std::string) override;
  double toReal() const override;
  BigInt *operator+(Number &other) override;
  BigInt *operator-(Number &other) override;
  BigInt *operator*(Number &other) override;
  BigInt *operator/(Number &other) override;
  BigInt *operator-() override;
  BigInt* operator+(long long& other) override;
  BigInt* operator-(long long& other) override;
  BigInt* operator*(long long& other) override;
  BigInt* operator/(long long& other) override;

private:
  std::vector<short> value;
  bool sign;
};