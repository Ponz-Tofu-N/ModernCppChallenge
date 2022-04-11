/* 33. Print process list */

/*
 * Features:
 * Process info -> name, id, status, account, memsize, pfbit
 * print sorted process list.
 */

#include "process_out.h"


int main()
{
    std::vector<ProcessInfo> procs{
        {
            1523, 
            "chrome.exe",
            "james b",
            Status::Running,
            1523458, 
            PFbit::Bit32
        },
        {
            54, 
            "application.exe",
            "james b",
            Status::Running,
            123485, 
            PFbit::Bit64
        },
        {
            457, 
            "cmd.exe",
            "SYSTEM",
            Status::Running,
            1523458, 
            PFbit::Bit64
        },
        {
            42, 
            "memo.exe",
            "james b",
            Status::Suspended,
            1523458, 
            PFbit::Bit32
        }
    };

    printProcesses(procs);
    
    return 0;
}
