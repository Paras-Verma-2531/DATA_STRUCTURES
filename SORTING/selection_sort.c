# include <stdio.h> 
void inputSize(int *size);
void inputElements(int array[],int size);
void selectionSort(int array[],int size);
void display(int array[],int size);
int main() {
     int size;
     inputSize(&size);
     int array[size];
     inputElements(array,size);
     selectionSort(array,size);
     printf("array in sorted manner is :\n");
     display(array,size);
     return 0 ;
}
void inputSize(int *size)
{
    int size1;
    printf("enter the size of array:");
    scanf("%d",&size1);
    *size=size1;
}
void inputElements(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("enter the %d element: ",(i+1));
        scanf("%d",&array[i]);
    }
}
void selectionSort(int array[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(array[min]>array[j]){min=j;}
        }//swapping of elements
        int t=array[i];
        array[i]=array[min];
        array[min]=t;
    }
}
void display(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",array[i]);
    }
}