//Library for different functions
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <limits>

using namespace std;
	
	/*
		========================================================================================
		total = Total price of purchase
		change = Change for the payment given
		
		counter - counter3
		-Represents to prevent multiple selection, repeating of text, infinite loops, and bugs.
		-It is also the ID to return in the previous console of the program.
		counter = used for the Go Back option in the subRam() function.
		counter1 = which model was selected in that brand
		counter3 = to prevent reusability of the discount code
		counter2 = to prevent displaying accessories
		========================================================================================
	*/
	int total, counter, counter1, counter3 = 1, change, counter2;
	
	//Holds user payment money
	float payment;
	/*
		====================================================
		choice = For Selecting Smartphone Brands
		phone = For Selecting Models of certain brand
		accessories = For Selecting accessory
		key1 - key5
		-Represents as user input from different functions
		====================================================
	*/
	char choice, phone, key1, key2, key3, key4, key5, accessories;
	
	//ID for every functions decrease certain stocks
	int stocks_counter;
	
	//A declared variable with certain value of price.
	int phone_price, key_storage, key_color, key_ram, discount, key_accessories;
	
	//Coupon = Max value to be entered by user
	//pin = For concatenation purpose
	string coupon[7], pin = "";
	
	//Represents Stocks for every model of smartphones
	int stocks_samsung[5] = {20, 20, 20, 20, 20};
	int stocks_apple[5] = {20, 20, 20, 20, 20};
	int stocks_google[5] = {20, 20, 20, 20, 20};
	int stocks_huawei[5] = {20, 20, 20, 20, 20};
	int stocks_xiaomi[5] = {20, 20, 20, 20, 20};
	
	/*
		=======================================================================
		2D Array
		model_name = Holds names for every index value
		model_id = where the model_name values would be set for output purposes
		=======================================================================
	*/
	string model_name[5][5] = { 
								{"Samsung Galaxy S9+","Samsung Galaxy Note 8", "Samsung Galaxy A", "Samsung Galaxy J7", "Samsung Galaxy J"},
								{"iPhone X", "iPhone 6+", "Iphone 6","iPhone 5+", "Iphone 5"},
								{"Google Pixel 2","Google Pixel 2 XL", "Google Pixel", "One Plus 6","One Plus 5"},
								{"Huawei Nova 3i","Huawei Mate 8", "Huawei P20 Lite", "Huawei Nova 2i","Huawei GR5"},
								{"Xiaomi Redmi Note 5","Xiaomi Pocophone", "Xiaomi Mi A1", "Xiaomi Mi A2","Xiaomi Mi Mix 2"}							
						   	  };
	string model_id; 
	
	//Arrays that holds every user input
	string model_color[5] = {"White Variant","Black Variant","Gold Variant","Gray Variant","Silver Variant"};
	string model_ram[5] = {"2 GB", "3 GB", "4 GB", "6 GB", "8 GB"};
	string model_storage[5] = {"8 GB", "16 GB", "32 GB", "64 GB ", "128 GB"};
	string model_accessories[5] = {"Earphones", "Power Bank", "Selfie Stick", "Cases", "Phone Charms"};
	
	/*
		======================
		model_sID = Brand
		model_rID = RAM
		model_cID = Color
		model_aID = Accessory
		======================
	*/
	
	string model_sID, model_rID, model_cID, model_aID;
	
	//Windows Supported Function that Handle Console Color
	HANDLE hSetColor = GetStdHandle(STD_OUTPUT_HANDLE);
	
//User-Define Functions for later on purposes of the program
void subModelSamsung();
void subStorage();
void subColor();
void subTotalSamsung();
void subModelApple();
void subModelGoogle();
void subModelHuawei();
void subModelXiaomi();
void subRam();
void subReceipt();
void Receipt();
void DecreaseStocks();
void Message();
void TotalDisplay();
void Accessories();
char Discount();

int main()
{
	//Console Upper Part Title
	system("Title The Phone Keepers");
	
	cout << 	"\t\t _______________________________________\n"
				"\t\t|\t\tPHONE BRAND\t\t|\n"
				"\t\t|\t\t-----------\t\t|\n\t\t|\t\t\t\t\t|\n"
				"\t\t|\tPress [1] Samsumg\t\t|\n"
				"\t\t|\tPress [2] Apple\t\t\t|\n"
				"\t\t|\tPress [3] Google Oneplus\t|\n"
				"\t\t|\tPress [4] Huawei\t\t|\n"
				"\t\t|\tPress [5] Xiaomi\t\t|\n"
				"\t\t|\t\t\t\t\t|\n"
				"\t\t|_______________________________________|" << endl;
						
			cout << "\n\t\tEnter Brand Here: ";
			
		//Algorithm to prevent other inputs from the user.
		do{
				
			do{
			choice = getch();
			}while(choice <= '0' || choice >= '6');
			
				if(choice >= 'A' && choice <= 'Z' || choice >= 'a' && choice <= 'z'){
					//Delete the previous users input
					cout << "\b ";
				}
			else if(choice >= '1' && choice <= '9'){		
			
			system("cls");
			
			//Control Structures for Selection of Users Input
			if(choice == '1'){
				//A Functions to go from the next code blocks of a console
				subModelSamsung();
			}else if(choice == '2'){
				subModelApple();
			}else if(choice == '3'){
				subModelGoogle();
			}else if(choice == '4'){
				subModelHuawei();
			}else if(choice == '5'){
				subModelXiaomi();
			}
		}
			
			}while(choice >= 'A' && choice <= 'Z' || choice >= 'a' && choice <= 'z' || choice <= '0' && choice >= '6');	
}

