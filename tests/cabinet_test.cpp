#define BOOST_TEST_MODULE CabinetTests
#include <boost/test/included/unit_test.hpp>
#include "../header/cabinet.hpp"
#include "../header/tool.hpp"

BOOST_AUTO_TEST_SUITE(CabinetTestSuite)


BOOST_AUTO_TEST_CASE(TestCabinetInsertTool) {
    cabinet _cabinet;
    tool _tool;
    _tool.setname("Hammer");
    _tool.setlagerort("A1");

    _cabinet.insertTool(_tool);

    BOOST_CHECK_EQUAL(_cabinet.getListe().size(), 1);
    BOOST_CHECK_EQUAL(_cabinet.getListe()[0].getname(), "Hammer");
    BOOST_CHECK_EQUAL(_cabinet.getListe()[0].getlagerort(), "A1");
}

// Weitere Testfälle für die Methoden in cabinet.cpp

BOOST_AUTO_TEST_SUITE_END()

