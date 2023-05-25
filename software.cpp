#include "software.h"



using namespace std;

void doTask() {

    MemberList members;
    Member* pNewMember = NULL;

    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {

        cout << "1.1 회원 가입\n";
        cout << "1.2 회원 탈퇴\n";
        cout << "2.1 로그인\n";
        cout << "2.2 로그아웃\n";
        cout << "3.1 채용정보 등록\n";
        cout << "3.2 등록된 채용정보 좋회\n";
        cout << "4.1 채용 정보 검색\n";
        cout << "4.2 채용 지원\n";
        cout << "4.3 지원 정보 조회\n";
        cout << "5.1 지원 정보 통계\n";
        cout << "6.1 종료\n";

        cin >> menu_level_1;
        cin.ignore();
        cin >> menu_level_2;
        switch (menu_level_1) {
        case 1:
        {
            Register* control_Reg = new Register();
            switch (menu_level_2) {
            case 1: //1.1 회원가입, 1 hankook 3456 hk pwd1 /OR/ 2 98765 hn pwd2
            {

                control_Reg->startInterface();
                cout << "type 1 to register as a company member\ntype 2 to register as a User";
                int input = -1;
                cin >> input;
                if (input == 1) {

                    control_Reg->addAccount(members, input);

                    cin.ignore();

                }
                else {
                    control_Reg->addAccount(members, input);
                    cin.ignore();
                }
                members.showAll(); //왜 안 되냐??
                break;
            }
            case 2://1.2 회원 탈퇴
            {

                break;
            }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2) {
            case 1: //2.1 로그인, hk pwd1
            {

            }
            case 2: //2.2 로그아웃, hk
            {

            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2) {
            case 1: //3.1 채용 정보 등록
            {

            }
            case 2: //3.2 등록된 채용 정보 조회
            {

            }

            }
            break;
        }
        case 4:
        {
            switch (menu_level_2) {
            case 1: //4.1 채용 정보 검색
            {

            }
            case 2: //4.2 채용 지원
            {

            }
            case 3: //4.3 지원 정보 조회
            {
                Application* control_application = new Application();
                control_application->call_startInterface(&members);
            }
            case 4: //4.4 지원 취소
            {
                //fread어쩌구 읽으면(business Number 읽기)
                CancelApply* control_cancelApply = new CancelApply();
                control_cancelApply->call_startInterface(&members, businessNum);
            }

            }
            break;
        }
        case 5:
        {
            switch (menu_level_2) {
            case 1: // 5.1 지원 정보 통계
            {
                Statistic* control_statistic = new Statistic();
                control_statistic->call_startInterface(&members);
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2) {
            case 1: // 6.1 종료
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


void MemberList::addMember(Member* member) {
    memberList[numMembers++] = member;
}

void MemberList::deleteMember(string _name) {
    for (int i = 0; i < numMembers; i++) {
        if (memberList[i]->Names()) {
            memberList[i]->Names();
        }
    }
}

void MemberList::showAll() {
    for (int i = 0; i < numMembers; i++) {
        memberList[i]->show();
    }
}









void apply() {
    char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING], address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
    fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

    Application startApplication();
}
void statistic() {
    char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING], address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
    fscanf_s(in_fp, "%s %s %s %s", name, SSN, ID, password);

    StatisticUI startStatistic();

    fprintf_s(out_fp, "1.1. 회원가입\n"); fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}





























//MemberList가 Member객체로 바로 접근 가능했으면 좋겠음(Member 내에 있는 것들에 접근 가능하게?)
//근데 이걸 어찌 구현할지 모르겠습니다... 죄송합니다 바라는 것은 많고 할 줄은 몰라서...

void ApplicationUI::startInterface(MemberList* memberlist) {
    fprintf(out_fp, "5.1.지원 정보 통계\n");
    //신호를 전달
    ApplicationUI * ui_application = new ApplicationUI(this, memberlist);
}

ApplicationUI::ApplicationUI(Application* Apply, MemberList* memberlist) {
    Application* control_application = Apply;
    this->startInterface(memberlist);
}

void ApplicationUI::startApplication(MemberList*memberlist) {
    fprintf(out_fp, "4.3. 지원 정보 조회\n");
    Application * control_application -> showList(memberlist);
}




void Application::call_startInterface(MemberList*memberlist) {
    ui_application = new ApplicationUI(this, memberlist);
}

void Application::showList(MemberList* memberlist) {
    int i = 0;
    while (memberlist.recruitInfo[i]->getBusinessNumber() != NULL) {
        string *arr = memberlist.listApply(memberlist.recruitInfo, i);
        fprintf_s(out_fp, "%s, %s, %s, %s", arr[0], arr[1], arr[2], arr[3]);
        i++;
    }
}



string* User::listApply(RecruitInfo* recruitInfo[], int n) {
    string a, b, c,d;
    string apply[3] ;
    a = recruitInfo[n]->getCompanyName();
    b = recruitInfo[n]->getTask();
    c = recruitInfo[n]->getBusinessNumber();
    d = recruitInfo[n]->getDeadline();
    return apply;
    //fprintf_s(out_fp, "%s, %s, %d, %s", a,b,c,d);//이렇게 하고싶음!
}



//=================================================================



void CancelApplyUI::startInterface(MemberList* member, int businessNumber) {
    fprintf(out_fp, "4.4.지원 취소\n");
    //신호를 전달
    CancelApplyUI* ui_cancelApply = new CancelApplyUI(this, member, businessNumber);
}

CancelApplyUI::CancelApplyUI(CancelApply* Apply, MemberList* memberlist, int businessNumber) {
    CancelApply* control_CancelApply = Apply;
    this->startInterface(memberlist, businessNumber);
}

void CancelApplyUI::startCancel(MemberList* memberlist, int businessNumber) {
    CancelApply* control_cancelApply ->showCancel(memberlist, businessNumber); //이건 또 왜이럴까요...
}

void CancelApply::call_startInterface(MemberList* memberlist, int businessNumber) {
    ui_cancelApply = new CancelApplyUI(this, memberlist, businessNumber);
}

void CancelApply::showCancel(MemberList* memberlist, int businessNumber) {
    memberlist->cancelApply(memberlist, businessNumber);//대충 member객체 안에 있는 cancelApply 한다는 의미...
    string* cancel = memberlist->cancelApply(memberlist, businessNumber);
    fprintf_s(out_fp, "%s, %d, %s", cancel[0], cancel[1], cancel[2]);
}

string* User::cancelApply(MemberList* user, int businessNumber1) {
    int i = 0;
    int a = 0;//어디서부터 앞으로 당겨야 하는지... index 저장
    string cancel[2];
    while (user.getRecruitInfo(i+1) != NULL) {
        if (user.getRecruitInfo(i)->getBusinessNumber() == businessNumber1) {
            cancel[0] = user.getRecruitInfo(i)->getCompanyName();
            cancel[1] = user.getRecruitInfo(i)->getBusinessNumber();
            cancel[2] = user.getRecruitInfo(i)->getTask();
            //fprintf_s(out_fp, "%s, %d, %s", cancel[0], cancel[1], cancel[2]);
            a = i;
        }
        if (a < i) {
            user.recruitInfo[i] = user.getRecruitInfo(i + 1);
        }
        i++;
    }
    return cancel;
}


//=================================================================


void StatisticUI::startInterface(MemberList* member) {
    fprintf(out_fp, "5.1.지원 정보 통계\n");
    //신호를 전달
    StatisticUI* ui_statistic = new StatisticUI(this, member);
}

StatisticUI::StatisticUI(Statistic* statistic, MemberList* member) {
    control_statistic = statistic;
    this->startInterface(member);
}

void Statistic::call_startInterface(MemberList* memberlist) {
    StatisticUI* ui_statistic = new StatisticUI(this, memberlist);
}
void Statistic::getStat(MemberList* member) {//MemberList * memberlist와 member가 동일한가?
    int i = 0;
    if (member.getType() == 1) {
        User listStat(MemberList* member);
        //여기까지만 해도 됨!! 출력 어디에다 둬야할지 고민이라 그냥 냅뒀음
        while (member.getWorkNum(i) != NULL) {
            fprintf_s(out_fp, "%s %d", member.getWorkName(i), member.getWorkNum(i));
        }
        //이 윗부분은 옮길까 고민중!!
    }
    else {
        companyStaff listStat(MemberList* member);
        while (member.getWorkNum(i) != NULL) {
            fprintf_s(out_fp, "%s %d", member.getWorkName(i), member.getWorkNum(i));
        }
    }//그렇다면 바로 보내는 것과 동일한가?
}//신호를 다시 꺼내오는 것은 어떻게 하는가...?


void User::listStat(MemberList* member) {
    int num = 0;//개수 샐 곳
    int i, l = 0;
    while (member.getRecruitInfo(i) != NULL) {
        for (int j = 0; j <= i; j++) {
            if (member.getRecruitInfo(i)->getTask() == getWorkName(j)) {
                int a = getWorkNum(j);
                setWorkNum(j,a+1);
                continue;
            }//만약 이름이 이미 있으면 workNum에 개수 하나 올리고
            else {
                setWorkName(l,(member.getRecruitInfo(j)->getTask));
                setWorkNum(l);
                l++;
            }//아니면 업무 기록해준다
        }
        i++;
    }
    return;
}
void companyStaff::listStat(MemberList* member) {
    //위와 비슷하게 나올듯?
    int num = 0;//개수 샐 곳
    int i, l = 0;
    while (member.getRecruitInfo(i) != NULL) {
        for (int j = 0; j <= i; j++) {
            if (member.getRecruitInfo(i)->getTask() == getWorkName(j)) {
                int a = getWorkNum(j);
                int b = getRecruitInfo(i)->getApplyNumber();
                setWorkNum(j, a + b);
                continue;
            }//만약 이름이 이미 있으면 workNum에 개수 하나 올리고
            else {
                setWorkName(l, (member.getRecruitInfo(j)->getTask));
                setWorkNum(l);
                l++;
            }//아니면 업무 기록해준다
        }
        i++;
    }
    return;
}

