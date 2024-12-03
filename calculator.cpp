//과제 6 12241457 박정민
/*후기 : 그동안 switch문의 case 부분을 중괄호를 이용해 작성하였는데 교수님의 조언을 받아 이게 잘못된 습관임을 알게 되었다
        본래 중괄호를 case문에 쓴 이유는 case안에서 중괄호를 써야 그 안에서 변수 선언이 가능하기에 사용하곤 했는데 그렇게 하는
        것 보다 변수를 바깥에서 선언하고 선언한 변수를 case문 안에 가져다 쓰는것이 다른이로 하여금 더 이해하기 쉽기에 중괄호를 지우고
        코드를 다시 짜보았다. 또한 선형탐색, 이진탐색, 삽입정렬의 알고리즘을 이해하고 직접 코드로 써보며 이에 대해 더 자세히
        알 수 있었다.*/

//설명문
        /*
        * 1.
            선형탐색은 배열의 첫 번째 요소부터 순차적으로 하나씩 비교하여 원하는 값을 찾는 방식이지만
            이진탐색은 배열이 정렬된 후 사용 가능한 탐색 방법으로, 중간 요소를 기준으로 탐색범위를 반씩
            줄여가며 찾는 방식이다.
            선형탐색은 시간복잡도가 O(n)이지만 이진탐색은 시간복잡도가 O(log n)이다.

          2.
            삽입정렬은 배열을 점차 정렬하는 방식으로, 정렬되지 않은 요소를 하나씩 꺼내 이미 정렬된 부분에 적절한
            위치에 삽입하는 알고리즘이다. 
           
        */
#include <iostream>
#include <cmath> //pow() 함수 쓰기위해 전처리과정에서 cmath 헤더파일 불러옴
#include <cstdlib> //rand() 함수 쓰기 위해 전처리과정에서 cstdlib 헤더파일 불러옴
#include <ctime> //srand() 함수 쓰기 위해 전처리과정에서 ctime 헤더파일 불러옴
using namespace std;

template <class T> //템플릿 함수 정의
T compare2Numbers(T num1, T num2) { //함수 매개 변수가 int일때와 double일때 둘다 동작
    if (num1 > num2)
        return num1;
    else if (num1 <= num2)
        return num2;
}
void inputNum1Num2(double& num1, double& num2);
void opCode5(double num1, double num2); //함수의 선언
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
void insertionSort(int intArray1[], int ARSIZE); //반환타입을 int[]로 하려 하였으나 안됨;
void printArray(int intArray1[], int ARSIZE);

enum OpCodes { EXIT = 0, ADD, SUB, MUL, DIV, MOD, EXP, RANDCOMP, FACTORIAL, ARRAYCOMP, SEARCH, SORT };

int main() {
    const int ARSIZE = 10; //ARSIZE 상수 정의
    OpCodes opCode;
    int input;
    double num1, num2;
    int intArray1[ARSIZE] = { 0 };
    int intArray2[ARSIZE] = { 0 };
    int resultArray[ARSIZE] = { 0 };
    int key;
    int low = 0;
    int pos;
    cout << "정보통신공학과 12241457 박정민 과제 7입니다" << endl;

    do
    {
        cout << "산술 연산 선택을 위한 정수(0~11, 0:반복종료) 입력 : ";
        cin >> input;
        while (true) {
            if (EXIT <= input <= RANDCOMP) {
                opCode = static_cast<OpCodes>(input);
                break;
            }
            else {
                cout << "연산자 입력 오류" << endl;
            }
        }
        if (opCode == EXIT) {
            break; // 이후 코드를 무시하고 반복문 탈출, 따라서 프로그램 종료
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
        
            cout << "정수를 입력하세요";
            cin >> num1;
            num1 = (int)num1;
            cout << "랜덤 생성된 배열 " << endl;
            generateArray(intArray1, ARSIZE, (int)num1);
            cout << endl << "원하는 키 값 입력 : ";
            cin >> key;
            pos = linearSearch(intArray1, ARSIZE, key);
            if (pos == -1)
                cout << key << "이(가) 배열에 없습니다!!" << endl;
            else
                cout << key << "이(가) 배열의 색인 " << pos << "에 있습니다!!" << endl;
            break;
        
        case SORT:
            cout << "정수를 입력하세요";
            cin >> num1;
            num1 = (int)num1;
            generateArray(intArray1, ARSIZE, (int)num1);
            insertionSort(intArray1, ARSIZE);
            cout << "정렬된 배열 " << endl;
            printArray(intArray1, ARSIZE);
            cout << endl << "원하는 키 값 입력 : ";
            cin >> key;
            pos = binarySearch(intArray1, low, ARSIZE, key);
            if (pos == -1)
                cout << key << "이(가) 배열에 없습니다!!" << endl;
            else
                cout << key << "이(가) 정렬된 배열의 색인 " << pos << "에 있습니다!!" << endl;
            break;
        
        default:
            cout << "연산자 입력 오류" << endl;
            continue; // 이후 코드를 무시하고 상위 반복문을 다시 실행
        }
    } while (true);
    return 0;
}

