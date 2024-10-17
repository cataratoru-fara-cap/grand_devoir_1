#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 100

using namespace std;

int n,w;
struct oaza {
    int water;
    int distanceToNext;
};

// Implementarea proprie a clasei coadă
template<typename T>
class Queue {
private:
    T queueArray[NMAX];
    int cap, coada;

public:
    Queue() : cap(0), coada(0) {}

    void enqueue(T x) {
        if (coada == NMAX) {
            cout << "Coada este plina";
            return;
        }
        queueArray[coada] = x;
        coada++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Coada este goala";
            T x;
            return x;
        }
        T x = queueArray[cap];
        cap++;
        return x;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Coada este goala";
            T x;
            return x;
        }
        return queueArray[cap];
    }

    int isEmpty() {
        return (cap == coada);
    }

    int size() {
        return coada - cap;
    }

    int start() {
        return cap;
    }

    int end() {
        return coada;
    }
};

// Funcția pentru a găsi oaza de plecare optimă
int findOptimalStart(vector<oaza>& oases, int w) {
    Queue<oaza> queueAux;
    vector<oaza> queueInit = oases;

    // Sortăm oazele în ordine crescătoare după distanța până la următoarea oază
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
         if (queueInit[i].distanceToNext > queueInit[j].distanceToNext) {
            swap(queueInit[i], queueInit[j]);
         }
    }
}

    for (int i = 0; i < n; ++i) {
        queueAux = Queue<oaza>(); // resetăm coada auxiliară la fiecare iterație
        int currentWater = w;
        int j = i;
        bool success = true;

        while (!queueAux.isEmpty() && currentWater >= 0) {
            currentWater -= queueAux.peek().distanceToNext;
            if (currentWater < 0) {
                success = false;
                break;
            }
            currentWater += queueAux.dequeue().water;
            j = (j + 1) % n;
        }

        if (success) {
            return i;
        }
    }

    return -1;
}

int main() {
    ifstream fin("input.txt");

    // Citim input-ul
    fin >> n >> w;

    vector<oaza> oases(n);
    for (int i = 0; i < n; ++i) {
        fin >> oases[i].water >> oases[i].distanceToNext;
    }

    // Găsim oaza de plecare optimă
    int optimalStart = findOptimalStart(oases, w);

    if (optimalStart == -1) {
        cout << "Nu există oaza de plecare optimă.\n";
    } else {
        cout << optimalStart +1 << "\n";
    }

    fin.close();

    return 0;
}
