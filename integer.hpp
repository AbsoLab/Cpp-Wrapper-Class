#pragma once

#include <string>
using namespace std;
// int의 wrapper class
/*
    구현 할 기능
    1. toString()
    2. x진법으로 출력: toString(2) 2진법
    3. 문자열을 int로: parseInt(), parseInt(2) 2진법
    4. 연산자 오버로딩
    5. int로 형 변환이 자유
    6. cout, printf로 출력 가능
*/

class MyInteger {

// 변수
private:
    int value;

// 생성자
public:
    MyInteger(int);
    MyInteger(const MyInteger&);

// 메소드
public:
    string to_string();
    string to_string(int);  // 2 ~ 16 진수만 지원

// 디버깅용
public:
    int getValue();
    void setValue(int);

};