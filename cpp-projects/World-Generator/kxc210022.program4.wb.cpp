//
//  Program_4
//Software:
//  Machine: Macbook Pro
//  Operating System: MacOS
//  Compiler: clang
//  IDE: Xcode
//  Created by Krish Chanda on 10/14/22.

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

// Creature Struct
struct Creature {
    string name;
    char mapSymbol;
    int row, column;
};

// Grid Struct
struct Grid {
    char mapSymbol;
    int row, column;
    
};

// Prints out name, class, program
void myName(){
    cout << "Krish Chanda\nCS 1337.502\nProgram #4\n==============" << endl;
}

void createUser(User *u){
    srand(clock()); // for random function
    string name;
    string quest;
    string random;
    char symbol;
    int row;
    int column;
    
    
    cin.ignore(); // clears the input from the menu function
    
    // user input
    cout << "What is your name?" << endl;
    getline(cin, name);

    
    cout << "What is your quest?" << endl;
    getline(cin, quest);
    
    
    int randInt = rand() % 3; // sets a random number from 0-2
    
    //switch case to determine random question
    switch(randInt){
        case 0:
            cout << "What is your favorite color?" << endl;
            getline(cin, random);
            break;
        case 1:
            cout << "What is the capital of Assyria?" << endl;
            getline(cin, random);
            break;
        default:
            cout << "What is the airspeed velocity of an unladen swallow?" << endl;
            getline(cin, random);
            break;
    }
    
    cout << "What is your symbol?" << endl;
    cin >> symbol;

    
    cout << "What row are you in?" << endl;
    cin >> row;
    
    
    cout << "What column are you in?" << endl;
    cin >> column;

    // assignment of input to struct
    u->name = name;
    u->quest = quest;
    u->nonsense = random;
    u->mapSymbol = symbol;
    u->row = row;
    u->column = column;
    
    
}

// Creates a struct creature and adds it to a vector of creatures
void createCreature(vector <Creature> *creatureVec){
    string name;
    char symbol;
    int row, column;
    
    //user input
    cout << "What is its name?" << endl;
    cin >> name;
    
    
    cout << "What is your symbol?" << endl;
    cin >> symbol;
    
    
    cout << "What row are you in?" << endl;
    cin >> row;
    
    cout << "What column are you in?" << endl;
    cin >> column;
    
    // creates a new struct and assignes user input
    Creature *c = nullptr;
    c = new Creature;
    c->name = name;
    c->mapSymbol = symbol;
    c->row = row;
    c-> column = column;
    
    creatureVec->push_back(*c); // adds new struct to the vector
    
}

// creates a grid struct and adds it to the grid vector
void createTerrian(vector<Grid> *g){
    int rowChar = 0;
    string characters;
    cout << "What row ill this be?" << endl;
    cin >> rowChar;
    while(characters.size() != 10){ // checks to make sure user enters 10 characters
        cout << "Please type 10 characters" << endl;
        cin >> characters;
        cin.clear();
        if (characters.size() == 10){
            break;
        }
    }
    cout << "Thank you for entering 10 characters!" << endl;
    Grid *x = nullptr;
    // asigns the set of 10 characters to the vector
    for(int i = 0; i < 10; i++){
        char a = characters[i];
        x = new Grid;
        x->row = rowChar;
        x->column = i;
        x->mapSymbol = a;
        g->push_back(*x);
        
    }
   
    
}
// adds all the user struct, creature vector and grid vector to a file
void saveFile(User u, vector<Creature> c, vector<Grid> g){
    // file stream
    fstream file;
    file.open("Save.txt", ios::out);
    if (!file.is_open()){
        cout << "file did not open" << endl;
    }
    // User text output
    string userText = u.name + "," + u.quest + "," + u.nonsense + ","  + to_string(u.row) + "," + u.mapSymbol + "," + to_string(u.column);
    file << userText << endl; // adds user struct to file
    
    file << c.size() << endl; // adds size of creature vector to file
    for (int i =0; i < c.size(); i++){
        string creatureText = c[i].name + "," + c[i].mapSymbol + "," + to_string(c[i].row) + "," + to_string(c[i].column); // adds creature struct to list
        file << creatureText << endl;
    }
    
    file << g.size() << endl; // adds zise of grid vector to file
    for (int i =0; i < g.size(); i++){
        string gridText = to_string(g[i].row) + "," + to_string(g[i].column) + "," + g[i].mapSymbol;
        file << gridText << endl; // adds creature struct to list
    }
    file.close(); //close file
}

// menu function
void menu(){
    //variable declarations
    vector<Grid> grid;
    vector<Creature> creature;
    User user;
    int input = 0;
    char in = '\n';
    
    
    // keeps running until user enters (5)
    while(input != 5){
        
        cout << "1. Create User\n2. Create Creature\n3. Create a row of terrain\n4. Save File\n5. Quit\n_________________\n" << endl;
        cin.get(in);
        input = (int)in - 48; // char to int conversion
        
        if (isdigit(in)){ //checks to see if user input is a digit
            if (input == 5){
                break;
            }
            
            //switch case
            switch(input){
                case 1:
                    createUser(&user);
                    break;
                case 2:
                    createCreature(&creature);
                    break;
                case 3:
                    createTerrian(&grid);
                    break;
                case 4:
                    saveFile(user, creature, grid);
                    break;
                default:
                    cout << "Please enter a number from 1 - 5" << endl;
            }
            cin.ignore();
            
        }
        else {
            cout << "Please Enter a Number" << endl;
            cin.ignore();
        }
        
        
    }
         
}


int main(int argc, const char * argv[]) {
    // main function
    myName();
    menu();
    return 0;
}
