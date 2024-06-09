#include "ContactManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin >> newContact.name;
    std::cout << "Enter phone number: ";
    std::cin >> newContact.phoneNumber;
    std::cout << "Enter email: ";
    std::cin >> newContact.email;
    contacts.push_back(newContact);
}

void displayContact(const Contact& contact) {
    std::cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << ", Email: " << contact.email << std::endl;
}

void displayContacts(const std::vector<Contact>& contacts) {
    for (const Contact& contact : contacts) {
        displayContact(contact);
    }
}

void saveContactsToFile(const std::vector<Contact>& contacts, const std::string& filename) {
    std::ofstream outFile(filename);
    for (const Contact& contact : contacts) {
        outFile << contact.name << ' ' << contact.phoneNumber << ' ' << contact.email << '\n';
    }
}

void loadContactsFromFile(std::vector<Contact>& contacts, const std::string& filename) {
    std::ifstream inFile(filename);
    Contact contact;
    while (inFile >> contact.name >> contact.phoneNumber >> contact.email) {
        contacts.push_back(contact);
    }
}

// Function to display formatted contact information with separators
void displayFormattedContact(const Contact& contact) {
    std::stringstream ss;
    ss << "Name: " << contact.name << " | Phone: " << contact.phoneNumber << " | Email: " << contact.email;
    std::cout << ss.str() << std::endl;
}

void searchContact(const std::vector<Contact>& contacts, const std::string& name) {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
        return contact.name == name;
        });
    if (it != contacts.end()) {
        std::cout << "Contact found: ";
        displayContact(*it);
    }
    else {
        std::cout << "Contact not found.\n";
    }
}

void copyContacts(const std::vector<Contact>& contacts, std::vector<Contact>& copiedContacts) {
    std::copy(contacts.begin(), contacts.end(), std::back_inserter(copiedContacts));
}

// Sorting
void sortContactsByName(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.name < b.name;
        });
}

void sortContactsByPhoneNumber(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.phoneNumber < b.phoneNumber;
        });
}

// Encryption
std::string encryptText(const std::string& text, int shift) {
    std::string result;
    for (char c : text) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            c = char((c - base + shift) % 26 + base);
        }
        result += c;
    }
    return result;
}

std::string decryptText(const std::string& text, int shift) {
    return encryptText(text, 26 - shift);
}

void encryptContacts(std::vector<Contact>& contacts, int shift) {
    for (Contact& contact : contacts) {
        contact.name = encryptText(contact.name, shift);
        contact.email = encryptText(contact.email, shift);
    }
}

void decryptContacts(std::vector<Contact>& contacts, int shift) {
    for (Contact& contact : contacts) {
        contact.name = decryptText(contact.name, shift);
        contact.email = decryptText(contact.email, shift);
    }
}
