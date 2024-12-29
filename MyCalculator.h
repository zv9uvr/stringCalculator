#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 500    //문자열 크기
#define CALCULATE(paren, sentence, result, my_op, op, time, count) \
    if ((paren) == 0) \
        single_calculate(sentence, result, my_op, op, time, count); \
    else if ((paren) > 0) \
        multi_calculate(sentence, result, my_op, op, paren);


//함수 선언
void count_paren(char* sentence, int* paren);
void single_calculate(char* sentence, char* result, char* my_op, char op, int* time, int* count);
void multi_calculate(char* sentence, char* result, char* my_op, char op, int paren);
void find_op(char* sentence, char* op);
void find_section(char* sentence, char* section);
void calculate(char* pre_sen, char* next_sen, char op, char* result, int* time, int* count);
void my_add(char* a, char* b, char* result);
void my_sub(char* a, char* b, char* result);
void my_multiply(char* a, int b, char* result);
void my_divide(char* a, char* b, int* count);
void new_sentence(char* sentence, char* section, char* op, char* result, int* count);
void middle_output(char* sentence, int count, char op, int i);
void final_output(char* result, int count, char op);

#endif