#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
// Função de ordenação Selection Sort 
void selectionSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[minIndex]) { 
                minIndex = j; 
            } 
        } 
        int temp = arr[minIndex]; 
        arr[minIndex] = arr[i]; 
        arr[i] = temp; 
    } 
} 
 
// Função de ordenação Insertion Sort 
void insertionSort(int arr[], int n) { 
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
} 
 
// Função de ordenação Bubble Sort 
void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 
 
// Função de ordenação Merge Sort 
void merge(int arr[], int left, int mid, int right) { 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
    int L[n1], R[n2]; 
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (int j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 
    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
 
void mergeSort(int arr[], int left, int right) { 
    if (left < right) { 
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
    } 
} 
 
// Função de ordenação Quick Sort 
int partition(int arr[], int low, int high) { 
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j < high; j++) { 
        if (arr[j] < pivot) { 
            i++; 
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        } 
    } 
    int temp = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = temp; 
    return i + 1; 
} 
 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
 
// Função de ordenação Heap Sort 
void heapify(int arr[], int n, int i) { 
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[largest]) 
        largest = left; 
    if (right < n && arr[right] > arr[largest]) 
        largest = right; 
    if (largest != i) { 
        int temp = arr[i]; 
        arr[i] = arr[largest]; 
        arr[largest] = temp; 
        heapify(arr, n, largest); 
    } 
} 
 
void heapSort(int arr[], int n) { 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i = n - 1; i >= 0; i--) { 
        int temp = arr[0]; 
        arr[0] = arr[i]; 
        arr[i] = temp; 
        heapify(arr, i, 0); 
    } 
} 
 
// Função para imprimir o array 
void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
} 
 
// Funções wrapper para Merge Sort e Quick Sort 
void mergeSortHelper(int arr[], int n) { 
mergeSort(arr, 0, n - 1); 
} 
void quickSortHelper(int arr[], int n) { 
quickSort(arr, 0, n - 1); 
} 
// Função para medir o tempo de execução de um algoritmo de ordenação 
void measureSortTime(void (*sortFunc)(int[], int), int arr[], int n) { 
clock_t start, end; 
start = clock(); 
sortFunc(arr, n);  // Chama a função de ordenação 
end = clock(); 
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
printf("Tempo de execução: %f segundos\n", time_taken); 
} 
// Função principal 
int main() { 
int n = 10;  // Tamanho do array para teste 
int arr[n]; 
// Gerar array aleatório 
for (int i = 0; i < n; i++) { 
arr[i] = rand() % 100;  // Números aleatórios entre 0 e 99 
} 
printf("Array gerado:\n"); 
printArray(arr, n); 
 
    int arrCopy[n]; 
 
    // Testar Selection Sort 
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i]; 
    printf("Selection Sort:\n"); 
    measureSortTime(selectionSort, arrCopy, n); 
    printArray(arrCopy, n); 
 
    // Testar Insertion Sort 
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i]; 
    printf("Insertion Sort:\n"); 
    measureSortTime(insertionSort, arrCopy, n); 
    printArray(arrCopy, n); 
 
    // Testar Bubble Sort 
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i]; 
    printf("Bubble Sort:\n"); 
    measureSortTime(bubbleSort, arrCopy, n); 
    printArray(arrCopy, n); 
 
    // Testar Merge Sort (usando wrapper) 
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i]; 
    printf("Merge Sort:\n"); 
    measureSortTime(mergeSortHelper, arrCopy, n); 
    printArray(arrCopy, n); 
 
    // Testar Quick Sort (usando wrapper) 
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i]; 
    printf("Quick Sort:\n"); 
    measureSortTime(quickSortHelper, arrCopy, n); 
printArray(arrCopy, n); 
// Testar Heap Sort 
for (int i = 0; i < n; i++) arrCopy[i] = arr[i]; 
printf("Heap Sort:\n"); 
measureSortTime(heapSort, arrCopy, n); 
printArray(arrCopy, n); 
return 0; 
}