#include <stdio.h>

typedef enum{
    Right=1, Up = 2, Left = 3, Down = 4
} direction;

void draw();
void initializeBoard();
void takeInputAndMove();


int xCoordinate = 5;
int yCoordinate = 6;
int xReward = 6;
int yReward = 12;


const int heigh = 20;
const int width = 10;
int gameRunning = 1;
int score = 0;

char field[10][20];


int main() {

    // seed for random generator
    srand(time(0));

    initializeBoard();
    while(gameRunning) {
        takeInputAndMove();
        draw();
    }
}

void initializeBoard() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < heigh; j++) {
            if (i == 0 || j == 0 || i == width-1 || j == heigh - 1) {
                field[i][j] = "#";
            }else {
                field[i][j] = " ";
            }
        }
    }
    field[xCoordinate][yCoordinate] = "@";
    field[xReward][yReward] = "*";
}

void draw() {
    printf("Press x to exit\n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < heigh; j++) {
            printf("%c", field[i][j]);
        }
    }
}

void takeInputAndMove() {
    if (kbhit()) {
        switch (getch()) {
        case 'a':
            xCoordinate--;
            break;
        case 's':
            yCoordinate--;
            break;
        case 'd':
            xCoordinate++;
            break;
        case 'w':
            yCoordinate++;
            break;
        case 'x':
            //Game over
            gameRunning = 0;
            break;
        }

        if (xCoordinate == 0 || xCoordinate == width-1 || yCoordinate == 0 || yCoordinate == heigh-1)
        {
            //also game over
            gameRunning == 0;
        }

        if (xCoordinate == xReward || yCoordinate == yReward) {
            score++;
            xReward = (rand() % (width-1 - 0 + 1)) + 0;
            yReward = (rand() % (heigh-1 - 0 + 1)) + 0;
            
        }
    }
}