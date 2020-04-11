#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<chrono>
using namespace std::chrono;
using std::cin;
using std::cout;

template<class T>
void swap(T&a,T&b){
    T temp=a;
    a=b;
    b=temp;
}
void gibRandom(int*arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        //srand(time(nullptr));
        arr[i]=-500+rand()%1000;
    }
    
}
template<class T>
void merge(T*arr,T *aux,int low,int mid,int high)
{
    int k=low,i=low,j=mid+1;
    while (i<=mid&&j<=high)
    {
        if (arr[i]<=arr[j])
        {
            aux[k++]=arr[i++];
        }
        else
        {
            aux[k++]=arr[j++];
        }
    }
    while (i<=mid)
    {
        aux[k++]=arr[i++];
    }
    for (int i = 0; i <= high; i++)
    {
        arr[i]=aux[i];
    }
    
}
template<class T>
void mergeSort(T*arr,T *aux,int low,int high)
{
    if (low==high)
    {
        return;
    }
    int mid=(low+((high-low)>>1));
    mergeSort(arr,aux,low,mid);
    mergeSort(arr,aux,mid+1,high);
    merge(arr,aux,low,mid,high);
}

template<class T>
void insert(T* a, int i)
{
	int j = i - 1;
	T min = a[i];
	while (j>=0&&a[j]>min)
	{
		a[j + 1] = a[j];
		--j;
	}
	a[j + 1] = min;
}
template<class T>
void insertionSort(T* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		insert(a, i);
	}
}

int isSorted(int arr[],int N)
{
	int prev = arr[0];
	for (int i = 1; i < N; i++) {
		if (prev > arr[i]) {
			printf("MergeSort Fails!!");
			return 0;
		}
		prev = arr[i];
	}

	return 1;
}

template<class T>
void benchAlgorithm(void(*algorithm)(T*,int),T* arr,int n,const char* name)
{
    auto start=high_resolution_clock::now();
    algorithm(arr,n);
    auto stop=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    printf("Time taken by %s: %d microseconds\n",name,duration.count());
}

template<class T>
void benchMerge(void(*mSort)(T*,T*,int,int),T*arr,T*aux,int low,int n,const char* name)
{
    auto start=high_resolution_clock::now();
    mSort(arr,aux,0,n);
    auto stop=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printf("Time taken by %s: %d microseconds\n",name,duration.count());
}

template<class T>
int binSearch(int*arr,int n,T x)
{
    int a=0,b=n-1;
    while (a<=b)
    {
        int k=(a+b)/2;
        if (arr[k]==x)
        {
            return k;
        }
        if (arr[k]>x)
        {
            b=k-1;
        }
        else
        {
            a=k+1;
        }
    }
    return -1;
}
template<class T>
int binSearch(T*a,int n,T x)
{
    int k=0;
    for (int  b = n/2; b >=1; b/=2)
    {
        while (k+b<n&&a[k+b]<=x)
        {
            k+=b;
        }
        if (a[k]==x)
        {
            return k;
        }
    }
    return -1;
}

int main()
{
    constexpr int n=315;
    int arr1[n]{0};
    int arr2[n]{0};
    int aux[n]{0};
    int index=0;
    while (index<15)
    {
        gibRandom(arr1,n);
        for (int i = 0; i < n; i++)
        {
            aux[i]=arr2[i]=arr1[i];
        }
        //benchAlgorithm(insertionSort,arr1,n,"insertion");
        //mergeSort(arr2,aux,0,n);
        benchMerge(mergeSort,arr2,aux,0,n,"merge");
        benchAlgorithm(insertionSort,arr1,n,"insertion");

        ++index;
    }
    
    isSorted(arr2,n);
}

/* int main(){
  
    // Call the function, here sort() 
    //int arr[] = { 15,22,-13,0,18,5435,13,56,122 };
	//int n = sizeof(a) / sizeof(a[0]);
	const int n=5000;
    int arr[n]{0};
    int arr2[n]{0};
    
    gibRandom(arr,n);
    int N=n;
	int aux[N];
	for (int i = 0; i < N; i++)
		aux[i] = arr[i];
    
    int i=0;
    while (i<10)
    {
        auto start = high_resolution_clock::now(); 
        // get inversion count by performing merge sort on arr
        mergeSort(arr, aux, 0, N - 1);
        // Get ending timepoint 
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start); 
        printf("Time taken tech: %d microseconds\n",duration.count());
        


        start = high_resolution_clock::now(); 
        // get inversion count by performing merge sort on arr
        mergeSortTemp(arr, N);

        // Get ending timepoint 
        stop = high_resolution_clock::now(); 
        duration = duration_cast<microseconds>(stop - start); 
        printf("Time taken dyn: %d microseconds\n\n",duration.count());
            ++i;
    }
    
	cout << "\n";
	return 0;
} 
*/