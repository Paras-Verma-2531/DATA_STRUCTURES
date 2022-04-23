# include <stdio.h> 
void inputSize(int *size);
void inputElements(int Array[],int size);
void bubbleSort(int array[],int size);
void display(int array[],int size);
int main() {
    int size;
    inputSize(&size);
    int array[size];
    inputElements(array,size);
    bubbleSort(array,size);
    printf("array in sorted order is :\n");
    display(array,size);
    return 0 ;
}
void inputSize(int *size)
{
    int size1;
    printf("enter the size of array: ");
    scanf("%d",&size1);
    *size=size1;
}
void inputElements(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("enter the %d element: ",(i+1));
        scanf("%d",(array+i));
    }
}
void bubbleSort(int array[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(*(array +j)>*(array+j+1))
            {//sorting through pointers
                int t=*(array+j);
                *(array+j)=*(array+j+1);
                *(array+j+1)=t;
            }
        }
    }
}
void display(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",array[i]);
    }
}