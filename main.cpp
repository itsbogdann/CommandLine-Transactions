#include "clase.h"
#include "mystructures.h"
#include <fstream>
#define NRBONURI 11590
#define NRPRODUSE 5000
#define NRTRANZACTII 5000
//NRPRODUSE = numarul de linii din fisierul bonuri.csv

using namespace std;

class raport {
    
    public:
    
    /* hashtable e gen un vector de tipul: {(element1,lista1),(element2,lista2),(elementN,listaN)},
     unde:
     - element = cheie
     - lista = MyStack<TIP> adica un vector de obiecte de tipul TIP ( TIP = produs, bon, tranzactie)
     */
    
    //liste
    MyStack<bon> *lista_produse;
    MyStack<produs> *lista_detalii;
    MyStack<tranzactie> *lista_tranzactii;
    
    
    HashTable<int> *bonuri = new HashTable<int>(NRBONURI);
    HashTable<int> *produse = new HashTable<int>(NRPRODUSE);
    HashTable<int> *tranzactii = new HashTable<int>(NRTRANZACTII);
    
    
    raport() {
        //constructor raport
        CitireBonuri();
        CitireProduse();
        CitireTranzactii();
        
    }
    
    ~raport() {
        delete[] lista_produse;
        delete bonuri;
    }
    
    
    
    void CitireBonuri()
    {
        lista_produse = new MyStack<bon>[NRBONURI];
        
        char x[100];
        char *p;
        int id_prod;
        long long int id_bon;
        string id_bon_string;
        
        
        ifstream f("bonuri.csv");
        f>>x; //trece peste prima linie
        
        while(f>>x){ //baga cate o linie in x
            
            //separa cuvintele prin virgula
            p = strtok(x,",");
            id_bon = atoll(p);
            id_bon_string = string(p);
            
            
        
            p = strtok(NULL, ",");
            if (p==NULL) break; // folositor la ultima citire, cand nu mai are ce sa bage in p si da eroare
            else
                id_prod = atoi(p);
            
            bon item(id_bon,id_prod); //obiect de tip bon initializat cu id_bon si id_prod
            lista_produse[id_prod].push(item); //pune obiect de tip bon intr-o lista
            bonuri->InsertItem(id_bon_string, id_prod); //adaug in hashtable un item
        }
        f.close(); //inchizi fisierul
    }
    
    
    
    void CitireProduse()
    {
        lista_detalii = new MyStack<produs>[NRPRODUSE];

        char *p;
        char name[100];
        int categ;
        double price;
      
        string string_id;
        char ss[100];
        
      ifstream f("produse.csv");
            f.getline(ss,100,'\n');

        
        while(f.getline(ss,100,'\n')){
          
            p = strtok(ss,",");
            int id = atoi(p);
            string_id = string(p);
            
            
            p=strtok(NULL, ",");
            if (p==NULL) break;
            else
                strcpy(name, p);

            
            p = strtok(NULL, ",");
            if (p==NULL) break;
            else
             categ = atoi(p);

            
            
            p=strtok(NULL, ",");
            if (p==NULL) break;
            else
            price = atof(p);
           
            
            produs item(id, name, categ, price);
            lista_detalii[id-1].push(item);
            produse->InsertItem(string_id, id);
        }
    
        f.close();

    }
    
    
    
    void CitireTranzactii()
    {
        
        lista_tranzactii = new MyStack<tranzactie>[NRTRANZACTII];
        
        char timestamp[100], ss[100];
        long long int id_bon;
        int id_magazin;
        
        string id_bon_string;
        
        ifstream f("tranzactii.csv");
        
        f.getline(ss,200,','); //sare peste primul cuvant

        f.getline(ss,200,','); //sare peste al doilea cuv
       
        f.getline(ss,200,','); //sare peste al treilea cuv
        
        f>>ss;
        
        
        while(!f.eof()){ //cat timp nu s-a terminat fisierul
            
            f.getline(ss,100,',');
            int id = atoi(ss);
            
            f.getline(ss,100,',');
            strcpy(timestamp, ss);
            
            
            f.getline(ss,100,',');
            id_bon = atoll(ss);
            id_bon_string = string(ss);
            
            f>>ss;
            id_magazin = atoi(ss);
            
            
            tranzactie item(id, timestamp, id_bon, id_magazin);
            lista_tranzactii[id-1].push(item);
            tranzactii->InsertItem(id_bon_string, id);
        
        }
        
        f.close();
    }
    
    
    
    
    LinkedList<> getList(string d) { //cu metoda asta, din hashtable-ul de bonuri iti iei lista aferenta cheii "d", de ex d=796949236872528 si lista returnata e cea cu id_prod-uri care au id_bon=d
        LinkedList<> lista = bonuri->GetItemByKey(d);
        return lista;
    }
    
    LinkedList<> getProdList(string d) { //la fel pt produse
        LinkedList<> lista = produse->GetItemByKey(d);
        return lista;
    }
    
    LinkedList<> getTranzList(string d){ // la fel pt tranz
        LinkedList<> lista = tranzactii->GetItemByKey(d);
        return lista;
    }
    
    
    void afisareDateProdus(int c) {
        produs a = lista_detalii[c-1].pop(); //iei ultimul obiect din lista cu detalii(adica produse) si il bagi in alt obiect "a" folosind constructorul de copiere din clasa "produs"
        
        cout<<"   Nume: "<<a.name<<endl;
        cout<<"   Categorie: "<<a.categ<<endl;
        cout<<"   Price: "<<a.price<<endl;
        cout<<endl;
    }
    
    
    void afisareDateTranzactie(int c) {
        tranzactie t = lista_tranzactii[c-1].pop();
        
        cout<<"   ID: "<<t.id<<endl;
        cout<<"   Timestamp: "<<t.timestamp<<endl;
        cout<<"   ID MAGAZIN: "<<t.id_mag<<endl;
        cout<<endl;
    }
    
    
};

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
