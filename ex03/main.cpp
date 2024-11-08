#include "PhoneBook.hpp"


void filterCommand(std::string input, PhoneBook &phonebook)
{
    if (input == "ADD" || input == "1")
    {
        phonebook.commandAdd(input);
    }
    else if (input == "SEARCH" || input == "2")
    {
        if (phonebook.getContacts().empty())
            std::cout << Color::RED << "No contacts to search. Your phonebook is empty! :(" << Color::RESET << std::endl;
        else
        {
            phonebook.displayContacts();
            std::cout << Color::GREEN << "See details of contact by index: " << Color::RESET;
            std::cin >> input;
            phonebook.showContactDetails(std::stoi(input) - 1);
        }
    }
    else if (input == "BOOKMARK" || input == "3")
    {
        if (phonebook.getContacts().empty())
            std::cout << Color::RED << "No contacts to bookmark. Your phonebook is empty! :(" << Color::RESET << std::endl;
        else
        {
            phonebook.displayContacts();
            std::cout << Color::GREEN << "Bookmark contact by index: " << Color::RESET;
            std::cin >> input;
            phonebook.bookmarkContact(std::stoi(input) - 1);
        }
    }
    else if (input == "REMOVE" || input == "4")
    {
        if (phonebook.getContacts().empty())
            std::cout << Color::RED << "No contacts to remove. Your phonebook is empty! :(" << Color::RESET << std::endl;
        else 
        {
            std::cout << Color::GREEN << "Write the contact's index or phone number to remove: " << Color::RESET;
            std::cin >> input;
            phonebook.removeContact(input);
        }
    }
    else if (input == "EXIT" || input == "5")
    {
        std::cout << Color::RED << "Exiting program." << Color::RESET << std::endl;
        exit(0);
    }
    else
        std::cout << Color::RED << "Unknown input. Try again." << Color::RESET << std::endl;
}

int main(void)
{
    PhoneBook phonebook;
    std::string input;
    bool keepRunning = true;

    std::cout << Color::BLUE << "Phonebook\nby:Team2 @ Seame" << Color::RESET << std::endl;

    while (true)
    {
        phonebook.displayOptions();

        std::cout << Color::GREEN << "Enter Command: " << Color::RESET;
        std::cin >> input;
        if (std::cin.eof())
        {
            std::cout << Color::RED << "Exiting program." << Color::RESET << std::endl;
            exit(0);
        }

        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
        
        filterCommand(input, phonebook);
    }
    return 0;
}
