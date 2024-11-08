#include "PhoneBook.hpp"
#include <exception>
#include <iostream>

PhoneBook::PhoneBook()
{}

PhoneBook::~PhoneBook()
{}

int PhoneBook::_findContactByPhone(const std::string &phone) const
{
    for (size_t i = 0; i < _contacts.size(); ++i)
    {
        if (_contacts[i].getPhoneNumber() == phone)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool PhoneBook::addContact(const std::string& name, const std::string& phoneNumber, const std::string& nickname)
{
    if (_findContactByPhone(phoneNumber) != -1)
    {
        std::cout << Color::RED << "Phone number already registered." << Color::RESET << std::endl;
        return false;
    }
    _contacts.push_back(Contact(name, phoneNumber, nickname));
    std::cout << Color::GREEN << "Contact added." << Color::RESET << std::endl;
    return true;
}

void PhoneBook::displayContacts() const
{
    for (size_t i = 0; i < _contacts.size(); ++i)
    {
        std::cout << Color::YELLOW << i + 1 << ": " << _contacts[i].getName() << " Nº" << _contacts[i].getPhoneNumber() << Color::RESET << std::endl;
    }
}

void PhoneBook::changeBookmarkStatus(int index)
{
    if(_contacts[index].getBookmarkStatus())
    {
        std::cout << "Would you like to unbookmark this contact? [Y/N]: ";
        char input;
        std::cin >> input;
        if (input == 'Y' || input == 'y')
        {
            _contacts[index].setBookmarkStatus(false);
            std::cout << Color::BLUE << "Contact unbookmarked." << Color::RESET << std::endl;
        }
    }
    else
    {
        std::cout << "Would you like to bookmark this contact? [Y/N]: ";
        char input;
        std::cin >> input;
        if (input == 'Y' || input == 'y')
        {
            _contacts[index].setBookmarkStatus(true);
            std::cout << Color::BLUE << "Contact bookmarked." << Color::RESET << std::endl;

            Contact contact = _contacts[index];
            _contacts.erase(_contacts.begin() + index);
            _contacts.insert(_contacts.begin(), contact);
        }

    }
}

void PhoneBook::showContactDetails(int index)
{
    if (index >= 0 && static_cast<size_t>(index) < _contacts.size())
    {
        const Contact &contact = _contacts[index];
        std::cout << "Name: " << contact.getName() << "\nPhone Number: " 
                    << contact.getPhoneNumber() << "\nNickname: " << contact.getNickname() 
                    << "\nBookmarked: " << (contact.getBookmarkStatus() ? Color::GREEN + "Yes" + Color::RESET : Color::RED + "No" + Color::RESET) << std::endl;
        
        this->changeBookmarkStatus(index);
    }
    else
    {
        std::cout << Color::RED << "Invalid contact index." << Color::RESET << std::endl;
    }
}

bool PhoneBook::removeContact(const std::string &value)
{
    // Remove by index
    int index = -1;
    try
    {
        index = std::stoi(value) - 1;
        if (index >= 0 && static_cast<size_t>(index) < _contacts.size()) {
            _contacts.erase(_contacts.begin() + index);
            std::cout << Color::GREEN << "Contact removed by index." << Color::RESET << std::endl;
            return true;
        }
    }
    catch (std::exception &e)
    {
        std::cout << Color::RED << "Error removing contact: " << e.what() << Color::RESET << std::endl;
        return false;
    }

    // Remove by phone number
    index = _findContactByPhone(value);
    if (index != -1)
    {
        _contacts.erase(_contacts.begin() + index);
        std::cout << Color::GREEN << "Contact removed by phone number." << Color::RESET << std::endl;
        return true;
    }
    std::cout << Color::RED << "No contact found to remove." << Color::RESET << std::endl;
    return false;
}

void PhoneBook::bookmarkContact(int index)
{
    if (index >= 0 && static_cast<size_t>(index) < _contacts.size())
    {
        if (_contacts[index].getBookmarkStatus())
        {
            std::cout << Color::YELLOW << "Contact already bookmarked." << Color::RESET << std::endl;
        }
        else
        {
            _contacts[index].setBookmarkStatus(true);
            std::cout << Color::BLUE << "Contact bookmarked." << Color::RESET << std::endl;
        }
    }
    else
    {
        std::cout << Color::RED << "Invalid contact index." << Color::RESET << std::endl;
    }
}

void PhoneBook::displayOptions() const
{
    std::cout << "\n------------------- PhoneBook -------------------\n" << std::endl;
    std::cout << "[1. ADD] [2. SEARCH] [3. BOOKMARK] [4. REMOVE] [5. EXIT]\n" << std::endl;
}

void PhoneBook::commandAdd(const std::string input)
{
    std::string name, phone, nickname;
    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);

    addContact(Utils::trim(name), Utils::trim(phone), Utils::trim(nickname));
}

std::vector <Contact> PhoneBook::getContacts() const
{
    return _contacts;
}
