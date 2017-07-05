#include <stdexcept>
#include <iostream>

#include <cstring>
#include <cstdlib>

#include "decimal.h"

namespace arithmetic {

  Decimal operator+(Decimal const &dec) {
    ;
  }

  void Decimal::init_number(const std::string &num) {
    num_ptr = number;
    set_sign(num[0]);
    determine_comma(num);

    for (char c : num) {
      add_digit(c);
    }
  }

  void Decimal::checked_insert(int index, char num) {
    if (index < number_current_places)
      num_ptr[index] = num - 48;
    else {
      int oldsize = sizeof(int) * number_current_places;
      int newsize = oldsize + sizeof(int) * INITIAL_PLACES;
      int *tmp = (int*)std::malloc(newsize);
      std::memcpy(tmp, num_ptr, oldsize);
      num_ptr = tmp;
      add_digit (num);
    }
  }

  void Decimal::check_boarders(int i, int max) {
    if (i >= max || i < 0)
      throw std::out_of_range("Index not in array bounds.");
  }

  void Decimal::put_num_at_index(int i, int num) {
    try {
      check_boarders (i, number_current_places);
      num_ptr[i] = num;
    } catch (const std::out_of_range &ex) {

    }
  }

  int Decimal::get_num_at_index(int i) {
    try {
      check_boarders(i, number_current_places);
      return num_ptr[i];
    } catch (const std::out_of_range &ex) {
      std::cerr << "Out of range error: " << ex.what() << '\n';
      exit(1);
    }
  }

  bool Decimal::is_dec(char c) {
    if (c >= '0' && c <= '9')
      return true;
    return false;
  }

  bool Decimal::is_comma(char c) {
    if (c == '.')
      return true;
    return false;
  }

  bool Decimal::is_sign(char c) {
    if (c == '+' || c== '-')
      return true;
    return false;
  }

  void Decimal::set_sign(char c) {
    switch (c) {
    case '-':
      num_ptr[0] = 0;
      break;
    default:
      num_ptr[0] = 1;
    }
  }

  void Decimal::set_comma(int index) {
    num_ptr[1] = index;
  }

  void Decimal::set_num(int index, char c) {
    if (index > 1 && is_dec(c))
      checked_insert(index, c);
  }

  void Decimal::add_digit(char c) {
    number_current_index++;
    set_num (number_current_index, c);
  }

  void Decimal::determine_comma(const std::string &num) {
    int index = 0;
    set_comma(0);
    for (char c : num) {
      index++;
      if (is_comma(c)) {
        set_comma(index);
        break;
      }
    }
  }
}
