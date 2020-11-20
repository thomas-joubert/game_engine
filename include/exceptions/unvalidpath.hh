#include <exception>
#include <string>

class UnvalidPath : public std::exception
{
    public :
        UnvalidPath(std::string path)
        {
            message_ = path + " is not a valid path.";
        }

        virtual const char* what() const noexcept
        {
            return message_.c_str();
        }

    private :
        std::string message_;
};
