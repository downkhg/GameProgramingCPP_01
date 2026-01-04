#include <stdio.h>
#include <string.h>
#include <Windows.h>

//구조체: 변수를 모아서 한꺼번에 이해하기 쉽도록 정리된것.
struct Status
{
	int id;
	//enum: 숫자대신에 사용하여 이 타입이나 한정된것이 어떤의미인지 이해하기 쉽도록 정의 되는 타입
	enum Type
	{
		Fire,
		Water,
		Grass,
		Electric,
		Psychic,
		Normal
	};
	
	Type type;
	char name[50];//이름으로 50자정도 저장이 가능하다
	int hp; //최대체력
	int attack;
	int defense;
	int speed;
	int attack_s;
	int defense_s;
};
//객체: 변수한개로 대상을 나타낼수없어, 묶어서 표현하는것(class, struct)
class Pokemon
{
public:
	int id;
	char name[50];

	int curHp;//현재체력
	int curPP;
	int lv;
	int exp;
	int maxExp;

	Status status;

public:
	Pokemon(int _id, const char* _name, Status status) //생성자: 객체가 초기화될때 각 멤버를 어떻게 초기할리 결정하는 함수
		: id(_id), lv(1), exp(0), maxExp(100)
	{
		strcpy(name, _name);//문자열 복사
		// Initialize other members as needed
		curHp = status.hp;
		this->status = status;
	}

	void AttackSkillA(Pokemon& pokemon)
	{
		//스킬에 맞에 적절한 코드를 작성해야함.
		pokemon.curHp -= status.attack; // Example damage
	}

	void AttackSkillB(Pokemon& pokemon)
	{
		pokemon.curHp -= status.attack; // Example damage
	}

	void AttackSkillC(Pokemon& pokemon)
	{
		pokemon.curHp -= status.attack_s; // Example damage
	}

	void AttackSkillD(Pokemon& pokemon)
	{
		pokemon.curHp -= status.attack_s; // Example damage
	}
	//비교연산자
	//A < B: B가 A보다 크다 
	//A > B: A가 B보다 크다
	//A <= B: B가 A보다 같거나 작다.
	//A >= B: A가 B보다 같거나 크다.
	//A == B: A와 B가 같다
	//A != B: A와 B가 같지 않다.
	bool Death()
	{
		return curHp <= 0;
	}

	void DisplayStatus()
	{
		printf("Pokemon: %s\n", name);
		printf("HP: %d\n", curHp);
		printf("Level: %d\n", lv);
		printf("EXP: %d/%d\n", exp, maxExp);
	}
};

void BattleMain(Pokemon& pikachu, Pokemon& bulbasaur)
{ 
	int nInput = 0;

	while (true)
	{
		//상태표시
		printf("----------My PoketMon--------------\n");
		pikachu.DisplayStatus();
		printf("----------Wide PoketMon------------\n");
		bulbasaur.DisplayStatus();
		printf("-----------------------------------\n");

		if (pikachu.Death() == false)//살아있을때
		{
			printf("Choose %s's skill:",pikachu.name);
			scanf("%d", &nInput);
			switch (nInput)
			{
			case 1:
				printf("%s used Skill A!\n",pikachu.name);
				pikachu.AttackSkillA(bulbasaur);
				printf("%s Attak A:%d HP:%d\n",pikachu.name, pikachu.status.attack, bulbasaur.curHp);
				break;
			case 2:
				printf("Pikachu used Skill B!\n");
				pikachu.AttackSkillB(bulbasaur);
				printf("%s Attak B:%d HP:%d\n", pikachu.name, pikachu.status.attack, bulbasaur.curHp);
				break;
			case 3:
				printf("Pikachu used Skill C!\n");
				pikachu.AttackSkillC(bulbasaur);
				printf("%s Attak C:%d HP:%d\n", pikachu.name, pikachu.status.attack_s, bulbasaur.curHp);
				break;
			case 4:
				printf("Pikachu used Skill D!\n");
				pikachu.AttackSkillD(bulbasaur);
				printf("%s Attak D:%d HP:%d\n", pikachu.name, pikachu.status.attack_s, bulbasaur.curHp);
				break;
			}
			Sleep(500);
		}
		else
		{
			printf("%s is Dead!\n", pikachu.name);
			break;
		}
		printf("--------- Pikachu is Turn End ------------\n");
		Sleep(500);
		if (bulbasaur.Death() == false)
		{
			printf("%s used Skill A!\n", bulbasaur.name);
			bulbasaur.AttackSkillB(pikachu);
			Sleep(500);
		}
		else
		{
			printf("%s is Dead!\n",bulbasaur.name);
			break;
		}
		printf("--------- %s is Turn End ------------\n", bulbasaur.name);
		Sleep(500);
	}
}

void main()
{
	//생성자의 호출
	Pokemon pikachu(1, "Pikachu", { 1, Status::Electric, "Pikachu", 100, 55, 40, 90, 50, 50 });
	Pokemon bulbasaur(2, "Bulbasaur", { 2, Status::Grass, "Bulbasaur", 120, 49, 49, 45, 65, 65 });
	Pokemon pairi(3, "pairi", { 2, Status::Grass, "pairi", 120, 49, 49, 45, 65, 65 });
	
	BattleMain(pikachu, pairi);
}