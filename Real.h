#include "Number.h"

class Real : public Number<double> {
public:
  Real(double value);
  std::string toString() const override;
  void eval(std::string) override;
  double toReal() const override;
  Real* operator+(Number &other) override;
  Real* operator-(Number &other) override;
  Real* operator*(Number &other) override;
  Real* operator/(Number &other) override;
  Real* operator-() override;
  Real* operator+(double& other) override;
  Real* operator-(double& other) override;
  Real* operator*(double& other) override;
  Real* operator/(double& other) override;
private:
  double value;
};