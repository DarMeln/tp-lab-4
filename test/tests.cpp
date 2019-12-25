#include "gtest/gtest.h"
#include "Automata.h"
#include <string.h>

using namespace std;

// task1
TEST(lab1,task1_1)
{
    Automata machine;
    machine.on();
    string res=machine->state;
    EXPECT_EQ(1,res);
}
TEST(lab1,task1_2)
{
    Automata machine;
    machine.coin(5);
    machine.coin(10);
    machine.choice(1);
    int res = machine->state;
    EXPECT_EQ(1,res);
}
