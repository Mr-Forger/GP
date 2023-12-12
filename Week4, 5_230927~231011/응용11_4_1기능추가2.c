#include <stdio.h>
#include <stdlib.h>  // system �Լ��� ����

char *ms_char[10] = {"��Ƽ����", "����", "ų�ι���", "��ġ", "��Ʈ", "�ߵ�", "����", "��(ô)", "��", "��"};

void print_distance_unit(void);
void measure_calculate(int basic, int transe, double measure);

int main(void)
{
    // ASCII ��Ʈ ���
    printf("$$\\       $$$$$$$$\\ $$\\   $$\\  $$$$$$\\ $$$$$$$$\\ $$\\   $$\\       $$\\   $$\\ $$\\   $$\\ $$$$$$\\ $$$$$$$$\\       $$\\ $$\\\n");
    printf("$$ |      $$  _____|$$$\\  $$ |$$  __$$\\\\__$$  __|$$ |  $$ |      $$ |  $$ |$$$\\  $$ |\\_$$  _|\\__$$  __|      $$ |$$ |\n");
    printf("$$ |      $$ |      $$$$\\ $$ |$$ /  \\__|  $$ |   $$ |  $$ |      $$ |  $$ |$$$$\\ $$ |  $$ |     $$ |         $$ |$$ |\n");
    printf("$$ |      $$$$$\\    $$ $$\\$$ |$$ |$$$$\\   $$ |   $$$$$$$$ |      $$ |  $$ |$$ $$\\$$ |  $$ |     $$ |         $$ |$$ |\n");
    printf("$$ |      $$  __|   $$ \\$$$$ |$$ |\\_$$ |  $$ |   $$  __$$ |      $$ |  $$ |$$ \\$$$$ |  $$ |     $$ |         \\__|\\__|\n");
    printf("$$ |      $$ |      $$ |\\$$$ |$$ |  $$ |  $$ |   $$ |  $$ |      $$ |  $$ |$$ |\\$$$ |  $$ |     $$ |                 \n");
    printf("$$$$$$$$\\ $$$$$$$$\\ $$ | \\$$ |\\$$$$$$  |  $$ |   $$ |  $$ |      \\$$$$$$  |$$ | \\$$ |$$$$$$\\    $$ |         $$\\ $$\\\n");
    printf("\\________|\\________|\\__|  \\__| \\______/   \\__|   \\__|  \\__|       \\______/ \\__|  \\__|\\______|   \\__|         \\__|\\__|\n");

    char startChoice;
    printf("\n�����Ͻǲ��� 'y' �����Ͻǲ��� 'n'�� �Է��ϼ���: ");
    scanf(" %c", &startChoice);

    if (startChoice != 'y' && startChoice != 'Y')
    {
        return 0;
    }
    system("cls");
    system("clear");

    while (1)
    {
        printf("���̿� ���� ������ ȯ�� ���α׷�\n\n");
        print_distance_unit();
        printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");

        int basic, transe;
        double measure;
        if (scanf("%d %d", &basic, &transe) != 2 || basic < 0 || basic > 9 || transe < 0 || transe > 9)
        {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
            printf("\n");
            continue;
        }

        printf("���� �Է��ϰ� Enter>");
        scanf("%lf", &measure);
        printf("\n");
        measure_calculate(basic, transe, measure);

        char again;
        printf("\n��� �Ͻǲ��� 'y', �׸� �Ͻǲ��� 'n'�� �Է����ּ���: ");
        scanf(" %c", &again);

        if (again == 'n' || again == 'N')
        {
            break; // ���α׷� ����
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
    printf("%.2f %8s�� ", measure, ms_char[basic]);
    printf("%15.5f %8s\n", result, ms_char[transe]);
}
