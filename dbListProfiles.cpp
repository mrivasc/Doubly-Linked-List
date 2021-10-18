#include <iostream>
#include <stdio.h>
using namespace std;

/* Modificar el ejemplo de Listas Doblemente Enlazadas vista en clase, deberá de:
1. En lugar de administrar números, deberá de generar un lista con Id, nombre de 
usuario y perfil (administrador, cliente, o trabajador).
2. Debe ingresar los datos desde teclado (opcional) */

struct Node{
	int id;
	string name, prof; 
	Node *prev, *next;
}; 

class List{
    private:
		Node *header, *trailer;
    public:
		List();
		~List();
        void getFront();
        void getLast();
		void addFront();
		void addLast();
        void removeFront();
        void removeLast();
        void printForward();
        void printReverse();
};

List::List(){
    header = new Node;       
    trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
	header->prev = nullptr;
	trailer->next = nullptr;
}

List::~List(){
    while(header->next!=trailer)
        removeFront();

    delete header; delete trailer;
}

void List::getFront(){
    if(header->next==trailer){
        cout << "No hay datos en la lista\n\n"; return;
    }

    Node *p = new Node;
    if(header->next){
        p = header->next;
        cout << "ID: " << p->id << endl;
        cout << "Nombre: " << p->name << endl;
        cout << "Perfil: " << p->prof << endl << endl;
    }
}

void List::getLast(){
    if(trailer->prev==header){
        cout << "No hay datos en la lista\n\n"; return;
    }

    Node *p = new Node;
    if(trailer->prev){
        p = trailer->prev;
        cout << "ID: " << p->id << endl;
        cout << "Nombre: " << p->name << endl;
        cout << "Perfil: " << p->prof << endl << endl;
    }
}

void List::addFront(){
	Node *nw = new Node; int r=0;

	cout << "AGREGANDO DATOS AL INICIO...\n\n";
	cout << "ID: "; cin >> nw->id; cin.ignore();
	cout << "Nombre: "; getline(cin, nw->name);

    do{
	    cout << "Perfil (1) Administrador | (2) Cliente | (3) Trabajador\n"; cin >> r; cout<<endl;
		if (r==1) nw->prof = "Administrador";
		else if (r==2) nw->prof = "Cliente";
		else if (r==3) nw->prof = "Trabajador";
		else cout<<"Digite una opcion valida.\n";
	} while (r!=1 and r!=2 and r!=3);

	nw->next = header->next;    // linking to first node
	nw->next->prev = nw;        // first node -> newNode
	header->next = nw;          // header->newNode
	nw->prev = header;          // newNode->header
}

void List::addLast(){
    Node *nw = new Node; int r=0;

	cout << "AGREGANDO DATOS AL FINAL...\n\n";
	cout << "ID: "; cin >> nw->id; cin.ignore();
	cout << "Nombre: "; getline(cin, nw->name);

    do{
	    cout << "Perfil (1) Administrador | (2) Cliente | (3) Trabajador\n"; cin >> r; cout<<endl;
		if (r==1) nw->prof = "Administrador";
		else if (r==2) nw->prof = "Cliente";
		else if (r==3) nw->prof = "Trabajador";
		else cout<<"Digite una opcion valida.\n";
	} while (r!=1 and r!=2 and r!=3);

    nw->prev = trailer->prev;   // linking to last node
    nw->prev->next = nw;        // last node -> newNode
	nw->next = trailer;         // newNode->trailer
    trailer->prev = nw;         // trailer->newNode
}

void List::removeFront(){
    Node *p = new Node;

    if(header->next!=trailer){
        p = header->next->next;
        delete header->next;

        header->next = p;
        p->prev = header;
    } else cout << "No hay datos en la lista\n\n";
}

void List::removeLast(){
    Node *p = new Node;

    if(trailer->prev!=header){
        p = trailer->prev->prev;
        delete trailer->prev;
        cout << "Persona eliminada exitosamente!\n\n";

        trailer->prev = p;
        p->next = trailer;
    } else cout << "No hay datos en la lista\n\n";
}
void List::printForward(){
    if(header->next==trailer){
        cout << "No hay datos en la lista\n\n"; return;
    }

    Node *p = header->next;
    while(p!=trailer){
        cout << "ID: " << p->id << endl;
        cout << "Nombre: " << p->name << endl;
        cout << "Perfil: " << p->prof << endl << endl;
        p = p->next;
    }
}

void List::printReverse(){
    if(trailer->prev==header){
        cout << "No hay datos en la lista\n\n"; return;
    }

    Node *p = trailer->prev;
    while(p!=header){
        cout << "ID: " << p->id << endl;
        cout << "Nombre: " << p->name << endl;
        cout << "Perfil: " << p->prof << endl << endl;
        p = p->prev;
    }
}

void menu(){
	int r=0; bool cont=true;
	List L;

	do{
		cout << "1. Obtener primer elemento \n2. Obtener ultimo elemento \n3. Agregar al inicio \n";
        cout << "4. Agregar al final \n5. Eliminar primer elemento \n6. Eliminar ultimo elemento \n";
        cout << "7. Imprimir \n8. Imprimir en reversa \n9. Salir\n\n-> ";
		cin >> r; cin.ignore(); cout << endl;

		switch (r){
		case 1: L.getFront();
            break;

        case 2: L.getLast();
            break;
            
        case 3: L.addFront();
			break;

		case 4: L.addLast();
			break;

        case 5: L.removeFront();
            break;

		case 6: L.removeLast();
			break;
        
        case 7: L.printForward();
            break;

        case 8: L.printReverse();
            break;

        case 9: cont = false;
		}
        
	} while (cont);
}

int main() { menu(); system("pause"); }