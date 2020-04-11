#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

const int MAX = 100000004;

int random() {
    return ((rand() & ((1 << 15) - 1)) << 0) |
           ((rand() & ((1 << 15) - 1)) << 15);
}

void pushDown(int* array, int idx, int len) {
    while (idx * 2 + 1 < len) {
        int child = idx * 2 + 1;
        if (child + 1 < len && array[child] < array[child + 1])
            child++;
        if (array[idx] >= array[child])
            break;
        swap(array[child], array[idx]);
        idx = child;
    }
}

void heapSort(int* array, int len) {
    for (int i = len - 1; i >= 0; i--) {
        pushDown(array, i, len);
    }
    for (; len > 1; len--) {
        swap(array[0], array[len - 1]);
        pushDown(array, 0, len - 1);
    }
}

void merge(int* where, int* p1, int s1, int* p2, int s2) {
    int idx1 = 0, idx2 = 0;
    while (idx1 < s1 && idx2 < s2) {
        if (p1[idx1] < p2[idx2])
            where[idx1 + idx2] = p1[idx1], idx1++;
        else
            where[idx1 + idx2] = p2[idx2], idx2++;
    }
    while (idx1 < s1) where[idx1 + idx2] = p1[idx1], idx1++;
    while (idx2 < s2) where[idx1 + idx2] = p2[idx2], idx2++;
}

void mergeSort(int* array, int size, int* aux) {
    if (size > 1) {
        mergeSort(array, size / 2, aux);
        mergeSort(array + size / 2, size - size / 2, aux + size / 2);
        merge(aux, array, size / 2, array + size / 2, size - size / 2);
        memcpy(array, aux, sizeof(array[0]) * size);
    }
}

void quicksort(int* array, int size) {
    if (size > 1) {
        int pivot = array[random() % size];

        // Less
        int left = 0;
        for (int i = 0; i < size; i++)
            if (array[i] < pivot) swap(array[i], array[left++]);
        quicksort(array, left);
        
        // Greater
        int right = size - 1;
        for (int i = size - 1; i >= left; i--)
            if (pivot < array[i]) swap(array[i], array[right--]);
        quicksort(array + right + 1, size - right - 1);
    }    
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++)
        fprintf(stdout, "%d%c", v[i], i + 1 == (int)v.size() ? '\n' : ' ');
}

void runTest(int testNum, const vector<int>& v) {
    fprintf(stderr, "Running testcase %d (sorting %d elements)...\n",
        testNum, (int)v.size());

    unsigned sTime, eTime;
    static int n;
    static int a[MAX];

    // STL sort
    sTime = clock();
    vector <int> stlSortRes = v;
    sort(stlSortRes.begin(), stlSortRes.end());
    eTime = clock();
    fprintf(stderr, "    >> STL sort execution time: %.3lfs.\n",
        (double)(eTime - sTime) / CLOCKS_PER_SEC);
    
    // Quicksort
    sTime = clock();
    n = (int)v.size();
    for (int i = 0; i < n; i++)
        a[i] = v[i];
    quicksort(a, n);
    vector <int> qsortRes(a, a + n);
    eTime = clock();
    fprintf(stderr, "    >> Quicksort execution time: %.3lfs.\n",
        (double)(eTime - sTime) / CLOCKS_PER_SEC);
    
    
    // Mergesort
    sTime = clock();
    n = (int)v.size();
    for (int i = 0; i < n; i++)
        a[i] = v[i];
    static int tmp[MAX];
    mergeSort(a, n, tmp);
    vector <int> msortRes(a, a + n);
    eTime = clock();
    fprintf(stderr, "    >> Mergesort execution time: %.3lfs.\n",
        (double)(eTime - sTime) / CLOCKS_PER_SEC);
    
    // Heapsort
    sTime = clock();
    n = (int)v.size();
    for (int i = 0; i < n; i++)
        a[i] = v[i];
    heapSort(a, n);
    vector <int> hsortRes(a, a + n);
    eTime = clock();
    fprintf(stderr, "    >> Heapsort execution time: %.3lfs.\n",
        (double)(eTime - sTime) / CLOCKS_PER_SEC);
    

    // Check answers
    if (qsortRes != stlSortRes) {
        fprintf(stderr, "ERROR: Quicksort result is wrong!\n");
        printVector(v);
        printVector(stlSortRes);
        printVector(qsortRes);
        exit(1);
    }
    if (msortRes != stlSortRes) {
        fprintf(stderr, "ERROR: Mergesort result is wrong!\n");
        printVector(v);
        printVector(stlSortRes);
        printVector(msortRes);
        exit(1);
    }
    if (hsortRes != stlSortRes) {
        fprintf(stderr, "ERROR: Heapsort result is wrong!\n");
        printVector(v);
        printVector(stlSortRes);
        printVector(hsortRes);
        exit(1);
    }
}

void runTests() {
    const int numTests = 8;
    int sizes[numTests] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

    for (int test = 0; test < numTests; test++) {
        vector <int> v(sizes[test]);
        for (int i = 0; i < (int)v.size(); i++)
            v[i] = random();
        runTest(test + 1, v);
    }
}

void sanityCheck() {
    vector <int> v({42, 13, 17, 5, 3, 67, 42, 10, 99, 8, 1, 3, 19});
    runTest(0, v);
}

int main(void) {
    sanityCheck();
    runTests();
    return 0;
}