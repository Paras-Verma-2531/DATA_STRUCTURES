# include <stdio.h> 
void inputSize(int *size);
void inputElements(int size,int array[]);
void mergeSort(int array[],int initial,int final);
void merge(int array[],int initial,int mid,int final);
void printArray(int array[],int size);
int main() {
    int size=0;
    inputSize(&size);
    int array[size];
    inputElements(size,array);
    mergeSort(array,0,size-1);
    printf("the sorted array is :\n");
    printArray(array,size);
    return 0 ;
}
void inputSize(int *size)
{int size1;
    printf("enter the size of array: ");
    scanf("%d",&size1);
    *size=size1;
}
void inputElements(int size,int array[])
{
    for(int i=0;i<size;i++)
    {
        printf("enter the %d element : ",(i+1));
        scanf("%d",&array[i]);
    }
}
void mergeSort(int array[],int initial,int final)
{
    if(initial<final)
    {
        int mid=(initial+final)/2;
        mergeSort(array,initial,mid);// recursive call for division of first part(<mid)
        mergeSort(array,mid+1,final);// recursive call for division of second part(>mid)
        merge(array,initial,mid,final);// will merge according to the sorted sequence
    }
}
void merge(int array[],int initial,int mid,int final)
{
   int size1=mid-initial+1;// size of first array
   int size2=final-mid;// size of second array
   int array1[size1];int array2[size2];
   for(int i=0;i<size1;i++)
   {
       array1[i]=array[initial+i];//copy elements in first array till (mid)
   }
   for(int i=0;i<size2;i++)
   {
       array2[i]=array[mid+1+i];//copy elements in second array from (mid+1)
   }
   int pointer1=0,pointer2=0;int pos=initial;
   while(pointer1<size1&&pointer2<size2)
   {
       if(array1[pointer1]<=array2[pointer2]){array[pos]=array1[pointer1];pointer1++;}
       else
       {
           array[pos]=array2[pointer2];
           pointer2++;
        }pos++;
   }
   while(pointer1<size1)
   {
       array[pos]=array1[pointer1];
       pointer1++;pos++;
   }
   while(pointer2<size2)
   {
       array[pos]=array2[pointer2];
      pointer2++;pos++;
   }
}
void printArray(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",array[i]);
    }
}
