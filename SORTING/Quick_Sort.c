# include <stdio.h> 
int Partition(int Array[],int initial,int final);
void Quicksort(int Array[],int intial,int final);
void inputSize(int *size);
void swap(int Array[],int pos1,int pos2);
void inputElements(int Array[],int size);
void printArray(int array[],int size);
int main() {
    int size=0;
    inputSize(&size);
    int Array[size];
    inputElements(Array,size);
    QuickSort(Array,0,size-1);
    printArray(Array,size);
    return 0 ;
}
void inputSize(int *size)
{
    int size1;
    printf("enter the size of Array: ");
    scanf("%d",&size1);
    *size=size1;
}
void inputElements(int Array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("enter the %d element: ",(i+1));
        scanf("%d",&Array[i]);
    }
}
int Partition(int Array[],int initial,int final)
{
    int pivot=Array[final];
    int i=initial-1;
    for(int j=initial;j<=final-1;j++)
    {
        if(Array[j]<pivot)
        {
            i++;
            swap(Array,i,j);
        }
    }
    swap(Array,i+1,final);
    return i+1;
}
void QuickSort(int Array[],int initial,int final)
{
    if(initial<final)
    {
      int pivot=Partition(Array,initial,final);
      QuickSort(Array,initial,pivot-1);
      QuickSort(Array,pivot+1,final);
    }
}
void swap(int Array[],int pos1,int pos2)
{
    int t=Array[pos1];
    Array[pos1]=Array[pos2];
    Array[pos2]=t;
}
void printArray(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",array[i]);
    }
}