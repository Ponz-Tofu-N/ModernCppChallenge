#include <string>
#include <vector>

struct cast_role {
  std::string actor;
  std::string role;
};

struct movie {
  uint32_t id;
  std::string title;                   // "The Matrix",
  uint32_t release_year;               // 1999,
  uint32_t length;                     // 196,
  std::vector<cast_role> casts;        // {{"Keanu Reeves", "Neo"},
                                       //  {"Laurence Fishburne", "Morpheus"},
                                       //  {"Carrie-Anne Moss", "Trinity"},
                                       //  {"Hugo Weaving", "Agent Smith"}},
  std::vector<std::string> directors;  // {"Lana Wachowski", "Lilly Wachowski"},
  std::vector<std::string> writers;    // {"Lana Wachowski", "Lilly Wachowski"},
};

using movie_list = std::vector<movie>;
