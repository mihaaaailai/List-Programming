/*
Se se creeze o lista dublu inlantuita in care fiecare inregistrare
retine informatii despre o persoana (nume, salariu) si adresa 
inregistrarii precedente. Numarul de persoane este dat. Sa se afiseze
lista personelor cu salariu mai mic decat cel al pesoanei date.
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Nod
{
    char nume[20];
    long salariu;
    Nod *anter;
};

Nod *prim, *ultim;

char num[20];
long sal;
int n;

void generare()
{
    Nod *temp;

    cout << "Numar de salariati ";
    cin >> n;
    cout << "Date despre salariati ";
    ultim=0;
    cout<<"\n Salariatul "<<1<<" ";
    temp= new Nod;
    cout << "\n Nume";
    cin>>temp->nume;
    cout << "Salariu ";
    cin>>temp->salariu;
    temp->anter=0;
    prim=ultim=temp;

    for(int i=2; i<=n; i++)
    {
        cout << "Salariatul " << i << " ";
        temp = new Nod;
        cout << "\n Nume";
        cin>>temp -> nume;
        cout << "Salariul ";
        cin>>temp->salariu;
        temp->anter=0;
        ultim->anter=temp;
        ultim=temp;
    }
}

void listare()
{
    cout << "\n Persoana cu salariul <"<<sal<<":";
    Nod *temp=prim;

    while(temp)
    {
        if(temp->salariu<sal)
            cout << "\n" << temp->nume;

        temp=temp->anter;
    }
}

int main()
{
    generare();
    sal=1000000;
    listare();
}




