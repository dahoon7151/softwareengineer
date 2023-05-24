#ifndef boundary_h
#define boundary_h

#include <iostream>
#include "entity.h"
#include <fstream>
#include <sstream>


using namespace std;

/*
 ############################################### // UI // ########################################################################
 ############################################### // UI // ########################################################################
 ############################################### // UI // ########################################################################
 */

class RegisterControl;
class LoginControl;

//================= REGISTER_UI ====================
class RegisterUI
{
private:
    RegisterControl* control_register;
public:
    RegisterUI(RegisterControl* Reg, MemberList* memberlist){
        cout << "UI 생성완료\n";
        control_register = Reg;
        this->startInterface(memberlist);
    }
    void startInterface(MemberList* memberlist);
    void addAccount(MemberList* memberlist, int type);
    
};


//================= Login_UI ====================
class LoginUI
{
private:
    LoginControl* control_login;
public:
    LoginUI(LoginControl* Log, MemberList* memberlist){
        cout << "UI 생성완료\n";
        control_login = Log;
        this->startInterface(memberlist);
    }
    
    void startInterface(MemberList* memberlist);
    void LogIn(MemberList* memberlist);
    
};





/*
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 */


//================= REGISTER_CONTROL ====================
class RegisterControl
{
private:
    RegisterUI* ui_register;
public:
    void call_startInterface(MemberList* memberlist);
    void createAccount(MemberList* memberlist, int type);
};



//================= LOGIN_CONTROL ====================
class LoginControl
{
private:
    LoginUI* ui_login;
public:
    void call_startInterface(MemberList* memberlist);
    void Login(MemberList* memberlist);
    
};




//============================== 다훈 ==============================////
RecruitInfo RecruitInfoList[50];

class RecruitInfoSearchUI
{
public:
    char CompanyName[MAX_STRING];

    void startInterface()
    {
        fprintf_s(out_fp, "4.1. 채용 정보 검색\n");
    }
    void searchCompName()     //search()를 변경
    {
        fscanf_s(in_fp, "%s", CompanyName, sizeof(CompanyName));
    }
};

class RecruitInfoSearch
{
public:
    char CompanyName[MAX_STRING];
    int BusinessNumber;
    char task[MAX_STRING];
    int applyNumber;
    char deadline[MAX_STRING];
    
    void showList()
    {

        RecruitInfoSearchUI recruitinfosearchui;
        recruitinfosearchui.startInterface();
        recruitinfosearchui.searchCompName();

        int found = 0;
        for (int i = 0; i < 50; i++)
        {
            found = RecruitInfoList[i].getCompList(recruitinfosearchui.CompanyName, &BusinessNumber, task, &applyNumber, deadline);
            if (found == 0)
                break;
        }
    }
};

class Apply
{
public:
    char 
};


#endif /* boundary_h */