//함수의 정의
void inputNum1Num2(double& num1, double& num2) { //num1, num2에 실수를 입력받는 함수 정의
    cout << "첫번째 수를 입력하세요 :";
    cin >> num1;
    cout << "두번째 수를 입력하세요 :";
    cin >> num2;
}
void opCode5(double num1, double num2) {
    cout << "실수에 대해서는 나머지 연산 적용 불가" << endl;
    int intNum1 = (int)num1;
    int intNum2 = (int)num2;
    cout << intNum1 << " % " << intNum2 << " = " << intNum1 % intNum2 << endl;
}
void opCode6(double num1, double num2) {
    double sq = num1;
    num2 = fabs(num2); //opCode가 6일때 num2는 양의정수여야하므로 먼저 num2를 cmath 헤더파일에 포함된 절댓값으로 바꾸는 함수인 fabs()를 사용하여 양의정수로 변경
    int intNum2 = (int)num2; //정수형이 되어야 하므로 기존 double형이였던 변수 num2를 int형으로 캐스팅한다.
    if (num1 == 0 && intNum2 == 0) {
        cout << "0^0은 정의되지 않습니다." << endl;
    }
    else {
        for (int i = 1; i++, i <= intNum2;) {
            sq *= num1; //for문을 활용하여 제곱 구하기(for문을 활용해 구하는 이유는 기존 **연산자는 피연산변수가 모두 정수여야 하기 때문, 
            //하지만 num1은 double형이기에 실수의 제곱형태를 구하려면 for문을 활용해야한다)
        }
        if (intNum2 == 0) {
            sq = 1; //
        } //~의0승일 경우 항상 1이므로 sq값에 1 지정, 위 for문의 경우로 x^0=x라는 틀린값이 도출되므로 intNum2가 0일때 답이 1이되는 예외사항을 만들어줘야함
        cout << "for문 이용한 결과 : " << num1 << " ^ " << intNum2 << " = " << sq << endl;
        cout << "pow()쓴 결과 : " << num1 << " ^ " << intNum2 << " = " << pow(num1, intNum2) << endl;
        cout << "비교결과 : ";
        if (pow(num1, intNum2) == sq) {
            cout << "두 값이 같습니다" << endl;
        }
        else {
            cout << "두 값이 다릅니다" << endl;
        }
    }
}
void opCode7(double num1, double num2) {
    //srand(time(0)); //프로그램 재시작시 같은 시드로인해 같은 랜덤값이 나오는 오류 발견, 이를 해결 위해 현재 시간을 시드로 설정하여
                    //프로그램을 시작할때마다 시드가 바뀌도록함.(교수님께서 쓰지 말라 하셔서 주석처리함)
    int ranNum1 = rand() % ((int)num1 + 1);
    int ranNum2 = rand() % ((int)num2 + 1);

    int resultInt = compare2Numbers(ranNum1, ranNum2);
    double resultDouble = compare2Numbers(num1, num2);

    cout << "입력된 두 수 = " << num1 << ", " << num2 << endl;
    cout << "입력된 두 수 중 큰 수 = " << resultDouble << endl;
    cout << "랜덤 수 중 큰 수 = " << resultInt << endl;
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
int factorialLoop(int num1) { //반복문을 이용한 펙토리얼 구현

    int result = 1;
    for (int i = 1; i <= num1; i++) {
        result *= i;
    }
    return result;
}
int factorialRecursion(int num2) { //재귀함수를 이용한 펙토리얼 구현
    if (num2 <= 1) {
        return 1;
    }
    else {
        return num2 * factorialRecursion(num2 - 1);
    }
}

void generateArray(int intArray[], int ARSIZE, int num1) //10크기의 랜덤 정수 가진 배열 생성하는 함수
{
    for (int i = 0; i < ARSIZE; i++) {
        intArray[i] = rand() % (num1 + 1);
    }
    for (int i = 0; i < ARSIZE; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;
}


void compare2Array(int intArray1[], int intArray2[], int resultArray[], int ARSIZE)  //두 배열을 비교하는 함수
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
    for (int i = 0; i < ARSIZE; i++) { //배열 출력하는 함수
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

void printArray(int intArray1[], int ARSIZE) //배열을 출력하는 코드
{
    for (int i = 0; i < ARSIZE; i++) {
        cout << intArray1[i] << " ";
    }
    cout << endl;
    
}

int linearSearch(int intArray1[], int ARSIZE, int key) { //배열 선형탐색 코드
    for (int i = 0; i < ARSIZE; i++) {
        if (intArray1[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int intArray1[], int low , int ARSIZE, int key) { //배열 이진탐색 코드
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