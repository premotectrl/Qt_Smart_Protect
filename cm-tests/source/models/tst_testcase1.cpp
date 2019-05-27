#include <QtTest>

// add necessary includes here

class testcase1 : public QObject
{
    Q_OBJECT

public:
    testcase1();
    ~testcase1();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

testcase1::testcase1()
{

}

testcase1::~testcase1()
{

}

void testcase1::initTestCase()
{

}

void testcase1::cleanupTestCase()
{

}

void testcase1::test_case1()
{

}

QTEST_APPLESS_MAIN(testcase1)

#include "tst_testcase1.moc"
