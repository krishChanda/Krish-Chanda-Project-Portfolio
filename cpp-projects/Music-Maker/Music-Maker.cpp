//
// Software:
//  Machine: Macbook Pro
//  Operating System: MacOS
//  Compiler: clang
//  IDE: Xcode
//  Created by Krish Chanda on 10/6/22.
//

//libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct Key { // key structure
    int octave;
    char letter;
    char symbol;
    float frequency;
    float wavelength;
};

struct Note { // note structure
    int octave;
    char letter;
    char symbol;
    int duration;
};


// creates a new key and takes parameters of all variables within the key struct
Key * makeKey(int octave, char letter, char symbol, float frequency, float wavelength ){
    Key *k = nullptr;
    k = new Key; // allocates new memory for a new Key
    k->octave = octave;
    k->letter = letter;
    k->symbol = symbol;
    k->frequency = frequency;
    k->wavelength = wavelength;
    
    return k;
}

// creates a new note and takes parameters of all variables within the note struct
Note * makeNote(int octave, char letter, char symbol, int duration){
    //cout << n->octave << endl;
    Note *n = nullptr;
    n = new Note; // // allocates new memory for a new Note
    n->octave = octave;
    n->letter = letter;
    n->symbol = symbol;
    n->duration = duration;
    
    return n;
}

//prints out a line of all elements in a struct key
void showKeyStruct(Key k){
    cout << setprecision(4) << fixed; // rounding of float decimal point to 4 spaces
    float a = k.frequency;
    float b = k.wavelength;
    cout << "[" << k.letter << k.symbol << k.octave << "]" << "==> ";
    cout << "(     " << k.frequency << "  *  " << k.wavelength << "    =    " << a * b <<  "    )" << endl;
    
}

//prints out a line of all elements in a struct note
void showNoteStruct(Note n){
    cout << "(" << n.letter << n.octave << n.symbol << "," << n.duration << ")" << endl;
}

// iterates through the whole key vector to print out each key in the vector
void showKeyVector(vector <Key> k){
    
    for(int i = 0; i < k.size(); i++){
        showKeyStruct(k[i]);
    }
}

// iterates through the whole note vector to print out each note in the vector
void showTuneVector(vector <Note> note){
    
    for(int i = 0; i < note.size(); i++){
        showNoteStruct(note[i]);
    }
}

// finds the matching index in the keys vector which has the same letter, octave and symbol as the note
int fetchIndex(Note n, vector <Key> k){
    for(int i = 0; i < k.capacity(); i++){
        if (k[i].letter == n.letter){
            if (k[i].octave == n.octave){
                if (k[i].symbol == n.symbol){
                    return i; // returns the index of the key vector
                }
            }
        }
    }
    return 0; // else return 0
}


// function collects all data points from the key function to key vector
void loadKey(vector <Key> * k){
    //file access
    ifstream file;
    file.open("Keys.txt");
    Key * ptr = nullptr;
    if(!file.is_open()){
        cout << "file did not open" << endl;
    }
    
    // checks to see if file is open and key vector is empty
    if (file.is_open() && k->empty()){
        
        
        
        while(!file.eof()){ // while loop runs until it is at the end of the file
            
            // string variable declarations
            string octave = "";
            string letter = "";
            string symbol = "";
            string frequency = "";
            string wavelength = "";
            
            // key values declaration
            int o = NULL;
            char l = '\n';
            char s = '\n';
            float f = 0;
            float w = 0;
            
            // collects the value of each value in a single line into the key
            getline(file, octave, ',');
            //cout << octave << endl;
            if (octave == ""){ //tests to see if it is an empty string at the end of the file
                break;
            }
            o = stoi(octave);
            getline(file, letter, ',');
            l = letter[0];
            //cout << letter << endl;
            getline(file, symbol, ',');
            s = symbol[0];
            //cout << symbol << endl;
            getline(file, frequency, ',');
            f = stof(frequency);
            //cout << frequency << endl;
            getline(file, wavelength, '\n'); // \n because it is end of file
            w = stof(wavelength);
            //cout << wavelength << endl;
            
            
            ptr = makeKey(o, l, s, f, w); // creates the key
            k->push_back(*ptr); // adds the key to the vector
            
            

        }
        
    }
    file.close(); // closes the file
    
}

//collects the file name from user
void getFileName(string * filePtr){
    cout << "Enter file name: " << endl;
    cin >> *filePtr;
    
}


