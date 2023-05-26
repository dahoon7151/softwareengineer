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
class Control_ApplyRecruitInfo;
class Control_RecruitInfoSearch;
class Control_Apply;
class Control_Statistic;
class Control_CancelApply;
class Control_Application;

//================= REGISTER ====================
class UI_Register
{
private:
    Control_Register* control_register;
public:
    UI_Register(Control_Register* Reg, MemberList* memberlist){
        control_register = Reg;
        this->startInterface(memberlist);
    }
    void startInterface(MemberList* memberlist);
    void addAccount(MemberList* memberlist, int type);
    
};


class Control_Register
{
private:
    UI_Register* ui_register;
public:
    void call_startInterface(MemberList* memberlist);
    void createAccount(MemberList* memberlist, int type);
};



//================= Login_UI ====================
class UI_Login
{
private:
    Control_Login* control_login;
public:
    UI_Login(Control_Login* Log, int type, MemberList* memberlist, string* curID, string* curPW){
        control_login = Log;
        this->startInterface(memberlist, type, curID, curPW);
    }
    
    void startInterface(MemberList* memberlist, int type, string*, string*);
    void LogIn(MemberList* memberlist, string* , string* );
    void LogOut(MemberList* memberlist, string*, string*);
    
};


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


class Control_DeleteAccount
{
private:
    UI_DeleteAccount* ui_deleteaccount;
public:
    void call_startInterface(MemberList* , string*, string*); //근데 로그인이 된 상태여야하지 않나?
    void deleteAccount(MemberList*, string*, string*);
    
};



//================= ApplyRecruit_UI ====================
class UI_ApplyRecruit{
private:
    Control_ApplyRecruit* control_applyrecruit;
public:
    UI_ApplyRecruit(Control_ApplyRecruit* applyrec, MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW){
        control_applyrecruit = applyrec;
        this->startInterface(memberlist,recruitlist, curID, curPW);
    }
    
    void startInterface(MemberList*, RecruitInfoList*, string*  , string*);
    void addRecruit(MemberList*, RecruitInfoList*,  string*, string*);
    
};


class Control_ApplyRecruit{
private:
    UI_ApplyRecruit* ui_applyrecruit;
public:
    void call_startInterface(MemberList* , RecruitInfoList*, string*, string*);
    void addRecruit(MemberList* memberlist, RecruitInfoList*, string* curID, string* curPW);
};



//===================3.2=================

class UI_ApplyRecruitInfo
{
private:
    Control_ApplyRecruitInfo* con;
public:
    void startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW);
    void showRecruitInfo(MemberList*, RecruitInfoList*, string*, string*);
};

class Control_ApplyRecruitInfo{
private:
    UI_ApplyRecruitInfo* ui_applyrecruitinfo;
public:
    void call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW);
    void showRecruitInfo(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW);
};


//====================4.1 채용 정보 검색=========================

class UI_RecruitInfoSearch{
    
public:
    void startInterface(MemberList* memberlist, RecruitInfoList* rec, string* curID, string* curPW);
    void search(MemberList* memberlist, RecruitInfoList* rec, string compName, string* curID, string* curPW);
};

class Control_RecruitInfoSearch {
private:
    UI_RecruitInfoSearch* ui_recruitinfosearch;
public:
    void call_startInterface(MemberList*, RecruitInfoList*, string*, string*);
    void search(MemberList* memberlist, RecruitInfoList* rec, string compName, string* curID, string* curPW);
};



//====================4.2 채용 지원==================================
class UI_Apply{
    
};

class Control_Apply
{
private:
    UI_Apply* ui_apply;
public:
    void startInterface(MemberList*, RecruitInfoList*, RecruitInfo*, string*, string*);
    void apply(MemberList* memberlist, RecruitInfoList* rec, RecruitInfo*, int businessNum, string* curID, string* curPW);
};





//====================4.3===================================
class UI_Application { // boundary
private:
    Control_Application* control_applicaion;
public:
    void startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW);
    UI_Application(Control_Application* Apply, MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW);
    void startApplication(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW);
};

class Control_Application { // control
private:
    UI_Application* ui_application;
    
public://memberList에서 recruitInfo를 바로 접근 가능한가?
    void call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW, int businessNumber);
    void showCancel(MemberList* memberlist, int businessNumber);
};


//==============================================
class UI_CancelApply { //아니 멀쩡하게 있구만...
private:
    Control_CancelApply* control_CancelApply;
public:
    UI_CancelApply(Control_CancelApply* Apply, MemberList* memberlist, RecruitInfoList * recruitlist, string* curID, string* curPW, int businessNumber);
    void startInterface(MemberList* member, RecruitInfoList* recruitlist, string* curID, string* curPW, int BusinessNumber);
    void startCancel(MemberList* memberlist, RecruitInfoList* recruitlist,string*curID,int businessNumber);
};

class Control_CancelApply {
private:
    UI_CancelApply* ui_cancelApply;
    
public://memberList에서 recruitInfo를 바로 접근 가능한가?
    void showCancel(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID,int businessNumber) ;
    void call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist,string*curID, string *curPW,int businessNumber);
    
};
//===========================================

class UI_Statistic {
private:
    Control_Statistic* control_statistic;
public:
    UI_Statistic(Control_Statistic* statistic, MemberList* member, RecruitInfoList* recruitlist, string* curID, string* curPW);//type number을 바로 접근 가능한가?
    void startInterface(MemberList* member, RecruitInfoList* recruitlist, string* curID, string* curPW);
    void startStatistic(MemberList* memberlist, string ID);
};



class Control_Statistic {
private:
    UI_Statistic* ui_statistic;
    
public:
    void call_startInterface(MemberList* memberlist, RecruitInfoList* recruitlist, string* curID, string* curPW);
    void getStat(MemberList* memberlist, string curID);
};




#endif /* boundary_h */
