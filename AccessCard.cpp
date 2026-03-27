#include "AccessCard.h"
#include <iostream>
using namespace std;
AccessCard::AccessCard(string cardID, int accessLevel) : cardID(cardID), accessLevel(accessLevel) {}

string AccessCard::getCardID() const
{
    return cardID;
}

int AccessCard::getAccessLevel() const
{
    return accessLevel;
}

void AccessCard::displayCardInfo() const
{
    cout << "Card ID: " << cardID << endl;
    cout << "Access Level: " << accessLevel << (accessLevel == 1 ? " (Basic)" : " (Labs)") << endl;
}