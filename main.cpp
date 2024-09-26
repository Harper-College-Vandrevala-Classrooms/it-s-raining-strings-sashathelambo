#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

void printBusinesses(const std::vector<std::string>& businesses) {
    for (const auto& business : businesses) {
        std::cout << "    " << business << std::endl;
    }
}

void addBusiness(std::vector<std::string>& businesses, const std::string& business) {
    businesses.push_back(business);
    std::sort(businesses.begin(), businesses.end());
}

void testAddBusiness() {
    std::vector<std::string> businesses;

    addBusiness(businesses, "Apple");
    assert(businesses.size() == 1);
    assert(businesses[0] == "Apple");

    addBusiness(businesses, "Google");
    assert(businesses.size() == 2);
    assert(businesses[0] == "Apple");
    assert(businesses[1] == "Google");

    addBusiness(businesses, "Microsoft");
    assert(businesses.size() == 3);
    assert(businesses[0] == "Apple");
    assert(businesses[1] == "Google");
    assert(businesses[2] == "Microsoft");
}

void testPrintBusinesses() {
    std::vector<std::string> businesses = {"Apple", "Google", "Microsoft"};
    std::cout << "Expected output:\n    Apple\n    Google\n    Microsoft\n";
    std::cout << "Actual output:\n";
    printBusinesses(businesses);
}

int main() {
    testAddBusiness();
    testPrintBusinesses();

    std::vector<std::string> businesses;
    std::string input;
    std::string choice;

    std::cout << "Welcome to the Business Sorting Program!" << std::endl;

    while (true) {
        std::cout << "Please enter the name of a business:  ";
        std::getline(std::cin, input);

        addBusiness(businesses, input);

        if (businesses.size() == 1) {
            std::cout << "Your business is:" << std::endl;
        } else {
            std::cout << "Your businesses are:" << std::endl;
        }
        printBusinesses(businesses);

        std::cout << "Would you like to add another business? (yes/no): ";
        std::getline(std::cin, choice);

        if (choice != "y" && choice != "Y" && choice != "yes" && choice != "Yes") {
            break;
        }
    }

    std::cout << "Thank you for using the Business Sorting Program!" << std::endl;

    return 0;
}
