#include<stdio.h>
#include<stdlib.h>
struct Array
 {
    int A[10];
    int size;
    int length;

 };
 void Display(struct Array arr)
 {
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ", arr.A[i]);
    }
 }
 int Binarysearch(struct Array arr, int key)
 {
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid]) //if the number which is to be searched is already at mid index of the array
        {
            return mid; //mid only will be that number
        }
        else if(key<arr.A[mid])
        {
            h=mid-1; //we will shift "high" to the index just before the mid index because if the number which is to be searched is less than mid then "high" definitly should be the index b/w "low" and mid so that further searching can be performed for theonly  remaining useful part of the array(although mid will shift b/w high and low again accordingly)
        }
        else
        {
            l=mid+1; //we will shift "low" to the index just after the mid index because if the number which is to be searched is greater than mid then "low" definitly should be the index b/w "high" and mid so that further searching can be performed for the only  remaining useful part of the array(although mid will shift b/w high and low again accordingly)
        }
    }
    return -1;

 }
 
 int main()
 {
    struct Array arr={{2,3,3,3,4,4,5,6},10,8};
    int y=Binarysearch(arr,4);
    printf("index is %d\n",y);
    Display(arr);
    return 0;
 }