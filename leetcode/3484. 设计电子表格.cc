#include <string>
#include <vector>
using namespace std;

class Spreadsheet {
public:
    Spreadsheet(int rows) {
        rows_ = rows;
        table = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        int row = stoi(cell.substr(1)) - 1;
        table[row][col - 'A'] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        int row = stoi(cell.substr(1)) - 1;
        table[row][col - 'A'] = 0;
    }
    
    int getValue(string formula) {
        int pos = formula.find('+');
        string left = formula.substr(1, pos - 1);
        string right = formula.substr(pos + 1);
        int l = 0, r = 0;
        if (isalpha(left[0])) {
            char col = left[0];
            int row = stoi(left.substr(1)) - 1;
            l = table[row][col - 'A'];
        } else {
            l = stoi(left);
        }
        if (isalpha(right[0])) {
            char col = right[0];
            int row = stoi(right.substr(1)) - 1;
            r = table[row][col - 'A'];
        } else {
            r = stoi(right);
        }
        return l + r;
    }

private:
    vector<vector<int>> table;
    int rows_;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */