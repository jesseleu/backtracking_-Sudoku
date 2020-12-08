//
//  main.cpp
//  JesseLeuProject3
//  Jesse Leu
//  Student ID :1979040
//  CSC501
//  ***********************************************************************
//  This program solve a sudoku puzzle, users input a string represents
//  a sudoku problem then the program will print out the puzzle with format and
//  print out the formatted solution.
//  ***********************************************************************
//  Created by Jesse L on 11/6/19.
//  Copyright © 2019 Jesse L. All rights reserved.
//
#include <istream>
#include <iostream>
#include "Puzzle.h"
int main() {
    Puzzle my;
    std::cout << "Please enter:" << std::endl;
    std::cin >> my;
    std::cout << "Original puzzle:"<< std::endl;
    std::cout << my << std::endl;
    if (my.solve()){
        std::cout << "Solved puzzle:"<< std::endl;
        std::cout << my << std::endl;
    }
    else{
       std::cout << "We don't have solution for this >< " << std::endl;
    }
}
