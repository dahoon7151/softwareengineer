#ifndef software_h
#define software_h

#include <iostream>

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


// ===== Memmber class
class Member{
private:
    string ID;
    int PW;
    
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




// ===== User class : Member
class User : Member //일반 회원
{
private:
    //ID
    //PWD 는 상속
    string memberName;
    int RegisterationNumber; //주민번호
    
    
public:
};


// =====companyStaff class : Member
class companyStaff : Member
{
private:
    //ID
    //PWD
    string companyName;
    int BusinessNumber;
    
public:
    
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
