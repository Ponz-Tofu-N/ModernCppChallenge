#include <pugixml.hpp>

#include "movie.h"

void make_element(
    pugi::xml_node node, std::string const& element,
    std::vector<std::pair<std::string, std::string>> const& attrs) {
  node.set_name(element.c_str());
  for (auto&& attr : attrs) {
    node.append_attribute(attr.first.c_str()) = attr.second.c_str();
  }
};

std::vector<std::pair<std::string, std::string>> make_casting_list(
    cast_role const& cast) {
  std::vector<std::pair<std::string, std::string>> ret;
  ret.push_back(std::make_pair("star", cast.actor));
  ret.push_back(std::make_pair("name", cast.role));

  return ret;
};

std::vector<std::pair<std::string, std::string>> make_staff(
    std::string const& staff) {
  return std::vector<std::pair<std::string, std::string>>{
      std::make_pair("name", staff)};
};

void serialize(movie_list list, std::string filepath) {
  pugi::xml_document doc;

  for (auto&& movie : list) {
    auto movie_node = doc.append_child();

    make_element(movie_node, "movie",
                 {
                     {"id", std::to_string(movie.id)},
                     {"year", std::to_string(movie.release_year)},
                     {"title", movie.title},
                     {"length", std::to_string(movie.length)},
                 });

    auto cast_node = movie_node.append_child("cast");

    for (auto&& cast : movie.casts) {
      make_element(cast_node.append_child(), "role", make_casting_list(cast));
    }

    auto director_node = movie_node.append_child("directors");
    for (auto&& director : movie.directors) {
      make_element(director_node.append_child(), "director",
                   make_staff(director));
    }

    auto writer_node = movie_node.append_child("writers");
    for (auto&& writer : movie.writers) {
      make_element(writer_node.append_child(), "writer", make_staff(writer));
    }

    doc.save_file(filepath.c_str());
  }
};

movie_list deserialize(std::string filepath) {
  pugi::xml_document doc;

  doc.append_child("movie");
};