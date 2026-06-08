/**
 * @mainpage Documentation Circular Queues
 *
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data Queues dengan pendekatan Circular Arrays
 * 
 * @section Operations
 * Project ini memiliki beberapa operasi dasar antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section Cara Penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - Nama  : Maritza Fidelya Huda
 * - NIM   : 20250140169
 * - Kelas : D
 * 
 * @brief
 * @version 0.1
 * @date 2026-06-08
 * 
 * @copyright maritza.fidelya.ft25@mail.umy.ac.id (c) 2026
 * 
 */

#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 * 
 * 
*/
class Queues {
private:
    int FRONT; ///< variable private front untuk menyimpan posisi depan antrian
    int REAR; ///< variable private rear untuk menyimpan posisi belakang antrian
    int max = 5; ///< variable private max untuk menyimpan ukuran maksimum antrian
    int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen-elemen antrian

public:
    /**
     * @brief Constructor a new Queues object
     * set default queue null
     * with FRONT = -1 and REAR = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }
    
    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variabel queue_array
     */
    void insert() {
        int num; ///< variable num untuk menyimpan nilai

        cout << "Enter a number : ";
        cin >> num;
        
        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            // Jika REAR berada di akhir array, pindahkan ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief method untuk menghapus data dalam antrian
     * data dihapus dari variabel queue_array
     */
    void remove()
    {
        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "\nQueue underflow\n";
            return;
        }

        cout << "\nThe element deleted from the queue is "
             << queue_array[FRONT]
             << "\n";
        
        // Cek apakah antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilkan yang berada dalam variabel queue_array
     */
    void display()
    {
        int FRONT_Position = FRONT; ///< variable FRONT_Position untuk menandakan posisi element pertama pada variable front
        int REAR_Position = REAR; ///< variable REAR_Position untuk menandakan posisi element terakhir pada variable rear

        // cek apakah antrian kosong
        if (FRONT_Position == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // jika FRONT_Position <= REAR_Position, iterasi dari FRONT hingga REAR
        if (FRONT_Position <= REAR_Position)
        {
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
            cout << endl;
        }
        else
        {
            // jika FRONT_Position > REAR_Position, iterasi dari FRONT hingga akhir array
            while (FRONT_Position <= max - 1)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            FRONT_Position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queues q; ///< objek untuk menggunakan member yang ada pada class Queues
    char ch; ///< variable ch untuk menyimpan pilihan menu yang diberikan

    while (true)
    {
        try
        {
            cout << "\nMenu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement Delete Operation" << endl;
            cout << "3. Display Values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }

    return 0;
}