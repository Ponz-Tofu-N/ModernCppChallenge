#include <string>
#include <filesystem>
#include <numeric>
#include <iostream>

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