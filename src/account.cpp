#include <iostream>
#include <string>
#include "account.hpp"


void Account::refresh_json_container() {
  json_container["first_name"] = first_name;
  json_container["last_name"]  = last_name;
  json_container["address"]    = address;
  json_container["phone"]      = phone;
  json_container["age"]        = age;
  json_container["id"]         = id;
  json_container["balance"]    = balance;
}

void Account::input_form(const unsigned i) {
  id = i;
  std::cout << "Enter first name: ";
  std::cin >> first_name;
  std::cout << "Enter last name: ";
  std::cin >> last_name;
  std::cout << "Enter age: ";
  std::cin >> age;
  std::cout << "Enter address: ";
  std::cin >> address;
  std::cout << "Enter phone: ";
  std::cin >> phone;
  std::cout << "Enter balance: ";
  std::cin >> balance;
  refresh_json_container();
}

void Account::update_form_message() {
  std::cout << "Available fields[current_values] for update:\n"
            << "1.first_name[" << json_container["first_name"] << "]\n"
            << "2.last_name["  << json_container["last_name"]  << "]\n"
            << "3.age["        << json_container["age"]        << "]\n"
            << "4.address["    << json_container["address"]    << "]\n"
            << "5.phone["      << json_container["phone"]      << "]\n"
            << "6.balance["    << json_container["balance"]    << "]\n"
            << "7.Exit and save\n\n\n"
            << "Enter your choice: ";
}

void Account::update_form(const unsigned i) {
  short option = 0;
  std::string tmp_str;
  unsigned tmp_unsigned;
  float tmp_float;
  do {
    update_form_message();
    std::cin >> option;
    switch (option) {
      case 1:
        std::cout << "New first_name: ";
        std::cin >> tmp_str;
        json_container["first_name"] = tmp_str;
        break;
      case 2:
        std::cout << "New last_name: ";
        std::cin >> tmp_str;
        json_container["last_name"] = tmp_str;
        break;
      case 3:
        std::cout << "New age: ";
        std::cin >> tmp_unsigned;
        json_container["age"] = tmp_unsigned;
        break;
      case 4:
        std::cout << "New address: ";
        std::cin >> tmp_str;
        json_container["address"] = tmp_str;
        break;
      case 5:
        std::cout << "New phone: ";
        std::cin >> tmp_unsigned;
        json_container["phone"] = tmp_unsigned;
        break;
      case 6:
        std::cout << "New balance: ";
        std::cin >> tmp_float;
        json_container["balance"] = tmp_float;
        break;
      case 7:
        break;
      default:
        std::cout << "Unknown option: " << option << "\n";
    }
  } while (option != 7);
}


json Account::dump() {
  return json_container;
}

Account::Account(const json &j) :
  json_container(j)
{}


