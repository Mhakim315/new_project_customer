#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<vector>
#include<ctime>
#include<sstream>
#include<limits>

using namespace std;
int i, size;
string p;
int customer_size = 0 ;
class product_record
{
	protected:
		string product_name;
		string name_of_product_for_buy;
		string search_name;
		bool inventory;
		long long product_inventory;
		long long number_product_of_buy;
		long long price_product;
		long long final_price = 0;
	public:
		product_record *next;
		void record_protuct();
		void show_list_product();
		void clear_the_product(string name_product);
		void record_information_products_in_the_file();
		long add_check_inventory_to_customer_order();
		int show_name_of_product_for_delete();
		
			
};
class order:public product_record
{
	private:
		string customer_name;
		string customer_lastname;
		string customer_phone_number; /*????? ?? ????? ???? ??? ??? ?? ????? ????? ????*/
		int year, mounth, day;
		int size_of_phone_number_for_file;
	public:
		order* next1;
		void customer_order();
		void customer_invoice();
		void clear_the_customer(string name_customer);
		void list_name_customer();
		void order_product();
		void record_information_customers_in_the_file();
		int Turnover_in_historical_period(int year1, int mont1, int day1, int year2, int month2, int day2);
		int show_name_and_lastname_customer_for_delete();
		int Turnover_default();
	
};
product_record* start;
order* start1;
order* start1_check;
void add_customer_order();
void add_product();
void showlist_product();
void showlist_customer_invoice();
void add_to_add_customer_order();
void showlist_file_products();
void showlist_file_customer();
void Turnover_chart();
int showlist_invoice_file();
int clear_invoice_customer();
int clear_registered_product();

