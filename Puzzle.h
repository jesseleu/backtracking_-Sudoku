//
//  Puzzle.hpp
//  JesseLeuProject3
//  Jesse Leu
//  Student ID :1979040
//  CSC501
//  Created by Jesse L on 11/6/19.
//  Copyright © 2019 Jesse L. All rights reserved.
//

#ifndef Puzzle_h
#define Puzzle_h
#define ROW 9
#define COL 9
#include <stdio.h>

//puzzle class
class Puzzle{
public:
   //construtor of puzzle
   Puzzle();
   //get value of a square
   //int x: rol index
   //int y: col index
   //return the value of the position
   int get(const int x,const int y)const;
   // set value to a square in puzzle
   //int x: rol index
   //int y: col index
   //int value: the value set to the position
   //return true if it is set
   bool set(const int x,const int y,const int value);
   // get the size
   // return  original input number of variable entries
   int size()const;
   //get the number of empty square
   //return the number of empty square
   int numEmpty()const;
   //check if the number can be set into the square
   //int x: row index
   //int y: col index
   //int value: the value need to be checked
   //return true if the number can be set to the square
   bool isValid(const int x,const int y,const int value)const;
   //solve the puzzle using backtracking algorithm
   //return true if solved
   bool solve();
   // Operator >> overloaded using a member function
   friend std::istream& operator >> (std::istream &in, Puzzle& myPuzzle);
   // Operator << overloaded using a member function
   friend std::ostream& operator << (std::ostream &os, Puzzle& myPuzzle);
   
   //nested class sqaure
   class square{
      
   private:
      //value of the square
      int value;
      // bool value indicates if is fixed
      bool fix;
      
   public:
      //constructor of square
      square();
      //get value
      //return value of square
      int getValue()const;
      //set value
      //int value: the value set to square
      void setValue(const int value);
      //get fix status
      //return true if fix is true
      bool isFix()const;
      //set bool fix to ture
      void setFix();
   };
private:
   //2d array of square
   square myList[ROW][COL];
   //size
   int puzzleSize = 0;
};
#endif /* Puzzle_h*/
