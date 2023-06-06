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