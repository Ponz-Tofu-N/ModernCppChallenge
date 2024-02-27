#include "movie.h"
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>

using json = nlohmann::json;

std::string serialize(const std::vector<movie> &movies)
{
    json movies_json;
    movies_json["movies"] = json::array();

    for (auto &&movie_item : movies)
    {
        json movie_json;

        movie_json["id"] = movie_item.id;
        movie_json["title"] = movie_item.title;
        movie_json["year"] = movie_item.release_year;
        movie_json["length"] = movie_item.length;

        for (auto &&cast : movie_item.casts)
        {
            json cast_json;

            cast_json["star"] = cast.actor;
            cast_json["name"] = cast.role;

            movie_json["cast"].push_back(cast_json);
        }

        movie_json["directors"] = movie_item.directors;
        movie_json["writers"] = movie_item.writers;

        movies_json["movies"].push_back(movie_json);
    }

    return movies_json.dump(2);
}

movie_list deserialize(const std::string& filepath)
{
    movie_list list;
    std::ifstream i(filepath);
    json j;
    i >> j;

    for (auto &&movie_json : j["movies"])
    {
        movie m;

        m.id = movie_json["id"];
        m.title = movie_json["title"];
        m.release_year = movie_json["year"];
        m.directors = movie_json["directors"];
        m.writers = movie_json["writers"];
        m.length = movie_json["length"];

        for (auto &&cast_json : movie_json["cast"])
        {
            cast_role cast;
            
            cast.actor = cast_json["star"];
            cast.role = cast_json["name"];
            
            m.casts.push_back(cast);
        }

        list.push_back(m);
    }

    return list;
}