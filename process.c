#include "MyCalculator.h"


//연산기호 찾기
void find_op(char* sentence, char* op) {
    char op_list[] = "+-*/";
    int i = 0;

    do {
        char* pos = strchr(sentence, op_list[i]);
        if (pos != NULL) {
            *op = op_list[i];
            break;
        }
        i++;
    } while (i < sizeof(op_list) - 1);
}





//괄호 내 가장 먼저 처리해야 할 섹션 찾기
void find_section(char* sentence, char* section) {
    char save[SIZE][SIZE];
    int index = 0;


    //괄호를 기준으로 나누고 저장하기
    char* token = strtok(sentence, "()");
    while (token != NULL) {
        strcpy(save[index], token); //계산용 

        //저장된 save의 내용 앞뒤 공백 제거 => ( programming + c ) . . . (programming + c)
        char* front = save[index];
        while (*front == ' ') front++;
        strcpy(save[index], front);

        char* back = save[index] + strlen(save[index]) - 1;
        while (*back == ' ') {
            *back = '\0';
            back--;
        }

        index++;

        token = strtok(NULL, "()");
    }


    //가장 먼저 계산할 섹션 탐색
    for (int i = 0; i < index; i++) {
        char op_list[] = "+-*/";

        char first = save[i][0]; //save의 첫 번째 문자
        char last = save[i][strlen(save[i]) - 1]; //save의 마지막 문자


        //양쪽 끝 문자가 연산 기호인지 확인하기
        int j = 0;
        int condition = 1; //section에 저장할 조건(condition)
        do {
            //save의 양끝에 모두 연산기호가 없어야 하므로 역을 이용
            if (first == op_list[j] || last == op_list[j]) {
                condition = 0; //만약 if문을 충족시켰다면, 우선순위에 해당하는 조건을 만족시키지 못함.
                break;
            }
            j++;
        } while (op_list[j] != '\0'); //+-*/ 다 비교하기


        //조건을 충족시켰다면 section에 저장
        if (condition) strcpy(section, save[i]); 

    }
}









//sentence 재구성 함수
void new_sentence(char* sentence, char* section, char* my_op, char* result, int* count) {
    char a[SIZE] = ""; //section 이전 문자열
    char b[SIZE] = "";  //section 이후 문자열

    //섹션 위치 찾기
    char* start = strstr(sentence, section);
    
    //만약 sentence에서 섹션의 시작주소를 찾았고, 그 앞의 문자가 '('라면 ...
    if ((start != NULL) && (*(start - 1) == '(')) {
        char* end = start + strlen(section); //섹션 끝 위치
        if (*end == ')') {                   //')' 포함 여부 확인
            start--; //section에 '(' 포함
            end++;   //section에 ')' 포함
        }


        //섹션 이전 부분 복사
        strncpy(a, sentence, start - sentence);
        a[start - sentence] = '\0';

        //섹션 이후 부분 복사
        strcpy(b, end);

        //sentence 재구성
        strcpy(sentence, a);    //섹션 이전 부분
        if (my_op == "/") strcat(sentence, count);   //결과 문자열
        else strcat(sentence, result);   //결과 문자열
        strcat(sentence, b);    //섹션 이후 부분
    }
}
