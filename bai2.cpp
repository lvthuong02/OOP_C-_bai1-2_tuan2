// Bài 2: Xây dựng lớp giáo viên GV gồm các thuộc tính họ tên ht (kiểu char[30]), tuổi t
// (kiểu số nguyên), bằng cấp cao nhất được đào tạo bc (kiểu char[15]), chuyên ngành
// (kiểu char[20]), bậc lương bl (kiểu float) là các thuộc tính riêng. Trong lớp có định
// nghĩa các hàm công cộng sau:
// - Hàm nhập dữ liệu cho các thông tin trên của 1 giáo viên
// - Hàm xuất các thông tin trên của giáo viên ra màn hình
// - Hàm tính tiền lương cơ bản lcb biết rằng lcb = bl *610
// Viết chương trình nhập vào n(n nguyên dương nhập từ bàn phím) giáo viên. In ra màn
// hình:
// - Danh sách các giáo viên có tiền lương nhỏ hơn 2000.
// - Danh sách giáo viên sắp xếp theo chuyên ngành.
#include<iostream>
#include<conio.h>
#include<cstdio>
#include<string.h>
using namespace std;
class teacher
{
    private:
        char ht[30],bc[15],cn[20];
        int t;
        float bl;
    public:
        void input()
        {
            cout<<"Nhap ten :";
            fflush(stdin);
            cin.getline(this->ht,30);
            cout<<"Nhap bang cap :";
            fflush(stdin);
            cin.getline(this->bc,15);
            cout<<"Nhap chuyen nganh :";
            fflush(stdin);
            cin.getline(this->cn,20);
            cout<<"Nhap tuoi :";cin>>t;
            cout<<"Nhap bac luong :";cin>>bl;
        }
        void output()
        {
            cout<<"Ten :"<<ht<<endl;
            cout<<"Bang cap :"<<bc<<endl;
            cout<<"Chuyen nganh :"<<cn<<endl;
            cout<<"Tuoi :"<<t<<endl;
            cout<<"Bac luong :"<<bl<<endl;
            cout<<"Luong co ban :"<<(int)bl*610<<endl;
            cout<<endl;
        }
        int lcb()
        {
            if(bl*610 < 2000)
                return 1;
            return 0;
        }
        friend void arrange(teacher x[],int n)
        {
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                    if(strcmp(x[i].cn,x[j].cn)==1)
                    {
                        teacher tp=x[i];
                        x[i]=x[j];
                        x[j]=tp;
                    }
        }
};
int main()
{
    int n;
    cout<<"Nhap so luong giao vien :";cin>>n;
    teacher* x=new teacher[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap thong tin giao vien thu :"<<i+1<<endl;
        x[i].input();
    }
    cout<<endl;
    cout<<"==Thong tin "<<n<< " giao vien sau khi nhap la=="<<endl;
    for(int i=0;i<n;i++)
    {
        x[i].output();
    }
    cout<<"==Danh sach giao vien co tien luong nho hon 2000=="<<endl;
    for(int i=0;i<n;i++)
        if(x[i].lcb() == 1)
        {
            x[i].output();
        }
    cout<<"==Danh sach giao vien sap xep theo chuyen nganh==\n";
    arrange(x,n);
    for(int i=0;i<n;i++)
    {
        x[i].output();
    }
    getche();
    return 0;
}