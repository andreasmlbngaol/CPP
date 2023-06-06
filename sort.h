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