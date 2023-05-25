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

class Control_Register;
class Control_DeleteAccount;
class Control_Login;
class Control_Logout;
class Control_ApplyRecruit;


//================= REGISTER_UI ====================
class UI_Register
{
private:
    Control_Register* control_register;
public:
    UI_Register(Control_Register* Reg, MemberList* memberlist){
        cout << "UI 생성완료\n";
        control_register = Reg;
        this->startInterface(memberlist);
    }
    void startInterface(MemberList* memberlist);
    void addAccount(MemberList* memberlist, int type);
    
};


//================= Login_UI ====================
class UI_Login
{
private:
    Control_Login* control_login;
public:
    UI_Login(Control_Login* Log, int type, MemberList* memberlist, string* curID, string* curPW){
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
class UI_DeleteAccount
{
private:
    Control_DeleteAccount* control_deleteAccount;
public:
    UI_DeleteAccount(Control_DeleteAccount* DelAccount, MemberList* memberlist, string* curID, string* curPW){
        cout <<"UI 생성완료\n";
        control_deleteAccount = DelAccount;
        this->startInterface(memberlist, curID, curPW);
    }
    
    void startInterface(MemberList*, string*, string*);
    void DeleteAccount(MemberList*, string*, string*);
    
    
};




//================= ApplyRecruit_UI ====================
class UI_ApplyRecruit{
private:
    Control_ApplyRecruit* control_applyrecruit;
public:
    UI_ApplyRecruit(Control_ApplyRecruit* applyrec, MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW){
        cout <<"UI Generated\\nn";
        control_applyrecruit = applyrec;
        this->startInterface(memberlist,recruitlist, curID, curPW);
    }
    
    void startInterface(MemberList*, RecruitInfoList*, string*  , string*);
    void addRecruit(MemberList*, RecruitInfoList*,  string*, string*);
    
};


/*
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 */


//================= REGISTER_CONTROL ====================
class Control_Register
{
private:
    UI_Register* ui_register;
public:
    void call_startInterface(MemberList* memberlist);
    void createAccount(MemberList* memberlist, int type);
};



//================= LOGIN_CONTROL ====================
class Control_Login
{
private:
    UI_Login* ui_login;
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
class Control_DeleteAccount
{
private:
    UI_DeleteAccount* ui_deleteaccount;
public:
    void call_startInterface(MemberList* , string*, string*); //근데 로그인이 된 상태여야하지 않나?
    void deleteAccount(MemberList*, string*, string*);
    
};

//====================3.1 채용 정보 등록=======================
//+++++++++++++ 민아님 ++++++++++++++++
class UI_ApplyRecruit{
public:   
    void startInterface();
}

class Control_ApplyRecruit{
private:
    UI_ApplyRecruit* ui_applyrecruit;
public:
    void call_startInterface(MemberList* , RecruitInfoList*, string*, string*); //근데 로그인이 된 상태여야하지 않나?
    void addRecruit(MemberList* memberlist, RecruitInfoList*, string* curID, string* curPW);
};


//====================3.2 채용 정보 조회

class UI_ApplyRecruitInfo{
    void startInterface();
}

class Control_ApplyRecruitInfo{
    private:
        UI_ApplyRecruitInfo* ui_applyrecruitinfo;
    public:
        void call_startInterface();
        void showRecruitInfo(MemberList* memberlist, RecruitInfoList*, string* curID, string* curPW);       
}






//====================4.1 채용 정보 검색

class RecruitInfoSearchUI
{
private:
public:
};

class RecruitInfoSearch
{
private:
public:
};

//====================4.2 채용 지원==================================

class ApplyUI
{
private:
public:
};

class Apply
{
private:
public:
};



/*
//====================4.3===================================
class UI_Application { // boundary
private:
    Application* control_applicaion;
public:
    ApplicationUI(Application* Apply, MemberList* memberlist);
    void startInterface(MemberList* memberlist);
    void startApplication(MemberList* memberlist);
};

class Application { // control
private:
    ApplicationUI* ui_application;
    
public://memberList에서 recruitInfo를 바로 접근 가능한가?
    void call_startInterface(MemberList* memberlist);
    void showList(MemberList* memberlist);
};
//==============================================
class CancelApplyUI { //아니 멀쩡하게 있구만...
private:
    CancelApply* control_CancelApply;
public:
    CancelApplyUI(CancelApply* cancelApply, MemberList* memberlist, int businessNumber);
    void startInterface(MemberList* memberlist, int businessNumber);//여기 있는데...
    void startCancel(MemberList* memberlist, int businessNumber);
};

class CancelApply {
private:
    CancelApplyUI* ui_cancelApply;
    
public://memberList에서 recruitInfo를 바로 접근 가능한가?
    void showCancel(MemberList* member, int businessNumber);
    void call_startInterface(MemberList* member, int businessNumber);
    
};
//===========================================
class StatisticUI {
private:
    Statistic* control_statistic;
public:
    StatisticUI(Statistic* statistic, MemberList* member);//type number을 바로 접근 가능한가?
    void startInterface(MemberList* member);
};



class Statistic {
private:
    StatisticUI* ui_statistic;
    
public:
    void call_startInterface(MemberList* member);
    void getStat(MemberList* memeber);
};

*/


#endif /* boundary_h */