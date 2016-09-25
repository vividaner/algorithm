//
//  Sort.h
//  algorithm
//
//  Created by DanMiao on 5/2/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Sort_h
#define Sort_h


#endif /* Sort_h */

void BubbleSort(int a[], int Num)
{
    for(int i = 0; i < Num; i++)
    {
        for(int j = 0; j < Num-i-1; j++)
        {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

void InsertSort(int a[], int Num)
{
    int tem;
    int j;
    for(int i = 1; i < Num; i++)
    {
        tem = a[i];
        for(j = i; j >=0; j--)
        {
            if(a[j-1] > tem)
                a[j] = a[j-1];
            else
                break;
        }
        a[j] = tem;
    }
}

void SelectSort(int a[], int Num)
{
    int k;
    for(int i = 0; i < Num; i++)
    {
        k = i;
        for(int j = i+1; j < Num; j++)
        {
            if(a[j] < a[k])
                k = j;
        }
        if(k != i)
            swap(a[k], a[i]);
    }
    
}


void CountSort(int a[], int Num)
{
    
}

void shell_sort(int a[], int start, int end, int gap)
{
    int tem;
    int j;
    for(int i = start+gap; i < end; i++)
    {
        tem = a[i];
        for(j = i; j >= start && j >= gap; j -= gap)
        {
            if(a[j-gap] > a[j])
                a[j] = a[j-gap];
            else
                break;
        }
        a[j] = tem;
    }
}

void ShellSort(int a[], int Num)
{
    int gap = Num;
    while(gap > 1)
    {
        gap = gap/3+1;
        shell_sort(a, 0, Num, gap);
    }
    
}




void Merge(int a[], int start, int mid, int end)
{
    int* tem = new int[end-start];
    int k = 0;
    int i = start;
    int j = mid;
    while(i < mid && j < end)
    {
        if(a[i] < a[j])
            tem[k++] = a[i++];
        else
            tem[k++] = a[j++];
    }
    while(i < mid)
        tem[k++] = a[i++];
    while(j < end)
        tem[k++] = a[j++];
    
    for(k = 0; k < end-start; k++)
        a[start+k] = tem[k];
    delete [] tem;
}

void MergeSort(int a[], int start, int end)
{
    if(start < end-1)
    {
        int mid = (start + end)/2;
        MergeSort(a, start, mid);
        MergeSort(a, mid, end);
        Merge(a, start, mid, end);
    }
    
    
    
}





int partition(int a[], int start, int end)
{
    int pivotKey = a[start];
    while(start < end)
    {
        while(start < end && a[end] >= pivotKey)
            end--;
        swap(a[start], a[end]);
        while(start < end && a[start] <= pivotKey)
            start++;
        swap(a[start],a[end]);
    }
    return start;
}


void QuickSort(int a[], int start, int end)
{
    if(start < end-1)
    {
        int pivot = partition(a, start, end);
        QuickSort(a, start, pivot);
        QuickSort(a, pivot+1, end);
    }
}

void MaxLeapFixDown(int a[], int i, int Num)
{
    int tem, j;
    tem = a[i];
    j = 2*i+1;
    while(j < Num)
    {
        if(j+1 < Num && a[j] < a[j+1])
            j++;
        if(a[j] <= tem)
            break;
        else
        {
            a[i] = a[j];
            i = j;
            j = 2*i+1;
        }
    }
    a[i] = tem;
}

void MaxLeapCreate(int a[], int Num)
{
    for(int i = Num/2; i >=0; i--)
        MaxLeapFixDown(a, i, Num);
}

void LeapSort(int a[], int Num)
{
    MaxLeapCreate(a, Num);
    for(int i = 0; i < Num; i++)
        printf("%d\t",a[i]);
    cout << endl;
    
    for(int i = Num-1; i >=0; i--)
    {
        swap(a[0], a[i]);
        MaxLeapFixDown(a, 0, i);
        
        for(int k = 0; k < Num; k++)
            printf("%d\t",a[k]);
        cout << endl;

    }
}
