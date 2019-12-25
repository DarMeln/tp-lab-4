#include "Automata.h"

Automata::Automata()
    : cash(0), state(STATES::OFF)
{

}

void Automata::on()
{
    if (this->state == STATES::OFF)
    {
        std::cout << "Welcome to our vending machine! How can I help you today?" << std::endl;
        this->state = STATES::WAIT;
    }
}

void Automata::off()
{
    if (this->state == STATES::WAIT)
    {
        std::cout << "Have a very safe and productive day!" << std::endl;
        this->state = STATES::OFF;
    }
}

void Automata::coin(int sum)
{
    if (!((this->state == STATES::WAIT) || (this->state == STATES::ACCEPT)))
    {
        std::cout << "Cannot commit to the operation at this time." << std::endl;
    }
    else
    {
        std::cout << "Accepting " << sum << " in cash..." << std::endl;
        this->state = STATES::ACCEPT;
        this->cash += sum;
    }
}

void Automata::choice(int option)
{
    if (this->state != STATES::ACCEPT)
    {
        std::cout << "Cannot commit to the operation at this time." << std::endl;
    }
    else
    {
        std::cout << "Thank you for choosing our " << this->menu[option] << "!" << std::endl;
        this->state = STATES::CHECK;
        this->check(option);
    }
}

void Automata::check(int option)
{
    if (this->cash >= this->prices[option])
    {
        this->cash -= this->prices[option];
        this->cook();
    }
    else
    {
        std::cout << "It seems you have insufficient cash for purchase! Returning to the main menu..." << std::endl;
        this->cancel();
    }
}

void Automata::cancel()
{
    this->state = STATES::WAIT;
}

void Automata::cook()
{
    std::cout << "Brewing your drink, please wait..." << std::endl;
    this->state = STATES::COOK;
    this->finish();
}

void Automata::finish()
{
    std::cout << "Your drink is ready! Have a good one!" << std::endl;
    this->state = STATES::WAIT;
}

void Automata::printMenu()
{
    for (int i = 0; i < this->prices.size(); i++)
    {
        std::cout << this->menu[i] << " - " << this->prices[i] << std::endl;
    };

}

std::string Automata::stateString(STATES state)
{
    std::vector<std::string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
    return states[state];
}

void Automata::printState()
{
    std::cout << this->stateString(this->state);
}
