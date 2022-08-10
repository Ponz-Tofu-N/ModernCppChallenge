#include <random>
#include <string>
#include <string_view>
#include <sstream>

std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
std::string ans = "METHINKS IT IS LIKE A WEASEL";
std::random_device seed_gen;
std::default_random_engine engine(seed_gen());

std::uniform_int_distribution<> dist_aphabet(0, 26);
std::uniform_int_distribution<> dist_percent(1, 100);

bool is_match(std::string_view str) { return str == ans; }
bool make_5percent() { return dist_percent(engine) <= 5; }

void make_mutatable_string(std::string& original) {
  std::for_each(std::begin(original), std::end(original), [&](char& c) {
    if (make_5percent())
      c = alphabet[dist_aphabet(engine)];
    });
}

std::string make_random_string() {
  std::stringstream random_ss;
  for (size_t i = 0; i < ans.size(); i++)
  {
    random_ss << alphabet[dist_aphabet(engine)];
  }

  return random_ss.str();
}

size_t score(std::string_view str) {
  size_t count = 0;
  for (size_t i = 0; i < ans.size(); i++)
  {
    if (ans[i] == str[i]) count++;
  }

  return count;
}


void run() {
  auto str = make_random_string();
  auto s = score(str);

  std::vector<std::pair<std::string, size_t>> childs(30, std::make_pair(str, s));

  int count = 0;
  do
  {
    for (auto child = std::begin(childs); child != std::end(childs); child++)
    {
      make_mutatable_string((*child).first);
      (*child).second = score((*child).first);
    }

    auto highest_score = std::max_element(childs.begin(), childs.end(), [](auto a, auto b) {
      // std::cout << (a).first << ": " << (a).second << std::endl;
      return a.second < b.second;
      });

    std::cout << count << "highest: " << (*highest_score).first << ": " << (*highest_score).second << std::endl;

    std::vector<std::pair<std::string, size_t>> new_childs(30, *highest_score);
    childs.swap(new_childs);

    count++;
  } while (!is_match(childs[0].first));
}