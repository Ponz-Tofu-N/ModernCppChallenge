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

        buf.fill('\0');
    }

    std::vector<FileHandle> handlerlist;
    static constexpr unsigned int MAXSIZE = 1024u;
    std::array<char, MAXSIZE> buf;

    const std::string ans_file1 = "this is a sample text for question 021 in file 1.";
    const std::string ans_file2 = "C++ is difficult for me in file 2.";
};

TEST_F(SysHandlerTst, valid)
{
    EXPECT_FALSE(!handlerlist[0]);
    EXPECT_FALSE(!handlerlist[1]);
    EXPECT_FALSE(handlerlist[2]);
}

TEST_F(SysHandlerTst, readFile1)
{
    read(handlerlist[0].get(), buf.data(), MAXSIZE);

    std::string str;
    for (size_t i = 0; buf[i] != '\0'; i++)
    {
        str.push_back(buf[i]);
    }
    
    EXPECT_EQ(ans_file1, str);
}

TEST_F(SysHandlerTst, readFile2)
{
    read(handlerlist[1].get(), buf.data(), MAXSIZE);

    std::string str;
    for (size_t i = 0; buf[i] != '\0'; i++)
    {
        str.push_back(buf[i]);
    }

    EXPECT_EQ(ans_file2, str);
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
