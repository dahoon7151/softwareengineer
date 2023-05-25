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

class MemberList {
private:
	Member* member[MAX_STRING];
};


// ===== Member class
class Member {
private:
    string ID;
    int PW;
	RecruitInfo *recruitInfo[MAX_STRING];
	int type = -1;

	int workNum[MAX_STRING];
	string workName[MAX_STRING];

public:
    virtual void saveInfo() = 0;
    virtual void deleteInfo() = 0;
    virtual bool checkID() = 0;
    virtual void addApplicant() = 0;

	virtual void listStat(Member member);
	int getType();
	RecruitInfo& getRecruitInfo(int i);
	string getWorkName(int i);
	int getWorkNum(int i);
	void setWorkName(int i, string name);
	void setWorkNum(int i, int number);
};


int Member::getType() {
	return type;
}

RecruitInfo& Member::getRecruitInfo(int i) {
	return *recruitInfo[i];
} //이거 방식을 모르겠음!!!!! 대충 이런 걸 가져오고 싶은데 어떻게?

string Member::getWorkName(int i) {
	return workName[i];
}
int Member::getWorkNum(int i) {
	return workNum[i];
}
void Member::setWorkName(int i, string name) {
	workName[i] = name;
}
void Member::setWorkNum(int i, int number = 0) {
	workNum[i] = number;
}




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
	string* listApply(RecruitInfo* recruitInfo[], int n);
	
	string* cancelApply(MemberList* user, int businessNumber1);
	
	void listStat(MemberList* member);
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
	void listStat(MemberList* member);
};



// ===== RecruitInfo class
class RecruitInfo : Company
{
private:
	string CompanyName; // 1) 회사이름
	int BusinessNumber; // 2) 사업자 번호
	string task; // 3) 업무
	int applyNumber; // 4) 인원수
	string deadline; //5) 신청 마감일
	int taskApplied = 0;



public:
	void getDetail(); //XXX (UI_showDetail, getDetail 삭제 해야함)
	void addApply(); // 즉시 지원( 외부_selectApply(), UI_apply(), addApply()
	void getRecruitInfoList();
	void editRecruitInfoList(); //XXX
	void deleteRecruitInfoList(); //XXX
	void checkAppNum();
	void deleteApplyList(); // XXX
	void getCompList();
	void getTaskList();

	string getTask();
	int getBusinessNumber();
	int getApplyNumber();
	string getCompanyName();
	string getDeadline();
	void getApply(RecruitInfo* recruitInfo[]);
	void cancelApplyList(RecruitInfo* recruitInfo[], string name, int number, string work);
	int getApplyNumber();
};

int RecruitInfo::getApplyNumber() {
	return applyNumber;
}

string RecruitInfo::getTask() {
	return task;
}
int RecruitInfo::getBusinessNumber() {
	return BusinessNumber;
}
int RecruitInfo::getApplyNumber() {
	return applyNumber;
}
string RecruitInfo::getCompanyName() {
	return CompanyName;
}
string RecruitInfo::getDeadline() {
	return deadline;
}




















class ApplicationUI { // boundary
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











#endif /* software_h */