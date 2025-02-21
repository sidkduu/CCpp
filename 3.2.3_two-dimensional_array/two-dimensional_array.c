#include<stdio.h>

int main()
{
	const int size = 3;
	int board[size][size]{
		{0},{0},
	};
	int i, j;
	int num0fX;
	int num0f0;
	int result = -1;			//-1:没人赢，1：X赢，0：o赢



	//读入矩阵
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	//检查行
	for (i = 0; i < size && result == -1; i++) {
		num0f0 = num0fX = 0;
		
		for (j = 0; j < size; j++) {
			if (board[i][j] == 1) {
				num0fX++;
			}
			else {
				num0f0++;
			}
		}
		if (num0f0 == size) {
			result = 0;
		}
		else if (num0fX == size) {
			result = 1;
		}
	}

	//检查列
	if (result == -1) {
		for (j = 0; j < size && result == -1; j++) {
			num0f0 = num0fX = 0;
			for (i = 0; i < size; i++) {
				if (board[i][j] == 1) {
					num0fX++;
				}
				else {
					num0f0++;
				}
			}
			if (num0f0 == size) {
				result = 0;
			}
			else if (num0fX == size) {
				result = 1;
			}
		}
	}

	//检查对角线
	if (result == -1) {
		num0f0 = num0fX = 0;
		
		for (i = 0; i < size; i++) {
			if (board[i][i] == 1) {
				num0fX;
			}
			else {
				num0f0;
			}
		}
		if (num0f0 == size) {
			result = 0;
		}
		else if (num0fX == size) {
			result = 1;
		}
	}
	if (result == -1) {
		num0f0 = num0fX = 0;

		for (i = 0; i < size; i++) {
			if (board[i][size - i - 1] == 1) {
				num0fX++;
			}
			else {
				num0f0++;
			}
		}
		if (num0f0 == size) {
			result = 0;
		}
		else if (num0fX == size) {
			result = 1;
		}
	}

	switch (result) {
	case 1:
		printf("X赢了\n");
		break;
	case 0:
		printf("O赢了\n");
		break;
	case -1:
		printf("双方都没有赢\n");
		break;
	}

	return 0;
}