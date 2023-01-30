#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

bool isLoggedIn() {
  std::string username, passwd, un, pw;

  std::cout << "Enter username: ";
  std::cin >> username;

  std::cout << "Enter password: ";
  std::cin >> passwd;

  std::ifstream read(username + ".txt");
  std::getline(read, un);
  std::getline(read, pw);

  return un == username && pw == passwd;
}

int main() {
  int choice;

  std::cout << "1. Register\n";
  std::cout << "2. Login\n";
  std::cout << "3. Quit\n";
  std::cout << "Your choice: ";
  std::cin >> choice;

  if (choice == 1) {
    std::string username, password;

    std::cout << "Enter a username: ";
    std::cin >> username;

    std::cout << "Enter a password: ";
    std::cin >> password;

    std::ofstream file;
    file.open(username + ".txt");

    file << username << std::endl << password << std::endl;
    file.close();

    main();
  } else if (choice == 2) {
    bool status = isLoggedIn();

    if (!status) {
      std::cout << "False Login" << std::endl;
      return 0;
    } else {
      std::cout << "Succesfully logged in" << std::endl;
      return 0;
    }
  }

  std::cout << "Quiting" << std::endl;
  return 0;
}
