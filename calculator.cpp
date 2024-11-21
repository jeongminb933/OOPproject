//과제 5 12241457 박정민
/*후기 : 수업시간에 배운 함수 오버로딩과 재귀함수를 실습 해보았다. 본 코드에서는
        함수 오버로딩을 편리하고 안전하게 할 수 있도록 함수 탬플릿을 사용해보았다.
        펙토리얼을 재귀함수와 반복문으로 나눠 표현했는데 함수를 이런식으로 다르게 표현
        할수 있다는 점을 알게 되었고, 교수님께서 수업시간에 보여주신것 처럼 재귀함수와 반복문의
        시간복잡도가 차이가나 작업속도가 달라질 수 있다는 점을 염려하여 코드를 짤 때 선택을
        잘해야 겠단 생각이 들었다.*/
        /*설명문 :
        1) 탬플릿 함수의 필요성 및 사용의 장점
        탬플릿 함수는 함수를 정의할 때 데이터 타입에 구애받지 않고 일반화된 코드를 작성할 수 있게 해준다.
        이러한 템플릿 함수는 동일한 로직을 여러 데이터 타입에 대해 사용할 수 있어 코드 중복을 줄일 수 있으며,
        다양한 데이터 타입에 대해 동작할 수 있는 함수를 작성할 수 있어, 프로그램의 유연성과 확장성을 높일 수 있다.

        2) 반복 함수와 재귀 함수의 차이점
        반복 함수와 재귀 함수는 문제를 해결하는 방식에서 차이가 있다.

           - 반복 함수
             - 반복 구조(예: for, while)를 사용하여 특정 작업을 여러 번 수행한다.
             - 상태를 유지하며, 루프가 종료될 때까지 반복한다.
             - 일반적으로 메모리 사용이 적고, 스택 오버플로우의 위험이 없다.

           - 재귀 함수
             - 함수가 자기 자신을 호출하여 문제를 해결한다.
             - 기본적으로 문제를 더 작은 부분 문제로 나누어 해결하는 방식이다.
             - 각 호출마다 새로운 스택 프레임이 생성되므로, 깊은 재귀 호출이 발생할 경우 스택 오버플로우의 위험이 있다.

        이 두 가지 방법은 상황에 따라 적절히 선택하여 사용해야한다.

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
enum OpCodes { EXIT = 0, ADD, SUB, MUL, DIV, MOD, EXP, RANDCOMP, FACTORIAL };

int main() {
    OpCodes opCode;
    int input;
    double num1, num2;
    cout << "정보통신공학과 12241457 박정민 과제 5입니다" << endl;

    do
    {
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