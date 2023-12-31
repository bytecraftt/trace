#include "Trace.h"

unsigned char Trace::flag_ = Level::ALL;
std::string Trace::file_ = ".";
unsigned short Trace::tab_ = 0;

Trace::Trace(const std::string &message) : level_(Level::ALL), message_(message)
{
    tab_++;
    Print(Level::DEBUG == level_ ? "BEGIN" : "");
}

Trace::Trace(Level level, const std::string &message) : level_(level), message_(message)
{
    tab_++;
    Print(Level::DEBUG == level_ ? "BEGIN" : "");
}

Trace::~Trace()
{
    if (Level::DEBUG == level_)
    {
        Print("END");
    }
    tab_--;
}

void Trace::SetTraceLevelFlag(unsigned char flag)
{
    flag_ = flag;
}

void Trace::SetFileName(const std::string &file)
{
    file_ = file;
}

Trace::operator std::string() const
{
    return Line();
}

std::string Trace::Line(const std::string &tail) const
{
    std::string result = std::string(tab_ - 1, '\t') + "[" + CurrentDateTimeToString() + "][" + LevelToString(level_);

    if (tail.size())
    {
        result += "][" + tail;
    }
    
    result += "]: " + message_ + "\n";

    return result;
}

void Trace::Print(const std::string &tail) const
{
    if (!(flag_ & level_))
    {
        return;
    }

    std::string buffer = Line(tail);

    std::cout << buffer;

    Write(buffer);   
}

void Trace::Write(const std::string &line) const
{
    std::ofstream file(file_, std::ios::out | std::ios::app);

    if (!file.is_open())
    {
        return;
    }

    file << line;

    file.close();
}

std::string Trace::LevelToString(Level level)
{
    std::string result;

    switch (level)
    {
    case Level::ERROR:
        result = "ERROR";
        break;
    case Level::WARRNING:
        result = "WARRNING";
        break;
    case Level::INFORMATION:
        result = "INFORMATION";
        break;
    case Level::DEBUG:
        result = "DEBUG";
        break;
    case Level::ALL:
    default:
        result = "ALL";
        break;
    }

    return result;
}

std::string Trace::CurrentDateTimeToString()
{
    auto currentTimePoint = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);
    std::tm currentTm = *std::localtime(&currentTime);
    char buffer[80] = {'\0'};
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &currentTm);
    std::string result(buffer);

    return result;
}