#include <iostream>
#include <string>

using namespace std;

class FlightBookingSystem { 
    int zborr=0;
    private:
    struct node {
        string passangerName;
        node* urm;
        node(string name) : passangerName(name), urm(nullptr) {}
    };
    struct vol {
        node* head;
        vol* urm;
        vol() : head(nullptr), urm(nullptr) {}
        bool full() {
            int nr=0;
            node* p = head;
            while(p) {
                nr++;
                p=p->urm;
            }
            return nr >= 5;

        }
    };
    vol* prim;
    public:
    FlightBookingSystem() : prim() {}
    void bookSeat(string passangerName) {
        if(!prim || prim->full()) {
            vol* nou = new vol;
            nou->head = new node(passangerName);
            nou->urm = prim;
            prim = nou;
            zborr++;
        }
        else {
            node* nou = new node(passangerName);
            nou->urm = prim->head;
            prim->head = nou;
        }
    }

    void cancelBooking(int seatIndex) {
        int index = 0;
        vol* currentFlight = prim;
        while (currentFlight) {
            node* previous = nullptr;
            node* current = currentFlight->head;
            while (current) {
                if (index == seatIndex) {
                    if (previous) {
                        previous->urm = current->urm;
                    } else {
                        currentFlight->head = current->urm;
                    }
                    delete current;
                    return;
                }
                previous = current;
                current = current->urm;
                index++;
            }
            currentFlight = currentFlight->urm;
        }
    }
    void displaySystem() {
       vol* p = prim;
        for(int i=zborr;i>=1;i--)
        cout << "Vol " << i <<       "reservations:" << endl;
        while (p) {
            node* pasager = p->head;
            while (pasager) {
                cout << "- " << pasager->passangerName << endl;
                pasager = pasager->urm;
            }
            p = p->urm;
        }
            
        }
    string getPassenger(int seatIndex) {
        int index = 0;
        vol* p = prim;
        while (p) {
            node* pasager = p->head;
            while (pasager) {
                if (index == seatIndex) {
                    return pasager->passangerName;
                }
                pasager = pasager->urm;
                index++;
            }
            p = p->urm;
        }
        return "";
    }
};

int main() {
    FlightBookingSystem system;
    int n=4, loc;
    char nume[10];
     cout<<"[1] Pasager nou"<<endl;
    cout<<"[2] Verifica pasager"<<endl;
    cout<<"[3] Verifica toate zborurile"<<endl;
    cout<<"[4] Sterge pasager"<<endl;
    cout<<"[0] Iesi din sistem"<<endl;
    cin>>n;
    while(n!=0) {
        if (n==1) {cout<<"Introduce nume: "; cin.get(); cin.get(nume, 10); system.bookSeat(nume); cin.get();} 
        else if (n==2) {cout<< "Introduce loc: "; cin>>loc; cout<<system.getPassenger(loc)<<endl;} 
        else if (n==3) system.displaySystem(); 
        else if (n==4) {cout<< "Introduce loc: "; cin>>loc; system.cancelBooking(loc);}
    cout<<"[1] Pasager nou"<<endl;
    cout<<"[2] Verifica pasager"<<endl;
    cout<<"[3] Verifica toate zborurile"<<endl;
    cout<<"[4] Sterge pasager"<<endl;
    cout<<"[0] Iesi din sistem"<<endl;
    cin>>n;
    }
    return 0;
}
