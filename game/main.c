#include "game.h"

int main()
{
	while (isRunning)
	{
		// 1. 화면 그려주기
		printMap();
		// 2. 사용자 입력 처리(방향키)
		handleInput();
		// 3. 게임 로직 처리(이벤트 처리)
		handleLogic();
		// 프레임 조절
		Sleep(60);
	}
	return 0;
}
