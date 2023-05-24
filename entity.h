#ifndef software_h
#define software_h

#include <iostream>
#include <fstream>
#include <sstream>


// **************************************************************************
// **************************************************************************
// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


// **************************************************************************
// **************************************************************************
// 함수 선언
void doTask();
void join();
void program_exit();


// **************************************************************************
// **************************************************************************
// 클래스 선언




// ===== Company class
class Company
{
private:
    string CompanyName;
    
public:
    void addNewRecruitInfo();
    void showRecruitInfo();
    void editREcruitInfo(); // XXX
    void deleteRecruitInfo(); // XXX
    void expireRecruitInfo(); // XXX
    void sendMessage();
    void listStatComp();
    
};



// ===== Memmber class
class Member{
private:
    string ID;
    string PW;
    int type = -1; //회사 = 1, 일반 = 0
    int state = -1; // 로그인 = 1
    
public:
    void setID(string _ID){ID = _ID;}
    void setPW(string _PW){PW = _PW;}
    void setType(int type);
    void setState(int _state);

    
    virtual void saveInfo() = 0;
    virtual void deleteInfo()= 0;
    virtual bool checkID()= 0;
    virtual void addApplicant()= 0;
    virtual void listApply()= 0;
    virtual void cancleApply()= 0; // 회원 함수 : 지원을 취소
    virtual void listStatUser()= 0; //
    virtual int Names() = 0;
    void show();
    string getID(){return ID;}
    string getPW(){return PW;}
    int getState(){return state;}
};



// ===== User class : Member
class UserMember : public Member //일반 회원
{
private:
    //ID
    //PWD 는 상속
    string memberName;
    int RegisterationNumber; //주민번호
    
    
public:
    UserMember(int type, int _serial,  string _ID, string _PW){
        setID(_ID);
        setPW(_PW);
        setType(type);
        this->RegisterationNumber = _serial;
    }
    virtual void saveInfo(){};
    virtual void deleteInfo(){};
    virtual bool checkID(){return true;};
    virtual void addApplicant(){};
    virtual void listApply(){};
    virtual void cancleApply(){}; // 회원 함수 : 지원을 취소
    virtual void listStatUser(){}; //
    virtual int Names(){return 0;}

    
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
    CompanyMember(int type, string _companyName, int _businessNum, string _ID, string _PW){
        setID(_ID);
        setPW(_PW);
        setType(type);
        this->companyName = _companyName;
        this->BusinessNumber = _businessNum;
    }
    virtual void saveInfo(){};
    virtual void deleteInfo(){};
    virtual bool checkID(){return true;};
    virtual void addApplicant(){};
    virtual void listApply(){};
    virtual void cancleApply(){}; // 회원 함수 : 지원을 취소
    virtual void listStatUser(){}; //
    virtual int Names(){
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
    MemberList():numMembers(0){};
    void addMember(Member* member);
    void deleteMember(string _name);
    void showAll();
    int getnumber(){return numMembers;}
    int checkIDlist(string, string);
    void setState(int _state, int index);
    int getState(int index);

};



// ===== RecruitInfo class
class RecruitInfo : Company
{
private:
    string CompanyName; // 1) 회사이름
    int BusinessNumber; // 2) 사업자 번호
    string task; // 3) 업무
    int applyNumber; // 4) 인원수
    int deadline; //5) 신청 마감일
    int taskApplied=0;
    
public:
    void getDetail(); //XXX (UI_showDetail, getDetail 삭제 해야함)
    void addApply(); // 즉시 지원( 외부_selectApply(), UI_apply(), addApply()
    void getRecruitInfoList();
    void editRecruitInfoList(); //XXX
    void deleteRecruitInfoList(); //XXX
    void checkAppNum();
    void getStatistic();
    void deleteApplyList(); // XXX
    void cacelApplyList();
    void getApply();
    void getCompList();
    void getTaskList();
    
};











#endif /* software_h */
