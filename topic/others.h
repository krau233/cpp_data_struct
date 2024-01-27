//
// Created by Admin on 2024/1/27.
//

#ifndef DATASTRUCT_OTHERS_H
#define DATASTRUCT_OTHERS_H

int gcd(int a, int b){
    if(b>a){
        int i =a;
        a = b;
        b =i;
    }
    return b==0?a:gcd(b,a%b);
}

#endif //DATASTRUCT_OTHERS_H
