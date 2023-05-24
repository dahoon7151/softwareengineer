#include "software_hw3.h"

// 1. 함수 및 요소 파악
// 2. software_hw3.h 상위 class 포함된 함수 짜기
// 3. boundary contorol class 및 함수 짜기


void doTask(){
    int menu_level_1 = 0, menu_level_2=0;
    int is_program_exit = 0;
    
    while(!is_program_exit){
        
        switch(menu_level_1){
            case 1:
            {
                switch(menu_level_2){
                    case 1: //1.1 회원가입, 1 hankook 3456 hk pwd1 OR 2 98765 hn pwd2
                    {
                        join();
                        break;
                    }
                    case 2://1.2 회원 탈퇴
                    {
                        
                        break;
                    }
                }
            }
            case 2:
            {
                switch(menu_level_2){
                    case 1: //2.1 로그인, hk pwd1
                    {
                        
                    }
                    case 2: //2.2 로그아웃, hk
                    {
                        
                    }
                }
            }
            case 3:
            {
                switch(menu_level_2){
                    case 1: //3.1 채용 정보 등록
                    {
                        
                    }
                    case 2: //3.2 등록된 채용 정보 조회
                    {
                        
                    }
                    
                }
            }
            case 4:
            {
                switch(menu_level_2){
                    case 1: //4.1 채용 정보 검색
                    {
                        
                    }
                    case 2: //4.2 채용 지원
                    {
                        
                    }
                    case 3: //4.3 지원 정보 조회
                    {
                        
                    }
                    case 4: //4.4 지원 취소
                    {
                        
                    }

                }
            }
            case 5:
            {
                switch(menu_level_2){
                    case 1: // 5.1 지원 정보 통계
                    {
                        
                    }
                }
            }
            case 6:
            {
                switch(menu_level_2){
                    case 1: // 6.1 종료
                    {
                        program_exit();
                        is_program_exit = 1;
                        break;
                    }
                }
            }
        }
    }
}




// join()
void join(){
    
}


void program_exit(){
    
}

void Company::addNewRecruitInfo(const std::string& task, int applyNumber, int deadline){ 
      this->task = task;
      this->applyNumber = applyNumber;
      this->deadline = deadline;

}

    
void Company::showRecruitInfo(){ //to do

}


void applyRecruit_InfoUI::inputRecruitinfo(){
        string task;
        int applyNumber;
        int deadline;
        fscanf(in_fp, "%s %d %d", task, &applyNumber, &deadline);
    };

void applyRecruit_InfoUI::startInterface(){
        fprintf(out_fp, "3.1. 채용 정보 등록\n");
        
        std::string task;
        int applyNumber;
        int deadline;

        std::cout << "업무를 입력하세요.: ";
        std::getline(std::cin, task);

        std::cout << "인원 수를 입력하세요: ";
        std::cin >> applyNumber;

        std::cout << "마감 기한을 입력하세요: ";
        std::cin >> deadline;
        fprintf(out_fp, "> %s %d %d\n", task.c_str(), applyNumber, deadline);

    }

void applyRecruit_Info::addRecruitInfo(const std::string& task, int applyNumber, int deadline){
        applyRecruit_Info applyrecruitinfo;
        applyrecruitinfo.addRecruitInfo(task, applyNumber, deadline);
    }

RecruitInfo RecruitInfoList[50];

void Recruit_InfoUI::startInterface(){
        fprintf(out_fp, "3.2. 등록된 채용 정보 조회\n");
    }

void Recruit_Info::showRecruitInfo(RecruitInfo* RecruitInfoList[]){
    for (int i = 0; i < 50; i++) {
        if(RecruitInfoList[i] != NULL){
            RecruitInfoList[i]->getRecruitInfoList(task, &applyNumber, deadline);
        }
    }
   }












