//---------------------------------------------- HEADER ----------------------------------------------//
#include <iostream> //standard library
#include <conio.h> //library untuk getch()
#include <time.h> //library untuk time()
#include <fstream> //library untuk mengakses file
#include <vector> //library untuk vector
#define clear system("cls") //mendefinisikan clear sebagai system("cls") 
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

//---------------------------------------------- SORT ----------------------------------------------//
//---------- Bubble Sort ----------//
//mengurutkan dengan cara mengecek satu persatu nilai dari array
//jika nilai a lebih besar dari nilai b, maka index kedua nya akan ditukar
//setiap perulangan dilakukan untuk mendapat nilai paling besar dan diletakkan di index paling terakhir

void bubbleSort(int arr[], int n){ 
    for (int i = 0; i < n-1; i++){ //tidak perlu melakukan perulangan sebanyak n kali, karena perulangan ke-n hanya berisi satu elemen array terakhir yang paling kecil
        for (int j = 0; j < n-i-1; j++){ //tidak perlu melakukan perulangan sebanyak n-1 kali, karena perulangan ke-(n-1) akan membandingkan nilai yang pasti paling besar
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]); //menukar index
            }
        }
    }
}

//---------- Selection Sort ----------//
//mengurutkan dengan cara mengecek satu persatu nilai dari array
//membuat variabel temporer berisi index dari nilai minimum
//bandingkan nilainya dengan setiap elemen di sebelah kanannya
//jika lebih kecil, maka index dari elemen tersebut akan menjadi index minimum.
//langkah terakhir jika index dari nilai minimum tidak sama dengan index perulangan nya maka akan ditukar
//sehingga didapat nilai terkecil dari setiap perulangan
//agak mirip dengan bubble sort, tetapi bubble sort menukar nilainya setiap kali nilai lebih kecil
//sedangkan selection sort mencatat index minimumnya dan hanya menukar 1 kali di setiap perulangan

void selectionSort(int arr[], int n){
    int minIndex; //index temporer
    for (int i = 0; i < n-1; i++){
        minIndex = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap(arr[i], arr[minIndex]);
        }
    }
}

//---------- Quick Sort ----------//
//merupakan fungsi rekursif
//membuat elemen paling kanan sebagi pivot untuk dibandingkan dengan elemen lainnya
//jika nilai elemen lain lebih kecil dari pivot maka akan diletakkan di sebelah kiri pivot
//jika nilai elemen lain lebih besar dari pivot maka akan diletakkan di sebelah kanan pivot
//selanjutnya mengurutkan kembali bagian sebelah kiri dan kanan pivot dengan cara yang sama sampai terurut

