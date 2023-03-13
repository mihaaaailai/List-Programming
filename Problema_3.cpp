/*
STERGEREA PRIMULUI NOD
*/

#include <iostream>
using namespace std;

struct  Nod
{
    int info;
    Nod *urm;
};

Nod *prim, *ultim;

void nod_cap()
{
    prim=new(Nod);
    cin >> prim->info;
    prim->urm=NULL;
    ultim=prim;
}

void inserare_sfarsit(int x)
{
    Nod *temp;
    temp=new(Nod);

    temp->info=x;
    temp->urm=NULL;
    ultim->urm=temp;
    ultim=temp;
}

void creare()
{
    char d='d';
    int x;
    nod_cap();
    while(d=='d')
    {
        cout<<"info=";
        cin >> x;
        inserare_sfarsit(x);
        cout<<"Se mai adauga elemente in lista? (d/n)";
        cin >> d;
    }
}

void parcurgere(Nod *temp)
{
    if(temp==NULL)
        cout << "Lista este vida!";
    else
        while(temp!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->urm;
        }
}

void stergere_primul()
{
    Nod *temp;

    if (prim==NULL)
    {
        cout << "Lista este vida \n";
    } else {
        temp=prim;
        prim=prim->urm;
        delete temp;
    }
}

int main()
{
    cout << "Se creeaza lista \n";
    creare();

    cout << "\n Se afiseaza lista \n";

    parcurgere(prim);

    cout <<"\n Se sterge primul element";

    stergere_primul();

    cout << "\nSe afiseaza lista dupa ce se sterge primul element: \n";

    parcurgere(prim);

    return 0;
}