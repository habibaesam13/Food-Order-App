
#include<iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <windows.h> //for sleep timer
#include<algorithm>
using namespace std;
bool loadMenuSuccess = false;
bool loginSuccess = false;
//functions definition
void main_menu();
void login();
void registration();
void forgot();
float calcPrice();
void display_Cart();
float discountFunction();
void order_function(bool, int, bool);
bool validity();
void timer(int, int, int);
void feedback();
void recommended_meal();
void random_meal();
void organizeBox(string menuElement)
{
	cout << "\t\t\t\t\t" << char(201);      for (int i = 0; i < 29; i++) { cout << char(205); }      cout << char(187) << endl;
	cout << "\t\t\t\t\t" << char(186) << "                             " << char(186) << endl;
	cout << "\t\t\t\t\t" << char(186) << "                             " << char(186) << endl;
	cout << "\t\t\t\t\t" << char(186) << menuElement << char(186) << endl;
	cout << "\t\t\t\t\t" << char(186) << "                             " << char(186) << endl;
	cout << "\t\t\t\t\t" << char(186) << "                             " << char(186) << endl;
	cout << "\t\t\t\t\t" << char(200);      for (int i = 0; i < 29; i++) { cout << char(205); }      cout << char(188) << endl;

}
struct meal
{
	int num = 0;
	string name = "";
	string category = "";
	string components = "";
	int food_id = 0;
	double price = 0.0;
};
meal meals[] =                                                                                                //INDEX AFTER SORT
{ {1,"Beef-Burger","Burger","Beef , Mayounese , Ketchup , Pickels , Onions",134591,90.50},                        //[0]
  {2,"Cheese-Burger","Burger","Beef , American Cheese  , Mayounese , Ketchup , Pickels ,  Onions",134592,80.50},  //[1]
  {6,"Margherita","Pizza","Diced tomatoes ,stretchy mozzarella",124500,52.50},                                    //[5]
  {8,"Seafood-Pizza","Pizza","Diced tomatoes , stretchy mozzarella , Shrimps , Tuna",124501,100.00},             //[7]
  {4,"Chicken-Soup","Soup","cream or milk ,chicken broth , onions , chicken broth , seasonings",210001,35.98},    //[3]
  {9,"Seafood-Soup","Soup" ,"Soup seafood , vegetables",210002,35.98},                                            //[8]
  {7,"Molten-Chocolate Cake","Dessert","chocolate , Butter , Sugar , Eggs , flour",356544,99.98},                 //[6]
  {3,"Cheese-Cake","Dessert","Cheese , Butter , Sugar , Eggs , Biscuit",356540,79.98},                            //[2]
  {5,"Coca-Cola","Drinks","",89541,10.30},                                                                        //[4]
  {10,"Sprite","Drinks","",85942,10.30},                                                                           //[9]
  {}
}; //array byt5zn fih l meals
meal mealUserOrder[20]; //array byt5zn fiih el orders bta3t el customer
void displayMeal(int index) //displays meal ordered by customer
{
	cout << "------------------------------------------" << endl;
	cout << "Meal Number " << (index + 1) << endl;
	cout << "***********" << endl;
	cout << "Meal Name is " << meals[index].name << endl;
	cout << "Meal components is " << meals[index].components << endl;
	cout << "Meal Price is " << meals[index].price << " L.E" << endl << endl;
	cout << "------------------------------------------" << endl;
}
void displayMenu() //function bt3rd el menu kolha
{
	cout << "Menu.................." << endl;
	cout << "#############################" << endl;
	cout << endl;
	for (int i = 0; i < 10; i++) {

		cout << "------------------------------------------" << endl;
		cout << "Meal Number " << (i + 1) << endl;
		cout << "***********" << endl;
		cout << "Meal Name is " << meals[i].name << endl;
		if (meals[i].components != "")
			cout << meals[i].components << endl;
		cout << "Meal Price is " << meals[i].price << endl;
		cout << "------------------------------------------" << endl;

	}

}
int searchMealName(int size, string searchvalue)
{
	int low = 0;
	int high = size - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (searchvalue == meals[mid].name)      //middle
		{
			return mid;
		}
		else if (searchvalue > meals[mid].name)  //upper half
		{
			low = mid + 1;
		}
		else                                    //lower half
		{
			high = mid - 1;
		}
	}
	return -1;
};
bool cmp(meal m1, meal m2) {           //DY BOOLEAN FUNCTION 3AMLENHA LEL SORT
	return m1.name < m2.name;
}
int main()
{
	int mainOption = 0, option = 0;
	int searchIndex, mealNumber = 0;
	string mealName;
	bool valid = true, re_order;
	char order;
	string dish;
	sort(meals, meals + 10, cmp);      //DY FUNCTION EL SORT
	system("COLOR 1F");
	while (loginSuccess == true)
	{

		organizeBox("   PRESS  1  TO VIEW  MENU   ");
		organizeBox("   PRESS  2  TO  SEARCH MEAL ");
		organizeBox("   PRESS  3  TO   GO   BACK  ");
		organizeBox("   PRESS  4  TO  VIEW  CART  ");
		organizeBox("   PRESS  5  TO  RANDOM MEAL ");
		organizeBox("  PRESS 6 TO FiLTER BY PRICE ");
		cout << endl;
		cin >> mainOption;
		if (cin.fail())
		{
			cin.clear(); cin.ignore(512, '\n');
			system("cls");
			continue;
		}
		switch (mainOption)
		{
		case 1:
			displayMenu();
			cout << "If you like to order enter Y/y to go back to main press N/n" << endl;
			if (validity())
			{
				order_function(valid, 0, false);
				display_Cart();
				cout << "\n\nWould you like to order again?(Y/N)" << endl;
				re_order = validity();
				if (re_order)
				{
					continue;
				}
				else
				{
					cout << "I'm glad we were able to help you today and we so appreciate your business. If you have the time and wouldn't mind, we'd love it if you shared this experience on [FCIS Order System]" << endl << "If you don't want just press enter :)" << endl; feedback();
					feedback();
					cout << endl << "Thanks for your feedback" << endl << "press y/Y to get back to main menu and N/n to exit the program " << endl;
					if (validity())
					{
						continue;
					}
					else
					{
						exit(1);

					}

				}
			}
			else
			{
				continue;
			}
			break;
		case 2:
			while (valid)
			{
				for (int i = 0; i < 10; i++)
				{
					cout << i + 1 << ")" << meals[i].name << "\n";
				}
				cout << "Enter name of meal you want to search : " << endl;
				cout << "Meal : ";
				cin >> dish;
				searchIndex = searchMealName(10, dish);
				if (searchIndex != -1)
				{
					displayMeal(searchIndex);

					cout << "If you like to order meal : " << meals[searchIndex].name << " Press O/o else press any key" << endl;

					cin >> order;
					if (cin.fail())
					{
						cin.clear(); cin.ignore(512, '\n');
						break;
					}
					else {
						switch (order)
						{
						case 'o':
						case 'O':
							valid = true;
							order_function(valid, searchIndex, true);
						default:
							break;
						}
					}
				}
				else
				{
					cout << "Meal not found..." << endl;
				}
				cout << "Would you like to search for something else...? Y/y for yes N/n for no and proceed to main menu" << endl;
				valid = validity();
				if (valid == false)
					continue;
			}
			if (valid == false)
			{
				continue;
			}
			break;
		case 3:
			loginSuccess = false;
			continue;
			break;
		case 4:
			if (mealUserOrder[0].food_id == 0)
			{
				cout << "\t\t\tWelcome to your cart" << endl << endl << endl;
				cout << "\t Your Cart is empty right now so if you like to make an order get back to main menu and view menu or search for meal" << endl << endl;
				cout << "\t\t\t HAVE A NICE DAY" << endl << endl;
			}
			else
			{
				display_Cart();

				cout << "\n\nWould you like to order again?(Y/N)" << endl;
				re_order = validity();
				if (re_order)
				{
					continue;
				}
				else
				{
					cout << "I'm glad we were able to help you today and we so appreciate your business. If you have the time and wouldn't mind, we'd love it if you shared this experience on [FCIS Order System]" << endl << "If you don't want just press enter :)" << endl; feedback();
					feedback();
					cout << endl << "Thanks for your feedback" << endl << "press y/Y to get back to main menu and N/n to exit the program " << endl;
					if (validity())
					{
						continue;
					}
					else
					{
						exit(1);
					}
				}
			}
			break;
		case 5:
			system("cls");
			random_meal();
			cout << "If you like to order enter Y/y to go back to main press N/n" << endl;
			if (validity())
			{
				order_function(valid, 0, true);
				display_Cart();
				cout << "\n\nWould you like to order again?(Y/N)" << endl;
				re_order = validity();
				if (re_order)
				{
					continue;
				}
				else
				{
					cout << "I'm glad we were able to help you today and we so appreciate your business. If you have the time and wouldn't mind, we'd love it if you shared this experience on [FCIS Order System]" << endl << "If you don't want just press enter :)" << endl; feedback();
					feedback();
					cout << endl << "Thanks for your feedback" << endl << "press y/Y to get back to main menu and N/n to exit the program " << endl;
					if (validity())
					{
						continue;
					}
					else
					{
						exit(1);
					}

				}
			}
			else
			{
				continue;
			}
			break;
		case 6:
			recommended_meal();
			cout << "If you like to order enter Y/y to go back to main press N/n" << endl;
			if (validity())
			{
				order_function(true, 0, false);
				display_Cart();
				cout << "\n\nWould you like to order again?(Y/N)" << endl;
				re_order = validity();
				if (re_order)
				{
					continue;
				}
				else
				{
					cout << "I'm glad we were able to help you today and we so appreciate your business. If you have the time and wouldn't mind, we'd love it if you shared this experience on [FCIS Order System]" << endl << "If you don't want just press enter :)" << endl; feedback();
					feedback();
					cout << endl << "Thanks for your feedback" << endl << "press y/Y to get back to main menu and N/n to exit the program " << endl;
					if (validity())
					{
						continue;
					}
					else
					{
						exit(1);
					}

				}
			}
			else
			{
				continue;
			}
			break;
		default:
			system("cls");
			loginSuccess = true;
			continue;
		}
	}

	if (loginSuccess == false)
	{
		main_menu();
	}

	return 0;
}
float calcPrice() {
	float subTotal = 0;
	for (int i = 0; i < 10; i++) {
		subTotal += mealUserOrder[i].price;
	}
	return subTotal;
}
void display_Cart() {
	float total_price = 0, taxes = 0, finaldiscount = 0, sub_total = 0;
	int index_Meal = 0, size_UserArray = 20, addOrRemove = 0, indexadded = 0, timercount = 0;
	bool re_order = false, validCart = false, valid = true, valid2 = true;
	system("cls"); // share7 est5damo f line 220
	cout << "\t\t\t\t Welcome To your Cart " << endl;
	for (int indexOfOrder = 0; indexOfOrder < size_UserArray; indexOfOrder++)
	{

		if (mealUserOrder[indexOfOrder].food_id != 0) //b3ml check en mfiish 3ndi index fady
		{
			cout << (indexOfOrder + 1) << ")" << "Meal name : " << mealUserOrder[indexOfOrder].name << endl;//"\t\t"<<counter << endl;
			if (mealUserOrder[indexOfOrder].components != "") // check en mfiish index fih components fadia 3shan fih 2 drinks el components fadia 
			{
				cout << "{ " << mealUserOrder[indexOfOrder].components << " } " << endl;
			}
			cout << mealUserOrder[indexOfOrder].price << " L.E" << endl << endl << "----------" << endl;
		}

	}
	cout << "Do you want to modify your cart ? \t (Enter Y/y for Yes and N/n for No and proceed to checkout)" << endl;
	validCart = validity();

	while (validCart) {
		cout << "To add a meal press 1 , to remove press 2 :)" << endl;
		cin >> addOrRemove;
		if (cin.fail())
		{
			cin.clear(); cin.ignore(512, '\n');
			cout << "Please enter a number ! ! !" << endl << endl;
			continue;
		}
		else
		{
			switch (addOrRemove)
			{
			case 1:
				displayMenu();
				cout << "Enter number of meal you want to add " << endl;
				cin >> index_Meal;
				if (cin.fail())
				{
					cout << "Please enter a valid  character" << endl;
					cin.clear(); cin.ignore(512, '\n');
					continue;
				}
				else {
					//bqaren been l index el customer d5lo wl array w a3ml shift ll array w asheel a5er element b i-- w a2ll l size bta3 l array l gdiid b size--
					for (int i = 0; i < size_UserArray; i++)
					{
						if (mealUserOrder[i].food_id == 0)
						{
							indexadded = i;
							break;
						}
					}
					mealUserOrder[indexadded].name = meals[(index_Meal - 1)].name;
					mealUserOrder[indexadded].food_id = meals[(index_Meal - 1)].food_id;
					mealUserOrder[indexadded].category = meals[(index_Meal - 1)].category;
					mealUserOrder[indexadded].price = meals[(index_Meal - 1)].price;
					mealUserOrder[indexadded].components = meals[(index_Meal - 1)].components;
					return display_Cart();

				}
				break;
			case 2:
				cout << "Enter number of meal you want to remove " << endl;
				cin >> index_Meal;

				//bqaren been l index el customer d5lo wl array w a3ml shift ll array w asheel a5er element b i-- w a2ll l size bta3 l array l gdiid b size--
				if (cin.fail())
				{
					cout << "Please enter a valid  character" << endl;
					cin.clear(); cin.ignore(512, '\n');
					continue;
				}
				else {
					for (int i = 0; i < size_UserArray; i++)
					{
						if (i == index_Meal - 1) {
							for (int j = i; j < size_UserArray - 1; j++)
							{
								mealUserOrder[j] = mealUserOrder[j + 1];
								//i--;
							}
						}
						size_UserArray--;
					}
				}
				return display_Cart();
				validCart = false;
				break;
			default:
				break;
			}
			//b3ml recursion 3shan a3rdlo l new cart w hna kan byd5lni f infinte loop bs lma 3mlt system cls mb2ash zbtt
		}
		system("cls");

	}
	cout << "Do you have a promo code ? Enter (Y/N) please : " << endl;
	if (validity() == true) {
		finaldiscount = discountFunction();
	}

	sub_total = calcPrice();
	taxes = calcPrice() * 0.12;
	total_price = taxes + sub_total - finaldiscount;

	cout << "subtotal = \t" << sub_total << endl;

	cout << "taxes = \t" << taxes << endl;
	cout << "discount = \t" << finaldiscount << endl;

	cout << "Your total price = \t" << total_price << "L.E" << endl;

	cout << "Press Y/y to submit order , N/n to check your cart " << endl;

	while (valid)
	{
		valid2 = validity();
		switch (valid2)
		{
		case true:
			valid = false;
			break;
		case false:
			return display_Cart();
			break;
		default:
			validity();
			break;
		}

	}

	for (int i = 0; i < 20; i++)
	{
		if (mealUserOrder[i].food_id != 0)
			timercount++;
	}
	timercount *= 1;
	timer(0, timercount / 60, timercount % 60);

	validCart = false;

}
float discountFunction() {
	string promo, promocodeArray[4] = { "GET30","fcis22","30OFF","FCIS22" };
	float discount = 0;
	bool validpromo = false;
	cout << "enter code" << endl;
	cin >> promo;
	for (int arrayindex = 0; arrayindex < 4; arrayindex++)
	{
		if (promo == promocodeArray[arrayindex])
		{
			discount = calcPrice() * 0.33333;
			validpromo = true;
		}
	}

	if (validpromo == false) {
		cout << "Wrong promo code did you make a typo?" << endl;
		cout << "Y/y for yes N/n for no" << endl;
		if (validity()) {
			return discountFunction();
		}
	}
	return discount;
}
void login()                                                                   //login function declaration 
{
	int count{};
	string userId, password, id, pass;
	system("cls");
	cout << "\t\t\t\t\tPLEASE ENTER THE ACCOUNT CREDENTIALS\t\t\n\n" << endl;
	organizeBox("           Username          ");
	cout << "\t\t\t\t\t"; cin >> userId; cout << "\n\n";
	organizeBox("           Password          ");
	cout << "\t\t\t\t\t"; cin >> password;
	ifstream input("record.txt");                                          //This code is used to check if username and password already exist in our records and ifstream is used to read the data
	while (input >> id >> pass)
	{
		if (userId == id && password == pass)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();

	if (count == 1)
	{
		cout << userId << "\n your LOGIN is successfull \n Thanks for logging in !\n";
		loginSuccess = true;
		main();
	}
	else
	{
		cout << "\n LOGIN ERROR \n Please cheack your username and password\n";
		main_menu();
	}
}                                                                             //End of login function 
void registration()                                                  //registration function declaration
{
	string ruserId, rpassword, rid, rpass;
	system("cls");
	cout << "\t\t\t_______PLEASE CHOOSE A USERNAME AND A PASSWORD_______\t\t\t\n\n";
	organizeBox("           Username          ");
	cout << "\t\t\t\t\t"; cin >> ruserId; cout << "\n\n";
	organizeBox("           Password          ");
	cout << "\t\t\t\t\t"; cin >> rpassword;
	ofstream f1("record.txt", ios::app);                                    //ofstream is used to write instde the file
	f1 << ruserId << ' ' << rpassword << endl;
	system("cls");
	cout << "\n\t\t\t Registration is successfull \n";
	main_menu();
}                                                                        //End of Rregistration function
void forgot()                                                        //forgot function declaration
{
	int option;
	system("cls");
	cout << "\t\t\t You forgot the password! But don't WORRY :)!" << endl;
	organizeBox("PRESS 1 TO SEACH BY USERNAME ");
	organizeBox("PRESS 2 TO GO  TO   MAIN MENU");
	cin >> option;

	switch (option)
	{
	case 1:
	{
		int count{};
		string suserId, sId, spass;
		cout << "\n\t\t\t Enter the user name you remembered : ";
		cin >> suserId;
		ifstream f2("record.txt");
		while (f2 >> sId >> spass)
		{
			if (sId == suserId)
			{
				count = 1;
			}
		}
		f2.close();
		if (count == 1)
		{
			cout << "\n\n your account is found! \n ";
			cout << "\n\n your password is : " << spass << "\n";
			main_menu();

		}
		else {
			cout << "\n\t sorry! your account is not found! \n";
			main_menu();
		}
		break;
	}
	case 2:
	{
		main_menu();
		break;
	}
	default:
		cout << "\t\t\t wrong choice ! please try again" << endl;
		forgot();
	}
}                                                                             //End of forgot function
void main_menu()
{
	int n;                                                                                   //Main MENU page
	organizeBox("Welcome To Food Ordering APP!");
	for (int i = 0; i < 120; i++) { cout << char(254); };
	cout << "\n\n";
	organizeBox("PRESS      1    TO     LOGIN ");
	organizeBox("PRESS      2    TO   REGISTER");
	organizeBox("PRESS  3 TO  RECOVER PASSWORD");
	organizeBox("PRESS      4    TO       EXIT");
	cout << "\n \t\t\t PLEASE ENTER YOUR CHOICE : ";
	cin >> n;
	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		system("cls");
		main_menu();
	}
	switch (n)
	{
	case 1:

		login();
		break;
	case 2:

		registration();
		break;
	case 3:

		forgot();
	case 4:
		cout << "\t\t\t Thankyou! \n\n";
		loginSuccess = false;
		break;
	default:
		system("cls");
		loginSuccess = false;
		main();
	}
}
void order_function(bool valid1, int searched_index, bool searched) {
	int mealnumber, mealIndex = 0;
	cout << endl;
	while (valid1)
	{
		if (searched == false)
		{
			cout << "Enter number of meal you want " << endl;
			cin >> mealnumber;
		}
		else
		{
			mealnumber = searched_index + 1;
		}
		if (cin.fail())
		{
			cout << "Please enter a valid  character" << endl;
			cin.clear(); cin.ignore(512, '\n');
			continue;
		}
		else {
			if (mealnumber <= 10) {
				displayMeal((mealnumber - 1));
				for (int i = 0; i < 20; i++)
				{
					if (mealUserOrder[i].food_id == 0)
					{
						mealIndex = i;
						break;
					}
				}
				mealUserOrder[mealIndex].name = meals[(mealnumber - 1)].name;
				mealUserOrder[mealIndex].food_id = meals[(mealnumber - 1)].food_id;
				mealUserOrder[mealIndex].category = meals[(mealnumber - 1)].category;
				mealUserOrder[mealIndex].price = meals[(mealnumber - 1)].price;
				mealUserOrder[mealIndex].components = meals[(mealnumber - 1)].components;
				if (mealIndex < 20) //limit of user Order array
				{
					mealIndex++;
				}
				if (searched == false)
				{
					cout << "Order Aded to cart successfully Enter Y/y to add more meals or N/n to proceed to cart" << endl;
					valid1 = validity();
				}
				else
				{
					break;
				}
			}
			else
			{
				cout << "Please enter a valid number" << endl;
				valid1 = false;
				continue;
			}
		}
	}

}
bool validity() { // function bt check l customer 3ayez ykml wla la2 w bt return true or false
	string input;
	char c;
	cin >> input;
	c = input[0];
	switch (c)
	{
	case 'Y':
	case 'y':
		return true;
		break;
	case 'N':
	case'n':
		return false;
		break;
	default:
		cout << "Please enter a valid character" << endl;
		return validity();
		break;
	}
}
void timer(int h, int m, int s) {
	for (; ; ) {

		if (h == 0 && m == 0 && s == 0)
		{
			break;
		}
		if (s == 0 && m == 0) {
			m = 59;
			s = 60;
			h--;
		}
		if (s == 0)
		{
			s = 59;
			m--;
		}
		system("cls");
		cout << "\t\t******Your order is getting prepared ******" << endl;
		cout << "\t\t\t\t";
		if (h < 10 || m < 10 || s < 10)
		{
			if (h < 10)
			{
				cout << "0" << h << ":";
			}
			else
				cout << h << ":";
			if (m < 10)
			{
				cout << "0" << m << ":";
			}
			else
				cout << m << ":";
			if (s < 10)
			{
				cout << "0" << s--;
			}
			else
				cout << s--;

		}
		else
			cout << h << ":" << m << ":" << s--;
		Sleep(1000);
	}
	cout << endl << "Your order is ready and on the way" << endl;
}
void feedback()
{
	string feedbacks;
	fstream myfile;
	myfile.open("feedbacks.txt", ios::app);//to wappaned
	if (myfile.is_open())
	{
		getline(cin, feedbacks);
		myfile << feedbacks << endl;
		myfile.close();
	}

}

