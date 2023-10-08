#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

//for closing the game:
bool close = false;

//Game essential var:
double number;
double nps;
double bnps;
double npc = 1.00;
string order;

//Key var:
const double KEY_PRICE = 5.00;
const double KEY_PRODUCTION = 0.2;
double KeyPrice;
double KeyProduction = KEY_PRODUCTION;
int KeyBought = 0;

//Calculator var
const double CALCULATOR_PRICE = 75.00;
const double CALCULATOR_PRODUCTION = 1;
double CalculatorPrice;
double CalculatorProduction = CALCULATOR_PRODUCTION;
int CalculatorBought = 0;


//Terminal var
const double TERMINAL_PRICE = 850.00;
const double TERMINAL_PRODUCTION = 10;
double TerminalPrice;
double TerminalProduction = TERMINAL_PRODUCTION;
int TerminalBought = 0;

//Meme var
const double MEME_PRICE = 1850.00;
const double MEME_PRODUCTION = 45;
double MemePrice;
double MemeProduction = MEME_PRODUCTION;
int MemeBough = 0;

//Upgrades unlcok bool
bool CanBuyKeyKeyUpgrade = false;
bool CanUnlockKeyKeyUpgrade = true;
bool HaveKeyKeyUpgrade = false;

bool CanBuyCasioUpgrade = false;
bool CanUnlockCasioUpgrade = true;
bool HaveCasioUpgrade = false;

bool CanBuyBinaryUpgrade = false;
bool CanUnlockBinaryUpgrade = true;
bool HaveBinaryUpgrade = false;

// Upgrade constants
const int KEYKEY_UPGRADE_PRICE = 100;
const int KEYKEY_DOBLE_UNLOCK = 5;

const int CASIO_UPGRADE_PRICE = 1000;
const int CASIO_UPGRADE_UNLOCK = 10;

const int BINARY_UPGRADE_PRICE = 1000;
const int BINARY_UPGRADE_UNLOCK = 100;

//multipler
double multiplier = 0.00;
const int BINARY_MULTIPLIER = 1;

//String constants for text:
const string NEW_TO_DO = "\nPlease write a new order:";
const string ORDER_ERROR = "\nERROR, not an order!";
const string LEAVE = "leave";
const string YES = "yes";
const string NO = "no";


//String Basic Orders
const string HELP = "help";
const string CLOSE = "close";
const string BUY = "buy";
const string INFO = "info";
const string PLUS = "+";

//String buy suborders
const string BUY_UPGRADE = "upgrade";
const string BUY_BUILD = "build";

//String buy upgrades and builds
const string KEY = "key";
const string MEME = "meme";
const string TERMINAL = "terminal";
const string CALCULATOR = "calculator";

const string KEYKEY = "keykey";
const string CASIO = "casio";
const string BINARY = "binary";

//String Constants, help menu
const string HELP_MENU_WELCOME = "Welcome to the help menu! All you see are orders, write the order so you will get help.";
const string HELP_MENU_CLOSE = "With this order you can close the game";
const string HELP_MENU_BUY = "It opens the shop, in the shop, you can buy upgrades or builds";
const string HELP_MENU_PLUS = "If you write a +, you will get a number, so you need to write all the + you can, ONLY ONE per order, in the game, the amount of numbers you gain per + is called npc (number per click?), and you can upgrade your npc in the shop!";
const string HELP_MENU_INFO = "It opens the info menu, you will get info like npc, the numbers you have, etc.";


//String Constants, +
const string YOU_GOT_PLUS = "You got: ";;
const string AND_NOW_YOU_HAVE_PLUS = " numbers. You now have: ";

//String constants, info menu
const string INFO_WELCOME = "Welcome to the info menu! Here you can see your stats and other.... info. ";
const string INFO_NPC = "Numbers per (click?): ";
const string INFO_NPS = "Numbers per second: ";
const string INFO_CREDITS = "Game (Its a game?) made by Eloi, you can edit this game if you want :). If you like this project, play Cookie clicker";

//String Constants, build descriptions
const string SHOP_KEY_DESCRIPTION = "A + key to write more + and get more numbers!";
const string SHOP_CALCULATOR_DESCRIPTION = "A Casio calculator to calculate more numbers!";
const string SHOP_TERMINAL_DESCRIPTION = "A terminal to get more numbers";
const string SHOP_MEME_DESCRIPTION = "Haa ha ha, look, a cat meme!";

