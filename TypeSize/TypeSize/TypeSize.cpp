#include <stdio.h>
//함수의 선언: 함수의 이름과 내용을 컴파일러 에게 알려주는 것. 항상 컴파일러가 존재를 알아야하므로, 인클루드와 메인사이에 함수가 있어야한다.
//ㄴ함수의 정의와 선언을 나누는 방법이 있음.(추후에 다룸)
//형태(형): 모양? 그릇의 종류. 이런 종류의 여러그릇들이 있음.
void SizeofTypes()
{
	printf("Size of char: %zu byte(s)\n", sizeof(char));
	printf("Size of short: %zu byte(s)\n", sizeof(short));
	printf("Size of int: %zu byte(s)\n", sizeof(int));
	printf("Size of long: %zu byte(s)\n", sizeof(long));
	printf("Size of long long: %zu byte(s)\n", sizeof(long long));
	printf("Size of float: %zu byte(s)\n", sizeof(float));
	printf("Size of double: %zu byte(s)\n", sizeof(double));
	printf("Size of long double: %zu byte(s)\n", sizeof(long double));
}
//변수: 값을 담는 그릇. 각 종류의 그릇을 1개씩 제작하였음.
void SizeofDataValueTypes()
{
	//변수의 선언: 값을 담는 그릇을 만드는데 이름을 지정함. 여기에서 이름은 이변수에 들어갈 대표적인 것을 상징함.
	//ㄴ굳이 이름에 맞지않는 값을 넣어도되지만, 코드를 짜는 중에 혼란을 줄수있기때문에 권장하지않음.
	//예) 그러나 fPi,dPi는 값을 변경하면 안됨. 이유는 파이의 값은 정해져있기때문이다.
	//ㄴ그래서 상수라는 개념이 존제하며 변수앞에 const를 붙이면 변수의 값을 변경할수없게 만든다.
	char cChar = 'Z';
	short sShort = 2^16;
	int iInt = 200;
	long lLong = 5000L;
	long long longLong = 60000LL;
	//상수(constant): 값을 담는 그릇이지만, 값을 변경할수없는 그릇.
	const float fPi = 3.14f;
	const double dPi = 3.14159;

	//변수는 값을 담는 그릇이므로, 저장된 값을 실행중에 변경이 가능하다.
	cChar = 'z';
	sShort = 32767;
	iInt = -200;
	lLong = -5000L;
	longLong = -60000LL;

	//상수로 변경하면 컴파일러가 값을 바꾸려할때 오류를 만들어서 빌드 할 수 없게 한다. 
	//-> 물리법칙을 바꿀수없는 세계 -> 컴파일러는 신과 같음. -> 신의 법칙을 프로그래머가 설계함
	//바꿔도 되나?? 파이의 값은 바꾸면 안됨. 값이 다르다면 이세계사람임. 세상에 물리법칙이 달라 완전히 다른세계가 될수있다.
	//fPi = 000000;
	//dPi = 233213321;

	printf("Size of cChar:%c/%zu byte(s)\n", cChar, sizeof(cChar));
	printf("Size of sShort:%d/%zu byte(s)\n", sShort, sizeof(sShort));
	printf("Size of iInt:%d/%zu byte(s)\n", iInt, sizeof(iInt));
	printf("Size of lLong:%ld/%zu byte(s)\n", lLong, sizeof(lLong));
	printf("Size of longLong:%lld/%zu byte(s)\n", longLong, sizeof(longLong));

	printf("Size of fPi:%f/%zu byte(s)\n", fPi, sizeof(fPi));
	printf("Size of dPi:%lf/%zu byte(s)\n", dPi, sizeof(dPi));
}

//문자는 아스키코드로 구성되어있다. 256개의 문자표현이 가능하다.(0~255) -> 1byte
void ASCIICharacterExample()
{
	unsigned char cChar = 0; //
	
	//수업이 금요일은 마지막 날이니까 놀아야지 //1
	while (true)//일단 돌려	
	{
		printf("[%c]%d, ", cChar, cChar);
		cChar++;
		if (cChar >= 255) //256번이 되면 멈춰
		{
			break;
		}
	}

	//오늘 월요일이니까 수업이 있네, ~ 화,수,목,~ 오늘 금요일이니까 놀아야지. //5
	cChar = 0; //다시 0으로 초
	while (cChar < 256) //256보다 작을때까지 돌려
	{
		printf("[%c]%d, ", cChar, cChar);
		cChar++;
	}
	
	////256번을 붙여넣으면 너무 힘들다.
	//printf("printf: %c/%d\n", cChar, cChar);
	//cChar++;

	//printf("printf: %c/%d\n", cChar, cChar);
	//cChar++;

	//printf("printf: %c/%d\n", cChar, cChar);
	//cChar++;

	//printf("printf: %c/%d\n", cChar, cChar);
	//cChar++;
	
}	

void main()
{
	//SizeofTypes();
	//SizeofDataValueTypes();
	ASCIICharacterExample();
}