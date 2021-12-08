#include "systemhandler.h"

#include <iostream>

FileHandle::FileHandle()
    : m_fd(-1)
{
}

FileHandle::FileHandle(const char* path, const int flag)
    : m_fd(open(path, flag))
{
}

FileHandle::FileHandle(FileHandle && other) noexcept
    : m_fd(other.release())
{
}

FileHandle::~FileHandle()
{
    close(m_fd);
}

int FileHandle::get() const noexcept
{
    return this->m_fd;
}

int FileHandle::release() noexcept
{
    auto buf_fd = this->m_fd;
    m_fd = -1; // invalid file descriptor
    return buf_fd;
}

FileHandle::operator bool() const
{
    return m_fd > 0;    
}