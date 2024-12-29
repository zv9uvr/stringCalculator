#include "MyCalculator.h"


//중간 결과 출력
void middle_output(char* sentence, int count, char op, int i) {

    //괄호 처리가 아직 남았다면 (어차피 문자열이 남아있으니)
    if (strchr(sentence, '(') != NULL) {
        printf("%d차 중간 결과: %s\n", i + 1, sentence);
    }

    //괄호 처리가 다 끝났다면 (숫자만 남았을 경우를 대비하여)
    else {
        if (op == '/') printf("%d차 중간 결과: %d\n", i + 1, count);
        else printf("%d차 중간 결과: %s\n", i + 1, sentence);
    }
    
}


//최종 결과 출력
void final_output(char* result, int count, char op) {
    if (op == '/') printf("최종 결과: %d\n", count);
    else printf("최종 결과: %s\n", result);
}