#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Van
struct TuDien
{
    char tiengAnh[30];
    char tiengViet[30];
    char tuLoai[10];
};
//Van
void Nhap1Tu(TuDien &a)
{

    printf("Tieng Anh: ");
    fflush(stdin);
    gets(a.tiengAnh);

    printf("Tieng Viet: ");
    fflush(stdin);
    gets(a.tiengViet);

    printf("Danh tu (n)\nDong tu (v)\nTinh tu (adj)\n");

    int ss1 , ss2 , ss3;
    do
    {
        printf("Tu loai: ");
        rewind(stdin);
        gets(a.tuLoai);
        
        ss1 = strcmp(a.tuLoai,"n");
        ss2 = strcmp(a.tuLoai,"v");
        ss3 = strcmp(a.tuLoai,"adj");

        if(ss1 != 0 && ss2 != 0 && ss3 != 0)
            printf("Tu loai vua nhap khong hop le. Vui long nhap lai\n");

    } while (ss1 != 0 && ss2 != 0 && ss3 != 0);
}
//Van
void Title()
{
    printf("\nVocabulary\t\t   Tu Loai\t Mean\n");
}
//Van
void Xuat1Tu(TuDien a)
{
    printf("%-30s% -10s %-30s\n",a.tiengAnh,a.tuLoai,a.tiengViet);
}
//Van
struct NODE
{
    TuDien data;
    NODE *pLeft;
    NODE *pRight;
    int height;
};
//Van
NODE* CreateNode(TuDien data)
{
    NODE *p = new NODE;
    p->data = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->height = 1;
    return p;
}
//Van
bool Init(NODE* &Root)
{
    Root = NULL;
}
//Linh
int GetHeight(NODE *p)
{
    if(!p) return 0;
    return p->height;
}
//Linh
int GetBalance(NODE *p)
{
    if(!p)  return 0;
    return GetHeight(p->pLeft) - GetHeight(p->pRight);
}
//Huy
NODE* RotateLeft(NODE* &p)
{
    if(!p) return NULL;
    if(!p->pRight) return NULL;

    NODE *pivot = p->pRight;

    p->pRight = pivot->pLeft;
    pivot->pLeft = p;

    p->height = 1 + __max(GetHeight(p->pRight) , GetHeight(p->pLeft));
    pivot->height = 1 + __max(GetHeight(pivot->pRight) , GetHeight(pivot->pLeft));

    return pivot;
}
//Huy
NODE* RotateRight(NODE* &p)
{
    if(!p) return NULL;
    if(!p->pLeft)   return NULL;

    NODE *pivot = p->pLeft;

    p->pLeft = pivot->pRight;
    pivot->pRight = p;

    p->height = 1 + __max(GetHeight(p->pRight) , GetHeight(p->pLeft));
    pivot->height = 1 + __max(GetHeight(pivot->pRight) , GetHeight(pivot->pLeft));

    return pivot;
}
//Huy
NODE* Balance(NODE* &pRoot)
{
    if(GetBalance(pRoot) < -1)
    {
        if(GetBalance(pRoot->pRight) > 0)
        {
            pRoot->pRight = RotateRight(pRoot->pRight);
        }
        pRoot = RotateLeft(pRoot);
    }
    else if(GetBalance(pRoot) > 1)
    {
        if(GetBalance(pRoot->pLeft) < 0)
        {
            pRoot->pLeft = RotateLeft(pRoot->pLeft);
        }
        pRoot = RotateRight(pRoot);
    }
    return pRoot;
}
//Linh
NODE* Insert(NODE* &Root, TuDien data)
{
    if(!Root) return CreateNode(data);

    if(strcmp(data.tiengAnh , Root->data.tiengAnh) < 0)
        Root->pLeft = Insert(Root->pLeft , data);

    else if(strcmp(data.tiengAnh , Root->data.tiengAnh) > 0)
        Root->pRight = Insert(Root->pRight , data);

    Root->height = 1 + __max(GetHeight(Root->pLeft) , GetHeight(Root->pRight));

    return Balance(Root);
}
//Linh
void LNR(NODE* Root)
{
    if(Root)
    {
        LNR(Root->pLeft);
        Xuat1Tu(Root->data);
        LNR(Root->pRight);
    }
}
//Linh
void NLR(NODE* Root)
{
    if(Root)
    {
        Xuat1Tu(Root->data);
        NLR(Root->pLeft);
        NLR(Root->pRight);
    }
}
//Linh
NODE* MinValue(NODE* pRoot)
{
    NODE *curent = pRoot;
    while (curent && curent->pLeft)
        curent = curent->pLeft;
    return curent;
}
//Linh
NODE* Remove(NODE* &Root, char key[])
{
    if(!Root)  return NULL;
    if(strcmp(Root->data.tiengAnh , key) > 0)
        Root->pLeft = Remove(Root->pLeft , key);
    else if(strcmp(Root->data.tiengAnh , key) < 0)
        Root->pRight = Remove(Root->pRight , key);
    else
    {
        if(!Root->pLeft)
        {
            NODE* tempt = Root->pRight;
            delete Root;
            return tempt;
        }
        else if(!Root->pRight)
        {
            NODE* tempt = Root->pLeft;
            delete Root;
            return tempt;
        }
        NODE* tempt = MinValue(Root->pRight);
        Root->data = tempt->data;
        Root->pRight = Remove(Root->pRight , tempt->data.tiengAnh);
    }
    if(!Root)  return NULL;
    Root->height = 1 + __max(GetHeight(Root->pLeft),GetHeight(Root->pRight));
    return Balance(Root);
}
//Huy
void DocFile(char filename[] , NODE* &Root)
{
    FILE *f;
    f = fopen(filename , "r");
    if(!f)
    {
        printf("Mo file khong thanh cong\n");
        return;
    }
    while (!feof(f))
    {
        TuDien a;
        char t[5];

        fscanf(f , "%s" , &a.tiengAnh);

        fgets(t,5,f);
        fgets(a.tiengViet,30,f);
        a.tiengViet[strlen(a.tiengViet) - 1] = '\0';

        fscanf(f , "%s" , &a.tuLoai);

        Root = Insert(Root , a);
    }
    fclose(f);
}
//Huy
void GhiFile(char filename[] , TuDien data)
{
    FILE *f;
    f = fopen(filename,"a");
    if(!f)
    {
        printf("Mo file khong thanh cong\n");
        return;
    }
    fprintf(f,"%s\n%s\n%s\n",data.tiengAnh,data.tiengViet,data.tuLoai);
    fclose(f);
}
//Huy
void SaveData(FILE *f , NODE* Root)
{
    if(Root)
    {
        fprintf(f,"%s\n%s\n%s\n",Root->data.tiengAnh,Root->data.tiengViet,Root->data.tuLoai);
        SaveData(f,Root->pLeft);
        SaveData(f,Root->pRight);
    }
}
//Nguyen
bool Search_Eng(NODE* Root, char key[])
{ 
    if(Root)
    {
        if(strcmp(Root->data.tiengAnh , key) == 0)
        {
            Title();
            Xuat1Tu(Root->data);
            return true;
        }
        else if(strcmp(Root->data.tiengAnh , key) > 0)
            return Search_Eng(Root->pLeft,key);
        else
            return Search_Eng(Root->pRight,key);
    }
    return false;
}
//Nguyen
bool Search_Vie(NODE* Root, char key[])
{
    if(Root)
    {
        if(strcmp(Root->data.tiengViet , key) == 0)
        {
            Title();
            Xuat1Tu(Root->data);
            return true;
        }
        return Search_Vie(Root->pLeft , key);
        return Search_Vie(Root->pRight , key);
    }
    return false;
}
bool check = false;     //Huy
void Approximate_Search(NODE* Root, char key[])
{
    if(Root)
    {
        if(strstr(Root->data.tiengAnh , key))
        {
            Title();
            Xuat1Tu(Root->data);
            check = true;
        }
        Approximate_Search(Root->pLeft , key);
        Approximate_Search(Root->pRight , key);
    }
}
//Van
void Change_Meaning(NODE* &Root, char key[])
{
    if(!Root)
    {
        printf("Khong tim thay tu \"%s\" trong tu dien\n",key); 
        return;
    }
    if(strcmp(Root->data.tiengAnh , key) == 0)
    {
        printf("Nhap lai nghia tieng Viet muon thay doi: ");
        fflush(stdin);
        gets(Root->data.tiengViet);
        return;
    }
    else if(strcmp(Root->data.tiengAnh , key) > 0)
        Change_Meaning(Root->pLeft,key);
    else
        Change_Meaning(Root->pRight,key);
}
//Huy & Linh & Van & Nguyen
void Menu(NODE* &Root, char filename[])
{
    while (true)
    {
        system("cls");
        printf("\n\t-----------------------------MENU-----------------------------");
        printf("\n\t\t(1) Xuat tat ca tu vung");
        printf("\n\t\t(2) Them 1 tu vung va ghi vao file");
        printf("\n\t\t(3) Tra tu vung tieng Anh");
        printf("\n\t\t(4) Tra tu vung tieng Anh qua nghia tieng Viet");
        printf("\n\t\t(5) Xoa 1 tu tieng Anh");
        printf("\n\t\t(6) Tra 1 tu vung tieng Anh va thay doi nghia tieng Viet");
        printf("\n\t\t(7) Tim kiem gan dung tu tieng Anh");
        printf("\n\t\t(0) Luu du lieu va Thoat");
        printf("\n\t-----------------------------END-----------------------------");

        int chon;
        printf("\nNhap lua chon: ");
        scanf("%d",&chon);

        if(chon == 0)
            break;
        char key[30];
        switch (chon)
        {
            case 1:     //Xuat tat ca tu vung
                {
                    printf("Tu dien Anh-Viet\n");
                    Title();
                    LNR(Root);
                    system("pause");
                }
                break;
            case 2:     //Them 1 tu vung va ghi vao file
                {
                    TuDien new_word;
                    Nhap1Tu(new_word);
                    Root = Insert(Root , new_word);
                    GhiFile(filename , new_word);
                    system("pause");
                }
                break;
            case 3:
                {
                    printf("Nhap tu tieng Anh can tim: ");
                    fflush(stdin);
                    gets(key);
                    if(!Search_Eng(Root,key))
                        printf("Khong tim thay tu \"%s\" trong tu dien\n",key);
                    system("pause");
                }
                break;
            case 4:     //Tim kiem tu tieng Viet
                {
                    printf("Nhap tu tieng Viet can tim: ");
                    fflush(stdin);
                    gets(key);
                    if(!Search_Vie(Root,key))
                        printf("Khong tim thay tu \"%s\" trong tu dien\n",key);
                    system("pause");
                }
                break;
            case 5:     //Xoa 1 tu tieng Anh
                {
                    printf("Nhap tu tieng Anh muon xoa: ");
                    fflush(stdin);
                    gets(key);
                    Root = Remove(Root , key);
                    system("pause");
                }
                break;
            case 6:     //Tim 1 tu tieng Anh va thay doi nghia tieng Viet
                {
                    printf("Nhap tu tieng Anh muon thay doi nghia tieng Viet: ");
                    fflush(stdin);
                    gets(key);
                    Change_Meaning(Root,key);
                    system("pause");
                }
                break;
            case 7:     //Tim kiem gan dung tu tieng Anh
                {
                    printf("Nhap tu tieng Anh can tim: ");
                    fflush(stdin);
                    gets(key);
                    Approximate_Search(Root,key);
                    if(!check)
                        printf("Khong tim thay tu tieng Anh co chuoi \"%s\"\n",key);
                    system("pause");
                }
                break;
            default:
                printf("Lua chon vua nhap khong hop le. Vui long nhap lai !!!\n");
                system("pause");
                break;
        }
    }
}

int main()
{
    NODE* Root;
    Init(Root);
    char filename[] = "TREE_DATA.txt";
    DocFile(filename,Root);

    Menu(Root,filename);

    FILE *f;
    f = fopen(filename,"w+");
    if(!f)
        printf("Mo file khong thanh cong");
    SaveData(f,Root);

    fclose(f);
    return 0;
}