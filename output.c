#include "MyCalculator.h"


//�߰� ��� ���
void middle_output(char* sentence, int count, char op, int i) {

    //��ȣ ó���� ���� ���Ҵٸ� (������ ���ڿ��� ����������)
    if (strchr(sentence, '(') != NULL) {
        printf("%d�� �߰� ���: %s\n", i + 1, sentence);
    }

    //��ȣ ó���� �� �����ٸ� (���ڸ� ������ ��츦 ����Ͽ�)
    else {
        if (op == '/') printf("%d�� �߰� ���: %d\n", i + 1, count);
        else printf("%d�� �߰� ���: %s\n", i + 1, sentence);
    }
    
}


//���� ��� ���
void final_output(char* result, int count, char op) {
    if (op == '/') printf("���� ���: %d\n", count);
    else printf("���� ���: %s\n", result);
}