int main()
{
	int options;
	int clear, check_clear_customer, check_clear_product;
	string name_product_clear;
	string name_customer_clear;
	product_record product;
	order order_customer;
	while(true)
	{
		cout<<"Enter a number 1 for add a product and registered in the  warehouse         : "<<"\n";
		cout<<"Enter a number 2 to see the list of products from beginning to today        : "<<"\n";
		cout<<"Enter a number 3 to add information customer and registered in system       : "<<"\n";
		cout<<"Enter a number 4 to see the list of names on any enter a name and lastname  : "<<"\n";
		cout<<"Enter a number 5 to clear the information product today from on the system  : "<<"\n";
		cout<<"Enter a number 6 to clear the information customers register today in system: "<<"\n";
		cout<<"Enter a number 7 to see the list information customer from begin until now  : "<<"\n";
		cout<<"Enter a number 8 to see the turnover in a cretain interval by default one month ago : "<<"\n";
		cout<<"Enter a number 9 to clear the registered invoice of customer or registered products : "<<"\n";
		cout<<"Enter a number 10 to display the graph of financial turnover once per year : "<<"\n";
		cout<<"Enter a number 11 to close :  "<<"\n";
		
		while(true)
		{
			cin>>options;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"Wrong input , please enter a number : "<<"\n";
			}
			else
				break;
		}
			switch(options)
			{
				case 1:
					add_product();
					system("CLS");
					break;
				case 2:
					cout<<"product_name"<<setw(20)<<"product_inventory"<<setw(15)<<"price_product"<<"\n\n";
					showlist_file_products();
					cout<<"\nThe list of ergistered products from the beginning of openning the program"<<"\n\n";
					cout<<"\nproduct_name"<<setw(20)<<"product_inventory"<<setw(15)<<"price_product"<<"\n\n";
					showlist_product();
					cout<<"\nplease clear the page enter a 1 : "<<"\n";
					cin>>clear;
					if(clear == 1)
						system("CLS");
					break;
				case 3:
					add_customer_order();
					system("CLS");
					break;
				case 4:
					int invo;
					cout<<"\nTo see the list of invoices registered today enter a number 1  : "<<"\n";
					cout<<"\nTo see the list of invoices previsouly registered eneter num 2 : "<<"\n";
					while(true)
					{
						cin>>invo;
						if(cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout<<"Wrong input, please enter a inputs carefully : "<<"\n\n";
						}
						else
							break;
					}
					if(invo == 1)
					{
						cout<<"\nThe list of customers who have registered by placing an order now : "<<"\n\n";
						order_customer.list_name_customer();
					}
					else if(invo == 2)
					{
						cout<<"\nThe list of customers who had alreadyy registered orders : "<<"\n\n";
						showlist_invoice_file();
					}
					else
						cout<<"\nplease enter the number according to the given information : "<<"\n\n";
					break;
				case 5:
					check_clear_product = product.show_name_of_product_for_delete();
					if(check_clear_product == 1)
					{
						cout<<"\nEnter the name of the product you want to clear : "<<"\n";
						cout<<"\nYou can pnly delete the information of the products that you have registered now : "<<"\n";
						cin>>ws;
						getline(cin, name_product_clear);
						product.clear_the_product(name_product_clear);
						system("CLS");
						break;	
					}
					break;
				case 6:
				    check_clear_customer = order_customer.show_name_and_lastname_customer_for_delete();
					if(check_clear_customer == 1)
					{
						cout<<"\nEnter the name and lastname of the customer you want to clear informaion with a space : "<<"\n";
						cout<<"\nYou can only delete the information of those who have registered now : "<<"\n";
						cin>>ws;
						getline(cin, name_customer_clear);
						order_customer.clear_the_customer(name_customer_clear);
						break;
					}
					break;
				case 7:
					cout<<"\nThe list of customer who are already registered : "<<"\n\n";
					showlist_file_customer();
					cout<<"\nThe list of customer who are registered today : "<<"\n\n";
					showlist_customer_invoice();
					cout<<"\nplease clear the page enter a 1 : "<<"\n";
					cin>>clear;
					if(clear == 1)
						system("CLS");
					break;
				case 8:
					int year1, year2, month1, month2, day1, day2, def;
					cout<<"\nif you do nou have an interval in mind , enter the number 1 to see the financial turnover of the last mounth and enter the date range number 2 : "<<"\n";
					cin>>def;
					if(def == 1)
					{
						order_customer.Turnover_default();	
						break;
					}
					else
					{
						cout<<"\nEnter the beginning and end of the date range you want to view with year and month and day : "<<"\n";
						cout<<"start of the range : "<<"\n";
						cout<<"year : ";
						cin>> year1;
						cout<<"\nmonth (one:1 to twelve:12): ";
						cin>>month1;
						cout<<"\nday (one:1 to thirty one:31): ";
						cin>>day1;
						cout<<"end of the range : "<<"\n";
						cout<<"year : ";
						cin>>year2;
						cout<<"\nmonth (one:1 to twelve:12): ";
						cin>>month2;
						cout<<"\nday (one:1 to thirty one:31): ";
						cin>>day2;
						order_customer.Turnover_in_historical_period(year1, month1, day1, year2, month2, day2);
						break;
					}
				case 9:
					int cls;
					cout<<"Enter the number 1 for clear the information of invoice customer : "<<"\n";
					cout<<"Enter the number 2 for clear the information of register product : "<<"\n\n";
					while(true)
					{
						cin>>cls;
						if(cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits <streamsize> :: max(), '\n');
							cout<<"Wrong input, please enter input carefully : "<<"\n\n";
						}
						else
							break;
					}
					if(cls == 1)
						clear_invoice_customer();
					else if(cls == 2)
						clear_registered_product();
					else
						cout<<"\nplease enter the number according to the given information"<<"\n\n";
					break;
				case 10:
					int check_input;
					cout<<"Note that this chart is only for products registered before this moment !"<<"\n";
					cout<<"If yout want to have an effect on the chart of the orders you have already registered\nfirs press the 1 kay in the proggram and the see the chart"<<"\n\n";
					cin >> check_input;
					if(check_input == 1)
					{
						product.record_information_products_in_the_file();
						order_customer.record_information_customers_in_the_file();
					}
					cout<<"Year\\"<<"Price"<<setw(18)<<"500000($)"<<setw(15)<<"100000($)"<<setw(15)<<"150000($)"<<setw(15)<<"200000($)"<<setw(15)<<"250000($)"<<setw(15)<<"300000($)"<<setw(15)<<"350000($)"<<"\n\n";
					Turnover_chart();
					break;
				case 11:
					product.record_information_products_in_the_file();
					order_customer.record_information_customers_in_the_file();
					exit(0);
				default :
					cout<<"You have entered the wrong value please try again"<<"\n";
					break;
						
				}
			
			}
			
}
void add_product()
{
	product_record* temp = new product_record();
	temp->record_protuct();
	if(start == NULL)
		start = temp;
	else
	{
		product_record* play = new product_record();
		play = start;
		while(play->next != NULL)
		{
			play = play->next;
		}
		play->next = temp;
	}
}
void product_record::record_protuct()
{
	while(true)
	{
		cout<<"Enter the pruduct name : "<<"\n";
		cin>>ws;
		getline(cin, product_name);
		cout<<"Enter the inventory of the product : "<<"\n";
		cin>>product_inventory;
		cout<<"Enter the product price : "<<"\n";
		cin>>price_product;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Wrong input, please enter a information from beginning : "<<"\n\n";
		}	
		else
			break;
	}
	next = NULL;
	
}
void showlist_product()
{
	product_record* play = start;
	if(start == NULL)
		cout<<"There are no products listed ! "<<"\n";
	else
	{
		while(play != NULL)
		{
			play->show_list_product();
			play = play->next;
		}
	}
	
}
void showlist_file_products()
{
	string product_name;
	long long product_inventory, price_product;
	fstream Product_file_path("products\\information.txt");
	if(!Product_file_path.is_open())
		cout<<"Error openning file"<<endl;
	else
	{
		while(!Product_file_path.eof())
		{
			Product_file_path >> product_name >> product_inventory >> price_product;
			if(Product_file_path.eof())
				break;
			cout<<product_name<<setw(20)<<product_inventory<<setw(20)<<price_product<<"\n";
			cout<<"--------------------------------------------------------------------------------------------------"<<"\n";
			
		}
	}
}
void product_record::show_list_product()
{
	cout<<product_name<<setw(20)<<product_inventory<<setw(20)<<price_product<<"\n";
	cout<<"--------------------------------------------------------------------------------------------------"<<"\n";
}
int	product_record::show_name_of_product_for_delete()
{
	int product_number_for_clear = 1;
	product_record* play = start;
	if(start == NULL)
	{
		cout<<"Does not have a product to clear up !"<<"\n";
		int clear;
		while(true)
		{
			cout<<"please enter a number 1 to clear the page : "<<"\n";
			cin>>clear;
			if(clear == 1)
			{
				system("CLS");
				return 0;
			}
		}
	}
	else
	{
		while(play != NULL)
		{
			cout<<"name of product "<<product_number_for_clear<<" : "<<play->product_name<<"\n";
			play = play->next;
			product_number_for_clear++;
		}
		return 1;
	}
	return 1;
}
void product_record::clear_the_product(string name_product)
{
	product_record* play = start;
	if(start == NULL)
		cout<<"Does not have a product to clear up !"<<"\n";
	else
	{
		while(play != NULL)
		{
			if(play->product_name == name_product)
			{
				start = start->next;
				cout<<"product with name "<<play->product_name<<"have delete the list of registered product now"<<"\n\n";
				delete play;
				break;
			}
			else
				play = play->next;	
		}
		
		
	}
	int clear;
	while(true)
	{
		cout<<"please enter a number 1 to clear the page : "<<"\n";
		cin >> clear;
		if(clear == 1)
		{
			system("CLS");
			break;
		}
	};
}
void order::customer_order()
{
	i=1;
	while(true)
	{
		order s;
		cout<<"Enter the customer name : "<<"\n";
		cin>>ws;
		getline(cin, customer_name);
		cout<<"Enter the customer lastname : "<<"\n";
		cin>>ws;
		getline(cin, customer_lastname);
		cout<<"if you want to enter the date of the invoice your self, enter the number  1 :"<<"\n";
		cout<<"and if yout want today date to be recorded autimatically enter the number 2 :"<<"\n";
		int check_number_date;
		cin>>check_number_date;
		if(check_number_date == 1)
		{
			cout<<"Enter the order date (year, mounth, day) : "<<"\n";
			cout<<"Enter the order year :"<<"\n";
			cin>>year;
			cout<<"Enter the order month : "<<"\n";
			cin>>mounth;
			cout<<"Enter the order day :"<<"\n";
			cin>>day;
		}
		// dar inja else ggharar dadam ke aar karbar addy be joz 1 , 2 vared kard barname moshkel nakhorad
		else
		{
			time_t now = time(0);
			tm* time_now_system = localtime(& now);
			year = (time_now_system->tm_year+1970) - 691;
			mounth = time_now_system->tm_mon + 1;
			day = time_now_system->tm_mday - 19;
			//cout<<year<<" "<<mounth<<" "<<day;
		}
		cout<<"Enter the customer phone number : "<<"\n";
		cin>>ws;
		getline(cin, customer_phone_number);
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Wrong input , please enter the input carefully : "<<"\n";
			cout<<"please enter the information of start : "<<"\n\n";
		}
		else
			break;
	}
	final_price = add_check_inventory_to_customer_order();
	next1 = NULL;
}


