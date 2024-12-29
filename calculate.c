#include "MyCalculator.h"


//계산 수행 함수
void calculate(char* pre_sen, char* next_sen, char op, char* result, int* time, int* count) {

    if (op == '+') {
        my_add(pre_sen, next_sen, result);
    }
    else if (op == '-') {
        my_sub(pre_sen, next_sen, result);
    }
    else if (op == '*') {
        //time(곱하는 횟수)을 a의 배열값과 아스키코드 연산을 활용하여 int형으로 변환해줌
        int i = 0;
        if (next_sen != NULL && *next_sen != ' ') {
            i = atoi(next_sen);
        }
        *time = i;
        my_multiply(pre_sen, *time, result);
    }
    else if (op == '/') {
        my_divide(pre_sen, next_sen, count);
    }
}




//덧셈 함수
void my_add(char* a, char* b, char* result) {
    result[0] = '\0';
    strcat(result, a);
    strcat(result, b);
}




//뺄셈 함수
void my_sub(char* a, char* b, char* result) {
    result[0] = '\0';  //결과 문자열 초기화
    char* pos = strstr(a, b);
    if (pos != NULL) {
        int len = strlen(b);
        strncpy(result, a, pos - a);
        result[pos - a] = '\0';
        strcat(result, pos + len);
    }
    else {
        strcpy(result, a);
    }
}




//곱셈 함수
void my_multiply(char* a, int b, char* result) {

    result[0] = '\0';  //결과 문자열 초기화
    for (int i = 0; i < b; i++) {
        strcat(result, a);
    }
}




//나눗셈 함수
void my_divide(char* a, char* b, int* count) {
    int result = 0;  //결과값 초기화

    char* pos = strstr(a, b);
    while (pos != NULL) {
        result++;
        pos = strstr(pos + strlen(b), b); //현재 위치 이후로 계속 검색
    }

    *count = result;
}
