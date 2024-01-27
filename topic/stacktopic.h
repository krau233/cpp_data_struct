//
// Created by Admin on 2024/1/27.
//

#ifndef DATASTRUCT_STACKTOPIC_H
#define DATASTRUCT_STACKTOPIC_H
#include "../include/stack/stack.h"
#include "../src/stack/stack.cpp"
bool bracketCheck(char str[],int length){
    Stack<char> s;
    for(int i = 0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            s.push(str[i]);
        }else{
            if(s.isEmpty()){
                return false;
            }
            char topElem;
            s.pop(topElem);
            if(str[i]==')'&& topElem!='(') return false;
            if(str[i]==']'&& topElem!='[') return false;
            if(str[i]=='{'&& topElem!='}') return false;
        }
    }
    return s.isEmpty();
}


#endif //DATASTRUCT_STACKTOPIC_H
