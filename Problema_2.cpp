/*
STERGEREA UNUI NOD CARE ARE AO VALOAREA DATA DE LA TASTATURA,
DIFERITA DE VALOAREA PRIMULUI NOD AL LISTEI SIMPLU INLANTUITE
*/

#include <iostream>
using namespace std;

 struct Nod
 {
    int info;
    Nod *urm;
 };

 Nod *prim, *ultim;

 int n;

 void creare(){
    Nod *temp= new Nod;
    cin >> temp->info;

    if(prim==NULL){
        prim=temp;

        prim->urm=NULL;
        ultim=prim;
    } else {
        ultim->urm=temp;
        temp->urm=NULL;
        ultim=temp;
    }
 }

 void afisare(int n)
 {
    int i;
    Nod *temp=new Nod;
    temp=prim;

    for(i=1;i<=n; i++){
        cout<<temp->info<<' ';
        temp=temp->urm;
    }
 }

 void stergere_element_de_valoare()
 {
    cout << "\n Se introduce valoarea nodului care trebuie sters ";
    int x, k=1, i;
    cin >> x;

    Nod *temp=new Nod;
    temp=prim;

    for(i=1;i<=n;i++)
    {
        // daca sa ajuns la nodul care trebuie sters
        if(temp->info==x)
            break;
        else {
            k++;
            temp=temp->urm;
        }
    }

    temp=prim;

    for(i=1;i<k-1;i++)
    {
        temp=temp->urm;
    }

    temp->urm=temp->urm->urm;
 }

 int main()
 {
     int i;
     cout<<"n=";
     cin>>n;
     for(i=1;i<=n;i++)
     {
        creare();
     }

    cout << "\n Se afiseaza lista: \n";
    afisare(n);
    cout << '\n';

    stergere_element_de_valoare();

    cout << "Se afiseaza lista dupa ce se sterge nodul cu val precizata:\n";

    afisare(n); cout << '\n';

    return 0;



 }
 
