#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void printBusinesses(const std::vector<std::string>& businesses) {
    for (const auto& business : businesses) {
        std::cout << "    " << business << std::endl;
    }
}

int main() {
    std::vector<std::string> businesses;
    std::string input;
    std::string choice;

    std::cout << "Welcome to the Business Sorting Program!" << std::endl;

    while (true) {
        std::cout << "Please enter the name of a business:  ";
        std::getline(std::cin, input);

        businesses.push_back(input);

        std::sort(businesses.begin(), businesses.end());

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
