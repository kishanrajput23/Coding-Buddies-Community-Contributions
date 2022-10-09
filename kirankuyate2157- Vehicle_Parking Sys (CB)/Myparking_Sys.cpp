#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

bool login()
{
    char u[200] = "Admin", p[200] = "1234567";
    char u2[200] = "kiran", p2[200] = "kiran";
    char u1[200], p1[200];
    cout << "\n\n\n\t\t\t\t\t Parking Reservation System Login";
    cout << "\n\t*********************************************************************************************";
    cout << "\n\t\t\t\t\t\tEnter Username: ";
    cin >> u1;
    cout << "\n\t\t\t\t\t\tEnter Password: ";
    cin >> p1;
    cout << "\n\t*********************************************************************************************";

    if ((strcmp(u, u1) == 0 && strcmp(p, p1) == 0) || strcmp(u2, u1) == 0 && strcmp(p2, p1) == 0)
    {

        cout << "\n\t.%%..%%..%%..%%..........%%%%%....%%%%...%%%%%...%%..%%..%%%%%%..%%..%%...%%%%..\n";
        cout << "\t.%%.%%...%%.%%...........%%..%%..%%..%%..%%..%%..%%.%%.....%%....%%%.%%..%%.....\n";
        cout << "\t.%%%%....%%%%............%%%%%...%%%%%%..%%%%%...%%%%......%%....%%.%%%..%%.%%%.\n";
        cout << "\t.%%.%%...%%.%%...........%%......%%..%%..%%..%%..%%.%%.....%%....%%..%%..%%..%%.\n";
        cout << "\t.%%..%%..%%..%%..........%%......%%..%%..%%..%%..%%..%%..%%%%%%..%%..%%...%%%%..\n";
        cout << "\t................................................................................\n";

        cout << "\n\t\t\t\t\t✅✅ Login is Successful";

        cout << "\n\n\n--------------------------------🚗🚐🚎  WELCOME TO SMART VEHICLE PARKING SYSTEM 🚙🚚🚍------------------------------------";
        cout << "\n";
        cout << "\n\nMAXIMUM PARKING CAPACITY AND PARKING CHARGES W.R.T VEHICLE SPECIFICATION";
        cout << "\n";
        cout << "\n\1. Maximum car parking(100), charge per car 50₹";
        cout << "\n\2. Maximum Truck parking(50) , Charge per Truck 100₹ ";
        cout << "\n\3. Maximum Bicycle parking(120), Charge per Bicycle 20₹";
        cout << "\n\4. Maximum Rickshaw parking(20), Charges per Rickshaw 40₹";
        return true;
    }
    else
    {
        cout << "\n\n\t\t\t\tOooppssss !!! You have entered wrong Credentials! 🔴\t";

        return false;
    }
}
string timeNow()
{
    string resTime = "";
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, " %I:%M%p", timeinfo);
    resTime.append(buffer);
    strftime(buffer, 80, " %d-%m-%Y", timeinfo);
    resTime.append(buffer);
    return resTime;
}
float vCharges(float time, int vType)
{
    float tch = 0;
    if (vType == 1)
    {
        tch += time * 20;
    }
    else if (vType == 2)
    {
        tch += time * 40;
    }
    else if (vType == 3)
    {
        tch += time * 50;
    }
    else if (vType == 4)
    {
        tch += time * 100;
    }
    return tch;
}
class id
{
public:
    bool status = false;
    string num = "-- ---";
    string name = "--- --";
    int vtype = 0;
    void takeDetail()
    {
        status = true;
        cout << "\t\tplease fill free to share littlebit information !!\n";
        cout << "\t\twhat's your name ?\n\t\t ... ";

        cin >> name;
        cout << "\t\tPhone No ?\n\t\t... ";
        cin >> num;
        cout << "\n\t\tvehicle type :\n\t\t\t1.Two wheeler bike.\n\t\t\t2.Three wheeler vehicles.\n\t\t\t3.Four wheeler vehicles(Car type).\n\t\t\t4.four and more wheeler vehicles(truck type).\n\t\t...";
        cin >> vtype;
        cout << "\n\t\t";
    }
};

class slot
{
public:
    bool status;
    int charges;
    string entryT;
    float parkTime;
    string exitT;
    string UserName;
    string plateNO;
    string uid;
    id ent;

    slot()
    {
        status = false;
        entryT = "0:0:0";
        exitT = "0:0:0";
        parkTime = 0;
        charges = 0;
        UserName = "-------";
        plateNO = "-------";
        uid = " ----- ----- ";
    }

    void makeEntry(id x)
    {
        cout << "\n\t\tmake entry : ";
        status = x.status;
        cout << " please park time : ";
        cin >> parkTime;
        entryT = timeNow();
        charges = vCharges(parkTime, x.vtype);
        UserName = x.name;
        cout << "\n\t\tenter Vehicle Plate number :\n\t\t... ";
        cin >> plateNO;
        uid = x.num;
    }

