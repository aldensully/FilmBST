#include "Submenu.h"
#include <iostream>
#include <stack>
#include "FilmDS.h"
#include <cstring>
#include <regex>
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

        const string months [12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
};

void SearchMenu::display(){
    cout << "\nSearch MENU" << endl;
    cout << "t - Search by Title" << endl;
    cout << "k - Search by Keyword(s)" << endl;
    cout << "s - Search by Studio" << endl;
    cout << "m - Search by Month" << endl;
    cout << "x - Return to main menu" << endl;
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
            case 't':
                titleSearch(films);
                break;
            case 'K':
                keywordSearch(films);
                break;
            case 'k':
                keywordSearch(films);
                break;
            case 'S':
                studioSearch(films);
                break;
            case 's':
                studioSearch(films);
                break;
            case 'M':
                monthSearch(films);
                break;
            case 'm':
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
        cout << "\nEnter title to search for (or '!' to cancel search): ";
        if(cin.peek() == '\n'){
            cin.ignore();
        }
        getline(cin,query);
        
        if(query == "!"){
            display();
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
        cout << "\nEnter keywords as comma separated list (or '!' to cancel search): ";
        if(cin.peek() == '\n'){
            cin.ignore();
        }
        getline(cin,query);
        
        if(query == "!"){
            display();
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
        cout << "\nEnter studio (or '!' to cancel search): ";
        if(cin.peek() == '\n'){
            cin.ignore();
        }

        getline(cin,query);
        
        if(query == "!"){
            display();
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
    regex regint("(\\+|-)?[[:digit:]]+");

    while(!terminate){
        string userInput;
        int monthQuery;
        string query;
        cout << "\nEnter month 1-12 (or '!' to cancel search): ";
        if(cin.peek() == '\n'){
            cin.ignore();
        }

        getline(cin,userInput);

        if(userInput == "!"){ //check if user wants to cancel search
            display();
            terminate = true;
        }
        else if(!regex_match(userInput,regint)){ //check if non-int
                cout << "Enter an integer" << endl; 
                cin.clear();
        }  
        else if(stoi(userInput) < 1 || stoi(userInput) > 12){ //check size
            cout << "Month must be from 1-12";
        }
        else{ //all good, search database now
            monthQuery = stoi(userInput); //convert user input to int
            query = months[monthQuery-1]; //convert to string month
            films.searchByMonth(query);
        }
    }
}
