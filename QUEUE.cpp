#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//Nguyen
struct DATE
{
    int ngay,thang,nam;
};
//Nguyen
void NhapNgay(DATE &d)
{
    int ngaymax;
    do{
        printf(" + Ngay: ");
		scanf("%d",&d.ngay);
		
        printf(" + Thang: ");
		scanf("%d",&d.thang);
		
        printf(" + Nam: ");
		scanf("%d",&d.nam);
		
        if((d.ngay < 0 || d.ngay > 31) || (d.thang < 0 || d.thang > 12) || d.nam < 0)
        {
            printf("Ngay khong hop le\n");
        }
        else
        {
            switch(d.thang)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                {
                    ngaymax = 31;
                }
                    break;
                case 2:
                {
                    if (d.nam % 4 == 0)
                    {
                        ngaymax = 29;
                    }
                    else
                    {
                        ngaymax = 28;
                    }
                }
                    break;
                case 4: case 6: case 9: case 11:
                {
                    ngaymax = 30;
                }
                    break;
            }

            if(d.ngay > ngaymax)
            {
                printf("Ngay khong hop le. Vui long nhap lai\n");
            }
        }
    } while((d.ngay <= 0 || d.ngay > 31) || (d.thang < 0 || d.thang > 12) || d.nam < 0 || d.ngay > ngaymax);
}
//Huy
void XuatNgay(DATE d)
{
    if(d.ngay > 0 && d.ngay <= 9) 
	{
		if (d.thang > 0 && d.thang <= 9)
		{	
			printf("0%d/0%d/%d ",d.ngay,d.thang,d.nam);
		}
        else
        {
			printf("0%d/%d/%d ",d.ngay,d.thang,d.nam);
		} 
	} 
	
	else if(d.ngay >= 10) 
	{
		if (d.thang > 0 && d.thang <= 9)
		{
			printf("%d/0%d/%d ",d.ngay,d.thang,d.nam);
		}
		else
		{
			printf("%d/%d/%d ",d.ngay,d.thang,d.nam);
		}	
	} 
}
//Huy
int SoSanhNgay(DATE d1, DATE d2)
{
    if (d1.nam < d2.nam)
       return -1;

    else if (d1.nam > d2.nam)
       return 1;

    if (d1.nam == d2.nam)
    {
        if (d1.thang < d2.thang)
            return -1;
        else if (d1.thang > d2.thang)
            return 1;
        else if (d1.ngay < d2.ngay)
            return -1;
        else if(d1.ngay > d2.ngay)
            return 1;
        else
            return 0;
    }
}
//Huy
void ChuanHoaTen(char name[])
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
//Nguyen
struct SACH
{
    char ma_sach[11];
    char ten_sach[50];
    char loai[15];
    int sl_tong , sl_cho_thue , sl_con_lai;
    int gia;
    DATE ngay_thue;
};
//Nguyen
struct NODE
{
    SACH data;
    NODE *pNext;
};
//Nguyen
struct QUEUE
{
    NODE* pHead;
    NODE* pTail;
};
//Nguyen
bool IsEmpty(QUEUE Q)
{
    return Q.pHead == NULL;
}
//Nguyen
void Init(QUEUE &Q)
{
    Q.pHead = Q.pTail = NULL;
}
//Nguyen
NODE* CreateNode(SACH data)
{
    NODE* p = new NODE;
    if(p == NULL)
    {
        printf("Khong du bo nho cap phat\n");
        return NULL;
    }
    p->data = data;
    p->pNext = NULL;
    return p;
}
//Nguyen
void Push(QUEUE &Q, SACH data)
{
    NODE *p = CreateNode(data);
    if(IsEmpty(Q))
    {
        Q.pHead = Q.pTail = p;
    }
    else
    {
        Q.pTail->pNext = p;
        Q.pTail = p;
    }
}
//Nguyen
bool Pop(QUEUE &Q, SACH &s)
{   
    if(IsEmpty(Q))
        return false;
    
    NODE *p = Q.pHead;
    s = p->data;
    Q.pHead = Q.pHead->pNext;
    delete p;
    return true;
}
//Nguyen
bool Top(QUEUE &Q, SACH &s)
{
    if(IsEmpty(Q))
        return false;
        
    s = Q.pHead->data;
    return true;
}
//Huy
void NhapSo(int &a)
{
    do
    {
        scanf("%d",&a);
        if(a<0)
            printf("So luong khong hop le. Vui long nhap lai: ");
    } while (a<0);
}
//Van
void Nhap1Sach(SACH &s)
{
    printf("Ma Sach: ");
    fflush(stdin);
    gets(s.ma_sach);
	
    printf("Ten Sach: ");
    fflush(stdin);
    gets(s.ten_sach);
    ChuanHoaTen(s.ten_sach);

    printf("Loai Sach: ");
    fflush(stdin);
    gets(s.loai);
    ChuanHoaTen(s.loai);

    printf("Gia (Don vi: Nghin VND): ");
    NhapSo(s.gia);

	printf("So luong tong: ");
    NhapSo(s.sl_tong);

    printf("So luong cho thue: ");
    NhapSo(s.sl_cho_thue);

    s.sl_con_lai = s.sl_tong - s.sl_cho_thue;
    
    printf("Nhap ngay cho thue:\n");
    NhapNgay(s.ngay_thue);
}
//Huy
void Title()
{
    printf(" Ma Sach  |\t    Ten Sach     \t |   Loai    |   Gia   | Tong | Cho Thue | Con Lai | Ngay Cho Thue\n");
}
//Linh
void Xuat1Sach(SACH s)
{	
	printf("%10s%30s   %10s   %d 000     %2d      %2d\t     %2d\t     ",s.ma_sach,s.ten_sach,s.loai,s.gia,s.sl_tong,s.sl_cho_thue,s.sl_con_lai);
    XuatNgay(s.ngay_thue);
    printf("\n");
}
//Nguyen
void CreateQueue(QUEUE &Q)
{
    int n;
    printf("Nhap so luong: ");
    do
    {
        scanf("%d",&n);
        if(n<0)
            printf("So luong khong hop le. Vui long nhap lai: ");
    } while (n<0);
    for(int i=0 ; i<n ; i++)
    {
        SACH s;
        printf("----Nhap thong tin thu %d----\n",i);
        Nhap1Sach(s);
        Push(Q,s);
    }
}
//Linh
void ShowQueue(QUEUE Q)
{
    Title();
    for(NODE *k = Q.pHead ; k != NULL ; k = k->pNext)
    {
        Xuat1Sach(k->data);
    }
}
//Nguyen
void XoaDau(QUEUE &Q)
{
    NODE *p = new NODE;
    p = Q.pHead;
    Q.pHead = Q.pHead->pNext;
    delete p;
}
//Nguyen
void XoaCuoi(QUEUE &Q)
{
    NODE *p = new NODE;
    for(NODE *k = Q.pHead ; k != NULL ; k = k->pNext)
    {
        if(k->pNext == Q.pTail)
        {
            delete Q.pTail;
            k->pNext = NULL;
            Q.pTail = k;
        }
    }
}
//Nguyen
void XoaTheoMa(QUEUE &Q)
{
    char ma_sach[11];
    printf("Nhap ma sach can xoa: ");
    fflush(stdin);
    gets(ma_sach);

    bool flag = false;
    if(strcmp(Q.pHead->data.ma_sach , ma_sach) == 0)
    {
        flag = true;
        XoaDau(Q);
        return;
    }
    else if(strcmp(Q.pTail->data.ma_sach , ma_sach) == 0)
    {
        flag = true;
        XoaCuoi(Q);
        return;
    }
    else
    {
        NODE *g = new NODE;
        for(NODE *k = Q.pHead ; k != NULL ; k = k->pNext)
        {
            if(strcmp(k->data.ma_sach , ma_sach) == 0)
            {
                g->pNext = k->pNext;
                flag = true;
                return;
            }
            g = k;
        }
    }
    if(!flag)
    {
        printf("Khong tim thay ma sach: %s\n",ma_sach);
    }
}
//Linh
void TimTheoMa(QUEUE Q)
{
    char ma_sach[11];
    printf("Nhap ma sach can tim: ");
	fflush(stdin);
	gets(ma_sach);
	
    bool flag = false;
    for(NODE *k = Q.pHead; k != NULL; k = k->pNext)
    {
        if(strcmp(k->data.ma_sach , ma_sach) == 0)
        {
            Title();
            Xuat1Sach(k->data);
            flag = true;
        }
    }
    if(!flag)
    {
        printf("Khong tim thay sach co ma: %s\n",ma_sach);
    }
}
//Huy
void TimTheoTen(QUEUE Q)
{
    char ten_sach[30];
    printf("Nhap ten sach can tim: ");
	fflush(stdin);
	gets(ten_sach);
    ChuanHoaTen(ten_sach);
	
    bool flag = false;
    for(NODE *k = Q.pHead; k != NULL; k = k->pNext)
    {
        if(strcmp(k->data.ten_sach , ten_sach) == 0)
        {
            Title();
            Xuat1Sach(k->data);
            flag = true;
        }
    }
    if(!flag)
    {
        printf("Khong tim thay sach co ten: %s\n",ten_sach);
    }
}
//Huy
void SWAP(SACH &a, SACH &b)
{
    SACH t = a;
    a = b;
    b = t;
}
//Huy
void SapXepTheoNgay(QUEUE &Q)
{
    for(NODE *i = Q.pHead ; i != NULL ; i = i->pNext)
    {
        for(NODE *j = i->pNext ; j != NULL ; j = j->pNext)
        {
            if(SoSanhNgay(i->data.ngay_thue , j->data.ngay_thue) == 1)
            {
                SWAP(i->data , j->data);
            }
        }
    }
}
//Nguyen
void SapXepTheoMa(QUEUE &Q)
{
    for(NODE *i = Q.pHead ; i != NULL ; i = i->pNext)
    {
        for(NODE *j = i->pNext ; j != NULL ; j = j->pNext)
        {
            if(strcmp(i->data.ma_sach,j->data.ma_sach) > 0)
            {
                SWAP(i->data , j->data);
            }
        }
    }
}
//Van
void SapXepTheoGia(QUEUE &Q)
{
    for(NODE *i = Q.pHead ; i != NULL ; i = i->pNext)
    {
        for(NODE *j = i->pNext ; j != NULL ; j = j->pNext)
        {
            if(i->data.gia > j->data.gia)
            {
                SWAP(i->data , j->data);
            }
        }
    }
}
//Huy
void DocFile(char filename[], QUEUE &Q)
{
    FILE* f;
    f = fopen(filename,"r");
    if(!f)
    {
        printf("Mo file khong thanh cong\n");
        exit(0);
    }
    while (!feof(f))
    {
        SACH a;
        char t[5];
        fscanf(f,"%s",&a.ma_sach);
        
        fgets(t,5,f);
        fgets(a.ten_sach,50,f);
        a.ten_sach[strlen(a.ten_sach) - 1] = '\0';

        //fgets(t,5,f);
        fgets(a.loai,15,f);
        a.loai[strlen(a.loai) - 1] = '\0';

        fscanf(f,"%d",&a.gia);
        fscanf(f,"%d %d %d",&a.sl_tong,&a.sl_cho_thue,&a.sl_con_lai);
        fscanf(f,"%d %d %d",&a.ngay_thue.ngay,&a.ngay_thue.thang,&a.ngay_thue.nam);

        Push(Q,a);
    }
    fclose(f);
}
//Huy
void GhiFile(char filename[], SACH a)
{
    FILE* f;
    f = fopen(filename,"a");
    if(!f)
    {
        printf("Mo file khong thanh cong\n");
        exit(0);
    }

    fprintf(f,"\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d %d %d\n"
    ,a.ma_sach ,a.ten_sach ,a.loai ,a.gia ,a.sl_tong ,a.sl_cho_thue ,a.sl_con_lai
    ,a.ngay_thue.ngay ,a.ngay_thue.thang ,a.ngay_thue.nam);

    fclose(f);
}
//Huy
void SaveData(FILE* f, QUEUE Q)
{
    NODE *p = Q.pHead;
    while (p)
    {
        fprintf(f,"\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d %d %d\n"
        ,p->data.ma_sach ,p->data.ten_sach ,p->data.loai ,p->data.gia 
        ,p->data.sl_tong ,p->data.sl_cho_thue ,p->data.sl_con_lai
        ,p->data.ngay_thue.ngay ,p->data.ngay_thue.thang ,p->data.ngay_thue.nam);

        p = p->pNext;
    }
}
//Linh
void Xuat_Thieunhi(QUEUE Q)
{
    printf("\n\nThe loai: Thieu nhi\n");
    bool flag = false;
    Title();
    for(NODE* i = Q.pHead ; i != NULL ; i = i->pNext)
    {
        if(strstr(i->data.ma_sach,"A20117"))
        {
            Xuat1Sach(i->data);
            flag = true;
        }
    }
    if(flag == false)
        printf("\nDanh sach khong co truyen Thieu nhi\n");
}
//Linh
void Xuat_Vanhoc(QUEUE Q)
{
    printf("\n\nThe loai: Van hoc\n");
    bool flag = false;
    Title();
    for(NODE* i = Q.pHead ; i != NULL ; i = i->pNext)
    {
        if(strstr(i->data.ma_sach,"B20110"))
        {
            Xuat1Sach(i->data);
            flag = true;
        }
    }
    if(flag == false)
        printf("\nDanh sach khong co truyen Van hoc\n");
}
//Linh
void Xuat_Tieuthuyet(QUEUE Q)
{
    printf("\n\nThe loai: Tieu thuyet\n");
    bool flag = false;
    Title();
    for(NODE* i = Q.pHead ; i != NULL ; i = i->pNext)
    {
        if(strstr(i->data.ma_sach,"D28277"))
        {
            Xuat1Sach(i->data);
            flag = true;
        }
    }
    if(flag == false)
        printf("\nDanh sach khong co Tieu thuyet\n");
}
//Huy & Linh & Nguyen & Van
void Menu(QUEUE &Q)
{
    while (true)
    {
        system("cls");
        printf("\n\t----------------------MENU----------------------");
        printf("\n\t\t(0) Luu du lieu va Thoat");
        printf("\n\t\t(1) Nhap thong tin");
        printf("\n\t\t(2) Xuat thong tin");
        printf("\n\t\t(3) Them thong tin");
        printf("\n\t\t(4) Xoa theo ma sach");
        printf("\n\t\t(5) Tim kiem theo ma truyen");
        printf("\n\t\t(6) Tim kiem theo ten truyen");
        printf("\n\t\t(7) Sap xep theo ngay cho thue");
        printf("\n\t\t(8) Sap xep theo Ma truyen");
        printf("\n\t\t(9) Sap xep theo Gia truyen");
        printf("\n\t\t(10) Xuat ra danh sach truyen theo phan loai");
        printf("\n\t----------------------END----------------------");

        int chon;
        printf("\nNhap lua chon: ");
        scanf("%d",&chon);

        if(chon == 0)
            break;

        switch (chon)
        {
            case 1:
                {
                    CreateQueue(Q);
                    system("pause");
                }
                break;
            case 2:
                {
                    ShowQueue(Q);
                    system("pause");
                }
                break;
            case 3:
                {
                    SACH s;
                    printf("----Nhap thong tin can them----\n");
                    Nhap1Sach(s);
                    Push(Q,s);
                    system("pause");
                }
                break;
            case 4:
                {
                    XoaTheoMa(Q);
                    printf("Thong tin sau khi xoa\n");
                    ShowQueue(Q);
                    system("pause");
                }
                break;
            case 5:
                {
                    TimTheoMa(Q);
                    system("pause");
                }
                break;
            case 6:
                {
                    TimTheoTen(Q);
                    system("pause");
                }
                break;
            case 7:
                {
                    SapXepTheoNgay(Q);
                    printf("Thong tin sau khi sap xep\n");
                    ShowQueue(Q);
                    system("pause");
                }
                break;
            case 8:
                {
                    SapXepTheoMa(Q);
                    printf("Thong tin sau khi sap xep\n");
                    ShowQueue(Q);
                    system("pause");
                }
                break;
            case 9:
                {
                    SapXepTheoGia(Q);
                    printf("Thong tin sau khi sap xep\n");
                    ShowQueue(Q);
                    system("pause");
                }
                break;
            case 10:
                {
                    printf("\n\t\t1. Thieu nhi");
                    printf("\n\t\t2. Van hoc");
                    printf("\n\t\t3. Tieu thuyet");
                    int c;
                    printf ("\nMoi nhap lua chon: ");
                    scanf ("%d", &c);

                    if(c == 1)
                    {
                        Xuat_Thieunhi(Q);
                    }
                    else if(c == 2)
                    {
                        Xuat_Vanhoc(Q);
                    }
                    else if(c == 3)
                    {
                        Xuat_Tieuthuyet(Q);
                    }
                    else
                    {
                        printf ("\nLua chon khong hop le!");
                    }
                    system("pause");
                }
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai lua chon !!!\n");
                system("pause");
                break;
        }
    }
}

int main()
{
    QUEUE Q;
    Init(Q);
    char filename[] = "DATA_BOOK.txt";
    DocFile(filename,Q);
    Menu(Q);
    FILE* f;
    f = fopen(filename,"w+");
    if(!f)
        printf("Mo file khong thanh cong\n");
    SaveData(f,Q);
    fclose(f);
    return 0;
}