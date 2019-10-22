#include <stdio.h>
#include <stdlib.h>

#define SWAP1(a, b, type) \
    type temp = a;       \
    a = b;               \
    b = temp;

#define SWAP2(a, b, type) \
    do                  \
    {                   \
        type temp = a;  \
        a = b;          \
        b = temp;       \
    } while (0)
    

/*
    여기서 SWAP1 과 SWAP2의 중요한 차이점은

    SWAP1은 스코프 내부에 temp변수가 자동으로 올라가게 되어 다음 SWAP1을 호출시 중복된 식별자 에러가 날 수 있다.
    반면에 SWAP2는 do while 문 내부에서만 유효하게 되므로 중복된 식별자 에러가 나지 않는다.

    주의.. 그런 의미라면 그냥 스코프도 같은 역할을 하지 않느냐는 생각을 할 수도 있지만... 
    스코프를 쓰게되면 SWAP2(a, b, type)을 칠 때 세미콜론을 사용하게 되므로 에러를 발생시킨다.

    따라서 do while이 더미 스코프를 만들기 가장 적절하다.

    추가... 
        세미콜론은 사실 여러개가 붙어도 무방하다.. 
        
        C에서는 소스코드를 작성하는데 있어서 세미콜론을 명령행의 마침으로 보고, 
        토큰을 구분하는 화이트스페이스나 케리지 리턴, 개행등 문자는 전부 무시한다.

        세미콜론이 여러개 붙을경우 컴파일러는 빈 명령행 여러개가 있는 것 으로 보고 그냥 무시한다.
*/

int main(void)
{
    int a = 10;
    int b = 20;

    SWAP1(a, b, int);

    printf("%d %d \n", a, b);

    SWAP2(a, b, int);

    printf("%d %d \n", a, b);

    // 여기서 중복된 식별자 에러가 난다.
    // SWAP1(a, b, int);
}