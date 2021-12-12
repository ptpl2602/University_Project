#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Linh
typedef struct NgaySinh
{
    unsigned int ngay;
    unsigned int thang;
    unsigned int nam;
}NS;

//Nguyen
bool InputDate(NS &z)
{
    int ngaymax;
    if((z.ngay <=0 || z.ngay >31)||(z.thang <=0 || z.thang >12)||(z.nam <= 0)) 
    {
        return false;
    }else{
        switch(z.thang)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                ngaymax = 31;
                break;
            case 2:
                if((z.nam%4 == 0 && z.nam%100 !=0) || z.nam%400==0)
                    ngaymax = 29;
                else
                    ngaymax = 28;
                break;
            case 4: case 6: case 9: case 11:
                    ngaymax = 30;
                    break;          
    	}
    }
    if (z.ngay>ngaymax)
    	return false;
    else
    	return true;
}
//Linh
typedef struct SinhVien
{
	char mssv[11];
    char hoten[30];
    char lop[10];
    struct NgaySinh ns;
    char gt;
    float ktlt;
    float ctdl;
    float csdl;
    float dtb;
}SV;
//Van
struct Node
{
	SV data;
	Node *pNext; 
};
typedef struct Node NODE;
//Van
struct List
{
	Node *pHead;
	Node *pTail;
};
typedef struct List LIST;
//Van
void Initialize(LIST &L)
{
	L.pHead = NULL;
	L.pTail = NULL;
}
//Linh
int IsEmpty(LIST L)
{
	return L.pHead == NULL;
}
//Van
NODE *CreateNode(SV x)
{
	NODE *p = new NODE;
	if (p == NULL)
    {
        printf("Khong du bo nho cap phat !!!");
        return NULL;
    }	
	p->data = x;
	p->pNext = NULL;
	return p;
}
//Linh
void AddHead(LIST &L, NODE *p)
{
	if(L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}
//Van
void AddTail (LIST &L, NODE *p)
{
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
//Linh
void Input_Number(int &a)
{
    do
    {
        scanf("%d", &a);
        if(a<0)
            printf("Nhap sai Nhap lai: ");
    } while (a<0);
}
//Huy
bool Check_Name(char name[])
{
    for(int i = 0 ; i < strlen(name) - 1 ; i++)
    {
        if(name[i] >= '0' && name[i] <= '9')
            return false;
    }
    return true;
}
//Huy
void Standardized_Name(char name[])
{
    char str[30];
    int count = 0;
    
    int first = 0, last = strlen(name) - 1;

    while (first < last && name[first] == ' ')
        first ++;
    while (last > first && name[last] == ' ')
        last --;
    
    if(name[first] >= 'a' && name[first] <= 'z')
        name[first] -= 32;

    for(int i = first + 1 ; i <= last ; i++)
    {
        if(name[i] >= 'A' && name[i] <= 'Z')
            name[i]+=32;
    }

    for(int i = first  ; i <= last ; i++)
    {
        if(i+1<=last)
        {
            if(name[i] == name[i+1] && name[i] == ' ')
                continue;
            if(name[i] == ' ' && name[i+1] >= 'a' && name[i+1] <= 'z')
                name[i+1] -= 32;
        }
        str[count] = name[i];
        count++;
    }
    name = str;
}
//Huy
bool Check_ID(char id[])
{
    int length = strlen(id);
    if(length != 10)
    {
        return false;
    }
    for(int i=0 ; i<length-1 ; i++)
    {
        if(id[i] <'0' || id[i] >'9')
        {
            return false;
        }
    }
    return true;
}
//Huy
bool Check_Class(char lop[])        //vi du: 20DATA1 or 20data1
{
    for(int i=0 ; i<strlen(lop)-1 ; i++)
    {
        if(lop[i] >= 'a' && lop[i] <= 'z')
            lop[i] -= 32;
    }
    if(strlen(lop) != 7)
        return false;
    if(lop[0] < '0' || lop[0] > '9')
        return false;
    if(lop[1] < '0' || lop[1] > '9')
        return false;
    if(lop[6] < '0' || lop[6] > '9')
        return false;
    if(lop[2] < 'A' || lop[2] > 'Z')
        return false;
    if(lop[3] < 'A' || lop[3] > 'Z')
        return false;
    if(lop[4] < 'A' || lop[4] > 'Z')
        return false;
    if(lop[5] < 'A' || lop[5] > 'Z')
        return false;
    return true;
}
//Huy
bool Check_Mark(float mark)
{
    if(mark<0 || mark >10)
    {
        return false;
    }
    return true;
}
//Linh
void Input_One_Old_Student(SV &x)
{
    printf("\nMSSV: ");
    do
    {
        fflush(stdin);
        gets(x.mssv);
        if(!Check_ID(x.mssv))
            printf("MSSV vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_ID(x.mssv));

    printf("Ho va ten: ");
    do
    {
        fflush(stdin);
        gets(x.hoten);
        if(!Check_Name(x.hoten))
            printf("Ho ten vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_Name(x.hoten));
    Standardized_Name(x.hoten);

    printf("Gioi tinh (X-nu) | (Y-nam): ");
    do
    {
        fflush(stdin);
        x.gt = getc(stdin);
        if(x.gt == 'x' || x.gt == 'y')
            x.gt = x.gt - 32;
        
        if(x.gt != 'X' && x.gt != 'Y')
        {
            printf("Gioi tinh vua nhap khong hop le. Vui long nhap lai: ");
        }
    } while(x.gt != 'X' && x.gt != 'Y');
    
    printf ("Nhap ngay sinh:");
    do{
		printf("\n- Ngay: ");
        scanf("%u",&x.ns.ngay);
        printf("- Thang: ");
        scanf("%u",&x.ns.thang);
        printf("- Nam: ");
        scanf("%u",&x.ns.nam);
		if (InputDate(x.ns) == false)
			printf ("\nNhap sai! Nhap lai:");
	} while (InputDate(x.ns)== false);

    printf("Lop: ");
    do
    {
        fflush(stdin);
        gets(x.lop);
        if(!Check_Class(x.lop))
            printf("Lop vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_Class(x.lop));

    printf("Diem mon Ky Thuat Lap Trinh: ");
    do
    {
        scanf("%f", &x.ktlt);
        if(!Check_Mark(x.ktlt))
            printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_Mark(x.ktlt));    
    
    printf("Diem mon Cau Truc Du Lieu: ");
    do
    {
        scanf("%f", &x.ctdl);
        if(!Check_Mark(x.ctdl))
            printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_Mark(x.ctdl));    
    
    printf("Diem mon Co So Du Lieu: ");
    do
    {
        scanf("%f", &x.csdl);
        if(!Check_Mark(x.csdl))
            printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_Mark(x.csdl));    

    x.dtb = (x.ktlt + x.ctdl + x.csdl) / 3;
}
void Title1()
{
    printf("\nSTT |   MSSV   |\t   Ho va Ten  \t\t| GT |  Ngay sinh   |   Lop   | KTLT | CTDL | CSDL | TB\n");
}
void Title2()
{
    printf("\n   MSSV   |\t    Ho va Ten    \t   | GT |  Ngay sinh   |   Lop   | KTLT | CTDL | CSDL | TB\n");
}
//Linh & Huy
void Output_One_Old_Student(SV x)
{	
    if(x.ns.ngay > 0 && x.ns.ngay <= 9) 
	{
		if (x.ns.thang > 0 && x.ns.thang <= 9)
		{	
        	if(x.gt == 'X')
				printf("%10s %30s   Nu     0%u/0%u/%u   %9s   %.1f   %.1f    %.1f    %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.ktlt,x.ctdl,x.csdl,x.dtb);
    		if(x.gt == 'Y')
				printf("%10s %30s   Nam    0%u/0%u/%u   %9s   %.1f   %.1f    %.1f    %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.ktlt,x.ctdl,x.csdl,x.dtb);
		} 
		else 
		{	
        	if(x.gt == 'X')
				printf("%10s %30s   Nu     0%u/%u/%u   %9s   %.1f  %.1f    %.1f   %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.ktlt,x.ctdl,x.csdl,x.dtb);
    		if(x.gt == 'Y')
				printf("%10s %30s   Nam    0%u/%u/%u   %9s   %.1f  %.1f    %.1f   %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.ktlt,x.ctdl,x.csdl,x.dtb);
		} 
	} 
	
	else if(x.ns.ngay >= 10) 
	{
		if (x.ns.thang > 0 && x.ns.thang <= 9)
		{
			if(x.gt == 'X')
				printf("%10s %30s   Nu     %u/0%u/%u   %9s   %.1f   %.1f    %.1f    %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.ktlt,x.ctdl,x.csdl,x.dtb);
    		if(x.gt == 'Y')
				printf("%10s %30s   Nam    %u/0%u/%u   %9s   %.1f   %.1f    %.1f    %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.ktlt,x.ctdl,x.csdl,x.dtb);
		}
		else
		{
			if(x.gt == 'X')
				printf("%10s %30s   Nu     %u/%u/%u   %9s   %.1f   %.1f    %.1f    %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.ktlt,x.ctdl,x.csdl,x.dtb);
    		if(x.gt == 'Y')
				printf("%10s %30s   Nam    %u/%u/%u   %9s   %.1f   %.1f    %.1f    %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.ktlt,x.ctdl,x.csdl,x.dtb);
		}	
	} 
}
//Huy
void EmptyList(LIST &L)
{
    int n;
    printf("Nhap so luong sinh vien: ");
    Input_Number(n);
    for(int i=0 ; i<n ; i++)
    {
	    SV x;
	    printf("\n-----Nhap thong tin sinh vien thu %d: -----", i+1);
	    Input_One_Old_Student(x);
	    NODE *p = CreateNode(x);
	    AddTail(L, p);
	}
    system("pause");
}
//Van
void Output_List_Old_Student(LIST L)
{
    int i=1;
	Title1();
	for(NODE *k = L.pHead; k != NULL; k = k->pNext)
	{
		printf("%3d  ",i);
		Output_One_Old_Student(k->data);
        i++;
	}
}
//Van
void FindInfoByID(LIST L)
{
	char ID[11];
	printf("MSSV can tim: ");
    fflush(stdin);
    gets(ID);
	
    bool flag = false;
	Title2();
    for(NODE* i = L.pHead ; i != NULL ; i = i->pNext)
    {
        if(strstr(i->data.mssv,ID))
        {
            Output_One_Old_Student(i->data);
            flag = true;
        }
    }
    if(flag == false)
        printf("Khong tim thay MSSV: %s trong danh sach \n",ID);
}
//Van
void Output_List_Student_Technology(LIST L)
{
    bool flag = false;
    Title2();
    for(NODE* i = L.pHead ; i != NULL ; i = i->pNext)
    {
        if(strstr(i->data.lop,"DTH"))
        {
            Output_One_Old_Student(i->data);
            flag = true;
        }
    }
    if(flag == false)
        printf("\nDanh sach khong co sinh vien thuoc nganh CNTT\n");
}
//Van
void Output_List_Student_CSC(LIST L)
{
    bool flag = false;
    Title2();
    for(NODE* i = L.pHead ; i != NULL ; i = i->pNext)
    {
        if(strstr(i->data.lop,"DATA"))
        {
            Output_One_Old_Student(i->data);
            flag = true;
        }
    }
    if(flag == false)
        printf("\nDanh sach khong co sinh vien thuoc nganh ATTT\n");
}
//Linh
void Search_Month(LIST L)
{
    unsigned int month;
    int flag =0;
    printf("Nhap thang sinh: ");
    scanf("%u", &month);

    Title2();
    for(NODE *i = L.pHead ; i != NULL ; i = i->pNext)
    {
        if(i->data.ns.thang == month)
        {
            Output_One_Old_Student(i->data);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nKhong tim thay sinh vien co ngay sinh vao thang %u \n",month);
    }
}
//Linh
int CountNode(LIST L)
{
    int num = 0;
    for(NODE *k = L.pHead ; k != NULL ; k = k->pNext)
    {
        num++;
    }
    return num;
}
//Linh
int Position(LIST L)
{
    int vt , num = CountNode(L);
    printf("\nNhap vi tri can them: ");
    do
    {
        scanf("%d",&vt);
        if(vt < 0 || vt > num + 1)
            printf("Vi tri khong hop le. Vui long nhap lai: ");
    } while (vt < 0 || vt > num + 1);
    return vt;    
}
//Linh
void AddStudent(LIST &L, SV data)
{
    int vt = Position(L) , num = CountNode(L);
    
    if(vt == 1)
    {
        NODE *g = CreateNode(data);
        AddHead(L, g);
    }
    else if(vt == num + 1)
    {
        NODE *g = CreateNode(data);
        AddTail(L, g);
    }
    else
    {
        NODE *g = new NODE;
        for(NODE *i = L.pHead ; i != NULL ; i = i->pNext)
        {
            vt--;
            if(vt == 0)
            {
                NODE *q = CreateNode(data);
                q->pNext = i;
                g->pNext = q;
            }
            g = i;
        }     
    }
}
//Nguyen
void DeleteHead(LIST &L)
{
    NODE *p;
    if(L.pHead == NULL)
    {
        return;
    }
    p = L.pHead;
    L.pHead = L.pHead -> pNext;
    delete p;
}
//Nguyen
void DeleteTail(LIST &L)
{
    NODE *p;
    if(L.pHead == NULL)
    {
        return;
    }
    for(NODE *k = L.pHead ; k != NULL ; k = k->pNext)
    {
        if(k->pNext == L.pTail)
        {
            delete L.pTail;
            k->pNext = NULL;
            L.pTail = k;
            return;
        }
    }
}
//Nguyen
void DeleteMSSV(LIST &L)
{
    char mssv[11];
    printf("Nhap MSSV can xoa: ");
    fflush(stdin);
    gets(mssv);
    bool flag = false;

    if(strcmp(L.pHead->data.mssv , mssv) == 0)
    {
        flag = true;
        DeleteHead(L);
        return;
    }
    else if(strcmp(L.pTail->data.mssv , mssv) == 0)
    {
        flag = true;
        DeleteTail(L);
        return;
    }
    else
    {
        NODE *g = new NODE;
        for(NODE *k = L.pHead;k != NULL;k = k -> pNext)
        {
            if(strcmp(k->data.mssv , mssv) == 0)
            {
                g->pNext = k->pNext;
                delete k;
                flag = true;
                return;
            }
            g = k;
        }
    }
    if(!flag)
    {
        printf("Khong co sinh vien can xoa!!\n");
    }
}
//Huy
void SWAP(SV &a, SV &b)
{
    SV temp = a;
    a = b;
    b = temp;
}
//Huy
void Get_Name(char fullname[] , char name[])
{
    for(int i = strlen(fullname) - 1 ; i >= 0 ; i--)
	{
		if(fullname[i] == ' ')
		{
			strcpy(name , fullname + 1 + i );
			break;
		}
	}
}
//Huy
void Sort_Name(LIST &L)
{
    for(NODE *i = L.pHead ; i != NULL ; i = i->pNext)
    {
        char name1[30] = "";
        Get_Name( i->data.hoten , name1 );

        for(NODE *j = L.pHead ; j != NULL ; j = j->pNext)
        {
            char name2[30] = "";
			Get_Name( j->data.hoten , name2 );

			if( strcmp( name1 , name2 ) < 0 )
			{
				SWAP(i->data , j->data);
			}

			else if( strcmp( name1 , name2 ) == 0 )
			{
				if( strcmp( i->data.hoten , j->data.hoten ) < 0 )
				{
					SWAP(i->data , j->data);
				}
			}

            Get_Name( i->data.hoten , name1 );
        }
    }
}
//Nguyen
void SortDTB(LIST &L)
{
    for(NODE *a = L.pHead;a != NULL;a = a -> pNext)
    {
        for(NODE *b = a -> pNext;b != NULL;b = b ->pNext)
        {
            if(a->data.dtb > b->data.dtb)
            {
                SWAP(a->data,b->data);
            }
        }
    }
}
//Huy
float MaxOfKTLT(LIST L)
{
    float max = L.pHead->data.ktlt;
    for(NODE *k = L.pHead->pNext ; k != NULL ; k = k->pNext)
    {
        if(k->data.ktlt > max)
            max = k->data.ktlt;
    }
    return max;
}
//Huy
float MaxOfCSDL(LIST L)
{
    float max = L.pHead->data.csdl;
    for(NODE *k = L.pHead->pNext ; k != NULL ; k = k->pNext)
    {
        if(k->data.csdl > max)
            max = k->data.csdl;
    }
    return max;
}
//Huy
float MaxOfCTDL(LIST L)
{
    float max = L.pHead->data.ctdl;
    for(NODE *k = L.pHead->pNext ; k != NULL ; k = k->pNext)
    {
        if(k->data.ctdl > max)
            max = k->data.ctdl;
    }
    return max;
}
//Huy
void MAX(LIST L)
{
    float maxKTLT = MaxOfKTLT(L) , maxCSDL = MaxOfCSDL(L) , maxCTDL = MaxOfCTDL(L);
    printf("\nSinh vien co diem mon KTLT cao nhat ");
    Title2();
    for(NODE *k = L.pHead ; k != NULL ; k = k->pNext)
    {
        if(k->data.ktlt == maxKTLT)
        {
            Output_One_Old_Student(k->data);
        }
    }
    printf("\nSinh vien co diem mon CSDL cao nhat ");
    Title2();
    for(NODE *k = L.pHead ; k != NULL ; k = k->pNext)
    {
        if(k->data.csdl == maxCSDL)
        {
            Output_One_Old_Student(k->data);
        }
    }
    printf("\nSinh vien co diem mon CTDL cao nhat ");
    Title2();
    for(NODE *k = L.pHead ; k != NULL ; k = k->pNext)
    {
        if(k->data.ctdl == maxCTDL)
        {
            Output_One_Old_Student(k->data);
        }
    }
}
//Huy
void GhiFile(char filename[] , SV a)
{
    FILE *f;
	f = fopen(filename , "a");
	if(f == NULL)
	{
		printf("Khong mo dc file lay gi ghi\n");
		exit(0);
	}

    fprintf( f , "\n%s\n%s\n%s\n%d %d %d\n"
    ,a.mssv , a.hoten , a.lop , a.ns.ngay , a.ns.thang , a.ns.nam );

    if(a.gt == 'X')
        fprintf(f , "%s\n" , "Nu");
    else if(a.gt == 'Y')
        fprintf(f , "%s\n" , "Nam");

    fprintf(f , "%.1f\n%.1f\n%.1f\n%.1f\n", a.ktlt , a.ctdl , a.csdl , a.dtb );

    fclose(f);
}
//Huy
void DocFile(char filename[] , LIST &L)
{
    FILE *f;
    f = fopen(filename , "r");
	if(!f)
	{
		printf("Khong mo dc file lay gi ghi\n");
		exit(0);
	}
    while (!feof(f))
    {
        SV a;
        char t[5];

        fscanf(f , "%s" , &a.mssv);

        fgets(t , 5 , f);
        fgets(a.hoten , 30 , f);
        a.hoten[strlen(a.hoten) - 1] = '\0';

        fscanf(f , "%s" , &a.lop);
        fscanf(f,"%u%u%u",&a.ns.ngay,&a.ns.thang,&a.ns.nam);

        char gt[4];
        fscanf(f , "%s" , &gt);

        if(strcmp(gt,"Nam")==0)
            a.gt = 'Y';
        else if(strcmp(gt,"Nu")==0)
            a.gt = 'X';
    
        fscanf(f , "%f%f%f%f" ,&a.ktlt,&a.ctdl,&a.csdl,&a.dtb);

        NODE *p = CreateNode(a);
        AddTail(L,p);
    }
    fclose(f);
}
//Huy
void SaveData(FILE* f, LIST L)
{
    NODE* p = L.pHead;
    while (p)
    {
        fprintf( f , "\n%s\n%s\n%s\n%d %d %d\n"
        ,p->data.mssv, p->data.hoten, p->data.lop, p->data.ns.ngay, p->data.ns.thang, p->data.ns.nam);

        if(p->data.gt == 'X')
            fprintf(f , "%s\n" , "Nu");
        else if(p->data.gt == 'Y')
            fprintf(f , "%s\n" , "Nam");

        fprintf(f, "%.1f\n%.1f\n%.1f\n%.1f\n", p->data.ktlt, p->data.ctdl, p->data.csdl, p->data.dtb);

        p = p->pNext;
    }
}
//Linh & Huy & Van & Nguyen
void Menu(LIST &L, char filename[])
{
    while (true)
    {	
        system("cls");
        printf("\n\t\t-------------------------MENU-------------------------\n");
        printf("\t\t\t1.  Tao Danh Sach Sinh Vien\n");
        printf("\t\t\t2.  Xuat Danh Sach Sinh Vien\n");
        printf("\t\t\t3.  Tim Sinh Vien Theo MSSV\n");
        printf("\t\t\t4.  Tim Sinh Vien Nganh\n");
        printf("\t\t\t5.  Tim Sinh Vien Theo Thang Sinh\n");
        printf("\t\t\t6.  Them Sinh Vien Vao Danh Sach\n");
        printf("\t\t\t7.  Xoa Sinh Vien Theo MSSV\n");
        printf("\t\t\t8.  Sap Xep Sinh Vien Theo Ten\n");
        printf("\t\t\t9.  Sap Xep Sinh Vien Theo DTB\n");
        printf("\t\t\t10. Xuat Sinh Vien Cao Diem Nhat Moi Mon\n");
        printf("\t\t\t0.  Luu du lieu va Thoat.\n");
        printf("\t\t------------------------------------------------------\n");

        int chon;
        printf("\nNhap lua chon: ");
        scanf("%d",&chon);

        if(chon == 0)
            break;

        switch (chon)
        {
        	case 1:         //Tao danh sach sinh vien
            {
                EmptyList(L);
            }
            break;
            
            case 2:         //Xuat danh sach sinh vien
            {
                Output_List_Old_Student(L);
                system("pause");                
            }
            break;

            case 3:     //tim sv theo mssv
            {
                FindInfoByID(L);
                system("pause");
            }
            break;

            case 4:
            {
                printf ("\n\t\t1.Tim sinh vien theo nganh CNTT");
            	printf ("\n\t\t2.Tim sinh vien theo nganh ATTT");
            	int cull;
            	printf ("\nMoi nhap cong viec: ");
            	scanf ("%d", &cull);
            	if (cull == 1)
				{
            		Output_List_Student_Technology(L);
				}
                else if(cull == 2)
				{
					Output_List_Student_CSC(L);
				}
                else
                {
					printf ("\nLua chon khong hop le!");					
				}
                system("pause");
            }
            break;
            
            case 5:     //Tim sinh vien theo thang sinh
            {
                Search_Month(L);
                system("pause");
            }
            break;

            case 6:      //Them sinh vien vao danh sach
            {
                SV x;                    
                printf("\n---- Nhap sinh vien can them ----");
                Input_One_Old_Student(x);
                AddStudent(L, x);
                printf("\nDanh sach sau khi them sinh vien co dang");
                Output_List_Old_Student(L);
                GhiFile(filename,x);
                system("pause");
            }
            break;

            case 7:     //Xoa sinh vien theo MSSV
            {
                DeleteMSSV(L);
                printf("Danh sach sinh vien sau khi xoa ");
                Output_List_Old_Student(L);
                system("pause");
            }
            break;

            case 8:     //Sap xep theo ten
            {              
                Sort_Name(L);
                printf("Danh sach sinh vien sau khi sap xep theo ten co dang");
                Output_List_Old_Student(L);
                system("pause");                
            }
            break;    

            case 9:     //Sap xep theo DTB
            {
                SortDTB(L);
                printf("Danh sach sinh vien sau khi sap xep theo DTB ");
                Output_List_Old_Student(L);
                system("pause");
            }
            break;

            case 10:
            {
                MAX(L);
                system("pause");
            }
            break;
            
        	default:
            	printf("\nLua chon khong hop le. Vui long nhap lai\n");
            	system("pause");
            break;
    	}
	}	
}

int main()
{
    LIST L;
    Initialize(L);
    char filename[] = "DATA_SV.txt";
    DocFile(filename,L);

    Menu(L,filename);

    FILE *f;
    f = fopen(filename,"w+");
    if(!f)
        printf("Khong mo duoc file\n");
    SaveData(f,L);
    fclose(f);
    return 0;
}