#include <random>
#include <string>
#include <string_view>

const char alphabet[27] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U', 'V','W','X','Y','Z',' ' };
std::string ans = "METHINKS IT IS LIKE A WEASEL";

bool is_match(std::string_view str) { return str == ans; }

void make_mutatable_string(std::string& original) {
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  std::uniform_int_distribution<> dist_aphabet(0, 26);
  std::uniform_int_distribution<> dist_percent(1, 100);

  std::for_each(std::begin(original), std::end(original), [&](char& c) {
    if (make_5percent())
      c = alphabet[dist_aphabet(engine)];
    });
}

std::string make_random_string() {
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  std::uniform_int_distribution<> dist(0, 26);

  std::string random_string;
  for (size_t i = 0; i < ans.size(); i++)
  {
    int index = dist(engine);
    random_string += alphabet[index];
  }

  return random_string;
}

size_t score(std::string_view str) {
  std::accumulate(str.begin(), str.end(), 0, [](auto c) {if (c)});
  size_t count = 0;
  for (size_t i = 0; i < ans.size(); i++)
  {
    if (ans[i] == str[i]) count++;
  }

  return count;
}

bool make_5percent() {
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  std::uniform_int_distribution<> dist(1, 100);

  return dist(engine) <= 5;
}