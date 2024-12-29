#include "MyCalculator.h"


// '(' 개수 세기
void count_paren(char* sentence, int* paren) {
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == '(') (*paren)++;
    }
}


//이항 계산
void single_calculate(char* sentence, char* result, char* my_op, char op, int* time, int* count) {

    //연산 기호 찾기
    find_op(sentence, &op);


    //연산 기호 문자열화
    my_op[0] = op;
    my_op[1] = '\0';

    char a[SIZE] = "";
    char b[SIZE] = "";


    //연산자 기준으로 섹션 나누기
    char* token = strtok(sentence, my_op);
    strcpy(a, token);
    token = strtok(NULL, my_op);
    strcpy(b, token);


    //공백 제거
    char* pos = a;
    while (*pos == ' ') pos++;
    strcpy(a, pos);

    pos = b;
    while (*pos == ' ') pos++;
    strcpy(b, pos);


    //계산 수행
    calculate(a, b, op, result, &time, &count);


    //최종 결과 출력
    final_output(result, count, op);
}



//다항 계산
void multi_calculate(char* sentence, char* result, char* my_op, char op, int paren) {
    char section[SIZE]; // 섹션 배열
    char temp[SIZE]; // 임시 배열
    int time = 0; // 곱셈 횟수
    int count = 0; // 나눗셈 결과

    for (int i = 0; i < paren + 1; i++) {

        strcpy(section, ""); // section 초기화
        strcpy(my_op, ""); // my_op 초기화

        strcpy(temp, sentence); //임시 배열에 맨 처음 sentence 복사

        find_section(sentence, section); //섹션 찾기

        strcpy(sentence, temp); //바뀐 sentence에 temp(처음 sentence 복사본) 복사
        strcpy(temp, section); //임시 배열에 section 복사


        //연산 기호 찾기
        find_op(section, &op);


        //연산 기호 문자열화
        my_op[0] = op;
        my_op[1] = '\0';



        if (op != '\0') {
            char a[SIZE] = "";
            char b[SIZE] = "";


            //연산자 기준으로 섹션 나누기
            char* token = strtok(section, my_op);
            strcpy(a, token);
            token = strtok(NULL, my_op);
            strcpy(b, token);

            strcpy(section, temp);  // 섹션 복구


            //공백 제거
            char* pos = a;
            while (*pos == ' ') pos++;
            strcpy(a, pos);

            pos = b;
            while (*pos == ' ') pos++;
            strcpy(b, pos);


            //계산 수행
            calculate(a, b, op, result, &time, &count);


            //연산 기호에 따른 sentence 재구성
            new_sentence(sentence, section, my_op, result, &count);
        }

        //중간 결과 출력
        middle_output(sentence, count, op, i);
    }

    //최종 결과 출력
    final_output(result, count, op);
}
