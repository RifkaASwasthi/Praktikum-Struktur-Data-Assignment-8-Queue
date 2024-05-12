# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center"> Rifka Annisa Swasthi </p>

## Dasar Teori
Queue adalah struktur data yang menyusun data secara linear. prinsip dari struktur data ini adalah FIFO First In First Out, FIFO ini dijalankan dengan  membuat buffer sederhana untuk menampung paket-paket yang masuk sementara waktu. FIFO memiliki beberapa karakteristik diantaranya:

1.  Cepat dan sederhana karena tidak melakukan classification

2.  Merupakan solusi umum yang banyak digunakan 

3.  Menggunakan satu buffer untuk berbagai jenis packet

4. Congestion sulit diperkirakan

5.  Memungkinkan terjadinya delay yang lebih lama 

6.  Sering terjadi kondisi packet dibuang (drop packet)
[1]

FIFO pada queue urutan data pertama atau data yang dikeluarkan disebut Front atau head, data yang dikeluarkan terakhir disebut Back, Rear atau Tail. Proses untuk menambahkan data yaitu Enqueue dan untuk emgnhilangkan data disebut Dequeue. 

Jenis-Jenis Queue [2]

1. Berdasarkan Implementasikannya yaitu Linear/Simple Queue yang penghapusan atau penambahan elemen hanya terjadi pada dua ujung barisan dan Circular Queue yang diujung barisan terhubung satu sama lain menciptakan struktur antrean yang berputar.

2. Berdasarkan Penggunaanya yaitu Priority Queue yang dimana elemen prioritas tertinggi akan diambil terlebih dahulu dan Double-ended Queue dimana elemen yang ditambehkan atau dihapus dari kedua ujung antrean.

Representasi queue dapat melibatkan array yang menggunakan petunjuk rear dan front, array memiliki kelebihan akses elemen yang cepat berdasarkan indeksnya, tetapi memiliki keterbatasan ukuran tetap yang tidak fleksibel. Representasi selanjutnya dapat menggunakan Linked List yang menggunakan simpul simpul yang terhubung untuk menyimpan elemen, setiap simpul mempunyai dua bagian yaitu data dan pointer untuk merujuk ke data berikutnya, linked list memungkinkan penambahan dan penghapusan elemen dengan fleksibel, tetapi memiliki overhead memori untuk menyimpan pointer tambahan.

Operasi dasar pada Queue [3]

a. Enqueue (Menambahkan elemen ke dalam Queue)

b. Dequeue (Menghapus elemen dari Queue)

c. Front (Mendapatkan elemen pertama dalam Queue)

d. Rear (Mendapatkan elemen terakhir dalam Queue)

e. IsEmpty (Memeriksa apakah Queue kosong)

f. Size (Mendapatkan jumlah elemen dalam Queue)




## Guided 

