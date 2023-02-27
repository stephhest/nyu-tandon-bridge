//
// sh7245_hw3_q1.cpp
//
/* Write a program that computes how much a customer has to pay after
purchasing two items. */
//
#include <iostream>
using namespace std;

const double PROMO_DISCOUNT = 0.50;
const double MEMBER_DISCOUNT = 0.90;

int main ()
{
    double first_item_price, second_item_price, base_price;
    double promo_discount_price, final_discount_price, tax_rate; 
    double total_price;
    char club_card;
    
    cout<<endl<<"Enter price of first item: ";
    cin>>first_item_price;
    cout<<"Enter price of second item: ";
    cin>>second_item_price;
    cout<<"Does customer have a club card? (Y/N): ";
    cin>>club_card;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>tax_rate;

    base_price = first_item_price + second_item_price;
    
    if (first_item_price > second_item_price)
        promo_discount_price = first_item_price + (second_item_price * PROMO_DISCOUNT);
    else
        promo_discount_price = second_item_price + (first_item_price * PROMO_DISCOUNT);
    
    if (club_card == 'Y' || club_card == 'y')
        final_discount_price = promo_discount_price * MEMBER_DISCOUNT;
    else if (club_card == 'N' || club_card == 'n')
        final_discount_price = promo_discount_price;
    else
        cout<<"Input Error";

    total_price = (final_discount_price * (tax_rate/100)) + final_discount_price;

    cout<<"Base price: "<<base_price<<endl;
    cout<<"Price after discounts: "<<final_discount_price<<endl;
    cout<<"Total price: "<<total_price<<endl;

    return 0;


}