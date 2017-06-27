#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <math.h>
#include <memory.h>

#define DECLSPEC_EXPORT __declspec(dllexport)
#define WINAPI __stdcall
#define WIDTH_SIZE 10
#define HEIGHT_SIZE 20

char pieceKind[] = { "OISZLJT" };
char gName[64];
char gPieceBitmap[8][4][4][4] =
{
	// NULL
	{
		{
			{0},
		},
	},
	// O
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
	},
	// I
	{
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
		},
	},
	// S
	{
		{
			{0, 0, 0, 0},
			{0, 0, 1, 1},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 0, 1, 1},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 0},
		},
	},
	// Z
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 1},
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 1},
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
	},
	// L
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 1},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 1},
			{0, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
	},
	// J
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
	},
	// T
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
	},
};

#ifdef __cplusplus
extern "C" {
#endif

DECLSPEC_EXPORT
char* WINAPI Name()
{
	strcpy(gName, "2013113504");
	return gName;
}

//충돌여부를 검사하는 함수
int isCollison(int curX,
	int curY,
	int curR,
	int curPieceType,
	int curBoard[HEIGHT_SIZE + 3][WIDTH_SIZE + 3]) {
	
	int i;
	int j;
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (gPieceBitmap[curPieceType][curR][i][j] == 1 &&
				curBoard[curY - i][curX + j] > 0) {
				return 1;
			}
		}
	}
	return 0;
}

/*
 * board는 boardW*boardH의 길이의 문자열로 이루어져 있다.
 * 예를 들어, 8*3크기의 경우：
 * 00000000
 * 00011001
 * 01111111
 * board에 다음과 같이 주어진다 ："011111110001100100000000".
 *
 * curPiece는 블럭의 모양으로 "OISZLJT" 중 하나의 문자열이 주어진다.
 * nextPiece는 미리보기를 사용할 경우 OISZLJT 중 하나가 그렇지 않을 경우 공백이 주어진다.
 * curR은 현재 블럭의 방향을 나타내며 1이 초기 방향，2는 90도 회전，3는180도 회전，4는 270도 회전된 것이다.
 * curX,curY는 4*4 블럭에서 1, 2의 위치를 기준으로 블럭의 현재 위치를 나타내는 좌표값이다.
 *		board에서 x=1,y=1은 왼쪽 하단,
 *		board에서 x=boardW,y=1은 오른쪽 하단,
 *		board에서 x=1,y=boardH은 왼쪽 상단이다.
 *		디렉토리에 pieces_orientations.jpg 파일 참고.
 *		기본 초기 위치는 curY==boardH-1, curX==boardW/2+1이다.
 *
 * bestX,bestRotation 을 지정하면 된다. (curX,curR과 같은 규칙을 따름)
 *
 * 참고：회전이 먼저 이루어지며 이후 x좌표를 이동한 후 떨어트린다.
 *		이 함수는 블록당 1회 호출 된다.
 */