// how many builds you have?
const string KEY_OWNED = " Keys owned: ";
const string CALCULATOR_OWNED = " Calculators owned: ";
const string TERMINAL_OWNED = " Terminal owned: ";
const string MEME_OWNED = " Memes owned: ";

//String Constants, shop
const string SHOP_WELCOME = "Welcome to the shop! Please select an order:";
const string SHOP_BUILD_WELCOME = "Welcome to the build menu! Please select a build:";
const string SHOP_LEAVE = "OK, bye!";
const string SHOP_PRICE = " Price: ";
const string SHOP_NPS = " nps: ";
const string SHOP_CONFIRMATION = " Do you REALLY want to buy this?";
const string SHOP_YOU_BOUGHT = "You bought a new ";
const string SHOP_UPGRADE_WELCOME = "Welcome to the upgrade menu! Please select an upgrade, if you don't see any upgrade, write leave.";
const string SHOP_YOU_CANT_BUY_THAT = "Sorry, not enought numbers, please write more + and get more numbers!";

//String constants, notifications
const string NEW_UPGRADE = "You unlocked a new upgrade! Open the shop menu writing the order buy.";

//Upgrade String Constants
const string KEYKEY_DESCRIPTION = "Your + key and keys will get a double number production!";
const string KEYKEY_USER_BOUGHT = "You bought the keykey upgrade! Now lets write a + a lot of times!";

const string CASIO_DESCRIPTION = "Wow, the calculators now will not explode!";
const string CASIO_USER_BOUGHT = "The calculators are now OP!";

const string BINARY_DESCRIPTION = "The 0 and the 1 will be giving you 1% more numbers";
const string BINARY_USER_BOUGHT = "You are now a boolean";



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


void BinaryUnlock(){
    while(close == false){
        if(number >= BINARY_UPGRADE_UNLOCK){
                if(CanUnlockBinaryUpgrade == true){
                    CanBuyBinaryUpgrade = true;
                    CanUnlockBinaryUpgrade = false;
                    cout << endl << NEW_UPGRADE << NEW_TO_DO << endl;
                }
        }
    }
}

void funcion1() {
    while(close == false){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        number+=nps;
        bnps = KeyBought*KeyProduction + CalculatorBought*CalculatorProduction + TerminalBought*TerminalProduction + MemeBough*MemeProduction;
        nps = bnps + bnps*multiplier/100;
    }
}

