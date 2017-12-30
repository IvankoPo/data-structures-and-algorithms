#include<iostream>
#include<vector>
// Опустить вершину
void SiftDown(std::vector<int>& arr, int size, int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if (left < size && arr[left] > arr[i])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i){
        std::swap(arr[i], arr[largest]);
        SiftDown(arr,size,  largest);
    }
}
// Поднять вершину вверх
void SiftUp(std::vector<int>& arr, int index)
{
    while(index > 0){
        int parent = (index-1)/2;
        if(arr[index] <= arr[parent])
            return;
        std::swap(arr[index], arr[parent]);
        index = parent;
    }
}
// Построить кучу из массива
void BuildHeap(std::vector<int> &arr)
{
    for (int i = arr.size() /2 - 1; i>=0; i--){
        SiftDown(arr, arr.size() ,i);
    }
}
// Добавляем элемент и восстанавлиевам основное свойство кучи
void Add(std::vector<int> &arr, int element)
{
    arr.push_back(element);
    SiftUp(arr, arr.size() -1);
}
// Извлечь максимум, восстановить свойство кучи
int ExtractMax(std::vector<int> &arr)
{
    if (arr.empty())
        return 0;
    int result = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    if (!arr.empty())
    {
        SiftDown(arr, arr.size(), 0);
    }
    return result;
}
// Пирамидальная сортировка(сортировка кучей)
void HeapSort(std::vector<int> &arr)
{
    int heapsize = arr.size();
    BuildHeap(arr);
    while(heapsize > 1)
    {
        std::swap(arr[0], arr[heapsize - 1]);
        --heapsize;
        SiftDown(arr, heapsize, 0);
    }
}
int main()
{
    std::vector<int> a = {11,14,4,8,2,7, 5,16, 19, 9};
    for (int i: a)
        std::cout << i << " ";
    BuildHeap(a);
    HeapSort(a);
    std::cout << std::endl;
    for (int i: a)
    std::cout << i << " ";
    return 0;
}