long product_record::add_check_inventory_to_customer_order()
{
	inventory = false;
	string product_name_for_search;
	lbl:cout<<"Enter the name of the product you want to order : "<<"\n";
	cin>>ws;
	getline(cin, name_of_product_for_buy);
	cout<<"Enter the number of the product you want to order : "<<"\n";
	cin>>number_product_of_buy;
	fstream Product_file("products\\information.txt");
	if(!Product_file.is_open())
		cout<<"Error openning file"<<endl;
	else
	{
		while(!Product_file.eof())
		{
			Product_file>>ws;
			Product_file >> product_name;
			if(Product_file.eof())
				break;
			if(product_name == name_of_product_for_buy)
			{
				Product_file>>ws;
				Product_file>>product_inventory;
				Product_file>>price_product;
				Product_file.close();
				if(number_product_of_buy > product_inventory)
				{
					cout<<"currently, this product is not in stock"<<"\n\n";
					system("pause");
					return 1;
				}
				else
				{
					
					long long product_inventory_path = product_inventory;
					product_inventory = product_inventory - number_product_of_buy;
					long long new_inventory = product_inventory;
					string line;
					fstream Product_file_new, Temporary_file;
					Product_file_new.open("\\Users\\ModernSystem\\Favorites\\html\\products\\information.txt");
					Temporary_file.open("\\Users\\ModernSystem\\Favorites\\html\\products\\Temporary.txt");
					if(!Product_file_new.is_open())
					{
						cout<<"Error openning file"<<"\n\n";
						system("pause");
						return 1;
					}
					if(!Temporary_file.is_open())
					{
						cout<<"Error openning file"<<"\n\n";
						system("pause");
						return 1;
					}
					while(!Product_file_new.eof())
					{
						Product_file_new>>ws;
						Product_file_new >> line;
						if(Product_file_new.eof())
							break;
						else
						{
							if(line == to_string(product_inventory_path))
								Temporary_file << new_inventory << "\n";
							else
								Temporary_file << line << "\n";
							
						}
					}
					Temporary_file.close();
					Product_file_new.close();
					fstream Product_file_new_new ,Temporary_file_new;
					Product_file_new_new.open("\\Users\\ModernSystem\\Favorites\\html\\products\\information.txt");
					Temporary_file_new.open("\\Users\\ModernSystem\\Favorites\\html\\products\\Temporary.txt");
					if(!Product_file_new_new.is_open())
					{
						cout<<"Error openning file"<<"\n\n";
						system("pause");
						return 1;
					}
					if(!Temporary_file_new.is_open())
					{
						cout<<"Error openning file"<<"\n\n";
						system("pause");
						return 1;
					}
					while(!Temporary_file_new.eof())
					{
						Temporary_file_new >> ws;
						Temporary_file_new >> line;
						if(Temporary_file_new.eof())
							break;
						Product_file_new_new << line << "\n";
					}
					Temporary_file_new.close();
					Product_file_new_new.close();
					cout<<"if you want to give a discount specify the discount amount : "<<"\n";
					float discount;
					cin>>discount;
					inventory = true;
					return ((double (number_product_of_buy * price_product)) - (double (number_product_of_buy *price_product)) * (discount));
					}
					
				}
				else
				{
					Product_file>>product_inventory>>price_product;
				}
				
			}
		}
	if(inventory == false)
	{
		cout<<"no found product with name please enter a name of product cerrfuly"<<"\n\n";
		cout<<"if you are record a of product enter a 1 and for out enter a 2 :"<<"\n";
		int sik;
		cin >> sik;
		if(sik == 1)
			goto lbl;
		else
			return 1;
	}
	int clear;
	while(true)
	{
		
		cout<<"please enter a number 1 to clear the page : "<<"\n";
		cin>>clear;
		if(clear == 1)
		{
			system("CLS");
			return 1;
			}
	}

}
void add_customer_order()
{
	order* temp = new order();
	temp->customer_order();
	if(start1 == NULL)
		start1 = temp;
	else
	{
		order* play = new order();
		play = start1;
		while(play->next1 != NULL)
		{
			play = play->next1;
		}
		play->next1 = temp;
		
	}
	customer_size++;		
}
void order::customer_invoice()
{
	
	size = customer_phone_number.size();
	cout<<"Customer name : "<<customer_name<<"\n"<<"Costomer lastname : "<<customer_lastname<<"\n"<<"order registration date : "<<year<<"/"<<setfill('0')<<setw(2)<<mounth<<"/"<<setw(2)<<day<<"\n"<<setfill(' ');
	cout<<"Customer phone number : "<<customer_phone_number<<"\n";
	customer_size++;
	cout<<"product order name : "<<name_of_product_for_buy<<"\n";
	cout<<"product order number : "<<number_product_of_buy<<"\n";
	if(!inventory)
		cout<<"There are no product order counditions for you !"<<"\n\n";
	else
		cout<<"The final price for you : "<<final_price<<"\n\n";
	
}
void showlist_customer_invoice()
{
	customer_size = 1;
	order* play = start1;
	if(start1 == NULL)
		cout<<"There is no list of invoices ! "<<"\n";
	else
	{
		while(play != NULL)
		{
			play->customer_invoice();
			play = play->next1;
		}
	}
}
void showlist_file_customer()
{
	string name, lastname, name_product, phone;
	int year, month, day;
	long long numberp, final;
	fstream Customer_file_list("Customers\\information.txt");
	if(!Customer_file_list.is_open())
		cout<<"Error openning file"<<"\n\n";
	else
	{
		while(!Customer_file_list.eof())
		{
			Customer_file_list>>ws;
			getline(Customer_file_list, name);
			if(Customer_file_list.eof())
				break;
			getline(Customer_file_list, lastname);
			Customer_file_list>>ws;
			Customer_file_list>>year>>month>>day;
			Customer_file_list>>ws;
			getline(Customer_file_list, phone);
			getline(Customer_file_list, name_product);
			Customer_file_list>>ws>>numberp>>final;
			cout<<"Customer name : "<<name<<"/t"<<"Customer lastname : "<<lastname<<"\n";
			cout<<"order registration date : "<<year<<"/"<<setfill('0')<<setw(2)<<month<<"/"<<setw(2)<<day<<setfill(' ')<<"\n";	
			cout<<"product order name : "<<name_product<<"\n";
			cout<<"product order number : "<<numberp<<"\n";
			cout<<"The final price for you : "<<final<<"\n\n";
						
		}
		Customer_file_list.close();
	}
}
int order::show_name_and_lastname_customer_for_delete()
{
	int customer_number_for_clear = 1;
	order* play = start1;
	if(start1 == NULL)
	{
		cout<<"There are not customer for clear the information that : "<<"\n";
		int clear;
		while(true)
		{
			cout<<"please enter a number 1 to clear the page : "<<"\n";
			cin>>clear;
			if(clear == 1)
			{
				system("CLS");
				break;
			}
		}
		return 0;
	}
	else
	{
		while(play != NULL)
		{
			cout<<"Customer "<<customer_number_for_clear<<" : "<<play->customer_name<<" "<<play->customer_lastname<<"\n";
			play = play->next1;
			customer_number_for_clear++;
		}
		return 1;
	}
	
}
void order::clear_the_customer(string name_customer)
{
	order* play = start1;
	if(start1 == NULL)
		cout<<"There are not customer for clear the information that : "<<"\n";
	else
	{
		while(play != NULL)
		{
			if(play->customer_name+ " "+ play->customer_lastname == name_customer)
			{
				start1 = start1->next1;
				delete play;
				cout<<"The customer with "<<play->customer_name<<" and last name "<<play->customer_lastname<<" was delete from the list registerd now"<<"\n\n";
				break;
				}
			else
				play = play->next1;	
		}
	}
	int clear;
	while(true)
	{
		cout<<"please enter a number 1 to clear the page : "<<"\n";
		cin>>clear;
		if(clear == 1)
		{
			system("CLS");
			break;
		}
	}
}
void order::list_name_customer()
{
	int number = 1;
	order* play = start1;
	if(start1 == NULL)
		cout<<"NO one hase placed an order yet ! "<<"\n\n";
	else
	{
		while(play != NULL)
		{
			cout<<"customer "<<number<<" : "<<play->customer_name<<" "<<play->customer_lastname<<"\n";
			cout<<"Enter the person name and last name To see the invoice : "<<"\n";
			play = play->next1;
			number++;
		}
		order* play = start1;
		cin>>ws;
		getline(cin, search_name);
		while(play != NULL)
		{

			if(play->customer_name + " " + play->customer_lastname == search_name)
			{
				play->customer_invoice();
				break;
			}
			else
				play = play->next1;
		}
		
		
	}
	int clear;
	while(true)
	{
		cout<<"please clear the page enter a 1 : "<<"\n";
		cin>>clear;
		if(clear == 1)
		{
			system("CLS");
			break;
		}
	}
}

