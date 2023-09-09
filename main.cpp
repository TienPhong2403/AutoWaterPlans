#include <iostream>
#include <iomanip>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <stdio.h>
#include <thread>
#include<cmath>


using namespace std;

int b;
int idti;
bool stop = 1;
struct Hour
{
    int hour;
    int minute;
    int second;
};
char inToA(int k)
{
    switch (k)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    }
}

void insertarray(char *h, Hour *j)
{
    int bait = 0;
    bait = j->second; // giay =2 chia du 2| chia lay nguyen 0   |2-> 02
    h[7] = inToA(bait % 10);
    h[6] = inToA(bait /= 10);

    bait = j->minute;
    h[4] = inToA(bait % 10);
    h[3] = inToA(bait /= 10);

    bait = j->hour;
    h[1] = inToA(bait % 10);
    h[0] = inToA(bait /= 10);
}

bool changetime(Hour *h)
{
    if (h->second > 0)
        --h->second;
    else if (h->minute > 0)
    {
        h->second = 59;
        --h->minute;
    }
    else if (h->hour > 0)
    {
        --h->hour;
        h->minute = 59;
        h->second = 59;
    }
    else
        return 0;
    return 1;
}

void WriteBlockChar(char *Arraych,
                    int row, int col,
                    int x, int y,
                    int color)
{
    CHAR_INFO *charater = new CHAR_INFO[row * col];
    for (int i = 0; i < row * col; i++)
    {
        charater[i].Attributes = color;
        charater[i].Char.AsciiChar = Arraych[i];
    }
    COORD sizebuff = {col, row};
    COORD pos = {0, 0};
    SMALL_RECT earea = {x, y, x + col - 1, y + row - 1};
 WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
    delete[] charater;
}

