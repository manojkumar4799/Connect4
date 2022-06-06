#include <iostream>
using namespace std;

class Connect4 {
private:
    int array[6][7]{ 0 };
    int rows[7]{ 5,5,5,5,5,5,5 };
    int totalPlacesOccupied = 0;

public:
    int RedPlayerTurn() {

        int insertCol;
        cout << endl << "choose a column to push red ball: ";
        cin >> insertCol;

        if (insertCol < 0 || insertCol >= 7) {

            cout << endl << " chosen column is invalid, please choose a valid column";
            RedPlayerTurn();
            return 0;
        }
        if (rows[insertCol] < 0) {

            cout << "column you chose has been full, please select other column";
            RedPlayerTurn();
            return 0;
        }

        array[rows[insertCol]][insertCol] = 1;
        PrintArray();
        if (DiagonalCheck(rows[insertCol], insertCol, array[rows[insertCol]][insertCol]) >= 4) {
            cout << endl << "Diagonal match for Red player";
            return 1;
        }
        if (HorizontalCheck(rows[insertCol], insertCol, array[rows[insertCol]][insertCol]) >= 4) {

            cout << endl << "Horizontal match for Red player";
            return 1;
        }
        if (VerticalCheck(rows[insertCol], insertCol, array[rows[insertCol]][insertCol]) >= 4) {

            cout << endl << "Vertical match for Red player";
            return 1;
        }
        totalPlacesOccupied++;
        rows[insertCol]--;
        return 0;

    }


    int BluePlayerTurn() {

        int insertCol;
        cout << endl << "choose a column to push blue ball: ";
        cin >> insertCol;

        if (insertCol < 0 || insertCol >= 7) {

            cout << endl << " chosen column is invalid, please choose a valid column";
            BluePlayerTurn();
            return 0;
        }

        if (rows[insertCol] < 0) {

            cout << "column you chose has been full, please select other column";
            BluePlayerTurn();
            return 0;
        }

        array[rows[insertCol]][insertCol] = 2;
        PrintArray();
        if (DiagonalCheck(rows[insertCol], insertCol, array[rows[insertCol]][insertCol]) >= 4) {

            cout << endl << "Diagonal match for Blue player";
            return 1;
        }
        if (HorizontalCheck(rows[insertCol], insertCol, array[rows[insertCol]][insertCol]) >= 4) {

            return 1;
            cout << endl << "Horizantal match for Blue player";
        }
        if (VerticalCheck(rows[insertCol], insertCol, array[rows[insertCol]][insertCol]) >= 4) {

            cout << endl << "Vertical match for Blue player";
            return 1;
        }
        totalPlacesOccupied++;
        rows[insertCol]--;
        return 0;

    }

    int GetOccupiedPlaces() {
        return totalPlacesOccupied;
    }

    int DiagonalCheck(int x, int y, int playerType) {

        int numOfConnects = 0;
        for (int tempx = x, tempy = y; tempx < 6 && tempy < 7 && array[tempx][tempy] == playerType; tempx++, tempy++) {

            numOfConnects++;
        }

        for (int tempx = x - 1, tempy = y - 1; tempx >= 0 && tempy >= 0 && array[tempx][tempy] == playerType; tempx--, tempy--) {

            numOfConnects++;
        }

        if (numOfConnects >= 4) {

            return numOfConnects;
        }
        else
            numOfConnects = 0;


        for (int tempx = x, tempy = y; tempx < 6 && tempy >= 0 && array[tempx][tempy] == playerType; tempx++, tempy--) {

            numOfConnects++;
        }

        for (int tempx = x - 1, tempy = y + 1; tempx < 6 && tempy >= 0 && array[tempx][tempy] == playerType; tempx--, tempy++) {

            numOfConnects++;
        }


        return numOfConnects;
    }


    int HorizontalCheck(int x, int y, int playerType) {

        int numOfConnects = 0;

        for (int tempy = y; tempy < 7 && array[x][tempy] == playerType; tempy++) {
            numOfConnects++;
        }

        for (int tempy = y - 1; tempy >= 0 && array[x][tempy] == playerType; tempy--) {
            numOfConnects++;
        }
        return numOfConnects;
    }


    int VerticalCheck(int x, int y, int playerType) {

        int numOfConnects = 0;

        for (int tempx = x, tempy = y; tempx < 6 && array[tempx][y] == playerType; tempx++) {

            numOfConnects++;
        }

        return  numOfConnects;

    }

    void PrintArray() {
        cout << endl;
        for (int i = 0; i < 6; i++) {
            cout << "-----------------------------" << endl;
            for (int j = 0; j < 7; j++) {

                cout << "| ";
                if (array[i][j] == 1)
                    cout << "R ";
                else if (array[i][j] == 2)
                    cout << "B ";
                else
                    cout << "* ";
            }
            cout << "| " << endl;


        }
        cout << "-----------------------------" << endl;
    }

    void RowPrint() {
        for (int i = 0; i < 7; i++) {

            cout << rows[i] << " ";
        }
    }
};

int main() {
    Connect4 game;
    while (game.GetOccupiedPlaces() != 42) {
        if (game.RedPlayerTurn() == 1) {

            cout << endl << "Red player won";
            break;
            return 0;
        }
        if (game.BluePlayerTurn() == 1) {

            cout << endl << "Blue player won";
            break;
            return 0;
        }
    }
    cout << endl << "DRAW GAME!!";
    return 0;

}