void subModelSamsung(){
	
	//stocks_counter is an ID for DecreaseStocks() function to determine which brand should have its stock decrease
	stocks_counter = 1;
	
	cout << "\t\t __________________________________________________\n"
			"\t\t|\t\tPHONE MODEL\t\t|  STOCKS  |\n"
			"\t\t|\t\t-----------\t\t|  ------  |\n\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|\tPress [1] Galaxy S9+\t\t|    " << stocks_samsung[0] << "    |\n"
			"\t\t|\tPress [2] Galaxy Note 8\t\t|    " << stocks_samsung[1] <<"    |\n"
			"\t\t|\tPress [3] Galaxy A\t\t|    " << stocks_samsung[2] <<"    |\n"
			"\t\t|\tPress [4] Galaxy J7\t\t|    " << stocks_samsung[3] <<"    |\n"
			"\t\t|\tPress [5] Galaxy J\t\t|    " << stocks_samsung[4] <<"    |\n"
			"\t\t|\tPress [6] 'Go-Back'\t\t|    \t   |\n" 
			"\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|_______________________________________|__________|" << endl;
	cout << "\n\t\tChoose Smartphone: ";
	
	do{
					
				do{
				phone = getch();
				}while(phone <= '0' || phone >= '7');
				
				if(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z'){
					cout << "\b ";
				}
				else if(phone >= '1' && phone <= '9'){	
				system("cls");
				counter = 1;
				
				if(phone == '1'){
					counter1 = 1;
					//Checks if the Stocks is still Available
					if(stocks_samsung[0] == 0){
						Message();
						subModelSamsung();
					}
					//Here's the use of 2D Array that holds the value of one variable to another
					//the row is the brand while the column is the text model value which was then set to model_id for output
					model_id = model_name[0][0];
					phone_price = 15000;
					//The line below means that it will go to subStorage() function after the process here is done
					subStorage();
				}
				else if(phone == '2'){
					counter1 = 2;
					if(stocks_samsung[1] == 0){
						Message();
						subModelSamsung();
					}
					model_id = model_name[0][1];
					phone_price = 14000;
					subStorage();
				}
				else if(phone == '3'){
					counter1 = 3;
					if(stocks_samsung[2] == 0){
						Message();
						subModelSamsung();
					}
					model_id = model_name[0][2];
					phone_price = 13000;
					subStorage();
				}
				else if(phone == '4'){
					counter1 = 4;
					if(stocks_samsung[3] == 0){
						Message();
						subModelSamsung();
					}
					model_id = model_name[0][3];
					phone_price = 12000;
					subStorage();
				}
				else if(phone == '5'){
					counter1 = 5;
					if(stocks_samsung[4] == 0){
						Message();
						subModelSamsung();
					}
					model_id = model_name[0][4];
					phone_price = 11000;
					subStorage();
				}
				else if(phone == '6'){
					main();
				}
		}
	}while(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z');
}

void subModelApple(){
	
		stocks_counter = 2;
		
	cout << "\t\t __________________________________________________\n"
			"\t\t|\t\tPHONE MODEL\t\t|  STOCKS  |\n"
			"\t\t|\t\t-----------\t\t|  ------  |\n\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|\tPress [1] iPhone X\t\t|    " << stocks_apple[0] << "    |\n"
			"\t\t|\tPress [2] iPhone 6+\t\t|    " << stocks_apple[1] << "    |\n"
			"\t\t|\tPress [3] iPhone 6\t\t|    " << stocks_apple[2] << "    |\n"
			"\t\t|\tPress [4] iPhone 5+\t\t|    " << stocks_apple[3] << "    |\n"
			"\t\t|\tPress [5] iPhone 5\t\t|    " << stocks_apple[4] << "    |\n"
			"\t\t|\tPress [6] 'Go-Back'\t\t|\t   |\n" 
			"\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|_______________________________________|__________|" << endl;
	cout << "\n\t\tChoose Smartphone: ";
				
	do{
					
				do{
				phone = getch();
				}while(phone <= '0' || phone >= '7');
				
				if(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z'){
					cout << "\b ";
				}
				else if(phone >= '1' && phone <= '9'){					
				system("cls");
				counter = 2;
				
				if(phone == '1'){
					counter1 = 1;
					if(stocks_apple[0] == 0){
						Message();
						subModelApple();
					}
					model_id = model_name[1][0];
					phone_price = 30000;
					subStorage();
				}
				else if(phone == '2'){
					counter1 = 2;
					if(stocks_apple[1] == 0){
						Message();
						subModelApple();
					}
					model_id = model_name[1][1];
					phone_price = 20000;
					subStorage();
				}
				else if(phone == '3'){
					counter1 = 3;
					if(stocks_apple[2] == 0){
						Message();
						subModelApple();
					}
					model_id = model_name[1][2];
					phone_price = 15000;
					subStorage();
				}
				else if(phone == '4'){
					counter1 = 4;
					if(stocks_apple[3] == 0){
						Message();
						subModelApple();
					}
					model_id = model_name[1][3];
					phone_price = 12000;
					subStorage();
					
				}
				else if(phone == '5'){
					counter1 = 5;
					if(stocks_apple[4] == 0){
						Message();
						subModelApple();
					}
					model_id = model_name[1][4];
					phone_price = 10000;
					subStorage();
				}
				else if(phone == '6'){
					main();
				}
			}
	}while(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z');
}

void subModelGoogle(){
	
		stocks_counter = 3;
	
	cout << "\t\t __________________________________________________\n"
			"\t\t|\t\tPHONE MODEL\t\t|  STOCKS  |\n"
			"\t\t|\t\t-----------\t\t|  ------  |\n\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|\tPress [1] Pixel 2\t\t|    " << stocks_google[0] << "    |\n"
			"\t\t|\tPress [2] Pixel 2 XL\t\t|    " << stocks_google[1] << "    |\n"
			"\t\t|\tPress [3] Pixel	  \t\t|    " << stocks_google[2] << "    |\n"
			"\t\t|\tPress [4] One Plus 6\t\t|    " << stocks_google[3] << "    |\n"
			"\t\t|\tPress [5] One Plus 5\t\t|    " << stocks_google[4] << "    |\n"
			"\t\t|\tPress [6] 'Go-Back'\t\t|\t   |\n" 
			"\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|_______________________________________|__________|" << endl;
	cout << "\n\t\tChoose Smartphone: ";
				
	do{
					
				do{
				phone = getch();
				}while(phone <= '0' || phone >= '7');
				
				if(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z'){
					cout << "\b ";
				}
				else if(phone >= '1' && phone <= '9'){
				system("cls");
				counter = 3;
				
				if(phone == '1'){
					counter1 = 1;
					if(stocks_google[0] == 0){
						Message();
						subModelGoogle();
					}
					model_id = model_name[2][0];
					phone_price = 15000;
					subStorage();
				}
				else if(phone == '2'){
					counter1 = 2;
					if(stocks_google[1] == 0){
						Message();
						subModelGoogle();
					}
					model_id = model_name[2][1];
					phone_price = 14000;
					subStorage();
				}
				else if(phone == '3'){
					counter1 = 3;
					if(stocks_google[2] == 0){
						Message();
						subModelGoogle();
					}
					model_id = model_name[2][2];
					phone_price = 13000;
					subStorage();
				}
				else if(phone == '4'){
					counter1 = 4;
					if(stocks_google[3] == 0){
						Message();
						subModelGoogle();
					}
					model_id = model_name[2][3];
					phone_price = 12000;
					subStorage();
				}
				else if(phone == '5'){
					counter1 = 5;
					if(stocks_google[4] == 0){
						Message();
						subModelGoogle();
					}
					model_id = model_name[2][4];
					phone_price = 11000;
					subStorage();
				}
				else if(phone == '6'){
					main();
				}
			}
	}while(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z');
}

void subModelHuawei(){
	
	stocks_counter = 4;
	
	cout << "\t\t __________________________________________________\n"
			"\t\t|\t\tPHONE MODEL\t\t|  STOCKS  |\n"
			"\t\t|\t\t-----------\t\t|  ------  |\n\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|\tPress [1] Huawei Nova 3i\t|    " << stocks_huawei[0] << "    |\n"
			"\t\t|\tPress [2] Huawei Mate 8\t\t|    " << stocks_huawei[1] << "    |\n"
			"\t\t|\tPress [3] Huawei P20 Lite\t|    " << stocks_huawei[2] << "    |\n"
			"\t\t|\tPress [4] Huawei Nova 2i\t|    " << stocks_huawei[3] << "    |\n"
			"\t\t|\tPress [5] Huawei GR5\t\t|    " << stocks_huawei[4] << "    |\n"
			"\t\t|\tPress [6] 'Go-Back'\t\t|\t   |\n" 
			"\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|_______________________________________|__________|" << endl;
	cout << "\n\t\tChoose Smartphone: ";
				
	do{
				
				do{
				phone = getch();
				}while(phone <= '0' || phone >= '7');
				
				if(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z'){
					cout << "\b ";
				}
				else if(phone >= '1' && phone <= '9'){			
				system("cls");
				counter = 4;
				
				if(phone == '1'){
					counter1 = 1;
					if(stocks_huawei[0] == 0){
						Message();
						subModelHuawei();
					}
					model_id = model_name[3][0];
					phone_price = 8000;
					subStorage();
				}
				else if(phone == '2'){
					counter1 = 2;
					if(stocks_huawei[1] == 0){
						Message();
						subModelHuawei();
					}
					model_id = model_name[3][1];
					phone_price = 9000;
					subStorage();
				}
				else if(phone == '3'){
					counter1 = 3;
					if(stocks_huawei[2] == 0){
						Message();
						subModelHuawei();
					}
					model_id = model_name[3][2];
					phone_price = 7000;
					subStorage();
				}
				else if(phone == '4'){
					counter1 = 4;
					if(stocks_huawei[3] == 0){
						Message();
						subModelHuawei();
					}
					model_id = model_name[3][3];
					phone_price = 3700;
					subStorage();
				}
				else if(phone == '5'){
					counter1 = 5;
					if(stocks_huawei[4] == 0){
						Message();
						subModelHuawei();
					}
					model_id = model_name[3][4];
					phone_price = 11000;
					subStorage();
				}
				else if(phone == '6'){
					main();
				}
			}
		}while(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z');
}

void subModelXiaomi(){
	
	stocks_counter = 5;
	
	cout << "\t\t __________________________________________________\n"
			"\t\t|\t\tPHONE MODEL\t\t|  STOCKS  |\n"
			"\t\t|\t\t-----------\t\t|  ------  |\n\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|\tPress [1] Redmi Note 5\t\t|    " << stocks_xiaomi[0] << "    |\n"
			"\t\t|\tPress [2] Pocophone\t\t|    " << stocks_xiaomi[1] << "    |\n"
			"\t\t|\tPress [3] Mi A1\t\t\t|    " << stocks_xiaomi[2] << "    |\n"
			"\t\t|\tPress [4] Mi A2\t\t\t|    " << stocks_xiaomi[3] << "    |\n"
			"\t\t|\tPress [5] Mi Mix 2\t\t|    " << stocks_xiaomi[4] << "    |\n"
			"\t\t|\tPress [6] 'Go-Back'\t\t|\t   |\n" 
			"\t\t|\t\t\t\t\t|\t   |\n"
			"\t\t|_______________________________________|__________|" << endl;
	cout << "\n\t\tChoose Smartphone: ";
	
	do{
				
				do{
				phone = getch();
				}while(phone <= '0' || phone >= '7');
				
				if(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z'){
					cout << "\b ";
				}else if(phone >= '1' && phone <= '9'){		
				system("cls");
				counter = 5;
				
				if(phone == '1'){
					counter1 = 1;
					if(stocks_xiaomi[0] == 0){
						Message();
						subModelXiaomi();
					}
					model_id = model_name[4][0];
					phone_price = 6500;
					subStorage();
				}
				else if(phone == '2'){
					counter1 = 2;
					if(stocks_xiaomi[1] == 0){
						Message();
						subModelXiaomi();
					}
					model_id = model_name[4][1];
					phone_price = 15000;
					subStorage();
				}
				else if(phone == '3'){
					counter1 = 3;
					if(stocks_xiaomi[2] == 0){
						Message();
						subModelXiaomi();
					}
					model_id = model_name[4][2];
					phone_price = 4000;
					subStorage();
				}
				else if(phone == '4'){
					counter1 = 4;
					if(stocks_xiaomi[3] == 0){
						Message();
						subModelXiaomi();
					}
					model_id = model_name[4][3];
					phone_price = 10000;
					subStorage();
				}
				else if(phone == '5'){
					counter1 = 5;
					if(stocks_xiaomi[4] == 0){
						Message();
						subModelXiaomi();
					}
					model_id = model_name[4][4];
					phone_price = 18000;
					subStorage();
				}
				else if(phone == '6'){
					main();
				}
			}
	}while(phone >= 'A' && phone <= 'Z' || phone >= 'a' && phone <= 'z');
}

void subStorage(){
		
	cout << "\t\t _______________________________________\n"
				"\t\t|\t\tPHONE STORAGE\t\t|\n"
				"\t\t|\t\t-------------\t\t|\n\t\t|\t\t\t\t\t|\n"
				"\t\t|\tPress [1] for 8 GB\t\t|\n"
				"\t\t|\tPress [2] for 16  GB\t\t|\n"
				"\t\t|\tPress [3] for 32  GB\t\t|\n"
				"\t\t|\tPress [4] for 64  GB\t\t|\n"
				"\t\t|\tPress [5] for 128 GB\t\t|\n"
			 	"\t\t|\tPress [6] 'Go-Back'\t\t|\n" 
			 	"\t\t|\t\t\t\t\t|\n"
				"\t\t|_______________________________________|" << endl;
	cout << "\n\t\tEnter Here: ";
					
	do{
						
			do{
			key1 = getch();
			}while(key1 <= '0' || key1 >= '7');
					
		if(key1 >= 'A' && key1 <= 'Z' || key1 >= 'a' && key1 <= 'z'){
				cout << "\b ";
		}
		else if(key1 >= '1' && key1 <= '9'){			
				system("cls");
				
				if(key1 == '1'){
					key_storage = 1000;
					model_sID = model_storage[0];
					subRam();
				}
				else if(key1 == '2'){
					key_storage = 2000;
					model_sID = model_storage[1];
					subRam();
				}
				else if(key1 == '3'){
					key_storage = 3000;
					model_sID = model_storage[2];
					subRam();
				}
				else if(key1 == '4'){
					key_storage = 4000;
					model_sID = model_storage[3];
					subRam();
				}
				else if(key1 == '5'){
					key_storage = 5000;
					model_sID = model_storage[4];
					subRam();
				}
				else if(key1 == '6'){
					
					/*
						==============================================================
						This if statement compares the "counter" variable value given
						depending on what brand was selected on the main() function. 
						This is to give this function the ability 
						to know what function went before it. 
						==============================================================
					*/
					if(counter == 1){
						  subModelSamsung();
                    }
					else if(counter == 2){
                          subModelApple();
                    }
					else if(counter == 3){
                          subModelGoogle();
                    }
					else if(counter == 4){
                          subModelHuawei();
                    }
					else if(counter == 5){
                          subModelXiaomi();
                    }     
				}
			}
	}while(key1 >= 'A' && key1 <= 'Z' || key1 >= 'a' && key1 <= 'z');
}

void subColor(){											
	cout << "\t\t _______________________________________\n"
				"\t\t|\t\tPHONE COLOR\t\t|\n"
				"\t\t|\t\t-----------\t\t|\n\t\t|\t\t\t\t\t|\n"
				"\t\t|\tPress [1] Color: White\t\t|\n"
				"\t\t|\tPress [2] Color: Black\t\t|\n"
				"\t\t|\tPress [3] Color: Gold\t\t|\n"
				"\t\t|\tPress [4] Color: Gray\t\t|\n"
				"\t\t|\tPress [5] Color: Silver\t\t|\n"
				"\t\t|\tPress [6] 'Go-Back'\t\t|\n"
				"\t\t|\t\t\t\t\t|\n"
				"\t\t|_______________________________________|" << endl;
	cout << "\n\t\tEnter Here: ";
	
	do{
					
					do{
					key2 = getch();
					}while(key2 <= '0' || key2 >= '7');
					
			if(key2 >= 'A' && key2 <= 'Z' || key2 >= 'a' && key2 <= 'z'){
				cout << "\b ";
			}
			else if(key2 >= '1' && key2 <= '9'){
				system("cls");
					
					if(key2 == '1'){
						model_cID = model_color[0];
						Accessories();
					}
					else if(key2 == '2'){
						model_cID = model_color[1];
						Accessories();
					}
					else if(key2 == '3'){
						model_cID = model_color[2];
						Accessories();
					}
					else if(key2 == '4'){
						model_cID = model_color[3];
						Accessories();
					}
					else if(key2 == '5'){
						model_cID = model_color[4];
						Accessories();
					}
					else if(key2 == '6'){
						subRam();
					}
				}
	}while(key2 >= 'A' && key2 <= 'Z' || key2 >= 'a' && key2 <= 'z');					
}

void subRam(){
	
	cout << "\t\t _______________________________________\n"
				"\t\t|\t\tPHONE RAM\t\t|\n"
				"\t\t|\t\t---------\t\t|\n\t\t|\t\t\t\t\t|\n"
				"\t\t|\tPress [1] for 2  GB\t\t|\n"
				"\t\t|\tPress [2] for 3  GB\t\t|\n"
				"\t\t|\tPress [3] for 4  GB\t\t|\n"
				"\t\t|\tPress [4] for 6  GB\t\t|\n"
				"\t\t|\tPress [5] for 8  GB\t\t|\n"
			 	"\t\t|\tPress [6] 'Go-Back'\t\t|\n" 
			 	"\t\t|\t\t\t\t\t|\n"
				"\t\t|_______________________________________|" << endl;
	cout << "\n\t\tEnter Here: ";
	
	do{
				
				do{
				key3 = getch();
				}while(key3 <= '0' || key3 >= '7');
						
			if(key3 >= 'A' && key3 <= 'Z' || key3 >= 'a' && key3 <= 'z'){
				cout << "\b ";
			}
			else if(key3 >= '1' && key3 <= '9'){
				system("cls");
					
				if(key3 == '1'){
					key_ram = 1000;
					model_rID = model_ram[0];
					subColor();
				}
				else if(key3 == '2'){
					model_rID = model_ram[1];
					key_ram = 2000;
					subColor();
				}
				else if(key3 == '3'){
					model_rID = model_ram[2];
					key_ram = 3000;
					subColor();
				}
				else if(key3 == '4'){
					model_rID = model_ram[3];
					key_ram = 4000;
					subColor();
				}
				else if(key3 == '5'){
					model_rID = model_ram[4];
                      key_ram =5000; 
					  subColor();   
				}
				else if(key3 == '6'){
                      subStorage();    
				}
			}
	}while(key3 >= 'A' && key3 <= 'Z' || key3 >= 'a' && key3 <= 'z');
}

void subTotalSamsung(){
	
	key_color = 299;
	
		//TotalDisplay() is called to run lines of codes that display on the console
		TotalDisplay();
		
		cout << "\t\tEnter Payment: ";
		
		//A loop that checks if the user input is numeric or if it is/are other characters on keyboard
		while(!(cin >> payment)){
		
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
				system("cls");
				//It set the color of the next cout text to "Red"
				SetConsoleTextAttribute(hSetColor, 4);
				cout << "\n\t\t\tValue: Not a Money.";
				//Text Color here is set to white again.
				SetConsoleTextAttribute(hSetColor, 7);
				
				TotalDisplay();
				cout << "\t\tEnter Payment: ";
				payment = 0;
		}
		
		if(payment > 100000){
			
			system("cls");
			SetConsoleTextAttribute(hSetColor, 4);
			cout << "\n\t\t\tInserted Large Value of Money!";
			SetConsoleTextAttribute(hSetColor, 7);
			subTotalSamsung();
		}
		
		if(payment < total){
			
			system("cls");
			SetConsoleTextAttribute(hSetColor, 4);
			cout << "\n\t\t\tInsufficient Money.";
			SetConsoleTextAttribute(hSetColor, 7);
			subTotalSamsung();
			
		}
	
		change = payment - total;
		subReceipt();
}

void subReceipt(){
		
		system("cls");
				cout << "\n\t\t\t\tItem Purchase\t\t    \n"
				"\t\t\t\t-------------\t\t    \n\t\t\t\t\t\t\t    \n\t\t\t";
				
					Receipt();

		cout << "\t\t|\t\t\t\t\t    |\n\t\t|\tPress [1] to Continue Transactions  |\n"
				"\t\t|\tPress [2] to Discount Code\t    |\n"
				"\t\t|\tPress [3] to Change Order\t    |\n"
			   	"\t\t|___________________________________________|" << endl;
		cout << "\n\t\tEnter Here: ";
		
		do{
		
			do{
			key4 = getch();
			}while(key4 <= '0' || key4 >= '4');
				
				
			if(key4 >= 'A' && key4 <= 'Z' || key4 >= 'a' && key4 <= 'z'){
				cout << "\b ";
			}
			else if(key4 >= '1' && key4 <= '9'){
				
				if(key4 == '1'){
					system("cls");
						cout << "\n\t\t\t\tReceipt\t\t    \n"
								"\t\t\t\t-------\t\t    \n\t\t\t\t\t\t\t    \n\t\t\t";
								Receipt();
								
						cout << "\t\t|\t\t\t\t\t    |\n\t\t|\tPress [1] to Buy.\t\t    |\n"
								"\t\t|\tPress [2] to Cancel.\t\t    |\n"
								"\t\t|\tPress [3] Go-Back\t\t    |\n"
								"\t\t|___________________________________________|" << endl;
						cout << "\n\t\tEnter Here: ";
				//Press [1] Continue Transactions
				do{
					key5 = getch();
				}while(key5  <= '0' || key5  >= '4');
				
						if(key5  >= 'A' && key5  <= 'Z' || key5  >= 'a' && key5  <= 'z'){
								cout << "\b ";
						}
						else if(key5  >= '1' && key5  <= '9'){
						//Press [1] to Buy	
							if(key5 == '1'){
								system("cls");
								cout << "\n\n\t\t _____________________________________\n"
										"\t\t|\t\t\t\t      |"
										"\n\t\t|      Thank you for purchasing!      |\n"
										"\t\t| Come back and get 10% Discount Off. |\n"
										"\t\t|\t Discount Code: reypogi\t      |\n"
										"\t\t|_____________________________________|" << endl;
								cout << "\n\t\t\tPress Any-key to Continue" << endl;
							
										getch();
										system("cls");
										//Initialize value of pin into an empty string to re-use the discount code again
										pin = "";
										counter3 = 1;
										key_accessories = 0;
											/*
												===========================================================================
												ifstream is a Function that reads a file
												PrintReceipt is a variable that reads the value inside the parameter.
												system() is a Windows Supported Functions that gives a programmer the power
												to start a certain application on the computer.
												
												-In this line of code we call the Receipt.html file
													
												After Reading a File, it must be closed to prevent 
												iteration of certain text inside a file	
												===========================================================================
											*/
										ifstream PrintReceipt("Receipt.html");
										system("Receipt.html");
										PrintReceipt.close();
										//When Transaction is done, it is the proper time to decrease the stock count of the model bought
										DecreaseStocks();
										//Repeats entire program
										main();
									}
						//Press [2] to Cancel			
							else if(key5 == '2'){
								/*
									===========================================================================
									MessageBox is a Function that supported by Windows, this functions shows a
									Dialog Box telling a certain statement to the user 
									===========================================================================
								*/
								MessageBox(NULL, "Unable to Process Transaction.", "Transaction Cancelled", MB_OK | MB_ICONINFORMATION);
								system("cls");
										
								cout << "\n\n\t\t _____________________________________\n"
										"\t\t|\t\t\t\t      |"
										"\n\t\t|\t   Program Terminated!\t      |\n"
										"\t\t|\t    No Longer Access!\t      |\n"
										"\t\t|_____________________________________|" << endl;
										exit(1);
									}
						//Press [3] to Go Back
							else if(key5 == '3'){
								subReceipt();
							}
									
					}while(key5 >= 'A' && key5 <= 'Z' || key5 >= 'a' && key5 <= 'z');
					
				}
				//Press [2] Discount Code
				else if(key4 == '2'){
					system("cls");
					Discount();
				}
				//Press [3] Change Order
				else if(key4 == '3'){
					system("cls");
					pin = "";
					counter3 = 1;
					key_accessories = 0;
					main();
				}
		}
	}while(key4 >= 'A' && key4 <= 'Z' || key4 >= 'a' && key4 <= 'z');
	
}

char Discount(){
	
	/*
		===========================================================================
		Here is an Array that accepts string value from the user
		and hide it as an "asterisk("*") and Concatenate it into an empty variable
		===========================================================================
	*/
	cout << "\n\t\tEnter a 7 Character Pin: ";
	for(int i = 0; i < 7; i++){
		coupon[i] = getch();
		pin = pin + coupon[i];
		cout << "*";	
	}
	
	getch();
	
	/*
		It checks whether the pin is equal or not
	*/
	if(pin == "reypogi"){
		system("cls");	
		
		if(counter3 == 1){
		cout << "\n\t\tYou have successfuly claimed your discount!" << endl;
			cout << "\t\t\tPress Any-key to Continue" << endl;
			getch();
			discount = total * 0.10; 
			total = total - discount;
			change = payment - total;
			counter3++;
			subReceipt();
		}
		else{
			system("cls");
			cout << "\n\t\t\tOops!Sorry Code Already Redeemed!";
			cout << "\n\t\t\t     Press Any-key to Continue" << endl;	
			getch();
			subReceipt();
		}	
		
	}
	
	else{
		pin = "";
		system("cls");
		cout << "\n\t\t\t Oops!Sorry Invalid Code.";
		cout << "\n\t\t\tPress Any-key to Continue" << endl;
		getch();
		subReceipt();
	}
	
}
void Receipt(){
	
		//These are Windows Supported Functions to get the present Date, Time, and Year of your Computer
		SYSTEMTIME time;
		GetLocalTime(&time);
		/*
			=====================================================================================
			ofstream is an stream functions that handles the user inputs and creating files.
			ReceiptFile is a varible where every user inputs is stored in it then transfer those
			information into files which is ("Receipt.html").
			=====================================================================================
			
		*/
		ofstream ReceiptFile("Receipt.html");
		
		cout << model_id << "\t\t    \n\t\t\t" << model_cID << "\t\t\t    "<< endl;
		if(counter2 == 1){
			cout << "\t\t\tAccessory: " << model_aID << "\t\t\t    " << endl;
		}else{
			cout << "\t\t\tAccessory: " << "None" << "\t\t\t    " << endl;
		}
		cout << "\t\t\tStorage: " << model_sID << "\t\t\t    " << endl;
		cout << "\t\t\tRAM: " << model_rID << "\t\t\t    " << endl;
		cout << "\t\t\tPayment: " << payment << "\t\t\t    " << endl;
		cout << "\t\t\tTotal: " << total << "\t\t\t    " << endl;
		cout << "\t\t\tChange: " << change << "\t\t\t    " << endl;
		cout << "\t\t\tDate: " << time.wMonth << "/" << time.wDay << "/" << time.wYear << "\t\t\t    " << endl;
		cout << "\t\t\tTime: " << time.wHour << ":" << time.wMinute << "\t\t\t    \n" << endl;
		cout << "\t\t ___________________________________________" << endl;
		
	/*
		===================================================================================
		It simply means to stored in ReceiptFile, and ReceiptFile holds those information.
		It uses the "<<" to insert information to that ReceiptFile Variable
		===================================================================================
	*/
	
	ReceiptFile <<	"<center><h2> Official Receipt </h2></center><br>"
					"<center><h1>[The Phone Keepers]</h1></center><br />" <<
				    "<h3 align =""center"">" << model_id << "<br /></h3>" <<
				    "<h3 align =""center"">" << model_cID << "<br /></h3>";
	
				    if(counter2 == 1){
	ReceiptFile << "<center>Accessory: " << model_aID << "<br /></center"; 
					}
					if(counter2 != 1){
	ReceiptFile << 	"<center>Accessory: " << "None" << "<br /></center"; 
					}
	ReceiptFile	<<  "<center>Storage: " << model_sID << "<br /></center>" <<
				   "<center>RAM: " << model_rID << "<br /></center>" <<
				   "<center>Payment: " << payment << "<br /></center>" <<
				   "<center>Total: " << total << "<br /></center>" <<
				   "<center>Change: " << change << "<br /></center>" <<
				   "<center>Date: " << time.wMonth << "/" << time.wDay << "/" << time.wYear << "<br /></center>" <<
				   "<center>Time: " << time.wHour << ":" << time.wMinute << "<br /><br />" <<
				   "<center><button onclick= ""self.close()"">Print</button></center>";
		//Again, after storing informations, ReceiptFile must be closed to prevent iteration of informations.
		ReceiptFile.close();			
}

void DecreaseStocks(){
	//Functions that decrease stocks, index by index depending on user selected items.
	// As stated earlier, stocks_counter is used to define which brand was selected
	//counter1 on the other hand is used to determine what model of which product was selected.
	if(stocks_counter == 1){
		if(counter1 == 1){
			stocks_samsung[0]--;
		}else if(counter1 == 2){
			stocks_samsung[1]--;
		}else if(counter1 == 3){
			stocks_samsung[2]--;
		}else if(counter1 == 4){
			stocks_samsung[3]--;
		}else if(counter1 == 5){
			stocks_samsung[4]--;
		}
	}
		
	if(stocks_counter == 2){
		if(counter1 == 1){
			stocks_apple[0]--;
		}else if(counter1 == 2){
			stocks_apple[1]--;
		}else if(counter1 == 3){
			stocks_apple[2]--;
		}else if(counter1 == 4){
			stocks_apple[3]--;
		}else if(counter1 == 5){
			stocks_apple[4]--;
		}
	}
			
	if(stocks_counter == 3){
		if(counter1 == 1){
			stocks_google[0]--;
		}else if(counter1 == 2){
			stocks_google[1]--;
		}else if(counter1 == 3){
			stocks_google[2]--;
		}else if(counter1 == 4){
			stocks_google[3]--;
		}else if(counter1 == 5){
			stocks_google[4]--;
		}
	}
			
	if(stocks_counter == 4){
		if(counter1 == 1){
			stocks_huawei[0]--;
		}else if(counter1 == 2){
			stocks_huawei[1]--;
		}else if(counter1 == 3){
			stocks_huawei[2]--;
		}else if(counter1 == 4){
			stocks_huawei[3]--;
		}else if(counter1 == 5){
			stocks_huawei[4]--;
		}
	}
					
	if(stocks_counter == 5){
		if(counter1 == 1){
			stocks_xiaomi[0]--;
		}else if(counter1 == 2){
			stocks_xiaomi[1]--;
		}else if(counter1 == 3){
			stocks_xiaomi[2]--;
		}else if(counter1 == 4){
			stocks_xiaomi[3]--;
		}else if(counter1 == 5){
			stocks_xiaomi[4]--;
		}
	}
	
}

void Message(){
	//A Prompt Box, if there's no available stock of the selected model.
	MessageBox(NULL, "No Available Stocks.", "Out of Stocks!", MB_OK | MB_ICONINFORMATION);
}

void TotalDisplay(){
	
		total = phone_price + key_storage + key_color + key_ram + key_accessories;
		cout << "\n\n\t\tModel Price: " << phone_price << endl;
		cout << "\t\tStorage Price: " << key_storage << endl;
		cout << "\t\tRam Price: " << key_ram << endl;
		cout << "\t\tColor Price: " << key_color << endl;
		if(counter2 == 1){
		cout << "\t\tAccessory Price: " << key_accessories << endl;
		}
		cout << "\t\t=======================\n";
		cout << "\t\tTotal is " << total << endl;
	
}

void Accessories(){
	system("cls");
					cout << 	"\t\t _______________________________________\n"
								"\t\t|\t     PHONE ACCESSORIES\t\t|\n"
								"\t\t|\t     -----------------\t\t|\n\t\t|\t\t\t\t\t|\n"
								"\t\t|\tPress [1] Earphones\t\t|\n"
								"\t\t|\tPress [2] Power Bank\t\t|\n"
								"\t\t|\tPress [3] Selfie Stick\t\t|\n"
								"\t\t|\tPress [4] Cases\t\t\t|\n"
								"\t\t|\tPress [5] Phone Charms\t\t|\n"
								"\t\t|\tPress [6] 'Just Cotinue'\t|\n"
								"\t\t|\tPress [7] 'Go-Back'\t\t|\n"
								"\t\t|\t\t\t\t\t|\n"
								"\t\t|_______________________________________|" << endl;
						
			cout << "\n\t\tEnter Here: ";
			
				do{
					accessories = getch();
				}while(accessories <= '0' || accessories >= '8');
				
					if(accessories >= 'A' && accessories <= 'Z' || accessories >= 'a' && accessories <= 'z'){
						cout << "\b ";
					}
					else if(accessories >= '1' && accessories <= '9'){
						system("cls");
						counter2 = 1;
						if(accessories == '1'){
							key_accessories = 1500;
							model_aID = model_accessories[0];
							subTotalSamsung();
						}else if(accessories == '2'){
							key_accessories = 2500;
							model_aID = model_accessories[1];
							subTotalSamsung();
						}else if(accessories == '3'){
							key_accessories = 1000;
							model_aID = model_accessories[2];
							subTotalSamsung();
						}else if(accessories == '4'){
							key_accessories = 500;
							model_aID = model_accessories[3];
							subTotalSamsung();
						}else if(accessories == '5'){
							key_accessories = 300;
							model_aID = model_accessories[4];
							subTotalSamsung();
						}else if(accessories == '6'){
							counter2++;
							subTotalSamsung();
						}else if(accessories == '7'){
							system("cls");
							subColor();
						}
					}
}
