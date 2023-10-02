#pragma once

#include <string>
#include <iostream>

enum Level
{
    ERROR = 0x1,
    WARRNING = 0x2,
    INFORMATION = 0x4,
    DEBUG = 0x8,
    ALL = 0xF
};

class Trace
{
public:
    explicit Trace(const std::string &message);
    explicit Trace(Level level, const std::string &message);
    
    Trace(const Trace &trace) = delete;

    ~Trace();

    static void SetTraceLevelFlag(unsigned char flag);
protected:
    void Print(const std::string &tail) const;

    static std::string LevelToString(Level level);
    static std::string CurrentDateTimeToString();
private:
    Level level_;
    std::string message_;
    static unsigned char flag_;
};