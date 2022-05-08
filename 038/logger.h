#include <filesystem>
#include <iostream>
#include <fstream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

namespace fs = std::filesystem;
class Logger
{
private:
    fs::path m_filepath;
    std::ofstream *ofstr = nullptr;
    bool canRemove = true;

    void make_logfile();
    void remove();
    void add_message(const std::string& message);

public:
    Logger(/* args */);
    ~Logger();

    void save();
    Logger& operator<<(const std::string& message);
};

Logger::Logger(/* args */)
{
    const boost::uuids::uuid uuid = boost::uuids::random_generator()();

    m_filepath = std::filesystem::temp_directory_path() / (boost::lexical_cast<std::string>(uuid) + ".tmp");

    std::cout << "Created: " << m_filepath << std::endl;
}

Logger::~Logger()
{
    if(canRemove)
        remove();
}

Logger& Logger::operator<<(const std::string& message)
{
    add_message(message);
    return *this;
}

void Logger::remove()
{
    std::filesystem::path logfile(m_filepath);
    std::filesystem::remove(logfile);
}

void Logger::save()
{
    canRemove = false;
}

void Logger::add_message(const std::string& message)
{
    std::ofstream ofstr;

    ofstr.open(m_filepath, std::ios_base::app);
    ofstr << message << std::endl;
    ofstr.close();
}
