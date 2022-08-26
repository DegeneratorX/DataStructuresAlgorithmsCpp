#include<iostream>

using namespace std;

class Node{
    public:
        int value;  // Declaração dos atributos
        Node* next;  // next aponta para um Node.

        Node(int value){ // Construtor
            this->value = value; // Se a variável passada fosse 'val', não precisaria usar o 'this', pois já ficaria claro que não são iguais.
            this->next = nullptr;
            // this->value está referienciando o 'int value;', e o this->next está referenciando o 'Node* next;'.
        }
};

class LinkedList{
    private: // Privo as variáveis, pois não há necessidade de acessá-las fora da instância diretamente. Usarei gets.
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value){ // Construtor da lista encadeada
            Node* newNode = new Node(value); // newNode aponta pro novo nó instanciado e criado.
            head = newNode; // Cabeça aponta pro novo nó criado, que o novo nó aponta pro nó instanciado. Ou seja, Head aponta pro mesmo lugar onde newNode aponta.
            tail = newNode;
            length = 1;
        }

        void printList(){
            Node* temp = head; // temp percorre a lista
            while (temp != nullptr){  // Enquanto ele não for nulo, vai printando.
                cout << temp->value << endl;
                temp = temp->next;  // Percorrimento
            }
        }

        Node* search(int value){
            Node* temp = this->head;
            while(temp != nullptr){
                if (temp->value == value){
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }

        void getHead(){
            cout << "Head: " << head->value << endl;
        }

        void getTail(){
            cout << "Tail: " << tail->value << endl;
        }

        void getLength(){
            cout << "Length: " << length << endl;
        }

        void addLast(int value){ // O(1), método próprio usando tail como referência.
            Node* newNode = new Node(value);
            if (this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }
            else{
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->length += 1;
        }

        void addLastWithoutTail(int value){  // O(n), método do Rudini. Economiza memória, não usa Tail para guardar. Precisa iterar pra achar o anterior do removido.
            Node* newNode = new Node(value);
            Node* temp = this->head;
            if (this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }
            else{
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
                this->tail = newNode;
            }
        }

        Node* removeLast(){  //O(n), usa o tail como referência.
            Node* temp = this->head;
            if (this->length == 0){
                return nullptr;
            }

            Node* tailGuardado = this->tail; // Guardo o nó que será removido.

            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
                this->length -= 1;
                return tailGuardado;
            } 
            else {
                while(temp->next->next != nullptr){
                    temp = temp->next;
                }
                temp->next = nullptr;
                this->tail = temp;
                this->length -= 1;
                return tailGuardado;
            }
        }

        Node* removeLastWithoutTail(){  //O(n), economiza memória ao não usar o tail como referência.
            
            if (this->length == 0){
                return nullptr;
            }

            Node* temp = this->head;

            if (length == 1){
                this->head = nullptr;
                this->tail = nullptr;
                return temp;
            }
            
            Node* prev = this->head;
            while(temp->next != nullptr){
                prev = temp;
                temp = temp->next;
            }
            tail = prev;
            tail->next = nullptr;
            this->length -= 1;
            return temp;
        }
};

int main(){
    LinkedList* ListaEncadeada = new LinkedList(4);

    ListaEncadeada->addLast(2);
    ListaEncadeada->addLast(10);
    ListaEncadeada->addLast(8);
    ListaEncadeada->addLast(15);
    ListaEncadeada->addLastWithoutTail(200);

    // cout << ListaEncadeada->removeLast()->value << endl;
    
    cout << ListaEncadeada->removeLastWithoutTail()->value << endl;
    cout << ListaEncadeada->removeLastWithoutTail()->value << endl;
    cout << ListaEncadeada->removeLast()->value << endl;
    cout << ListaEncadeada->removeLast()->value << endl;
    cout << ListaEncadeada->removeLast()->value << endl;
    cout << ListaEncadeada->removeLastWithoutTail()->value << endl;

    cout << endl;
    

    //ListaEncadeada->printList();

}