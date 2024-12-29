#include "MyCalculator.h"


//��� ���� �Լ�
void calculate(char* pre_sen, char* next_sen, char op, char* result, int* time, int* count) {

    if (op == '+') {
        my_add(pre_sen, next_sen, result);
    }
    else if (op == '-') {
        my_sub(pre_sen, next_sen, result);
    }
    else if (op == '*') {
        //time(���ϴ� Ƚ��)�� a�� �迭���� �ƽ�Ű�ڵ� ������ Ȱ���Ͽ� int������ ��ȯ����
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




//���� �Լ�
void my_add(char* a, char* b, char* result) {
    result[0] = '\0';
    strcat(result, a);
    strcat(result, b);
}




//���� �Լ�
void my_sub(char* a, char* b, char* result) {
    result[0] = '\0';  //��� ���ڿ� �ʱ�ȭ
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




//���� �Լ�
void my_multiply(char* a, int b, char* result) {

    result[0] = '\0';  //��� ���ڿ� �ʱ�ȭ
    for (int i = 0; i < b; i++) {
        strcat(result, a);
    }
}




//������ �Լ�
void my_divide(char* a, char* b, int* count) {
    int result = 0;  //����� �ʱ�ȭ

    char* pos = strstr(a, b);
    while (pos != NULL) {
        result++;
        pos = strstr(pos + strlen(b), b); //���� ��ġ ���ķ� ��� �˻�
    }

    *count = result;
}
