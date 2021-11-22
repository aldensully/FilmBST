#include <iostream>
#include "Submenu.h"
#include "FilmDS.h"
#include <stack>
using namespace std;
class AboutMenu : public Submenu{
    public:
        void display(){
            cout << "\nThis application lets you search and explore the top films of 2017 using a simple binary search tree. Follow the prompts on screen or enter '?' at any time for help." << endl;
        };
        void run(stack<Submenu*>& submenus, FilmDS films ){
            display();
            string userInput;
            char inp;
             
            while(inp != 'x' && inp != 'X'){
                cout << "Enter 'X' to go back: ";
                cin >> userInput;
                inp = userInput[0];
            } 
            submenus.pop();

        }

        ~AboutMenu(){};
};
