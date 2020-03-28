#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>
#include <iostream>

template<class T>
void print_vec(std::vector<T> &a) {
    using namespace std;
    cout << "[";
    for(auto &x:a) {
        cout << x << " ";
    }
    cout << "\b]" << endl;
}

template<class T>
void merge(std::vector<T> &tab, const int left, const int mid, const int right) {
    const int l=right-left+1;
    std::vector<T> tmp = std::vector<T>();
    tmp.reserve(l);

    int i=left, j=mid+1;
    for (int k=0;k<l;k++){
        if (j>right || (i<=mid && tab[i]<tab[j])){
            tmp[k]=tab[i];
            i++;
        }
        else{
            tmp[k]=tab[j];
            j++;
        }
    }
    for (int k=0,i=left;k<l;k++,i++){
        tab[i]=tmp[k];
    }
}

template<class T>
void mergesort(std::vector<T> &tab, const int left, const int right) {
    if(left<right) {
        int mid=left+(right-left)/2;
        mergesort(tab, left, mid);
        mergesort(tab, mid+1, right);
        merge(tab, left, mid, right);
    }
}

#endif
