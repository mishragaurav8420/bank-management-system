#include <bits/stdc++.h>
#include <conio.h>  
#include <ctype.h>  
#include <unistd.h> 
#include<windows.h>  
#include<string>
using namespace std;
class Bank_Account
{
    string name;
    int Account_Num;
    string Type_Account;
    float Balance;
class login
{
    string username;
    string password;

public:
    login()
    {
        string temp;
        char ch;
        cout << "Enter username : " << endl;
        getline(cin, temp);
        username = temp;
        temp.clear(); //for clearing string

        cout << "  **Instruction*" << endl
             << endl;
        cout << "1. Passworld should upper &lowercase\n2. Passworld should atlest one special char\n3. passworld should be greater than 5" << endl;

        while (1)
        {
            cout << "Enter passworld :   " << endl;

            while (1)
            {
                ch = getch();
                if (ch == 13)
                    break;

                if (ch == 8)
                    cout << "\b";
                else
                {
                    cout << "*";
                    temp.push_back(ch);
                }
            }
            //for checking length
            if (temp.length() <= 5)
            {
                cout << "\nPassworld Should be greter than 5 " << endl;
                cout << " Try again " << endl;
                continue;
            }

            //for checking special charter upper and lower case
            int count = 0, lower = 0, upper = 0, special = 0;
            string::iterator it;
            for (it = temp.begin(); it != temp.end(); it++)
            {
                if (isupper(*it) == 0 && lower == 0)
                {
                    lower++;
                    count++;
                }

                if (isupper(*it) == 1 && upper == 0)
                {
                    upper++;
                    count++;
                }

                if (isalnum(*it) == 0 && special == 0)
                {
                    special++;
                    count++;
                }
            }

            if (count >= 3)
                break;
            else
            {
                if (lower == 0)
                    cout << "\nPassword should have atlesat one lowercase " << endl;
                if (upper == 0)
                    cout << "\nPassword should have atlest one upper case " << endl;
                if (special == 0)
                    cout << "\npassword should have atlest one special charcter " << endl;
            }
        }
        cout << "\nAgain Enter passworld  :" << endl;
        string ptr;
        while (1)
        {
            while (1)
            {
                ch = getch();
                if (ch == 13)
                    break;
                if (ch == 8)
                    cout << "\b";
                else
                {
                    cout << "*";
                    ptr.push_back(ch);
                }
            }
            if (ptr != temp)
            {
                cout << "\nPassworld did not match please try again  :" << endl;
            }
            else
            {
                password = temp;
                temp.clear();
                int delay = 1;
                while (1)
                {

                    string str = "abc%6*(gdhsgfg@#$hjdfj98h&%^%&fAVFtrGS45365gfhskjhfhyhunmcxbhjfgskhryhjkshhguyubgy765767$^$%fgg&^7589hfYUY&U*(UJ())ggh";
                    int n = str.length();
                    string otp;

                    for (int i = 0; i < 5; i++)
                    {

                        otp.push_back(str[rand() % n]);
                    }
                    cout << "\nEnter Captcha =" << otp << endl;
                    getline(cin, temp);
                    if (temp == otp)
                        break;
                    else
                    {
                        cout << "Please Enter captcha again wait " << delay * 10 << "second " << endl;
                        int ss = 10 * delay;
                        while (ss)
                        {
                            sleep(1);
                            system("cls");
                            ss--;
                            cout << "\t\t0 h :0 m :" << ss << "s " << endl;
                        }
                    }
                    delay = delay + 1;
                }
                cout << "Congratualtion You sign in sucessfully" << endl;
                break;
            }
        }
    }
    //for sign in fuction
    bool signin()
    {
    	int max=3,flag=0;
    	char ch;
    	while(max)
    	{
    		string user,pass;
    		cout<<"Enter user name  :"<<endl;
    		getline(cin,user);
    		cout<<"Enter password    :"<<endl;
    		//for printing star
    		while (1)
            {
                ch = getch();
                if (ch == 13)
                    break;
                if (ch == 8)
                    cout << "\b";
                else
                {
                    cout << "*";
                    pass.push_back(ch);
                }
            }
            if(pass==password&&username==user)
            {
            	flag=1;
            	return flag;
			}
			else{
				user.clear();
				pass.clear();
			}
    		
    		max--;
    		cout<<"\nYou have  "<<max<<"Attept "<<endl;
    	     Beep(784,1000);
		}
		return flag;
	}
}; login l;
   
    
    public:
    Bank_Account()
    {
        string name;
        cout<<"\n\t****Personal Information***"<<endl;
        cout<<"\nEnter your name :"<<endl;
        getline(cin,name);
        this->name=name;
        
        int ac;
        cout<<endl<<"Enter your 12 digit Account no : ";
        cin>>ac;
        Account_Num=ac;
        
         string choice;
         cin.ignore();
         cout<<endl<<"Type of Account "<<endl<<endl;
         cout<<" 1...Current_account "<<endl;
         cout<<" 2...Savings_account "<<endl;
         cout<<" 3...Salary_account "<<endl;
         cout<<" 4...Fixed_deposit_account"<<endl;
	cin.ignore();
         getline(cin,choice);
         Type_Account=choice;
       
         Balance=500.0f;
         
    }
    
    void Get_data()
    {   
        cout<<"\n\n\t**Account Detail**\t"<<endl;
        cout<<"Name =\t\t\t "<<name<<endl;
        cout<<"Account_Number=\t\t "<<Account_Num<<endl;
        cout<<"Account_Type=\t\t "<<Type_Account<<endl;
        cout<<"Avilable Balance \t "<<Balance<<endl<<endl;
        
    }
    
    void deposit()
    {
        float amount;
        cout<<"Enter amount which is deposited  "<<endl;
        cin>>amount;
        Balance+=amount;
        cout<<"Your total balance after deposited is "<<Balance<<endl;
        
    }
    
    void withdraw()
    {   
        int amount;
        cout<<"Enter amount which is withdraw  "<<endl;
        cin>>amount;
        if(Balance-amount>500)
        cout<<"Sorry!!! your balance is not sufficient for this amount  "<<endl;
        else
        {
            Balance-=amount;
            cout<<"Your avilable Balance after withdraw is  "<<Balance<<endl;
        }
    }
    bool Signin()
    {
    	bool flag;
    	cout<<"\n\t***Sign in Menu****"<<endl;
    	return l.signin();
	}
    
    
};

int main()
{
    Bank_Account obj;
    obj.Get_data();
    while(obj.Signin())
    {
    	int choice;
    	do{
		
    	 cout<<"\n\n**Enter your choice**"<<endl;
    cout<<" 1...Withdraw money."<<endl;
    cout<<" 2...Deposit money."<<endl;
    cout<<" 3...Display Balance."<<endl;
    cout<<" 4...Quit the program. "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
           obj.withdraw();
           break;
        
        case 2:
             obj.deposit();
             break;
             
        case 3:
             obj.Get_data();
             break;
        default:
        	if(choice!=4)
             cout<<"Enter a valid choice "<<endl;
        
    }}while(choice!=4);
    	break;
	}
    
}
