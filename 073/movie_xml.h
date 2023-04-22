#include <pugixml.hpp>

#include "movie.h"

void serialize(movie_list list, std::string filepath) {
  pugi::xml_document doc;

  auto node = doc.append_child("movie");
  node.append_attribute("year") = "1993";
  doc.save_file(filepath.c_str());
};
movie_list deserialize(std::string filepath) {
  pugi::xml_document doc;

  doc.append_child("movie");
};