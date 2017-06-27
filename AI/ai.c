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

//�浹���θ� �˻��ϴ� �Լ�
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
 * board�� boardW*boardH�� ������ ���ڿ��� �̷���� �ִ�.
 * ���� ���, 8*3ũ���� ��죺
 * 00000000
 * 00011001
 * 01111111
 * board�� ������ ���� �־����� ��"011111110001100100000000".
 *
 * curPiece�� ���� ������� "OISZLJT" �� �ϳ��� ���ڿ��� �־�����.
 * nextPiece�� �̸����⸦ ����� ��� OISZLJT �� �ϳ��� �׷��� ���� ��� ������ �־�����.
 * curR�� ���� ���� ������ ��Ÿ���� 1�� �ʱ� ���⣬2�� 90�� ȸ����3��180�� ȸ����4�� 270�� ȸ���� ���̴�.
 * curX,curY�� 4*4 ������ 1, 2�� ��ġ�� �������� ���� ���� ��ġ�� ��Ÿ���� ��ǥ���̴�.
 *		board���� x=1,y=1�� ���� �ϴ�,
 *		board���� x=boardW,y=1�� ������ �ϴ�,
 *		board���� x=1,y=boardH�� ���� ����̴�.
 *		���丮�� pieces_orientations.jpg ���� ����.
 *		�⺻ �ʱ� ��ġ�� curY==boardH-1, curX==boardW/2+1�̴�.
 *
 * bestX,bestRotation �� �����ϸ� �ȴ�. (curX,curR�� ���� ��Ģ�� ����)
 *
 * ����ȸ���� ���� �̷������ ���� x��ǥ�� �̵��� �� ����Ʈ����.
 *		�� �Լ��� ��ϴ� 1ȸ ȣ�� �ȴ�.
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
		//õ��
		for (column = 0; column < WIDTH_SIZE + 3; column++) {
			curBoard[22][column] = 2;
		}

		//�ٴ�
		for (int column = 0; column < WIDTH_SIZE + 3; column++) {
			curBoard[0][column] = 2;
			curBoard[1][column] = 2;
		}

		//���� ��
		for (int row = 0; row < HEIGHT_SIZE + 3; row++) {
			curBoard[row][0] = 2;
			curBoard[row][1] = 2;
		}

		//������ ��
		for (int row = 0; row < HEIGHT_SIZE + 3; row++) {
			curBoard[row][12] = 2;
		}

		//���� ����� �������� �ʱ�ȭ
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
	//���� ȸ�� ���¿� ���� ��� ����� �� üũ�ϱ�
	for (curR = 0; curR < 4; curR++) {
		int fromX = curX;
		int toX = curX;
		int tempX;
		int tempY;

		//�ִ�� �� �� �ִ� ���� ��ǥ
		while (isCollison(fromX - 1, curY, curR, curPieceType, curBoard) == 0) {
			fromX--;
		}

		//�ִ�� �� �� �ִ� ������ X��ǥ
		while (isCollison(toX + 1, curY, curR, curPieceType, curBoard) == 0) {
			toX++;
		}

		//��� X��ǥ�� ���� ���ƺ���.
		for (tempX = fromX; tempX <= toX; tempX++) {
			int toY = curY;
			int heightOnX[13] = { 0 };
			int completeLines = 0; //�ϼ��� ���� ����
			int aggregateHeight = 0; //�� ���̵��� ��
			int holes = 0; //������ ����
			int bumpiness = 0; //���̵��� ����
			int heightestBlock = 0;
			double total = 0;

			//������ �ʱ�ȭ
			int copiedBoard[23][13];
			memcpy(copiedBoard, curBoard, sizeof(curBoard));

			//���� ������ �� Y��ǥ ���ϱ�
			while (isCollison(tempX, toY - 1, curR, curPieceType, curBoard) == 0) {
				toY--;
			}
			tempY = toY;

			//���� ������ �� ������ ����
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (gPieceBitmap[curPieceType][curR][i][j] == 1)
						copiedBoard[tempY - i][tempX + j] = 1;
				}
			}

				//�ϼ��� ������ ���� ����
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

				//������ ��ü���� ���� ����ϱ�
				for (int column = 2; column < WIDTH_SIZE + 2; column++) {
					for (int row = HEIGHT_SIZE + 2; row > 0; row--) {
						if (copiedBoard[row][column] == 1) {
							heightOnX[column] = row;
							break;
						}
					}

					aggregateHeight += heightOnX[column];
				}

				//������ ���� ����
				for (int row = 1; row < HEIGHT_SIZE + 2; row++) {
					for (int column = 2; column < WIDTH_SIZE + 2; column++) {
						if (copiedBoard[row][column] == 0) {
							if (row < heightOnX[column]) {
								holes++;
							}
						}
					}
				}

				//������ ���� ���ϱ�
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
 * path�� �����ϴ� ��ɾ ���� ����
 *      'l': �� ĭ �������� �̵�
 *      'r': �� ĭ ���������� �̵�
 *      'd': �� ĭ �Ʒ��� �̵�
 *      'L': ������ ���� �������� �̵�
 *      'R': ������ ���� ���������� �̵�
 *      'D': ������ ���� �Ʒ��� �̵����� �� �߰� �̵� ���ɣ�
 *      'z': �� �ð�������� ȸ��
 *      'c': �ð�������� ȸ��
 * path ���ڿ� ����'\0'�� �ϵ� ������ ��Ÿ����.
 *
 * ���� ��ɾ �̿��Ͽ� ������ �̵��� �����ϸ� �Ʒ��� ��ü �ڵ带 �����Ͽ��� �Ѵ�.
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
