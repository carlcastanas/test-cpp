#include <iostream>
#include <string>
using namespace std;

const int maxrow=100;
string b_title [maxrow]={};
string b_author[maxrow]={};
int64_t b_isbn[maxrow]={13};
int counter;

void AddRecord() {
    char title[50];
    char author[20];
    int64_t isbn;

    cin.ignore();

    cout << "| Book Author: ";
    cin.getline(author, 20);
    cout << "| Book Name: ";
    cin.getline(title, 50);
    cout << "| ISBN: ";
    cin >>isbn;

 for (int x = 0; x < maxrow; x++)
 {
    if(b_author[x] == "\0")
    {
        b_author[x] = author;
        b_title[x] = title;
        b_isbn[x] = isbn;
        break;
    }
 }
}

void ListRecord()
{
 int counter = 0;
 int x;
cout << "Current Record(s)" <<endl;
    cout << "|===================================================================|" << endl;
    cout << "  No. |       AUTHOR         |        TITLE            |    ISBN    " << endl << "|===================================================================|\n";
    for (int x = 0; x < maxrow; x++)
    if (b_author[x] != "\0") {
    counter++;
    cout << " " << counter << "       " << b_author[x] << "              " << b_title[x] << "              " << b_isbn[x] << endl;
    cout <<"|===================================================================|\n";
    }
    else if (counter==0) {
    cout << "| No Record found!" << endl;
    cout <<"|===================================================================|\n";
    break;
    }
   
}
void bubbleSort(){
      for (int x = 0; x < maxrow; x++)
    {
    if (b_title[x] != "\0")  
    counter++;  
    }
            for(int i=0;i<counter;i++)
            {
                for( int j=i+1; j<counter; j++)
                {
                    if(b_title[j] < b_title[i])
                    {
                       string temp;
                        temp = b_title[i];
                        b_title[i] = b_title[j];
                        b_title[j] = temp;

                    }
                }
            }
                 for( int i=0; i<counter; i++){
                cout << "|"<<"   "<<b_title[i]<<"     "<<endl;
                cout <<"|===================================================================|\n";
                    }
                }
         
void SearchRecord(string search)
{
   
   cout << "Current Record(s)" << endl;
   cout << "|===================================================================|" << endl;
    cout << "  No. |     AUTHOR       |      TITLE     |      ISBN     " << endl << "|===================================================================|\n";
   
   int counter = 0;
   for (int x = 0; x < maxrow; x++)            
   {   

      if (b_title[x] == search)
       {
      counter++;
         cout << "  " << counter << "         " << b_author[x] << "              " << b_title[x] << "       " << b_isbn[x] << endl;
      break;
       }
    }
    
    if (counter == 0)
    {
    cout << "  No Record found!" << endl;
    }
     cout << "|=======================================================|" << endl;
}
void DeleteRecord(string borrow)
{
    int x, j;
    int size = 20;
    int counter = 0;

    for (int x = 0; x < size; x++)
{
    if (b_title[x] == borrow)
    {
        for(j=x; j<(size-1); j++){
        b_title[j] = b_title[j+1];
         b_author[j] = b_author[j+1];
        }
        counter++;
        break;
    }
}
if (counter == 0)
{ 
    cout << "|===================================================================|" << endl;
    cout << "| Book title does not exist!"<<endl;
    cout << "|===================================================================|" << endl;
}
else

        cout << "|===================================================================|" << endl;
        cout << "| Successfully Borrowed!" << endl;
        cout << "|===================================================================|" << endl;

    }
int main()
{
    cout << "|===================================================================|" << endl;
    cout << "  MENU\n";
    cout << "|===================================================================|" << endl;
    int option;
    string b_title;
    string borrow;
    char author[20];
    do{
    cout << "| 1-Insert book in the library" << endl;
    cout << "| 2-Display all book" << endl;
    cout << "| 3-Sorted list of Books " <<endl;
    cout << "| 4-Search book" << endl;
    cout << "| 5-Borrow book" <<endl;
    cout << "| 6-Exit" << endl;
    cout << "|===================================================================|" << endl;
    cout << "| Select option >> ";
    cin >> option;

    switch (option)
    {
    case 1: AddRecord();
    break;

    case 2: ListRecord();
   
    break;
    
    case 3:
    cout << "| Sorted List of Books: " << endl;
    bubbleSort();
    break;

    case 4:cin.ignore();
    cout << "| Searching for book using title" << endl;
    getline(cin, b_title);
    SearchRecord(b_title);
    break;
    
    case 5: cin.ignore();
    cout << "| Borrow by title >> " << endl;
    getline(cin, borrow);
    DeleteRecord(borrow);
    break;
    
    default:
    cout << "| Exit............." << endl;
    return 0;
    }
  
    }while (option<6);
}
