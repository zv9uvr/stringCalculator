#include "MyCalculator.h"


// '(' ���� ����
void count_paren(char* sentence, int* paren) {
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == '(') (*paren)++;
    }
}


//���� ���
void single_calculate(char* sentence, char* result, char* my_op, char op, int* time, int* count) {

    //���� ��ȣ ã��
    find_op(sentence, &op);


    //���� ��ȣ ���ڿ�ȭ
    my_op[0] = op;
    my_op[1] = '\0';

    char a[SIZE] = "";
    char b[SIZE] = "";


    //������ �������� ���� ������
    char* token = strtok(sentence, my_op);
    strcpy(a, token);
    token = strtok(NULL, my_op);
    strcpy(b, token);


    //���� ����
    char* pos = a;
    while (*pos == ' ') pos++;
    strcpy(a, pos);

    pos = b;
    while (*pos == ' ') pos++;
    strcpy(b, pos);


    //��� ����
    calculate(a, b, op, result, &time, &count);


    //���� ��� ���
    final_output(result, count, op);
}



//���� ���
void multi_calculate(char* sentence, char* result, char* my_op, char op, int paren) {
    char section[SIZE]; // ���� �迭
    char temp[SIZE]; // �ӽ� �迭
    int time = 0; // ���� Ƚ��
    int count = 0; // ������ ���

    for (int i = 0; i < paren + 1; i++) {

        strcpy(section, ""); // section �ʱ�ȭ
        strcpy(my_op, ""); // my_op �ʱ�ȭ

        strcpy(temp, sentence); //�ӽ� �迭�� �� ó�� sentence ����

        find_section(sentence, section); //���� ã��

        strcpy(sentence, temp); //�ٲ� sentence�� temp(ó�� sentence ���纻) ����
        strcpy(temp, section); //�ӽ� �迭�� section ����


        //���� ��ȣ ã��
        find_op(section, &op);


        //���� ��ȣ ���ڿ�ȭ
        my_op[0] = op;
        my_op[1] = '\0';



        if (op != '\0') {
            char a[SIZE] = "";
            char b[SIZE] = "";


            //������ �������� ���� ������
            char* token = strtok(section, my_op);
            strcpy(a, token);
            token = strtok(NULL, my_op);
            strcpy(b, token);

            strcpy(section, temp);  // ���� ����


            //���� ����
            char* pos = a;
            while (*pos == ' ') pos++;
            strcpy(a, pos);

            pos = b;
            while (*pos == ' ') pos++;
            strcpy(b, pos);


            //��� ����
            calculate(a, b, op, result, &time, &count);


            //���� ��ȣ�� ���� sentence �籸��
            new_sentence(sentence, section, my_op, result, &count);
        }

        //�߰� ��� ���
        middle_output(sentence, count, op, i);
    }

    //���� ��� ���
    final_output(result, count, op);
}
