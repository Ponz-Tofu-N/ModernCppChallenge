#include <gtest/gtest.h>
#include <algorithm>

#include "../systemhandler.h"

class SysHandlerTst : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        const std::string file0path = "files/file1.txt";
        const std::string file1path = "files/file2.txt";

        handlerlist.push_back(FileHandle(file0path.c_str()));
        handlerlist.push_back(FileHandle(file1path.c_str()));
        handlerlist.push_back(FileHandle());
    }

    std::vector<FileHandle> handlerlist;
    static constexpr unsigned int MAXSIZE = 1024u;
};

TEST_F(SysHandlerTst, valid)
{
    EXPECT_FALSE(!handlerlist[0]);
    EXPECT_FALSE(!handlerlist[1]);
    EXPECT_FALSE(handlerlist[2]);
}

TEST_F(SysHandlerTst, readFile1)
{
    char str_cp[MAXSIZE];
    read(handlerlist[0].get(), str_cp, MAXSIZE);

    std::string str(str_cp);
    EXPECT_EQ("for question 021 in file 1.", str);
}

TEST_F(SysHandlerTst, readFile2)
{
    char str_cp[MAXSIZE];
    read(handlerlist[1].get(), str_cp, MAXSIZE);

    std::string str(str_cp);
    EXPECT_EQ("C++ is difficult in file 2.", str);
}

TEST_F(SysHandlerTst, move)
{
    auto fd = handlerlist[1].get();
    FileHandle handler{std::move(handlerlist[1])};

    EXPECT_EQ(fd, handler.get());
    EXPECT_EQ(-1, handlerlist[1].get());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
