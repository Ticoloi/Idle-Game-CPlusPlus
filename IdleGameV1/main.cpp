#include <iostream>
#include <chrono>
#include <thread> 
using namespace std;

//for closing the game:
bool close = false;

//Game essential var:
double number;
double nps;
double npc = 1.00;

//Key var:
const double KEY_PRICE = 5.00;
const double KEY_PRODUCTION = 0.3;
double KeyPrice;
double KeyProduction = KEY_PRODUCTION;
int KeyBought = 0;

//Calculator var
const double CALCULATOR_PRICE = 25.00;
const double CALCULATOR_PRODUCTION = 1;
double CalculatorPrice;
double CalculatorProduction = CALCULATOR_PRODUCTION;
int CalculatorBought = 0;


//Terminal var
const double TERMINAL_PRICE = 750.00;
const double TERMINAL_PRODUCTION = 10;
double TerminalPrice;
double TerminalProduction = TERMINAL_PRODUCTION;
int TerminalBought = 0;

//Upgrades vars
bool CanBuyKeyKeyUpgrade = false;
bool CanUnlockKeyKeyUpgrade = true;
bool HaveKeyKeyUpgrade = false;
bool CanBuyCasioUpgrade = false;
bool CanUnlockCasioUpgrade = true;
bool HaveCasioUpgrade = false;


//String constants for text:
const string NEW_TO_DO = "\nPlease write a new order:";
const string ORDER_ERROR = "ERROR, not an order!";

//String Constants, help menu
const string HELP_MENU = "Welcome to the help menu! All you see are orders, write the order so you will get help.";
const string HELP_MENU_OPTIONS = "\n1- close\n2- buy\n4- +\n5- info\nleave";
const string HELP_MENU_CLOSE = "With this order you can close the game";
const string HELP_MENU_BUY = "It opens the shop, in the shop, you can buy upgrades or builds";
const string HELP_MENU_PLUS = "If you write a +, you will get a number, so you need to write all the + you can, ONLY ONE per order, in the game, the amount of numbers you gain per + is called npc (number per click?), and you can upgrade your npc in the shop!";
const string HELP_MENU_INFO = "It opens the info menu, you will get info like npc, the numbers you have, etc.";
const string YOU_GOT_PLUS = "You got: ";;
const string AND_NOW_YOU_HAVE_PLUS = " numbers. You now have: ";

//String Constants, build descriptions
const string KEY_DESCRIPTION = "A + key to write more + and get more numbers!";
const string CALCULATOR_DESCRIPTION = "A Casio calculator to calculate more numbers!";
const string TERMINAL_DESCRIPTION = "A terminal to get more numbers";

//String constants, info menu
const string INFO_WELCOME = "Welcome to the info menu! Here you can see your stats and other.... info. ";
const string INFO_NPC = "Numbers per (click?): ";
const string INFO_NPS = "Numbers per second: ";
const string INFO_CREDITS = "Game (Its a game?) made by Eloi, you can edit this game if you want :). If you like this project, play Cookie clicker";



// how many builds you have?
const string KEY_OWNED = " Keys owned: ";
const string CALCULATOR_OWNED = " Calculators owned: ";
const string TERMINAL_OWNED = " Terminal owned: ";


//String Constants, shop
const string PRICE = " Price: ";
const string SHOP_NPS = " nps: ";
const string SHOP_CONFIRMATION = " Do you REALLY want to buy this? yes/no";
const string YOU_BOUGHT = "You bought a new ";
const string SHOP_UPGRADE_WELCOME = "Welcome to the upgrade menu! Please select an upgrade, if you don't see any upgrade, write leave.";
const string YOU_CANT_BUY_THAT = "Sorry, not enought numbers, please write more + and get more numbers!";

//String constants, notifications
const string NEW_UPGRADE = "You unlocked a new upgrade! Open the shop menu writing the order buy.";

//Upgrade String Constants
const string KEYKEY_DESCRIPTION = "Your + key and keys will get a double number production!";
const string KEYKEY_USER_BOUGHT = "You bought the keykey upgrade! Now lets write a + a lot of times!";
const string CASIO_DESCRIPTION = "Wow, the calculators now will not explode!";
const string CASIO_USER_BOUGHT = "The calculators are now OP!";

