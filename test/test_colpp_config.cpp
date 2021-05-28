#include <doctest.h>

#include "colpp/colpp.hpp"
#include "colpp/colpp_config.hpp"



TEST_SUITE_BEGIN("core");

TEST_CASE("check version"){

    #ifndef COLPP_VERSION_MAJOR
        #error "COLPP_VERSION_MAJOR is undefined"
    #endif
    

    #ifndef COLPP_VERSION_MINOR
        #error "COLPP_VERSION_MINOR is undefined"
    #endif


    #ifndef COLPP_VERSION_PATCH
        #error "COLPP_VERSION_PATCH is undefined"
    #endif

    CHECK_EQ(COLPP_VERSION_MAJOR , 0);
    CHECK_EQ(COLPP_VERSION_MINOR , 1);
    CHECK_EQ(COLPP_VERSION_PATCH , 0);
}



TEST_SUITE_END(); // end of testsuite core
