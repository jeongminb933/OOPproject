//���� 5 12241457 ������
/*�ı� : �����ð��� ��� �Լ� �����ε��� ����Լ��� �ǽ� �غ��Ҵ�. �� �ڵ忡����
        �Լ� �����ε��� �����ϰ� �����ϰ� �� �� �ֵ��� �Լ� ���ø��� ����غ��Ҵ�.
        ���丮���� ����Լ��� �ݺ������� ���� ǥ���ߴµ� �Լ��� �̷������� �ٸ��� ǥ��
        �Ҽ� �ִٴ� ���� �˰� �Ǿ���, �����Բ��� �����ð��� �����ֽŰ� ó�� ����Լ��� �ݺ�����
        �ð����⵵�� ���̰��� �۾��ӵ��� �޶��� �� �ִٴ� ���� �����Ͽ� �ڵ带 © �� ������
        ���ؾ� �ڴ� ������ �����.*/
        /*������ :
        1) ���ø� �Լ��� �ʿ伺 �� ����� ����
        ���ø� �Լ��� �Լ��� ������ �� ������ Ÿ�Կ� ���ֹ��� �ʰ� �Ϲ�ȭ�� �ڵ带 �ۼ��� �� �ְ� ���ش�.
        �̷��� ���ø� �Լ��� ������ ������ ���� ������ Ÿ�Կ� ���� ����� �� �־� �ڵ� �ߺ��� ���� �� ������,
        �پ��� ������ Ÿ�Կ� ���� ������ �� �ִ� �Լ��� �ۼ��� �� �־�, ���α׷��� �������� Ȯ�强�� ���� �� �ִ�.

        2) �ݺ� �Լ��� ��� �Լ��� ������
        �ݺ� �Լ��� ��� �Լ��� ������ �ذ��ϴ� ��Ŀ��� ���̰� �ִ�.

           - �ݺ� �Լ�
             - �ݺ� ����(��: for, while)�� ����Ͽ� Ư�� �۾��� ���� �� �����Ѵ�.
             - ���¸� �����ϸ�, ������ ����� ������ �ݺ��Ѵ�.
             - �Ϲ������� �޸� ����� ����, ���� �����÷ο��� ������ ����.

           - ��� �Լ�
             - �Լ��� �ڱ� �ڽ��� ȣ���Ͽ� ������ �ذ��Ѵ�.
             - �⺻������ ������ �� ���� �κ� ������ ������ �ذ��ϴ� ����̴�.
             - �� ȣ�⸶�� ���ο� ���� �������� �����ǹǷ�, ���� ��� ȣ���� �߻��� ��� ���� �����÷ο��� ������ �ִ�.

        �� �� ���� ����� ��Ȳ�� ���� ������ �����Ͽ� ����ؾ��Ѵ�.

        */
#include <iostream>
#include <cmath> //pow() �Լ� �������� ��ó���������� cmath ������� �ҷ���
#include <cstdlib> //rand() �Լ� ���� ���� ��ó���������� cstdlib ������� �ҷ���
#include <ctime> //srand() �Լ� ���� ���� ��ó���������� ctime ������� �ҷ���
using namespace std;

template <class T> //���ø� �Լ� ����
T compare2Numbers(T num1, T num2) { //�Լ� �Ű� ������ int�϶��� double�϶� �Ѵ� ����
    if (num1 > num2)
        return num1;
    else if (num1 <= num2)
        return num2;
}
void inputNum1Num2(double& num1, double& num2);
void opCode5(double num1, double num2); //�Լ��� ����
void opCode6(double num1, double num2);
void opCode7(double num1, double num2);
void opCode8(int num1, int num2);
void castAbsoulteValue(double& num1, double& num2);
int factorialLoop(int num1);
int factorialRecursion(int num2);
enum OpCodes { EXIT = 0, ADD, SUB, MUL, DIV, MOD, EXP, RANDCOMP, FACTORIAL };

int main() {
    OpCodes opCode;
    int input;
    double num1, num2;
    cout << "������Ű��а� 12241457 ������ ���� 5�Դϴ�" << endl;

    do
    {
        cin >> input;
        while (true) {
            if (EXIT <= input <= RANDCOMP) {
                opCode = static_cast<OpCodes>(input);
                break;
            }
            else {
                cout << "������ �Է� ����" << endl;
            }
        }
        if (opCode == EXIT) {
            break; // ���� �ڵ带 �����ϰ� �ݺ��� Ż��, ���� ���α׷� ����
        }
        switch (opCode) {

        case ADD:
            inputNum1Num2(num1, num2);
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case SUB:
            inputNum1Num2(num1, num2);
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case MUL:
            inputNum1Num2(num1, num2);
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case DIV:
            inputNum1Num2(num1, num2);
            cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            break;
        case MOD:
        {
            inputNum1Num2(num1, num2);
            opCode5(num1, num2);
            break;
        }
        case EXP:
        {
            inputNum1Num2(num1, num2);
            opCode6(num1, num2);
            break;
        }
        case RANDCOMP:
        {
            inputNum1Num2(num1, num2);
            opCode7(num1, num2);

            break;
        }
        case FACTORIAL:
        {
            inputNum1Num2(num1, num2);
            castAbsoulteValue(num1, num2);
            opCode8(num1, num2);
            break;
        }
        default:
            cout << "������ �Է� ����" << endl;
            continue; // ���� �ڵ带 �����ϰ� ���� �ݺ����� �ٽ� ����
        }
    } while (true);
    return 0;
}

