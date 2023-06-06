#include "header.h"
#include "search.h"
#include "sort.h"
#include "main.h"

//---------------------------------------------- MAIN ----------------------------------------------//
int main(){
    clear;
    int pilihan;
    home: 
        cout << "1. Mencari String di dalam file\n";
        cout << "2. Mencari String di dalam String\n";
        cout << "3. Mencari String di dalam Array String\n";
        cout << "4. Mencari integer di dalam Array Integer\n";
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        ignore;
        if (pilihan == 1){
            stringInFile();
        } else if (pilihan == 2){
            stringInString();
        } else if (pilihan == 3){
            stringInArray();
        } else if (pilihan == 4){
            integerInArray();
        } else{
            clear;
            goto home;
        }
    getch(); //menahan terminal
    return 0; //mengembalikan nol sebagai tanda program berjalan sampai akhir tanpa masalah
}