#include "FilmDS.h"
#include "BinarySearchTree.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

string titleQuery;
bool resultFlag = false;
vector<string>keywords;
string studioQuery;
string monthQuery;
int int_monthQuery;

FilmDS::FilmDS(){
    BinarySearchTree<Film> filmsBST;
}


//these global functions are passed to the binary search tree via 
//the member functions at the bottom

void displayAllInfo(Film& item) {
    item.printAllInfo();
}
void displayTitle(Film& item){
    item.printTitle();
}

void titleSearch(Film& item){
    string cleaned;
    char ch;
    //make filmTitle lowercase to compare to query 
    for(int i=0;i<item.getFilmTitle().length();i++){
        ch = tolower(item.getFilmTitle()[i]);
        cleaned = cleaned + ch;
    }
    //compare to current film
    if(cleaned == titleQuery){
        resultFlag = true; //flag tells 'searchByTitle' nothing was found
        cout << item.getFilmTitle() << " " << to_string(item.getRank());
    }

}
void keywordSearch(Film& item){
    string cleaned;
    char ch;
    //make film title lowercase to compare to query
    for(int i=0;i<item.getFilmTitle().length();i++){
        ch = tolower(item.getFilmTitle()[i]);
        cleaned = cleaned + ch;
    }
    //iterate through keywords and compare with current film title
    //using cstring strstr method
    for(int j=0;j<keywords.size();j++){
        if(strstr(cleaned.c_str(),keywords.at(j).c_str())){
            resultFlag = true;
            cout << item.getFilmTitle() << endl;
        }
    }
}
void studioSearch(Film& item){
    string cleaned;
    char ch;

    for(int i=0;i<item.getStudio().length();i++){
        ch = tolower(item.getStudio()[i]);
        cleaned = cleaned + ch;
    }
    if(cleaned == studioQuery){
        resultFlag = true;
        cout << "title: " << item.getFilmTitle() << ", studio: " << item.getStudio() << endl;
    }
}
void monthSearch(Film& item){
    //start here... film dates are in strings and you need to compare 
    //with a month integer so figure that out
    //then i think the only thing left to do is the orderbyrank
}



void FilmDS::add(const Film& film){
    filmsBST.add(film);
}
void FilmDS::remove(const Film& film){
    //filmsBST.remove(film);
}
void FilmDS::displayInOrder(){
    filmsBST.inorderTraverse(displayTitle);
}
void FilmDS::displayInRankOrder(){
    cout << "order by rank not set up yet" << endl;
}
void FilmDS::displayTitles(){
}

//calls bst to search for title, passing global function at top^
void FilmDS::searchByTitle(string title){
    resultFlag = false;
    titleQuery = title;
    filmsBST.inorderTraverse(titleSearch);
    if(!resultFlag){
        cout << "FILM NOT FOUND" << endl;
    }
}

//calls bst to search for keywords, keywords stored in global vector at top
void FilmDS::searchByKeyword(string keyword){
    resultFlag = false; //reset flag
    keywords.clear(); //reset keywords
    stringstream ss(keyword);
    while(ss.good()){
    string substr;
            getline(ss,substr, ',');
            if(substr[0] == ' '){
            substr.erase(0,1);
        }
        keywords.push_back(substr);
    }
    filmsBST.inorderTraverse(keywordSearch);
    if(!resultFlag){
        cout << "NO FILMS FOUND BASED ON KEYWORD(S)" << endl;
    }
}
void FilmDS::searchByStudio(string studio){
    resultFlag = false; //reset flag
    studioQuery = studio;
    filmsBST.inorderTraverse(studioSearch);
    if(!resultFlag){
        cout << "NO FILMS FOUND BASED ON KEYWORD(S)" << endl;
    }
}
void FilmDS::searchByMonth(string month){

}
