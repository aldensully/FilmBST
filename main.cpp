#include <iostream>
#include <fstream>
#include "Film.h"
#include "FilmDS.h"
#include "Submenu.h"
#include "MainMenu.cpp"
#include <stack>

using namespace std;

void readFile(const string FILENAME, FilmDS& films);

int main(){
    string userInput;
    char inp;
    char current = 'M'; //id to keep track of current page
    bool terminate = false;

    FilmDS films;
    const string FILENAME = "Films2017.csv"; 
    readFile(FILENAME, films);
    
    stack<Submenu*>submenus;
    submenus.push(new MainMenu());    
    
    while(!submenus.empty()){
        submenus.top()->run(submenus,films);
    }
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
    };
}

