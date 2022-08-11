
#include <iostream>
#include <fstream>

using namespace std;

struct customer{
    int accountNo, age,balance,PIN;
    string name,name2,address,address2,address3;
    char gender;

};
void intro();
int mainmenu();
void show_records();
void get_data(customer c[],int elements);
void credit();
void debit();
void delete_record();

int main()
{
    int size, choice;;
customer personList[size];
    intro();
do{
system ("cls");
choice = mainmenu();
switch (choice)
{
    case 1:
    system("cls");
    cout<<"How many elements you want to enter: \t";cin>>size;
    get_data(personList,size);
       break;

    case 2:
     show_records();
     break;
    case 3:
        credit();
        break;
    case 4:
        debit();
        break;
    case 5:
        delete_record();
        break;


}
}while(choice != 6);

    return 0;
}

void intro()
{
    cout<<"BANK MANAGEMENT SYSTEM"<<endl;
    cout<<"======================"<<endl<<endl<<endl;
    cout<<"Welcome to Bank Management System"<<endl;
    cout<<"How may I help you?"<<endl;
    cout<<"Press any key to continue: ";
    cin.ignore();
    cin.get();

}
int mainmenu()
{
    int choice;
    cout<<"1. Add Account Holder        "<<endl;
    cout<<"2. Show Records              "<<endl;
    cout<<"3. Deposit an Amount(Credit) "<<endl;
    cout<<"4. Withdraw an Amount(Debit) "<<endl;
    cout<<"5. Delete Account            "<<endl;
    cout<<"6. Exit                      "<<endl;
    cout<<endl<<"Please choose an option:";
    cin>>choice;
    return choice;
}
void get_data(customer c[],int elements)
{
    ofstream outfile("Sharpsbrain.txt", ios::app);
    cout<<"Please Enter Records Now"<<endl<<endl;
    for (int i = 0; i<elements; i++)
    {
        cout<<"Record "<<i+1<<endl;
        cout<<"========="<<endl;
        cout<<"Account Number: \t";
        cin>>c[i].accountNo;
        cout<<"Full Name:      \t";
        cin.ignore();
        getline(cin,c[i].name);
        cout<<"Gender(M/F):    \t";
        cin>>c[i].gender;
        cout<<"Age:            \t";
        cin>>c[i].age;
        cout<<"Town and City:   \t";
        cin.ignore();
        getline(cin,c[i].address);
        cout<<"Initial Deposit:\t";
        cin>>c[i].balance;
        cout<<"PIN Code:       \t";
        cin>>c[i].PIN;
        cout<<endl;
        outfile<<c[i].accountNo<<"\t"<<c[i].name<<"\t"<<c[i].gender<<"\t"<<c[i].age<<"\t"<<c[i].address<<"\t"<<c[i].balance<<"\t"<<c[i].PIN<<endl;
    }

}
void show_records()
{
   int i = 0;
   bool check = true;
    customer c;
    ifstream infile("Sharpsbrain.txt");
    cout<<"Account Holder List"<<endl;
    cout<<"==================="<<endl<<endl;

    while (infile>>c.accountNo>>c.name>>c.name2>>c.gender>>c.age>>c.address>>c.address2>>c.address3>>c.balance>>c.PIN)
    {
        i++;
        cout<<endl<<"Record "<<i<<endl;
        cout<<"========"<<endl;
        cout<<"Account Number:  \t"<<c.accountNo<<endl;
        cout<<"Name:            \t"<<c.name<<' '<<c.name2<<endl;
        cout<<"Gender:          \t"<<c.gender<<endl;
        cout<<"Age:             \t"<<c.age<<endl;
        cout<<"Town and City:   \t"<<c.address<<' '<<c.address2<<' '<<c.address3<<endl;
        cout<<"Initial Deposit: \t"<<c.balance<<endl;
        cout<<"PIN Code:        \t"<<c.PIN;
        cout<<endl;
        check = false;
    }
    if (check)
    {
        cout<<"No Records"<<endl;
    }
        cout<<"========"<<endl;
        cout<<"Press any key to continue: ";
        cin.ignore();
        cin.get();

}
void credit()
{
    int accountNumber, pin, deposit;
    customer c;
    bool check = true;
    ifstream infile("Sharpsbrain.txt");
    ofstream outfile("Temp.txt");
           cout<<"Enter Account Number:     ";cin>>accountNumber;
           cout<<"Enter PIN:                ";cin>>pin;
    while (infile>>c.accountNo>>c.name>>c.name2>>c.gender>>c.age>>c.address>>c.address2>>c.address3>>c.balance>>c.PIN)
    {
        if(accountNumber == c.accountNo&&pin == c.PIN)
        {
            cout<<"Account Exists!!!        "<<endl;
            cout<<"Enter Amount to deposit: ";cin>>deposit;
            cout<<deposit<<" Rs has been Credited"<<endl;
            cout<<"Total Balance:           "<<c.balance + deposit<<endl;
            c.balance = c.balance + deposit;
            outfile<<c.accountNo<<"\t"<<c.name<<"\t"<<c.name2<<"\t"<<c.gender<<"\t"<<c.age<<"\t"<<c.address<<"\t"<<c.address2<<"\t"<<c.address3<<"\t"<<c.balance<<"\t"<<c.PIN<<endl;
            cout<<"Press any key to continue: ";
            cin.ignore();
            cin.get();
           check = false;
        }
        else
            outfile<<c.accountNo<<"\t"<<c.name<<"\t"<<c.name2<<"\t"<<c.gender<<"\t"<<c.age<<"\t"<<c.address<<"\t"<<c.address2<<"\t"<<c.address3<<"\t"<<c.balance<<"\t"<<c.PIN<<endl;

    }
    if (check)
    {
        cout<<"Account does not exists!!!"<<endl;
        cout<<"Press any key to continue: ";
        cin.ignore();
        cin.get();
    }

    infile.close();
    outfile.close();
    remove("Sharpsbrain.txt");
    rename("Temp.txt","Sharpsbrain.txt");

}void debit()
{
    int accountNumber, pin, deposit;
    customer c;
    bool check = true;
    ifstream infile("Sharpsbrain.txt");
    ofstream outfile("Temp.txt");
           cout<<"Enter Account Number:     ";cin>>accountNumber;
           cout<<"Enter PIN:                ";cin>>pin;
    while (infile>>c.accountNo>>c.name>>c.name2>>c.gender>>c.age>>c.address>>c.address2>>c.address3>>c.balance>>c.PIN)
    {
        if(accountNumber == c.accountNo&&pin == c.PIN)
        {
            cout<<"Account Exists!!!        "<<endl;
            cout<<"Enter Amount to withdraw: ";cin>>deposit;
            if (deposit > c.balance)
            {
                cout<<"Balance is not sufficient "<<endl;
                cout<<"Credit your account"<<endl;
            }
            else
            {
            cout<<deposit<<" Rs has been debited"<<endl;
            cout<<"Total Balance:           "<<c.balance - deposit<<endl;
            c.balance = c.balance - deposit;
            }
            outfile<<c.accountNo<<"\t"<<c.name<<"\t"<<c.name2<<"\t"<<c.gender<<"\t"<<c.age<<"\t"<<c.address<<"\t"<<c.address2<<"\t"<<c.address3<<"\t"<<c.balance<<"\t"<<c.PIN<<endl;
            cout<<"Press any key to continue: ";
            cin.ignore();
            cin.get();
           check = false;
        }
        else
            outfile<<c.accountNo<<"\t"<<c.name<<"\t"<<c.name2<<"\t"<<c.gender<<"\t"<<c.age<<"\t"<<c.address<<"\t"<<c.address2<<"\t"<<c.address3<<"\t"<<c.balance<<"\t"<<c.PIN<<endl;

    }
    if (check)
    {
        cout<<"Account does not exists!!!"<<endl;
        cout<<"Press any key to continue: ";
        cin.ignore();
        cin.get();
    }

    infile.close();
    outfile.close();
    remove("Sharpsbrain.txt");
    rename("Temp.txt","Sharpsbrain.txt");

}
void delete_record()
{
    int accountNumber, pin;
    char choice;
    customer c;
    bool check = true;
    ifstream infile("Sharpsbrain.txt");
    ofstream outfile("Temp.txt");
           cout<<"Enter Account Number:     ";cin>>accountNumber;
           cout<<"Enter PIN:                ";cin>>pin;
    while (infile>>c.accountNo>>c.name>>c.name2>>c.gender>>c.age>>c.address>>c.address2>>c.address3>>c.balance>>c.PIN)
    {



        if(accountNumber != c.accountNo&&pin != c.PIN)
            outfile<<c.accountNo<<"\t"<<c.name<<"\t"<<c.name2<<"\t"<<c.gender<<"\t"<<c.age<<"\t"<<c.address<<"\t"<<c.address2<<"\t"<<c.address3<<"\t"<<c.balance<<"\t"<<c.PIN<<endl;
           check = false;
        }
    if (check == false)
    {
        cout<<"Record has been deleted successfully!"<<endl;
         cout<<"Press any key to continue: ";
        cin.ignore();
        cin.get();
    }
    if (check)
    {
        cout<<"Account does not exists!!!"<<endl;
        cout<<"Press any key to continue: ";
        cin.ignore();
        cin.get();
    }

    infile.close();
    outfile.close();
    remove("Sharpsbrain.txt");
    rename("Temp.txt","Sharpsbrain.txt");
}

