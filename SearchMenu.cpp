#include "Submenu.h"
#include <iostream>
#include <stack>
#include "FilmDS.h"
#include <cstring>
using namespace std;

class SearchMenu : public Submenu{
    public:

        SearchMenu(){};
        void display();
        void run(stack<Submenu*>& submenus, FilmDS films);
        void titleSearch(FilmDS& films);
        void keywordSearch(FilmDS& films);
        void studioSearch(FilmDS& films);
        void monthSearch(FilmDS& films);
        ~SearchMenu(){};
};

void SearchMenu::display(){
    cout << "\nSearch MENU" << endl;
    cout << "T - Search by Title" << endl;
    cout << "K - Search by Keyword(s)" << endl;
    cout << "S - Search by Studio" << endl;
    cout << "M - Search by Month" << endl;
    cout << "X - Return to main menu" << endl;
}
void SearchMenu::run(stack<Submenu*>& submenus, FilmDS films){
    string userInput;
    char inp;
    bool terminate = false;

    display();
    
    while(!terminate){
        cout << "\nEnter Selection(or '?' to show menu)-> ";
        cin >> userInput;
        inp = userInput[0];
        switch(inp){
            case 'T':
                titleSearch(films);
                break;
            case 'K':
                keywordSearch(films);
                break;
            case 'S':
                studioSearch(films);
                break;
            case 'M':
                monthSearch(films);
                break;
            case '?':
                display();
                break;
            case 'x':
                terminate = true;
                break;
            case 'X':
                terminate = true;
                break;
            default:
                break;
        }
    }
    submenus.pop();
}
void SearchMenu::titleSearch(FilmDS& films){
    
    char ch;
    bool terminate = false;
    while(!terminate){
        string query;
        string cleaned;
        cout << "\nEnter title to search for(or '!' to cancel search): ";
        if(cin.peek() == '\n'){
            cin.ignore();
        }
        getline(cin,query);
        
        if(query == "!"){
            terminate = true;
        } else{
            for(int i=0;i<query.length();i++){
                ch = tolower(query[i]);
                cleaned = cleaned + ch;
            }
            films.searchByTitle(cleaned);
        }
    }
}
void SearchMenu::keywordSearch(FilmDS& films){
    char ch;
    bool terminate = false;
    while(!terminate){
        string query;
        string cleaned;
        cout << "\nEnter keywords as comma separated list(or '!' to cancel search): ";
        if(cin.peek() == '\n'){
            cin.ignore();
        }
        getline(cin,query);
        
        if(query == "!"){
            terminate = true;
        }
        else{
            for(int i=0;i<query.length();i++){
                ch = tolower(query[i]);
                cleaned = cleaned + ch;
            }
            films.searchByKeyword(cleaned);
        }
    }

}
void SearchMenu::studioSearch(FilmDS& films){
    char ch;
    bool terminate = false;
    while(!terminate){
        string query;
        string cleaned;
        cout << "\nEnter studio(or '!' to cancel search): ";
        if(cin.peek() == '\n'){
            cin.ignore();
        }

        getline(cin,query);
        
        if(query == "!"){
            terminate = true;
        }
        else{
            for(int i=0;i<query.length();i++){
                ch = tolower(query[i]);
                cleaned = cleaned + ch;
            }
            films.searchByStudio(cleaned);
        }
    }
}
void SearchMenu::monthSearch(FilmDS& films){
    char ch;
    bool terminate = false;
    while(!terminate){
        string query;
        int monthQuery;
        cout << "\nEnter month 1-12(or '!' to cancel search): ";
        if(cin.peek() == '\n'){
            cin.ignore();
        }

        getline(cin,query);
        
        if(query == "!"){
            terminate = true;
        }
        else{
            monthQuery = stoi(query); 
            films.searchByMonth(monthQuery);
        }
    }
}
