#include <iostream>
#include <string>
#include<fstream>
using namespace std;

const int maxrow=10;

string EmpName [maxrow]={};
string EmpID[maxrow]={};

void AddRecord() {
    char name[50];
    char empno[5];

    cin.ignore();

    cout << "Book ID: ";
    cin.getline(empno, 5);
    cout << "Book Name: ";
   cin.getline(name, 50);

 for (int x = 0; x < maxrow; x++)
 {
    if(EmpID[x] == "\0")
    {
        EmpID[x] = empno;
        EmpName[x] = name;
        break;
    }
 }
}

void ListRecord()
{
system("CLS");
cout << "Current Record(s)" <<endl;
cout << "============================" << endl;
int counter = 0;
cout << " No. |    ID    |      Book NAME    " << endl << "============================\n";
for (int x = 0; x < maxrow; x++)
{
    if (EmpID[x] != "\0")
    {
        
    counter++;
    cout << " " << counter << "        " << EmpID[x] << "          " << EmpName[x] << endl;

    }
if (counter == 0)
    {
        cout << "No Record found!" << endl;
    }

    cout << "============================" << endl;

}
}

void SearchRecord(string search)
{
   system("CLS");
   cout << "Current Record(s)" << endl;
   cout << "============================" << endl;
   
   int counter = 0;
   for (int x = 0; x < maxrow; x++)            
   {   

      if (EmpID[x] == search)
       {
      counter++;
      cout << " " << counter << "        " << EmpID[x] << "          " << EmpName[x] << endl;
      break;
       }
    }
    
    if (counter == 0)
    {
    cout << "No Record found!" << endl;
    }
     cout << "-----------------------------" << endl;
}

void UpdateRecord(string search)
{
char name[50];
char empno[5];

int counter = 0;

for (int x = 0; x < maxrow; x++)
{
    if (EmpID[x] == search)
    {
        counter++;

        cout << "Book Name: ";
        cin.getline(name, 50);

        EmpName [x] = name;

        cout << "Update Successfull!" << endl;
        break;
    }
}
}

void DeleteRecord(string search)
{
    int counter = 0;

    for (int x = 0; x < maxrow; x++)
{
    if (EmpID[x] == search)
    {

        counter++;
        EmpName [x] = " ";
        EmpID[x] = " ";
        cout << "Successfully Deleted!" << endl;
        break;
    }
if (counter == 0)
{
    cout << "Book Number does not exist!";
}
}
}
int main()
{
    std::cout << "MENU\n";
    int option;
    string empID;
    system("CLS");

    do{
    cout << "1-Insert book in the library" << endl;
    cout << "2-Update book" <<endl;
    cout << "3-Delete book" << endl;
    cout << "4-Search book" <<endl;
    cout << "5-Display all book" << endl;
    cout << "6-Exit..." << endl;
    cout << "-----------------------------" << endl;


    cout << "Select option >> ";
    cin >> option;

    switch (option)
    {
    case 1: AddRecord();
    system( "CLS");
    break;

    case 2: 
    cin.ignore();
    cout << "Searching for book" << endl;
    getline(cin, empID);
    UpdateRecord(empID);
    system( "CLS");
    break;
    
    case 3:
    cin.ignore();
    cout << "Delete by No >> " << endl;
    getline(cin, empID);
    DeleteRecord(empID);
    system( "CLS");
    break;

    case 4:
        cin.ignore();
    cout << "Searching for book" << endl;
    getline(cin, empID);
    SearchRecord(empID);
    break;

    case 5: ListRecord();
    break;
    }
  
    }while (option != 6);

}