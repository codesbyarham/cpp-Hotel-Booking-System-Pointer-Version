#include <iostream>
using namespace std;

const int F = 5; // floors
const int R = 8; // rooms

// function prototype
void show(char (*h)[R]);
void book(char (*h)[R], int f, int r);
void freeRoom(char (*h)[R], int f, int r);
int countEmpty(char (*h)[R]);
int mostBooked(char (*h)[R]);

int main() {
    // initialize all rooms as empty
    char h[F][R];
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < R; j++) {
            h[i][j] = 'E';
        }
    }
    
    int ch;
    do {
        cout << "\n===== HOTEL MENU =====" << endl;
        cout << "1. Book a room" << endl;
        cout << "2. Free a room" << endl;
        cout << "3. Count available rooms" << endl;
        cout << "4. Find floor with most bookings" << endl;
        cout << "5. Show hotel status" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        
        if (ch == 1) {
            int f, r;
            cout << "Enter floor (0-" << F - 1 << "): ";
            cin >> f;
            cout << "Enter room (0-" << R - 1 << "): ";
            cin >> r;
            if (f >= 0 && f < F && r >= 0 && r < R)
                book(h, f, r);
            else
                cout << "Invalid floor or room!" << endl;
        }
        else if (ch == 2) {
            int f, r;
            cout << "Enter floor (0-" << F - 1 << "): ";
            cin >> f;
            cout << "Enter room (0-" << R - 1 << "): ";
            cin >> r;
            if (f >= 0 && f < F && r >= 0 && r < R)
                freeRoom(h, f, r);
            else
                cout << "Invalid floor or room!" << endl;
        }
        else if (ch == 3) {
            cout << "Total available rooms: " << countEmpty(h) << endl;
        }
        else if (ch == 4) {
            cout << "Floor with most bookings: " << mostBooked(h) << endl;
        }
        else if (ch == 5) {
            show(h);
        }
    } while (ch != 6);
    
    return 0;
}

// show full hotel table
void show(char (*h)[R]) {
    cout << "\nHotel Room Status (E = Empty, B = Booked):\n" << endl;
    for (int i = 0; i < F; i++) {
        cout << "Floor " << i << ": ";
        for (int j = 0; j < R; j++) {
            cout << *(*(h + i) + j) << " ";
        }
        cout << endl;
    }
}

// book a room
void book(char (*h)[R], int f, int r) {
    if (*(*(h + f) + r) == 'E') {
        *(*(h + f) + r) = 'B';
        cout << "Room booked!" << endl;
    }
    else {
        cout << "Already booked!" << endl;
    }
}

// free a room
void freeRoom(char (*h)[R], int f, int r) {
    if (*(*(h + f) + r) == 'B') {
        *(*(h + f) + r) = 'E';
        cout << "Room freed!" << endl;
    }
    else {
        cout << "Already empty!" << endl;
    }
}

// count empty rooms
int countEmpty(char (*h)[R]) {
    int c = 0;
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < R; j++) {
            if (*(*(h + i) + j) == 'E') {
                c++;
            }
        }
    }
    return c;
}

// find floor with most booked rooms
int mostBooked(char (*h)[R]) {
    int maxB = -1, fIndex = -1;
    for (int i = 0; i < F; i++) {
        int b = 0;
        for (int j = 0; j < R; j++) {
            if (*(*(h + i) + j) == 'B') {
                b++;
            }
        }
        if (b > maxB) {
            maxB = b;
            fIndex = i;
        }
    }
    return fIndex;
}