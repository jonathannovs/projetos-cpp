#include <iostream>

using namespace std;
const string PALAVRA_SECRETA = "MELANCIA";

bool letra_existe(char chute){
    for(int i=0; i < PALAVRA_SECRETA.size(); i++){
        if(chute == PALAVRA_SECRETA[i]){
            return true;
        }
    }
    return false;
}




int main(){
    cout<< PALAVRA_SECRETA <<endl;

    bool nao_acertou =  true;
    bool nao_enforcou = true;

    while(nao_acertou && nao_enforcou){
        char chute;
        cin >> chute;

        if(letra_existe(chute)){
            cout<< "Vc acertou! seu chute esta na palavra" << endl;
        }
        else{
            cout<<"Vc errou! Seu chute não esta na palavra"<<endl;
        }

    }
}













