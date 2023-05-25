#include "software.h"



using namespace std;

void doTask() {

    MemberList members;
    Member* pNewMember = NULL;

    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {

        cout << "1.1 ȸ�� ����\n";
        cout << "1.2 ȸ�� Ż��\n";
        cout << "2.1 �α���\n";
        cout << "2.2 �α׾ƿ�\n";
        cout << "3.1 ä������ ���\n";
        cout << "3.2 ��ϵ� ä������ ��ȸ\n";
        cout << "4.1 ä�� ���� �˻�\n";
        cout << "4.2 ä�� ����\n";
        cout << "4.3 ���� ���� ��ȸ\n";
        cout << "5.1 ���� ���� ���\n";
        cout << "6.1 ����\n";

        cin >> menu_level_1;
        cin.ignore();
        cin >> menu_level_2;
        switch (menu_level_1) {
        case 1:
        {
            RegisterControl* control_Reg = new RegisterControl();
            switch (menu_level_2) {
            case 1: //1.1 ȸ������, 1 hankook 3456 hk pwd1 /OR/ 2 98765 hn pwd2
            {

                control_Reg->call_startInterface(&members);
                members.showAll(); //�� �� �ǳ�??
                break;
            }
            case 2://1.2 ȸ�� Ż��
            {

                break;
            }
            }
            break;
        }
        case 2:
        {
            LoginControl* control_log = new LoginControl();
            switch (menu_level_2) {
            case 1: //2.1 �α���, hk pwd1
            {
                control_log->call_startInterface(&members);
                break;
            }
            case 2: //2.2 �α׾ƿ�, hk
            {

            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2) {
            case 1: //3.1 ä�� ���� ���
            {

            }
            case 2: //3.2 ��ϵ� ä�� ���� ��ȸ
            {

            }

            }
            break;
        }
        case 4:
        {
            switch (menu_level_2) {
            case 1: //4.1 ä�� ���� �˻�
            {
                RecruitInfoSearch r41;
                r41.showList();
                break;
            }
            case 2: //4.2 ä�� ����
            {

            }
            case 3: //4.3 ���� ���� ��ȸ
            {

            }
            case 4: //4.4 ���� ���
            {

            }

            }
            break;
        }
        case 5:
        {
            switch (menu_level_2) {
            case 1: // 5.1 ���� ���� ���
            {

            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2) {
            case 1: // 6.1 ����
            {
                program_exit();
                is_program_exit = 1;
                break;

            }
            }
            break;
        }
        }
    }
}




// join()
void join() {

}


void program_exit() {
    cout << "sibal";
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************



//============================ Member Entity ���� �Լ� ============================
// Member :: setType()
void Member::setType(int type)
{
    if (type == 1) type = 1; //ȸ�� ȸ��
    else type = 0; //�Ϲ� ȸ��
}



// Member :: setState
void Member::setState(int _state) {
    if (_state == 1) {
        state = 1;
    }
    else if (_state == 0) {
        state = 0;
    }
    else {}
}


// <<<<<<<<<<<<<<<<<<<<< FOR DEBUGGING >>>>>>>>>>>>>>>>>>>>>>>>
// Member :: show()
void Member::show() {
    cout << "\nID: " << ID << "\n" << "PW: " << PW << "\n\n" << endl;
}








//============================ MemberList ���� �Լ� ============================

//MemberList :: addMember
void MemberList::addMember(Member* member) { //�̰� �����ͷ� �����ϱ� �Ǽ�!!
    memberList[numMembers++] = member;
}


//MemberList :: deleteMember
void MemberList::deleteMember(string _name) {
    for (int i = 0; i < numMembers; i++) {
        if (memberList[i]->Names()) {
            memberList[i]->Names();
        }
    }
}


//MemberList :: checkIDlist
int MemberList::checkIDlist(string id, string pw) {
    for (int i = 0; i < this->getnumber(); i++) {
        if (memberList[i]->getID() == id) {
            if (memberList[i]->getPW() == pw) {
                //cout << "�α��� ����";
                return i; //�ε����� ��ȯ
            }
        }
    }
    return -1;
}


//MemberList :: setState
void MemberList::setState(int _state, int index) {
    memberList[index]->setState(_state);
}


//MemberList :: getState
int MemberList::getState(int index) {
    return memberList[index]->getState(); // �α��� ���� ��ȯ
}




// <<<<<<<<<<<<<<<<<<<<< FOR DEBUGGING >>>>>>>>>>>>>>>>>>>>>>>>
//MemberList :: showAll()
void MemberList::showAll() {
    for (int i = 0; i < numMembers; i++) {
        memberList[i]->show();
    }
}
/*
 ############################################### // UI // ########################################################################
 ############################################### // UI // ########################################################################
 ############################################### // UI // ########################################################################
 */

 //=====================// RegisterUI //====================
 //=====================// RegisterUI //====================

 //RegisterUI :: startInterface
void RegisterUI::startInterface(MemberList* memberlist) {
    cout << "type 1 to register as a company member\ntype 2 to register as a user\n";
    int input = -1;
    cin >> input;

    this->addAccount(memberlist, input);

}

//RegisteraUI :: addAccount
void RegisterUI::addAccount(MemberList* memberlist, int type) {
    control_register->createAccount(memberlist, type); // UI���� ��Ʈ�� �Լ� ����
}


//=====================// LoginUI //====================
//=====================// LoginUI //====================
void LoginUI::startInterface(MemberList* memberlist) {
    cout << "Log-in UI\n";

    this->LogIn(memberlist);
}

void LoginUI::LogIn(MemberList* memberlist) {
    control_login->Login(memberlist); //UI�� control �Լ� ȣ�� // (UI startInterface() -> UI LogIn() -> control Login())
}


/*
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 ############################################### // CONTROL // ########################################################################
 */


 //=====================// RegisterControl //====================
 //=====================// RegisterControl //====================


 //RegisterControl :: call_startInterface()
void RegisterControl::call_startInterface(MemberList* memberlist) {
    ui_register = new RegisterUI(this, memberlist); // Control���� UI ������ ȣ��
}


//RegisterControl :: createAccount
void RegisterControl::createAccount(MemberList* memberlist, int type) {
    Member* mem;
    if (type == 1) {  //ȸ��ȸ��
        string name, id, pw;
        int serial_number;

        cout << "ȸ��� ��� ���̵� ���\n";
        cin >> name >> serial_number >> id >> pw;
        mem = new CompanyMember(type, name, serial_number, id, pw);
        memberlist->addMember(mem); // Control ���� entity �Լ� ����

    }
    else if (type == 0) { //�Ϲ�ȸ��
        string id, pw;
        int serial_number;
        cout << "�ֹι�ȣ ���̵� ���\n";
        cin >> serial_number >> id >> pw;

        mem = new UserMember(type, serial_number, id, pw);
        memberlist->addMember(mem); // Control ���� entity �Լ� ����
    }
}



//=====================// LoginControl //====================
//=====================// LoginControl //====================


//LoginControl :: startInterface
void LoginControl::call_startInterface(MemberList* memberlist) {
    ui_login = new LoginUI(this, memberlist);
}

//LoginControl :: Login
void LoginControl::Login(MemberList* memberlist) {
    cout << "id pw �Է�\n";
    string id, pw;

    cin.ignore();
    cin >> id >> pw;
    cout << "���� �Է��� �� : " << id << " " << pw << endl;

    if (memberlist->checkIDlist(id, pw) >= 0) {
        cout << "�α��� ����\n\n";
        memberlist->setState(1, memberlist->checkIDlist(id, pw)); //type = 1�̸� �α��� ����

    }
    else if (memberlist->checkIDlist(id, pw) == -1) {
        cout << "�׷� �� ����\n";
    }



}

void Company::addNewRecruitInfo(char* _task, int* _applyNumber, char* _deadline) {
        this->task = _task;
        this->applyNumber = _applyNumber;
        this->deadline = _deadline;
}


void Company::showRecruitInfo() { 
}


void applyRecruit_InfoUI::inputRecruitinfo() {
    string task;
    int applyNumber;
    int deadline;
    fscanf(in_fp, "%s %d %d", task, &applyNumber, &deadline);
};

void applyRecruit_InfoUI::startInterface() {
    fprintf(out_fp, "3.1. ä�� ���� ���\n");
}

void applyRecruit_Info::addRecruitInfo(const std::string& task, int applyNumber, int deadline) {
    applyRecruit_Info applyrecruitinfo;
    applyrecruitinfo.addRecruitInfo(task, applyNumber, deadline);
}

RecruitInfo RecruitInfoList[50];

void Recruit_InfoUI::startInterface() {
    fprintf(out_fp, "3.2. ��ϵ� ä�� ���� ��ȸ\n");
}

void Recruit_Info::showRecruitInfo(RecruitInfo* RecruitInfoList[]) {
    for (int i = 0; i < 50; i++) {
        if (RecruitInfoList[i] != NULL) {
            RecruitInfoList[i]->getRecruitInfoList(task, &applyNumber, deadline);
        }
    }
}

int Member::getType() {
    return type;
}

RecruitInfo Member::getRecruitInfo(int i) {
    return recruitInfo[i];
}
string Member::getWorkName(int i) {
    return workName[i];
}
int Member::getWorkNum(int i) {
    return workNum[i];
}
void Member::setWorkName(int i, string name) {
    workName[i] = name;
}
void Member::setWorkNum(int i, int number = 1) {
    workNum[i] = number;
}