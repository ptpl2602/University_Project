#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 100
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
    if((z.ngay <= 0 || z.ngay > 31) || (z.thang <= 0 || z.thang > 12) || (z.nam <= 0)) 
    {
        return false;
    }
    else
    {
        switch(z.thang)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    ngaymax = 31;
                break;
            case 2:
                if((z.nam % 4 == 0 && z.nam % 100 !=0) || z.nam % 400 == 0)
                    ngaymax = 29;
                else
                    ngaymax = 28;
                break;
            case 4: case 6: case 9: case 11:
                    ngaymax = 30;
                break;
    	}
    }
    if (z.ngay > ngaymax)
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
    float toan;
    float ly;
    float hoa;
    float dtb;
}SV;
//Huy
struct LIST
{
    int num;
    SV a[MAX];
};
//Huy
void numList(LIST &L)
{
    L.num = 0;
}
//Huy
int ListSize(LIST L)
{
    return L.num;
}
//Huy
bool IsEmpty(LIST L)
{
    return (L.num == 0);
}
//Huy
bool IsFull(LIST L)
{
    return (L.num == MAX);
}
//Huy
void NhapSo(int &a)
{
    do
    {
        scanf("%d", &a);
        if(a<0 || a>100)
            printf("Nhap sai Nhap lai: ");
    } while (a<0 || a>100);
    
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
bool Check_Class(char lop[])
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
		if (InputDate(x.ns)== false)
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

    printf("Diem mon Toan: ");
    do
    {
        scanf("%f", &x.toan);
        if(!Check_Mark(x.toan))
            printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_Mark(x.toan));    
    
    printf("Diem mon Ly: ");
    do
    {
        scanf("%f", &x.ly);
        if(!Check_Mark(x.ly))
            printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_Mark(x.ly));    
    
    printf("Diem mon Hoa: ");
    do
    {
        scanf("%f", &x.hoa);
        if(!Check_Mark(x.hoa))
            printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
    } while (!Check_Mark(x.hoa));    

    x.dtb = (x.toan + x.ly + x.hoa) / 3;
}
//Huy
void Output_One_Old_Student(SV x)
{	
    if(x.ns.ngay > 0 && x.ns.ngay <= 9) 
	{
		if (x.ns.thang > 0 && x.ns.thang <= 9)
		{	
            if(x.gt == 'X')
				printf("%10s %30s   Nu     0%u/0%u/%u   %9s    %.1f  %.1f   %.1f  %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.toan,x.ly,x.hoa,x.dtb);
            if(x.gt == 'Y')
				printf("%10s %30s   Nam    0%u/0%u/%u   %9s    %.1f  %.1f   %.1f  %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.toan,x.ly,x.hoa,x.dtb);
		} 
		else 
		{	
            if(x.gt == 'X')
				printf("%10s %30s   Nu     0%u/%u/%u   %9s    %.1f  %.1f   %.1f  %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.toan,x.ly,x.hoa,x.dtb);
            if(x.gt == 'Y')
				printf("%10s %30s   Nam    0%u/%u/%u   %9s    %.1f  %.1f   %.1f  %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.toan,x.ly,x.hoa,x.dtb);
		} 
	} 
	
	else if(x.ns.ngay >= 10) 
	{
		if (x.ns.thang > 0 && x.ns.thang <= 9)
		{
			if(x.gt == 'X')
				printf("%10s %30s   Nu     %u/0%u/%u   %9s    %.1f  %.1f   %.1f  %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.toan,x.ly,x.hoa,x.dtb);
            if(x.gt == 'Y')
				printf("%10s %30s   Nam    %u/0%u/%u   %9s    %.1f  %.1f   %.1f  %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.toan,x.ly,x.hoa,x.dtb);
		}
		else
		{
			if(x.gt == 'X')
				printf("%10s %30s   Nu     %u/%u/%u   %9s    %.1f  %.1f   %.1f  %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.toan,x.ly,x.hoa,x.dtb);
            if(x.gt == 'Y')
				printf("%10s %30s   Nam    %u/%u/%u   %9s    %.1f  %.1f   %.1f  %.1f\n",x.mssv,x.hoten,x.ns.ngay,x.ns.thang,x.ns.nam,x.lop,x.toan,x.ly,x.hoa,x.dtb);
		}	
	} 
}
//Linh
void Input_List_Old_Student(LIST &L)
{
    for(int i=0; i<L.num; i++)
    {
        printf("\n-------Nhap sinh vien thu %d-------", i+1);
        Input_One_Old_Student(L.a[i]);
    }
}
//Huy
void Title1()
{
    printf("\nSTT |   MSSV   |\t   Ho va Ten  \t\t| GT |  Ngay sinh   |   Lop   | Toan | Ly  | Hoa | TB\n");
}
//Huy
void Title2()
{
    printf("\n|   MSSV   |\t   Ho va Ten  \t\t| GT |  Ngay sinh   |   Lop   | Toan | Ly  | Hoa | TB\n");
}
//Linh
void Output_List_Old_Student(LIST L)
{
    Title1();
    for(int i=0 ; i<L.num ; i++)
    {
        printf("%3d  ",i+1);
        Output_One_Old_Student(L.a[i]);
    }
}
//Nguyen
void AddStudent(LIST &L)
{
    int vt;
    printf("Nhap vi tri can chen: ");
    do
    {
        scanf("%d",&vt);
        if(vt<0 || vt>L.num)
            printf("Vi tri khong hop le. Nhap lai: ");
    } while (vt<0 || vt>L.num);

    L.num++;
    for(int i = L.num-1 ; i>=vt ; i--)
        L.a[i] = L.a[i - 1];
    printf("\nNhap thong tin sinh vien:");
    Input_One_Old_Student(L.a[vt]);
}
//Nguyen
void DeleteStudent(LIST &L)
{
    char mssv[11];
    printf("Nhap ma so sinh vien can xoa: ");
    fflush(stdin);
    gets(mssv);
    int vt;
    for(int i=0 ; i<L.num ; i++)
    {
        if(strcmp(L.a[i].mssv, mssv)==0) 
        {
            vt = i;
        }
    }
    for(int i=vt ; i<L.num ; i++)
    {
        L.a[i] = L.a[i+1];
    }
    L.num--;
}
//Nguyen
void Bubble_Sort_Student(LIST &L)
{
    SV temp;
    for(int i=0 ; i<L.num-1 ; i++)
    {
        for(int j=L.num-i-1 ; j>i ; j--)
        {
            if(L.a[j-1].dtb > L.a[j].dtb)
            {
                temp = L.a[j];
                L.a[j] = L.a[j-1];
                L.a[j-1] = temp;
            }
        }
    }
}
//Nguyen
void Linear_Search_MSSV(LIST L, char id[])
{
	int flag = 0;
    for(int i=0;i<L.num;i++)
    {
        if(strcmp(L.a[i].mssv,id) == 0)
        {
            flag = 1;
            Output_One_Old_Student(L.a[i]);
		}
	}
	if(flag == 0)
    {
        printf("\nKhong tim thay sinh vien!!!\n");
    }
}
//Huy
float Mark(float mark)
{
    float a = int(mark);
    while (a < mark + 0.05)
    {
        a += 0.1;
    }
    return a - 0.1;
}
//Nguyen
void Output_List_Student_Mark(LIST L)
{
    Bubble_Sort_Student(L);
    Output_List_Old_Student(L);

    float mark;
    printf("Xuat danh sach sinh vien theo DTB: ");
    scanf("%f",&mark);
    int count = 0;
    Title2();
    for(int i = 0 ; i < L.num ; i++)
    {
        if(Mark(L.a[i].dtb) - mark < 0.01 && Mark(L.a[i].dtb) - mark > -0.01)
        {
            count++;
            Output_One_Old_Student(L.a[i]);
        }
    }
    if(count == 0)
    {
        printf("Tim thay 0 thong tin sinh vien\n");
    }
}
//Nguyen
void Output_List_Student_Technology(LIST L)
{
    Title2();
    for(int i = 0 ; i<L.num ; i++)
    {
        if(strstr(L.a[i].lop,"DTH"))
        {
            Output_One_Old_Student(L.a[i]);
        }
    }
}
//Huy
void Empty_List(LIST L)
{
    printf("Danh sach sinh vien hien dang rong!!!\n");
    printf("Nhap so luong sinh vien: ");
    NhapSo(L.num);
    Input_List_Old_Student(L);
    system("pause");
}
//Nguyen & Huy & Linh
void Menu(LIST &L)
{
    while (true)
    {	
        system("cls");
        printf("\n\t\t--------------------MENU--------------------\n");
        printf("\t\t\t1. Tao Danh Sach Sinh Vien\n");
        printf("\t\t\t2. Xuat Danh Sach Sinh Vien\n");
        printf("\t\t\t3. Them Sinh Vien Vao Danh Sach\n");
        printf("\t\t\t4. Xoa Sinh Vien Theo MSSV\n");
        printf("\t\t\t5. Xuat Ten Sinh Vien Theo DTB Tang Dan\n");
        printf("\t\t\t6. Tim Sinh Vien Theo MSSV\n");
        printf("\t\t\t7. Xuat Sinh Vien Theo Diem\n");
        printf("\t\t\t8. Xuat Sinh Vien Theo Nganh CNTT\n");
        printf("\t\t\t0. Luu du lieu va Thoat.\n");
        printf("\t\t--------------------------------------------\n");

        int chon;
        printf("Nhap lua chon: ");  
        scanf("%d",&chon);

        if(chon == 0)
            break;

    switch (chon)
    {
        case 1:
        {
            printf("Nhap so luong sinh vien: ");
            NhapSo(L.num);
            Input_List_Old_Student(L);
            system("pause");
        }
        break;
        case 2:
        {
            if(IsEmpty(L))
            {
                Empty_List(L);
            }
            else
            {
                Output_List_Old_Student(L);
                system("pause");
            } 
        }
        break;
        case 3: 
        {
            if(IsFull(L))
            {
                printf("\nDanh sach da day");
                system("pause");
            }
            if(IsEmpty(L))
            {
                Empty_List(L);
            }
            else
            {
                AddStudent(L);
                system("pause");
            }
        }
        break;
        case 4:
        {
            if(IsEmpty(L))
            {
                printf("\nDanh sach trong !!!");
                system("pause");
            }
            else
            {
                DeleteStudent(L);
                system("pause");
            }
        }
        break;
        case 5:
        {
            if(IsEmpty(L))
            {
                Empty_List(L);
            }
            else
            {
                Bubble_Sort_Student(L);
                Output_List_Old_Student(L);
                system("pause");
            }
        }
        break;
        case 6:
        {
            if(IsEmpty(L))
            {
                Empty_List(L);
            }
            else
            {
                Output_List_Old_Student(L);
                char id[11];
                printf("Nhap ma so sinh vien can tim: ");
                fflush(stdin);
                gets(id);
                Title2();
                Linear_Search_MSSV(L,id);
                system("pause");
            }
        }
        break;
        case 7:          //Xuat sinh vien theo diem
            {
                if(IsEmpty(L))
                {
                    Empty_List(L);
                }
                else
                {
                    Output_List_Student_Mark(L);
                    system("pause");
                }
            }
            break; 
        case 8:         //Xuat sinh vien theo nganh CNTT
        {
            if(IsEmpty(L))
            {
                Empty_List(L);
            }
            else
            {
                Output_List_Student_Technology(L);
                system("pause");
            }
        }
        break;
        default:
            printf("\n\nLua chon khong hop le !!!");
            break;
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

    fprintf( f , "%s\n%s\n%s\n%d %d %d\n"
    ,a.mssv , a.hoten , a.lop , a.ns.ngay , a.ns.thang , a.ns.nam );

    if(a.gt == 'X')
        fprintf(f , "%s\n" , "Nu");
    else if(a.gt == 'Y')
        fprintf(f , "%s\n" , "Nam");

    fprintf(f , "%.1f\n%.1f\n%.1f\n%.1f\n", a.toan , a.ly , a.hoa , a.dtb );

    fclose(f);
}
//Huy
void DocFile(char filename[] , LIST &L)
{
    FILE *f;
    f = fopen(filename , "r");
	if(!f)
	{
		printf("Mo file khong thanh cong\n");
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

        fscanf(f , "%u" ,&a.ns.ngay);
        fscanf(f , "%u" ,&a.ns.thang);
        fscanf(f , "%u" ,&a.ns.nam);

        char gt[4];
        fscanf(f , "%s" , &gt);

        if(strcmp(gt,"Nam")==0)
            a.gt = 'Y';
        else if(strcmp(gt,"Nu")==0)
            a.gt = 'X';
    
        fscanf(f , "%f" ,&a.toan);
        fscanf(f , "%f" ,&a.ly);
        fscanf(f , "%f" ,&a.hoa);
        fscanf(f , "%f" ,&a.dtb);

        L.a[L.num++] = a;
    }
    L.num--;
    fclose(f);
}
//Huy
void SaveData(FILE* f, LIST L)
{
    int i = 0;
    while (i < L.num)
    {
        fprintf( f , "%s\n%s\n%s\n%u %u %u\n"
        ,L.a[i].mssv, L.a[i].hoten , L.a[i].lop , L.a[i].ns.ngay , L.a[i].ns.thang , L.a[i].ns.nam );

        if(L.a[i].gt == 'X')
            fprintf(f , "%s\n" , "Nu");
        else if(L.a[i].gt == 'Y')
            fprintf(f , "%s\n" , "Nam");

        fprintf(f , "%.1f\n%.1f\n%.1f\n%.1f\n", L.a[i].toan , L.a[i].ly , L.a[i].hoa , L.a[i].dtb );

        i++;
    }
}

int main()
{
    LIST L;
    numList(L);
    char filename[] = "DATA_SV.txt";
    DocFile(filename,L);
    Menu(L);
    FILE* f;
    f = fopen(filename,"w+");
    if(!f)
        printf("Mo file khong thanh cong");
    SaveData(f,L);
    fclose(f);
    return 0;
}