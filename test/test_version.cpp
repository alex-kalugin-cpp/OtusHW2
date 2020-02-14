#define BOOST_TEST_MODULE test_version


#include "../simpleIP4/simpleIP4.h"
#include <string>
#include <boost/test/unit_test.hpp>
// сюда надо еще кучу тестов, а может нет
//test
BOOST_AUTO_TEST_SUITE(test_simpleIP4)

BOOST_AUTO_TEST_CASE(test_consructor)
{


    SimpleIP4 test(1,2,3,4);
    BOOST_CHECK_EQUAL(test.GetByte1(), 1);
    BOOST_CHECK_EQUAL(test.GetByte2(), 2);
    BOOST_CHECK_EQUAL(test.GetByte3(), 3);
    BOOST_CHECK_EQUAL(test.GetByte4(), 4);

}
BOOST_AUTO_TEST_CASE(test_less)
{
    SimpleIP4 test1(1,2,13,4);
    SimpleIP4 test2(1,2,3,44);
    BOOST_CHECK_EQUAL((test1 < test2), false);
}
}
BOOST_AUTO_TEST_SUITE(test_foo)
BOOST_AUTO_TEST_CASE(test_Parse)
{
    std::string ipstr1("1.2.3.4");
    SimpleIP4 test = ParseIP4(ipstr1);
    BOOST_CHECK_EQUAL(test.GetByte1(), 1);
    BOOST_CHECK_EQUAL(test.GetByte2(), 2);
    BOOST_CHECK_EQUAL(test.GetByte3(), 3);
    BOOST_CHECK_EQUAL(test.GetByte4(), 4);
}
}
