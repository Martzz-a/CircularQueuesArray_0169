#include <iostream>
using namespace std;

class Queues {
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_array[max];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }
    
    void insert() {
        int num;

        cout << "Enter a number : ";
        cin >> num;

        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }
    }
};