void product_record::record_information_products_in_the_file()
{
	fstream Product_file;
	Product_file.open("products\\information.txt", ios::app);
	if(!Product_file.is_open())
		cout<<"Error openning of file"<<"\n";
	else
	{
		product_record* play = start;
		if(start != NULL)
		{
			while(play != NULL)
			{
				Product_file<<play->product_name<<"\n"<<play->product_inventory<<"\n"<<play->price_product<<"\n";
				play = play->next;
			}
		}
		Product_file.close();
	}
}
void order::record_information_customers_in_the_file()
{
	fstream Customer_file;
	Customer_file.open("Customers\\information.txt", ios::app);
	if(!Customer_file.is_open())
		cout<<"Error openning of file"<<"\n\n";
	else
	{
		order* play = start1;
		if(start1 != NULL)
		{
			while(play != NULL)
			{
				Customer_file<<play->customer_name<<"\n"<<play->customer_lastname<<"\n"<<play->year<<"\n"<<play->mounth<<"\n"<<play->day<<"\n";
				Customer_file<<play->customer_phone_number<<"\n";
				Customer_file<<play->name_of_product_for_buy<<"\n";
				Customer_file<<play->number_product_of_buy<<"\n";
				Customer_file<<play->final_price<<"\n";
				play = play->next1;
			}
		}
		Customer_file.close();
		
	}
}

