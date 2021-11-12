#include <iostream>
#include <fstream>
#include "Film.h"
#include "FilmDS.h"
using namespace std;

void readFile(const string FILENAME, FilmDS& films);

int main(){
    FilmDS films;
    const string FILENAME = "Films2017.csv"; 
    readFile(FILENAME, films);

    films.displayInOrder();
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
