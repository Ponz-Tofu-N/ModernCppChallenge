#include "generator.h"

#include <array>

password_generators::password_generators() {
  std::random_device seed_gen;
  std::array<std::uint32_t, 100> seeds;

  for (std::uint32_t& x : seeds) {
    x = seed_gen();
  }

  std::seed_seq seq(seeds.begin(), seeds.end());
  engine = std::mt19937(seq);
}

password_generators::~password_generators() {}

std::string password_generators::generate() {
  // 0以上9以下の値を等確率で発生させる
  std::string password;
  for (auto&& g : generators) {
    tokens += g->allowed_char();
    std::uniform_int_distribution<> dist(0, tokens.size() - 1);
    for (size_t i = 0; i < g->length(); i++) {
      int index = dist(engine);
      password.push_back(tokens[index]);
    }
  }

  return password;
}

void password_generators::add(std::unique_ptr<generator> g) {
  generators.push_back(std::move(g));
}

size_t password_generators::length() { return 0; }

std::string password_generators::allowed_char() { return std::string(); }

std::string basic_generator::generate() { return std::string(); }

void basic_generator::add(std::unique_ptr<generator> g) {}

size_t basic_generator::length() { return len; }

std::string uppercase_generator::allowed_char() {
  return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}
std::string number_generator::allowed_char() { return "0123456789"; }
std::string symbol_generator::allowed_char() { return "()!$&%#=-|^~{}[]@_?"; }
