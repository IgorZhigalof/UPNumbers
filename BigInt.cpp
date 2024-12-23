#include "BigInt.h"
#include <iostream>
#include <sstream>

static std::vector<short> getValueFromString(std::string str) {
    std::vector<short> result;
    bool isNegative = false;
    if (str[0] == '-') {
        isNegative = true;
    }
    for (int i = str.length() - 1; i >= (isNegative ? 1 : 0); i--) {
        result.push_back((short) ((str[i] - '0')));
    }
    return result;
}

static bool isFirstBigger(const std::vector<short>& first, const std::vector<short>& second) {
    size_t maxSize = std::max(first.size(), second.size());
    std::vector<short> paddedFirst = first;
    std::vector<short> paddedSecond = second;
    paddedFirst.resize(maxSize, 0);
    paddedSecond.resize(maxSize, 0);
    for (int i = maxSize - 1; i >= 0; --i) {
        if (paddedFirst[i] != paddedSecond[i]) {
            return paddedFirst[i] > paddedSecond[i];
        }
    }
    return false;
}

static std::vector<short> normalizedSummator(std::vector<short> bigger, std::vector<short> lower, bool isSubtraction) {
    std::vector<short> result;
    short sign = isSubtraction ? -1 : 1;
    int carry = 0;
    for (auto i = 0; i < bigger.size(); ++i) {
        int val2 = (i < lower.size()) ? lower[i] : 0;
        int total = bigger[i] + val2 * sign + carry;
        if (total >= 10) {
            result.push_back(total % 10);
            carry = total / 10;
        }
        else if (total < 0) {
            result.push_back(total + 10);
            carry = -1;
        }
        else {
            result.push_back(total);
            carry = 0;
        }
    }

    if (carry != 0) {
        result.push_back(carry);
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}

BigInt::BigInt(std::vector<short> value, bool sign) {
    this->value = value;
    this->sign = sign;
}

BigInt::BigInt(std::string str) {
    this->eval(str);
}

BigInt::BigInt(long long value) {
  this->sign = value >= 0;
  value = std::abs(value);
  long long numCount = 1;
  int prev = 0;
  while (value > numCount) {
    this->value.push_back((((value % (10 * numCount)) - prev)) / numCount);
    prev = value % (10 * numCount);
    numCount *= 10;
  }
};

std::string BigInt::toString() const {
  std::ostringstream oss;
  oss << (this->sign ? "" : "-");
  for (auto it = value.rbegin(); it != value.rend(); ++it) {
    oss << std::to_string(*it);
  };
  return oss.str();
}

void BigInt::eval(std::string str) {
    this->value = getValueFromString(str);
    if (str[0] == '-') {
        this->sign = false;
    }
    else {
        this->sign = true;
    }
};

double BigInt::toReal() const {
  if (value.size() >= 8) {
    throw std::runtime_error("Number too large");
  }
  double val = 0;
  int counter = 1;
  for (auto it = value.rbegin(); it != value.rend(); ++it) {
    val += *it * (counter);
    counter *= 10;
  };
  val *= this->sign ? 1 : -1;
  return val;
}

BigInt *BigInt::operator+(Number &other) {
  const BigInt& bigInt = dynamic_cast<const BigInt&>(other);
  bool isSubtraction = this->sign != bigInt.sign;
  std::vector<short> result;
  bool thisBigger = isFirstBigger(this->value, bigInt.value);
  bool sign;
  if (thisBigger) {
      result = normalizedSummator(this->value, bigInt.value, isSubtraction);
      sign = this->sign;
  } 
  else {
      result = normalizedSummator(bigInt.value, this->value, isSubtraction);
      sign = bigInt.sign;
  }
  return new BigInt(result, sign);
};

BigInt *BigInt::operator-(Number &other) {
  BigInt& bigInt = dynamic_cast<BigInt&>(other);
  bigInt.sign = !bigInt.sign;
  return this->operator+(bigInt);
}

BigInt *BigInt::operator*(Number &other) {
    const BigInt &bigInt = dynamic_cast<const BigInt &>(other);
    std::vector<short> result(this->value.size() + bigInt.value.size(), 0);

    for (int i = 0; i < this->value.size(); ++i) {
        int carry = 0;
        for (int j = 0; j < bigInt.value.size() || carry != 0; ++j) {
            long long current = result[i + j] + this->value[i] * (j < bigInt.value.size() ? bigInt.value[j] : 0) + carry;
            result[i + j] = current % 10;
            carry = current / 10;
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    bool resultSign = this->sign == bigInt.sign;
    return new BigInt(result, resultSign);
}

BigInt* BigInt::operator/(Number& other) {
    return new BigInt(this->toReal() / other.toReal());
};

BigInt* BigInt::operator*(long long& other) {
    bool resultSign = (other >= 0) == this->sign;
    long long absOther = std::abs(other);
    std::vector<short> result;
    long long carry = 0;
    for (size_t i = 0; i < this->value.size(); ++i) {
        long long product = this->value[i] * absOther + carry;
        result.push_back(product % 10);
        carry = product / 10;
    }
    while (carry > 0) {
        result.push_back(carry % 10);
        carry /= 10;
    }
    return new BigInt(result, resultSign);
}

BigInt* BigInt::operator+(long long& other) {
    BigInt* bigint = new BigInt(other);
    return *this + *bigint;
}

BigInt* BigInt::operator-(long long& other) {
    BigInt* bigint = new BigInt(other);
    return *this - *bigint;
}

BigInt* BigInt::operator/(long long& other) {
    BigInt* bigint = new BigInt(other);
    return *this / *bigint;
};

BigInt *BigInt::operator-() {
    return new BigInt(this->value, this->sign * -1);
}
