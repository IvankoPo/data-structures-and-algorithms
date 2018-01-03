#include <iostream>
#include <vector>

void QuickSort(std::vector<int> &arr,int left,int right)
{
    int i=left, 
            j=right,
            mid=arr[left+((right-left)>>1)];
    while(i<=j)
    {
        while(arr[i] < mid) i++;
        while(arr[j] > mid) j--;
        if(i<=j)
        {
            std::swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(i < right)
        QuickSort(arr,i,right);
    if(left<j)
        QuickSort(arr,left,j);
}

int main() 
{
    std::vector<int> v = {13, 24, 43, 21, 22, 17, 28, 14, 15, 20};
    QuickSort(v, 0, 9);
    for(int i: v){
        std::cout << i << " ";
    }
    return 0;
}
// 13 14 15 17 20 21 22 24 28 43 