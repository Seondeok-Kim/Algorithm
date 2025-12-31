#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <windows.h>
#define n 20 // 맵의 가로, 세로 크기 20으로 고정
#define MAX_HP 100 // 최대 체력


//전역 변수
extern char map[n][n + 1];// 20*20 맵의 모양
extern int used[n][n]; //아이템 획득 여부 체크하는 배열 (1:획득함, 0:획득 전) 
extern int y, x; // 캐릭터(@)의 현재 Y,X 좌표
extern int hp; // 현재 캐릭터의 HP
extern int state; // 함정 중복 데미지 방지를 위한 플래그(0:대기, 1:피격상태)
extern int isRunning; // 게임 진행 여부(0:종료, 1:실행 중)

//함수 선언
void printMap(); // 현재 맵, 캐릭터의 상태 등 모든 화면 출력
void handleInput(); // 사용자의 입력 처리
void handleLogic(); // 이동 로직 처리
int isValid(int y, int x); // 벽 체크(0:벽, 1:갈 수 있는 곳)
void hpUp(); // 회복 아이템(a)
void hpDown(); // 가시 함정(^)
void gameOver(); // 게임 종료(패배, M)
void gameWin(); // 게임 종료(승리, Y)

#endif
