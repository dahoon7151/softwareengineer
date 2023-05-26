#ifndef software_h
#define software_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


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
class UserMember;
class CompanyMember;


// ===== Memmber class
class Member{
private:
    string ID;
    string PW;
    string Name="";
    int number;
    int type = -1; //회사 = 1, 일반 = 0
    int state = -1; // 로그인 = 1
    
public:
    Member(int _t, string _id, string _pw):ID(_id), PW(_pw), type(1){}
    
    void setID(string _ID){ID = _ID;}
    void setPW(string _PW){PW = _PW;}
    void setType(int type);
    void setState(int _state);
    string GETNAME(){return Name;}
    void setName(string name){Name = name;}
    void setNumber(int num){number = num;}
    
    int getNumber(){return number;}
    
    
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
    int getState(){return state;}
    
    virtual UserMember* getUserMember()=0;


};



// ===== User class : Member
class UserMember : public Member //일반 회원
{
private:
    //ID
    //PWD 는 상속
    //int RegisterationNumber; //주민번호
    RecruitInfo* AppliedList[10];
    int appliedNum = 0;
    
public:
    UserMember(int type, int _serial,  string _ID, string _PW):Member(type, _ID, _PW){
        setNumber(_serial);
    }
    virtual void saveInfo(){};
    virtual void deleteInfo(){}
    virtual bool checkID(){return true;}
    virtual void addApplicant(){}
    virtual void listApply(){}
    virtual void cancleApply(){}// 회원 함수 : 지원을 취소
    virtual void listStatUser(){} //
    virtual int Names(){return 0;}
    //virtual string getName(){return name;}
    virtual int getNumber(){return Member::getNumber();}
    
    void sortList();
    string getCompname(int index);
    string getTask(int index);
    int getHeads(int index);
    int getDeadline(int index);
    int getAppliedNum(){return appliedNum;}
    virtual UserMember* getUserMember(){return this;}

    void showAllApplied();
    void Apply(RecruitInfo* rec);
    RecruitInfo* getAppliedList(int index){return AppliedList[index];}

    void setAppliedNum(int num){appliedNum = num;}
    
    string* listApply(RecruitInfo* recruitInfo[], int n);
    string* cancelApply(MemberList* user, int businessNumber1);
    
    void listStat(MemberList* member);

};



/*
// ===== RecruitInfo class
class RecruitInfo
{
private:
    string CompanyName; // 1) 회사이름
    int BusinessNumber; // 2) 사업자 번호
    string task; // 3) 업무
    int applyNumber; // 4) 인원수
    int deadline; //5) 신청 마감일
    int taskApplied;
    
public:
    RecruitInfo(string _compname, int _Bn, string _task, int _applynum, int _deadline):taskApplied(0){
        CompanyName = _compname;
        BusinessNumber = _Bn;
        task = _task;
        applyNumber = _applynum;
        deadline = _deadline;
    }
    //void getDetail(); //XXX (UI_showDetail, getDetail 삭제 해야함)
    //void addApply(); // 즉시 지원( 외부_selectApply(), UI_apply(), addApply()
    //void getRecruitInfoList();
    //void editRecruitInfoList(); //XXX
    //void deleteRecruitInfoList(); //XXX
    //void checkAppNum();
    //void deleteApplyList(); // XXX
    //void getApply();
    //void getCompList();
    //void getTaskList();
    
    //=======김다빈================
 
     string getTask();
     int getBusinessNumber();
     string getCompanyName();
     string getDeadline();
     void cancelApplyList(int a, int b);
     int getApplyNumber();
 
};
*/




class RecruitInfo
{
private:
    string CompanyName; // 1) 회사이름
    int BusinessNumber; // 2) 사업자 번호
    string task; // 3) 업무
    int applyNumber; // 4) 인원수
    int deadline; //5) 신청 마감일
    int taskApplied;
 
    
public:
    RecruitInfo(){taskApplied = 0;}
    RecruitInfo(string compname, int bn, string _task, int an, int _deadline){
        CompanyName = compname;
        BusinessNumber = bn;
        task = _task;
        applyNumber = an;
        deadline = _deadline;
        taskApplied = 0;
    }
    
    string getCompName();
    string getTask();
    int getHeads();
    int getDeadline();
    int getBusinessNumber();

};




// =====companyStaff class : Member
class CompanyMember : public Member
{
private:
    //ID
    //PWD
    //string companyName;
    //int BusinessNumber;
    RecruitInfo lists[50];
    
public:
    CompanyMember():Member(0, " ", " "){}
    CompanyMember(int _type, string _companyName, int _businessNum, string _ID, string _PW):Member(_type, _ID, _PW){
        //this->companyName = _companyName;
        //this->BusinessNumber = _businessNum;
        setName(_companyName);
        setNumber(_businessNum);
    }
    
    virtual void saveInfo(){}
    virtual void deleteInfo(){}
    virtual bool checkID(){return true;}
    virtual void addApplicant(){}
    virtual void listApply(){}
    virtual void cancleApply(){}// 회원 함수 : 지원을 취소
    virtual void listStatUser(){} //
    virtual int Names(){
        cout << getName();
        return 1;
    }
     
     
    virtual string getName(){return Member::getName();}
    virtual int getNumber(){return Member::getNumber();}
    virtual UserMember* getUserMember(){
        UserMember* user = new UserMember(1, 2, "1", "3");
        return user;
    }
    
    string getID(){return Member::getID();}
    string getPW(){return Member::getPW();}
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
    
    void setNumMembers(int num);
    UserMember* getMember(int index);
    string getCompName(int index);
    
};







class RecruitInfoList
{
private:
    RecruitInfo* recruitlist[50];
    int numRecruitInfo;
    
public:
    RecruitInfoList():numRecruitInfo(0){}
    void addRecruitInfo(RecruitInfo* recruitinfo);
    void show(string compname);
    
    string getCompName(int index);
    
};














#endif /* software_h */