int order::Turnover_in_historical_period(int year1 , int month1, int day1, int year2, int month2, int day2)
{
	long total_turnover_in_historical_period = 0;
	int year_end, year_start, month_end, month_start, day_end, day_start;
	if(year1 > year2)
	{
		year_end = year1;
		year_start = year2;
	}
	else
	{
		year_end = year2;
		year_start = year1;
	}
	if(month1 > month2)
	{
		month_end = month1;
		month_start = month2;
	}
	else
	{
		month_end = month2;
		month_start = month1;
	}
	if(day1 > day2)
	{
		day_end = day1;
		day_start = day2;
	}
	else
	{
		day_end = day2;
		day_start = day1;
	}
	fstream Customer_file;
	Customer_file.open("Customers\\information.txt");
		if(!Customer_file.is_open())
	{
		cout<<"Error openning file"<<"\n\n";
		return 1;
	}
	else
	{
		int i=0;
		while(!Customer_file.eof())
		{
			Customer_file>>customer_name>>customer_lastname>>year>>mounth>>day;
			if(Customer_file.eof())
				break;
			if((year < year_end && year > year_start) || (year == year_end && year == year_start && mounth < month_end && mounth < month_start)|| (year == year_end && year == year_start && mounth == month_end && mounth == month_start && day < day_end && day > day_start))
			{
				i++;
				Customer_file>>customer_phone_number;
				Customer_file>>name_of_product_for_buy;
				Customer_file>>number_product_of_buy;
				Customer_file>>final_price;
				cout<<"Information about the customer " << i <<" ordering the product : "<<"\n\n";
				cout<<"Customer name : "<<customer_name<<"\t"<<"Customer lastname : "<<customer_lastname<<"\n";
				cout<<"Order registration date : "<<year<<"/"<<setfill('0')<<setw(2)<<mounth<<"/"<<setw(2)<<day<<setfill('0')<<"\n"<<setfill(' ');
				cout<<"Customer phone number : "<<customer_phone_number<<"\n";
				cout<<"Information about the ordered prouduct : "<<"\n\n";
				cout<<"The name of the product ordered for purchase : "<<name_of_product_for_buy<<"\n";
				cout<<"The number of the product orderd for pruchase : "<<number_product_of_buy<<"\n";
				cout<<"Final price of custom product : "<<final_price<<"\n";
				total_turnover_in_historical_period += final_price; 
					if(final_price == 1)
						total_turnover_in_historical_period--;//in ek vahed ra bare in kam kardam zera vahtee ke ghemat nahee be soorat defaul sab meeshe add 1 ro behesh mide
			}
			else
			{
				Customer_file>>customer_phone_number;
				Customer_file>>name_of_product_for_buy;
				Customer_file>>number_product_of_buy;
				Customer_file>>final_price;
			}
		}
	}
	Customer_file.close();
	cout<<"Accordin to the factors show in this historical period, the total turnover is equal to : "<<total_turnover_in_historical_period<<"\n\n";
	cout<<"please enter a number 1 to clear the page : "<<"\n";
	int clear;
	cin>>clear;
	while(true)
	{
		if(clear ==1 )
		{
			system("CLS");
			break;
		}
	}
	return 1;
}
int order::Turnover_default()
{
	int day_now_shamsi , mounth_now_shamsi, year_now_shamsi;
	time_t now = time(0);
	tm *ltm = localtime(& now);
	long total_turnover_default = 0;
	year_now_shamsi = (1970 + ltm->tm_year) - 691;
	mounth_now_shamsi = (1 + ltm->tm_mon);
	day_now_shamsi = (ltm->tm_mday) - 19;
	fstream Customer_file;
	Customer_file.open("Customers\\information.txt");
	if(!Customer_file.is_open())
	{
		cout<<"Error openning of file "<<"\n\n";
		return 1;
	}
	else
	{
		int i = 0;
		while(!Customer_file.eof())
		{	
			Customer_file>>customer_name>>customer_lastname>>year>>mounth>>day;
			if(Customer_file.eof())
				break;
 			if((year == year_now_shamsi && mounth_now_shamsi && mounth == mounth_now_shamsi && abs(day - day_now_shamsi) <= 30) || (year == year_now_shamsi) && ((mounth_now_shamsi - mounth ) == 1) &&  ((day_now_shamsi + (30 - day)) <=30))
				{
					i++;
					Customer_file>>customer_phone_number;
					Customer_file>>name_of_product_for_buy;
					Customer_file>>number_product_of_buy;
					Customer_file>>final_price;
					cout<<"Information about the customer "<< i <<" ordering the product : "<<"\n\n";
					cout<<"Customer name : "<<customer_name<<"\t"<<"Customer lastname : "<<customer_lastname<<"\n";
					cout<<"Order registration date : "<<year<<"/"<<setfill('0')<<setw(2)<<mounth<<"/"<<setw(2)<<day<<setfill('0')<<"\n"<<setfill(' ');
					cout<<"Customer phone number : "<<customer_phone_number<<"\n\n";
					cout<<"Information about the ordered prouduct : "<<"\n\n";
					cout<<"The name of the product ordered for purchase : "<<name_of_product_for_buy<<"\n";
					cout<<"The number of the product orderd for pruchase : "<<number_product_of_buy<<"\n";
					cout<<"Final price of custom product : "<<final_price<<"\n\n";
					total_turnover_default += final_price; 
					if(final_price == 1)
						total_turnover_default--;//in ek vahed ra bare in kam kardam zera vahtee ke ghemat nahee be soorat defaul sab meeshe add 1 ro behesh mide
				}
				else
				{
					Customer_file>>customer_phone_number;
					Customer_file>>name_of_product_for_buy;
					Customer_file>>number_product_of_buy;
					Customer_file>>final_price;
				}
		}
		Customer_file.close();
		cout<<"According to the invoices show for this last month , the total turnover is equal to : "<<total_turnover_default<<"\n";
	}
	cout<<"please enter a number 1 to clear the page : "<<"\n";
	int clear;
	cin>>clear;
	while(true)
	{
		if(clear ==1 )
		{
			system("CLS");
			break;
		}
	}
	return 1;
}
int showlist_invoice_file()
{
	int Customer_size = 1;
	string Customer_name_in_file , Customer_lastname_in_file, Customer_phone_number_in_file, name_product_customer_order;
	int year_of_customer_order, month_of_customer_order, day_of_customer_order;
	long long number_of_product_customer_order, final_customer_order;
	
	lbl_c:fstream Customer_invoice_file;
	Customer_invoice_file.open("\\Users\\ModernSystem\\Favorites\\html\\Customers\\information.txt");
	if(!Customer_invoice_file.is_open())
		cout<<"Error openning file"<<"\n\n";
	else
	{
		getline(Customer_invoice_file, Customer_name_in_file);
		if(Customer_invoice_file.eof())
			{
				cout<<"there are not the information foe customer in file please first record information "<<"\n\n";
				Customer_invoice_file.close();
				return 1;
			}
		else
		{
			Customer_invoice_file.close();
			Customer_invoice_file.open("Customers\\information.txt");
		}
		while(!Customer_invoice_file.eof())
		{
			Customer_invoice_file>>ws;
				getline(Customer_invoice_file, Customer_name_in_file);
				getline(Customer_invoice_file, Customer_lastname_in_file);
				if(Customer_invoice_file.eof())
					break;
				cout<<"Customer "<<Customer_size<<" : "<<Customer_name_in_file<<" "<<Customer_lastname_in_file<<"\n";
				Customer_invoice_file >> ws;
				Customer_invoice_file >> year_of_customer_order >> month_of_customer_order >> day_of_customer_order;
				Customer_invoice_file >> ws;
				getline(Customer_invoice_file, Customer_phone_number_in_file);
				getline(Customer_invoice_file, name_product_customer_order);
				Customer_invoice_file >> ws;
				Customer_invoice_file >> number_of_product_customer_order >> final_customer_order;	
				Customer_size ++;
			}
			Customer_invoice_file.close();
		}
		string name_customer_for_see_of_invoice;
		bool test = false;
		cout<<"Enter the name and lastname of the customer who invoice you want to see : "<<"\n";
		cin>>ws;
		getline(cin, name_customer_for_see_of_invoice);
		Customer_invoice_file.open("\\Users\\ModernSystem\\Favorites\\html\\Customers\\information.txt");
		if(!Customer_invoice_file.is_open())
			cout<<"Error openning file"<<"\n\n";
		else
		{
			while(!Customer_invoice_file.eof())
			{
				Customer_invoice_file>>ws;
				getline(Customer_invoice_file, Customer_name_in_file);
				getline(Customer_invoice_file, Customer_lastname_in_file);
				if(Customer_invoice_file.eof())
					break;
				if(Customer_name_in_file+ " " + Customer_lastname_in_file == name_customer_for_see_of_invoice)
				{
					test = true;
					Customer_invoice_file >> ws;
					Customer_invoice_file >> year_of_customer_order >> month_of_customer_order >> day_of_customer_order;
					Customer_invoice_file >> ws;
					getline(Customer_invoice_file, Customer_phone_number_in_file);
					getline(Customer_invoice_file, name_product_customer_order);
					Customer_invoice_file >> ws;
					Customer_invoice_file >> number_of_product_customer_order >> final_customer_order;
					cout<<"\n\nCustomer name : "<<Customer_name_in_file<<"\t"<<"Customer lastname : "<<Customer_lastname_in_file<<"\n";
					cout<<"Order registration date : "<<year_of_customer_order<<"/"<<setfill('0')<<setw(2)<<month_of_customer_order<<"/"<<setw(2)<<day_of_customer_order<<setfill(' ')<<"\n";
					cout<<"Customer phone number : "<<Customer_phone_number_in_file<<"\n"<<"name of product customer order : "<<name_product_customer_order<<"\n";
					cout<<"number of product customer order : "<<number_of_product_customer_order<<"\n"<<"The final price of hte product : "<<final_customer_order<<"\n";
					Customer_invoice_file.close();
					break;
				}
				else
				{
					Customer_invoice_file >> ws;
					Customer_invoice_file >> year_of_customer_order >> month_of_customer_order >> day_of_customer_order;
					Customer_invoice_file >> ws;
					getline(Customer_invoice_file, Customer_phone_number_in_file);
					getline(Customer_invoice_file, name_product_customer_order);
					Customer_invoice_file >> ws;
					Customer_invoice_file >> number_of_product_customer_order >> final_customer_order;
				}
			}
			if(test == false)
			{
				cout<<"person with this name is not in the list of those who have already registered an order : "<<"\n";
				cout<<"please enter a name of customer cerrfuly"<<"\n\n";
				cout<<"if you are record a of product enter a 1 and for out enter a 2 :"<<"\n";
				int sik;
				cin >> sik;
				if(sik == 1)
					goto lbl_c;
				else
					return 1;
				}
			}
		
	cout<<"\n\n";
	int clear;
	cout<<"\nplease enter the number 1 for clear the page : "<<"\n";
	while(true)
	{
		cin>>clear;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Wrong input, please enter a number 1 "<<"\n";
		}
		else
		{
			system("CLS");
			break;
		}
	}
	return 1;
}

