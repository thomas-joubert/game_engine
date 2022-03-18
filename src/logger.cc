#include "logger.hh"

#define BASE_LOG "Log : "

namespace logging
{
    InfoLogger *InfoLogger::logger_;

    InfoLogger& InfoLogger::instance()
    {
        if (!logger_)
            logger_ = new InfoLogger;

        return *logger_;
    }

    void InfoLogger::logInfo(void)
    {
        if (log_[log_.size() - 1] != '\n')
            std::cout << log_ << '\n';

        flush();
    }

    InfoLogger& InfoLogger::operator<<(const std::string& t)
    {
        int index = 0;
        for (size_t i = 0; i < t.size(); i++)
        {
            if (t[i] == '\n')
            {
                log_ += t.substr(index, i);
                logInfo();
                index = i + 1;
            }
        }

        log_ += t.substr(index);

        return *this;
    }

    void InfoLogger::flush(void)
    {
        log_ = BASE_LOG;
    }
}
