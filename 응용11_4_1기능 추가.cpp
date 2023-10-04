#include <stdio.h>

// 단위들을 전역 변수로 선언하여 다양한 함수에서 사용 가능하도록 합니다.
char *ms_char[10] = {"센티미터", "미터", "킬로미터", "인치", "피트", "야드", "마일", "자(척)", "간", "리"};

// 단위 목록 출력 함수
void print_distance_unit(void);
// 변환 계산 함수
void measure_calculate(int basic, int transe, double measure);

int main(void)
{
    double measure;
    int basic, transe;
    char again = 'y'; // 사용자에게 계속 변환할 것인지 물어볼 때 사용하는 변수

    while (again == 'y' || again == 'Y')
    {
        printf("길이에 대한 도량형 환산 프로그램\n\n");
        print_distance_unit();
        printf("\n\n기본단위와 변환단위\n입력 후 Enter(예:1 5)>");
        
        if (scanf("%d %d", &basic, &transe) != 2 || basic < 0 || basic > 9 || transe < 0 || transe > 9)
        {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
            continue;
        }

        printf("값을 입력하고 Enter>");
        scanf("%lf", &measure);
        printf("\n");
        measure_calculate(basic, transe, measure);

        printf("\n계속 변환하실꺼면'y' 그만하실꺼면 'n': ");
        scanf(" %c", &again);
    }

    return 0;
}

// 단위 목록을 출력하는 함수
void print_distance_unit(void)
{
    int i;
    for(i=0; i<=9; i++)
    {
        printf("%d:%-8s  ", i, ms_char[i]);
        if (i%3 == 2)
            printf("\n");
    }
}

// 입력된 기본 단위에서 대상 단위로 길이를 변환하는 함수
void measure_calculate(int basic, int transe, double measure)
{
    double msre[10], unit, result;

    // 각 단위별로 센티미터를 기준으로 한 변환 계수를 정의
    msre[0]=392772;		//centimeter
    msre[1]=msre[0]/100.;	//meter
    msre[2]=msre[1]/1000.;	//kilometer
    msre[3]=msre[0]/2.54;	//inch
    msre[4]=msre[3]/12.;	//feet
    msre[5]=msre[4]/3.;	//yard 
    msre[6]=msre[5]/1760.;	//mile
    msre[7]=12960.;      	//자
    msre[8]=msre[7]/6.;   	//간
    msre[9]=msre[8]/(6.*36); //리


    unit = msre[basic];
    result = measure * (msre[transe] / unit);
    printf("%.2f %8s는 ", measure, ms_char[basic]);
    printf("%15.5f %8s\n", result, ms_char[transe]);
}