int clear_invoice_customer()
{
	bool check_customer_in_file = false;
	string name_in_file, family_in_file, phone_in_file, product_in_file, name_and_family_for_clear;
	int year_in_file, month_in_file, day_in_file;
	long long final_in_file, number_in_file;
	vector <string> strings;
	vector <int> ints;
	vector <long long> longs;
	int number_of_customer_in_file_for_show = 1;
	int number_of_customer_in_file_for_clear = 0;
	fstream file_show;
	file_show.open("Customers\\information.txt", ios::in);
	if(!file_show.is_open())
	{
		cout<<"Error openning file"<<"\n\n";
		return 1;
	}
	else
	{
		if(file_show.eof())
		{
			cout<<"this file is not found the customer please first registered the information of customer "<<"\n\n";
			system("puase");
			system("CLS");
			return 1;
		}
		while(!file_show.eof())
		{
			file_show >> name_in_file;
			if(file_show.eof())
				break;
			file_show >> family_in_file;
			file_show >> year_in_file >> month_in_file >> day_in_file;
			file_show >> phone_in_file >> product_in_file;
			file_show >> number_in_file >> final_in_file;
			cout<<"Customer "<<number_of_customer_in_file_for_show<<" : "<<name_in_file<<" "<<family_in_file<<"\n";
			number_of_customer_in_file_for_show++;
		}
		file_show.close();
	}
	cout<<"\n";
	fstream file_clear;
	file_clear.open("Customers\\information.txt");
	if(!file_clear.is_open())
	{
		cout<<"Error openning file"<<"\n\n";
		return 1;
	}
	else
	{
		cout<<"Enter the name and last name you want clear this with a space : "<<"\n";
		cin >> ws;
		getline(cin, name_and_family_for_clear);
		while(!file_clear.eof())
		{
			file_clear >> name_in_file;
			if(file_clear.eof())
				break;
			file_clear >> family_in_file;
			if(name_and_family_for_clear != name_in_file + " "+ family_in_file)
			{
				strings.push_back(name_in_file);
				strings.push_back(family_in_file);
				file_clear >> year_in_file >> month_in_file >> day_in_file;
				ints.push_back(year_in_file);
				ints.push_back(month_in_file);
				ints.push_back(day_in_file);
				file_clear >> phone_in_file >> product_in_file;
				strings.push_back(phone_in_file);
				strings.push_back(product_in_file);
				file_clear >> number_in_file >> final_in_file;
				longs.push_back(number_in_file);
				longs.push_back(final_in_file);
				number_of_customer_in_file_for_clear++;
			}
			else
			{
				check_customer_in_file = true;
				cout<<"The customer with name "<<name_in_file<<" and last name "<<family_in_file<<" was delete from the list customers"<<"\n\n";
				file_clear >> year_in_file >> month_in_file >> day_in_file;
				file_clear >> phone_in_file >> product_in_file;
				file_clear >> number_in_file >> final_in_file;

			}
		}
		if(check_customer_in_file == false)
		{
			cout<<"no found customer in file with name and family "<<"\n";
			cout<<"please enter a name and family carefully (enter a name and last name with a space)"<<"\n\n";
			system("pause");
			system("CLS");
			return 1;
		}
		file_clear.close();
		file_clear.open("Customers\\information.txt", ios::out | ios::trunc);
		file_clear.close();
		file_clear.open("Customers\\information.txt");
		int check_for_number_in_file = 1;
		int number_ints = 0 ;
		int number_longs = 0 ;
		int number_strings = 0;
		while(check_for_number_in_file <= number_of_customer_in_file_for_clear)
		{
			file_clear << strings[number_strings] <<"\n";
			number_strings++;
			file_clear << strings[number_strings]<<"\n";
			number_strings++;
			file_clear << ints[number_ints] <<"\n";
			number_ints++;
			file_clear << ints[number_ints] <<"\n";
			number_ints++;
			file_clear << ints[number_ints]<<"\n";
			number_ints++;
			file_clear << strings[number_strings]<<"\n";
			number_strings++;
			file_clear << strings[number_strings]<<"\n";
			number_strings++;
			file_clear << longs[number_longs]<<"\n";
			number_longs++;
			file_clear << longs[number_longs]<<"\n";
			number_longs++;
			check_for_number_in_file++;
		}
		file_clear.close();
	}
	int clear;
	while(true)
	{
		cout<<"please enter a numer 1 to clear the page : "<<"\n";
		cin>>clear;
		if(clear == 1)
		{
			system("CLS");
			break;	
		}
		
	}
	return 1;
}
int clear_registered_product()
{
	bool check_inventory_of_product = false;
	int size_product = 1;
	string name_product, name_of_product_clear;
	long number_product, price_product;
	fstream information, Temporary;
	information.open("products\\information.txt");
	Temporary.open("products\\Temporary.txt", ios::trunc);
	Temporary.close();
	if(!information.is_open())
	{	
		cout<<"Error openning file"<<"\n\n";
		return 1;
	}
	else
	{
		if(information.eof())
		{
			cout<<"this file is not found the products please first registered the product "<<"\n\n";
			system("puase");
			system("CLS");
			return 1;
		}
		while(!information.eof())
		{
		    information >> ws;
			getline(information, name_product);
			if(information.eof())
				break;
			information >> ws;
			information >> number_product;
			information >> price_product;
			cout<<"name of product "<<size_product<<" : "<<name_product<<"\n";
			size_product++;
		}
		information.close();
		information.open("products\\information.txt", ios::in);
		Temporary.open("products\\Temporary.txt", ios::out);
		if(!Temporary.is_open())
		{
		cout<<"Error openning file"<<"\n\n";
		return 1;
		}
		cout<<"\nEnter a name of product you are want to clear then : "<<"\n";
		cin >> ws;
		getline(cin, name_of_product_clear);
		while(!information.eof())
		{
			information >> ws;
			getline(information, name_product);
			if(information.eof())
				break;
			information >> ws;
			information >> price_product;
			information >> number_product;
			if(name_product == name_of_product_clear)
			{
				check_inventory_of_product = true;
			}
			else
			{
				Temporary << name_product << "\n";
				Temporary << price_product<<"\n";
				Temporary << number_product<<"\n";
			}
		}
		if(check_inventory_of_product == false)
		{
			cout<<"product with name not found in registered product"<<"\n\n";
			system("pause");
			system("CLS");
			return 1;
		}
		information.close();
		Temporary.close();
		information.open("products\\information.txt", ios::trunc);
		information.close();
		information.open("products\\information.txt", ios::out);
		Temporary.open("products\\Temporary.txt", ios::in);
		while(!Temporary.eof())
		{
			Temporary >> ws;
			getline(Temporary, name_product);
			if(Temporary.eof())
				break;
			Temporary >> price_product;
			Temporary >> number_product;
			information << name_product <<"\n";
			information << price_product <<"\n";
			information << number_product<< "\n";
		}
		information.close();
		Temporary.close();
	}
	int clear;
	while(true)
	{
		cout<<"please enter the number 1 to clear the page : "<<"\n";
		cin>>clear;
		if(clear == 1)
		{
			system("CLS");
			break;
		}
	}
	return 1;
}