int AI(int boardW, int boardH,
	char board[],
	char curPiece,
	int curX, int curY,
	int curR,
	char nextPiece,
	int* bestX, int* bestRotation)
{
	double BestScore = -800000;
	curX = curX - 1;
	curY = curY + 2;
	int curPieceType = 0;
	int curBoard[HEIGHT_SIZE + 3][WIDTH_SIZE + 3];

	//set curBoard
	{
		int i = 0;
		int column;
		//천장
		for (column = 0; column < WIDTH_SIZE + 3; column++) {
			curBoard[22][column] = 2;
		}

		//바닥
		for (int column = 0; column < WIDTH_SIZE + 3; column++) {
			curBoard[0][column] = 2;
			curBoard[1][column] = 2;
		}

		//왼쪽 벽
		for (int row = 0; row < HEIGHT_SIZE + 3; row++) {
			curBoard[row][0] = 2;
			curBoard[row][1] = 2;
		}

		//오른쪽 벽
		for (int row = 0; row < HEIGHT_SIZE + 3; row++) {
			curBoard[row][12] = 2;
		}

		//실제 사용할 보드판을 초기화
		for (int row = 2; row < HEIGHT_SIZE + 2; row++) {
			for (int column = 2; column < WIDTH_SIZE + 2; column++) {
				curBoard[row][column] = board[i++] - '0';
			}
		}
	}

	//get current gPieceBitMap
	{
		while (curPiece != pieceKind[curPieceType++]) {
			;
		}
	}

	//start simulation
	//블럭의 회전 상태에 따른 모든 경우의 수 체크하기
	for (curR = 0; curR < 4; curR++) {
		int fromX = curX;
		int toX = curX;
		int tempX;
		int tempY;

		//최대로 갈 수 있는 왼쪽 좌표
		while (isCollison(fromX - 1, curY, curR, curPieceType, curBoard) == 0) {
			fromX--;
		}

		//최대로 갈 수 있는 오른쪽 X좌표
		while (isCollison(toX + 1, curY, curR, curPieceType, curBoard) == 0) {
			toX++;
		}

		//모든 X좌표에 블럭을 놓아본다.
		for (tempX = fromX; tempX <= toX; tempX++) {
			int toY = curY;
			int heightOnX[13] = { 0 };
			int completeLines = 0; //완성된 줄의 개수
			int aggregateHeight = 0; //각 높이들의 합
			int holes = 0; //구멍의 개수
			int bumpiness = 0; //높이들의 편차
			int heightestBlock = 0;
			double total = 0;

			//보드판 초기화
			int copiedBoard[23][13];
			memcpy(copiedBoard, curBoard, sizeof(curBoard));

			//블럭을 내렸을 때 Y좌표 구하기
			while (isCollison(tempX, toY - 1, curR, curPieceType, curBoard) == 0) {
				toY--;
			}
			tempY = toY;

			//블럭을 내렸을 때 보드판 상태
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (gPieceBitmap[curPieceType][curR][i][j] == 1)
						copiedBoard[tempY - i][tempX + j] = 1;
				}
			}

				//완성된 라인의 개수 세기
				for (int row = 2; row <= HEIGHT_SIZE + 2; row++) {
					int pieceCnt = 0;
					for (int column = 2; column < WIDTH_SIZE + 2; column++) {
						if (copiedBoard[row][column] == 1) {
							pieceCnt++;
						}
					}

					if (pieceCnt == WIDTH_SIZE) {
						completeLines++;
					}
				}

				//보드의 전체적인 높이 계산하기
				for (int column = 2; column < WIDTH_SIZE + 2; column++) {
					for (int row = HEIGHT_SIZE + 2; row > 0; row--) {
						if (copiedBoard[row][column] == 1) {
							heightOnX[column] = row;
							break;
						}
					}

					aggregateHeight += heightOnX[column];
				}

				//구멍의 개수 세기
				for (int row = 1; row < HEIGHT_SIZE + 2; row++) {
					for (int column = 2; column < WIDTH_SIZE + 2; column++) {
						if (copiedBoard[row][column] == 0) {
							if (row < heightOnX[column]) {
								holes++;
							}
						}
					}
				}

				//높이의 편차 구하기
				for (int column = 2; column < WIDTH_SIZE + 1; column++) {
					bumpiness += abs(heightOnX[column] - heightOnX[column + 1]);
				}

				total = (-0.510066 * aggregateHeight) + (0.760666 * completeLines) + (-0.35663 * holes) + (-0.184483 * bumpiness);

				if (total > BestScore) {
					BestScore = total;
					*bestX = tempX + 1;
					*bestRotation = curR + 1;
				}
			}
		}
	return 0;
}

/*
 * path를 지정하는 명령어에 대한 설명：
 *      'l': 한 칸 왼쪽으로 이동
 *      'r': 한 칸 오른쪽으로 이동
 *      'd': 한 칸 아래로 이동
 *      'L': 가능한 가장 왼쪽으로 이동
 *      'R': 가능한 가장 오른쪽으로 이동
 *      'D': 가능한 가장 아래로 이동（이 후 추가 이동 가능）
 *      'z': 반 시계방향으로 회전
 *      'c': 시계방향으로 회전
 * path 문자열 끝에'\0'이 하드 랜딩을 나타낸다.
 *
 * 위의 명령어를 이용하여 임의의 이동이 가능하며 아래의 전체 코드를 수정하여야 한다.
 */
DECLSPEC_EXPORT
int WINAPI AIPath(int boardW, int boardH,
		char board[],
		char curPiece,
		int curX, int curY,
		int curR,
		char nextPiece,
		char path[] )
{
	//if (0)
	{
		int bestX;
		int bestRotation;
		AI(boardW, boardH,
			board,
			curPiece, 
			curX, curY,
			curR,
			nextPiece,
			&bestX, &bestRotation
			);
		 
		while ( curR != bestRotation )
		{
			strcat(path, "z");
			curR = curR % 4 + 1;
		}
		while ( curX > bestX )
		{
			strcat(path, "l");
			curX -= 1;
		}
		while ( curX < bestX )
		{
			strcat(path, "r");
			curX += 1;
		}
	}
	//strcpy(path, "ddddddddddcccrrrrrrDL");
	return 0;
}

#ifdef __cplusplus
}
#endif
