#include <iostream>
#include "Submenu.h"
#include "FilmDS.h"
#include <stack>
using namespace std;
class AboutMenu : public Submenu{
    public:
        void display(){
            cout << "\nThis application lets you search the top films of 2017 using a binary search tree. The Reports Menu gives you the option to see the films displayed in alphabetical order and in rank order. The Search Menu allows search by title, keywords, studio and month. Follow the prompts on screen or enter '?' at any time for help." << endl;
        };
        void run(stack<Submenu*>& submenus, FilmDS films ){
            display();
            string userInput;
            char inp;
             
            while(inp != 'x' && inp != 'X'){
                cout << "\nEnter 'x' to go back: ";
                cin >> userInput;
                inp = userInput[0];
            } 
            submenus.pop();

        }

        ~AboutMenu(){};
};
