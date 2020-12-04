#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <stdexcept>
#include <utility>
#include <iostream>

#include  "logger.hh"

TEST(Logger_tests, log_info_simple)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    log::InfoLogger& logger = log::InfoLogger::instance();

    logger << "hello je suis un log\n";

    ASSERT_EQ(buffer.str(), "Log : hello je suis un log\n");

    logger.flush();

    std::cout.rdbuf(sbuf);
}

TEST(Logger_tests, log_info_multiple)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    log::InfoLogger& logger = log::InfoLogger::instance();

    logger << "hello je suis un log\n" << "hello je suis un deuxieme log\n";

    ASSERT_EQ(buffer.str(), "Log : hello je suis un log\nLog : hello je suis un deuxieme log\n");
    logger.flush();

    std::cout.rdbuf(sbuf);
}

TEST(Logger_tests, log_info_multiple_last_no_escape)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    log::InfoLogger& logger = log::InfoLogger::instance();

    logger << "hello je suis un log\n" << "hello je suis un deuxieme log";

    ASSERT_EQ(buffer.str(), "Log : hello je suis un log\n");

    logger.flush();

    std::cout.rdbuf(sbuf);
}

TEST(Logger_tests, log_info_multiple_last_no_escape_manual_flush)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    log::InfoLogger& logger = log::InfoLogger::instance();

    logger << "hello je suis un log\n" << "hello je suis un deuxieme log";

    logger.logInfo();

    ASSERT_EQ(buffer.str(), "Log : hello je suis un log\nLog : hello je suis un deuxieme log\n");
    logger.flush();

    std::cout.rdbuf(sbuf);
}

TEST(Logger_tests, log_info_no_escape)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    log::InfoLogger& logger = log::InfoLogger::instance();

    logger << "hello je suis un log";

    ASSERT_EQ(buffer.str(), "");

    logger.flush();

    std::cout.rdbuf(sbuf);
}

TEST(Logger_tests, log_info_no_escape_manual_flush)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    log::InfoLogger& logger = log::InfoLogger::instance();

    logger << "hello je suis un log";

    logger.logInfo();

    ASSERT_EQ(buffer.str(), "Log : hello je suis un log\n");
    logger.flush();

    std::cout.rdbuf(sbuf);
}
