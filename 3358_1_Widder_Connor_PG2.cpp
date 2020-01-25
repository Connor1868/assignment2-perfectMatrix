//Roster Number: 72 & 75
//
//Author: Connor Widder
//Due Date: 09/25/2019
//Assignment Number 2
//Fall - 2019 - CS 3358 - 001
//Instructor: Husain Gholoom
//
//Program will display random numbers in matrix pattern
//as size based will be based on user input and display
//row, column, and diagonal sum information to determine
//if random number assortment is a perfect number or not
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

void prompt(int&); //initiates user to begin entering number for matrix size
void displayMatrix(int&, int&); //displays matrix based on user input
int randomNumberGenerator(int&); //generates random numbers for vector placement
void perfectNumberVerification(int&, vector< vector<int> > &); //verifies perfect number criteria


//**********************************************
//Main will walk user through the algorithm and
//entirety of program for matrix and perfect number
//development
//**********************************************
int main(){
    srand(time(0)); //ensures proper random numbers each run

    int matrixSize; //initiated by user to create matrix size
    int randNum; //placement for random number
    char answer; //user answer for continuation of program
    do{
        prompt(matrixSize);
        displayMatrix(matrixSize, randNum);
        cout << "Would you like to find another perfect matrix? " << endl;
        cin >> answer;
    }while (answer == 'y' || answer == 'Y');


    if (answer == 'n' || answer == 'N'){
        cout << endl
             << "This algorithm is implemented by Tristan Wells & Connor Widder "
             << endl;
        return 0;
    }
    else if (answer != 'y' || answer != 'Y' || answer != 'n' || answer != 'N'){
         cout << "Error *** Invalid Choice - Must enter y|Y or n|N" << endl;
    }

    return 0;
}


//****************************************
//Prompt will begin user interaction to
//determine matrix size based on user input
//
//Param-1-matrixSize will be passed as the size
//of the matrix as it will be used in other
//functions repeatedly
//****************************************
void prompt(int &matrixSize){

    cout << "Enter the size of the matrix: ";
    cin >> matrixSize;
    if (matrixSize <= 0 || matrixSize > 10){
        cout << "Error *** Invalid Choice - Size must be > 1 and < 11" << endl;
        prompt(matrixSize);
    }
}


//***************************************
//displayMatrix will sequentially display the
//two dimensional vector the random numbers
//have been placed in
//
//Param-1-matrixSize will be passed as the size
//of the matrix as it will be used in other
//functions repeatedly
//Param-2-x is a placeholder for the random
//numbers and they are placed in the vector
//***************************************
void displayMatrix( int &matrixSize , int &x){

    int rows = matrixSize;
    int cols = matrixSize;

    vector<vector<int> >matrix(rows, vector<int>(cols));

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++){
            matrix[i][j] = randomNumberGenerator(x);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    perfectNumberVerification(matrixSize, matrix);
}


//************************************
//randomNumberGenerator will generate the
//random numbers needed to fill vector
//elements
//
//Param-1-x is a placeholder for the random
//numbers and they are placed in the vector
//************************************
int randomNumberGenerator(int& x){

    x = rand() % 10;
    return x;
}

//********************************************
//perfectNumberVerification will go through the
//proccess of checking the sum values of all columns
//and rows, as well as diagonal summations to
//determine if the given matrix defines the perfect
//number with all values matching
//
//Param-1-matrixSize will be passed as the size
//of the matrix as it will be used in other
//functions repeatedly
//Param-2-matrix is the reference variable of the
//two dimensional vector we are using to display
//our random numbers
void perfectNumberVerification(int &matrixSize, vector< vector<int> > &matrix){

    int rowSum = 0; //sum of row values
    int colSum = 0; //sum of column values
    int diagSum = 0; //sum of diagonal values
    int secDiagSum = 0; //sum of inverted diagonal values
    int i; //index variable
    int j; //secondary index variable
    int total = 0; //sum of all numbers in matrix

    for(i = 0; i < matrixSize; i++){
        for(j = 0; j < matrixSize; j++){
            total = total + matrix[i][j];
        }
    }
    cout << "The perfect number is : " << total/matrixSize << endl << endl;
    //algorithm to determine perfect number
    for(i = 0; i < matrixSize; i++){
        for(j = 0; j < matrixSize; j++){
            rowSum = rowSum + matrix[i][j];
            //total = total + matrix[i][j];
        }//algorithm to determine row sums
        cout << "Sum of numbers in Row # " << i+1 << " = " << rowSum << endl;
        rowSum = 0; //displays various row sums
    }
    cout << endl;
    //algorithm to determine column sums
    for(i = 0; i < matrixSize; i++){
        for(j = 0; j < matrixSize; j++){
            colSum = colSum + matrix[j][i];
            //total = total + matrix[i][j];
        }
        cout << "Sum of numbers in Column # " << i+1 << " = " << colSum << endl;
        colSum = 0; //displays various column sums
    }
    cout << endl;
    for(i = 0; i < matrixSize; i++)
        diagSum = diagSum + matrix[i][i];//displays diagonal sum
        cout << "Sum of numbers in first diagonal " << " = " << diagSum << endl;

    for(i = 0; i < matrixSize; i++){
            secDiagSum = secDiagSum + matrix[i][(matrixSize-1) - i];
    }//displays inverted diagonal sum
        cout << "Sum of numbers in second diagonal " << " = " << secDiagSum << endl
             << endl;

    if (rowSum == colSum && diagSum == secDiagSum){
        int perfect_num = total;
        cout << "The above is a perfect matrix" << endl << endl;
    }//determines if matrix reaches perfect criteria
    else
        cout << "The above is not a perfect matrix" << endl << endl;

}

