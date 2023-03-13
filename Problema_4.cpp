/*
LISTA DUBLU INLANTUITA
*/

#include <iostream>
using namespace std;

struct  Nod
{
    int info;
    Nod *anter, *urm;
};

Nod *prim, *ultim;

void creare()
{
    Nod *temp;
    temp = new Nod;
    cout<<"info=";
    cin>>temp->info;

    if(!prim)
    {
        prim=temp;
        prim->urm=NULL;
        prim->anter=NULL;
        ultim=prim;
    } else {
        ultim->urm=temp;
        temp->anter=ultim;
        ultim=temp;
        ultim->urm=NULL; 
    }

}

void listare_stanga_dreapta()
{
    Nod *temp;
    temp = prim;
    while (temp)
    {
        cout<<temp->info<<" ";
        temp=temp->urm;
    }
    
}
// Stergerea primului element dintr-o lista dublu inlantuita
void stergere_primul()
{
    Nod *temp;
    if(prim!=ultim)
    {
        temp=prim;
        prim=prim->urm;
        prim->anter=0;
        delete(temp);
    } else {
        prim=ultim=0;
    }
}

void stergere_ultimul()
{
    Nod *temp;
    if(prim!=ultim){
        temp=ultim;
        ultim=ultim->anter;
        ultim->urm=0;
        delete(temp);
    } else {
        prim=ultim=0;
    }
}

int main()
{
    int i,n;
    cout << "n= ";
    cin >> n;
    for(i=1;i<=n; i++)
        creare();

    cout << "\n Se afiseaza lista: \n";
    listare_stanga_dreapta();
    cout << "\n Se sterge primul nod \n";
    stergere_primul();
    cout << "\n Se afiseaza lista dupa ce se sterge primul element: \n";
    listare_stanga_dreapta();

    cout << "\n Se sterge ultimul nod \n";

    stergere_ultimul();

    cout << "Se afiseaza lista dupa ce se sterge ultimul element: \n";

    listare_stanga_dreapta();

}