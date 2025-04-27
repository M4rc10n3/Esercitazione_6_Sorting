#include <vector>
#include <algorithm>
#include <chrono>
#include "SortingAlgorithm.hpp"

using namespace std;

namespace SortLibrary {

template<Sortable T>
void BubbleSort(vector<T>& v){
    for(unsigned int i = 0; i < v.size() - 1; i++){
        for(unsigned int j = i + 1; j < v.size(); j++){
            if(v[j] < v[i]){
                //swap
                T temporary = v[i];
                v[i] = v[j];
                v[j] = temporary;
            }
        }

    }
}

/* Heap sort algorithm that creates and sorts the heap with the specific functions make_heap and sort_heap 
    of the <algorithm> header*/
template<Sortable T>
void HeapSortNotImplemented(vector<T>& v){
    make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end());
}

/* Heap sort algorithm that creates the heap with the specific function make_heap of the <algorithm> header and 
    sorts it using the pop_heap function recursively*/
template<Sortable T>
void HeapSortSemiImplemented(vector<T>& v){
    make_heap(v.begin(), v.end());
    /* The "pop_heap" function swaps the greatest element of the heap and its last element, so every time we call it, 
    pop_heap puts the greatest element of the heap in the position pointed by the second input. 
    This is the reason why the second input of the function is `v.end() - i` and not simply `v.end()` */
    for(unsigned int i = 0; i < v.size(); i++){
        pop_heap(v.begin(),v.end() - i);
    }
}

/* Heap sort algorithm that creates the heap recursively with the push_heap function and 
    sorts it using the pop_heap function recursively */
template<Sortable T>
void HeapSortFullyImplemented(vector<T>& v){
    /* The "push_heap" function creates a heap with the elements contained between the two iterators it takes as inputs; 
    unfortunately, if the elements between the iterators don't make a heap, the behavior is undefined. 
    Therefore, at each for cycle we should add just one element to the heap, starting from zero elements. 
    At the first iteration, "push_heap" will create a heap between the iterators it takes as inputs with just one element, 
    at the second iteration it will create a heap with two elements and so on... 
    (I checked it made a heap at each iteration using the function "is_heap" contained in the <algorithm> header 
    using a differente code file not shared on GitHub) */
    for(unsigned int i = 0; i <= v.size(); i++){
        push_heap(v.begin(), v.begin() + i);
    }
    for(unsigned int i = 0; i < v.size(); i++){
        pop_heap(v.begin(), v.end() - i);
    }
}


template <Sortable T>
double TimeElapsedBubbleSort(vector<T>& vector_imported, const unsigned int& num_experiments){
    double time_elapsed = 0.0;
    for(unsigned int t = 0; t < num_experiments; t++){
        vector<T> v(vector_imported);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        SortLibrary::BubbleSort<T>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed /= num_experiments;
    return time_elapsed;
}

template <Sortable T>
double TimeElapsedHeapSortNotImplemented(vector<T>& vector_imported, const unsigned int& num_experiments){
    double time_elapsed = 0.0;
    for(unsigned int t = 0; t < num_experiments; t++){
        vector<T> v(vector_imported);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        SortLibrary::HeapSortNotImplemented<T>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed /= num_experiments;
    return time_elapsed;
}

template <Sortable T>
double TimeElapsedHeapSortSemiImplemented(vector<T>& vector_imported, const unsigned int& num_experiments){
    double time_elapsed = 0.0;
    for(unsigned int t = 0; t < num_experiments; t++){
        vector<T> v(vector_imported);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        SortLibrary::HeapSortSemiImplemented<T>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed /= num_experiments;
    return time_elapsed;
}

template <Sortable T>
double TimeElapsedHeapSortFullyImplemented(vector<T>& vector_imported, const unsigned int& num_experiments){
    double time_elapsed = 0.0;
    for(unsigned int t = 0; t < num_experiments; t++){
        vector<T> v(vector_imported);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        SortLibrary::HeapSortFullyImplemented<T>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed /= num_experiments;
    return time_elapsed;
}

int TheBest(double& time_elapsed_bubble_sort,
            double& time_elapsed_heap_sort_not_implemented,
            double& time_elapsed_heap_sort_semi_implemented,
            double& time_elapsed_heap_sort_fully_implemented){

                if(time_elapsed_bubble_sort < time_elapsed_heap_sort_not_implemented &&
                   time_elapsed_bubble_sort < time_elapsed_heap_sort_semi_implemented && 
                   time_elapsed_bubble_sort < time_elapsed_heap_sort_fully_implemented){
                    return 2;
                }
                else if(time_elapsed_heap_sort_not_implemented < time_elapsed_heap_sort_fully_implemented &&
                    time_elapsed_heap_sort_not_implemented < time_elapsed_heap_sort_semi_implemented && 
                    time_elapsed_heap_sort_not_implemented < time_elapsed_bubble_sort){
                        return 3;
                }
                else if(time_elapsed_heap_sort_semi_implemented < time_elapsed_heap_sort_fully_implemented &&
                    time_elapsed_heap_sort_semi_implemented < time_elapsed_heap_sort_not_implemented && 
                    time_elapsed_heap_sort_semi_implemented < time_elapsed_bubble_sort){
                        return 4;
                }
                else{
                        return 5;
                }


            }


}




