#include <iostream>
#include <fstream>
#include <string>

#include "json.hpp"
#include "account.hpp"
#include "bank.hpp"

using json = nlohmann::json;


Bank::Bank(const std::string db) :
  db_file(db)
{
  read_db();
}

bool Bank::read_db() {
  std::ifstream ifs(db_file);
  if(ifs.is_open()) {
    ifs >> json_container;
    ifs.close();
    return true;
  }
  return false;
}

bool Bank::write_db() {
  std::ofstream ofs(db_file);
  if(ofs.is_open()) {
    ofs << json_container.dump(2);
    ofs.close();
    return true;
  }
  return false;
}

void Bank::welcome_message() {
    std::cout << "CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n\n"
              << "######## WELCOME TO THE MAIN MENU ########\n\n"
              << "1.Create new account\n"
              << "2.Update information of excisting account\n"
              << "3.For transactions\n"
              << "4.Check the details of existing account\n"
              << "5.Removing existing account\n"
              << "6.View customer's list\n"
              << "7.Exit\n\n\n"
                 "Enter your choice: ";
}

bool Bank::create_account() {
  Account acc;
  unsigned accs_quantity = json_container["accounts"].size();
  unsigned next_id = 0;
  // Find next useable id
  for (int i = 0; i < accs_quantity; i++) {
    unsigned i_id = json_container["accounts"][i]["id"];
    if (i_id > next_id)
      next_id = i_id + 1;
  }
  acc.input_form(next_id);
  json_container["accounts"][accs_quantity] = acc.dump();
  return write_db();
}

bool Bank::update_account() {
  unsigned id;
  bool found = false;
  std::cout << "Enter account id: ";
  std::cin >> id;
  for (int i = 0; i < json_container["accounts"].size(); i++) {
    if (json_container["accounts"][i]["id"] == id) {
      found = true;
      break;
    }
  }
  if (found) {
    Account acc(json_container["accounts"][id]);
    acc.update_form(id);
    json_container["accounts"][id] = acc.dump();
    return write_db();
  } else {
    std::cout << "No account with id " << id << "\n";
    return false;
  }
}

void Bank::print_customer_list() {
  std::cout << "id\tfirst_name\tlast_name\n";
  for(int i = 0; i < json_container["accounts"].size(); i++) {
    std::cout << json_container["accounts"][i]["id"] << "\t"
              << static_cast<std::string>(json_container["accounts"][i]["first_name"]) << "\t\t"
              << static_cast<std::string>(json_container["accounts"][i]["last_name"]) << "\n";
  }
}

void Bank::start() {
  short option = 0;
  do {
    welcome_message();
    std::cin >> option;
    switch (option) {
      case 1:
        create_account();
        break;
      case 2:
        update_account();
        break;
      case 6:
        print_customer_list();
        break;
      case 7:
        break;
      default:
        std::cout << "Unknown option: " << option << "\n";
    }
  } while (option != 7);
}