    void makeExit()
    {
        status = false;
        entryT = "0:0:0";
        exitT = "0:0:0";
        charges = 0;
        UserName = "-------";
        plateNO = "-------";
        uid = " ----- ----- ";
    }
    void showDetail()
    {
        cout << "\tUser Name : " << UserName << "\n";
        cout << "\tUser id : " << uid << "\n";
        cout << "\tStatus : ";
        if (status == true)
            cout << "Activated\n";
        else
            cout << "Deactivated\n";
        cout << "\tEntry Time : " << entryT << "\n";
        cout << "\tExit Time : " << exitT << "\n";
        cout << "\tCharge : " << charges << "₹\n";
        cout << "\tPlate No : " << plateNO << "\n";
    }
    void showExDetail()
    {
        exitT = timeNow();
        cout << "\tUser Name : " << UserName << "\n";
        cout << "\tUser id : " << uid << "\n";
        cout << "\tStatus : ";
        if (status == true)
            cout << "Activated\n";
        else
            cout << "Deactivated\n";
        cout << "\tEntry Time : " << entryT << "\n";
        cout << "\tExit Time : " << exitT << "\n";
        cout << "\tCharge : " << charges << "₹\n";
        cout << "\tPlate No : " << plateNO << "\n";
    }
};

class parkLon
{
private:
    // vector < vector<slot> Area(16,vector<slot>(10);
    slot Area[16][10];
    int curentered = 0;
    int tCnt = 0;
    int earned = 0;

public:
    // while entering car
    id veh;
    void verify()
    {
        cout << "\n\t\tplease verify identity\n";

        veh.takeDetail();
    }
    void enter()
    {
        bool isDone = false;
        for (int i = 0; i < 16; i++)
        {
            if (isDone == true)
                break;
            for (int j = 0; j < 10; j++)
            {
                if (Area[i][j].status == false)
                {
                    Area[i][j].makeEntry(veh);
                    cout << "\t\t take your slips >>>  \n";
                    isDone = true;
                    cout << "\n-----------------------------------------------------\n";
                    Area[i][j].showDetail();
                    cout << "\t\t done 👍 !";
                    cout << "\n-----------------------------------------------------\n";
                    curentered++;
                    tCnt++;
                    earned += Area[i][j].charges;
                    break;
                }
            }
        }
    }

    void showpark()
    {
        cout << "\n_____________________________________________________________\n";
        for (int i = 0; i < 16; i++)
        {
            if (i == 2)
                cout << " Enter --> ";
            else
                cout << "\t   ";
            for (int j = 0; j < 10; j++)
            {
                if (Area[i][j].status == true)
                    cout << "🟩 ";
                else
                    cout << "🟧 ";
            }
            cout << "\n";
            if (i == 15)
                cout << "\n<-- Exit\t\t\t\t\t\t Exit -->";
        }
        cout << "\n______________________________________________________________\n";
    }

    void exit()
    {
        bool isDoneE = false;
        for (int i = 0; i < 16; i++)
        {
            if (isDoneE == true)
                break;
            for (int j = 0; j < 10; j++)
            {
                if (Area[i][j].status == true)
                {
                    cout << "Host: " << Area[i][j].ent.name << "  user :" << veh.name << "\n";
                    Area[i][j].status = false;
                    cout << "\t\t take your slips >>>  \n";
                    isDoneE = true;
                    cout << "\n-----------------------------------------------------\n";
                    Area[i][j].showExDetail();
                    cout << "\t\t done 👍 !";
                    cout << "\n-----------------------------------------------------\n";
                    Area[i][j].makeExit();
                    curentered--;
                    break;
                }
            }
        }
        if (isDoneE == false)
        {
            isDoneE = true;
            cout << "\n-----------------------------------------------------\n";
            cout << "\tfor this name no entry exist ! ";
            cout << "\n-----------------------------------------------------\n";
        }
    }

    void totalEars()
    {
        cout << "\n-----------------------*------------------------------\n";
        cout << "\t\tCar lon Earning is " << earned;
        cout << "\n-----------------------------------------------------\n";
    }
    void curEntry()
    {
        cout << "\n------------------------*-----------------------------\n";
        cout << "\t\tcurrent vehicles  " << curentered << "  parked ";
        cout << "\n-----------------------------------------------------\n";
    }
};

int main()
{
    bool start = false, access = true;
    int t = 0;
    while (!start && t < 5)
    {
        start = login();
        t++;
    }
    if (!start)
    {
        cout << "\n\t\t__________________________________________________________________\n\n";
        cout << "  \t\tAttempt of login failed or limit exceeded ! 🔴🔴🔴 \n";
        access = false;
        cout << "\t\t__________________________________________________________________\n";
    }
    if (access)
    {
        cout << "\n\n\t\t* KK SMART PARKING SYSTEM *\n";
        parkLon A;
        int ch, flg = 1;
        while (flg)
        {
            cout << "\n\t\t\t  1. Arrival of a Car";
            cout << "\n\t\t\t  2. Total no of cars Arrived";
            cout << "\n\t\t\t  3. Total parking charges of all cars with details";
            cout << "\n\t\t\t  4. Departure of the car";
            cout << "\n\t\t\t  5. Show Parking";
            cout << "\n\t\t\t  6. Stop system ";
            cout << "\n\t\t.... ";
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                A.verify();
                A.enter();
                break;
            }
            case 2:
            {
                A.curEntry();
                break;
            }
            case 3:
            {
                A.totalEars();
                break;
            }
            case 4:
            {
                A.verify();
                A.exit();
                break;
            }
            case 5:
            {
                A.showpark();
            }
            case 6:
            {
                cout << "\n\t\twhile you stop all data will reset! confirm y/n ? ...  ";
                char b;
                cin >> b;
                if (b == 'y' || b == 'Y')
                    flg = 0;
                cout << "\n\t\t Have Nice Day, Thank You!\n\n";
                break;
            }
            default:
                cout << "\t\tERROR please enter valid input !!\n";
            }
        }
    }
    return 0;
    getch();
}
