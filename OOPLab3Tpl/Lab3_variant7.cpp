#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <clocale>
#define SIZE 20

enum STATE {
    OK, BAD_INIT, BAD_DIV
};

using namespace std;

class Crosses {
private:
    char arr[3][3] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    bool player;
    char* player1 = new char(SIZE);
    char* player2 = new char(SIZE);
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
        /*Here it's possible to make just a 3 or even 2 cycle, but we have only 8 winning combinations, so I do 8 if statement
        in order to see every single combination and be sure that it does works*/
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
};

class Vector {
private:
    double* arr; // x y z
    int size = 3;
    int status;
    int const param;
    static int count;
public:
    Vector() : status(OK), param(0){
        arr = new double[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        count++;
    }
    Vector(double value) : param(0) {
        arr = new double[size];
        for (int i = 0; i < size; i++) {
            arr[i] = value;
        }
        status = OK;
        count++;
    }
    ~Vector() {
        count--;
        cout << "\n Current status of vector: " << status << endl;
        cout << " Vector delete" << endl;
    }
    int getState() {
        return status;
    }
    static int getCount() {
        if (count <= 0) cout << " There is no objects created ";
        return count;
    }
    Vector(double* next);
    Vector(const Vector&);
    Vector add(Vector& d);
    Vector minus(Vector& d);
    Vector divideShort(short num);
    void assignElem(int const param);
    void getElem();
    void input();
    void output();
};

/*------------------------------------------------------*/
int Vector::count = 0;
Vector::Vector(const Vector& s) : param(0), status(OK) {
    if (this == &s) return;
    arr = new double[s.size];
    for (int i = 0; i < 3; i++) {
        arr[i] = s.arr[i];
    }
    status = OK;
    count++;
}

Vector::Vector(double* next) : param(0) {
    arr = new double[size];
    if (next == nullptr) {
        status = BAD_INIT;
        arr[0] = 0; arr[1] = 0; arr[2] = 0; 
    }
    else {
        arr[0] = next[0]; arr[1] = next[1]; arr[2] = next[2];
        status = OK;
    }
    count++;
}

Vector Vector::add(Vector& a) {
    Vector tmp; 
    for (int i = 0; i < 3; i++) {
        tmp.arr[i] = arr[i] + a.arr[i];
    }
    return tmp;
}

Vector Vector::minus(Vector& m) {
    Vector tmp;
    for (int i = 0; i < 3; i++) {
        tmp.arr[i] = arr[i] - m.arr[i];
    }
    return tmp;
}

Vector Vector::divideShort(short num) {
    Vector tmp;
    if (num == 0) {
        tmp.status = BAD_DIV;
        cout << " Error divide \n";
        return *this;
    }
    for (int i = 0; i < 3; i++) {
        tmp.arr[i] = arr[i] / num;
    }
    return tmp;
}

void Vector::assignElem(int const param) {
    srand(time(nullptr));
    int rndNum = rand() % 3;
    arr[rndNum] = param;
}

void Vector::getElem() {
    srand(time(nullptr));
    int rndNum = rand() % 3;
    cout << "Receive random element of array: " << arr[rndNum];
}

void Vector::input() {
    cout << "\n Input element of vector(x, y, z): ";
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
}

void Vector::output() {
    cout << " \nVector as array[x, y, z]:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << " [" << i << "]: " << arr[i] << ", ";
    }
}

/*------------------------------------------------------*/

int showTask(int answerTask)
{
    /*Create objects*/
    Crosses cross;
    Vector emptyVector;
    Vector arrInput;
    Vector initArrayOneParam(10.0);
    Vector objCopyInitArr(initArrayOneParam);
    double* v = nullptr, next[] = {2.5, 0, 10};
    Vector pointerArr(next);
    Vector anotherPointerArr(next);
    Vector getCount();

    switch (answerTask) {
    case 1:
        cross.startGame();
        while (true) {
            system("cls");
            cross.showGrid();
            cross.showGame();
            if (cross.checkStatus())
                break;
            cross.chooseCell();
        }
        break;

    case 2:
        cout << "Testing class Vector{}..." << endl;
        emptyVector.assignElem(3);
        emptyVector.getElem();
        emptyVector.output();
        initArrayOneParam.output();
        if (pointerArr.getState() != OK) cout << " Object pointer 1 = [0]: 0, [1]: 0, [2]: 0 \n"; //Here, I need to figure it out 
        pointerArr.output();
        if (anotherPointerArr.getState() != OK) cout << " Object pointer 1 = [0]: 0, [1]: 0, [2]: 0 \n";
        cout << "\n Quantity of created objects: " << Vector::getCount() << endl;
        cout << " Input data in objInput(x, y, z): ";
        arrInput.input();
        arrInput.divideShort(5);
        arrInput.output();
        
        break;

    default:
        cout << "Try again!";
        break;
    }

    return answerTask;
}

int main() {
    int answer;
    cout << "Choose a task! Enter number from 1 to 3" << endl;
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";

    do {
        cout << "\n    Enter: "; cin >> answer;
        showTask(answer);
    } while (answer <= 0 || answer > 3);

    return 0;
}
