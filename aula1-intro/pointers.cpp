// O conceito de bigO está já escrito no meu repositório de E.D. em python.
// Ao invés disso, aqui ficará apenas o conceito de ponteiros e classes em C++.

#include<iostream>

using namespace std;

int main(){
    // Perceba que ao criar num2, num2 não aponta pra num1. Se eu mudar o valor
    // de num1, num2 fica inalterado. Isso ocorre pq num2 aponta pra outro lugar
    // da memória, com o mesmo valor.

    int num1 = 11;
    int num2 = num1;

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    cout << endl;

    num1 = 22;  // Perceba que eu não estou mudando num2.

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    //###############################################
    // Agora perceba que ao fazer uma "instanciação" da classe "int" através de
    // num3, basicamente estou criando um inteiro em algum lugar da memória que
    // tem valor 11, e que nós estamos apontando o num1 para o inteiro que
    // acabamos de criar.

}