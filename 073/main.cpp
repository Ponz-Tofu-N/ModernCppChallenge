/* 73. Serialize and Deserialize with XML*/

/*
 * Rule
 * - Deserialize from a file to a movie list
 * - Serialize from a movie list to a file
 */

#include <iostream>

#include "movie_xml.h"

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

  // auto result = deserialize("movies.xml");

  // assert(result.size() == 2);
  // assert(result[0].title == "The Matrix");
  // assert(result[1].title == "Forrest Gump");
}