// Upgrade constants
const int KEYKEY_UPGRADE_PRICE = 100;
const int KEYKEY_DOBLE_UNLOCK = 2;
const int CASIO_UPGRADE_PRICE = 1000;
const int CASIO_UPGRADE_UNLOCK = 5;

string order;


void KeyKeyUnlock(){
    while(close == false){
        if(KeyBought >= KEYKEY_DOBLE_UNLOCK){
                if(CanUnlockKeyKeyUpgrade == true){
                    cout << endl << NEW_UPGRADE << NEW_TO_DO << endl;
                    CanBuyKeyKeyUpgrade = true;
                    CanUnlockKeyKeyUpgrade = false;
                }
        }
    }
}

void KeyKeyWork(){
    bool upgradet = false;
    while(close == false){
         if(HaveKeyKeyUpgrade == true){
            if(upgradet == false){
                KeyProduction = KeyProduction*2;
                npc = npc*2;
                upgradet = true;
            }
        }
    }
}


void CasioWork(){
    bool upgradet = false;
    while(close == false){
        if(HaveCasioUpgrade == true){
            if(upgradet == false){
                CalculatorProduction = CalculatorProduction*2;
                upgradet = true;
            }
        }
    }
}


void CasioUnlock(){
    while(close == false){
        if(CalculatorBought >= CASIO_UPGRADE_UNLOCK){
                if(CanUnlockCasioUpgrade == true){
                    cout << endl << NEW_UPGRADE << NEW_TO_DO << endl;
                    CanBuyCasioUpgrade = true;
                    CanUnlockCasioUpgrade = false;
                }
        }
    }
}




void funcion1() {
    while(close == false){
        std::this_thread::sleep_for(std::chrono::seconds(1));  
        number+=nps;
        nps = KeyBought*KeyProduction + CalculatorBought*CalculatorProduction + TerminalBought*TerminalProduction; 
    }  
}

