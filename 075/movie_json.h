#include "movie.h"
#include <nlohmann/json.hpp>
#include <string>

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
