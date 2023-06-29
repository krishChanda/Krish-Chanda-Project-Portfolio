//
//  Program 5
//  Software:
//  Machine: Macbook Pro
//  Operating System: MacOS
//  Compiler: clang
//  IDE: Xcode
//  Created by Krish Chanda on 11/17/22.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <time.h>
using namespace std;

// Matrix class definition
class Matrix {
    private:
        vector<vector<double>> matrix; // vector of vectors matrix
    public:
    // constructor
    Matrix(){
        matrix = {{1,0,0},{0,1,0},{0,0,1}}; // default matrix
    }
    // function definitions
    void show();
    double getValue(int row, int col);
    void setValue(int row, int col, double val);
    double subDet(int row, int col);
    double determinant();
    Matrix coFactor();
    Matrix adjoint();
    Matrix inverse();

    // Matrix overloaded + function
    Matrix operator+ (const Matrix& m){
        Matrix sum;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                sum.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
            }
        }
        return sum;
    }
    
    // Matrix overloaded - function
    Matrix operator- (const Matrix& m){
        Matrix dif;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                dif.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
            }
        }
        return dif;
    }
    
    // Matrix overloaded * function
    Matrix operator* (const Matrix& m){
        Matrix multi;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int sum = 0.0;
                for(int k = 0; k < 3; k++){
                    sum = sum + (m.matrix[i][k] * this->matrix[k][j]);
                }
                multi.matrix[i][j] = sum;
            }
        }
        return multi;
    }
};

void Matrix::show(){
    // nested for loop to display each element in the matrix
    for(int i = 0; i < 3; i++){
        cout << "|";
        for(int j = 0; j < 3; j++){
            cout << fixed << setprecision(5);
            cout << matrix[i][j] << ",";
        }
        cout << "|" << endl;
    }
}
// class getter
double Matrix::getValue(int row, int col){
    
    return matrix[row][col];
}


// class setter
void Matrix::setValue(int row, int col, double val){
    matrix[row][col] = val;
}

// subDet function returns a double value of the subDet
double Matrix::subDet(int row, int col){ // takes coordianates as input
    double x = 0;
    if(row == 0){
        if(col == 0){
            x = (matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]);
        }
        else if(col == 1){
            x = (matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]);
        }
        else if(col == 2){
            x = (matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]);
        }
    }
    else if(row == 1){
        if(col == 0){
            x = (matrix[0][1] * matrix[2][2]) - (matrix[0][2] * matrix[2][1]);
        }
        else if(col == 1){
            x = (matrix[0][0] * matrix[2][2]) - (matrix[0][2] * matrix[2][0]);
        }
        else if(col == 2){
            x = (matrix[0][0] * matrix[2][1]) - (matrix[0][1] * matrix[2][0]);
        }
    }
    else if(row == 2){
        if(col == 0){
            x = (matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1]);
        }
        else if(col == 1){
            x = (matrix[0][0] * matrix[1][2]) - (matrix[0][2] * matrix[1][0]);
        }
        else if(col == 2){
            x = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        }
    }

    return x;
}
// returns a double value of the determinant
double Matrix::determinant(){
    double x = subDet(0, 0);
    double y = subDet(0, 1);
    double z = subDet(0, 2);
    
    double result = (x * matrix[0][0]) - (y * matrix[0][1]) + (z * matrix[0][2]);
    return result;
}


// Matrix coFactor function
Matrix Matrix::coFactor(){
    Matrix x;
    x.matrix[0][0] = subDet(0, 0);
    x.matrix[0][1] = subDet(0, 1) * -1;
    x.matrix[0][2] = subDet(0, 2);
    x.matrix[1][0] = subDet(1, 1) * -1;
    x.matrix[1][1] = subDet(1, 1);
    x.matrix[1][2] = subDet(1, 1) * -1;
    x.matrix[2][0] = subDet(2, 0);
    x.matrix[2][1] = subDet(2, 1) * -1;
    x.matrix[2][2] = subDet(2, 2);
    
    
    return x;
}
// Matrix adjoint function, inverses the order of coordinates
Matrix Matrix::adjoint(){
    Matrix x;
    x.matrix[0][0] = this->matrix[0][0];
    x.matrix[0][1] = this->matrix[1][0];
    x.matrix[0][2] = this->matrix[2][0];
    x.matrix[1][0] = this->matrix[0][1];
    x.matrix[1][1] = this->matrix[1][1];
    x.matrix[1][2] = this->matrix[2][1];
    x.matrix[2][0] = this->matrix[0][2];
    x.matrix[2][1] = this->matrix[1][2];
    x.matrix[2][2] = this->matrix[2][2];
    return x; // returns a class matrix
}
// Matrix inverse function
Matrix Matrix::inverse(){
    Matrix result;
    double x = determinant();
    Matrix temp1 = coFactor();
    Matrix temp2 = temp1.adjoint();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result.matrix[i][j] = temp2.matrix[i][j] / x;
        }
    }
    return result; // returns a class matrix
}

int main(int argc, const char * argv[]) {
    srand(clock()); // random
    // set values to matrix
    cout << "Demonstrate the constructor" << endl;
    Matrix matrix1; // class declaration
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            double x = rand() % 100; // assigns random number to coordinate 0 - 100
            matrix1.setValue(i, j, x);
        }
    }
    // set values for a second matrix
    Matrix matrix2; // class declaration
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            double x = rand() % 100; // assigns random number from 0 - 100 to coordianate
            matrix2.setValue(i, j, x);
        }
    }
    Matrix matrix3;
    matrix3.show(); // displays the matrix
    cout << " " << endl;
    
    // Show Matrix Addition
    cout << "Demonstrate Addition" << endl;
    matrix3 = matrix1 + matrix2;
    matrix1.show();
    cout << " " << endl;
    matrix2.show();
    cout << " " << endl;
    matrix3.show();
    cout << " " << endl;
    
    // Show Matrix Subtraction
    cout << "Demonstrate Subtraction" << endl;
    matrix3 = matrix1 - matrix2;
    matrix1.show();
    cout << " " << endl;
    matrix2.show();
    cout << " " << endl;
    matrix3.show();
    cout << " " << endl;
    
    // Show Matrix Multiplication
    cout << "Demonstrate Multiplication" << endl;
    matrix3 = matrix1 * matrix2;
    matrix1.show();
    cout << " " << endl;
    matrix2.show();
    cout << " " << endl;
    matrix3.show();
    cout << " " << endl;
    
    // Show Matrix Inversion
    cout << "Demonstrate Inversion" << endl;
    matrix2 = matrix1.inverse();
    matrix3 = matrix1 * matrix2;
    matrix1.show();
    cout << " " << endl;
    matrix2.show();
    cout << " " << endl;
    matrix3.show();
    cout << " " << endl;
    
    
    return 0;
}