void printClock()
{
    int g, p, s, in;
    Hour h;
    cin >> g >> p >> s;
    h.hour = g;
    h.minute = p;
    h.second = s;

    char a[8] = {'0', '0', ':', '0', '0', ':', '0', '0'};
    in = 1;
    if (in == 1)
    {

        while (stop)
        {
            if (!changetime(&h))
                stop = 0;
            insertarray(a, &h);
            WriteBlockChar(a, 1, 8, 70, 3, 0x004 | 0x060);
            Sleep(970);
        }
    }
    Beep(1320, 1500);
    int add = b;
    cout << "Da tuoi them " << add << "m^3 nuoc";
    in = 0;
    stop = 1;
}
class Plant
{
    protected:
        char name[100];
        char plant;
        float area, ln;
    public:
        Plant()
        {

        }
        void plantName()
        {
            cout<<endl<<"Nhap ten cay: "; cin.ignore(); cin.get(name, 100);
        }
        void getName()
        {
            cout<<name;
        }
        void plantArea()
        {
            cout<<"Nhap dien tich vuon cay (m^2) = "; cin>>area;
        }
        float returnArea()
        {
            return area;
        }
        void getArea()
        {
            cout<<area<<" (m^2)";
        }
        void plantLn()
        {
            cout<<"Nhap luong nuoc can thiet cho 1 m^2: "; cin>>ln;
        }
        float returnln()
        {
            return ln;
        }
        void TypePlant()
        {
            switch (plant)
            {
                case 1:
                    cout<<"Cay luong thuc ";
                    break;
                case 2:
                    cout<<"Cay an qua ";
                    break;
                case 3:
                    cout<<"Thao duoc";
                    break;
                case 4:
                    cout<<"Cay canh";
                    break;
                case 5:
                    cout<<"Cay lam nghiep";
                    break;
                case 6:
                    cout<<"Cay cong nghiep";
                    break;
            }
        }
        void ChoosePlant()
        {
            cout<<endl<<"Chon loai cay trong";
            cout<<endl<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
            cout<<endl<<"┃(1) Cay luong thuc                  ┃";
            cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
            cout<<endl<<"┃(2) Cay an qua                      ┃";
            cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
            cout<<endl<<"┃(3) Cay thao duoc                   ┃";
            cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
            cout<<endl<<"┃(4) Cay canh                        ┃";
            cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
            cout<<endl<<"┃(5) Cay lam nghiep                  ┃";
            cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
            cout<<endl<<"┃(6) Cay cong nghiep                 ┃";
            cout<<endl<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

            cout<<endl<<"Nhap lua chon cua ban: ";

            bool check = true;
            while (check)
            {
                int n;
                cin>>n;
                if(n>0 && n<=6)
                {
                    plant = n;
                    check = false;
                }
                else
                    cout<<endl<<"Khong co loai cay nay! Vui long nhap lai: ";
            }
        }
};
class Moisture
{
    protected:
        int moist;
        int cur_moist;
    public:
        void input_Moistune()
        {
            cout<<"Nhap do am can thiet cua cay la: "; cin>>moist;
        }
        void inputCurr_Moist()
        {
            cout<<endl<<"Nhap do am hien tai: "; cin>>cur_moist;
        }
        void getMoistune()
        {
             cout<<moist<<"%";
        }
        void showCur_Moistune()
        {
            bool check = true;
            while (check)
            {
                if(cur_moist < moist)
                {
                    cout<<"Do am khong du. Can tuoi nuoc them!";
                    check = false;
                }
                else
                {
                    cout<<"Do am da du. Khong can tuoi nuoc them!";
                    break;
                }
            }
        }
};
class Temperature
{
    protected:
        int temper;
        int cur_temper;
    public:
    void inputTemperatune()
    {
        cout<<"Nhap nhiet do gioi han: "; cin>>temper;
    }
    void inputCurr_Temper()
    {
        cout<<endl<<"Nhap nhiet do hien tai: "; cin>>cur_temper;
    }
    void getTemperatune()
    {
        cout<<temper<<" do C";
    }
    void showCur_Temperatune()
    {
        bool check = true;
        while (check)
        {
            if(cur_temper > temper)
            {
                cout<<"Nhiet do qua cao. Can tuoi nuoc them!"<<endl;
                check = false;
            }
            else
            {
                cout<<"Nhiet do phu hop. Khong can tuoi nuoc them!"<<endl;
                break;
            }
        }
    }
};
class WateringSystem: public Moisture, public Temperature, public Plant
{
    protected:
        bool stt = true;
        float water, add, time;
    public:
        WateringSystem *next;
        void normalize()
        {
            int g, p ,s;
            g = time;
            time -= g;  time *= 60;
            p = time;
            time -= p; time *= 60;
            s = time;
            cout<<endl<<"Thoi gian tuoi nuoc la: ";
            if(g<9 && p<9 && s<9)
            {
                cout<<"0"<<g<<":"<<"0"<<p<<":"<<"0"<<s;
            }
            else if(g<9 && p<9 )
            {
                cout<<"0"<<g<<":"<<"0"<<p<<":"<<s;
            }
            else if(g<9 && s<9 )
            {
                cout<<"0"<<g<<":"<<p<<":"<<"0"<<s;
            }
            else if(g<9)
            {
                cout<<"0"<<g<<":"<<p<<":"<<s;
            }
            else if(p<9 && s<9 )
            {
                cout<<g<<":"<<"0"<<p<<":"<<"0"<<s;
            }
            else if(p<9)
            {
                cout<<g<<":"<<"0"<<p<<":"<<s;
            }
            else if(s<9)
            {
                cout<<g<<":"<<p<<":"<<"0"<<s;
            }
            else
            {
                cout<<g<<":"<<p<<":"<<"0"<<s;
            }
        }
        void displayAmountOfWater()
        {
            cout<<endl<< "Luong nuoc da tuoi la: " <<water<< " (m3)"<<endl;
        }
        void displayTime()
        {
            cout<<endl<< "Thoi gian tuoi nuoc la: " <<setprecision(3)<<fixed<<time<< " (h)";
        }
        void SmartWatering()
        {
            // float hsl;
            int pump, ct;
            float DT = returnArea();
            float LN = returnln();
            water = DT * LN;
            int x;
            cout<<endl<<"Tien hanh tuoi thong minh?";
            cout<<endl<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
            cout<<endl<<"┃(1) Co                     ┃";
            cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
            cout<<endl<<"┃(2) Khong                  ┃";
            cout<<endl<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
            cout<<endl<<"Nhap lua chon: ";
            bool check = true;
            while (check)
            {
                cin >> x;
                if (x == 1)
                {
                    if((cur_temper > temper) && (cur_moist < moist))
                    {
                        cout<<endl<<"Nhiet do qua cao. Do am khong du!";
                        cout<<endl<<"Tien hanh tuoi nhanh voi 3 may bom!";
                        pump = 3; ct = 1000;
                        /* hsl = (moist - cur_moist);
                         water = water * hsl;
                         */
                        time = water / (pump*ct);
                        displayTime();
                        normalize();
                        displayAmountOfWater();
                    }
                    else if((cur_temper < temper) && (cur_moist < moist))
                    {
                        cout<<endl<<"Nhiet do phu hop. Do am khong du!";
                        cout<<endl<<"Tien hanh tuoi nho giot voi 2 may bom!";
                        pump = 2; ct = 800;
                        /* hsl = (moist - cur_moist);
                         water = water * hsl;
                         */
                        time = water / (pump*ct);
                        displayTime();
                        normalize();
                        displayAmountOfWater();
                    }
                    else if((cur_temper > temper) && (cur_moist > moist))
                    {
                        cout<<endl<<"Nhiet do qua cao. Do am phu hop!";
                        cout<<endl<<"Tien hanh tuoi phun suong voi 1 may bom!";
                        pump = 1; ct = 500;
                        time = water / (pump*ct);
                        displayTime();
                        normalize();
                        displayAmountOfWater();
                    }
                    else
                    {
                        cout<<endl<<"Dieu kien thich hop. Khong can tuoi.";
                        cout<<endl;
                    }
                    check = false;
                }
                else if (x == 2)
                {
                    cout<<endl<<"Khong tuoi thi thoi"<<endl;
                    check = false;
                }
                else
                {
                    cout<<"Khong co chuc nang nay! Moi ban nhap lai.";
                    cout<<endl<<"Nhap lua chon: ";
                }
            }
        }
        void OptionalWatering()
        {
            int pump, ct,LN;
            // float hsl;
            float DT = returnArea();
            pump = Chonmaybom();
            ct = Cachtuoi();
            cout<<endl<<"Nhap luong nuoc tuoi /1m^2 (m^3): "; cin>>LN;
            water = DT * LN;
            time = water / (pump*ct);
            displayAmountOfWater();
            displayTime();
            normalize();
        }
        // Chon cach tuoi
        int Cachtuoi()
        {
            int x, y;
            cout<<endl<<"Ban muon cach tuoi nao ";
            cout<<endl<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
            cout<<endl<<"┃(1) Tuoi phun suong(500 m^3/h)             ┃";
            cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
            cout<<endl<<"┃(2) Tuoi nho giot(800 m^3/h)               ┃";
            cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
            cout<<endl<<"┃(3) Tuoi nhanh(1000 m^3/h)                 ┃";
            cout<<endl<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
            cout<<endl<<"Nhap lua chon: ";
            bool check = true;
            while (check)
            {
                cin>>x;
                if (x == 1)
                {
                    cout<<endl<<"May hoat dong!";
                    y = 500;
                    check = false;
                }
                else if (x == 2)
                {
                    cout<<endl<<"May hoat dong!";
                    y = 800;
                    check = false;
                }
                else if (x == 3)
                {
                    cout<<endl<<"May hoat dong!";
                    y = 1000;
                    check = false;
                }
                else
                {
                    cout<<endl<<"Khong co chuc nang nay! - Hay nhap lai: ";
                }
            }
            return y;
        }
        int Chonmaybom()
        {
            int pump;
            cout<<endl<<"So may bom ban muon su dung la: ";
            cin>>pump;
            return pump;
        }
};
WateringSystem *inputSystem(WateringSystem &tc, WateringSystem *&cuoi, WateringSystem *&ds)
{
    system("cls");
    char con = 'c';
    while (con == 'c')
    {

        WateringSystem *node = new WateringSystem;
        node->ChoosePlant();
        node->plantName();
        node->plantArea();
        node->input_Moistune();
        node->inputTemperatune();
        node->plantLn();
        node->next = NULL;

        if (ds == NULL)
        {
            ds = node;
            cuoi = node;
        }
        else
        {
            cuoi->next = node;
            cuoi = node;
        }
        cout<<endl<<"Ban co muon tiep tuc hay khong? (yes= 'c' to-> Co, no= 'k' to -> Khong): ";
        cin>>con;
    }
    cout<<"Hoan tat qua trinh nhap thong tin!"<<endl;
    return cuoi, ds;
}
void PlantList(WateringSystem &tc, WateringSystem *&cuoi, WateringSystem *&ds)
{
    system("cls");
    cout<<endl<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"<<endl;
    cout<<setw(39)<<left<<"┃"<<"DANH SACH CAY TRONG"<<setw(42)<<right<<"┃";
    cout<<endl<<"┣━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━┫";
    cout<<endl<<setw(20)<<"┃     Ten cay      ┃"<<setw(19)<<"     Loai cay     ┃"<<setw(18)<<" Do am can thiet ┃"<<setw(21)<<" Nhiet do can thiet ┃"<<setw(18)<<" Dien tich trong ┃";
    cout<<endl<<"┣━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━┫";

    cuoi = ds;
    while (cuoi != NULL)
    {
        /*
        cout << setw(MAX_HORIZONTAL) << cuoi->getName() << setw(MAX_HORIZONTAL - strlen(cuoi->getName())) << delimiter;
        cout << setw(MAX_HORIZONTAL) << cuoi->TypePlant() << setw(MAX_HORIZONTAL - strlen(cuoi->TypePlant())) << delimiter;
        cout << setw(MAX_HORIZONTAL) << cuoi->getMoistune() << setw(MAX_HORIZONTAL - strlen(cuoi->getMoistune())) << delimiter;
        cout << setw(MAX_HORIZONTAL) << cuoi->getTemperatune() << setw(MAX_HORIZONTAL - strlen(cuoi->getTemperatune())) << delimiter;
        cout << setw(MAX_HORIZONTAL) << cuoi->getArea() << setw(MAX_HORIZONTAL - strlen(cuoi->getArea())) << delimiter;
        */
        cout<<endl<<"┃"; cout<<setw(18)<<left;  cuoi->getName();
        cout<<"┃"; cout<<setw(18); cuoi->TypePlant();
        cout<<setw(9)<<left<<"┃"; cuoi->getMoistune(); cout<<setw(8)<<right<<" ";
        cout<<setw(8)<<left<<"┃"; cuoi->getTemperatune(); cout<<setw(8)<<right<<" ";
        cout<<setw(7)<<left<<"┃"; cuoi->getArea(); cout<<setw(7)<<right<<"┃";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━┫";
        cuoi = cuoi->next;
    }
    cout<<endl<<"┗━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┛";
}
void showCurrentStatus(WateringSystem &tc, WateringSystem *&cuoi, WateringSystem *&ds)
{
    cout<<endl<<"Danh sach cay sau khi nhap: "<<endl;
    cuoi = ds;
    while (cuoi != NULL)
    {
        cout<<endl<<"Ten: ";
        cuoi->getName();
        cout<<endl<<"Loai cay: ";
        cuoi->TypePlant();
        cuoi->inputCurr_Moist();
        cuoi->showCur_Moistune();
        cuoi->inputCurr_Temper();
        cuoi->showCur_Temperatune();
        cuoi = cuoi->next;
    }
    cout<<endl<<"Hoan tat qua trinh thiet lap trang thai hien tai!";
}
void Smart_Watering(WateringSystem &tc, WateringSystem *&cuoi, WateringSystem *&ds)
{
    system("cls");
    cuoi = ds;
    while (cuoi != NULL)
    {
        cout<<endl<<"Ten: ";
        cuoi->getName();
        cout<<endl<<"Loai cay: ";
        cuoi->TypePlant();
        cout<<endl<<"Dien tich trong: ";
        cuoi->getArea();
        cuoi->SmartWatering();
        cuoi = cuoi->next;
        cout<<endl<<"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    }
    cout<<endl<<"Hoan tat tuoi thong minh - May tro ve trang thai nghi!";
}
void Optional_Watering(WateringSystem &tc, WateringSystem *&cuoi, WateringSystem *&ds)
{
    system("cls");
    cuoi = ds;
    while (cuoi != NULL)
    {
        cout<<endl<<"Ten: ";
        cuoi->getName();
        cout<<endl<<"Loai cay: ";
        cuoi->TypePlant();
        cout<<endl<<"Dien tich trong: ";
        cuoi->getArea();
        cuoi->OptionalWatering();
        cuoi = cuoi->next;
        cout<<endl<<"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    }
    cout<<endl<<endl<<"Hoan tat tuoi tuy chon - May tro ve trang thai nghi!";
}
void Timer()
{
    system("cls");
    int key;
    int a;
    while (true)
    {

        cout<<endl<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
        cout<<endl<<"┣━━━━━━━━━━━━Thiet lap tuy chon━━━━━━━━━━━━┫";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
        cout<<endl<<"┃(1) Hen gio tuoi                          ┃";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
        cout<<endl<<"┃(0) Quay lai                              ┃";
        cout<<endl<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
        cout<<endl<<endl<<"Nhap lua chon cua ban: ";
        cin>>key;
        switch (key)
        {
        case 0:
            return;
            break;
        default:
            cout<<endl<<"Khong co chuc nang nay!";
            cout<<endl<<"Moi ba nhap lai!";
            break;
        case 1:
            cout<<endl<<"Luong nuoc ban muon tuoi (m^3): ";
            cin>>b;
            idti = 1;

            cout<<"Nhap thoi gian hen gio tuoi: ";
            thread clock;
            clock = thread(printClock);
            if (clock.joinable())
            {
                clock.join();

            }
            //clock.detach();
        }

    }
}
void mainMenu(WateringSystem &tc, WateringSystem *&cuoi, WateringSystem *&ds)
{
    int key;
    while (true)
    {
        system("cls");

        cout<<endl<<"╔═════════════════════════════════════════╗";
        cout<<endl<<"║             BANG DIEU KHIEN             ║";
        cout<<endl<<"╚═════════════════════════════════════════╝";

        cout<<endl<<endl<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
        cout<<endl<<"┃(1) Thiet lap thong tin cay              ┃";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
        cout<<endl<<"┃(2) Thiet lap trang thai hien tai cay    ┃";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
        cout<<endl<<"┃(3) Danh sach cay trong                  ┃";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
        cout<<endl<<"┃(4) Tuoi nuoc thong minh                 ┃";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
        cout<<endl<<"┃(5) Tuoi nuoc tuy chon                   ┃";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
        cout<<endl<<"┃(6) Hen gio tuoi                         ┃";
        cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
        cout<<endl<<"┃(0) Thoat chuong trinh                   ┃";
        cout<<endl<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

        cout<<endl<<endl<<"Nhap lua chon cua ban : ";
        cin >> key;
        switch (key)
        {
        case 1:
            inputSystem(tc, cuoi, ds);
            cout<<endl<<"Bam phim bat ki de tro lai bang dieu khien!";
            getch();
            break;
        case 2:
            system("cls");
            showCurrentStatus(tc, cuoi, ds);
            cout<<endl<<"Bam phim bat ki de tro lai bang dieu khien!";
            getch();
            break;
        case 3:
            PlantList(tc, cuoi, ds);
            cout<<endl<<"Bam phim bat ki de tro lai bang dieu khien!";
            getch();
            break;
        case 4:
            Smart_Watering(tc, cuoi, ds);
            cout<<endl<<"Bam phim bat ki de tro lai bang dieu khien!";
            getch();
            break;
        case 5:
            Optional_Watering(tc, cuoi, ds);
            cout<<endl<<"Bam phim bat ki de tro lai bang dieu khien!";
            getch();
            break;
        case 6:
            Timer();
            cout<<endl<<"Bam phim bat ki de tro lai bang dieu khien!";
            getch();
            break;
        case 0:
            cout<<endl<<"Ban da chon thoat chuong trinh!";
            cout<<endl<<"Bye. See you later <3";
            getch();
            return;
        default:
            cout<<endl<<"Khong co chuc nang nay!";
            cout<<endl<<"Ba m phim bat ki de tiep tuc!";
            getch();
            break;
        }
    }
};
void hihi()
{
    cout<<endl<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
    cout<<endl<<"┃                                          BAI TAP LON Oop                                         ┃";
    cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
    cout<<endl<<"┃ Nhom: 3                                                                                          ┃";
    cout<<endl<<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
    cout<<endl<<"┃ Thanh vien: Tran The Anh                                                                         ┃";
    cout<<endl<<"┃             Tran Manh Ha                                                                         ┃";
    cout<<endl<<"┃             Luong Thi Mai Linh                                                                   ┃";
    cout<<endl<<"┃             Nguyen Tien Phong                                                                    ┃";
    cout<<endl<<"┃             Luc Doan Cao Thien                                                                   ┃";
    cout<<endl<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
}
int main()
{
    SetConsoleCtrlHandler((PHANDLER_ROUTINE)close, TRUE);
    SetConsoleTitle("HE THONG TUOI VUON");
    SetConsoleOutputCP(65001);
    hihi();
    getch();
    system("cls");
    WateringSystem tc;
    WateringSystem *ds = NULL;
    WateringSystem *cuoi = NULL;
    mainMenu(tc, cuoi, ds);
    system("pause");
    return 0;
}
