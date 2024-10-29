#include <iostream>
#include <ctime>

using namespace std;

string leggiComando() {
    string c;
    do {
        cout << "[R]accolta fondi | [P]revisione budget | [S]pesa imprevista | [X] esci" << endl;
        cin >> c;
    } while (c != "R" && c != "P" && c != "S" && c != "X");
    
    return c;
}

void previsioneBudget(float budget) {
    float percRand, variazione;
    
    percRand = rand() % ( (21 + 10) - 10 );
    variazione = budget * percRand / 100;
    budget = budget + variazione;
    cout << "Previsione budget: " << percRand << "%" << endl;
    cout << "Budget stimato temporaneo all'interno della funzione: " << budget << endl;
}

void raccoltaFondi(float fondi, float & budget) {
    
    if (fondi >= 0) {
        budget = budget + fondi;
    } else {
        cout << "Inserito un valore negativo. Operazione annullata." << endl;
    }
}

void spesaImprevista(float spesa, float & budget) {
    if (spesa >= 0) {
        if (spesa > budget) {
            cout << "Spesa maggiore del budget. Operazione annullata." << endl;
        } else {
            budget = budget - spesa;
        }
    } else {
        cout << "Importo spesa negativo. Operazione annullata." << endl;
    }
}


int main() {
    srand(time(0));
    
    string c;
    float budget, fondi, spesa;
    
    // Il budget iniziale va da 100 a 1000 euro.
    budget = rand() % (1001 - 100) + 100;
    cout << "Budget iniziale: " << budget << "€" << endl;
    do {
        c = leggiComando();
        if (c == "R") {
            cout << "Inserisci importo per la raccolta fondi" << endl;
            cin >> fondi;
            raccoltaFondi(fondi, budget);
            cout << "Budget aggiornato dopo la raccolta fondi: " << budget << endl;
        }
        if (c == "P") {
            previsioneBudget(budget);
            cout << "Budged attuale: " << budget << "€" << endl;
        }
        if (c == "S") {
            cout << "Inserisci importo per la spesa imprevista" << endl;
            cin >> spesa;
            spesaImprevista(spesa, budget);
            cout << "Budget aggiornato dopo la spesa: " << budget << endl;
        }
    } while (c != "X");
    cout << "Ciao, a presto!" << endl;
    return 0;
}

