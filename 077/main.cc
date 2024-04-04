#include "movie.h"
#include "movie_pdf.h"

int main(int argc, char const *argv[]) {
  movie_list movies{{
                        .title = "The Matrix",
                        .release_year = 1999,
                        .length = 196,
                    },
                    {
                        .title = "The Trueman Show",
                        .release_year = 198,
                        .length = 103,
                    },
                    {
                        .title = "The Pursuit of Happyness",
                        .release_year = 2006,
                        .length = 117,
                    },
                    {
                        .title = "The Fight Club",
                        .release_year = 1999,
                        .length = 139,
                    },
                    {
                        .title = "Forrest Gump",
                        .release_year = 1994,
                        .length = 202,
                    }};

  print_movie_list("list_of_movies.pdf", movies);

  return 0;
}
