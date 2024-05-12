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
