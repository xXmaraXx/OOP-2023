#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CircularQueue.h"
#include <string>


TEST_CASE("Circular Queue-unsigned") {
    CircularQueue<int> q(4);
    SECTION("add 2 elements, check size") {
        q.push(1);
        q.push(2);
        REQUIRE(q.size() == 2);
    }
}

TEST_CASE("Circular Queue-string") {
    CircularQueue<std::string> q(4);
    SECTION("add 2 elements, check size") {
        q.push("Hello");
        q.push("World");
        REQUIRE(q.size() == 2);
    }
}

TEST_CASE("Check if empty") {
    CircularQueue<int> q(4);
    q.push(2);
    q.pop();
    REQUIRE(q.empty());
}

/// fail
TEST_CASE("first and last on empty queue") {
    CircularQueue<std::string> q(4);
    REQUIRE_NOTHROW(q.front());
    REQUIRE_NOTHROW(q.back());
}

TEST_CASE("5 elements") {
    CircularQueue<int> q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    REQUIRE(q.back() == 5);
}

TEST_CASE("1000 elements") {
    CircularQueue<int> q(1000);
    for (int i = 1; i <= 1000; i++) {
        q.push(i);
    }
    for (int i = 1; i <= 1000; i++) {
        REQUIRE(q.front() == i);
        q.pop();
    }
    REQUIRE(q.empty());
}

///

TEST_CASE("initialization") {
    CircularQueue<int> q(4);
    REQUIRE(q.size() == 0);
    REQUIRE(q.empty());
}

//fail
TEST_CASE("empty") {
    CircularQueue<std::string> q(4);
    REQUIRE(q.empty());
    q.push("Hello");
    REQUIRE(q.empty());
}

TEST_CASE("size") {
    CircularQueue<int> q(4);
    SECTION("overwrite") {
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        REQUIRE(q.size() == 4);
        q.push(5);
        REQUIRE(q.size() == 4);
    }
    SECTION("decrementation") {
            q.push(1);
            q.push(2);
            q.push(3);
            q.push(4);
            REQUIRE(q.size() == 4);
            q.pop();
            REQUIRE(q.size() == 3);
    }
}


TEST_CASE("front and back") {
    CircularQueue<std::string> q(4);
    q.push("a");
    q.push("b");
    q.push("c");
    q.push("d");
    q.push("e");
    REQUIRE(q.back() == "e");
    REQUIRE(q.front() == "b");

}

//fail
TEST_CASE("pop on empty queue") {
    CircularQueue<std::string> q(4);
    REQUIRE_NOTHROW(q.pop());
}