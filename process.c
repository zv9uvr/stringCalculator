#include "MyCalculator.h"


//�����ȣ ã��
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





//��ȣ �� ���� ���� ó���ؾ� �� ���� ã��
void find_section(char* sentence, char* section) {
    char save[SIZE][SIZE];
    int index = 0;


    //��ȣ�� �������� ������ �����ϱ�
    char* token = strtok(sentence, "()");
    while (token != NULL) {
        strcpy(save[index], token); //���� 

        //����� save�� ���� �յ� ���� ���� => ( programming + c ) . . . (programming + c)
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


    //���� ���� ����� ���� Ž��
    for (int i = 0; i < index; i++) {
        char op_list[] = "+-*/";

        char first = save[i][0]; //save�� ù ��° ����
        char last = save[i][strlen(save[i]) - 1]; //save�� ������ ����


        //���� �� ���ڰ� ���� ��ȣ���� Ȯ���ϱ�
        int j = 0;
        int condition = 1; //section�� ������ ����(condition)
        do {
            //save�� �糡�� ��� �����ȣ�� ����� �ϹǷ� ���� �̿�
            if (first == op_list[j] || last == op_list[j]) {
                condition = 0; //���� if���� �������״ٸ�, �켱������ �ش��ϴ� ������ ������Ű�� ����.
                break;
            }
            j++;
        } while (op_list[j] != '\0'); //+-*/ �� ���ϱ�


        //������ �������״ٸ� section�� ����
        if (condition) strcpy(section, save[i]); 

    }
}









//sentence �籸�� �Լ�
void new_sentence(char* sentence, char* section, char* my_op, char* result, int* count) {
    char a[SIZE] = ""; //section ���� ���ڿ�
    char b[SIZE] = "";  //section ���� ���ڿ�

    //���� ��ġ ã��
    char* start = strstr(sentence, section);
    
    //���� sentence���� ������ �����ּҸ� ã�Ұ�, �� ���� ���ڰ� '('��� ...
    if ((start != NULL) && (*(start - 1) == '(')) {
        char* end = start + strlen(section); //���� �� ��ġ
        if (*end == ')') {                   //')' ���� ���� Ȯ��
            start--; //section�� '(' ����
            end++;   //section�� ')' ����
        }


        //���� ���� �κ� ����
        strncpy(a, sentence, start - sentence);
        a[start - sentence] = '\0';

        //���� ���� �κ� ����
        strcpy(b, end);

        //sentence �籸��
        strcpy(sentence, a);    //���� ���� �κ�
        if (my_op == "/") strcat(sentence, count);   //��� ���ڿ�
        else strcat(sentence, result);   //��� ���ڿ�
        strcat(sentence, b);    //���� ���� �κ�
    }
}