void funcion2() {
    while(close != true){
            cin >> order;
            if(order == CLOSE) close = true;
            else if(order == HELP){
                cout << endl << HELP_MENU_WELCOME << endl << "1- " << BUY << endl <<"2- " << CLOSE << endl <<"3- " << INFO << endl <<"4- " << PLUS << endl << LEAVE << endl;
                cout << "<" << HELP << "> ";
                cin >> order;
                if(order == CLOSE) cout << endl << HELP_MENU_CLOSE << NEW_TO_DO << endl;
                else if(order == INFO) cout << endl << HELP_MENU_INFO << NEW_TO_DO << endl;
                else if(order == LEAVE) cout << endl << NEW_TO_DO << endl;
                else if(order == PLUS) cout << endl << HELP_MENU_PLUS << NEW_TO_DO << endl;
                else if(order == BUY) cout << endl << HELP_MENU_BUY << NEW_TO_DO << endl;
                else cout << ORDER_ERROR << NEW_TO_DO << endl;
            }

            else if(order == PLUS) {number+=npc; cout << YOU_GOT_PLUS <<  npc << AND_NOW_YOU_HAVE_PLUS << number << endl;}

            else if(order == INFO) {
                cout << endl << INFO_WELCOME << endl << INFO_NPC << npc << endl << INFO_NPS << nps << endl << INFO_CREDITS << endl << NEW_TO_DO << endl;
            }

            else if(order == BUY) {

                cout << endl << SHOP_WELCOME << endl << "- " << BUY_BUILD << endl << "- " << BUY_UPGRADE << endl << LEAVE << endl;
                cout << "<" << BUY << "> ";
                cin >> order;

                    if(order == BUY_BUILD){

                        cout<< endl << SHOP_BUILD_WELCOME << endl << "1- " << KEY << endl << "2- " << CALCULATOR << endl << "3- " << TERMINAL << endl << "4- " << MEME << endl << LEAVE <<  endl;
                        cout << "<" << BUY << "><" << BUY_BUILD << "> ";
                        cin >> order;

                        if(order == KEY){
                            KeyPrice = KEY_PRICE + KeyBought/10.00;
                            cout<< endl << SHOP_KEY_DESCRIPTION << SHOP_PRICE << KeyPrice << SHOP_NPS << KeyProduction << KEY_OWNED << KeyBought << SHOP_CONFIRMATION << " " << YES << "/" << NO << endl;
                            cout << "<" << BUY << "><" << BUY_BUILD << "><" << KEY << "> ";
                            cin >> order;
                            if(order == YES) {
                                    if(number >= KeyPrice){
                                        cout << endl << SHOP_YOU_BOUGHT << KEY << "!" << NEW_TO_DO << endl;
                                        KeyBought++;
                                        number = number - KeyPrice;
                                        }
                                    else cout << endl << SHOP_YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else if(order == NO){cout <<  NEW_TO_DO << endl;}
                                else cout << ORDER_ERROR <<  NEW_TO_DO << endl;
                            }

                        else if(order == CALCULATOR){
                            CalculatorPrice = CALCULATOR_PRICE + CalculatorBought;
                            cout<< endl << SHOP_CALCULATOR_DESCRIPTION << SHOP_PRICE << CalculatorPrice << SHOP_NPS << CalculatorProduction << CALCULATOR_OWNED << CalculatorBought << SHOP_CONFIRMATION << " " << YES << "/" << NO << endl;
                            cout << "<" << BUY << "><" << BUY_BUILD << "><" << CALCULATOR << "> ";
                            cin >> order;
                            if(order == YES) {
                                    if(number >= CalculatorPrice){
                                        cout << endl << SHOP_YOU_BOUGHT << CALCULATOR << "!" << NEW_TO_DO << endl;
                                        CalculatorBought++;
                                        number = number - CalculatorPrice;
                                        }
                                    else cout << endl << SHOP_YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else if(order == NO){cout <<  NEW_TO_DO << endl;}
                                else cout << ORDER_ERROR <<  NEW_TO_DO << endl;
                        }

                        else if(order == TERMINAL){
                            TerminalPrice = TERMINAL_PRICE + TerminalBought*75;
                            cout<< endl << SHOP_TERMINAL_DESCRIPTION << SHOP_PRICE << TerminalPrice << SHOP_NPS << TerminalProduction << TERMINAL_OWNED << TerminalBought << SHOP_CONFIRMATION << " " << YES << "/" << NO << endl;
                            cout << "<" << BUY << "><" << BUY_BUILD << "><" << TERMINAL << "> ";
                            cin >> order;
                            if(order == YES) {
                                    if(number >= TerminalPrice){
                                        cout << endl << SHOP_YOU_BOUGHT << TERMINAL << "!" << NEW_TO_DO << endl;
                                        TerminalBought++;
                                        number = number - TerminalPrice;
                                        }
                                    else cout << endl << SHOP_YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else if(order == NO){cout <<  NEW_TO_DO << endl;}
                                else cout << ORDER_ERROR <<  NEW_TO_DO << endl;
                        }

                        else if(order == MEME){
                            MemePrice = MEME_PRICE + MemeBough*100;
                            cout<< endl << SHOP_MEME_DESCRIPTION << SHOP_PRICE << MemePrice << SHOP_NPS << MemeProduction << MEME_OWNED << MemeBough << SHOP_CONFIRMATION << " " << YES << "/" << NO << endl;
                            cout << "<" << BUY << "><" << BUY_BUILD << "><" << MEME << "> ";
                            cin >> order;
                            if(order == YES) {
                                    if(number >= MemePrice){
                                        cout << endl << SHOP_YOU_BOUGHT << MEME << "!" << NEW_TO_DO << endl;
                                        MemeBough++;
                                        number = number - MemePrice;
                                        }
                                    else cout << endl << SHOP_YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else if(order == NO){cout <<  NEW_TO_DO << endl;}
                                else cout << ORDER_ERROR <<  NEW_TO_DO << endl;
                        }

                        else if(order == LEAVE) {cout << NEW_TO_DO << endl;}
                        else cout << ORDER_ERROR << NEW_TO_DO << endl;

                    }
                    else if(order == BUY_UPGRADE){
                        cout << endl << SHOP_UPGRADE_WELCOME;
                        if(CanBuyKeyKeyUpgrade == true) cout << endl << "- " << KEYKEY;
                        if(CanBuyCasioUpgrade == true) cout << endl << "- " << CASIO;
                        if(CanBuyBinaryUpgrade == true) cout << endl << "- " << BINARY;
                        cout << endl << LEAVE;
                        cout << endl;
                        cout << "<" << BUY << "><" << BUY_UPGRADE << "> ";
                        cin >> order;

                        if (order == KEYKEY){
                            if(CanBuyKeyKeyUpgrade == true){
                                cout << endl <<  KEYKEY_DESCRIPTION << SHOP_PRICE << KEYKEY_UPGRADE_PRICE << SHOP_CONFIRMATION << " " << YES << "/" << NO << endl;
                                cout << "<" << BUY << "><" << BUY_UPGRADE << "><" << KEYKEY << "> ";
                                cin >> order;
                                if(order == YES){
                                        if(number >= KEYKEY_UPGRADE_PRICE){
                                            cout << endl << KEYKEY_USER_BOUGHT << endl;
                                            KeyProduction = KeyProduction*2;
                                            npc = npc*2;
                                            CanBuyKeyKeyUpgrade = false;
                                            HaveKeyKeyUpgrade = true;
                                            number = number - KEYKEY_UPGRADE_PRICE;
                                        }
                                        else cout << endl << SHOP_YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else if(order == NO){cout <<  NEW_TO_DO << endl;}
                                else cout << ORDER_ERROR << NEW_TO_DO << endl;
                            }
                            else cout << ORDER_ERROR << NEW_TO_DO << endl;
                        }

                        else if (order == CASIO){
                            if(CanBuyCasioUpgrade == true){
                                cout << endl <<  CASIO_DESCRIPTION << SHOP_PRICE << CASIO_UPGRADE_PRICE << SHOP_CONFIRMATION << " " << YES << "/" << NO << endl;
                                cout << "<" << BUY << "><" << BUY_UPGRADE << "><" << CASIO << "> ";
                                cin >> order;
                                if(order == YES){
                                        if(number >= CASIO_UPGRADE_PRICE){
                                            cout << endl << CASIO_USER_BOUGHT << endl;
                                            CalculatorProduction = CalculatorProduction*2;
                                            CanBuyCasioUpgrade = false;
                                            HaveCasioUpgrade = true;
                                            number = number - CASIO_UPGRADE_PRICE;
                                        }
                                        else cout << endl << SHOP_YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else if(order == NO){cout <<  NEW_TO_DO << endl;}
                                else cout << ORDER_ERROR << NEW_TO_DO << endl;
                            }
                            else cout << ORDER_ERROR << NEW_TO_DO << endl;
                        }

                        else if (order == BINARY){
                            if(CanBuyBinaryUpgrade == true){
                                cout << endl <<  BINARY_DESCRIPTION << SHOP_PRICE << BINARY_UPGRADE_PRICE << SHOP_CONFIRMATION << " " << YES << "/" << NO << endl;
                                cout << "<" << BUY << "><" << BUY_UPGRADE << "><" << BINARY << "> ";
                                cin >> order;
                                if(order == YES){
                                        if(number >= BINARY_UPGRADE_PRICE){
                                            cout << endl << BINARY_USER_BOUGHT << endl;
                                            multiplier = multiplier + BINARY_MULTIPLIER;
                                            CanBuyBinaryUpgrade = false;
                                            HaveBinaryUpgrade = true;
                                            number = number - BINARY_UPGRADE_PRICE;
                                        }
                                        else cout << endl << SHOP_YOU_CANT_BUY_THAT << NEW_TO_DO << endl;
                                }
                                else if(order == NO){cout <<  NEW_TO_DO << endl;}
                                else cout << ORDER_ERROR << NEW_TO_DO << endl;
                            }
                            else cout << ORDER_ERROR << NEW_TO_DO << endl;
                        }
                        else cout << ORDER_ERROR << NEW_TO_DO << endl;
                    }
                    else if(order == LEAVE) {cout << NEW_TO_DO << endl;}
                    else cout << ORDER_ERROR << NEW_TO_DO << endl;
            }
            else cout << ORDER_ERROR << NEW_TO_DO << endl;
    }
}




int main(){

    cout << "Welcome to this idle game! Write + and press enter. Write help to get help." << endl;
    std::thread t1(funcion1);
    std::thread t2(funcion2);
    std::thread t3(CasioUnlock);
    std::thread t4(KeyKeyUnlock);
    std::thread t5(BinaryUnlock);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout << endl << "Bye!" << endl;
    return 0;
}

