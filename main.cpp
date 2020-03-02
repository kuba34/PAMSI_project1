#include <iostream>
#include <random>
#include <chrono>
#include <array>
#include <vector>
#include <algorithm>

template<class T>
void mergesort(std::vector<T> &vec,int,int);
template<class T>
void quicksort(std::vector<T> &vec, int left, int right);
template<class T>
void introsort(std::vector<T> &vec);
template<class T>
void heapsort(std::vector<T> &vec);

/*
template<class Iter>
void quicksort(Iter begin, Iter end);
template<class Iter>
void mergesort(Iter begin, Iter end);
template<class Iter>
void introsort(Iter begin, Iter end);
*/
int main() {
    //TODO:
    //full random
    //25%, 50%, 75%, 95%, 99%, 99,7%
    //reverse sorted
    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    std::array<std::vector<int>, 40> arrays;

    for(int i = 0;i<5;++i) {
        for(int j = 0;j<8;++j) {
            arrays[i*8+j].reserve(sizes[i]);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000000);

    for(auto &vec:arrays) {
        for(int i=0;i<vec.capacity();++i) {
            vec.push_back(dis(gen));
        }
    }

    for(auto &a: arrays) {
        std::cout << a.size() << std::endl;
    }

    namespace ch = std::chrono;

    auto start = ch::steady_clock::now();
    //quicksort(arrays[35].begin(), arrays[35].end());
    //quicksort(arrays[0], 0, arrays[0].size());
    mergesort(arrays[0], 0, arrays[0].size());
    auto end = ch::steady_clock::now();

    bool is = std::is_sorted(arrays[0].begin(), arrays[0].end());
    std::cout << std::boolalpha << "Is sorted: "  << is << std::endl;
    std::cout << "Elapsed:  "  <<
        ch::duration_cast<ch::microseconds>(end-start).count() << "µs" << std::endl;
}

template<class T>
void quicksort(std::vector<T> &vec, int left, int right) {
     int i=left;
     int j=right;
     T pivot=vec[left+(right-left)/2];
     //T pivot=vec[(left+right)>>1];
     do{
         while(vec[i]<pivot) i++;
         while(vec[j]>pivot) j--;
         if(i<=j){
             int temp=vec[i];
             vec[i]=vec[j];
             vec[j]=temp;
             i++;
             j--;
         }
     }while(i<=j);
     if(left<j) quicksort(vec,left,j);
     if(right>i) quicksort(vec,i,right);
}

template<class T>
void merge(std::vector<T> &vec, int left, int mid, int right) {
    int i,j,q;
    std::vector<T> t;
    t.reserve(right+1);
    for (i=left; i<=right; i++) t[i]=vec[i];
    //for (i=left; i<=right; i++) t.push_back(vec[i]);
    i=left; j=mid+1; q=left;                 // Ustawienie wskaźników veclic
    while (i<=mid && j<=right) {         // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do veclicy głównej
        if (t[i]<t[j])
            vec[q++]=t[i++];
        else
            vec[q++]=t[j++];
    }
    while (i<=mid) vec[q++]=t[i++]; // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór się skończył
}

template<class T>
void mergesort(std::vector<T> &vec, int left, int right) {
    int mid;
    if (left<right) {
        mid=left+(right-left)/2;
        mergesort(vec, left, mid);    // Dzielenie lewej części
        mergesort(vec, mid+1, right);   // Dzielenie prawej części
        merge(vec, left, mid, right);   // Łączenie części lewej i prawej
    }
}

/*
template<class Iter>
Iter partition(Iter left, Iter right)
{
    Iter i=left-1;
    Iter it=left;
    while(it<right)
    {
        if(*it<=*right)
        {
            ++i;
            std::swap(*i,*it);
        }
        ++it;
    }

    std::iter_swap(i+1,right);
    return ++i;
}

template<class Iter>
void quicksort(Iter left, Iter right)
{
    if(std::distance(left,right)>1)
    {
        Iter pivot=partition(left,right);
        quicksort(left,pivot-1);
        quicksort(pivot+1,right);
    }
}
*/
