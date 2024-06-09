#include "ContactManager.h"
#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char* argv[]) {
    std::vector<Contact> contacts;
    std::string filename = "contacts.txt";
    int shift = 3;  // Default shift for Caesar Cipher

    // Check if shift value is provided as argument
    if (argc > 1) {
        shift = std::atoi(argv[1]);
        std::cout << "Using shift value from arguments: " << shift << "\n";
    }

    int choice;
    do {
        std::cout << "1. Add Contact\n2. Display Contacts\n3. Save Contacts\n4. Load Contacts\n";
        std::cout << "5. Display Formatted First Contact\n6. Search Contact\n";
        std::cout << "7. Sort Contacts by Name (Original Contacts Are Changed)\n";
        std::cout << "8. Copy, Sort, and Display Contacts by Name (Original Contacts Remain Unchanged)\n";
        std::cout << "9. Sort Contacts by Phone Number\n10. Encrypt Contacts\n";
        std::cout << "11. Decrypt Contacts\n12. Change Caesar Cipher Shift\n";
        std::cout << "13. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayContacts(contacts);
            break;
        case 3:
            saveContactsToFile(contacts, filename);
            break;
        case 4:
            loadContactsFromFile(contacts, filename);
            break;
        case 5:
            if (!contacts.empty()) {
                displayFormattedContact(contacts[0]);
            }
            else {
                std::cout << "No contacts to display.\n";
            }
            break;
        case 6: {
            std::string name;
            std::cout << "Enter name to search: ";
            std::cin >> name;
            searchContact(contacts, name);
            break;
        }
        case 7:
            sortContactsByName(contacts);
            std::cout << "Contacts sorted by name.\n";
            break;
        case 8: {
            std::vector<Contact> sortedContacts = contacts;
            sortContactsByName(sortedContacts);
            displayContacts(sortedContacts);
            break;
        }
        case 9:
            sortContactsByPhoneNumber(contacts);
            std::cout << "Contacts sorted by phone number.\n";
            break;
        case 10:
            encryptContacts(contacts, shift);
            std::cout << "Contacts encrypted.\n";
            break;
        case 11:
            decryptContacts(contacts, shift);
            std::cout << "Contacts decrypted.\n";
            break;
        case 12:
            std::cout << "Enter new shift value: ";
            std::cin >> shift;
            std::cout << "Shift value updated.\n";
            break;
        case 13:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 13);

    return 0;
}
