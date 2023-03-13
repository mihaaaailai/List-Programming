/*
LISTA SIMPLU INLANTUITA
*/
#include <iostream>
#include <conio.h>
using namespace std;

struct  Nod
{
    int info;
    Nod *urm;
};

Nod *prim, *ultim;

void creare_adaugare()
{
    if(prim==NULL){
        prim = new Nod;
        cout << "Se introduce valoarea retinuta in primul nod ";
        cin >> prim->info;
        prim->urm=NULL;
        ultim=prim;
    
    } else {
        Nod *temp;
        temp= new Nod;

        cout << "Valorea care se adauga in lista este ";
        cin>> temp->info;
        ultim->urm=temp;
        ultim=temp;
        ultim->urm=NULL;
    }

}

void listare()
{
    Nod *temp;
    temp=prim;

    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp=temp->urm;
    }

    cout<<'\n';
}

void adaugare_inaintea_valorii(int val)
{
    Nod *temp, *x;
    temp=prim;
    while(temp->urm->info!=val)
        temp=temp->urm;

    x=new Nod;
    cout<<"Valorea care se insereaza este ";
    cin>>x->info;
    x->urm=temp->urm;
    temp->urm=x;
    
}

void inserare_dupa_valoare(int val)
{
    Nod *temp, *x;
    temp=prim;
    while (temp->info!=val)
        temp=temp->urm;

    x = new Nod;

    cout << "Valorea care se insereaza este ";
    cin>>x->info;
    x->urm=temp->urm;
    temp->urm=x;

    if(temp==ultim){
        ultim=x;
    }
    
    
}

void gasire_element_pe_pozitie(int k)
{
    Nod *temp;
    temp=prim;
    int i=1;
    while(temp!=NULL&&i!=k)
    {
        temp=temp->urm;
        i++;
    }

    cout << "Elementul de pe poz "<< k << "este: " << temp->info;
}

void gasire_element_de_valoare(int x)
{
    int i=0;
    Nod *temp;
    for(temp=prim; temp != NULL; temp=temp->urm){
        if(x==temp->info)
            i++;
    }

    if(i!=0) 
        cout << "Nodul cautat exista in lista";
    else
        cout << "Nodul cautat nu exista in lista";
    
}

int main()
{
    int i,k,n,val_inf;
    cout<<"n= ";
    cin>>n;
    for(i=1;i<=n;i++){
        creare_adaugare();
    }

    cout << '\n' << "Se afiseaza lista:\n";

    listare();

    cout << "\n Valoarea inainte careia se realizeaza inserarea este ";

    cin >> val_inf;

    adaugare_inaintea_valorii(val_inf);

    cout << "Se afiseaza lista dupa ce se insereaza val data inaintea altei valori precizate: \n";

    listare();
    cout << '\n';

    cout << "Valorea dupa care se realizeaza inserarea este: ";
    cin >> val_inf;

    inserare_dupa_valoare(val_inf);

    listare();

    cout << "\n Se introduce pozitia pe care se gaseste elementul cautat ";
    cin >> k;

    gasire_element_pe_pozitie(k);

    int x;
    cout << "\n Se introduce nodul care se cauta in lista ";
    cin >> x;

    gasire_element_de_valoare(x);
    return 0;
}





