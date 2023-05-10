/* 74. Selecting Data from XML using XPath*/

/*
 * Rule
 * - Print the all movie's titles released after the given year.
 * - Print the last actor in the casting list for the all movies.
 */

#include "movie_xml.h"

#include <cassert>
#include <iostream>

int main() {
  movie_list movies{{
                        11001,
                        "The Matrix",
                        1999,
                        196,
                        {{"Keanu Reeves", "Neo"},
                         {"Laurence Fishburne", "Morpheus"},
                         {"Carrie-Anne Moss", "Trinity"},
                         {"Hugo Weaving", "Agent Smith"}},
                        {"Lana Wachowski", "Lilly Wachowski"},
                        {"Lana Wachowski", "Lilly Wachowski"},
                    },
                    {
                        9871,
                        "Forrest Gump",
                        1994,
                        202,
                        {{"Tom Hanks", "Forrest Gump"},
                         {"Sally Field", "Mrs. Gump"},
                         {"Robin Wright", "Jenny Curran"},
                         {"Mykelti Williamson", "Bubba Blue"}},
                        {"Robert Zemeckis"},
                        {"Winston Groom", "Eric Roth"},
                    }};

  serialize(movies, "movies.xml");

  auto filtered = released_after("movies.xml", 1995);

  assert(filtered.size() == 1);
  assert(filtered[0] == "The Matrix");

  std::cout << "OK" << std::endl;
}
