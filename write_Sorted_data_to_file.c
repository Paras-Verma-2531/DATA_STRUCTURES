# include <stdio.h> 
int i=0,array[50];
void readfile(FILE *ptr);
void insertionSort();
void writeData(FILE *ptr);
int main() {
    FILE *ptr=fopen("elements_file.txt","r");
    readfile(ptr);
    insertionSort();
    FILE *ptr1=fopen("sorted_elements.txt","a");
    writeData(ptr1);
    fclose(ptr1);
    fclose(ptr);
    return 0 ;
}
void readfile(FILE *ptr)
{
    if(ptr==NULL){printf("file does not exixts\n");}
    while(!feof(ptr))
    {
        fscanf(ptr,"%d",&array[i]);i++;
    }
}
void insertionSort()
{ int key;int k;key=k=0;

    for(int j=1;j<i;j++)//start from 1 till n(size)
    {
        key=array[j];
        k=j-1;// set k as j-1;
        while(k>=0 && array[k]>key) // run till condition satisfies
        {
            array[k+1]=array[k];// move element to the right
            k=k-1;
        }array[k+1]=key;// insert the required data at k+1 position
    }
}
void writeData(FILE *ptr)
{ int j=0;
    while(j<i)
    {
       fprintf(ptr,"%d\n",array[j]);
       j++;
    }
}