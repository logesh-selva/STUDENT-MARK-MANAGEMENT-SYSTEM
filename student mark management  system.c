#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int rno;
    char name[20];
    struct subject
    {
        int scode;
        char sname[20];
        int mark;
    }sub[3];
    int total;
    float avg;
}student;
void create();
void append();
void display();
void search();
void no_of_rec();
void update();
void delete_rec();
void sort_by_value();
void sort_by_value_per();
void sort_by_name() ;
int main()
{
    printf("**********STUDENT MARK MANAGEMENT SYSTEM WITH FILES BY SPARTAZ TEAM**********");
    int ch;
    do
    {
        printf("\n1 . CREATE\n2 . DISPLAY\n3 . APPEND\n4 . NO OF RECORDS\n5 . SEARCH\n6 . UPDATE\n7 . DELETE\n");
        printf("8 . SORT BY VALUE\n");
        printf("9 . SORT BY VALUE PERMANANTLY\n");
        printf("10 . SORT BY NAME\n");
        printf("0 . EXIT\n");
        printf("ENTER YOUR OPTION : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();//for displaying the values
            break;
        case 3:
            append();
            break;
        case 4:
            no_of_rec();
            break;
        case 5:
            search();
            break;
        case 6:
            update();
            break;
        case 7:
            delete_rec();
            break;
        case 8:
            sort_by_value();
            break;
        case 9:
            sort_by_value_per();
            break;
        case 10:
            sort_by_name();
            break;
        }
    }while(ch!=0);
    return 0;
}
//file writing function in c programing
void create(){
    struct student *s;
    printf("Enter How many students you want : ");
    // n is number of student
    int n,i,j;
    //creating file pointer (fp)
    FILE * fp;
    scanf("%d",&n);
    // allocating memory to s
    s = calloc (n,sizeof(student));
    // file pointer assaingD:\zoho preparation\files\c programing\student.txt file in(write) mode
    fp = fopen("student.txt","w");// fopen(file name,file mode)
    for(int i=0;i<n;i++){
            //intial total and avrage is 0
            s[i].total=0;
            s[i].avg=0;
            //geting roll num
            printf("Enter Rollnum : ");
            scanf("%d",&s[i]);
            fflush(stdin);
            printf("Enter Name    : ");
            scanf("%[^\n]",s[i].name);
            for(int j=0;j<3;j++)
            {
            printf("Enter Mark Optained Subject %d: ",j+1);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
            }

            s[i].avg=s[i].total/3.0;
            fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}
void display(){
    //creating  student object
    struct student s1;
    FILE * fp;
    fp =  fopen ("student.txt","r");
    while(fread(&s1,sizeof(student),1,fp))
    {
        printf ("\n%-5d%-20s",s1.rno,s1.name);
        for(int j=0;j<3;j++)
        {
            printf("%4d",s1.sub[j].mark);
        }
        printf("%5d%7.2f",s1.total,s1.avg);
    }
    fclose(fp);
}
void append() {


       struct student *s;
    printf("Enter How many students you want To append: ");
    // n is number of student
    int n,i,j;
    //creating file pointer (fp)
    FILE * fp;
    scanf("%d",&n);
    // allocating memory to s
    s = calloc (n,sizeof(student));
    // file pointer assaingD:\zoho preparation\files\c programing\student.txt file in(write) mode
    fp = fopen("student.txt","a");// fopen(file name,file mode)
    for(int i=0;i<n;i++){
            //intial total and avrage is 0
            s[i].total=0;
            s[i].avg=0;
            //geting roll num
            printf("Enter Rollnum : ");
            scanf("%d",&s[i]);
            fflush(stdin);
            printf("Enter Name : ");
            scanf("%[^\n]",s[i].name);
            for(int j=0;j<3;j++)
            {
            printf("Enter Mark Optained Subject %d: ",j+1);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
            }

            s[i].avg=s[i].total/3.0;
            fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}
void no_of_rec(){
    struct  student s1;
    FILE * fp;
    fp = fopen("student.txt","r");
    fseek(fp,0,SEEK_END);                   //fseek used to move the curser into selected part
    int n = ftell(fp)/sizeof(student);      //ftell used to tell curser pointer
    printf("\nNumeber of records %d \n",n);

}
void search(){
    system("cls");
    struct student s1;
    FILE * fp;
    fp =  fopen ("student.txt","r");
    int rno;
    printf("\nEnter a rollnumber to search : ");
    scanf("%d",&
          rno);
    int found =0;
    while(fread(&s1,sizeof(student),1,fp))
    {
    if(s1.rno == rno)
    {
        found = 1;
        printf ("\n%-5d%-20s",s1.rno,s1.name);
        for(int j=0;j<3;j++)
        {
            printf("%4d",s1.sub[j].mark);
        }
        printf("%5d%7.2f\n",s1.total,s1.avg);
    }

    }
    if(!found)
    {
        printf("\nRecord Not found\n");
    }
    fclose(fp);
}
void update(){
    system("cls");
    struct student s1;
    FILE * fp,*fp1;
    fp =  fopen ("student.txt","r");
    fp1 = fopen ("temp.txt","w");
    int rno;
    printf("\nEnter a rollnumber to update : ");
    scanf("%d",& rno);
    int found =0;
    while(fread(&s1,sizeof(student),1,fp))
    {
    if(s1.rno == rno)
    {
        found = 1;
        s1.total=0;
        s1.avg=0;
        fflush(stdin);
        //geting roll num
        printf("Enter Name : ");
        scanf("%[^\n]",s1.name);
        for(int j=0;j<3;j++)
        {
        printf("Enter Mark Optained Subject %d: ",j+1);
        scanf("%d",&s1.sub[j].mark);
        s1.total += s1.sub[j].mark;
        }
        s1.avg=s1.total/3.0;

    }
     fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found)
    {
        fp = fopen("student.txt","w");
        fp1 = fopen("temp.txt","r");
        while(fread(&s1,sizeof(student),1,fp1))
        {
            fwrite(&s1,sizeof(student),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        printf("\nRecord Not found\n");
    }
    fclose(fp);
}
void delete_rec(){
    system("cls");
    struct student s1;
    FILE * fp,*fp1;
    fp =  fopen ("student.txt","r");
    fp1 = fopen ("temp.txt","w");
    int rno;
    printf("\nEnter a rollnumber to delate : ");
    scanf("%d",& rno);
    int found =0;
    while(fread(&s1,sizeof(student),1,fp))
    {
    if(s1.rno == rno)
    {
        found = 1;
    }
    else
    fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found)
    {
        fp = fopen("student.txt","w");
        fp1 = fopen("temp.txt","r");
        while(fread(&s1,sizeof(student),1,fp1))
        {
            fwrite(&s1,sizeof(student),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        printf("\nRecord Not found\n");
    }
    fclose(fp);
}
void sort_by_value(){
    struct student s1,*s;
    FILE * fp;
    fp = fopen ("student.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (struct student * ) calloc (n,sizeof(student));
    rewind(fp);
    for(int i=0;i<n;i++){
        fread(&s[i],sizeof(student),1,fp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i].total > s[j].total){
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    for (int i =0 ;i<n;i++){
        printf ("\n%-5d%-20s",s[i].rno,s[i].name);
        for(int j=0;j<3;j++)
        {
        printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].avg);
    }
    fclose(fp);
}
void sort_by_value_per(){
    struct student s1,*s;
    FILE * fp;
    fp = fopen ("student.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (struct student * ) calloc (n,sizeof(student));
    rewind(fp);

    for(int i=0;i<n;i++){
        fread(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i].total > s[j].total){
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    fp = fopen("student.txt","w");
    for (int i =0 ;i<n;i++){
        printf ("\n%-5d%-20s",s[i].rno,s[i].name);
        for(int j=0;j<3;j++)
        {
        printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].avg);
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}
void sort_by_name(){
    struct student s1,*s;
    FILE * fp;
    fp = fopen ("student.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (struct student * ) calloc (n,sizeof(student));
    rewind(fp);
    for(int i=0;i<n;i++){
        fread(&s[i],sizeof(student),1,fp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(strcmp(s[i].name,s[j].name)<0){
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    system("cls");
    for (int i =0 ;i<n;i++){
        printf ("\n%-5d%-20s",s[i].rno,s[i].name);
        for(int j=0;j<3;j++)
        {
        printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].avg);
        }
    fclose(fp);
}
