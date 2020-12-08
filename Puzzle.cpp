//
//  Puzzle.cpp
//  JesseLeuProject3
//  Jesse Leu
//  Student ID :1979040
//  CSC501
//  Created by Jesse L on 11/6/19.
//  Copyright © 2019 Jesse L. All rights reserved.
//
#include <vector>
#include <iostream>
#include "Puzzle.h"

#define ROW 9
#define COL 9

//constructor of square
Puzzle::square::square(){
	value = -1;
	fix = false;
}
//get value
//return value of square
int Puzzle::square::getValue()const{
	return value;
}
//set value
//int value: the value set to square
void Puzzle::square::setValue(int value){

	this->value = value;
	
}
//set bool fix to ture
void Puzzle::square::setFix(){
	fix = true;
}
//get fix status
//return true if fix is true
bool Puzzle::square::isFix()const{
	return fix;
}
//construtor of puzzle
Puzzle::Puzzle(){
	
}
//get value of a square
//int x: rol index
//int y: col index
//return the value of the position
int Puzzle::get(const int x,const int y)const{
	if(x > ROW - 1 || x < 0 || y > COL - 1 || y < 0 ){
		return -1;
	}
	return myList[x][y].getValue();
}
// set value to a square in puzzle
//int x: rol index
//int y: col index
//int value: the value set to the position
//return true if it is set
bool Puzzle::set(int x,int y,int value){
	if(!(isValid(x, y, value)) || myList[x][y].isFix()){
	return false;
	}
	myList[x][y].setValue(value);
	return true;
}
// get the size
// return  original input number of variable entries
int Puzzle::size()const{
	return puzzleSize;
}
//get the number of empty square
//return the number of empty square
int Puzzle::numEmpty()const{
	int numEmpty = 0;
		for (int i = 0; i < ROW; i++){
			 for (int j = 0; j < COL; j++){
				 if (get(i, j) == 0){
					 numEmpty++;
				 }
			 }
		}
		 return numEmpty;
}
//check if the number can be set into the square
//int x: row index
//int y: col index
//int value: the value need to be checked
//return true if the number can be set to the square
bool Puzzle::isValid(const int x,const int y,const int value)const{
	//check if x and y are valid
	if(x > ROW - 1 || x < 0 || y > COL - 1 || y < 0|| value > 9 || value < 0){
		return false;
	}
	//check rows
	for (int i = 0; i < ROW; i++){
		if (value == get(x, i) && value != 0){
			return false;
		}
	}
	// check cols
	for (int j = 0; j < COL; j++){
		if (value == get(j, y)&& value != 0){
			return false;
		}
	}
    
	int xSection = x / 3;
	int ySection = y / 3;
	//check subgrid
	for (int k = xSection * 3; k < (xSection + 1) * 3; k++){
		for (int p = ySection * 3; p < (ySection + 1) * 3; p ++){
			if (value == get(k, p)&& value != 0){
				return false;
			}
		}
	}
	return true;
}
//solve the puzzle using backtracking algorithm
//return true if solved
bool Puzzle::solve(){
	for(int row = 0; row < ROW; row++){
		for (int col = 0; col < COL ;col++){
			if (get(row, col) == 0){ //find the next empty square
				for (int i = 1; i <= 9 ;i++){
					if(set(row, col, i)){ // check if there is any possible number can put in
						if (solve()){ //if the last call return true
							return true;
						}
						else {
							set(row,col, 0);
						}
					}
				}
				return false; //return false if there is no any number can be set into a square
			}
		}
	}
	return true; // if rol and col pass the end of puzzle return true
}
// Operator >> overloaded using a member function
std::istream& operator>>(std::istream& in, Puzzle& myPuzzle){
	std::string s ="";
	std::vector<int> intList {};
	while(intList.size() < ROW * COL){ //keep reading utill get 81 digits
		in>> s;
		for (char ch :s){//check each char is digit
			if(isdigit(ch)){
				intList.push_back(ch - '0');// store the int
			}
		}
	}
	std::vector<int>::iterator it = intList.begin();
	for(int i = 0; i < ROW ; i ++ ){
		for (int j = 0; j < COL; j++){
			if(it != intList.end()){
				int next = *it;
				// if user has invalid input such as 99999, the program will set to 90000
				if(myPuzzle.set(i, j, next)){
					if(next == 0){
						//count size
						myPuzzle.puzzleSize++;
					}
					else{
						//set the square fixed if next != 0
						myPuzzle.myList[i][j].setFix();
					}
				}
				// if user has invalid input such as 99999, the program will set to 90000
				else{
					myPuzzle.set(i, j, 0);
				}
				
				it++;//it->next
			}
		}
	}
return in;
}
// Operator<< overloaded using a member function
std::ostream& operator<<(std::ostream& os,Puzzle& myPuzzle){
	for(int row = 0; row < ROW; row++){
		if(row  == 3 || row  == 6){
			os <<"------+-----+------"<<std::endl ;
		}
		for (int col = 0; col < COL ;col++){
			if(col == 3 || col == 6){
				os << "|"<< myPuzzle.get(row,col);
			}
			else{
			os <<" "<< myPuzzle.get(row,col);
			}
		}
		os<<std::endl;
	}	
return os;
}
