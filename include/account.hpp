#pragma once
#include <string>

#include "json.hpp"

using json = nlohmann::json;


class Account {
private:
  void refresh_json_container();
  void update_form_message();
public:
  json json_container;
  std::string first_name;
  std::string last_name;
  std::string address;
  std::string phone;
  unsigned age;
  unsigned id;
  float balance;
  Account() {}
  Account(const json &j);
  void input_form(const unsigned i);
  void update_form(const unsigned i);
  json dump();
  void load(const json &j);
};
