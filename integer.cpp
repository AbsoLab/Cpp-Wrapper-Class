#include "integer.hpp"
#include <iostream>
// 생성자
MyInteger::MyInteger(int input): value(input) { };
MyInteger::MyInteger(const MyInteger& input): value(input.value) { };

// 메소드
string MyInteger::to_string() {
    return to_string(10);
}
string MyInteger::to_string(const int notation) {

    // 잘못된 입력 처리
    if ( notation < 2 || 16 < notation ) {
        return NULL;
    }

    string result = "";
    string revers_result = "";
    int value = this->value;
    int i_temp;

    while (value != 0) {

        i_temp = value % notation;

        
        if (0 <= i_temp && i_temp < 10) {

            result += '0' + i_temp;

        // 11진수 이상 문자 처리
        } else {

            switch(i_temp) {
            case 10:
                result += 'A';
                break;
            case 11:
                result += 'B';
                break;
            case 12:
                result += 'C';
                break;
            case 13:
                result += 'D';
                break;
            case 14:
                result += 'E';
                break;
            case 15:
                result += 'F';
                break;
            }
        }

        value /= notation;
    }

    // 문자열 뒤집기
    for (int i=result.size()-1; i >= 0; --i) {
        revers_result += result[i];
    }

    return revers_result;
}

int MyInteger::parseInt(const string str) {
    return parseInt(str, 10);
}
int MyInteger::parseInt(const string str, const int notation) {

    int result = 0;

    for (int i=0; i<str.size(); ++i) {

        char ch_num = str[i];
        int num;

        if ('0' <= ch_num && ch_num <= '9') {

            num = ch_num - '0';

        } else {    // 'A' ~ 'F', 'a' ~ 'f'

            if (ch_num == 'A' || ch_num == 'a') {

                num = 10;

            } else if (ch_num == 'B' || ch_num == 'b') {

                num = 11;

            } else if (ch_num == 'C' || ch_num == 'c') {

                num = 12;

            } else if (ch_num == 'D' || ch_num == 'd') {

                num = 13;

            } else if (ch_num == 'E' || ch_num == 'e') {

                num = 14;

            } else { // if (ch_num == 'F' || ch_num == 'f') {

                num = 15;
            }
        }

        result *= notation;
        result += num;
    }

    return result;
}

// 디버깅용
int MyInteger::getValue() {
    return this->value;
}
void MyInteger::setValue(int input) {
    this->value = input;
}