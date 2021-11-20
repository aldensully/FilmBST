#include <iostream>
#include <fstream>
#include "Film.h"
#include "FilmDS.h"
using namespace std;

void readFile(const string FILENAME, FilmDS& films);
void mainMenu();
void select(char input);
void about();
void reports();
void search();

int main(){
    string userInput;
    char inp;

    FilmDS films;
    const string FILENAME = "Films2017.csv"; 
    readFile(FILENAME, films);
    
    mainMenu();

    while(inp != 'x' && inp != 'X'){
        cin >> userInput;
        inp = userInput[0];
        select(inp);
    }
    //films.displayInOrder();
    //films.searchByTitle("Dunkirk");

    return 0;
};
void readFile(const string FILENAME, FilmDS& films){
    string inString;
    ifstream inFile(FILENAME);

    if(!inFile){
        cout << "Error reading input file!" << endl;
    }
    else{
        getline(inFile,inString);
        while(inFile){
            Film newFilm(inString);
            films.add(newFilm);
            //cout << newFilm.getFilmTitle() << endl;
            getline(inFile, inString);
        };
        inFile.close(); 

        cout << "File closed!" << endl;
    };
}
void mainMenu(){
    cout << "MAIN MENU" << endl;
    cout << "A - About the Application" << endl;
    cout << "R - Reports" << endl;
    cout << "S - Search the Database" << endl;
    cout << "X - Exit the Program" << endl;
    cout << "B - Back" << endl;
    cout << "? - Help" << endl;
}
void select(char input){
    
    if(input == 'A'){
        about();
    }
    else if(input == 'R'){
        reports(); 
    }
    else if(input == 'S'){
        search();
    }
    else if(input == 'B'){
        mainMenu();
    }
    else if(input == 'X' || input == 'x'){
        cout << "Enjoy your day!" << endl;
    }
    else{
        cout << "invalid input, enter selection or enter '?' for help" << endl;
    }
}
void about(){
    cout << "welcome to the film bst application!" << endl;
}
void reports(){
    cout << "welcome to the reports page" << endl;
}
void search(){
    cout << "welcome to the search page" << endl;
}
