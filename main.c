#include "MyCalculator.h"



int main() {
    char sentence[SIZE] = ""; // 사용자 입력 문자열
    char result[SIZE] = ""; // 연산 결과 문자열
    char op = '\0'; // 연산 기호
    char my_op[2] = ""; // 연산 기호 문자열로 변경
    int time = 0; // 곱셈 계산 반복 횟수 저장용 변수
    int count = 0; // 나눗셈 계산 결과 저장용 변수
    char section[SIZE] = ""; // 섹션 배열
    char temp[SIZE] = ""; // 임시 배열


    //문자열 입력받기
    printf("문자열을 입력하세요: ");
    gets(sentence);


    //sentence에서 (의 수를 세어서 while문의 조건을 생성.
    int paren = 0;
    count_paren(sentence, &paren);


    //CALCULATE 매크로를 활용하여 이항/다항 계산 수행.
    CALCULATE(paren, sentence, result, my_op, op, &time, &count);


    return 0;
}
