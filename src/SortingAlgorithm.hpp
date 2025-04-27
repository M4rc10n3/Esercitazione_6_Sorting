#pragma once

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};
/* Bubble sort algorithm as implemented in class */
template<Sortable T>
void BubbleSort(vector<T>& v);

/* Heap sort algorithm that creates and sorts the heap with the specific functions make_heap and sort_heap 
    of the <algorithm> header*/
template<Sortable T>
void HeapSortNotImplemented(vector<T>& v);

/* Heap sort algorithm that creates the heap with the specific function make_heap of the <algorithm> header and 
    sorts it using the pop_heap function recursively*/
template<Sortable T>
void HeapSortSemiImplemented(vector<T>& v);

/* Heap sort algorithm that creates the heap recursively with the push_heap function and 
    sorts it using the pop_heap function recursively (this was the way we implemented it in class)*/
template<Sortable T>
void HeapSortFullyImplemented(vector<T>& v);

/* TimeElapsedBubbleSort gives as output the time needed in order to sort the vector using the algorithm BubbleSort 
vector_imported: the vector on whihc we want to use the algorithm in order to sort it;
num_experiments: the number of experiments we want to do to test the algorithm; they are used
 to calculate the mean of time needed for the algorithm; */
template <Sortable T>
double TimeElapsedBubbleSort(vector<T>& vector_imported, const unsigned int& num_experiments);

/* TimeElapsedHeapSortNotImplemented gives as output the time needed in order to sort the vector using 
the algorithm HeapSortNotImplemented 
vector_imported: the vector on whihc we want to use the algorithm in order to sort it;
num_experiments: the number of experiments we want to do to test the algorithm; they are used
 to calculate the mean of time needed for the algorithm; */
template <Sortable T>
double TimeElapsedHeapSortNotImplemented(vector<T>& vector_imported, const unsigned int& num_experiments);

/* TimeElapsedHeapSortSemiImplemented gives as output the time needed in order to sort the vector using 
the algorithm HeapSortSemiImplemented 
vector_imported: the vector on whihc we want to use the algorithm in order to sort it;
num_experiments: the number of experiments we want to do to test the algorithm; they are used
 to calculate the mean of time needed for the algorithm; */
template <Sortable T>
double TimeElapsedHeapSortSemiImplemented(vector<T>& vector_imported, const unsigned int& num_experiments);

/* TimeElapsedHeapSortFullyImplemented gives as output the time needed in order to sort the vector using 
the algorithm HeapSortFullyImplemented 
vector_imported: the vector on whihc we want to use the algorithm in order to sort it;
num_experiments: the number of experiments we want to do to test the algorithm; they are used
 to calculate the mean of time needed for the algorithm; */
template <Sortable T>
double TimeElapsedHeapSortFullyImplemented(vector<T>& vector_imported, const unsigned int& num_experiments);

/* TheBest tells which is the best algorithm for the vector, using if and else constructs, 
and returning different numbers based on the different best algorithm 
time_elapsed_bubble_sort: time needed in order to sort the vector using the algorithm BubbleSort 
time_elapsed_heap_sort_not_implemented: time needed in order to sort the vector using the algorithm HeapSortNotImplemented 
time_elapsed_heap_sort_semi_implemented: time needed in order to sort the vector using the algorithm HeapSortSemiImplemented 
time_elapsed_heap_sort_fully_implemented: time needed in order to sort the vector using the algorithm HeapSortFullyImplemented */
int TheBest(double& time_elapsed_bubble_sort,
            double& time_elapsed_heap_sort_not_implemented,
            double& time_elapsed_heap_sort_semi_implemented,
            double& time_elapsed_heap_sort_fully_implemented);

}


