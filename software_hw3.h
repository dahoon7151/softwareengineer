#ifndef software_h
#define software_h

#include <iostream>
#include <vector>

// **************************************************************************
// **************************************************************************
// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#define MAX_COMPANY 100

using namespace std;

FILE* in_fp, * out_fp;


// **************************************************************************
// **************************************************************************
// 함수 선언
void doTask();
void join();
void program_exit();


// **************************************************************************
// **************************************************************************
// 클래스 선언
class State{

};

// ===== Member class
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
    string task;
    int applyNumber;
    int deadline;

public:

    void addNewRecruitInfo(const std::string& task, int applyNumber, int deadline){ 
      this->task = task;
      this->applyNumber = applyNumber;
      this->deadline = deadline;
    };

    void Company::showRecruitInfo(){
        // 이 함수가 필요한지 모르겠다 getRecruitInfoList() 함수로 한번에 받아와서 조회 기능 구현하면 될 것 같은데..?
    };


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
    char task; // 3) 업무
    int applyNumber; // 4) 인원수
    int deadline; //5) 신청 마감일
    int taskApplied=0;
    
public:
    void getDetail(); //XXX (UI_showDetail, getDetail 삭제 해야함)
    void addApply(); // 즉시 지원( 외부_selectApply(), UI_apply(), addApply()

    void getRecruitInfoList(){
        int i = 0;
    // Company class 
    // 배열 형태로
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


class applyRecruitInfoUI{
public:
    string task;
    int applyNumber;
    int deadline;
    
    void inputRecruitinfo(){
        fscanf(in_fp, "%s %d %d", task, &applyNumber, &deadline);
    }

    void startInterface(){
        fprintf(out_fp, "3.1. 채용 정보 등록\n");
        fprintf(out_fp, "> %s %d %d\n", task, applyNumber, deadline);
    }
};

class applyRecruitInfo{
    public:
        void addRecruitInfo(){
            Company company;
            std::string task;
            int applyNum;
            int deadline;

            company.addNewRecruitInfo(task, applyNum, deadline);
    }
};

class RecruitInfoUI{
public:
    string task[MAX_COMPANY];
    int applyNumber[MAX_COMPANY];
    int deadline[MAX_COMPANY];
    void startInterface(int num){
        fprintf(out_fp, "3.2. 등록된 채용 정보 조회\n");
        for(int i = 0; i < num; i++){
            fprintf(out_fp, "> { %s %d %d }\n", task[i], applyNumber[i], deadline[i]);
        }
    }
};

class RecruitInfo{
public:
    // 지원정보 조회 형태랑 비슷하게 짜면 될 것 같은데 화살표가 없다 how??
};

#endif /* software_h */