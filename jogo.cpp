#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    cout <<"**********************************" << endl;  /*cout irá imprimir e endl para pulas linhas*/
    cout <<"*Bem-vindo ao jogo da adivinhacao*" << endl;
    cout <<"**********************************" << endl;

    cout << "Escolha seu nivel de dificuldade"<< endl;
    cout<< "Facil(F), Medio(M), Dificil(D)"<<endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_tentativas;

    if(dificuldade=='F'){
        numero_tentativas = 15;
    }
    else if(dificuldade=='M'){
        numero_tentativas = 10;
    }
    else{
        numero_tentativas=5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    //substituindo o while pelo for
    //while (nao_acertou){  
    //  tentativas ++;     
    //for(inicio; condicao; incrementador)
    for(tentativas=1;tentativas<=numero_tentativas;tentativas++){ 
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;

        cout << "O valor do chute eh: " << chute << endl;
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute> NUMERO_SECRETO;

        if(acertou){
            cout << "Parabens, vc acertou o numero secreto" << endl;
            nao_acertou = false;
            break; // usando o break para quebrar o laço caso acerte
        }
        else if(maior){
            cout << "Seu chute foi maior que o numero secreto" << endl;
        }
        else{
            cout << "Seu chute foi menor que o numero secreto" << endl;
        }
    }
    cout <<"Fim de jogo"<< endl;
    if(nao_acertou){
        cout<<"Vc perdeu, tente novamente" << endl;
    }
    else{
        cout << "Vc acertou o numero secreto em: " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout<< fixed;
        cout << "Sua pontuacao foi de: "<< pontos<< endl;
    }
    cout << "O Numero secreto eh: " << NUMERO_SECRETO << endl;
}

/*no terminal
>>g++ jogo.cpp -o jogo.out
>>jogodaadivinhacao.out
*/