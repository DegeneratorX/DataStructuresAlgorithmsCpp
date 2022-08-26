#include<iostream>
#include<string>

using namespace std;

class Cookie{
    private:
        string color;  // Declaro o atributo cor.

    public:
        Cookie(string color){  // Construtor da classe
            this->color = color;
        }

        string getColor(){
            return color;
        }

        void setColor(string color){
            this->color = color;
        }
};


int main(){

// Ponteiro para um tipo "Cookie"
Cookie * cookieOne = new Cookie("green");
// Criação e instanciação de um objeto do tipo Cookie, que aponta pro tipo Cookie.
// 'new' aloca dinamicamente a memória de forma automática, substituindo o malloc.
// Além disso, o 'new' passa valores para o construtor da classe.

Cookie * cookieTwo = new Cookie("blue");

cout << "C1: " << cookieOne->getColor() << endl;
cout << "C2: " << cookieTwo->getColor() << endl;

cookieOne->setColor("yellow");

cout << "C1: " << cookieOne->getColor() << endl;

return 0;

}