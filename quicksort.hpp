#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

template<class T>
void quicksort(T *tab, int left, int right) {
    int i = left;
    int j = right;
    //T pivot = tab[right-1];
    T pivot = tab[left+(right-left)/2];
    do {
        while(tab[i] < pivot) { i++; }
        while(tab[j] > pivot) { j--; }
        if(i <= j) {
            T tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
            i++;
            j--;
        }
    } while(i<=j);
    if(left<j) {
        quicksort(tab,left,j);
    }
    if(right>i) {
        quicksort(tab,i,right);
    }
}

#endif
