/* 53. Average Movies Rating */

/*
 * features
 * - Remove the highest and lowest 5% ratings before taking the average.
 * - trimmed mean
 */

#include "movie.h"

int main()
{
  std::vector<movie::movie> movies{
      {101, "The Matrix", {10, 9, 10, 9, 9, 8, 7, 10, 5, 9, 9, 8}},
      {102, "Gladiator", {10, 5, 7, 8, 9, 8, 9, 10, 10, 5, 9, 8, 10}},
      {103, "Interstellar", {10, 10, 10, 9, 3, 8, 8, 9, 6, 4, 7, 10}}};

  movie::print_ratings(movies);
}