void recommended_meal()
{
	bool valied2;
	float price;
	cout << "PLEASE ENTER A PRICE YOU WANT TO SHOW YOU THE RECOMMENDED MEALS:  \n";
	cin >> price;
	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "PLEAS ENTER A VALID PRICE\n";
	}
	else if (price < 10)
	{
		cout << "not in range\n";
	}
	for (int i = 0; i < 10; i++)
	{
		if (price >= meals[i].price)
		{
			cout << "----------------------------------------------\n";
			cout << "the meal number is:  " << meals[i].num << endl;
			cout << "the meal name is:  " << meals[i].name << endl;
			if (meals[i].components != "")
			{
				cout << "the meal components is:   "; cout << meals[i].components << endl;
				cout << "the meal price is:   " << meals[i].price << endl;
				cout << "---------------------------------------------------";
			}
			else
				cout << "the meal price is:   " << meals[i].price << endl;
			cout << "---------------------------------------------------";
		}
	}
	cout << endl;
	cout << "enter Y/y to enter another price or N/n to leave\n";
	valied2 = validity();
	if (valied2 == true)
		return recommended_meal();
	if (valied2 == false)
		cout << "thanks\n";
}
void random_meal()
{
	srand(time(0));
	cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "\t\t\t\t\tWELCOME TO RANDOM MEAL\n";
	cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	for (int i = 0; i < 1; i++)
	{
		int x = rand() % 10;
		cout << "Meal Number " << (x + 1) << endl;
		cout << "***********" << endl;
		cout << "Meal Name is--> " << meals[x].name << endl;
		if (meals[x].components != "")
		{
			cout << "Meal components is--> " << meals[x].components << endl;
			cout << "Meal Price is--> " << meals[x].price << endl;
		}
		else
			cout << "Meal Price is--> " << meals[x].price << endl;

	}
}