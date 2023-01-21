#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>

#define N 10                                                   //macro for defining the array size....

using namespace std;

class supermarket
{
    private:
        
        int items;
        
        string name[N];
        float quantity[N];
        float price[N];
        float totalprice[N];
        float amount;
        float gst;
    
    public:

        void input()
        {
            cout << "\n How many items purchased: ";
            cin >> items;
            amount = 0.0;

            for(int i = 0; i < items; i++)
            {
                cout << "\n";
                cout << "Enter product details: "; 
                
                cout << "  Item name: ";
                getline(cin>>ws, name[i]);

                cout << "  Item quantity: ";
                cin >> quantity[i];
                
                cout << "  Item price: ";
                cin >> price[i];

                totalprice[i] = price[i] * quantity[i]; 
                amount += totalprice[i];               
            }
            gst = amount * 0.07;
        }

        void output()
        {
            system("cls");
            cout << fixed << setprecision(2);            // to set precision of floating point numbers....
	        cout << left;                                // because allignment of setw is right by default....

            // bill no.
            int a;
            ifstream infile("COUNT.TXT");
            infile >> a;

            ofstream outfile("COUNT.TXT");
            a += 1;                                       
            outfile << a;
            outfile.close();

            ofstream outf("HIS.TXT", ios::app);                      // to open history file in append mode.... 

            outf << endl << "Bill No.: " << a << endl;
            outf << "----------------------------------------------------------------------------------------------------" << endl;
            cout << "\n";

            cout << "======================================================================" << endl;
            cout << "                           PAYMENT SUMMARY                            " << endl;
            cout << "======================================================================" << endl;
            cout << "\n\n";
            cout << setw(15) << "Name of Item" << setw(15) << "Quantity" << setw(15) << "Rate" << setw(15) << "Amount" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            
            for(int i = 0; i < items; i++)
            {
                outf << "Name: " << name[i] << setw(20) << "Qty: " << quantity[i] << setw(20) << "Rate: " << price[i] << setw(20) << "Amount: " << totalprice[i] << endl;
                cout << setw(15) << name[i] << setw(15) << quantity[i] << setw(15) << price[i] << setw(15) << totalprice[i] << endl;
            }
	    
        cout << endl << setw(45) << right << "Total: " << amount << endl;
	    outf << endl << setw(75) << right << "Total: " << amount << endl;

	    cout << "\n";
            cout << "  GST @ 7% : " << gst << endl;
            cout << "  TOTAL AMOUNT TO PAY: " << amount + gst << endl << endl;
            
	    outf << "\n";
	    outf << "  GST @ 7% : " << gst << endl;
            outf << "  TOTAL AMOUNT TO PAY: " << amount + gst << endl << endl; 

	    outf << "====================================================================================================" << endl;
            cout << "======================================================================" << endl;
            outf.close();
        }

            
};

bool checkPassword()
{
    string s;
    system("cls");

    cout << "===================================================" << endl;
    cout << "|   Welcome to Supermarket Billing Calculation    |\n"; 
    cout << "---------------------------------------------------" << endl;

    cout << "ENTER PASSWORD : ";

    getline(cin>>ws, s);

    if(s == "000")
        return true;
    else
        return false;
}

int main()
{
    system("color F1");
   
    // password.... 
    bool pass = checkPassword();
    if(pass == false)
    {
        cout << "\nWRONG PASSWORD";
        cout << "\nOne attempt left";

        Sleep(3000);

        pass = checkPassword();
        if(pass == false)
            return 0;
    }

    //if password is correct....
    do
    {
    
    system("cls");
    
    cout << "\n";
    cout << "==================================================" << endl;
    cout << "      Supermarket Billing Calculation System      " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "  What do you want to do?                         " << endl;
    cout << "\n";

    cout << "  1:  Generate New Receipt                        " << endl;
    cout << "  2:  Veiw Earling Enteries                       " << endl;
    cout << "  3:  EXIT                                        " << endl;
    cout << "--------------------------------------------------" << endl;

    int choice;
    cout << "  Enter your choice: ";
    cin >> choice;
    cout << "--------------------------------------------------" << endl;

    supermarket obj;
    if(choice == 1)
    {
        obj.input(); 
        obj.output(); 
	
    //to hold program at a particular instance....
	char temp;
	cout << "Enter any key to continue: ";
	cin >> temp;
    }

    else if(choice == 2)
    {
	    cout << "  Loading file...." << endl << endl ;
        ifstream file("HIS.txt");

        string ch;
        while(!file.eof())
        {
            getline(file, ch);
            cout << ch << endl;
        }
        file.close();
	
    char temp;
	cout << "Enter any key to continue: ";
	cin >> temp;
    }

    else if(choice == 3)
    {
        exit(0);
    }

    }while(1);
}