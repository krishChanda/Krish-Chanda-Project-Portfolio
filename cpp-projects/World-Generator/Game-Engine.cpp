//
//
//  Created by Krish Chanda on 10/25/22.
//Software:
//  Machine: Macbook Pro
//  Operating System: MacOS
//  Compiler: clang
//  IDE: Xcode
//  Created by Krish Chanda on 10/25/22.

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

//user Struct
struct User {
    string name;
    char mapSymbol;
    string quest;
    string nonsense;
    int row, column;
};
//creature struct
struct Creature {
    string name;
    char mapSymbol;
    int row, column;
};
// grid struct
struct Grid {
    char mapSymbol;
    int row, column;
    
};

// prints name, class, and program #
void myName(){
    cout << "Krish Chanda\nCS 1337.502\nProgram #4\n---------------------" << endl;
}
//loads the data from the file
void loadFile(User *user, vector<Creature> *creatureVec, vector<Grid> * gridVec){
    //variable declarations
    string userSym = "";
    
    //file stream
    fstream file;
    file.open("Save.txt", ios::in);
    if (!file.is_open()){
        cout << "file did not open" << endl;
    }
    
    //data collection
    string rowS = "";
    string colS = "";
    getline(file, user->name, ',');
    getline(file, user->quest, ',');
    getline(file, user->nonsense, ',');
    getline(file, userSym, ',');
    getline(file, rowS, ',');
    getline(file, colS, '\n');
    
    int row = stoi(rowS);
    int col = stoi(colS);
    user->row = row;
    user->column = col;
    user->mapSymbol = userSym[0];
    string vLenString = "";
    getline(file, vLenString, '\n');
    int vLenCreature = stoi(vLenString);
    
    // collects every creature in the string
    for (int i = 0; i < vLenCreature; i++){
        Creature *temp = nullptr;
        string creatureName = "";
        getline(file, creatureName, ',');
        
        
        string creatureSym = "";
        getline(file, creatureSym, ',');
        char cSym = creatureSym[0];
        
        
        int cRow, cCol;
        string sRow, sCol;
        getline(file, sRow, ',');
        getline(file, sCol, '\n');
        cRow = stoi(sRow);
        cCol = stoi(sCol);
        
        // assigns the input to the creature struct
        temp = new Creature;
        temp->name = creatureName;
        temp->mapSymbol = cSym;
        temp->row = cRow;
        temp->column = cCol;
        creatureVec->push_back(*temp);
        
    }
    
    // data collection for grid vector
    getline(file, vLenString, '\n');
    int vLenGrid = stoi(vLenString);
    
    for (int i = 0; i < vLenGrid; i++){
        Grid *temp = nullptr;
        
        
        
        
        int cRow, cCol;
        string sRow, sCol;
        getline(file, sRow, ',');
        getline(file, sCol, ',');
        cRow = stoi(sRow);
        cCol = stoi(sCol);
        
        string gridSym = "";
        getline(file, gridSym, '\n');
        char gSym = gridSym[0];
        
        // assigns file input to grid structure
        temp = new Grid;
        temp->mapSymbol = gSym;
        temp->row = cRow;
        temp->column = cCol;
        gridVec->push_back(*temp);

    }
    
}

//displays the file input into text editor
void display(User u, vector<Creature> c, vector<Grid> g){
    char array[10][10]; // 2d array for grid
    // sets each element to '.'
    for(int i = 0; i < sizeof(array)/10; i++){
        for(int j = 0; j < sizeof(array[i])/10; j++){
            array[i][j] = '.';
        }
    }
    //adds symbols from the file grid to the 2d array
    for (int i = 0; i < g.size(); i++){
        array[g[i].row][g[i].column] = g[i].mapSymbol;
    }
    // adds creatures to the grids
    for (int i = 0; i < c.size(); i++){
        array[c[i].row][c[i].column] = c[i].mapSymbol;
    }
    
    // adds user to the grid
    array[u.row][u.column] = u.mapSymbol;
    
    
    //displays the grid
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << array[i][j];
        }
        cout << endl;
    }
    cout << endl;
    //displays all the creatures
    for (int i = 0; i < c.size(); i++){
        cout << c[i].mapSymbol << ": " << c[i].name << endl;
    }
    cout << endl;
    //displays user struc values
    cout << u.mapSymbol << ": " << u.name << endl;
    cout << u.quest << endl;
    cout << u.nonsense << endl;


}

int main(int argc, const char * argv[]) {
    // main function, calls rest of functions
    User u;
    vector<Creature> c;
    vector<Grid> g;
    myName();
    loadFile(&u, &c, &g);
    display(u, c, g);

    return 0;
}
