#ifndef DECIMAL_H_
#define DECIMAL_H_

#include <string>

#define INITIAL_PLACES 20

namespace arithmetic {
  class Decimal {
  public:
    Decimal(const std::string &num) {
      init_number(num);
    }
    Decimal operator+(Decimal &dec);

  private:
    int number_current_index = 0;
    int number_current_places = INITIAL_PLACES;
    int number[INITIAL_PLACES];
    int *num_ptr;

    void init_number(const std::string &num);
    void put_num_at_index(int i, int num);
    int get_num_at_index(int i);
    void check_boarders(int i, int max);
    bool is_dec(char c);
    bool is_comma(char c);
    bool is_sign(char c);
    void checked_insert(int index, char num);
    void set_sign(char c);
    void set_comma(int index);
    void set_num(int index, char c);
    void add_digit(char c);
    void determine_comma(const std::string &num);
  };
} // namespace pi

#endif // DECIMAL_H_
