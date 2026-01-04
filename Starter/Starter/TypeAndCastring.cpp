#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}
//매개변수가 정수형이라, 결과물인 C도 결과가 정수형이다.
float Devid(float a, float b)
{
	return a / b;
}

//실수를 확인하고 싶다 -> 0과 1사이에 값 -> 실제 물건을 나누었을때
void main()
{
	int a = 5;
	int b = 20;
	printf("Add: %d\n", Add(a, b));

	a = 1;
	b = 4;
	printf("Devid:%f\n",Devid((float)a, (float)b));
	//%f: float //캐스팅: 형변환 -> 다른타입의 값을 ()안에 타입으로 변경한다.
}
//롤 그레이브즈 평타 앞에 있는 유닛을 때리면 뒤에 있는 유닛도 데미지를 적게받는다.(스플래시)
//3 > 1.5
//A: 7 B: 8.5 -> 8
//A: 4 B: 7 -> 7
//일반적으로 오류가 없도록 처리하기위해서는 int보다는 float 값으로 많이 처리한다.
//정수형은 소수점이하를 버리기때문에 오차

//대학교에서는 계산기 왜 비싼걸쓸까?
//정밀도(Precision) -> 오차가 적다.
//double(배정밀도) -> float(단정밀도) -> long float(확장정밀도) -> decimal(고정소수점)
//정밀도가 높을수록 메모리를 많이 차지한다.