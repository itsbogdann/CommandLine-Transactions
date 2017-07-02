#include "SET4.h"


void RezolvareTask()
{
    raport Raportul;
    string StringCitire;
    cout<<"Introduceti id-ul bonului:" <<endl;
    cin>>StringCitire;
    
    LinkedList<> ListaBon = Raportul.getList(StringCitire);
   // lista listabon = lista din hashtable-ul bonuri aferenta cheii "StringCitire" pe care o dam
    
    
    cout<<"Produsele cumparate: "<<endl;
    cout<<endl;
    
    while(!ListaBon.IsEmpty()) //cat timp sunt elemente in lista
    {
        string s1 = to_string(ListaBon.PopValue()); //facem id_prod din int -> string
        cout<<"ID Produs: "<<s1<<endl;
       
        cout<<" Detalii Produs: "<<endl;
            LinkedList<> ListaProd = Raportul.getProdList(s1); //luam lista de produse aferenta cheii rezultate din lista trecuta(s1 adica id_prod)
                int pp = ListaProd.PopValue(); //scoatem ultimul obiect din lista
                Raportul.afisareDateProdus(pp);
        
        
        
    }
    
    cout<<"TRANZACTII:"<<endl;
    cout<<endl;
    
    LinkedList<> ListaTranz = Raportul.getTranzList(StringCitire); //cam la fel pt tranzactii
    
    int i=0;
    while(!ListaTranz.IsEmpty())
    {
        cout<<" Tranzactie "<<i<<endl;
        int kk = ListaTranz.PopValue();
        Raportul.afisareDateTranzactie(kk);
        i++; // cu i numerotam tranzactiile
    }
 
    
}


int main()
{
    RezolvareTask();
}