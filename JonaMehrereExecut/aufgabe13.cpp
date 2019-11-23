#include <iostream>
#include <string>
using namespace std;

struct Fehler{
    string nachricht;
};

int berechneTageImMonat(const int& Monat){
    int tag;
    switch(Monat){
        case 1: tag=31;
            break;
        case 2: tag=28;
            break;
        case 3: tag=31;
            break;
        case 4: tag=30;
            break;
        case 5: tag=31;
            break;
        case 6: tag=30;
            break;
        case 7: tag=31;
            break;
        case 8: tag=31;
            break;
        case 9: tag=30;
            break;
        case 10: tag=31;
            break;
        case 11: tag=30;
            break;
        case 12: tag=31;
            break;
        default: Fehler fehler;
            fehler.nachricht = "Es wurde eine ungueltige Zahl eingegeben fuer den Monat: " + Monat;
            throw  fehler;
    }
    return tag;
}



/*
 * gibt den Tag im Jahr zurück
 * Schaltjahre werden ignoriert
 */
int bestimmeTagImJahr(const int& Monat, const int& TagImMonat){
    int tag = 0;
    int m = Monat;
    while(m>1){
        try {
            tag += berechneTageImMonat(m-1);
        }catch(Fehler fehler){
            throw fehler;
        }
        --m;
    }
    tag += TagImMonat;
    return tag;
}

void Rahmen(){
    int Jahr;
    int Monat;
    int TagImMonat;

    cout << "Bitte geben Sie das Jahr ein" << endl;
    cin >> Jahr;
    cout << "Bitte geben Sie den Monat ein" << endl;
    cin >> Monat;
    cout << "Bitte geben Sie den Tag im Monat ein" << endl;
    cin >> TagImMonat;
    int tag;
    try {
        tag = bestimmeTagImJahr(Monat, TagImMonat);
    }catch(Fehler fehler){
        throw fehler;
    }
    cout << "Es ist der " << tag << " Tag im Jahr\n";
}


int main()
{
    //test();
    try {
        Rahmen();
    }catch(Fehler fehler){
        printf("Programm wurde wegen '%s' unterbrochen\n", fehler.nachricht.c_str());
    }

    return 0;
}
