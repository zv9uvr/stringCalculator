#include "MyCalculator.h"



int main() {
    char sentence[SIZE] = ""; // ����� �Է� ���ڿ�
    char result[SIZE] = ""; // ���� ��� ���ڿ�
    char op = '\0'; // ���� ��ȣ
    char my_op[2] = ""; // ���� ��ȣ ���ڿ��� ����
    int time = 0; // ���� ��� �ݺ� Ƚ�� ����� ����
    int count = 0; // ������ ��� ��� ����� ����
    char section[SIZE] = ""; // ���� �迭
    char temp[SIZE] = ""; // �ӽ� �迭


    //���ڿ� �Է¹ޱ�
    printf("���ڿ��� �Է��ϼ���: ");
    gets(sentence);


    //sentence���� (�� ���� ��� while���� ������ ����.
    int paren = 0;
    count_paren(sentence, &paren);


    //CALCULATE ��ũ�θ� Ȱ���Ͽ� ����/���� ��� ����.
    CALCULATE(paren, sentence, result, my_op, op, &time, &count);


    return 0;
}
