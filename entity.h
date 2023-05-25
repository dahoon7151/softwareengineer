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


class RecruitInfo;
class MemberList;


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
    virtual string getName()=0;
    virtual int getNumber()=0;
    int getState(){return state;}
};



// ===== User class : Member
class UserMember : public Member //일반 회원
{
private:
    //ID
    //PWD 는 상속
    string name;
    int RegisterationNumber; //주민번호
    RecruitInfo* AppliedList[10];
    int appliedNum = 0;
    
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
    virtual string getName(){return name;}
    virtual int getNumber(){return RegisterationNumber;}
    
    
    string* listApply(RecruitInfo* recruitInfo[], int n);
    string* cancelApply(MemberList* user, int businessNumber1);
    
    void listStat(MemberList* member);

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
    virtual string getName(){return companyName;}
    virtual int getNumber(){return BusinessNumber;}
    
};


// ===== RecruitInfo class
class RecruitInfo
{
private:
    string CompanyName; // 1) 회사이름
    int BusinessNumber; // 2) 사업자 번호
    string task; // 3) 업무
    int applyNumber; // 4) 인원수
    int deadline; //5) 신청 마감일
    int taskApplied=0;
    
public:
    RecruitInfo(string _compname, int _Bn, string _task, int _applynum, int _deadline):taskApplied(0){
        CompanyName = _compname;
        BusinessNumber = _Bn;
        task = _task;
        applyNumber = _applynum;
        deadline = _deadline;
    }
    void getDetail(); //XXX (UI_showDetail, getDetail 삭제 해야함)
    void addApply(); // 즉시 지원( 외부_selectApply(), UI_apply(), addApply()
    void getRecruitInfoList();
    void editRecruitInfoList(); //XXX
    void deleteRecruitInfoList(); //XXX
    void checkAppNum();
    void deleteApplyList(); // XXX
    void getApply();
    void getCompList();
    void getTaskList();
    
    //=======김다빈================
    string getTask();
    int getBusinessNumber();
    string getCompanyName();
    string getDeadline();
    void cancelApplyList(int a, int b);
    int getApplyNumber();
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
    
    Member* getMember(int index);
    void setNumMembers(int num);
};







class RecruitInfoList
{
private:
    RecruitInfo* recruitlist[50];
    int numRecruitInfo;
    
public:
    RecruitInfoList():numRecruitInfo(0){}
    void addRecruitInfo(RecruitInfo* recruitinfo);
    
};














#endif /* software_h */
