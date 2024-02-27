#include "movie_json.h"

#include <iostream>

int main(int argc, char const *argv[])
{
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

    std::cout << serialize(movies) << std::endl;
    
    std::fstream fst;
    fst.open("movies.json",  std::ios_base::out);

    fst << serialize(movies);

    assert(movies == deserialize(std::string("movies.json")));

    return 0;
}
