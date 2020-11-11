#include <exception>
#include <string>

class UnvalidPath : public std::exception
{
    public :
        UnvalidPath(std::string path)
            : path_(path)
        {}

        const char* what()
        {
            return std::string(path_ + " is not a valid path").c_str();
        }

    private :
        std::string path_;
};
