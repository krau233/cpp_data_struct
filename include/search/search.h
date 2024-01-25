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

//折半查找
template<typename T>
int binary_search(CArrayList<T> array,T key){
    int low=1,high=array.length;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if (array[mid]== key) return mid;
        else if(array[mid]<key) low = mid+1;
        else  high = mid-1;
    }
    return 0;
}
#endif //DATASTRUCT_SEARCH_H
