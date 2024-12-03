//���� 6 12241457 ������
/*�ı� : �׵��� switch���� case �κ��� �߰�ȣ�� �̿��� �ۼ��Ͽ��µ� �������� ������ �޾� �̰� �߸��� �������� �˰� �Ǿ���
        ���� �߰�ȣ�� case���� �� ������ case�ȿ��� �߰�ȣ�� ��� �� �ȿ��� ���� ������ �����ϱ⿡ ����ϰ� �ߴµ� �׷��� �ϴ�
        �� ���� ������ �ٱ����� �����ϰ� ������ ������ case�� �ȿ� ������ ���°��� �ٸ��̷� �Ͽ��� �� �����ϱ� ���⿡ �߰�ȣ�� �����
        �ڵ带 �ٽ� ¥���Ҵ�. ���� ����Ž��, ����Ž��, ���������� �˰����� �����ϰ� ���� �ڵ�� �Ẹ�� �̿� ���� �� �ڼ���
        �� �� �־���.*/

//����
        /*
        * 1.
            ����Ž���� �迭�� ù ��° ��Һ��� ���������� �ϳ��� ���Ͽ� ���ϴ� ���� ã�� ���������
            ����Ž���� �迭�� ���ĵ� �� ��� ������ Ž�� �������, �߰� ��Ҹ� �������� Ž�������� �ݾ�
            �ٿ����� ã�� ����̴�.
            ����Ž���� �ð����⵵�� O(n)������ ����Ž���� �ð����⵵�� O(log n)�̴�.

          2.
            ���������� �迭�� ���� �����ϴ� �������, ���ĵ��� ���� ��Ҹ� �ϳ��� ���� �̹� ���ĵ� �κп� ������
            ��ġ�� �����ϴ� �˰����̴�. 
           
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
void generateArray(int intArray[], int ARSIZE, int num1);
void compare2Array(int intArray1[], int intArray2[], int resultArray[], int ARSIZE);
int linearSearch(int intArray1[], int ARSIZE, int key);
int binarySearch(int intArray1[], int low, int ARSIZE, int key);
void insertionSort(int intArray1[], int ARSIZE); //��ȯŸ���� int[]�� �Ϸ� �Ͽ����� �ȵ�;
void printArray(int intArray1[], int ARSIZE);

enum OpCodes { EXIT = 0, ADD, SUB, MUL, DIV, MOD, EXP, RANDCOMP, FACTORIAL, ARRAYCOMP, SEARCH, SORT };

int main() {
    const int ARSIZE = 10; //ARSIZE ��� ����
    OpCodes opCode;
    int input;
    double num1, num2;
    int intArray1[ARSIZE] = { 0 };
    int intArray2[ARSIZE] = { 0 };
    int resultArray[ARSIZE] = { 0 };
    int key;
    int low = 0;
    int pos;
    cout << "������Ű��а� 12241457 ������ ���� 7�Դϴ�" << endl;

    do
    {
        cout << "��� ���� ������ ���� ����(0~11, 0:�ݺ�����) �Է� : ";
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
        
            inputNum1Num2(num1, num2);
            opCode5(num1, num2);
            break;
        
        case EXP:
        
            inputNum1Num2(num1, num2);
            opCode6(num1, num2);
            break;
        
        case RANDCOMP:
        
            inputNum1Num2(num1, num2);
            opCode7(num1, num2);

            break;
        
        case FACTORIAL:
        
            inputNum1Num2(num1, num2);
            castAbsoulteValue(num1, num2);
            opCode8(num1, num2);
            break;
        
        case ARRAYCOMP:
        
            inputNum1Num2(num1, num2);
            generateArray(intArray1, ARSIZE, (int)num1);
            generateArray(intArray2, ARSIZE, (int)num2);
            compare2Array(intArray1, intArray2, resultArray, ARSIZE);

            break;
        
        case SEARCH:
        
            cout << "������ �Է��ϼ���";
            cin >> num1;
            num1 = (int)num1;
            cout << "���� ������ �迭 " << endl;
            generateArray(intArray1, ARSIZE, (int)num1);
            cout << endl << "���ϴ� Ű �� �Է� : ";
            cin >> key;
            pos = linearSearch(intArray1, ARSIZE, key);
            if (pos == -1)
                cout << key << "��(��) �迭�� �����ϴ�!!" << endl;
            else
                cout << key << "��(��) �迭�� ���� " << pos << "�� �ֽ��ϴ�!!" << endl;
            break;
        
        case SORT:
            cout << "������ �Է��ϼ���";
            cin >> num1;
            num1 = (int)num1;
            generateArray(intArray1, ARSIZE, (int)num1);
            insertionSort(intArray1, ARSIZE);
            cout << "���ĵ� �迭 " << endl;
            printArray(intArray1, ARSIZE);
            cout << endl << "���ϴ� Ű �� �Է� : ";
            cin >> key;
            pos = binarySearch(intArray1, low, ARSIZE, key);
            if (pos == -1)
                cout << key << "��(��) �迭�� �����ϴ�!!" << endl;
            else
                cout << key << "��(��) ���ĵ� �迭�� ���� " << pos << "�� �ֽ��ϴ�!!" << endl;
            break;
        
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

void generateArray(int intArray[], int ARSIZE, int num1) //10ũ���� ���� ���� ���� �迭 �����ϴ� �Լ�
{
    for (int i = 0; i < ARSIZE; i++) {
        intArray[i] = rand() % (num1 + 1);
    }
    for (int i = 0; i < ARSIZE; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;
}


void compare2Array(int intArray1[], int intArray2[], int resultArray[], int ARSIZE)  //�� �迭�� ���ϴ� �Լ�
{
    for (int i = 0; i < ARSIZE; i++) {
        if (intArray1[i] > intArray2[i]) {
            resultArray[i] = 1;
        }
        else if (intArray1[i] < intArray2[i]) {
            resultArray[i] = 2;
        }
        else
            resultArray[i] = 0;
    }
    for (int i = 0; i < ARSIZE; i++) { //�迭 ����ϴ� �Լ�
        cout << resultArray[i] << " ";
    }
    cout << endl;
}

void insertionSort(int intArray1[], int ARSIZE) { 
    int insert;
    for (int i = 1; i < ARSIZE; i++) {
        insert = intArray1[i];
        int moveItem = i;
        while ((moveItem > 0) && (intArray1[moveItem - 1] > insert)) {
            intArray1[moveItem] = intArray1[moveItem - 1];
            moveItem--;
        }
        intArray1[moveItem] = insert;
    }
}

void printArray(int intArray1[], int ARSIZE) //�迭�� ����ϴ� �ڵ�
{
    for (int i = 0; i < ARSIZE; i++) {
        cout << intArray1[i] << " ";
    }
    cout << endl;
    
}

int linearSearch(int intArray1[], int ARSIZE, int key) { //�迭 ����Ž�� �ڵ�
    for (int i = 0; i < ARSIZE; i++) {
        if (intArray1[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int intArray1[], int low , int ARSIZE, int key) { //�迭 ����Ž�� �ڵ�
    int high = ARSIZE - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (intArray1[mid] == key) {
            return mid;
        }
        else if (intArray1[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}