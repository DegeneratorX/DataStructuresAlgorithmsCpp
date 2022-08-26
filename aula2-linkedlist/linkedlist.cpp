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

        void getHead(){
            cout << "Head: " << head->value << endl;
        }

        void getTail(){
            cout << "Tail: " << tail->value << endl;
        }

        void getLength(){
            cout << "Length: " << length << endl;
        }

        void append(int value){
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

        Node* pop(){
            Node* temp = this->head;
            if (this->length == 0){
                return nullptr;
            }
            else if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
                this->length -= 1;
                return temp;
            } 
            else {
                while(temp->next != nullptr){
                    //TODO
                }
            }
        }
};

int main(){
    LinkedList* ListaEncadeada = new LinkedList(4);

    ListaEncadeada->append(2);
    ListaEncadeada->printList();

}