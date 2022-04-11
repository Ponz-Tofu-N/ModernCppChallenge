#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

enum class Status
{
    Running,
    Suspended
};

enum class PFbit
{
    Bit32,
    Bit64
};

struct ProcessInfo
{
    int id;
    std::string name;
    std::string account;
    Status status;
    size_t memsize;
    PFbit pfbit;
};

std::ostream& operator<< (std::ostream& os, const Status& status)
{
    switch (status)
    {
    case Status::Running:
        os << "Running";
        return os;
    case Status::Suspended:
        os << "Suspended";
        return os;
    default:
        return os;
    }
}

std::ostream& operator<< (std::ostream& os, const PFbit& bit)
{
    switch (bit)
    {
    case PFbit::Bit32:
        os << "32-bit";
        return os;
    case PFbit::Bit64:
        os << "64-bit";
        return os;
    default:
        return os;
    }
}

void printProcesses(std::vector<ProcessInfo>& procs)
{
    std::sort(procs.begin(), procs.end(), [&](const ProcessInfo& p1, const ProcessInfo& p2){
        return p1.name < p2.name;
    });

    for (auto &&process : procs)
    {
        std::cout << std::left << std::setw(8) << process.id
                  << std::left << std::setw(18) << process.name
                  << std::left << std::setw(10) << process.status
                  << std::left << std::setw(10) << process.memsize
                  << std::left << std::setw(10) << process.pfbit << std::endl;
    }
}
