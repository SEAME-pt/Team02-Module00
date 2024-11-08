#pragma once

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "Utils.hpp"
#include <iostream>
#include <algorithm>

/** @class PhoneBook
 * @brief A class that represents a phone book.
 * 
 * The PhoneBook class stores a collection of contacts and provides various operations to manage the contacts.
 * It allows adding, removing, and displaying contacts, as well as searching for contacts and bookmarking them.
 * The phone book is implemented using a vector to store the contacts.
 */

class PhoneBook { 

    private:
        std::vector<Contact> _contacts; /**< The vector that stores the contacts. */
        
        /**
         * @brief Finds the index of a contact based on the phone number.
         * @param phone The phone number to search for.
         * @return The index of the contact if found, -1 otherwise.
         */
        int _findContgit remote -vactByPhone(const std::string& phone) const;

    public:
        /**
         * @brief Default constructor for the PhoneBook class.
         */
        PhoneBook();

        /**
         * @brief Destructor for the PhoneBook class.
         */
        ~PhoneBook();

        /**
         * @brief Adds a new contact to the phone book.
         * @param name The name of the contact.
         * @param phoneNumber The phone number of the contact.
         * @param nickname The nickname of the contact.
         * @return True if the contact was added successfully, false otherwise.
         */
        bool addContact(const std::string& name, const std::string& phoneNumber, const std::string& nickname);

        /**
         * @brief Displays all the contacts in the phone book.
         */
        void displayContacts() const;

        /**
         * @brief Displays the available options for the phone book.
         */
        void displayOptions() const;

        /**
         * @brief Shows the details of a specific contact.
         * @param index The index of the contact to display.
         */
        void showContactDetails(int index);

        /**
         * @brief Removes a contact from the phone book.
         * @param id The ID of the contact to remove.
         * @return True if the contact was removed successfully, false otherwise.
         */
        bool removeContact(const std::string& id);

        /**
         * @brief Bookmarks a contact in the phone book.
         * @param index The index of the contact to bookmark.
         */
        void bookmarkContact(int index);
        
        /**
         * @brief Processes the "add" command.
         * @param input The input string containing the command and contact details.
         */
        void commandAdd(const std::string input);

        /**
         * @brief Processes the "search" command.
         * @param input The input string containing the command and search query.
         */
        void commandSearch(const std::string input);

        /**
         * @brief Changes the bookmark status of a contact.
         * @param index The index of the contact to change the bookmark status.
         */
        void changeBookmarkStatus(int index);

        /**
         * @brief Gets the vector of contacts in the phone book.
         * @return The vector of contacts.
         */
        std::vector<Contact> getContacts() const;
};
