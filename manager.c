/**********************************************************
 *                                                        *
 *    This code is a simple manager.                      *  
 *    It gets inputs (in this case employee info.)        *
 *    from the user and places them in a array            *
 *    then the user can ask for the info given a id       *
 *                                                        *
 **********************************************************/

// I think this is an exercice from some book, but i am not sure.

#include <stdio.h>
#include <conio.h>

#define LIMIT 100

struct employee{
int code;
float salary;
int age;
};

void addEmp(int *index, struct employee list[]);
int findFromCode(int code, struct employee list[], int range);

int main()
{
	struct employee emp[LIMIT];
	int empNum = 0;
	int awnser;

	// A
	printf("-----------------------------------\n");
	while (empNum <= LIMIT)
	{
		printf("Adicionar um funcionário(s ou n): ");
		awnser = getch();
		printf("%c\n", awnser);
		if (awnser == 'n' || awnser == 'N')
		{
			break;
		}
		else if (awnser == 's' || awnser == 'S')
		{
			addEmp(&empNum, emp);
		}
	}
	
	// B
	printf("-----------------------------------\n");
	printf("Quer buscar as informações?(s ou n) ");
	awnser = getch();
	printf("%c\n", awnser);

	if (awnser == 'n' || awnser == 'N')
	{
		printf("Prosseguindo ...\n");
	}
	else if (awnser == 's' || awnser == 'S')
	{
		int cd, index;
		printf("Indique o código: ");
		scanf("%d", &cd);

		index = findFromCode(cd, emp, empNum);
		if (index != -1)
		{
			printf("O funcionário com código %d possui um salário de %.2f aos %d anos de idade.\n", emp[index].code, emp[index].salary, emp[index].age);
		}
		else
		{
			printf("NOT FOUND!\n");
		}
	}

	// C
	printf("-----------------------------------\n");
	printf("Quer aumentar o salário de alguém?(s ou n) ");
	awnser = getch();
	printf("%c\n", awnser);

	if (awnser == 'n' || awnser == 'N')
	{
		printf("Prosseguindo ...\n");
	}
	else if(awnser == 's' || awnser == 'S')
	{
		int cd, index;
		printf("Indique o código: ");
		scanf("%d", &cd);

		index = findFromCode(cd, emp, empNum);
		if (index != -1)
		{
			float oldSal = emp[index].salary;
			emp[index].salary *= 1.1f;
			printf("O salário do funcionário com código %d foi de %.2f à %.2f.\n", emp[index].code, oldSal, emp[index].salary);
		}
		else
		{
			printf("NOT FOUND!\n");
		}
	}

	// D
	printf("-----------------------------------\n");
	float sum = 0.0f;
	for (int i = 0; i < empNum; i++)
	{
		sum += emp[i].age;
	}
	float m = sum / empNum;
	printf("A idade média dos funcionários é de %.2f.\n", m);

	// E
	printf("-----------------------------------\n");
	int ageLim;
	printf("Digite o valor de uma idade para saber quantos funcionários são mais novos: ");
	scanf("%d", &ageLim);
	for (int i = 0; i < empNum; i++)
	{
		if (emp[i].age < ageLim)
		{
			printf("O funcionário com código %d possui um salário de %.2f aos %d anos de idade\n", emp[i].code, emp[i].salary, emp[i].age);
		}
	}
}

void addEmp(int *index, struct employee list[])
{
	printf("Por favor, passe os dados requisitados: \n");
	printf("Código do funcionário: ");
	scanf("%d", &list[*index].code);

	printf("Salário do funcionário: ");
	scanf("%f", &list[*index].salary);

	printf("Idade do funcionário: ");
	scanf("%d", &list[*index].age);
	*index += 1;
}

int findFromCode(int code, struct employee list[], int range)
{
	// linear search
	for (int i = 0; i < range; i++)
	{
		if(list[i].code == code)
		{
			return i;
		}
	}

	return -1;
}