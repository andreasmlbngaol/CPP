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
