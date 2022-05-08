#include <string>
#include <filesystem>
#include <numeric>
#include <iostream>
#include <chrono>

// for Q.037
#include <regex>

std::size_t directory_size(const std::string &dir)
{
    // 型名ではない名前空間の別名はusingではなくnamespaceで宣言する。
    namespace fs = std::filesystem;

    fs::path dir_path(dir);

    //再帰なしのdirectory_iteratorというクラスもある。
    fs::recursive_directory_iterator rdir_itr(dir_path);

    // 第3引数は初期値、第4引数は最終結果（returnは項ごとの結果ではなく、全体合算の値）
    // その項は0でもreturnを0にすると、それまでの加算結果も0で上書きされる
    return std::accumulate(fs::begin(rdir_itr), fs::end(rdir_itr), 0UL,
                           [&](std::size_t total, const fs::directory_entry &e)
                           {
                               if (fs::is_regular_file(e))
                                   return total + fs::file_size(e.path());

                               return total;
                           });
}

void list_directory(std::string &dir)
{
    namespace fs = std::filesystem;

    fs::path dir_path(dir);
    fs::recursive_directory_iterator rdir_itr(dir_path);

    while (fs::end(rdir_itr) != rdir_itr)
    {
        std::cout << (*rdir_itr).path().c_str() << std::endl;
        rdir_itr++;
    }
}

std::string datetime_to_string(const std::chrono::system_clock::time_point tp)
{
    namespace fs = std::filesystem;
    namespace chrono = std::chrono;

    auto sec = chrono::duration_cast<chrono::seconds>(tp.time_since_epoch());

    std::time_t t = sec.count();
    const std::tm *lt = std::localtime(&t);

    std::ostringstream ss;
    ss << std::put_time(lt, "%c");
    return ss.str();
}

template <typename Duration>
void remove_file(const std::string &dir, Duration d)
{
    namespace fs = std::filesystem;

    // chronoとfilesystemのエポックが異なる
    // - filesystem
    //   "This clock's (unspecified) epoch is 2174-01-01 00:00:00 UTC."
    //   https://github.com/gcc-mirror/gcc/blob/16e2427f50c208dfe07d07f18009969502c25dc8/libstdc%2B%2B-v3/include/std/chrono#L3280
    // - chrono
    //   "The Unix epoch is 00:00:00 UTC on 1 January 1970 (an arbitrary date) - Unix time"
    //   https://en.wikipedia.org/wiki/Unix_time

    const auto epochBias = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        std::chrono::system_clock::now() - fs::file_time_type::clock::now().time_since_epoch());

    fs::path dir_path(dir);
    fs::recursive_directory_iterator file(dir_path);

    while (file != fs::end(file))
    {
        if ((*file).is_regular_file())
        {
            auto now = std::chrono::system_clock::now();
            auto duraiton = (now - d).time_since_epoch();
            auto lwt = std::chrono::time_point_cast<std::chrono::system_clock::duration>(fs::last_write_time((*file).path()).time_since_epoch() + epochBias);

            if (duraiton > lwt.time_since_epoch())
            {
                std::cout << (*file).path().filename() << std::endl;
                std::cout << datetime_to_string(lwt) << std::endl;

                fs::remove((*file).path());
            }
        }

        file++;
    }
}

std::vector<std::string> findByRegex(const std::string &path, const std::regex &re)
{
    namespace fs = std::filesystem;

    fs::path dir_path(path);
    std::smatch matches;
    fs::recursive_directory_iterator file(dir_path);
    
    std::vector<std::string> hit_files;

    while (file != fs::end(file))
    {
        if ((*file).is_regular_file())
        {
            auto filename = (*file).path().filename().generic_string();
            std::regex_match(filename, matches, re);
            if(matches[0].matched)
                hit_files.push_back(matches[0].str());
        }

        file++;
    }

    return hit_files;
}

std::vector<std::filesystem::directory_entry> findByRegexA(const std::string &path, const std::regex &re)
{
    namespace fs = std::filesystem;

    fs::path dir_path(path);
    fs::recursive_directory_iterator file(dir_path);
    
    std::vector<fs::directory_entry> hit_files;

    std::copy_if(fs::begin(file), fs::end(file), std::back_inserter(hit_files), [&](const fs::directory_entry e){
        return std::regex_match(e.path().filename().string(), re) && fs::is_regular_file(e);
    });

    return hit_files;
}
