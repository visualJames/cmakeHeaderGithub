#include <iostream>
#include <string>
using namespace std;

/*
 * Es wird das lexikalisch erste Wort ermittelt
 */
string ermittlelexikalischErstesWort(const string& ueberpruefendesWort, const string& erstesWort){
    __cxx11::basic_string<char>::size_type i=0;
    while(i<ueberpruefendesWort.size() && i<erstesWort.size()){
        if(ueberpruefendesWort.at(i)<erstesWort.at(i)){
            return ueberpruefendesWort;
        }else if(ueberpruefendesWort.at(i)>erstesWort.at(i)) {
            return erstesWort;
        }
        ++i;
    }
    if(ueberpruefendesWort.size()<erstesWort.size()){
        return ueberpruefendesWort;
    }else if(ueberpruefendesWort.size()>erstesWort.size()){
        return erstesWort;
    }else{
        //das Gleiche Wort wurde übergeben
        return erstesWort;
    }
}

/*
 * Ergebnis steht in erstesWort drin
 * Es wird das lexikalisch letzte Wort ermittelt
 */
string ermittlelexikalischLetztesWort(const string& ueberpruefendesWort,const string& erstesWort){
    __cxx11::basic_string<char>::size_type i=0;
    while(i<ueberpruefendesWort.size() && i<erstesWort.size()){
        if(ueberpruefendesWort.at(i)>erstesWort.at(i)){
            return ueberpruefendesWort;
        }else if(ueberpruefendesWort.at(i)<erstesWort.at(i)) {
            return erstesWort;
        }
        ++i;
    }
    if(ueberpruefendesWort.size()>erstesWort.size()){
        return ueberpruefendesWort;
    }else if(ueberpruefendesWort.size()<erstesWort.size()){
        return erstesWort;
    }else{
        //das Gleiche Wort wurde übergeben
        return erstesWort;
    }
}

void vergleich(string erwartet, string pruefe){
    if(pruefe.compare(erwartet)){
        printf("Der String '%s' ist nicht gleich dem erwarteten String '%s'\n",pruefe.c_str(), erwartet.c_str());
    }else{
        printf("Der String '%s' ist gleich '%s'\n", pruefe.c_str(), erwartet.c_str());
    }
}

void test(){
    string s1 = "FElix";
    string s2 = "Felix";
    string s3 = "Fix";
    string s4 = "AFlix";
    string s5 = "FElix";
    string s6 = "A";
    string s7 = "AA";
    vergleich(s1, s2);
    vergleich(s1, s6);

    printf("\n ab hier jetzt ermittleErstesWort\n\n");
    vergleich(s4, ermittlelexikalischErstesWort(s2, s4));
    vergleich(s6, ermittlelexikalischErstesWort(s6, s7));
    vergleich(s2, ermittlelexikalischErstesWort(s2, s3));
    vergleich(s1, ermittlelexikalischErstesWort(s2, s1));

    printf("\n ab hier jetzt ermittleLetztestWort\n\n");
    vergleich(s2, ermittlelexikalischLetztesWort(s2, s4));
    vergleich(s7, ermittlelexikalischLetztesWort(s6, s7));
    vergleich(s3, ermittlelexikalischLetztesWort(s2, s3));
    vergleich(s2, ermittlelexikalischLetztesWort(s2, s1));
}

void Rahmen(){
    string erstesWort;
    string letztesWort;
    string c;

    cout << "Bitte geben Sie ein Wort ein" << endl;
    cin >> c;
    erstesWort = c;
    letztesWort = c;
    while(cin >> c){
        cout << "Bitte geben Sie ein weiters Wort ein (Beende Enter, Strg D)" << endl;
        erstesWort = ermittlelexikalischErstesWort(c, erstesWort);
        letztesWort = ermittlelexikalischLetztesWort(c, letztesWort);
    }
    printf("Das lexikalisch erste Wort ist %s und das Letzte ist %s\n", erstesWort.c_str(), letztesWort.c_str());
}


int main()
{
    //test();
    Rahmen();
    return 0;
}
