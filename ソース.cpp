#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char data[] = "\
################################\                    #\
# ..           #               #\
# ..           #        +      #\
# ..           ####+    ###### #\
#                              #\
#                              #\
#            #                 #\
#            #                 #\
#            #    #         +  #\
# ############    #         +  #\
#                 ####+     +  #\
#                 #   +        #\
#                 #         @  #\
################################";


#define MAZE_WIDTH 32
#define MAZE_HEIGHT 141
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
	"G",
};
char monsterAA[][2 + 1] = {
	"Åó",
};