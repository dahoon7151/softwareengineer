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






#endif /* boundary_h */
