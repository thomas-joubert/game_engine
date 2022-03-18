#include <iostream>
#include <memory>

namespace logging
{
    class InfoLogger
    {
        public :
            static InfoLogger& instance();

            void logInfo(void);
            InfoLogger& operator<<(const std::string& t);
            void flush(void);

        private :
            InfoLogger() = default;

            InfoLogger(const InfoLogger& other) = delete;
            InfoLogger operator=(const InfoLogger& other) = delete;

            static InfoLogger *logger_;
            std::string log_ = "Log : ";
    };
}
