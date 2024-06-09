#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <string>
#include <vector>

struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string email;
};

void addContact(std::vector<Contact>& contacts);
void displayContact(const Contact& contact);
void displayContacts(const std::vector<Contact>& contacts);
void saveContactsToFile(const std::vector<Contact>& contacts, const std::string& filename);
void loadContactsFromFile(std::vector<Contact>& contacts, const std::string& filename);
void displayFormattedContact(const Contact& contact);
void searchContact(const std::vector<Contact>& contacts, const std::string& name);
void copyContacts(const std::vector<Contact>& contacts, std::vector<Contact>& copiedContacts);
void sortContactsByName(std::vector<Contact>& contacts);
void sortContactsByPhoneNumber(std::vector<Contact>& contacts);
void encryptContacts(std::vector<Contact>& contacts, int shift);
void decryptContacts(std::vector<Contact>& contacts, int shift);
void decryptContacts(std::vector<Contact>& contacts, int shift);

#endif // CONTACT_MANAGER_H
