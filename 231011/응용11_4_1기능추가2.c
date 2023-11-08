#include <stdio.h>
#include <stdlib.h>  // system 함수를 위해

char *ms_char[10] = {"센티미터", "미터", "킬로미터", "인치", "피트", "야드", "마일", "자(척)", "간", "리"};

void print_distance_unit(void);
void measure_calculate(int basic, int transe, double measure);

int main(void)
{
    // ASCII 아트 출력
    printf("$$\\       $$$$$$$$\\ $$\\   $$\\  $$$$$$\\ $$$$$$$$\\ $$\\   $$\\       $$\\   $$\\ $$\\   $$\\ $$$$$$\\ $$$$$$$$\\       $$\\ $$\\\n");
    printf("$$ |      $$  _____|$$$\\  $$ |$$  __$$\\\\__$$  __|$$ |  $$ |      $$ |  $$ |$$$\\  $$ |\\_$$  _|\\__$$  __|      $$ |$$ |\n");
    printf("$$ |      $$ |      $$$$\\ $$ |$$ /  \\__|  $$ |   $$ |  $$ |      $$ |  $$ |$$$$\\ $$ |  $$ |     $$ |         $$ |$$ |\n");
    printf("$$ |      $$$$$\\    $$ $$\\$$ |$$ |$$$$\\   $$ |   $$$$$$$$ |      $$ |  $$ |$$ $$\\$$ |  $$ |     $$ |         $$ |$$ |\n");
    printf("$$ |      $$  __|   $$ \\$$$$ |$$ |\\_$$ |  $$ |   $$  __$$ |      $$ |  $$ |$$ \\$$$$ |  $$ |     $$ |         \\__|\\__|\n");
    printf("$$ |      $$ |      $$ |\\$$$ |$$ |  $$ |  $$ |   $$ |  $$ |      $$ |  $$ |$$ |\\$$$ |  $$ |     $$ |                 \n");
    printf("$$$$$$$$\\ $$$$$$$$\\ $$ | \\$$ |\\$$$$$$  |  $$ |   $$ |  $$ |      \\$$$$$$  |$$ | \\$$ |$$$$$$\\    $$ |         $$\\ $$\\\n");
    printf("\\________|\\________|\\__|  \\__| \\______/   \\__|   \\__|  \\__|       \\______/ \\__|  \\__|\\______|   \\__|         \\__|\\__|\n");

    char startChoice;
    printf("\n시작하실꺼면 'y' 종료하실꺼면 'n'을 입력하세요: ");
    scanf(" %c", &startChoice);

    if (startChoice != 'y' && startChoice != 'Y')
    {
        return 0;
    }
    system("cls");
    system("clear");

    while (1)
    {
        printf("길이에 대한 도량형 환산 프로그램\n\n");
        print_distance_unit();
        printf("\n\n기본단위와 변환단위\n입력 후 Enter(예:1 5)>");

        int basic, transe;
        double measure;
        if (scanf("%d %d", &basic, &transe) != 2 || basic < 0 || basic > 9 || transe < 0 || transe > 9)
        {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
            printf("\n");
            continue;
        }

        printf("값을 입력하고 Enter>");
        scanf("%lf", &measure);
        printf("\n");
        measure_calculate(basic, transe, measure);

        char again;
        printf("\n계속 하실꺼면 'y', 그만 하실꺼면 'n'을 입력해주세요: ");
        scanf(" %c", &again);

        if (again == 'n' || again == 'N')
        {
            break; // 프로그램 종료
        }
        else if (again == 'y' || again == 'Y')
        {
            system("cls");
            system("clear");
        }
    }

    return 0;
}

void print_distance_unit(void)
{
    int i;
    for (i = 0; i <= 9; i++)
    {
        printf("%d:%-8s  ", i, ms_char[i]);
        if (i % 3 == 2)
            printf("\n");
    }
}

void measure_calculate(int basic, int transe, double measure)
{
    double msre[10], unit, result;

    msre[0]=392772;
    msre[1]=msre[0]/100.;
    msre[2]=msre[1]/1000.;
    msre[3]=msre[0]/2.54;
    msre[4]=msre[3]/12.;
    msre[5]=msre[4]/3.;
    msre[6]=msre[5]/1760.;
    msre[7]=12960.;
    msre[8]=msre[7]/6.;
    msre[9]=msre[8]/(6.*36);

    unit = msre[basic];
    result = measure * (msre[transe] / unit);
    printf("%.2f %8s는 ", measure, ms_char[basic]);
    printf("%15.5f %8s\n", result, ms_char[transe]);
}
