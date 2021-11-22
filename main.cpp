#include <iostream>
#include <fstream>
#include "Film.h"
#include "FilmDS.h"
#include "Submenu.h"
#include "MainMenu.cpp"
#include "Film.cpp"
#include "FilmDS.cpp"
#include <stack>

using namespace std;

void readFile(const string FILENAME, FilmDS& films);

int main(){
    FilmDS films;
    const string FILENAME = "Films2017.csv"; 
    readFile(FILENAME, films);
    
    stack<Submenu*>submenus; //stack of submenus is used to show menus
    submenus.push(new MainMenu());   //push mainmenu to stack to begin 

    //program runs until mainmenu submenu is popped
    while(!submenus.empty()){
        submenus.top()->run(submenus,films); //each submenu has a run function to control their state
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
            getline(inFile, inString);
        };
        inFile.close(); 
    };
}

