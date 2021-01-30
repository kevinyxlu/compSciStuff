//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

class MarketItem {
    public:
        void setPrice(double newprice);
        double getPrice();
        void setName(string newname);
        string getName();
        MarketItem(double newprice, string newname);
        MarketItem();
    public:
        string name;
        double price;
        void checkPrice();
};

MarketItem::MarketItem:MarketItem(0, "n/a"){
}

int main()
{
	MarketItem choclateBar();
    //MarketItem choclateBar(1.5, "Twix");
    //MarketItem choclateBar;
    choclateBar.checkPrice();

    return 0;
}

void MarketItem::checkPrice()
{
    if(price < 100 && price > 0)
    {
        cout << "price is a positive non-zero less than $100";
    }
}