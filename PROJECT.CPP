/*Program to demonstrate Student's Registration and Displaying Stuent Detail*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;
// A Class defition of student
class Student
{
    // data hidden from the outside world
    int r_no;
    char reg_no[15], s_nm[30], f_nm[30], m_nm[30], std[11], mob[11];
    int marks_X, marks_XII;

public:
    // Function Declaration year that return last two digit of year
    int Year();
    // Function Declaration of Student to be displayed
    void Display(int, int);
    // Functiont Declaration of Student to be Searched
    Student Search(char[], int &flag);
    // Functiont Declaration of Student to be Modify
    void Modify(char[], int &flag);
    // Functiont Declaration of Student to be Delete
    void Delete(char[], int &flag);

    // Function to get student name
    void S_Nm()
    {
        cout << "Enter the Student Name:\n";
        gets(s_nm);
        for (int i = 0; i < strlen(s_nm); i++)
        {
            s_nm[i] = toupper(s_nm[i]);
        }
    }
    // getting father student name
    void F_Nm()
    {
        cout << "Enter the Student Father's Name:\n";
        gets(f_nm);
        for (int i = 0; i < strlen(f_nm); i++)
        {
            f_nm[i] = toupper(f_nm[i]);
        }
    }
    // getting mother student name
    void M_Nm()
    {
        cout << "Enter the Student Mother's Name:\n";
        gets(m_nm);
        for (int i = 0; i < strlen(m_nm); i++)
        {
            m_nm[i] = toupper(m_nm[i]);
        }
    }
    // getting student phone number
    void P_N0()
    {
        do
        {
            cout << "Enter the Student Phone Number:\n";
            cin >> mob;
            // checking where student phone number is 10 digit or not
            if (strlen(mob) != 10)
            {
                cout << "Incorrect!!! Please Reinter Phone Number\n";
            }
        } while (strlen(mob) != 10);
    }
    // getting student class
    void C_Nm()
    {
        cout << "Enter the Class of Student:\n";
        cin.ignore();
        gets(std);
        for (int i = 0; i < strlen(std); i++)
        {
            std[i] = toupper(std[i]);
        }
    }
    // getting student xth marks
    void M_X()
    {
        do
        {
            cout << "Enter the Marks of Student in (class X):\n";
            cin >> marks_X;
            // checking student xth marks is less than or equal to 600 or not
            if (marks_X > 600)
            {
                cout << "Incorrect marks!!!, Please reinter your marks of Class 10th\n";
            }
        } while (marks_X > 600);
    }
    // getting student xiith marks
    void M_XII()
    {
        do
        {
            cout << "Enter the Marks of Student in (class XII):\n";
            cin >> marks_XII;
            // checking student xiith marks is less than or equal to 600 or not
            if (marks_XII > 600)
            {
                cout << "Incorrect marks!!!, Please Reinter your marks of class 12th\n";
            }
        } while (marks_XII > 600);
    }
    // Member Function to get Student Details
    void GetData(int t = 0)
    {
        // calling of function get student name
        S_Nm();
        // calling of function get student father's name
        F_Nm();
        // calling of function get student Mother's name
        M_Nm();
        // calling Student phone number
        P_N0();
        // calling of function get Student Class
        C_Nm();
        // Calling of function get student X marks
        M_X();
        // Calling of function get student XII marks
        M_XII();
        // Increment Registration by 1
        r_no = t + 1;
    }
    // Function to create Registraiton number
    void Reg()
    {
        int yr = Year();
        char year[3];
        sprintf(year, "%d", yr);
        char roll[4];
        sprintf(roll, "%03d", r_no);
        strcpy(reg_no, year);
        strcat(reg_no, "BZVGCS");
        strcat(reg_no, roll);
        strcat(reg_no, "/");
        strcat(reg_no, year);
    }
    // Function to get serial number
    int GetSerial()
    {
        return r_no;
    }
};

// funtion to display student data
void Student ::Display(int tmp, int i)
{
    if (i == 0)
    {
        cout << right << (char)201 << setw(17) << setfill((char)205) << char(203) << setw(21) << setfill((char)205) << char(203) << setw(21) << setfill((char)205) << char(203) << setw(21) << setfill((char)205) << char(203) << setw(11) << setfill((char)205) << char(203) << setw(11) << setfill((char)205) << char(203) << setw(11) << setfill((char)205) << char(203) << setw(12) << setfill((char)205) << char(187) << setfill(' ') << endl;
        cout << left << (char)186 << setw(16) << "Registration No." << (char)186 << setw(20) << "Student Name" << (char)186 << setw(20) << "Father's Name" << (char)186 << setw(20) << "Mother's Name" << (char)186 << setw(10) << "Class" << (char)186 << setw(10) << "Mobile No." << (char)186 << setw(10) << "Marks (X)" << (char)186 << setw(11) << "Marks (XII)" << (char)186 << endl;
        cout << right << (char)204 << setw(17) << setfill((char)205) << char(206) << setw(21) << setfill((char)205) << char(206) << setw(21) << setfill((char)205) << char(206) << setw(21) << setfill((char)205) << char(206) << setw(11) << setfill((char)205) << char(206) << setw(11) << setfill((char)205) << char(206) << setw(11) << setfill((char)205) << char(206) << setw(12) << setfill((char)205) << char(185) << setfill(' ') << endl;
    }
    cout << left << (char)186 << setw(16) << reg_no << (char)186 << setw(20) << s_nm << (char)186 << setw(20) << f_nm << (char)186 << setw(20) << m_nm << (char)186 << setw(10) << std << (char)186 << setw(10) << mob << (char)186 << setw(10) << marks_X << (char)186 << setw(11) << marks_XII << (char)186 << endl;
    if (r_no != tmp)
    {
        cout << right << (char)204 << setw(17) << setfill((char)205) << char(206) << setw(21) << setfill((char)205) << char(206) << setw(21) << setfill((char)205) << char(206) << setw(21) << setfill((char)205) << char(206) << setw(11) << setfill((char)205) << char(206) << setw(11) << setfill((char)205) << char(206) << setw(11) << setfill((char)205) << char(206) << setw(12) << setfill((char)205) << char(185) << setfill(' ') << endl;
    }
    else
    {
        cout << right << (char)200 << setw(17) << setfill((char)205) << char(202) << setw(21) << setfill((char)205) << char(202) << setw(21) << setfill((char)205) << char(202) << setw(21) << setfill((char)205) << char(202) << setw(11) << setfill((char)205) << char(202) << setw(11) << setfill((char)205) << char(202) << setw(11) << setfill((char)205) << char(202) << setw(12) << setfill((char)205) << char(188) << setfill(' ') << endl;
    }
}

// Member Function to Search a Student
Student Student ::Search(char str[], int &flag)
{
    Student std;
    ifstream infile;
    infile.open("STUDENT_RECORD.DAT", ios ::in | ios::binary);
    while (infile.read((char *)&std, sizeof(std)))
    {
        if (strcmp(std.s_nm, str) == 0)
        {
            flag = 1;
            break;
        }
    }
    infile.close();
    return std;
}

// Member funciton to modify particular data of student
void Student ::Modify(char name[], int &flag)
{
    Student std;
    int choice;
    ifstream infile("STUDENT_RECORD.DAT", ios ::in | ios ::binary);
    ofstream outfile("Record.DAT", ios::out | ios::app | ios::binary);
    while (infile.read((char *)&std, sizeof(std)))
    {
        if (strcmp(std.s_nm, name) == 0)
        {
            std.Display(std.GetSerial(), 0);
            cout << "Update Student's Record:" << endl
                 << "0. EXIT" << endl
                 << "1. Name" << endl
                 << "2. Father's Name" << endl
                 << "3. Mother's Name" << endl
                 << "4. Phone Number" << endl
                 << "5. Class" << endl
                 << "6. Marks (X)"
                 << "7. Marks (XII)" << endl
                 << ".....";
            cin >> choice;
            cin.ignore();
            switch (choice)
            {
            case 0:
                exit(-1);
                break;
            case 1:
                std.S_Nm();
                break;
            case 2:
                std.F_Nm();
                break;
            case 3:
                std.M_Nm();
                break;
            case 4:
                std.P_N0();
                break;
            case 5:
                std.C_Nm();
                break;
            case 6:
                std.M_X();
                break;
            case 7:
                std.M_XII();
                break;
            default:
                cout << "Invalid Input";
            }
            // file.seekp(-sizeof(std), ios::cur);
            // file.write((char *)&std, sizeof(std));
            flag = 1;
        }
        outfile.write((char *)&std, sizeof(std));
    }
    infile.close();
    outfile.close();
    remove("STUDENT_RECORD.DAT");
    rename("Record.DAT", "STUDENT_RECORD.DAT");

}

// Member function to Delete a particular student
void Student ::Delete(char nm[], int &flag)
{
    Student std;
    ifstream infile("STUDENT_RECORD.DAT", ios::in | ios::binary);
    if (!infile)
    {
        cout << "Unable to open file\n";
        return;
    }
    ofstream outfile("Record.DAT", ios::out | ios::binary);
    while (infile.read((char *)&std, sizeof(std)))
    {

        if (strcmp(std.s_nm, nm) == 0)
        {
            flag = 1;
            std.Display(std.r_no, 0);
            continue;
        }
        outfile.write((char *)&std, sizeof(std));
    }
    infile.close();
    outfile.close();
    remove("STUDENT_RECORD.DAT");
    rename("Record.DAT", "STUDENT_RECORD.DAT");
}

// Function to get current year of last two digit
int Student ::Year()
{
    time_t t = time(0);
    tm *ltm = localtime(&t);
    int tmp_dt = 1900 + ltm->tm_year;
    int dt = 0, tmp, i = 2;
    // loop to get last two digit of current year and it will be reversed
    while (i--)
    {
        tmp = tmp_dt % 10;
        dt = dt * 10 + tmp;
        tmp_dt /= 10;
    }
    i = 2;
    int date = 0; // loop to arrange in proper year which is reversed in last loop
    while (i--)
    {

        tmp = dt % 10;
        date = date * 10 + tmp;
        dt /= 10;
    }
    return date;
}

// Declaration of MS college shown in rectangular box
int ShowMS();

// print text in center
void Center(char str[]);

// Definition of Main Fuction
int main()
{
    Student stud;
    ifstream infile;
    int total_serial;
    char choice;
    while (1)
    {
        system("cls");
        total_serial = 0;
        // shows Ms College chandmari motihari
        ShowMS();
        cout << "0. EXIT" << endl
             << "1. DISPLAY" << endl
             << "2. REGISTER" << endl
             << "3. SEARCH" << endl
             << "4. MODIFY" << endl
             << "5. DELETE" << endl
             << endl
             << "Please Enter your choice" << endl
             << ".....";
        cin >> choice;
        cin.ignore();
        // check last registration number of student
        infile.open("STUDENT_RECORD.DAT", ios ::in | ios ::binary);
        if (infile)
        {
            while (infile.read((char *)&stud, sizeof(stud)))
            {
                // Loop to get last registration of student
                total_serial = stud.GetSerial();
            }
        }
        infile.close();
        switch (choice)
        {
        // Exit
        case '0':
        {
            exit(1);
            break;
        }
        // Displaying all Student detail
        case '1':
        {
            system("cls");
            ShowMS();
            int i = 0;
            char s_r[] = "STUDENT RECORD";
            char r_n_f[] = "Record Not Found";
            if (total_serial == 0)
            {
                Center(r_n_f);
            }
            else
            {
                Center(s_r);
                ifstream infile;
                infile.open("STUDENT_RECORD.DAT", ios ::in | ios ::binary);
                while (infile.read((char *)&stud, sizeof(stud)))
                {
                    stud.Display(total_serial, i);
                    i++;
                }
                infile.close();
            }
            Center((char*)"Press any key to continue...");
            getch();
            break;
        }
        // Student Registration
        case '2':
        {
            char str[] = "Registration Form";
            system("cls");
            ShowMS();
            Center(str);
            stud.GetData(total_serial);
            stud.Reg();
            ofstream outfile;
            outfile.open("STUDENT_RECORD.DAT", ios::out | ios::app | ios ::binary);
            outfile.write((char *)&stud, sizeof(stud));
            outfile.close();
            Center((char*)"Press any key to continue...");
            getch();
            break;
        }
        // Student Searching
        case '3':
        {
            int flag = 0;
            char st_nm[30];
            char r_n_f[] = "Record Not Found";
            char str[50] = "STUDENT RECORD OF ";
            system("cls");
            ShowMS();
            cout << "Enter Student Name to search:\n";
            gets(st_nm);
            for (int i = 0; i < strlen(st_nm); i++)
            {
                st_nm[i] = toupper(st_nm[i]);
            }
            stud = stud.Search(st_nm, flag);
            system("cls");
            ShowMS();
            if (flag)
            {
                strcat(str, st_nm);
                Center(str);
                stud.Display(stud.GetSerial(), 0);
            }
            else
            {
                Center(r_n_f);
            }
            getch();
            Center((char*)"Press any key to continue...");
            break;
        }
        // Student Modification
        case '4':
        {
            int flag = 0;
            char st_nm[30];
            char r_n_f[] = "Record Not Found";
            char str[50] = "Student Modified Sucessfully - ";

            system("cls");
            ShowMS();
            cout << "Enter Student Name to Search \n";
            gets(st_nm);
            for (int i = 0; i < strlen(st_nm); i++)
            {
                st_nm[i] = toupper(st_nm[i]);
            }
            stud.Modify(st_nm, flag);
            system("cls");
            ShowMS();
            if (flag)
            {
                strcat(str, st_nm);
                Center(str);
            }
            else
            {
                Center(r_n_f);
            }
            Center((char*)"Press any key to continue...");
            getch();
            break;
        }
        // Student Deletion
        case '5':
        {
            int flag = 0;
            char st_nm[30];
            char r_n_f[] = "Record Not Found";
            char str[50] = "Student Record Deleted Sucessfully - ";
            system("cls");
            ShowMS();
            cout << "Enter Student Name to Delete: \n";
            gets(st_nm);
            for (int i = 0; i < strlen(st_nm); i++)
            {
                st_nm[i] = toupper(st_nm[i]);
            }
            system("cls");
            ShowMS();
            stud.Delete(st_nm, flag);
            if (flag)
            {
                strcat(str, st_nm);
                Center(str);
            }
            else
            {
                Center(r_n_f);
            }
            Center((char*)"Press any key to continue...");
            getch();
            break;
        }
        default:
            Center((char *)"Invalid Input");
            getch();
        }
    }
    return 0;
}

// Definition of print Ms College in rectangular box
int ShowMS()
{
    string ms = "MUNSHI SINGH COLLEGE";
    string ms_ad = "Chandmari Motihari, BIHAR - 845401";
    int l1 = ms.length();
    int l2 = ms_ad.length();
    int l_ms, l_ms_ad;
    l_ms = (124 / 2) - (l1 / 2);
    l_ms_ad = (124 / 2) - (l2 / 2);
    cout << (char)201 << setw(125) << setfill((char)205) << char(187) << setfill(' ') << endl;
    // Show Munshi Singh College
    if (l1 % 2 == 0)
    {
        cout << (char)186 << setw(l_ms) << setfill(' ') << char(32) << ms << char(32) << setw(l_ms) << (char)186 << endl;
    }
    else
    {
        cout << (char)186 << setw(l_ms) << setfill(' ') << char(32) << ms << setw(l_ms) << (char)186 << endl;
    }
    // chandmari, motihari Bihar-845401
    if (l2 % 2 == 0)
    {
        cout << (char)186 << setw(l_ms_ad) << setfill(' ') << char(32) << ms_ad << char(32) << setw(l_ms_ad) << (char)186 << endl;
    }
    else
    {
        cout << (char)186 << setw(l_ms_ad) << setfill(' ') << char(32) << ms_ad << setw(l_ms_ad) << (char)186 << endl;
    }
    cout << (char)200 << setw(125) << setfill((char)205) << char(188) << setfill(' ') << endl;
    return 0;
}

// Definition of Function used to print string in center
void Center(char str[])
{
    int len = strlen(str);
    int len_2 = (126 / 2) - len / 2;
    if (len % 2 == 0)
    {
        cout << setw(len_2) << setfill(' ') << char(32) << str << setw(len_2) << char(32) << endl;
    }
    else
    {
        cout << setw(len_2) << setfill(' ') << char(32) << str << setw(len_2 - 1) << char(32) << endl;
    }
}