#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <string>
#include "SortingAlgorithm.cpp"

using namespace std;

using namespace SortLibrary;

int main(int argc, char* argv[]){

    cout << "argc: " << argc << endl;
    for(int a = 0; a < argc; a++)
        cout << argv[a] << endl; 

    cout << "How many elements would you like the vectors to have?" << endl;
    cout << "Number of elements: ";
    int dimension;
    cin >> dimension;

    // v1 is a vector with pseudo-random "int" elements generated with seed 7 and not greater than 135
    srand(7);
    vector<int> v1(dimension);
    for(int i = 0; i < dimension; i++){
        v1[i] = rand() % 135;
    }

    // v2 is a vector with consecutive "int" elements starting from -3
    vector<int> v2(dimension);
    std::iota(v2.begin(), v2.end(), -3);

    // v3 is a vector with elements of type "double" between 0 and 1
    srand(23);
    vector<double> v3(dimension);
    for(int i = 0; i < dimension; i++)
        v3[i] = rand() / ((double)RAND_MAX);

    /* v4 is a vector composed by consecutive elements in its first half 
    and pseudo-random "int" elements generated with seed 13 and not greater than 369 */
    srand(13);
    vector<int> v4(dimension);
    for(int i = int(dimension * 0.5); i < dimension; i++)
        v4[i] = rand() % 369;
    copy(v2.begin(), v2.begin() + int(dimension * 0.5), v4.begin());

    /* v5 is a vector with pseudo-random "int" elements generated with seed equal to the time (expressed in seconds)
    since the epoch; they are not greater than 135 */
    const auto today_time = chrono::system_clock::now();
    srand(chrono::duration_cast<chrono::seconds>(
        today_time.time_since_epoch()).count());
    vector<int> v5(dimension);
    for(int i = 0; i < dimension; i++){
        v5[i] = rand() % 248;
    }

    unsigned int num_experiments = 111;

    /* Performing the bubble sort algorithm on every vector and saving the time needed for each set of experiments */
    double time_elapsed_bubble_sort_v1 = TimeElapsedBubbleSort(v1, num_experiments);
    double time_elapsed_bubble_sort_v2 = TimeElapsedBubbleSort(v2, num_experiments);
    double time_elapsed_bubble_sort_v3 = TimeElapsedBubbleSort(v3, num_experiments);
    double time_elapsed_bubble_sort_v4 = TimeElapsedBubbleSort(v4, num_experiments);
    double time_elapsed_bubble_sort_v5 = TimeElapsedBubbleSort(v5, num_experiments);
    cout << "Bubble Sort - v1: " << time_elapsed_bubble_sort_v1 << endl;
    cout << "Bubble Sort - v2: " << time_elapsed_bubble_sort_v2 << endl;
    cout << "Bubble Sort - v3: " << time_elapsed_bubble_sort_v3 << endl;
    cout << "Bubble Sort - v4: " << time_elapsed_bubble_sort_v4 << endl;
    cout << "Bubble Sort - v5: " << time_elapsed_bubble_sort_v5 << endl;

    /* Performing the heap sort algorithm (creating and sorting the heap with the specific functions make_heap and sort_heap 
    of the <algorithm> header) on every vector and saving the time needed for each set of experiments */
    double time_elapsed_heap_sort_not_implemented_v1 = TimeElapsedHeapSortNotImplemented(v1, num_experiments);
    double time_elapsed_heap_sort_not_implemented_v2 = TimeElapsedHeapSortNotImplemented(v2, num_experiments);
    double time_elapsed_heap_sort_not_implemented_v3 = TimeElapsedHeapSortNotImplemented(v3, num_experiments);
    double time_elapsed_heap_sort_not_implemented_v4 = TimeElapsedHeapSortNotImplemented(v4, num_experiments);
    double time_elapsed_heap_sort_not_implemented_v5 = TimeElapsedHeapSortNotImplemented(v5, num_experiments);
    cout << "Heap Sort Not Implemented - v1: " << time_elapsed_heap_sort_not_implemented_v1 << endl;
    cout << "Heap Sort Not Implemented - v2: " << time_elapsed_heap_sort_not_implemented_v2 << endl;
    cout << "Heap Sort Not Implemented - v3: " << time_elapsed_heap_sort_not_implemented_v3 << endl;
    cout << "Heap Sort Not Implemented - v4: " << time_elapsed_heap_sort_not_implemented_v4 << endl;
    cout << "Heap Sort Not Implemented - v5: " << time_elapsed_heap_sort_not_implemented_v5 << endl;

    /* Performing the heap sort algorithm (creating the heap with the specific function make_heap of the <algorithm> header and 
    sorting it using the pop_heap function recursively) on every vector and saving the time needed for each set of experiments */
    double time_elapsed_heap_sort_semi_implemented_v1 = TimeElapsedHeapSortSemiImplemented(v1, num_experiments);
    double time_elapsed_heap_sort_semi_implemented_v2 = TimeElapsedHeapSortSemiImplemented(v2, num_experiments);
    double time_elapsed_heap_sort_semi_implemented_v3 = TimeElapsedHeapSortSemiImplemented(v3, num_experiments);
    double time_elapsed_heap_sort_semi_implemented_v4 = TimeElapsedHeapSortSemiImplemented(v4, num_experiments);
    double time_elapsed_heap_sort_semi_implemented_v5 = TimeElapsedHeapSortSemiImplemented(v5, num_experiments);
    cout << "Heap Sort Semi Implemented - v1: " << time_elapsed_heap_sort_semi_implemented_v1 << endl;
    cout << "Heap Sort Semi Implemented - v2: " << time_elapsed_heap_sort_semi_implemented_v2 << endl;
    cout << "Heap Sort Semi Implemented - v3: " << time_elapsed_heap_sort_semi_implemented_v3 << endl;
    cout << "Heap Sort Semi Implemented - v4: " << time_elapsed_heap_sort_semi_implemented_v4 << endl;
    cout << "Heap Sort Semi Implemented - v5: " << time_elapsed_heap_sort_semi_implemented_v5 << endl;

    /* Performing the heap sort algorithm (creating the heap recursively with the push_heap function and 
    sorting it using the pop_heap function recursively) on every vector and saving the time needed for each set of experiments */
    double time_elapsed_heap_sort_fully_implemented_v1 = TimeElapsedHeapSortFullyImplemented(v1, num_experiments);
    double time_elapsed_heap_sort_fully_implemented_v2 = TimeElapsedHeapSortFullyImplemented(v2, num_experiments);
    double time_elapsed_heap_sort_fully_implemented_v3 = TimeElapsedHeapSortFullyImplemented(v3, num_experiments);
    double time_elapsed_heap_sort_fully_implemented_v4 = TimeElapsedHeapSortFullyImplemented(v4, num_experiments);
    double time_elapsed_heap_sort_fully_implemented_v5 = TimeElapsedHeapSortFullyImplemented(v5, num_experiments);
    cout << "Heap Sort Fully Implemented - v1: " << time_elapsed_heap_sort_fully_implemented_v1 << endl;
    cout << "Heap Sort Fully Implemented - v2: " << time_elapsed_heap_sort_fully_implemented_v2 << endl;
    cout << "Heap Sort Fully Implemented - v3: " << time_elapsed_heap_sort_fully_implemented_v3 << endl;
    cout << "Heap Sort Fully Implemented - v4: " << time_elapsed_heap_sort_fully_implemented_v4 << endl;
    cout << "Heap Sort Fully Implemented - v5: " << time_elapsed_heap_sort_fully_implemented_v5 << endl;

    cout << "For v1 with " << dimension << " elements, the best algorithm is: ";
    int result1 = TheBest(time_elapsed_bubble_sort_v1, time_elapsed_heap_sort_not_implemented_v1, 
        time_elapsed_heap_sort_semi_implemented_v1, time_elapsed_heap_sort_fully_implemented_v1);
    if(result1 == 2){
        cout << "Bubble Sort." << endl;
    }
    else if (result1 == 3){
        cout << "Heap Sort Not Implemented." << endl;
    }
    else if (result1 == 4){
        cout << "Heap Sort Semi Implemented." << endl;
    }
    else{
        cout << "Heap Sort Fully Implemented." << endl;
    }

    cout << "For v2 with " << dimension << " elements, the best algorithm is: ";
    int result2 = TheBest(time_elapsed_bubble_sort_v2, time_elapsed_heap_sort_not_implemented_v2, 
        time_elapsed_heap_sort_semi_implemented_v2, time_elapsed_heap_sort_fully_implemented_v2);
    if(result2 == 2){
        cout << "Bubble Sort." << endl;
    }
    else if (result2 == 3){
        cout << "Heap Sort Not Implemented." << endl;
    }
    else if (result2 == 4){
        cout << "Heap Sort Semi Implemented." << endl;
    }
    else{
        cout << "Heap Sort Fully Implemented." << endl;
    }

    cout << "For v3 with " << dimension << " elements, the best algorithm is: ";
    int result3 = TheBest(time_elapsed_bubble_sort_v3, time_elapsed_heap_sort_not_implemented_v3, 
        time_elapsed_heap_sort_semi_implemented_v3, time_elapsed_heap_sort_fully_implemented_v3);
    if(result3 == 2){
        cout << "Bubble Sort." << endl;
    }
    else if (result3 == 3){
        cout << "Heap Sort Not Implemented." << endl;
    }
    else if (result3 == 4){
        cout << "Heap Sort Semi Implemented." << endl;
    }
    else{
        cout << "Heap Sort Fully Implemented." << endl;
    }

    cout << "For v4 with " << dimension << " elements, the best algorithm is: ";
    int result4 = TheBest(time_elapsed_bubble_sort_v4, time_elapsed_heap_sort_not_implemented_v4, 
        time_elapsed_heap_sort_semi_implemented_v4, time_elapsed_heap_sort_fully_implemented_v4);
    if(result4 == 2){
        cout << "Bubble Sort." << endl;
    }
    else if (result4 == 3){
        cout << "Heap Sort Not Implemented." << endl;
    }
    else if (result4 == 4){
        cout << "Heap Sort Semi Implemented." << endl;
    }
    else{
        cout << "Heap Sort Fully Implemented." << endl;
    }
    
    cout << "For v5 with " << dimension << " elements, the best algorithm is: ";
    int result5 = TheBest(time_elapsed_bubble_sort_v5, time_elapsed_heap_sort_not_implemented_v5, 
        time_elapsed_heap_sort_semi_implemented_v5, time_elapsed_heap_sort_fully_implemented_v5);
    if(result5 == 2){
        cout << "Bubble Sort." << endl;
    }
    else if (result5 == 3){
        cout << "Heap Sort Not Implemented." << endl;
    }
    else if (result5 == 4){
        cout << "Heap Sort Semi Implemented." << endl;
    }
    else{
        cout << "Heap Sort Fully Implemented." << endl;
    }

    return 0;
}

