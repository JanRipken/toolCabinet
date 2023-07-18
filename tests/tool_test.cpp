#define BOOST_TEST_MODULE ToolTests
#include <boost/test/included/unit_test.hpp>
#include "../header/tool.hpp"


BOOST_AUTO_TEST_SUITE(ToolTestSuite)

BOOST_AUTO_TEST_CASE(TestToolGetSet) {
    tool _tool;
    _tool.setname("Hammer");
    _tool.setlagerort("A1");

    BOOST_CHECK_EQUAL(_tool.getname(), "Hammer");
    BOOST_CHECK_EQUAL(_tool.getlagerort(), "A1");
}

BOOST_AUTO_TEST_SUITE_END()

