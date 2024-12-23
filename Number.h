#ifndef NUMBER_H
#define NUMBER_H
#include <string>

template<typename T>
class Number {
public:
  ~Number() = default;
  virtual std::string toString() const = 0;
  virtual double toReal() const = 0;
  virtual void eval(std::string) = 0;
  virtual Number *operator+(Number &other) = 0;
  virtual Number *operator-(Number &other) = 0;
  virtual Number *operator*(Number &other) = 0;
  virtual Number *operator/(Number &other) = 0;
  virtual Number *operator-() = 0;
  virtual Number* operator+(T& other) = 0;
  virtual Number* operator-(T& other) = 0;
  virtual Number* operator*(T& other) = 0;
  virtual Number* operator/(T& other) = 0;
};

#endif // NUMBER_H