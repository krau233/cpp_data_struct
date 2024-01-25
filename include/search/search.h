//
// Created by Admin on 2024/1/22.
//

#ifndef DATASTRUCT_SEARCH_H
#define DATASTRUCT_SEARCH_H

#include "../list/array.h"

//顺序查找
template<typename T>
int search_seq(CArrayList<T> array,T key){
    for(int i = 1;i<=array.length;i++){
        if(array[i]==key){
            return i;
        }
    }
    return 0;
}

#endif //DATASTRUCT_SEARCH_H
