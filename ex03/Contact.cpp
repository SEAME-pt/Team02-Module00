#include "Contact.hpp"

Contact::Contact()
{}

Contact::Contact(const std::string& newName, const std::string& newPhoneNumber, const std::string& newNickname): _name(newName), _phoneNumber(newPhoneNumber), _nickname(newNickname), _isBookmarked(false)
{}

Contact::~Contact()
{}

std::string Contact::getName() const
{
    return _name;
}

std::string Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

bool Contact::getBookmarkStatus() const
{
    return _isBookmarked;
}

void Contact::setBookmarkStatus(bool status)
{
    _isBookmarked = status;
}