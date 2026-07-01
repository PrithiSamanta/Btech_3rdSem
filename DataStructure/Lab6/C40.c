#include <stdio.h>
struct Student{
    int rollno;
    char branch[50];
    char name[50];
    int batch_no;
};
int main(){
    struct Student s1;
    struct Student *ptr=&s1;
    printf("Enter roll_no branch name and batch_no : ");
    scanf("%d %s %s %d",&ptr->rollno,ptr->branch,ptr->name,&ptr->batch_no);
    printf("%d %s %s %d",ptr->rollno,ptr->branch,ptr->name,ptr->batch_no);
    return 0;
}