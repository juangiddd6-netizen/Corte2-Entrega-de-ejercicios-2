#include <vector>
#include <string>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid;
    int rows;

    int getCellValue(string s) {
        // si es número
        if (isdigit(s[0])) {
            return stoi(s);
        }

        // si es referencia de celda
        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;

        return grid[row][col];
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        grid[row][col] = 0;
    }

    int getValue(string formula) {
        // quitar '='
        formula = formula.substr(1);

        int plusPos = formula.find('+');

        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        return getCellValue(left) + getCellValue(right);
    }
};