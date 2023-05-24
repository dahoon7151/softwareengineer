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
#define MAX_COMPANY 100

using namespace std;
FILE* in_fp, *out_fp;

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
    string task;
    int applyNumber;
    int deadline;

public:

    void addNewRecruitInfo(const std::string& task, int applyNumber, int deadline);
    void showRecruitInfo(); //to do

    void editREcruitInfo(); // XXX
    void deleteRecruitInfo(); // XXX
    void expireRecruitInfo(); // XXX
    void sendMessage();
    void listStatComp();
    
};


// ===== Member class
class Member{
private:
    string ID;
    string PW;
    
public:
    virtual void saveInfo()=0;
    virtual void deleteInfo()=0;
    virtual bool checkID()=0;
    virtual void addApplicant()=0;
    virtual void listApply()=0;
    virtual void cancleApply()=0; // 회원 함수 : 지원을 취소
    virtual void deleteApply(); // 회원 함수 XXX :지원 했던 기록 삭제
    virtual void listStatUser()=0; //
};


// ===== User class : Member
class User : public Member //일반 회원
{
private:
    //ID
    //PWD 는 상속
    string memberName;
    int RegisterationNumber; //주민번호
    
public:
};


// =====companyStaff class : Member
class companyMember : public Member
{
private:
    //ID
    //PWD
    string companyName;
    int BusinessNumber;
public:
    
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
};

class RecruitInfoList
{
private:
    string task;
    int applyNumber;
    char deadline;
public:

};


// ===== RecruitInfo class
class RecruitInfo : Company
{
private:
    string CompanyName; // 1) 회사이름
    int BusinessNumber; // 2) 사업자 번호
    char task[MAX_COMPANY]; // 3) 업무
    int applyNumber; // 4) 인원수
    char deadline[MAX_COMPANY]; //5) 신청 마감일
    int taskApplied=0;
    
public:
    void getDetail(); //XXX (UI_showDetail, getDetail 삭제 해야함)
    void addApply(); // 즉시 지원( 외부_selectApply(), UI_apply(), addApply()

    void getRecruitInfoList(char* _task, int* _applyNumber, char* _deadline){
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
    void cancelApplyList();
    void getApply();
    void getCompList();
    void getTaskList();
    
};


class applyRecruit_InfoUI{
    private:
        
    public:
        void inputRecruitinfo();
        void startInterface();
};

class applyRecruit_Info{
    public:
        void addRecruitInfo(const std::string& task, int applyNumber, int deadline);
};

class Recruit_InfoUI{
    public:
        void startInterface();
};


RecruitInfo RecruitInfoList[50];

class Recruit_Info{
    private:

    public:
        char task[MAX_COMPANY]; 
        int applyNumber; 
        char deadline[MAX_COMPANY]; 
        void showRecruitInfo(RecruitInfo* RecruitInfoList[]);
};

#endif /* software_h */ 