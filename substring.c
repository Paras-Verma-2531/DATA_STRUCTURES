# include <stdio.h> 
# include <string.h> 
void inputString(char *string1,char *string2);
void checkSubString(char *string1,char *string2);
int main() {
    char string_1[20];char string_2[50];
    char *string1=string_1;char *string2=string_2;
    inputString(string1,string2);
    checkSubString(string1,string2);
    return 0 ;
}
void inputString(char *string1,char *string2)
{
    printf("enter the main string: ");
    fflush(stdin);
    gets(string1);
    printf("enter the substring : ");
    fflush(stdin);
    gets(string2);
}
void checkSubString(char *string1,char *string2)
{
    int k=strlen(string2);int length=strlen(string1);
    int p=k;char tempString[3];int temp=0;
    for(int i=0;i<=length-k;i++)
    {
        for(int j=i;j<p;j++)
        {
          tempString[temp]=*(string1+j);temp++;
        }char *temp_string=tempString;
        *(temp_string+temp)='\0';temp=0;p++;
        int comp=strcmp(temp_string,string2);
        if(!comp){printf("the substring %s exists in %s ",string2,string1);break;}
    }
}