void Turnover_chart()
{
	string customer_name_in_file, customer_family_in_file, phone_in_file, product_in_file;
	int year_in_file, month_in_file, day_in_file, number_in_file;
	int size_vector_year_in_file;
	long final_in_file;
	vector <int> vector_year_in_file;
	vector <int> vector_size_one_year ;
	vector <long> vector_print_final_price ;
	fstream file_information_customer;
	file_information_customer.open("Customers\\information.txt");
	if(!file_information_customer.is_open())
	{
		cout<<"Error openning file information customer"<<"\n\n";
	}
	else
	{
		while(!file_information_customer.eof())
		{
			file_information_customer >> customer_name_in_file >> customer_family_in_file;
			if(file_information_customer.eof())
				break;
			else
			{
				file_information_customer >> year_in_file >> month_in_file >> day_in_file;
				file_information_customer >> phone_in_file >> product_in_file >> number_in_file >> final_in_file;
				vector_year_in_file.push_back(year_in_file);
			}
		}
	}
	//ebteda baead sal hara darr vector moratab konim ta henam namaesh be tarteeb zaher shavand
	int size_vector_year_in_file_for_moratab_sazy = vector_year_in_file.size();
	for(int i=0; i<size_vector_year_in_file_for_moratab_sazy; i++)
	{
		for(int j=i ; j<size_vector_year_in_file_for_moratab_sazy; j++)
		{
			if(vector_year_in_file[j] < vector_year_in_file[i])
			{
				int temp = vector_year_in_file[i];
				vector_year_in_file[i] = vector_year_in_file[j];
				vector_year_in_file[j] = temp;
			}
		}
	}
	
	file_information_customer.close();
	fstream file_year_customer_order;
	
	file_year_customer_order.open("Customers\\yearcustomer.txt", ios::trunc);
	file_year_customer_order.close();
	
	file_year_customer_order.open("Customers\\yearcustomer.txt");
	if(!file_year_customer_order.is_open())
	{
		cout<<"Error opennig file year customer order"<<"\n";
	}
	else
	{
		size_vector_year_in_file = vector_year_in_file.size();
		for(int i=0; i<size_vector_year_in_file ; i++)
		{
			bool check_cout_in_file = true;
			for(int j=0; j<i; j++)
			{
				if(vector_year_in_file[i] == vector_year_in_file[j])
				{
					check_cout_in_file = false;
				}
			}
			if(check_cout_in_file == true)
				{
					file_year_customer_order << vector_year_in_file[i] << "\n";
				}
		}
	}
	file_year_customer_order.close();
	
	long turnover_final_price;
	fstream read_file_information_customer;
	read_file_information_customer.open("Customers\\information.txt");
	if(!read_file_information_customer.is_open())
	{
		cout<<"Error openning file information customer for read "<<"\n\n";
	}
	else
	{
		for(int i=0; i<size_vector_year_in_file ; i++)
		{
			turnover_final_price = 0;
			while(!read_file_information_customer.eof())
			{
					read_file_information_customer >> customer_name_in_file >> customer_family_in_file;
					if(read_file_information_customer.eof())
						break;
					else
					{
						read_file_information_customer >> year_in_file >> month_in_file >> day_in_file;
						read_file_information_customer >> phone_in_file >> product_in_file >> number_in_file >> final_in_file;
						//if(vector_year_in_file[i] == year_in_file)
						//{
						//	vector_size_one_in_file[i]++;
						//}
						turnover_final_price +=final_in_file;
					
						
					}
			vector_print_final_price.push_back(turnover_final_price);
			}
			
			
		}
	}
	read_file_information_customer.close();
	
	int index , year_in_file_for_print;
	fstream print_year_in_file;
	print_year_in_file.open("Customers\\yearcustomer.txt");
	if(!print_year_in_file.is_open())
	{
		cout<<"Error openning file print year in file "<<"\n\n";
	}
	else
	{
		index = 0;
		while(!print_year_in_file.eof())
		{
			print_year_in_file >>  year_in_file_for_print;
			if(print_year_in_file.eof())
				break;
			else
			{
				cout<<year_in_file_for_print<<"          ";
				for(int i =1 ; i<=vector_print_final_price[index] ; i+=100000)
				{
					cout<<"*";
				}
			}
			cout<<"\n\n";
			index++;
		}
	}
	print_year_in_file.close();
	
	int clear;
	while(true)
	{
		cout<<"please enter the number 1 to clear the page : "<<"\n";
		cin>>clear;
		if(clear == 1)
		{
			system("CLS");
			break;
		}
	}

}







	