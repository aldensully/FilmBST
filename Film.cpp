#include "Film.h"
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<string>
#include<iomanip>

using namespace std;

Film::Film(){};
Film::Film(string data){
    string temp;
    istringstream iss(data);

    getline(iss,temp,',');
    rank = stoi(temp);
    
    getline(iss,filmTitle,',');
    getline(iss,studio,',');

    getline(iss,temp,',');
    totalGross = stod(temp);

    getline(iss,temp,',');
    totalTheaters = stoi(temp);

    getline(iss,temp,',');
    openingGross = stod(temp);

    getline(iss,temp,',');
    openingTheaters = stoi(temp);

    getline(iss,openingDate,',');
};
int Film::getRank(void){
    return rank; 
}
int Film::getTotalTheaters(void){
    return totalTheaters;
}
int Film::getOpeningTheaters(void){
    return openingTheaters;
}
double Film::getTotalGross(void){
    return totalGross;
}
double Film::getOpeningGross(void){
    return openingGross;
}
string Film::getFilmTitle(void){
    return filmTitle;
}
string Film::getOpeningDate(void){
    return openingDate;
}
string Film::getStudio(void){
    return studio;
}

//format large number
string formatNum(int num){
    auto s = to_string(num);
    int n = s.length() - 3;
    while(n>0){
        s.insert(n,",");
        n-=3;
    }
    s.insert(0,"$");
    return s;
}
//functions called in binarySearch
void Film::printAllInfo(void){
    cout << setw(50) << left << filmTitle << setw(10) << rank << setw(10) << studio << setw(20) << formatNum((int)totalGross) << setw(20) << totalTheaters << setw(20) << formatNum((int)openingGross) << setw(20) << openingTheaters << openingDate << endl; 
}
string Film::getAllInfo(void){ //outputs formatted information
    stringstream out;
    out << setw(50) << left << filmTitle << setw(10) << rank << setw(10) << studio << setw(20) << formatNum((int)totalGross) << setw(20) << totalTheaters << setw(20) << formatNum((int)openingGross) << setw(20) << openingTheaters << openingDate << endl; 
    return out.str();
}

void Film::printTitle(void) const{
    cout << filmTitle << endl;
}
//overloaded operators
bool Film::operator <(const Film& rhs) const{
    return (this->filmTitle < rhs.filmTitle);
}
bool Film::operator >(const Film& rhs)const{
    return (this->filmTitle > rhs.filmTitle);
}
bool Film::operator ==(const Film& rhs)const{
    return (this->filmTitle == rhs.filmTitle); //TODO add more fields to match on or use a unique id instead of just rank
}
