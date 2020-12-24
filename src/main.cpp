#include <iostream>
#include <iomanip>

#include "bank.hpp"


int main() {
  Bank b("database.json");
  b.start();
  // j["pi"] = {3.14, 3.15};
  // j["names"] = {"Armen", "Lia", "Vahag"};
  // j["object1"]["object2"] = true;
  // j["nested_array"] = {
  //   {"name3", 3},
  //   {"name1", 1},
  //   {"name2", 2}, 
  //   {"name4", true}
  // };
  // j["nested_array"]["name1"] = 1;
  // j["nested_array"]["name2"] = 2;
  // j["nested_array"]["name3"] = 3;
  // std::ofstream ofs("test.json");
  // if(ofs.is_open()) {
  //   // ofs << j.dump(2);
  //   ofs << std::setw(2) << j;
  //   ofs.close();
  // } else {
  //   std::cout << "Unable to open" << std::endl;
  // }
  // std::cout << j.dump(2) << std::endl;

}
