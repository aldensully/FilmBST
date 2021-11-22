#include "FilmDS.h"
#include "BinarySearchTree.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstring>
#include <cassert>
#include <unordered_set>
using namespace std;

string titleQuery;
bool resultFlag = false;
vector<string>keywords;
unordered_set<int>blacklist={};
string minRankFilm;
string studioQuery;
string monthQuery;
int minRank = 101; //default value 


//----------------
//Global Functions
//----------------
void displayAllInfo(Film& item) {
    item.printAllInfo();
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
        item.printAllInfo();
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
    for(int j=0;j<keywords.size();j++){
        if(strstr(cleaned.c_str(),keywords.at(j).c_str())){
            resultFlag = true;
            item.printAllInfo();
        }
    }
}

void studioSearch(Film& item){
    string cleaned;
    char ch;
    //convert to lowercase
    for(int i=0;i<item.getStudio().length();i++){
        ch = tolower(item.getStudio()[i]);
        cleaned = cleaned + ch;
    }
    //compare
    if(cleaned == studioQuery){
        resultFlag = true;
        item.printAllInfo();
    }
}

void monthSearch(Film& item){
    string date = item.getOpeningDate();
    //look for substring of month in the items opening date
    if(strstr(date.c_str(),monthQuery.c_str())){
        resultFlag = true;
        item.printAllInfo();
    }
}

//for printing out films by increasing rank. uses global vars 
void findMin(Film& item){
    int tempRank = item.getRank();
    if((tempRank < minRank) && blacklist.count(tempRank) == 0){
        minRank = tempRank;
        minRankFilm = item.getAllInfo(); //store formatted film info
    }
}

void outputHeader(){
    cout << setw(50) << left << "TITLE" << setw(10) << "RANK" << setw(10) << "STUDIO" << setw(20) << "TOTAL GROSS" << setw(20) << "TOTAL THEATERS" << setw(20) << "OPENING GROSS" << setw(20) << "OPENING THEATERS" << "OPENING DATE" << endl;
}

//----------------------------------------------------------
//Member functions. These are called in the submenus at runtime
//----------------------------------------------------------

FilmDS::FilmDS(){
    BinarySearchTree<Film> filmsBST;
}

void FilmDS::add(const Film& film){
    filmsBST.add(film);
}

void FilmDS::remove(const Film& film){
    //filmsBST.remove(film);
}
void FilmDS::displayInOrder(){
    outputHeader();
    filmsBST.inorderTraverse(displayAllInfo);
}

void FilmDS::displayInRankOrder(){
    outputHeader();
    minRank = 101; //reset global values
    blacklist.clear(); 
    while(blacklist.size() < 100){
        filmsBST.inorderTraverse(findMin);
        blacklist.insert(minRank);
        cout << minRankFilm; //minRankFilm contains preformatted output
        minRank = 101;
    }
}

void FilmDS::searchByTitle(string title){
    outputHeader();
    resultFlag = false;
    titleQuery = title;
    filmsBST.inorderTraverse(titleSearch);
    if(!resultFlag){
        cout << "FILM NOT FOUND" << endl;
    }
}

void FilmDS::searchByKeyword(string keyword){
    outputHeader();
    resultFlag = false; //reset flag
    keywords.clear(); //reset keywords
    stringstream ss(keyword);
    while(ss.good()){
    string substr;
            getline(ss,substr, ',');
            if(substr[0] == ' '){
            substr.erase(0,1);
        }
        keywords.push_back(substr); //global vec of keywords
    }
    filmsBST.inorderTraverse(keywordSearch);
    if(!resultFlag){
        cout << "NO FILMS FOUND" << endl;
    }
}

void FilmDS::searchByStudio(string studio){
    outputHeader();
    resultFlag = false; //reset flag
    studioQuery = studio;
    filmsBST.inorderTraverse(studioSearch);
    if(!resultFlag){
        cout << "NO FILMS FOUND" << endl;
    }
}

void FilmDS::searchByMonth(string month){
    outputHeader();
    //global vars 
    resultFlag = false;
    monthQuery = month;

    filmsBST.inorderTraverse(monthSearch);
    if(!resultFlag){
        cout << "NO FILMS FOUND" << endl;
    }
}

