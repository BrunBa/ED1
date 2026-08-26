#include <stdio.h>

int maior(int a, int b, int c);
int menor(int a, int b, int c);
int media(int a, int b, int c);

int main(){
    
}

int maior(int a, int b, int c){
    if (a > b && a > c){
        return a;
    } else if (b > a && b > c){
        return b;
    } else {
        return c;
    }
}

int menor(int a, int b, int c){
    if (a < b && a < c){
        return a;
    } else if (b < a && b < c){
        return b;
    } else {
        return c;
    }
}

int media(int a, int b, int c){
    return (a + b + c) / 3;
}