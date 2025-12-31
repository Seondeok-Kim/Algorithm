#include "game.h"

// 맵의 모양
char map[n][n + 1] =
{
	"####################",
	"# # ^ #Y  ###Ma ^^ #",
	"# ^ M  ##M#######^##",
	"#####M  #^     M#  #",
	"#  ^   #MM M#M  ^^ #",
	"#  ##^ #^  ^#####  #",
	"#M  ^^#M #MY^ ^## M#",
	"# ^# M#^ ###^   #^M#",
	"# ^# ^M M### # M#  #",
	"#  #Ma#  MYM # ^#M^#",
	"# ^  Ma# ###^#M^#  #",
	"#^###### ###^#^^^  #",
	"#^## M ^  ^ ^ ###  #",
	"#^## ^^##M#a# ##  ##",
	"#^## ^#^^Y#######^^#",
	"#^   ## ###M #   ^^#",
	"# ###aM^ ^^^^  # ###",
	"# ########### ^#  ##",
	"#             ^#M aM",
	"####################",
};

//아이템 획득 여부 체크하는 배열(1:획득함, 0:획득 전)
int used[n][n] = { 0 };

//캐릭터(@)의 Y,X 좌표
int y = 1, x = 1;
int hp = MAX_HP;
int state = 0; 
//게임진행여부(0:종료, 1:실행중)
int isRunning = 1;

// 현재 맵, 캐릭터 상태 등 모든 화면 출력
void printMap() 
{
	//1. 현재 커서를 0,0으로 이동
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	//2.이차원  map을 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			if (y == i && x == j) printf("@");
			else if (used[i][j]) printf(" "); // 이미 먹은 아이템 자리는 빈칸으로
			else printf("%c", map[i][j]);
		}
		printf("\n");
	}
	// 3자리 무조건 채우기 %-3d
	printf("HP: %-3d \n", hp);
}


// 사용자의 입력 처리
void handleInput()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		// 왼쪽 벽이 아니라면
		if (isValid(y, x - 1))
		{
			x--;
			state = 0; // 이동 성공 시 state를 0으로 초기화 -> 다음 함정이 잘 동작한다
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (isValid(y, x + 1))
		{
			x++;
			state = 0;
		}
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (isValid(y - 1, x)) {
			y--;
			state = 0;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) 
	{ 
		if (isValid(y + 1, x)) {
			y++;
			state = 0;
		}
	}
} 


// 벽 체크(0:벽, 1:갈 수 있는 곳)
int isValid(int y, int x)
{
	return (map[y][x] != '#');
}


// 이동 로직 처리
void handleLogic() 
{
	// 게임 종료 (패배)
	if (map[y][x] == 'M') {
		gameOver();
	}
	// 게임 종료 (승리)
	else if (map[y][x] == 'Y') {
		gameWin();
	}
	// 함정
	else if (map[y][x] == '^') {
		hpDown();
		if (hp <= 0)
		{
			gameOver();
		}
	}
	// 회복 아이템
	else if (map[y][x] == 'a' && used[y][x] == 0) {
		hpUp();
	}
}

//회복아이템(a)
void hpUp() 
{
	hp = MAX_HP;
	used[y][x] = 1;// Todo: 회복 아이템을 먹으면, 사라져야 한다
}
// 가시함정(^)
void hpDown() 
{
	if (state == 0) {
		hp -= 10;
		state = 1;
	}
}

//게임 종료(패배, M)
void gameOver()
{
	system("color 0F");
	Sleep(100);
	system("color 4F");
	Sleep(200);

	system("color 0F");
	Sleep(100);
	system("color 4F");
	Sleep(200);

	system("cls");
	printf("GAME OVER!!!");

	isRunning = 0; // 전체 반복이 종료된다. 
}

//게임종료(승리, Y)
void gameWin()
{
	system("color 0F");
	Sleep(100);
	system("color 2F");
	Sleep(200);
	system("color 0F");
	Sleep(100);
	system("color 2F");
	Sleep(200);

	system("cls");
	printf("GAME WIN!!!");

	isRunning = 0; // 전체 반복이 종료된다. 
}
