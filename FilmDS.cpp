#include "FilmDS.h"
#include "BinarySearchTree.h"
#include <vector>
#include <iostream>
using namespace std;

string titleQuery;
string keywordQuery;
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
    if(item.getFilmTitle() == titleQuery){
        cout << "found film!" << endl;
        cout << item.getFilmTitle() << endl;
        cout << item.getStudio() << endl;
    }
}




void FilmDS::add(const Film& film){
    filmsBST.add(film);
}
void FilmDS::remove(const Film& film){
    //filmsBST.remove(film);
}
void FilmDS::displayInOrder(){
    filmsBST.inorderTraverse(displayAllInfo);
}
void FilmDS::displayTitles(){
}
void FilmDS::searchByTitle(string title){
    cout << "searched for " << title << endl;
    titleQuery = title;
    filmsBST.inorderTraverse(titleSearch);
}
void FilmDS::searchByKeyword(string keyword){

}
void FilmDS::searchByStudio(string studio){

}
void FilmDS::searchByMonth(string month){

}
