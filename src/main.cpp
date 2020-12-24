#include "bank.hpp"


int main() {
  Bank b("database.json");
  b.start();
  return 0;
}
