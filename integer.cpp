#include "integer.hpp"

// 생성자
MyInteger::MyInteger(int input): value(input) { };
MyInteger::MyInteger(const MyInteger& input): value(input.value) { };


// 디버깅용
int MyInteger::getValue() {
    return this->value;
}
void MyInteger::setValue(int input) {
    this->value = input;
}