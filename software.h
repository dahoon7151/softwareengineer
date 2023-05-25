#ifndef software_h
#define software_h

#include <iostream>
#include <fstream>
#include <sstream>

FILE* in_fp, * out_fp;

// **************************************************************************
// **************************************************************************
// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


// **************************************************************************
// **************************************************************************
// �Լ� ����
void doTask();
void join();
void program_exit();


// **************************************************************************
// **************************************************************************
// Ŭ���� ����




// ===== Company class
class Company
{
private:
    string CompanyName;
public:

    void addNewRecruitInfo(char* _task, int* _applyNumber, char* _deadline){

    };
    void showRecruitInfo(); 

    void editREcruitInfo(); // XXX
    void deleteRecruitInfo(); // XXX
    void expireRecruitInfo(); // XXX
    void sendMessage();
    void listStatComp();
    
};



// ===== Memmber class
class Member {
private:
    string ID;
    string PW;
    RecruitInfo* recruitInfo[MAX_STRING];
    int type = -1; //ȸ�� = 1, �Ϲ� = 0
    int state = -1; // �α��� = 1

    int workNum[MAX_STRING];
    string workName[MAX_STRING];

public:
    void setID(string _ID) { ID = _ID; }
    void setPW(string _PW) { PW = _PW; }
    void setType(int type);
    void setState(int _state);


    virtual void saveInfo() = 0;
    virtual void deleteInfo() = 0;
    virtual bool checkID() = 0;
    virtual void addApplicant() = 0;
    virtual int Names() = 0;
    void show();
    string getID() { return ID; }
    string getPW() { return PW; }
    int getState() { return state; }

    virtual void listStat(Member member);
    int getType();
    RecruitInfo getRecruitInfo(int i);
    string getWorkName(int i);
    int getWorkNum(int i);
    void setWorkName(int i, string name);
    void setWorkNum(int i, int number);
};



// ===== User class : Member
class UserMember : public Member //�Ϲ� ȸ��
{
private:
    //ID
    //PWD �� ���
    string memberName;
    int RegisterationNumber; //�ֹι�ȣ


public:
    void listApply(RecruitInfo* recruitInfo[], int n);

    void cancelApply(User user, int businessNumber1); // ȸ�� �Լ� : ������ ���

    void listStat(Member member);

    UserMember(int type, int _serial, string _ID, string _PW) {
        setID(_ID);
        setPW(_PW);
        setType(type);
        this->RegisterationNumber = _serial;
    }
    virtual void saveInfo() {};
    virtual void deleteInfo() {};
    virtual bool checkID() { return true; };
    virtual void addApplicant() {};
    virtual void listApply() {};
    virtual void cancleApply() {}; // ȸ�� �Լ� : ������ ���
    virtual void listStatUser() {}; //
    virtual int Names() { return 0; }


};


// =====companyStaff class : Member
class CompanyMember : public Member
{
private:
    //ID
    //PWD
    string companyName;
    int BusinessNumber;

public:
    CompanyMember(int type, string _companyName, int _businessNum, string _ID, string _PW) {
        setID(_ID);
        setPW(_PW);
        setType(type);
        this->companyName = _companyName;
        this->BusinessNumber = _businessNum;
    }
    virtual void saveInfo() {};
    virtual void deleteInfo() {};
    virtual bool checkID() { return true; };
    virtual void addApplicant() {};
    virtual void listApply() {};
    virtual void cancleApply() {}; // ȸ�� �Լ� : ������ ���
    virtual void listStatUser() {}; //
    virtual int Names() {
        cout << this->companyName;
        return 1;
    }

};


// ===== MemberList class
class MemberList
{
private:
    Member* memberList[50];
    int numMembers;

public:
    MemberList() :numMembers(0) {};
    void addMember(Member* member);
    void deleteMember(string _name);
    void showAll();
    int getnumber() { return numMembers; }
    int checkIDlist(string, string);
    void setState(int _state, int index);
    int getState(int index);

};



// ===== RecruitInfo class
class RecruitInfo : Company
{
private:
    char CompanyName[MAX_STRING]; // 1) ȸ���̸�
    int BusinessNumber; // 2) ����� ��ȣ
    char task[MAX_STRING]; // 3) ����
    int applyNumber; // 4) �ο���
    char deadline[MAX_STRING]; //5) ��û ������                     //�ڷ��� �ٲ�
    int taskApplied = 0;

public:
    void getDetail(); //XXX (UI_showDetail, getDetail ���� �ؾ���)
    void addApply(); // ��� ����( �ܺ�_selectApply(), UI_apply(), addApply()

    void getRecruitInfoList(char* _task, int* _applyNumber, char* _deadline) {
        strcpy(_task, task);
        *_applyNumber = applyNumber;
        strcpy(_deadline, deadline);

        fprintf(out_fp, "> %s %d %s\n", task, applyNumber, deadline);
    };
    void editRecruitInfoList(); //XXX
    void deleteRecruitInfoList(); //XXX
    void checkAppNum();
    void getStatistic();
    void deleteApplyList(); // XXX
    void cacelApplyList();
    void getApply();
    void getCompList(char* _CompanyName) {
        if (CompanyName == _CompanyName)
        {
            fprintf_s(out_fp, "> %s %d %s %d %s\n", CompanyName, BusinessNumber, task, applyNumber, deadline);
        }
    }
    void getTaskList();  //XXX

};

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
    RegisterUI(RegisterControl* Reg, MemberList* memberlist) {
        cout << "UI �����Ϸ�\n";
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
    LoginUI(LoginControl* Log, MemberList* memberlist) {
        cout << "UI �����Ϸ�\n";
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

class applyRecruit_InfoUI {
private:

public:
    void inputRecruitinfo();
    void startInterface();
};

class applyRecruit_Info {
public:
    char task[MAX_STRING];
    int applyNumber;
    char deadline[MAX_STRING];
    void addRecruitInfo();
};

class Recruit_InfoUI {
public:
    void startInterface();
};


RecruitInfo RecruitInfoList[50];

class Recruit_Info {
private:

public:
    char task[MAX_STRING];
    int applyNumber;
    char deadline[MAX_STRING];
    void showRecruitInfo(RecruitInfo* RecruitInfoList[]);
};



//============================== ���� ==============================////
RecruitInfo RecruitInfoList[50];

class RecruitInfoSearchUI
{
public:
    char CompanyName[MAX_STRING];

    void startInterface()
    {
        fprintf_s(out_fp, "4.1. ä�� ���� �˻�\n");
    }
    void searchCompName()     //search()�� ����
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

        for (int i = 0; i < 50; i++)
        {
            RecruitInfoList[i].getCompList(recruitinfosearchui.CompanyName);
        }
    }
};

class ApplyUI              ////////�̰� �ʿ��Ѱǰ�? startinterface�Լ� �ʿ��Ѱ�?
{
public:
    void startInterface()
    {
        fprintf_s(out_fp, "4.2. ä�� ����\n");
    }
};

class Apply
{
    void apply()
    {
        ApplyUI applyui;
        applyui.startInterface();
    }
};




#endif /* software_h */#pragma once
