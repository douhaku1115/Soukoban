#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char data[] = "\
################################\
#              #               #\
#              #        +      #\
#  gg          ####     ###### #\
#  gg                          #\
#     Å@Å@                     #\
#            #                 #\
#            #                 #\
#            #    #         +  #\
# ############    #            #\
#                 ####+        #\
#                 #   +        #\
#                 #            #\
################################";


#define MAZE_WIDTH 32
#define MAZE_HEIGHT 15
enum {
	CELL_TYPE_NONE,
	CELL_TYPE_WALL,
	CELL_TYPE_PACAGE,
	CELL_TYPE_GOAL
};
char cellAA[][2 + 1] = {
	"Å@",
	"Å°",
	"Å†",
	"Åõ",
};
char monsterAA[][2 + 1] = {
	"Åó"
	
};
typedef struct {
	int x, y;
	int directions;
}MONSTER;
MONSTER monsters;
int cells[MAZE_HEIGHT][MAZE_WIDTH];

int getMonster(int _x, int _y) {
	
		if ((monsters.x == _x) && (monsters.y == _y))
			return 0;
	return -1;
}
void display() {
	system("cls");
	for (int y = 0; y < MAZE_HEIGHT; y++) {
		for (int x = 0; x < MAZE_WIDTH; x++) {
			int monster = getMonster(x, y);
			if (monster == 0)
				printf(monsterAA[monster]);
			else
				printf(cellAA[cells[y][x]]);
		}
		printf("\n");
	}
}
void gameOver() {
		monsters.x = -1;
		monsters.y = -1;
		display();
		printf("  GAME OVER!!\a");
		_getch();
		exit(0);
};

int main() {
	int monster = -1;
	monsters.x = 12;
	monsters.y = 12;
	srand((unsigned int)time(NULL));
	for (int y = 0; y < MAZE_HEIGHT; y++)
		for (int x = 0; x < MAZE_WIDTH; x++) {
			char c = data[MAZE_WIDTH * y + x];
			int cell = CELL_TYPE_NONE;
			switch (c) {
			case'#':cell = CELL_TYPE_WALL; break;
			case'+':cell = CELL_TYPE_PACAGE; break;
			case'g':cell = CELL_TYPE_GOAL; break;
			case'@':monster = 0;  break;
				
			break;
			}
			cells[y][x] = cell;

		}
	while (1) {
			display();
			int x = monsters.x;
			int y = monsters.y;
			switch (_getch()) {
			case'w':y--; break;
			case's':y++; break;
			case'a':x--; break;
			case'd':x++; break;
			}
			x = (MAZE_WIDTH + x) % MAZE_WIDTH;
			
			monsters.x = x;
			monsters.y = y;
			display();
				
		}
	_getch();
}