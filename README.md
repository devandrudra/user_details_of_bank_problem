# User_details_of_bank_problem
## Introduction
Making a program on real life cases In C++ which totaly based on the user input and scalable where customer can be created with their unique account number<br>
## Required setups
1.IDE with installed g++ compiler and ensure all setups have done<br>
2.libraries: <iostream>, <vector>, using namespace std;<br>
3.class with constructor<br>
## Elaborating parts of the code--
 class bank_account
 {
    
    int account_no;
    string account_holder_name;
    double balance;

    public:

    
    bank_account()
    {
        int k=0;
        cout<<"Enter account number: ";
        cin>>account_no;
        cout<<"enter the name: ";
        cin.ignore();
        getline(cin,account_holder_name);
        cout<<"enter initial bank balance: ";
        cin>>balance;
    }
    int get_acc_no()
    {
        return account_no;
        
    }
    string get_acc_holder_name()
    {
        return account_holder_name;
    }

    void display()
    {
        cout<<"account no: "<<account_no<<endl;
        cout<<"account holder name: "<<account_holder_name<<endl;
        cout<<"balance: "<<balance<<endl;
    }

    void deposite(double amount)
    {
        if(amount>0) balance += amount;
        else cout<<"amount should be greater than 0"<<endl;
    }

    void withdraw(double amount)
    {
        if(amount<=balance && amount>0) balance -= amount;
        else cout<<"amount is not sufficient to withdraw!"<<endl;
    }

    void transfer(bank_account &customer, double amount)
    {
        if(amount<=balance && amount>0) 
        {
            balance-=amount;
            customer.balance+=amount;
        }

        else
        {
            cout<<"can't process!";

        }
    }

    double operator +(bank_account &customer)
    {
        return customer.balance + balance;
    }

    bool operator ==(bank_account &customer)
    {

        return balance == customer.balance;
    }
};

### constructor(bank_account)
take input when instances are created<br>
### Other functions--
display and getting account number and operator overloading to calculate total money deposited by customers etc<br>
### main function
Main function to achieve desired outcomes<br>
