#ifndef INTROSORT_HPP
#define INTROSORT_HPP

#include <vector>
#include "quicksort.hpp"

template<class T>
void heapify(std::vecor<T> &vec, const int left, const int right) {
    int j, i=left;
    while (i<=right/2)
    {
        j=2*i;
        if (j+1<=right && vec[j+1]>vec[j])
            j=j+1;
        if (vec[i]<vec[j]) {
            T tmp = vec[0];
            vec[0] = vec[i];
            vec[i] = tmp;
        }
        else
            break;
        i=j;
    }
}

template<class T>
void heapsort(std::vector<T> &vec, const int left, const int right) {
    int i;
    for (i=N/2;i>0;i--) {
        heapify(vec-1,i,N);
    }
    for (i=N-1; i>0; --i) {
        T tmp = vec[0];
        vec[0] = vec[i];
        vec[i] = tmp;
        heapify(vec-1,1,i);
    }
}

template<class T>
void introsort(std::vector<T> &vec) {

}
