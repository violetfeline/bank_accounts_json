#pragma once
#include <string>

#include "json.hpp"

using json = nlohmann::json;

class Bank {
private:
  std::string db_file;
  json json_container;
  bool read_db();
  bool write_db();
  void welcome_message();
  long int find_index(unsigned id);
  bool create_account();
  bool update_account();
  bool transfer_funds();
  void account_details();
  bool remove_account();
  void print_customer_list();
public:
  Bank(const std::string db);
  void start();
};
