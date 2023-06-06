//---------------------------------------------- HEADER ----------------------------------------------//
#include <iostream> //standard library
#include <conio.h> //library untuk getch()
#include <time.h> //library untuk time()
#include <fstream> //library untuk mengakses file
#include <vector> //library untuk vector
#define clear system("cls") //mendefinisikan clear sebagai system("cls") 
// #define in , // mendifinisikan in sebagai ,
#define ignore cin.ignore() // mendefinisikan ignore sebagai cin.ignore()
using namespace std;

//---------------------------------------------- SHOW ----------------------------------------------//
// menampilkan isi array

void show(int arr[], int n){ 
    cout << "Array:\n{";
    for (int i = 0; i < n; i++){
        cout << arr[i];
        if (i != n-1){
            cout << ", ";
        }
    }
    cout << "}\n";
}