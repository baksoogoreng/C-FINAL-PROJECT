#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void menu()
{
    printf("\nPROGRAM PENGURUTAN DAN PENCARIAN\n");
    printf("=============================\n");
    printf("Silakan Memilih Menu\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Sequential Search\n");
    printf("5. Binary Search\n");
    printf("0. Keluar\n");
    printf("=============================\n");
}

void jumlah()
{
    printf("Jumlah Data :\n");
    printf("1. 1000\n");
    printf("2. 16000\n");
    printf("3. 64000\n");
    printf("\nPilihan jumlah data : \n");
}

void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void selectionsort(int arr[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
    }
}

void bubblesort(int arr[], int n)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        int i = 0;
        while (i < n - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
            i++;
        }
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int tempLow = low;
    int tempHigh = high;
    while (tempLow < tempHigh)
    {
        while (arr[tempLow] <= pivot && tempLow <= high - 1)
        {
            tempLow++;
        }
        while (arr[tempHigh] > pivot && tempHigh >= low + 1)
        {
            tempHigh--;
        }
        if (tempLow < tempHigh)
            swap(&arr[tempLow], &arr[tempHigh]);
    }
    swap(&arr[low], &arr[tempHigh]);
    return tempHigh;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int sequentialsearch(int arr[], int n)
{
    int search = rand() % 1000;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[], int n)
{
    int search = rand() % 1000;
    int bawah = 0;
    int atas = n-1;
    while (bawah <= atas)
    {
        int mid =(atas + bawah) / 2;
        if (arr[mid] == search)
        {
            return mid;
        }
        else{
            if (arr[mid] < search)
                bawah = mid + 1;
            else
                atas = mid - 1;
        }
        
    }
    return -1;
}

int main()
{
    int pilihan, jumlahdata, arr[64000], n;
    clock_t start, end;
    do
    {
        menu();
        printf("\nMasukkan nomor program : ");
        scanf("%d", &pilihan);
        if (pilihan == 0)
        {
            printf("Keluar dari program.\n");
            break;
        }
        jumlah();
        scanf("%d", &jumlahdata);
        if (jumlahdata == 1)
        {
            n = 1000;
        }
        else if (jumlahdata == 2)
        {
            n = 16000;
        }
        else if (jumlahdata == 3)
        {
            n = 64000;
        }
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 1000;
        }

        if (pilihan == 1)
        {
            start = clock();
            selectionsort(arr, n);
            end = clock();
        }
        else if (pilihan == 2)
        {
            start = clock();
            bubblesort(arr, n);
            end = clock();
        }

        else if (pilihan == 3)
        {
            start = clock();
            quickSort(arr, 0, n - 1);
            end = clock();
        }

        else if (pilihan == 4)
        {
            quickSort(arr, 0, n - 1);
            start = clock();
            int found = sequentialsearch(arr, n);
            end = clock();
            if (found != -1)
            {
                printf("Data ditemukan di indeks %d\n", found);
            }
            else
            {
                printf("Data tidak berhasil ditemukan!\n");
            }
        }
        else if (pilihan == 5)
        {
            quickSort(arr, 0, n - 1);
            start = clock();
            int found = binarysearch(arr, n);
            end = clock();
            if (found != -1)
            {
                printf("Data ditemukan di indeks %d\n", found);
            }
            else
            {
                printf("Data tidak berhasil ditemukan!\n");
            }
        }
        else if (pilihan == 0)
        {
            break;
        }
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("It took %f seconds to execute \n", time_taken);
    } while (pilihan != 0);
    return 0;
}