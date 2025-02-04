//make an account which have constructor and fun to display, withdraw, deposite, transfer make an operator overloading

#include<iostream>
#include<vector>

using namespace std;

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

int main()
{   vector<bank_account> customer;
    int size,i,j;
    cout<<"enter the customer strength: ";
    cin>>size;

    for(i=0;i<size;i++)
    {
        cout<<"enter the "<<i+1<<"th account details---\n";
        
        while(true)
        {
            bank_account temp;
            for(j=0 ; j<i ; j++)
            {
                if(customer[j].get_acc_no()==temp.get_acc_no()) 
                {
                    cout<<"account number shoulb be unique!\n";
                    cout<<"please enter valid account details------\n";
                    break;
                }
            }
            if(j==i) 
            {customer.push_back(temp);
            cout<<endl;
            break;
            }
            
        }
        
        
        
        
    }

    while(true)
    {
        char ch;
        cout<<"which operation do you want to perform! (withdraw/deposite/transfer...)\n enter 'w' for withdraw \n enter 'd' for deposite\n enter 't' for transfer and any other character if not interested!\n";
        cin>>ch;
        if(ch=='d' || ch=='w' || ch=='t')
        {
            switch(ch)
            {
                case 'w':
                int a;
                double w;
                cout<<"enter the account no: ";
                cin>>a;
                cout<<"enter amount to withdraw: ";
                cin>>w;
                for(j=0 ; j<customer.size() ; j++)
                {
                    if(customer[j].get_acc_no()==a)
                    {
                    customer[j].withdraw(w);
                    break;
                    }
                    
                }
                if(j==customer.size()) cout<<"customer not exist\n";
                break;

                case 'd':
                int b;
                double d;
                cout<<"enter the account no: ";
                cin>>b;
                cout<<"enter amount to deposit: ";
                cin>>d;
                for(j=0 ; j<customer.size() ; j++)
                {
                    if(customer[j].get_acc_no()==b)
                    {
                    customer[j].deposite(d);
                    break;
                    }
                    
                }
                if(j==customer.size()) cout<<"customer not exist\n";
                break;

                case 't':
                int a1,b1;
                double t;
                cout<<"enter the account no of Sender: ";
                cin>>a1;
                cout<<"enter the account no of Receiver: ";
                cin>>b1;
                cout<<"enter amount to transfer: ";
                cin>>t;
                for(i=0 ; i<customer.size() ; i++)
                {
                    if(a1==customer[i].get_acc_no()) break;
                }
                if(i==customer.size()) {cout<<"customer doesn't exist\n"; break;}

                for(j=0 ; j<customer.size() ; j++)
                {
                    if(customer[j].get_acc_no()==b1)
                    {
                    break;
                    }
                    
                }
                if(j==customer.size()) {cout<<"customer doesn't exist\n"; break;}
                customer[i].transfer(customer[j],t);
                break;

            }
        }
        else break;
    }

    for(int i=0 ; i<customer.size() ; i++)
    {
        customer[i].display();
        cout<<"\n"<<endl;
    }
    return 0;
}