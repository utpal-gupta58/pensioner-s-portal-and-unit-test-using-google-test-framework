#include "main.cpp"
#include<bits/stdc++.h>
using namespace std;
#include<gtest/gtest.h>
//update_pension =====================================================================================
TEST(PENSION_test,show_pension1){
    EXPECT_EQ(true,show_updated_pension());
}
TEST(PENSION_test,update_pension1){
    EXPECT_EQ(true,update_pension(25));
}
TEST(PENSION_test,update_pension2){
    EXPECT_EQ(true,update_pension(0));
}
TEST(PENSION_test,update_pension3){
    EXPECT_EQ(false,update_pension(0));
}
TEST(PENSION_test,update_pension4){
    int prev=pension;
    update_pension(25);
    EXPECT_EQ(25+prev,pension);
}
TEST(PENSION_test,update_pension5){
    int prev=pension;
    update_pension(0);
    EXPECT_EQ(prev,pension);
    EXPECT_EQ(false,update_pension(0));

}
// member_check and member death and test =====================================================================================

TEST(login_DeathTest,dlogin1){
    occupation_check='A';
    EXPECT_EXIT(member(),::testing::ExitedWithCode(1),"");
}
TEST(login_DeathTest,dlogin2){
    occupation_check='O';
    EXPECT_EXIT(member(),::testing::ExitedWithCode(1),"");
}
TEST(login_DeathTest,dlogin3){
    occupation_check='F';
    EXPECT_EXIT(member(),::testing::ExitedWithCode(1),"");
}

TEST(login_test,login1){
    occupation_check='O';
    member();
    ASSERT_EQ(member_check,1);
}
TEST(login_test,login2){
    occupation_check='F';
    member();
    ASSERT_EQ(member_check,0);
}
//login() ============================================================================================
TEST(login_test,login3){
    name="abc";
    occupation_check='O';
    trial=0;
    member();
    c="superintendent";
    ASSERT_EQ(login(member_check),1);
}
TEST(login_test,login4){
    name="abc";
    occupation_check='O';
    trial=0;
    member();
    c="superintendent";
    ASSERT_EQ(login(member_check),0);
}
TEST(login_test,login5){
    name="abc";
    occupation_check='F';
    trial=0;
    member();
    c="sumankundu";
    ASSERT_EQ(login(member_check),1);
}
TEST(login_test,login6){
    name="abc";
    occupation_check='F';
    trial=1;
    member();
    c="sumankundu";
    ASSERT_EQ(login(member_check),1);
}




//choice_function =====================================================================================
TEST(choice_DeathTest,dchoice1){
    choice=6;
    EXPECT_DEATH(choice_function(),"6 was selected");
    EXPECT_EXIT(choice_function(), ::testing::ExitedWithCode(1),"6 was selected");
}
TEST(choice_DeathTest,dchoice2){
    choice=11;
    EXPECT_DEATH(choice_function(),"wrong key chosen");
    EXPECT_EXIT(choice_function(), ::testing::ExitedWithCode(1),"wrong key chosen");
}
TEST(choice_DeathTest,dchoice3){
    choice=11;
    EXPECT_DEATH(choice_function(),"6 was selected");
    EXPECT_EXIT(choice_function(), ::testing::ExitedWithCode(1),"6 was selected");
}

TEST(choice_Test,choice1){
    choice=1;
    choice_function();
    Name="utpal";
    age=19;
    department="CSE";
    EXPECT_EQ(true,x);
}
TEST(choice_Test,choice2){
    choice=2;
    pension_increment=25;
    choice_function();
    EXPECT_EQ(true,s);
}
TEST(choice_Test,choice3){
    choice=2;
    pension_increment=0;
    choice_function();
    EXPECT_EQ(false,s);
}
TEST(choice_Test,choice4){
    choice=3;
    choice_function();
    EXPECT_EQ(true,s);
}
TEST(choice_Test,choice5){
    choice=4;
    choice_function();
    EXPECT_EQ(true,e);
}
TEST(choice_Test,choice6){
    choice=5;
    application="abc";
    choice_function();
    EXPECT_EQ(true,p);
}
TEST(choice_Test,choice7){
    choice=5;
    application="";
    choice_function();
    EXPECT_EQ(false,p);
}
TEST(choice_Test,choice8){
    choice=7;
    a='Y';
    choice_function();
    EXPECT_EQ(true,g);
}
TEST(choice_Test,choice9){
    choice=7;
    a='N';
    choice_function();
    EXPECT_EQ(false,g);
}





int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}