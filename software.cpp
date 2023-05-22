#include "software.h"


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






















