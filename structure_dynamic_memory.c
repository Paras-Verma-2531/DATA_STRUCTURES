#include <stdio.h>
#include <stdlib.h>
struct student
{
    char subject_name[20];
    int subject_code;
};
int main()
{

    struct student *st1;
    int n;
    printf("enter the number of students\n");
    scanf("%d", &n);

    st1 = (struct student *)malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++)
    {
        printf("enter the subject  name of %d student\n", (i + 1));
        scanf("%s", (st1 + i)->subject_name);
        printf("enter the subject code\n");
        scanf("%d", &(st1 + i)->subject_code);
    }

    printf("if you want to add more number, press '1' else press any character\n");
    int ch;

    scanf("%d", &ch);
    if (ch ==1)
    {
        printf("enter the further size\n");
        int new_size;
        scanf("%d", &new_size);
        // struct student *st2;
        st1 = (struct student *)realloc((n + new_size), sizeof(struct student));
        for (int i = n; i < (n + new_size); i++)
        {
            printf("enter the subject name of %d subject\n", (n + 1));
            scanf("%s",(st1+n)->subject_name);
            printf("enter  the subject  code\n");
            scanf("%d", &(st1+n)->subject_code);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("the details of %d students is: \n", (i + 1));
            printf("the subject code is : %s\n", (st1 + i)->subject_name);
            printf("the subject code is : %d\n", (st1 + i)->subject_code);
        }
    }

    return 0;
}