#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define MAZESIZEX 65
#define MAZESIZEY 24
#define WALL_C '1'
#define WALL_S "1"
#define EMPTY_C ' '
#define EMPTY_S " "

int	scoord(int x, int y);
int	wcoord(int x, int y);
int	dirSum(int dir[4]);
int	spaceMoveAllowed(char* spaces, int randDir, int x, int y);
void	removeWall(char* walls, int randDir, int x, int y);
int	randDirX(int randDir, int x);
int	randDirY(int randDir, int y);
void	mazeFill(char* spaces, char* walls, int x, int y);
void	mazeDraw(char* walls);
void	addSpace(char* spaces, char* walls);
void	printDebug(char* spaces, char* walls, int x, int y);

int main()
{
	char*	spaces;
	char*	walls;

	spaces = (char*)calloc(MAZESIZEY * MAZESIZEX, sizeof(char));
	walls = (char*)calloc((MAZESIZEY + 1) * (MAZESIZEX * 2 + 1), sizeof(char));

	addSpace(spaces, walls);

	srand(time(NULL));
	int	x = rand() % MAZESIZEX;
	int	y = rand() % MAZESIZEY;

	mazeFill(spaces, walls, x, y);

	mazeDraw(walls);

}

void	addSpace(char* spaces, char* walls)
{
	int i = -1;

	while (++i < (MAZESIZEY + 1) * (MAZESIZEX * 2 + 1))
		walls[i] = WALL_C;
	i = -1;
	while (++i < MAZESIZEY * MAZESIZEX)
		spaces[i] = EMPTY_C;
}

void	printX(void)
{
	int i = -1;
	while (++i < MAZESIZEX)
		printf("%d", i % 10);
	printf("\n");
}

void	printXmaze(void)
{
	int i = -1;
	while (++i < MAZESIZEX)
		printf(" %d", i % 10);
	printf("\n");
}

void	printDebug(char* spaces, char* walls, int x, int y)
{
	int iy;
	char buf;
	printf("X: %d, Y= %d\n", x, y);
	printX();
	iy = -1;
	while (++iy < MAZESIZEY)
	{
		write (1, &spaces[scoord(0, iy)], MAZESIZEX);
		write (1, "\n", 1);
	}
	mazeDraw(walls);

	read(0, &buf, 1);
}



void	mazeDraw(char* walls)
{
	int	y;
	int x;

	printXmaze();
	y = -1;
	while (++y < MAZESIZEY + 1)
	{
		x = 1;
		write(1, WALL_S, 1);
		while (x < MAZESIZEX * 2 + 1)
		{
			write(1, &walls[wcoord(x, y)], 1);
			write(1, WALL_S, 1);
			x += 2;
		}
		write (1, "\n", 1);
		if (y < MAZESIZEY)
		{
			x = 0;
			while (x < MAZESIZEX * 2)
			{
				write(1, &walls[wcoord(x, y)], 1);
				write(1, EMPTY_S, 1);
				x += 2;
			}
			write(1, WALL_S, 1);
			write (1, "\n", 1);
		}
	}
}

int	scoord(int x, int y)
{
	return (y * MAZESIZEX + x);
}

int	wcoord(int x, int y)
{
	return (y * (MAZESIZEX * 2 + 1) + x);
}

int	dirSum(int dir[4])
{
	return (dir[0] + dir[1] + dir[2] + dir[3]);
}

int	spaceMoveAllowed(char* spaces, int randDir, int x, int y)
{
	switch (randDir)
	{
		case 0:
			if ((x - 1 >= 0) && (spaces[scoord(x - 1, y)] != 'v'))
			{
				//printf("left allowed at x:%d y:%d val:%c\n", x - 1, y, spaces[scoord(x - 1, y)]);
				return 1;
			}
			break;
		case 1:
			if ((y - 1 >= 0) && (spaces[scoord(x, y - 1)] != 'v'))
			{
				//printf("up allowed at x:%d y:%d val:%c\n", x, y - 1, spaces[scoord(x, y - 1)]);
				return 1;
			}
			break;
		case 2:
			if ((x + 1 < MAZESIZEX) && (spaces[scoord(x + 1, y)] != 'v'))
			{
				//printf("right allowed at x:%d y:%d val:%c\n", x + 1, y, spaces[scoord(x + 1, y)]);
				return 1;
			}
			break;
		case 3:
			if ((y + 1 < MAZESIZEY) && (spaces[scoord(x, y + 1)] != 'v'))
			{
				//printf("down allowed at x:%d y:%d val:%c\n", x, y + 1, spaces[scoord(x, y + 1)]);
				return 1;
			}
			break;
	}
	return 0;
}

void	removeWall(char* walls, int randDir, int x, int y)
{
	switch (randDir)
	{
		case 0:
			walls[wcoord(x * 2, y)] = EMPTY_C;
			break;
		case 1:
			walls[wcoord(x * 2 + 1, y)] = EMPTY_C;
			break;
		case 2:
			walls[wcoord(x * 2 + 2, y)] = EMPTY_C;
			break;
		case 3:
			walls[wcoord(x * 2 + 1, y + 1)] = EMPTY_C;
			break;
	}
}

int	randDirX(int randDir, int x)
{
	if (randDir == 0)
		return (x - 1);
	if (randDir == 2)
		return (x + 1);
	return x;
}

int	randDirY(int randDir, int y)
{
	if (randDir == 1)
		return (y - 1);
	if (randDir == 3)
		return (y + 1);
	return y;
}

void	mazeFill(char* spaces, char* walls, int x, int y)
{
	int	dir[4] = {0, 0, 0, 0};
	int randDir;

	spaces[scoord(x, y)] = 'v';
	//printDebug(spaces, walls, x, y);
	while (dirSum(dir) != 4)
	{
		randDir = rand() % 4;
		if (dir[randDir] == 0)
		{
			dir[randDir] = 1;
			if (spaceMoveAllowed(spaces, randDir, x, y) == 1)
			{
				removeWall(walls, randDir, x, y);
				//printf("REMOVE WALL\n");
				mazeFill(spaces, walls, randDirX(randDir, x), randDirY(randDir, y));
				//printf("COME BACK\n");
			}
		}
	}
	//printf("FINISHED POINT\n");
}

