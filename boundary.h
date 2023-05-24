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
class LogoutControl;
class DeleteAccountControl;

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
    LoginUI(LoginControl* Log, int type, MemberList* memberlist, string* curID, string* curPW){
        cout << "UI 생성완료\n";
        control_login = Log;
        this->startInterface(memberlist, type, curID, curPW);
    }
    
    void startInterface(MemberList* memberlist, int type, string*, string*);
    void LogIn(MemberList* memberlist, string* , string* );
    void LogOut(MemberList* memberlist, string*, string*);
    
};



/*
//================= Logout_UI ====================
class LogoutUI
{
private:
    LogoutControl* control_logout;
public:
    LogoutUI(LogoutControl* Log, MemberList* memberlist){
        cout << "UI 생성완료\n";
        control_logout = Log;
        this->startInterface(memberlist);
    }
    
    void startInterface(MemberList* memberlist);
    void LogOut(MemberList* memberlist, string*, string*);
    
};
 
 */


//================= DeleteAccount_UI ====================
class DeleteAccountUI
{
private:
    DeleteAccountControl* control_deleteAccount;
public:
    DeleteAccountUI(DeleteAccountControl* DelAccount, MemberList* memberlist, string* curID, string* curPW){
        cout <<"UI 생성완료\n";
        control_deleteAccount = DelAccount;
        this->startInterface(memberlist, curID, curPW);
    }
    
    void startInterface(MemberList*, string*, string*);
    void DeleteAccount(MemberList*, string*, string*);
    
    
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
    void call_startInterface(MemberList* memberlist, int type, string*, string*);
    void Login(MemberList* memberlist, string* curID, string* curPW);
    void Logout(MemberList* memberlist, string* curID, string* curPW);
    
};


/*

//================= LOGOUT_CONTROL ====================
class LogoutControl
{
private:
    LogoutUI* ui_logout;
public:
    void call_startInterface(MemberList* memberlist);
    void Logout(MemberList* memberlist, string* curID, string* curPW);
    
};
*/




//=================DELETEACCOUNT_CONTROL ====================
class DeleteAccountControl
{
private:
    DeleteAccountUI* ui_deleteaccount;
public:
    void call_startInterface(MemberList* , string*, string*); //근데 로그인이 된 상태여야하지 않나? 
    void deleteAccount(MemberList*, string*, string*);
    
};


#endif /* boundary_h */
