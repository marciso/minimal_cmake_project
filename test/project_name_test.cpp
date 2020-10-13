#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include "catch2/internal/catch_main.cpp"

#include "project_name.hpp"

TEST_CASE( "My test", "[test]" ) {
    REQUIRE( 1 == 1 );
}
