//
//  Program 2
//  Software:
//  Machine: Macbook Pro
//  Operating System: MacOS
//  Compiler: clang
//  IDE: Xcode
//  Created by Krish Chanda on 9/17/22.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstring>
#include <ctype.h>
#include <stdio.h>

using namespace std;


// Tests to see if a file works
void testSoftware(string text)
{
    ofstream file("FindMe.txt"); // creates a new textfile
    
    if(!file.is_open()) // error message if file cannot be opened
    {
        cout << "unable to open the file: ";
    }
    else
    {
        file << text; // adds string parameter to the file
        file.close();
        cout << "File is closed ";
    }
    
    // file is closed
    
}

// Loads Cipher text file into code editor
void loadCipher(string *ptr)
{
    ifstream file("Cipher.txt"); // opens file
    
    stringstream stream;
    
    stream << file.rdbuf(); // collects file data
    
    *ptr = stream.str(); // sets the text of the file to the string
    
    
    
    
}

// iterates through the cipher string and only keeps alphabets and makes them upper case
void cleanText(string cipher, string *result)
{
    for (int i = 0; i < cipher.length(); i++) // iterates through loop
    {
        if(isalpha(cipher[i])) // checks if char is a letter or not
        {
            *result += toupper(cipher[i]); // if letter, make it upper and add it to string
            
        }
    }
}


// displays the set of 8 characters in the text and the selected char from the sequence
char displayData(string set, int num)
{
    cout << num << ":";
    for (int i = 0; i < 8 - num; i++) // initial for loop, displays (8 - num) dots
    {
        cout << ".";
    }
    cout << set.substr(0, num); // prints out the sequence of chars from 0 to index
    cout << "[";
    cout << set.substr(num - 1, 1); // prints out index
    cout << "]";
    cout << set.substr(num); // prints out rest of sequence
    for (int i = 0; i < num; i++) // final for loop that prints out (num) dots
    {
        cout << ".";
    }
    cout << " " << endl;
    return set[num - 1]; // returns a char to put in final code
}

// sorts the cipher string into 8 char sequences and finds the char based on given index
void process(string stringCipher, string* decodedCipher, string* string2)
{
    cleanText(stringCipher, decodedCipher); // cleans string
    string stringArray[73];
    int sequence[] = { 7, 8, 7, 6, 5, 6, 5, 4, 3, 4, 3, 2, 1, 1, 2, 3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8, 8 , 7, 8, 7, 6, 5, 6, 5, 4, 3, 4, 3, 2, 1, 1, 2, 3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8, 8 , 7, 8, 7, 6, 5, 6, 5, 4, 4, 3, 3, 2, 1, 1, 2, 3, 4}; // cipher code
    
    int count = 0;
    for (int i = 0; i < 73; i++){ // for loop goes through sequence of 8 chars
        
        stringArray[i] = decodedCipher->substr(count, 8); // calls the decoded Cipher function
        count = count + 8; // goes to next sequence of 8 sequence
    }
    
    for(int i = 0; i < 73; i++) // adds char to a string pointer
    {
        char a = displayData(stringArray[i], sequence[i]);
        *string2 += a;
    }
    
}

// prints out string code into 3 different lines
void deCode(string code)
{
    cout << "\n";
    cout << code.substr(0, 28) << endl; 
    cout << "\n";
    cout << code.substr(28, 24) << endl;
    cout << "\n";
    cout << code.substr(52, 21) << endl;
    
}


int main(int argc, const char * argv[]) {
    
    // Name output
    cout << "Krish Chanda\nCS 1337-503\nProgram 2\n" << endl;
    cout << "=======================" << endl;
    
    string t = "This is only a test";
    
    // initialize variables
    string cipher = "";
    string cleanedText = "";
    string code = "";
    
    
    // function calls
    loadCipher(&cipher);
    cout << cipher << "\n"; // prints original code
    process(cipher, &cleanedText, &code); // finds the index of chars and prints the strings in sequence of 8 chars
    deCode(code); // prints final message
    
    //cout << cleanedText;
    
    //string temp = "DSBUTISA";
    //char c = displayData(temp, 5);
    
    return 0;
}