### 1. Contoh kode Queue

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull(){
    if (back == maksimalQueue){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if (back == 0){
        return true;
    } else{
        return false;
    }
}

void enqueueAntrian(string data){
    if (isFull()){
        cout << "Antrian penuh" << endl;
    } else{
        if (isEmpty()) {
            queueTeller[0] = data;
            front ++;
            back ++;
        } else{
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian(){
    if (isEmpty()){
        cout << "Antrian kosong" << endl;
    }else{
        for (int i = 0; i< back; i++){
            queueTeller[i] = queueTeller[i+1];
        }
    } back--;
}

int countQueue(){
    return back;
}

void cleanQueue(){
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else{
        for (int i = 0; i < back; i++){
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue(){
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++){
        if (queueTeller[i] != ""){
            cout << i +1 << "." << queueTeller[i] << endl;
        } else{
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main(){
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian =" << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian =" << countQueue() << endl;
    return 0;
}
```
Kode di atas adalah contoh penerapan queue dangan menggunakan array yang berjumlah 5, awalnya kita inisiasi integer front  dan back  menjadi 0 untuk menandai posisi depan dan belakang pada antrian. String queueTeller menyimpan elemen berupa array yang banyaknya ditentukan oleh maksimalQueue. Bool is full untuk mengecheck apakah antrian penuh atau kosong jika back sama dengan maksimalQueue dan hasilnya isi maka return true dan bool kedua untuk mengeckeck apakah 0 sama dengan back jika iya maka return true. voidenqueue/ tambah, untuk menambahkan elemen baru kedalam antrian jika antrian penuh maka akan ditampilkan pesan antrian penuh, void dequeue/ hapus, untuk menghapus elemen di antrian dan jika antrian kosong maka akan ditampilkan pesan antrian kosong, jika antrian kosong dalam isEmpty maka elemen baru data akan ditempatkan di indeks ke 0 dari array queueTeller, dengan disertai penyesuaian nilai front dan back ditambah masing masing satu, jika antrian kosong else isEmpty maka elemen baru ditempatkan di indeks back dari array ququeTeller dan diikuti pemanbahan nilai back. jika sudah fungsi akan mengambalikkan jumlah elemen yang ada dalam antrian dengn int countQueue. void clean untuk menghapus semua elemen dan mengatur front dan back ke nilai awal dengan memeriksa apakah antrian kosong dengan isEmpty, jika kosong maka akan menampilkan antrian kosong, jika tidak kosong masuk ke else, didalam else for diguanakan utnk mengakses elemen dalam array queueTeller hingga back - 1 karena back-1 itu indeks pertama yang kosong setelah elemen- antrian terakhir, setelah semua elemen dihapus back dikembalikan ke 0 dan nilai front diatur kembali ke 0 untuk menunjukkantidak ada elemen di depan antrian. selanjutknya untuk menampilkan elemen dalam antrian tadi menggunaakan void viewQueue dengan keluaraun Data antrian teller dan dipanggil menggunakan int main.

## Unguided 

### 1. 

```C++
#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueAntrian(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Data antrian teller:" << endl;
            Node* current = front;
            int index = 1;
            while (current != nullptr) {
                cout << index << ". " << current->data << endl;
                current = current->next;
                index++;
            }
        }
    }

    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void cleanQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }
};

int main() {
    Queue queue;
    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}

```
#### Output:
![Screenshot 2024-05-12 203636](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-8-Queue/assets/162097297/2883c294-9ce8-4fc8-ae20-492193f71944)


Kode di atas adalah contoh dari queue menggunakan linked list, dengan merepresentasikan node dari linked list menggunakan string data dan kelas queue untuk mengelola linked list sebagai antrian. bool isEmpty untuk mengecheck apakah kosong jika iya maka kembali ke front, void enqueue untuk menambah node baru yang berupa string data,data ditambahkan sampai null jika di check kosong maka ditambahkan ke front jika tidak akan next. void dequeue jika dicheck kosong maka akan muncul Antrian kosong, jika antrian tidak kosong akan else yang berisi pointer temp diarahkan ke node pertama dalam antrian front, pointer front diubah menjadi node berikutnya sehingga node pertama dihapus dalam antrian node yang dihapus dari memori menggunakan delete temp untuk menghindari kebocoran memori. view untuk menampilkan semua elemen jika kosong maka antrian kosong jika ada maka data antrian teller, sampai void clean jika kosong kembali ke dequeueAntrian untuk mengeprint int main.

#### Full code Screenshot:
![Screenshot 2024-05-12 203519](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-8-Queue/assets/162097297/9781ab53-0648-4d1e-933a-e838676c9010)


### 2. 

```C++
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class QueueMahasiswa {
private:
    Mahasiswa* front;
    Mahasiswa* rear;

public:
    QueueMahasiswa() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueMahasiswa(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeueMahasiswa() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Data mahasiswa dalam antrian:" << endl;
            Mahasiswa* current = front;
            int index = 1;
            while (current != nullptr) {
                cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
                index++;
            }
        }
    }

    int countQueue() {
        int count = 0;
        Mahasiswa* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void cleanQueue() {
        while (!isEmpty()) {
            dequeueMahasiswa();
        }
    }
};

int main() {
    QueueMahasiswa queue;
    queue.enqueueMahasiswa("Andi", "2311110050");
    queue.enqueueMahasiswa("Maya", "234100079");
    queue.viewQueue();
    cout << "Jumlah mahasiswa dalam antrian = " << queue.countQueue() << endl;
    queue.dequeueMahasiswa();
    queue.viewQueue();
    cout << "Jumlah mahasiswa dalam antrian = " << queue.countQueue() << endl;
    return 0;
}

```
#### Output:
![Screenshot 2024-05-12 203818](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-8-Queue/assets/162097297/c137d68b-0dbe-442d-89d3-e7e0f8665f54)

Kode di atas merupakan penerapan queue menggunakan linked list, hampir sama dengan unguided 2 bedanya kita menggunakan node struct mahasiswa string nama, string nim class front dan rear mahasiswa ketika void view if kosong maka antrian kosong else ada Data mahasiswa dalam antrian while diidi nama current nim, sampai int main untuk mengepring elemen tadi

#### Full code Screenshot:
![Screenshot 2024-05-12 203725](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-8-Queue/assets/162097297/e8f0ef0a-1278-42f4-8dc6-78a1351552e9)

## Kesimpulan
Queue adalah struktur data yang menyusun data secara linear dengan menggunakan prinsip  FIFO First In First Out, FIFO ini dijalankan dengan  membuat buffer sederhana untuk menampung paket-paket yang masuk sementara waktu yang dikeluarkan disebut pertama Front atau head, data yang dikeluarkan terakhir disebut Back, Rear atau Tail. Proses untuk menambahkan data yaitu Enqueue dan untuk emgnhilangkan data disebut Dequeue.

Operasi pada Queue Enqueue (Menambahkan elemen ke dalam Queue),Dequeue (Menghapus elemen dari Queue),Front (Mendapatkan elemen pertama dalam Queue),Rear (Mendapatkan elemen terakhir dalam Queue),IsEmpty (Memeriksa apakah Queue kosong),Size (Mendapatkan jumlah elemen dalam Queue)



## Referensi
[1] Enggar Febriyanti1, Suwanto Raharjo2, Muhammad Sholeh3. 2017, PERBANDINGAN MANAJEMEN BANDWIDTH MENGGUNAKAN METODE FIFO (FIRST-IN FIRST-OUT) DANPCQ (PER CONNECTION QUEUE) PADA ROUTER MIKROTIK,  Institut Sains & Teknologi  AKPRIND Yogyakarta: [Jurna]l JARKOM.

[2] Rizki Maulana. 2023, Struktur Data Queue: Pengertian, Fungsi, dan Jenisnya [Artikel], dicoding.com.

[3] Riczky Pratama. 2023, Queue: Pengenalan, Implementasi, Operasi Dasar, dan Aplikasi, [Artikel] Medium.