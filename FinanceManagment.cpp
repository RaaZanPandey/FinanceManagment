#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;
class login{
    public:
    string name;
    string password;

        login(string name, string password)
        {
             this->name = name;
             this->password = password;
        }
};
class  income{
    public:
      string source ;
      float amount;
      int date;
        
        income(string source  , float amount, int date)
        {
            this->source = source;
            this->amount = amount;
            this->date = date;
        }
         void display()
         {
            cout<<setw(30)<<source
                <<setw(30)<<amount
                <<setw(30)<<date<<endl;
         }
};
class  expenses{
    public:
      string source ;
      float amount;
      int date;
        
        expenses(string source  , float amount, int date)
        {
            this->source = source;
            this->amount = amount;
            this->date = date;
        }
         void display()
         {
            cout<<setw(30)<<source
                <<setw(30)<<amount
                <<setw(30)<<date<<endl;
         }
};

class Register{
    public:
    string name;
    string password;
    int dateOfBirth;
    vector<income> Income;
    vector<expenses> Expenses;
    
        Register(string name, string password, int dateOfBirth)
        {
            this->name = name;
            this->password = password;
            this->dateOfBirth = dateOfBirth;
         
        }
};
int main()
{
    vector<Register> Registeration;
    vector<login> Login;
    vector<income> Income;
    vector<expenses> Expenses;


     int choice;
    cout<<endl<<endl;
    cout<<"            PERSONAL FINNANCE"<<endl;
    cout<<string(50, '=')<<endl;
    cout<<"1. Register"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Remove my ID"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<string(50, '_')<<endl;

    do{
        cout<<"Enter your choice :";
        cin>>choice;

           switch (choice)
           {
           case 1:
             {
                 string name;
                 string password;
                 int dateOfBirth;
                 cin.ignore();

                 cout<<"Enter your name  :";
                 getline(cin, name);
                
                 cout<<"Create a Password  :";
                 getline(cin, password);
                 cout<<"Enter your date of Birth  :";
                 cin>>dateOfBirth;
                 Registeration.push_back(Register(name, password, dateOfBirth));
                 cout<<"Your registered succesfully"<<endl;
            break;
             }
             case 2:
             {
               
                string name;
                string password;
                int option;
                cin.ignore(); 
                   cout<<endl<<endl;
                   cout<<"FOR LOGIN YOU ACCOUNT "<<endl;
                   cout<<string(50, '~')<<endl;
                   cout<<"Enter your name  :";
                   getline(cin, name);
                  
                   cout<<"Enter your password  :";
                   getline(cin, password);
                     
                     cout<<endl<<endl;
                     cout<<"MAIN MENU"<<endl;
                     cout<<string(50, '-')<<endl;
                     
                     cout<<"1. Add Income"<<endl;
                     cout<<"2. Add Expenses"<<endl;
                     cout<<"3. View Report"<<endl;
                     cout<<"4. Log Out"<<endl<<endl;
                     cout<<string(50, '~')<<endl;
                     do{
                       
                        cout<<"Enter your choice  :";
                        cin>>option;

                          switch (option)
                          {
                          case 1:
                          {
                            string source;
                            float amount;
                            int date;
                             cin.ignore();
                             cout<<"What is the source of Income  :";
                             getline(cin, source);
                             cout<<"Enter the amount  :";
                             cin>>amount;
                             cout<<"Enter the  date of entry  :";
                             cin>>date;

                                Income.push_back(income(source, amount, date));
                                cout<<"Income  added succesfully"<<endl;

                             break;
                          }
                          case 2:
                          {
                            string source;
                            float amount;
                            int date;

                            cout<<"What is the source of expenses  :";
                            cin.ignore();
                            cin>>source;
                            cout<<"Enter the amount of expenses in  :";
                            cin>>amount;
                            cout<<"Enter the date of expenses  :";
                            cin>>date;

                                Expenses.push_back(expenses(source, amount, date));
                                cout<<"Your expenses is added succesfully "<<endl;
                            break;
                          }
                          case 3:
                          {
                            if(Income.empty())
                            {
                              cout<<"You have not added any income or expenses yet"<<endl;
                            }
                            else
                            {
                              cout<<endl<<endl;
                              cout<<"LIST OF YOUR INCOME WITH SOURCE AND DATE "<<endl;
                              cout<<string(100, '_')<<endl;
                              cout<<setw(30)<<"Source"
                                  <<setw(30)<<"Amount"
                                  <<setw(30)<<"Date"<<endl;
                                  cout<<string(100, '_')<<endl;
                              for( auto& I :Income)
                              {
                                I.display();
                              }
                            }
                            cout<<endl;
                            cout<<string(50, '_')<<endl;

                            if(Expenses.empty())
                            {
                              cout<<"You have not added your expenses yet "<<endl;
                            }
                            else
                            {
                              cout<<endl<<endl;
                              cout<<"LIST OF YOUR EXPENSES WITH SOPURCE AND DATE "<<endl;
                              cout<<string(100, '_')<<endl;
                              cout<<string(100, '_')<<endl;
                              cout<<setw(30)<<"Source"
                                  <<setw(30)<<"Amount"
                                  <<setw(30)<<"Date"<<endl;
                                  cout<<string(100, '_')<<endl;

                                  for(auto E :Expenses)
                                  {
                                    E.display();
                                  }
                            }
                              cout<<endl;
                            cout<<string(50, '_')<<endl;
                            break;
                          }
                          case 4:
                          {
                           cout<<"Existing......"<<endl;
                           break;
                          }
                        
                          default:
                            break;
                          }
            
                     }
                     while(option != 5);
             }
                     
                     case 3:
                     {
                       string name;
                       string password;
                       cout<<"Enter yur name ";
                       cin.ignore();
                       getline(cin, name );
                       cout<<"Enter your password";
                       getline(cin, password);

                       bool nameFound = false;
                       auto it = Registeration.begin();
                       while(it != Registeration.end())
                       {
                        if(it->name == name && it->password == password )
                        {
                          Registeration.erase(it);
                          cout<<"Your account removed succesfully"<<endl;
                          nameFound = true;
                        }
                        else{
                          it++;
                        }
                       }
                       if(!nameFound)
                       {
                        cout<<"Inavalid NAME or PASSWORD"<<endl;
                       }
                       break;
                     }
                     case 4:
                     {
                      cout<<"Exesing ....."<<endl;
                   
                      break;
                     }
             default:
            break;
             }
          //  default:
          //   break;
    
           }
            while(choice != 5);
    }

