#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>

/**
 * @brief The Contact class represents a contact in a phone book.
 */
class Contact
{
private:
    std::string _name;          ///< The name of the contact.
    std::string _phoneNumber;   ///< The phone number of the contact.
    std::string _nickname;      ///< The nickname of the contact.
    bool        _isBookmarked;  ///< The bookmark status of the contact.

public:
    /**
     * @brief Default constructor for the Contact class.
     */
    Contact();

    /**
     * @brief Constructor for the Contact class.
     * @param newName The name of the contact.
     * @param newPhoneNumber The phone number of the contact.
     * @param newNickname The nickname of the contact.
     */
    Contact(const std::string& newName, const std::string& newPhoneNumber, const std::string& newNickname);

    /**
     * @brief Destructor for the Contact class.
     */
    ~Contact();

    /**
     * @brief Get the name of the contact.
     * @return The name of the contact.
     */
    std::string getName() const;

    /**
     * @brief Get the phone number of the contact.
     * @return The phone number of the contact.
     */
    std::string getPhoneNumber() const;

    /**
     * @brief Get the nickname of the contact.
     * @return The nickname of the contact.
     */
    std::string getNickname() const;

    /**
     * @brief Get the bookmark status of the contact.
     * @return The bookmark status of the contact.
     */
    bool getBookmarkStatus() const;
    
    /**
     * @brief Set the bookmark status of the contact.
     * @param status The bookmark status to set.
     */
    void setBookmarkStatus(bool status);
};
