#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define N 25

using namespace std;

class Crosses {
private:     
    char arr[3][3] = {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool player;
    char* player1 = new char(N);
    char* player2 = new char(N);
    bool status;

public:
    Crosses() : player(true), status(false) {}

    void startGame() {
        do {
            cout << "Enter name of the first player: ";
            cin >> player1;
            cout << "Enter name of the second player: ";
            cin >> player2;
        } while (!strcmp(player1, player2));
    }

    void showGrid() {
        cout << "       1    2    3" << endl;
        cout << "    ________________" << endl;
        cout << "  1 | " << 11 << " | " << 12 << " | " << 13 << " |" << endl;
        cout << "  2 | " << 21 << " | " << 22 << " | " << 23 << " |" << endl;
        cout << "  3 | " << 31 << " | " << 32 << " | " << 33 << " |" << endl;
        cout << endl;
    }

    void showGame() {
        cout << "\n" << "      1   2   3" << endl;
        cout << "    _____________" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "  " << i + 1 << " | ";
            for (int j = 0; j < 3; j++) {
                cout << arr[i][j] << " | ";
            }
            cout << endl;
        }
    }
    void chooseCell() {
        int cell;
        while (true) {
            cout << endl;
            if (player) {
                cout << "  " << player1;
            }
            else {
                cout << "  " << player2;
            }
            cout << ", enter cell: ";

            cin >> cell;
            if (cell > 10 && cell < 34) {
                int i = cell / 10;
                int j = cell % 10;

                if (0 < j && j < 4) {
                    if (arr[i - 1][j - 1] != 'X' && arr[i - 1][j - 1] != 'O') {
                        if (player) {
                            arr[i - 1][j - 1] = 'X';
                        }
                        else {
                            arr[i - 1][j - 1] = 'O';
                        }
                        player = !player;
                        break;
                    }
                }
            }
            cout << "  Choose another cell: " << endl;
        }
    }

    bool checkStatus() {
        bool step = false;
        if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && (arr[0][0] == 'X' || arr[0][0] == 'O')) {
            status = true;
                if (arr[0][0] == 'X') {
                    step = true;
                }
        }
        else if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && (arr[1][0] == 'X' || arr[1][0] == 'O')) {
            status = true;
            if (arr[1][0] == 'X') {
                step = true;
            }
        }
        else if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && (arr[2][0] == 'X' || arr[2][0] == 'O')) {
            status = true;
            if (arr[2][0] == 'X') {
                step = true;
            }
        }
        else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && (arr[0][0] == 'X' || arr[0][0] == 'O')) {
            status = true;
            if (arr[0][0] == 'X') {
                step = true;
            }
        }
        else if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && (arr[0][1] == 'X' || arr[0][1] == 'O')) {
            status = true;
            if (arr[0][1] == 'X') {
                step = true;
            }
        }
        else if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && (arr[0][2] == 'X' || arr[0][2] == 'O')) {
            status = true;
            if (arr[0][2] == 'X') {
                step = true;
            }
        }
        else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && (arr[1][1] == 'X' || arr[1][1] == 'O')) {
            status = true;
            if (arr[1][1] == 'X') {
                step = true;
            }
        }
        else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && (arr[1][1] == 'X' || arr[1][1] == 'O')) {
            status = true;
            if (arr[1][1] == 'X') {
                step = true;
            }
        }

        if (status) {
            if (step) {
                cout << "\n  " << player1 << " win!" << endl;
            }
            else {
                cout << "\n  " << player2 << " win!" << endl;
            }
            return true;
        }
        else {
            bool draw = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (arr[i][j] != 'X' && arr[i][j] != 'O') {
                        draw = false;
                    }
                }
            }

            if (draw) {
                cout << "draw!";
                return true;
            }
        }
        return false;
    }

    //Setter
    void setPersonsAttr (char *name1, char *name2){
        *player1 = *name1;
        *player2 = *name2;
    }

    //Getter
    char getPersonsAttr (){
        return *player1, *player2;
    }
};

int main() {
    Crosses cross;

    cross.startGame();
    while (true) {
        system("cls");
        cross.showGrid();
        cross.showGame();
        if (cross.checkStatus())
            break;
        cross.chooseCell();
    }
    char* name1 = new char(N);
    char* name2 = new char(N);
    cross.setPersonsAttr(name1, name2);
    cross.getPersonsAttr();
    delete [] name1;
    delete [] name2;

    return 0;
}