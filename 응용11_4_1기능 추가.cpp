#include <stdio.h>

// �������� ���� ������ �����Ͽ� �پ��� �Լ����� ��� �����ϵ��� �մϴ�.
char *ms_char[10] = {"��Ƽ����", "����", "ų�ι���", "��ġ", "��Ʈ", "�ߵ�", "����", "��(ô)", "��", "��"};

// ���� ��� ��� �Լ�
void print_distance_unit(void);
// ��ȯ ��� �Լ�
void measure_calculate(int basic, int transe, double measure);

int main(void)
{
    double measure;
    int basic, transe;
    char again = 'y'; // ����ڿ��� ��� ��ȯ�� ������ ��� �� ����ϴ� ����

    while (again == 'y' || again == 'Y')
    {
        printf("���̿� ���� ������ ȯ�� ���α׷�\n\n");
        print_distance_unit();
        printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
        
        if (scanf("%d %d", &basic, &transe) != 2 || basic < 0 || basic > 9 || transe < 0 || transe > 9)
        {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
            continue;
        }

        printf("���� �Է��ϰ� Enter>");
        scanf("%lf", &measure);
        printf("\n");
        measure_calculate(basic, transe, measure);

        printf("\n��� ��ȯ�Ͻǲ���'y' �׸��Ͻǲ��� 'n': ");
        scanf(" %c", &again);
    }

    return 0;
}

// ���� ����� ����ϴ� �Լ�
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

// �Էµ� �⺻ �������� ��� ������ ���̸� ��ȯ�ϴ� �Լ�
void measure_calculate(int basic, int transe, double measure)
{
    double msre[10], unit, result;

    // �� �������� ��Ƽ���͸� �������� �� ��ȯ ����� ����
    msre[0]=392772;		//centimeter
    msre[1]=msre[0]/100.;	//meter
    msre[2]=msre[1]/1000.;	//kilometer
    msre[3]=msre[0]/2.54;	//inch
    msre[4]=msre[3]/12.;	//feet
    msre[5]=msre[4]/3.;	//yard 
    msre[6]=msre[5]/1760.;	//mile
    msre[7]=12960.;      	//��
    msre[8]=msre[7]/6.;   	//��
    msre[9]=msre[8]/(6.*36); //��


    unit = msre[basic];
    result = measure * (msre[transe] / unit);
    printf("%.2f %8s�� ", measure, ms_char[basic]);
    printf("%15.5f %8s\n", result, ms_char[transe]);
}
