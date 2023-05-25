#ifndef software_h
#define software_h

#include <iostream>

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
} //�̰� ����� �𸣰���!!!!! ���� �̷� �� �������� ������ ���?

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
class User : Member //�Ϲ� ȸ��
{
private:
    //ID
    //PWD �� ���
    string memberName;
    int RegisterationNumber; //�ֹι�ȣ

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
	string CompanyName; // 1) ȸ���̸�
	int BusinessNumber; // 2) ����� ��ȣ
	string task; // 3) ����
	int applyNumber; // 4) �ο���
	string deadline; //5) ��û ������
	int taskApplied = 0;



public:
	void getDetail(); //XXX (UI_showDetail, getDetail ���� �ؾ���)
	void addApply(); // ��� ����( �ܺ�_selectApply(), UI_apply(), addApply()
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

public://memberList���� recruitInfo�� �ٷ� ���� �����Ѱ�?
	void call_startInterface(MemberList* memberlist);
	void showList(MemberList* memberlist);
};
//==============================================
class CancelApplyUI { //�ƴ� �����ϰ� �ֱ���...
private:
	CancelApply* control_CancelApply;
public:
	CancelApplyUI(CancelApply* cancelApply, MemberList* memberlist, int businessNumber);
	void startInterface(MemberList* memberlist, int businessNumber);//���� �ִµ�...
	void startCancel(MemberList* memberlist, int businessNumber);
};

class CancelApply {
private:
	CancelApplyUI* ui_cancelApply;

public://memberList���� recruitInfo�� �ٷ� ���� �����Ѱ�?
	void showCancel(MemberList* member, int businessNumber);
	void call_startInterface(MemberList* member, int businessNumber);

};
//===========================================
class StatisticUI {
private:
	Statistic* control_statistic;
public:
	StatisticUI(Statistic* statistic, MemberList* member);//type number�� �ٷ� ���� �����Ѱ�?
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