void funcion2() {
    while(close != true){
            cin >> order;
            if(order == "close") close = true;
            else if(order == "help"){
                cout << endl << HELP_MENU << HELP_MENU_OPTIONS << endl;
                cin >> order;
                if(order == "close") cout << endl << HELP_MENU_CLOSE << NEW_TO_DO << endl;
                else if(order == "info") cout << endl << HELP_MENU_INFO << NEW_TO_DO << endl;
                else if(order == "leave") cout << endl << NEW_TO_DO << endl;
                else if(order == "+") cout << endl << HELP_MENU_PLUS << NEW_TO_DO << endl;
                else if(order == "buy") cout << endl << HELP_MENU_BUY << NEW_TO_DO << endl;
                else cout << ORDER_ERROR << NEW_TO_DO << endl;
            }

            else if(order == "+") {number+=npc; cout << YOU_GOT_PLUS <<  npc << AND_NOW_YOU_HAVE_PLUS << number << endl;}

            else if(order == "info") {
                cout << endl << INFO_WELCOME << endl << INFO_NPC << npc << endl << INFO_NPS << nps << endl << INFO_CREDITS << endl << NEW_TO_DO << endl;

            }

            else if(order == "buy") {

                cout<< endl << "A build or a Upgrade?\nbuild\nupgrade" <<endl;
                cin >> order;
                    if(order == "build"){

                        cout<< endl << "Select a build:\nkey\ncalculator\nterminal" <<endl;
                        cin >> order;

                        if(order == "key"){
                            KeyPrice = KEY_PRICE + KeyBought/10.00;
                            cout<< endl << KEY_DESCRIPTION << PRICE << KeyPrice << SHOP_NPS << KeyProduction << KEY_OWNED << KeyBought << SHOP_CONFIRMATION <<endl;
                            cin >> order;
                            if(order == "yes") {
                                    if(number >= KeyPrice){
                                        cout << endl << YOU_BOUGHT << "key!" << NEW_TO_DO << endl;
                                        KeyBought++;
                                        number = number - KeyPrice;
                                        }
                                    else cout << endl << YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else cout <<  NEW_TO_DO << endl;
                            }

                            else if(order == "calculator"){
                            CalculatorPrice = CALCULATOR_PRICE + CalculatorBought;
                            cout<< endl << CALCULATOR_DESCRIPTION << PRICE << CalculatorPrice << SHOP_NPS << CalculatorProduction << CALCULATOR_OWNED << CalculatorBought << SHOP_CONFIRMATION <<endl;
                            cin >> order;
                            if(order == "yes") {
                                    if(number >= CalculatorPrice){
                                        cout << endl << YOU_BOUGHT << "calculator!" << NEW_TO_DO << endl;
                                        CalculatorBought++;
                                        number = number - CalculatorPrice;
                                        }
                                    else cout << endl << YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else cout <<  NEW_TO_DO << endl;
                            }

                            else if(order == "terminal"){
                            TerminalPrice = TERMINAL_PRICE + TerminalBought*75;
                            cout<< endl << TERMINAL_DESCRIPTION << PRICE << TerminalPrice << SHOP_NPS << TerminalProduction << TERMINAL_OWNED << TerminalBought << SHOP_CONFIRMATION <<endl;
                            cin >> order;
                            if(order == "yes") {
                                    if(number >= TerminalPrice){
                                        cout << endl << YOU_BOUGHT << "terminal!" << NEW_TO_DO << endl;
                                        TerminalBought++;
                                        number = number - TerminalPrice;
                                        }
                                    else cout << endl << YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else cout <<  NEW_TO_DO << endl;
                            }

                            else cout << ORDER_ERROR << NEW_TO_DO << endl;

                        }
                        else if(order == "upgrade"){
                            cout << endl << SHOP_UPGRADE_WELCOME;
                            if(CanBuyKeyKeyUpgrade == true) cout << endl << "keykey";
                            if(CanBuyCasioUpgrade == true) cout << endl << "casio";
                            cout << endl;
                            cin >> order;
                            if (order == "keykey"){
                                    if(CanBuyKeyKeyUpgrade == true){
                                        cout << endl <<  KEYKEY_DESCRIPTION << PRICE << KEYKEY_UPGRADE_PRICE << SHOP_CONFIRMATION << endl;
                                        cin >> order;
                                        if(order == "yes"){
                                                if(number >= KEYKEY_UPGRADE_PRICE){
                                                    cout << endl << KEYKEY_USER_BOUGHT << endl;
                                                    CanBuyKeyKeyUpgrade = false;
                                                    HaveKeyKeyUpgrade = true;
                                                }
                                                else cout << endl << YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                        }
                                        else cout <<  NEW_TO_DO << endl;
                                    }
                                    else cout << ORDER_ERROR << NEW_TO_DO << endl;

                        }
                            if (order == "casio"){
                                    if(CanBuyCasioUpgrade == true){
                                        cout << endl <<  CASIO_DESCRIPTION << PRICE << CASIO_UPGRADE_PRICE << SHOP_CONFIRMATION << endl;
                                        cin >> order;
                                        if(order == "yes"){
                                                if(number >= CASIO_UPGRADE_PRICE){
                                                    cout << endl << CASIO_USER_BOUGHT << endl;
                                                    CanBuyCasioUpgrade = false;
                                                    HaveCasioUpgrade = true;
                                                }
                                                else cout << endl << YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                        }
                                        else cout <<  NEW_TO_DO << endl;
                                    }
                                    else cout << ORDER_ERROR << NEW_TO_DO << endl;

                        }
                        else cout << NEW_TO_DO << endl;
                        }
                        else cout << ORDER_ERROR << NEW_TO_DO << endl;
            }
            else cout << ORDER_ERROR << NEW_TO_DO << endl;
    }
 }




int main(){

    cout << "Welcome to this idle game! Write + and press enter. Write help to get help." << endl;

  std::thread t1(funcion1);
  std::thread t2(funcion2);
  std::thread t3(CasioWork);
  std::thread t4(CasioUnlock);
  std::thread t5(KeyKeyWork);
  std::thread t6(KeyKeyUnlock);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
    cout << endl << "Bye!" << endl;
    return 0;
}