//�Լ��� ����
void inputNum1Num2(double& num1, double& num2) { //num1, num2�� �Ǽ��� �Է¹޴� �Լ� ����
    cout << "ù��° ���� �Է��ϼ��� :";
    cin >> num1;
    cout << "�ι�° ���� �Է��ϼ��� :";
    cin >> num2;
}
void opCode5(double num1, double num2) {
    cout << "�Ǽ��� ���ؼ��� ������ ���� ���� �Ұ�" << endl;
    int intNum1 = (int)num1;
    int intNum2 = (int)num2;
    cout << intNum1 << " % " << intNum2 << " = " << intNum1 % intNum2 << endl;
}
void opCode6(double num1, double num2) {
    double sq = num1;
    num2 = fabs(num2); //opCode�� 6�϶� num2�� �������������ϹǷ� ���� num2�� cmath ������Ͽ� ���Ե� �������� �ٲٴ� �Լ��� fabs()�� ����Ͽ� ���������� ����
    int intNum2 = (int)num2; //�������� �Ǿ�� �ϹǷ� ���� double���̿��� ���� num2�� int������ ĳ�����Ѵ�.
    if (num1 == 0 && intNum2 == 0) {
        cout << "0^0�� ���ǵ��� �ʽ��ϴ�." << endl;
    }
    else {
        for (int i = 1; i++, i <= intNum2;) {
            sq *= num1; //for���� Ȱ���Ͽ� ���� ���ϱ�(for���� Ȱ���� ���ϴ� ������ ���� **�����ڴ� �ǿ��꺯���� ��� �������� �ϱ� ����, 
            //������ num1�� double���̱⿡ �Ǽ��� �������¸� ���Ϸ��� for���� Ȱ���ؾ��Ѵ�)
        }
        if (intNum2 == 0) {
            sq = 1; //
        } //~��0���� ��� �׻� 1�̹Ƿ� sq���� 1 ����, �� for���� ���� x^0=x��� Ʋ������ ����ǹǷ� intNum2�� 0�϶� ���� 1�̵Ǵ� ���ܻ����� ����������
        cout << "for�� �̿��� ��� : " << num1 << " ^ " << intNum2 << " = " << sq << endl;
        cout << "pow()�� ��� : " << num1 << " ^ " << intNum2 << " = " << pow(num1, intNum2) << endl;
        cout << "�񱳰�� : ";
        if (pow(num1, intNum2) == sq) {
            cout << "�� ���� �����ϴ�" << endl;
        }
        else {
            cout << "�� ���� �ٸ��ϴ�" << endl;
        }
    }
}
void opCode7(double num1, double num2) {
    //srand(time(0)); //���α׷� ����۽� ���� �õ������ ���� �������� ������ ���� �߰�, �̸� �ذ� ���� ���� �ð��� �õ�� �����Ͽ�
                    //���α׷��� �����Ҷ����� �õ尡 �ٲ����.(�����Բ��� ���� ���� �ϼż� �ּ�ó����)
    int ranNum1 = rand() % ((int)num1 + 1);
    int ranNum2 = rand() % ((int)num2 + 1);

    int resultInt = compare2Numbers(ranNum1, ranNum2);
    double resultDouble = compare2Numbers(num1, num2);

    cout << "�Էµ� �� �� = " << num1 << ", " << num2 << endl;
    cout << "�Էµ� �� �� �� ū �� = " << resultDouble << endl;
    cout << "���� �� �� ū �� = " << resultInt << endl;
}

void opCode8(int num1, int num2) {
    cout << "Factorial(" << (int)num1 << ") = " << factorialLoop((int)num1) << endl;
    cout << "Factorial(" << (int)num2 << ") = " << factorialRecursion((int)num2) << endl;
}
void castAbsoulteValue(double& num1, double& num2)
{
    num1 = (int)num1;
    if (num1 < 0) {
        num1 = -num1;
    }
    num2 = (int)num2;
    if (num2 < 0)
    {
        num2 = -num2;
    }
}
int factorialLoop(int num1) { //�ݺ����� �̿��� ���丮�� ����

    int result = 1;
    for (int i = 1; i <= num1; i++) {
        result *= i;
    }
    return result;
}
int factorialRecursion(int num2) { //����Լ��� �̿��� ���丮�� ����
    if (num2 <= 1) {
        return 1;
    }
    else {
        return num2 * factorialRecursion(num2 - 1);
    }
}