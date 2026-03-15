#include <iostream>
#include <cmath>
using namespace std;

class Queens {
private:
    int r1, c1;
    int r2, c2;

public:
    Queens(int row1, int col1, int row2, int col2) {
        r1 = row1;
        c1 = col1;
        r2 = row2;
        c2 = col2;
    }

    bool canAttack() {

        // misma fila
        if (r1 == r2) return true;

        // misma columna
        if (c1 == c2) return true;

        // misma diagonal
        if (abs(r1 - r2) == abs(c1 - c2)) return true;

        return false;
    }
};

int main() {

    // ejemplo del problema
    Queens q(3, 2, 6, 5);

    if (q.canAttack())
        cout << "Las reinas pueden atacarse" << endl;
    else
        cout << "Las reinas NO pueden atacarse" << endl;

    return 0;
}