int partition(int arr[], int low, int high){
    int pivot = arr[high]; //memberi nilai pivot data yang paling kanan/terakhir
    int i = low - 1;

    for(int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

//---------- Bogo Sort ----------//
//mengurutkan dengan cara mengacak elemen pada array
//akan mengecek apakah data sudah terurut atau belum
//jika belum maka akan mengacak kembali sampai terurut
//kemungkinan terbaik adalah akan selesai dalam 1 kali pengacakan
//kemungkinan terburuk adalah tidak akan selesai karena tidak menemukan urutan yang benar sampai tak terhingga kali pengacakan

bool isSorted(int arr[], int n){ //function untuk mengecek apakah sudah terurut atau belum
    while (--n > 0){
        if(arr[n] < arr [n-1]){
            return false;
        }
    }
    return true;
}

void shuffle(int arr[], int n){ //function untuk mengacak.
    for (int i = 0; i < n; i++){
        swap(arr[i], arr[rand() % n]);
    }
}

void bogoSort(int arr[], int n){
    srand(time(0)); //membuat seed pada rand() menjadi sesuai dengan waktu, sehingga akan berubah setiap kali program berjalan.
    while (!isSorted(arr, n)){
        shuffle(arr, n);
    }
}

void sortStringInFile(string file){
    vector<string> content;
    fstream File;
    string temp;
    File.open(file, ios::in);
    while(getline(File, temp)){
        content.push_back(temp);
    }
    File.close();

    for (int i = 0; i < content.size()-1; i++){
        for (int j = 0; j < content.size()-1-i; j++){
            if(content[j][0] > content[j+1][0]){
                swap(content[j], content[j+1]);
            }
            if(content[j][0] = content[j+1][0]){
                for (int k = 1; k < content[j].length();k++){
                    if(content[j][k] > content[j+1][k]){
                        swap(content[j],content[j+1]);
                        break;
                    }
                }
            }
        }
    }
} 

//---------------------------------------------- SEARCH ----------------------------------------------//
//---------- Linear Search ----------//
//mencari satu persatu dari awal setiap elemen array nya, 
//jika ketemu maka index nya akan dikembalikan, jika tidak maka akan mengembalikan -1

int linearSearch(int x , int arr[], int n){ 
    for (int i = 0; i < n; i++){
        if (x == arr[i]){
            return i;
        }
    }
    return -1;
}

//---------- Binary Search ----------//
//hanya bisa dipakai untuk data yang sudah terurut
//mencari dengan cara mencari titik tengah dengan cara membagi 2 
//jik nili sam dengan titik tengah maka akan mengembalikan titik tengah (sebagai index)
//jika nilai lebih kecil dari titik tengah maka akan mencari di bagian kiri/sebelum titik tengah
//jika nilai lebih besar dari titik tengah maka akan mencari di bagian kanan/setelah titik tengah
//proses dilakukan berulang-ulang sampai data yang dicari sama dengan titik tengah
//akan berhenti saat nilai index minimumnya sama dengan index maximumnya
//jika tidak ada maka akan mengembalikan nilai -1

int binarySearch(int x , int arr[], int l, int r){
    while(l <= r){
        int m = l + (r-l) / 2;
        if (arr[m] == x){
            return m;
        } else if (arr[m] < x){
            l = m + 1;
        } else{
            r = m - 1;
        }
    }
    return -1;
}

//---------- Ternary Search ----------//
//hanya bisa dipakai untuk data yang sudah terurut
//merupakan function rekursif
//mencari 2 titik dengan cara membagi 3 array
//jika data yang dicari sama dengan titik 1 maka akan mengembalikan titik 1 (sebagai index)
//jika data yang dicari sama dengan titik 2 maka akan mengembalikan titik 2 (sebagai index)
//jika nilai lebih kecil dari titik 1 maka akan melakukan fungsi ini lagi di sebelah kiri dari titik 1
//jika nilai lebih besar dari titik 2 maka akan melakukan fungsi ini lagi di sebelah kanan dari titik 2
//jika tidak keduanya maka akan melakukan fungsi ini lagi di antara titik 1 dan titik 2
//hal ini dilakukan berulang-ulang sampai nilai yang dicari sama dengan titik 1 atau titik 2, dan mengembalikan titik tersebut (sebagai index)
//akan berhenti saat nilai index minimumnya sama dengan index maximumnya
//jika tidak ditemukan maka akan mengembalikan nilai -1

int ternarySearch(int x , int arr[], int l, int r){
    while (l <= r){
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;

        if (x == arr[mid1]){
            return mid1;
        } else if (x == arr[mid2]){
            return mid2;
        }
        if (x < arr[mid1]){
            return ternarySearch(x , arr, l, mid1-1);
        } else if(x > arr[mid2]){
            return ternarySearch(x , arr, mid2+1, r);
        } else{
            return ternarySearch(x , arr, mid1 + 1, mid2 -1);
        }
    }
    return -1;
}


//---------- Search String in String ----------//
// mencocokkan karakter pertama dari string yang ingin dicari dengan seluruh karakter string utama
// jika ada yang cocok maka index karakter pada string utama tersebut akan dianggap sebagai index 0 untuk mencocokkan karakter selanjutnya
// membandingkan setiap karakter selanjutnya pada string yang ingin dicari dengan setiap karakter string utama
// jika karakter selanjutnya tidak sama maka melanjutkan perulangan dan tidak lagi menganggap karakter tersebut sebagai index 0
// dilakukan sampai semua karakter cocok
// jika berhasil maka akan mengembalikan nilai index pada string utama tadi
// jika tidak ditemukan akan mengembalikan nilai -1

int searchStringInString(string word , string sentence){
    for (int i = 0; i < sentence.length(); i++){
        if (sentence[i] == word[0]){
            for (int j = 0; j < word.length(); j++){
                if (sentence[i+j] != word[j]){
                    break;
                }
                return i;
            }
        }
    }
    return -1;
}


//---------- Search String in Array ----------//
//Pada dasarnya metode pencariannya sama dengan Search String in String, hanya saja ini mencari suatu string di dalam kumpulan array string
//Kembaliannya adalah index dari array dimana string tersebut ditemukan, bukan index ke berapa pada suatu array string tersebut.
//Jika tidak ditemukan akan mengembalikan nilai -1

int searchStringInArray(string word , string sentence[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < sentence[i].length(); j++){
            if (sentence[i][j] == word[0]){
                for (int k = 1; k < word.length(); k++){
                    if (sentence[i][j+k] != word[k]){
                        break;
                    }
                    if (k = word.length()-1){
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}

//---------- Search String in File ----------//
//Pada dasarnya metode pencariannya sama dengan Search String in Array, tapi kali ini dalam suatu file yang sudah ada
//Kembaliannya adalah baris dimana string tersebut ditemukan di dalam file
//Jika tidak ditemukan akan mengembalikan nilai -1

int searchStringInFile(string word , string file){
    fstream File;
    vector<string> content;
    File.open(file, ios::in); 
    string temp;
    while (getline(File, temp)){
        content.push_back(temp);
    }
    for (int i = 0; i < content.size(); i++){
        for (int j = 0; j < content[i].length(); j++){
            if (content[i][j] == word[0]){
                for (int k = 1; k < word.length();k++){
                    if (content[i][j+k] != word[k]){
                        break;
                    }
                    if (k = word.length()-1){
                        return i + 1;
                    }
                }
            }
        }
    }
    return -1;
}

//---------------------------------------------- ALL FUNCTION IN MAIN ----------------------------------------------//
//---------- String in File ----------//
//meminta masukan string yang ingin dicari dalam File
//meminta nama File beserta extensionnya
//menampilkan baris dimana string tersebut ditemukan di dalam File

void stringInFile(){
    string word; //input string yang ingin dicari
    string file; //input nama file beserta extension
    clear;

    cout << "Masukkan string yang ingin dicari   : ";
    getline(cin, word);
    cout << "Masukkan nama file dan extensionnya : ";
    getline(cin, file);

    int hasil = searchStringInFile(word, file);
    if (hasil != -1){
        cout << "\"" << word << "\" ditemukan di baris ke-" << hasil;
    } else{
        cout << "\"" << word << "\" tidak ditemukan";
    }
}

//---------- String in String ----------//
//meminta masukan keseluruhan kalimat
//meminta masukan string yang ingin dicari dalam kalimat tersebut
//menampilkan index dimana string yang ingin dicari tersebut ditemukan

void stringInString(){
    string sentence;
    string word;

    clear;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);
    cout << "Masukkan string yang ingin dicari: ";
    getline(cin, word);

    int hasil = searchStringInString(word, sentence);
    if (hasil != -1){
        cout << "\"" << word << "\" ditemukan di indeks ke-" << hasil;
        if (word.length() != 1){
            cout << " sampai " << hasil + word.length()-1;
        }
    } else{
        cout << "\"" << word << "\" tidak ditemukan";
    }
}

//---------- String in Array ----------//
//meminta masukan batas array dari string
//meminta masukan string keseluruhan dari masing-masing array
//meminta masukan string yang ingin dicari dalam setiap array dari string
//menampilkan index array dimana string yang ingin dicari tersebut ditemukan

void stringInArray(){
    int n;
    string word;
    clear;
    cout << "Masukkan batas array: ";
    cin >> n;
    ignore;

    string sentence[n];
    clear;
    for (int i = 0; i < n; i++){
        cout << "Masukkan string [" << i << "]: ";
        getline(cin, sentence[i]);
    }

    cout << "Masukkan string yang ingin dicari: ";
    getline(cin, word);

    int hasil = searchStringInArray(word, sentence, n);
    if (hasil != -1){
        cout << "\"" << word << "\" ditemukan di string dengan indeks ke-" << hasil;
    } else{
        cout << "\"" << word << "\" tidak ditemukan";
    }
}

//---------- Integer in Array ----------//
//meminta masukan batas array dari integer
//meminta masukan integer dari masing-masing array
//meminta masukan metode sorting yang ingin dipakai untuk mengurutkan integer
//mengurutkan integer sesuai dengan metode yang dipilih
//meminta masukan metode searching yang ingin dipakai untuk mencari letak integer
//mencari letak index integer sesuai dengan metode yang dipilih

void integerInArray(){
    int n; //jumlah array
    int x; //data yang akan dicari

    clear;
    cout << "Masukkan batas array: ";
    cin >> n;

    int arr[n]; //array dengan jumlah n elemen

    for (int i = 0; i < n; i++){
        cout << "Masukkan bilangan [" << i << "]: ";
        cin >> arr[i];
    }

    int sort; //input metode sorting
    clear;
    sorting:
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Quick Sort\n";
    cout << "4. Bogo Sort\n";
    cout << "Pilih metode sort: ";
    cin >> sort;
    switch (sort){
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            quickSort(arr, 0, n-1);
            break;
        case 4:
            bogoSort(arr, n);
            break;
        default:
            goto sorting;
    }

    int search; //input metode searching
    int hasil; //hasil (index dari data yang dicari)
    searching:
    clear;
    show(arr, n);
    cout << "Masukkan bilangan yang ingin dicari: ";
    cin >> x;
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Ternary Search\n";
    cout << "Pilih metode search: ";
    cin >> search;
    switch(search){
        case 1:
            hasil = linearSearch(x, arr, n);
            break;
        case 2:
            hasil = binarySearch(x, arr, 0, n-1);
            break;
        case 3:
            hasil = ternarySearch(x, arr, 0, n-1);
            break;
        default:
            goto searching;
    }

    cout << x;
    if(hasil == -1){
        cout << " tidak ditemukan";
    } else{
        cout << " ditemukan di indeks ke-" << hasil;
    }
}

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