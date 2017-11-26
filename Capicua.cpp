//
//  main.cpp
//  Capicua
//
//  Created by Nicolas Gimenez
//  Copyright © 2017 Nicolas Gimenez. All rights reserved.
//

#include <iostream>
#include <array>

const unsigned N=800;
struct Stack {
    std::array <int,N> a;
    unsigned i=0;
};

void Push (Stack&, int);
int Pop (Stack&);
unsigned length(const Stack&);
bool Capicua(Stack&);


int main(){

    std::cout<<"\n Probando los numeros 3,4\n";
    
    Stack s;
    Push (s,3);
    Push (s,4);

    if (Capicua(s)){
        std::cout<<"\n Los numeros ingresados son capicua\n";
    } else {
        std::cout<<"\n Los numeros no son capicua\n";
        
    }

    std::cout<<"\n Probando los numeros 3,4,4,3\n";

    Push (s,3);
    Push (s,4);
    Push (s,4);
    Push (s,3);

    if (Capicua(s)){
        std::cout<<"\n Los numeros ingresados son capicua\n";
    } else {
        std::cout<<"\n Los numeros no son capicua\n";
        
    }

}

bool Capicua(Stack& s){
    if (length(s) == 0){
        std::cout<<"\nStack Vacio \n";
        return false;
    }
    unsigned l = length(s);
    unsigned k = l / 2;
    std::array<int,400> aux;
    unsigned j=0;
    
    while (j<k){
        aux.at(j) = Pop(s);
        j++;
    }
    if (l % 2 == 1){
        Pop(s);
    }
    j--;
    while (aux.at(j) == Pop(s)){
        if(j == 0){
            return true;
        }
        j--;
    }
    return false;
}
void Push (Stack& s, int x){
    s.a.at(s.i)=x;
    ++s.i;
}

int Pop (Stack& s){
    --s.i;
    return s.a.at(s.i);
}

unsigned length(const Stack& s){
    return s.i;
}
