#ifndef entity_h
#define entity_h

#include <iostream>
#include "boundary.h"

using namespace std;

/*
 ************************** Entity ********************************************************************************
 ************************** Entity ********************************************************************************
 ************************** Entity ********************************************************************************
 */

//======================== Member 관련
class Member
{
private:
    string ID = "";
    string PW = "";
    int serial;
    int type = -1; // 회사 = 1, 일반 = 0
    int state = -1; // 로그인 =1, 로그아웃 = 0
    
public:
    Member(int _type, int _serial, string _id, string _pw):type(_type), serial(_serial), ID(_id), PW(_pw){}
    
    //get 함수들
    
    string getID(){return ID;}
    string getPW(){return PW;}
    int getType(){return type;}
    int getState(){return state;}
    
};

class UserMember : public Member
{
private:
public:
    UserMember(int _type, int _serial, string _id, string _pw):Member(_type, _serial, _id, _pw){}
    
    string getIDList(){return getID();}
    string getPWList(){return getPW();}
    int getTypeList(){return getType();}
    int getStateList(){return getState();}
    
    
};

class CompanyMember : public Member
{
private:
    string companyName;
public:
    CompanyMember(int _type, string _compname, int _serial, string _id, string _pw):Member(_type, _serial, _id, _pw){
        companyName = _compname;
    }
    
    string getIDList(){return getID();}
    string getPWList(){return getPW();}
    int getTypeList(){return getType();}
    int getStateList(){return getState();}
    
};





//======================== RecruitInfo 관련

class RecruitInfo
{
private:
    string CompanyName;
    int BusinessNumber;
    string Task;
    int ApplyNumber;
    int Deadline;
    int TaskApplied = 0;
public:
    RecruitInfo(string _compname, int _bn, string _task, int _applynum, int _dl):CompanyName(_compname), BusinessNumber(_bn), Task(_task), ApplyNumber(_applynum), Deadline(_dl){}
    
    
    
};


/*
 ************************** Collections *************************************************************************
 ************************** Collections *************************************************************************
 ************************** Collections *************************************************************************
 */


class MemberList
{
private:
    Member* ownedMember[50];
    int numMembers = 0;
public:

    
};

class RecruitInfoList
{
private:
    RecruitInfo* ownedRecruitInfo[50];
    int numRecruit = 0;
public:
    
};



/*
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 ************************** boundary ********************************************************************************
 */


class Control;
class Control_Register;
class Control_DeleteAccount;
class Control_Login;
class Control_Logout;
class Control_ApplyRecruit;

class UI_Register;
class UI_Login;
class UI_DeleteAccount;
class UI_Logout;






class UI
{
private:
public:
};


//================= R E G I S T E R ====================
class UI_Register
{
private:
    Control_Register* control_register;
public:
    void startInterface();
    
};


//================= D E L E T E A C C O U N T ====================

class UI_DeleteAccount
{
private:
    Control_DeleteAccount* control_deleteaccount;
public:
    void startInterface();
    
};


//================= L O G I N ====================

class UI_Login
{
private:
    Control_Login* control_login;
public:
    void startInterface();
    
    
};

//================= L O G O U T ====================

class UI_Logout
{
private:
    Control_Logout* control_logout;
public:
    void startInterface();
    
};


//================= A P P L Y R E C ====================
class UI_ApplyRecruit
{
private:
    Control_ApplyRecruit* control_applyrec;
public:
    void startInterface();
    
};



/*
 ************************** Control ********************************************************************************
 ************************** Control ********************************************************************************
 ************************** Control ********************************************************************************
 ************************** Control ********************************************************************************
 ************************** Control ********************************************************************************
 ************************** Control ********************************************************************************
 ************************** Control ********************************************************************************
 ************************** Control ********************************************************************************
 ************************** Control ********************************************************************************
 */

class ControlList{
private:
    Control* controls[10];
    MemberList members;
public:
    void generateControl(int num);
};


//=================================== C O N T R O L ==================
class Control{
private:
public:
};


//=================================== R E G I S T E R ==================
class Control_Register : public Control
{
private:
    UI_Register* ui_register;
    ControlList* list;
public:
    Control_Register(ControlList* _list){
        ui_register = new UI_Register();
        ui_register->startInterface();
        list = _list;
    }
    
    void addAccount();
};


//=================================== D E L E T E A C C O U N T ==================
class Control_DeleteAccount : public Control
{
private:
    UI_DeleteAccount* ui_delaccount;
    ControlList* list;
public:
    Control_DeleteAccount(ControlList* _list){
        ui_delaccount = new UI_DeleteAccount();
        ui_delaccount->startInterface();
        list = _list;
    }
    
    void deleteAccount();
};

//=================================== L O G I N ==================
class Control_Login : public Control
{
private:
    UI_Login* ui_login;
    ControlList* list;
public:
    Control_Login(ControlList* _list){
        ui_login = new UI_Login();
        ui_login->startInterface();
        list = _list;
    }
    
    void logIn();
};


//=================================== L O G O U T ==================
class Control_Logout : public Control
{
private:
    UI_Logout* ui_logout;
    ControlList* list;
public:
    Control_Logout(ControlList* _list){
        ui_logout = new UI_Logout();
        ui_logout->startInterface();
        list = _list;
    }
    
    void logOut();
};



//=================================== A P P L Y R E C R U I T ==================
class Control_ApplyRecruit : public Control
{
private:
    UI_ApplyRecruit* ui_applyrec;
    ControlList* list;
public:
    Control_ApplyRecruit(ControlList* _list){
        ui_applyrec = new UI_ApplyRecruit();
        ui_applyrec->startInterface();
        list = _list;
    }
    
    void applyRecruit();
};













#endif /* entity_h */
