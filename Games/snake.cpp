#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
//NOTE : dir=-2 ->left , dir=2 ->right , dir=1 -> up , dir= -1 ->down

bool gameOver;
const int height = 20, width = 20;
int x, y, fruitX, fruitY, score;
int taillength,dir;
int tailX[width * height], tailY[width * height];

void Setup() {
    gameOver = false;
    x = width / 2;
    y = height / 2;
    fruitX = (rand() % (width - 1)) + 1;
    fruitY = (rand() % (height - 1)) + 1;
    score = 0;
}
void Draw() {
    system("cls");
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }
            else if (i == y && j == x) {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX) {
                cout << "F";
            }
            else {
                bool prnt = false;
                for (int k = 0; k < taillength; k++) {
                    prnt = false;
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; prnt = true;
                    }
                }
                if (prnt == false) { cout << " "; }
            }
            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl << "Score:" << score << endl;
    cout << "fruitx: " << fruitX << " fruitY: " << fruitY << endl << " x: " << x << " y: " << y << endl;
}
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = -2;
            break;
        case 'w':
            dir = 1;
            break;
        case 's':
            dir = -1;
            break;
        case 'd':
            dir = 2;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic() {
    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < taillength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case -1:
        y++;
        break;
    case -2:
        x--;
        break;
    }
    if (x == fruitX && y == fruitY) {
        taillength += 1;
        score += 1;
        fruitX = (rand() % (width - 1)) + 1;
        fruitY = (rand() % (height - 1)) + 1;
    }
    if (x >= width) { x = 0; }
    else if (x < 0) { x = width - 1; }
    if (y >= height) { y = 0; }
    else if (y < 0) { y = height - 1; }
    for (int i = 1; i < taillength; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
        }
    }
}
int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(15);
    }
    return 0;
}