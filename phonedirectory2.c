#include<stdio.h>
#include<string.h>
#include<conio.h>

struct contact

{
    char nam[50];
    char adres[50];
    long int m_no;
    char gendr[10];
    char m_id[100];

};
void Menu();
void Data();
void ARec();
void ListRec();
void ModRec();
void DelRec();
void SRec();

int exit();

int main()
    {
        Menu();

        return 0;
    }
    void Menu()
    {
        printf("\n\t\tWELCOME TO PHONE DIRECTORY");
        printf("\n\n\t\t     MENU  \t\n\n");
        printf("\t1.List Contacts\t2.Add New Contact\t3.Modify  \n");
        printf("\t4.Search\t5.Delete\t6.Exit\n\n");
        printf("\tEnter the choice:-");

        switch(getch())
        {
            case '1':ListRec();
            break;
            case '2':ARec();
            break;
            case '3':ModRec();
            break;
            case '4' :SRec();
            break;
            case '5' :DelRec();
            break;
            case '6' :exit();
            default: printf("\n  Enter 1 to 6 only.");
            getch();

        }

    }

    int exit()
    {
        Menu();
        return 0;

    }

    void ARec()
    {
        FILE *f;
        struct contact p;
        f=fopen("project","ab+");
        printf("\n  Name : ");
        Data(p.nam);
        printf("\nAddress: ");
        Data(p.adres);
        printf("\nMobile No.:" );
        scanf("%d",&p.m_no);
        printf("Gender:");
        Data(p.gendr);
        printf("\nE-mail:");
        Data(p.m_id);
        fwrite(&p,sizeof(p),1,f);
        fflush(stdin);
        printf("\nrecord saved");

    fclose(f);
    getch();
    Menu();

    }

    void ListRec()
    {

        struct contact p;
        FILE *f;
        f=fopen("project","rb");

        if(f==NULL)
        {
            printf("\n No contacts detected yet!:\n");
            exit();
        }
        while(fread(&p,sizeof(p),1,f)==1)
        {
            printf("\n\n\n  YOUR RECORD IS\n\n ");

            printf("\nName=%s\nAdess=%s\nMobile No=%ld\nGender=%s\nE-mail=%s",p.nam,p.adres,p.m_no,p.gendr,p.m_id);
            getch();


        }
        fclose(f);
        getch();
        Menu();
    }
    void  SRec()
    {
        struct contact p;

        FILE *f;
        char name[100];

        f=fopen("projct","rb");
        if(f==NULL)
        {
            printf("\n Error in opening\n");
            exit();

        }
        printf("\nEnter Name of Person to search\n");

        Data(name);
        while(fread(&p,sizeof(p),1,f)==1)
        {
            if(strcmp(p.nam,name)==00)
            {
                printf("\n\tDetail Information About %s",name);
                printf("\nName :%s\naddress:%s\nMobile No:%ld\nGender:%s\nE-mail:%s",p.nam,p.adres,p.m_no,p.gendr,p.m_id);

            }
            else
                printf("Not found");
        }
        fclose(f);
        getch();
        Menu();

    }

    void DelRec()
    {
        struct contact p;

        FILE *f,*ft;

                    int flag;
                    char name[100];
                    f=fopen("project","rb");
                    if(f==NULL)
                    printf("Contact data not yet added.");

            else
                {
                        ft=fopen("temp","wb+");
                        if(ft==NULL)
                        printf("file opening error");
                        Data(name);
                        fflush(stdin);
                        while(fread(&p,sizeof(p),1,f)==1)
                        {
                            if(strcmp(p.nam,name)!=0)
                               fwrite(&p,sizeof(p),1,ft);
                            if(strcmp(p.nam,name)==0);
                        flag=1;
                        }
                    fclose(f);
                    fclose(ft);
                    if(flag!=1)
                    {
                        printf("No Record To Delete.");
                        remove("temp.txt");
                    }
                    else
                    {

                        remove("project");
                        rename("temp.txt","project");
                        printf("Record Deleted");
                    }

                }
        getch();
        Menu();
   
    }
void ModRec()
{
    int c;
    FILE *f;
    int flag=0;

    struct contact p,s;

            char nam[50];
            f=fopen("project","rb+");
            if(f==NULL)
            {
               printf("No Contact added yet!\n");

               exit();

            }
            else
            {
              printf("Enter Name to modify:\n");
              Data(nam);
              while(fread(&p,sizeof(p),1,f)==1)
              {
                 if(strcmp(nam,p.nam)==0)
                 {
                    printf("\nName :");
                    Data(s.nam);
                    printf("\nAddess:");
                    Data(s.adres);
                    printf("\nPhone no");
                    scanf("%d",&s.m_no);
                    printf("\nGender:");
                    Data(s.gendr);
                    printf("\nE-mail");
                    Data(s.m_id);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;

                 }
                fflush(stdin);

              } 
              if(flag==1)

                        printf("\n  Your contact is modified");
                else
                        printf("\n Contact data not found");

                    fclose(f);

            }
            getch();
            Menu();
}
void Data(char *Name)
{
    int i=0,j;
    char ch,cha;

do
{
    ch=getch();
            if(ch!=8&&ch!=13)
            {
                *(Name+i)=ch;
                    putch(ch);
                    i++;

            }
            if(ch==8)
            {
                if(i>0)
                {
                    i--;
                }
                for(j=0;j<i;j++)
                {
                    cha=*(Name+j);
                    putch(cha);
                }
            }
} while (ch!=13);
*(Name+i)='\0';


}