// function collects all data points from the key function to note vector
void loadTune(vector <Note> *tune, string fileName){
    // opens file
    ifstream file;
    file.open(fileName);
    string n = "";
    Note * notePtr = nullptr;
    if(!file.is_open()){
        cout << "file did not open!" << endl;
    }
    
    // checks to see if file is open and note vector is empty
    if (file.is_open() && tune->empty()){
        
        while(!file.eof()){ // while loop runs until it is at the end of the file
            
            // variable declarations
            char letter = '\n';
            char octave = '\n';
            char symbol = '\n';
            int intOctave = 0;
            string duration = "";
            
            
            file.get(letter); // use get to get only a single character at a time
            if (letter == ' '){ // checks if it is at the final element of the file
                break;
            }
            file.get(octave);
            //cout << octave << endl;
            file.get(symbol);
            getline(file, duration, '\n');
            string modifiedDuration = "";
            modifiedDuration = duration.substr(1);
            int d = stoi(modifiedDuration);
            
            intOctave = octave - 48; // it is in ASCII value, so substracting 48 gives an int value
            notePtr = makeNote(intOctave, letter, symbol, d); // create a new note
            tune->push_back(*notePtr); //add note to vector tune
        }
    }
    file.close(); // close file
    
    
}

//draws a single line for the note
void drawNote(int minOctave, int maxOctave, int index, int duration){
    
    // start and end positions
    int startPos = minOctave * 17;
    int endPos = (maxOctave + 1) * 17;
    
    // prints dots until index is reached
    for(int i = startPos; i < index; i++){
        cout << ".";
        
    }
    
    // at index prints out one of the following indexs
    switch (duration) {
        case 125:
            cout << "|";
            break;
        case 250:
            cout << "+";
            break;
        case 500:
            cout << "o";
            break;
        case 750:
            cout << "O";
            break;
        case 1000:
            cout << "$";
            break;
            
        default:
            cout << "-";
            break;
    }
    
    // prints dots from the index to end position
    for(int i = index + 1; i < endPos; i++){
        cout << ".";
    }
    //end line
    cout << "\n";
    
}

// prints out the whole tune
void drawTune(vector <Note> tune, vector<Key> key){
    
    int minTemp = tune[0].octave;
    //cout << minTemp << endl;
    int maxTemp = tune[0].octave;
    //cout << maxTemp << endl;
    int minOctave = 0;
    int maxOctave = 0;
    
    // find the min Octave
    for(int i = 0; i < tune.size(); i++){
        if(tune[i].octave <= minTemp){
            minTemp = tune[i].octave;
            minOctave = minTemp;
        }
    }
    
    //find max octave
    for(int i = 0; i < tune.size(); i++){
        if(tune[i].octave >= maxTemp){
            maxTemp = tune[i].octave;
            maxOctave = maxTemp;
        }
    }
    
     
    // for each element in note vector, it prints out the note
    for (int i = 0; i < tune.size(); i++){
        int indexKey = fetchIndex(tune[i],key);
        int durationTune = tune[i].duration;
        drawNote(minOctave, maxOctave, indexKey, durationTune);
        
    }
    //cout << endl;
    
}

// prints out name
void myName(){
    cout << "Krish Chanda\nCS 1337-503\nProgram #3\nFall 2022" << endl;
}

// menu bar user interacts with
void menu(){
    
    //variable declarations
    vector<Key> key;
    vector<Note> note;
    string fileName = "Tune1.txt";
    
    // input string
    string in = "";
    int input = 0;
    while(input != 7){ // while loop runs until user clicks 7
        cout << "1. Load Key File\n2. Show Loaded Keys\n3. Set Tune Filename\n4. Load Tune File\n5. Show Tune File\n6. Draw Tune File\n7. Exit\n=========================" << endl;
        
        getline(cin, in);
        input = stoi(in);
        
        // switch statement that calls functions based on user input
        switch (input){
            case 1:
                loadKey(&key);
                
                break;
            case 2:
                showKeyVector(key);
                cout << key.size();
                break;
            case 3:
                getFileName(&fileName);
                //cout << "Enter file name" << endl;
                //cin >> fileName;
                cin.ignore(1); // clears input once user eners file name so in variable doesn't collect it
                note.clear();
                break;
            case 4:
                loadTune(&note, fileName);
                break;
            case 5:
                showTuneVector(note);
                break;
            case 6:
                drawTune(note, key);
                break;
            case 7:
                break;
                
            default:
                cout << "Please enter a Valid number from 1 - 7" << endl;
                cin.clear(); // clears user's previous input
                break;
                
        
                
            
        }
    }
    
    
}


int main(int argc, const char * argv[]) {
    // main function
    myName();
    menu();
    
    return 0;
}
