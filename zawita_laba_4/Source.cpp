#include <iostream>
#include<stdio.h>
#include <fstream>
using namespace std;

const size_t N = 10;
const size_t arrayMax = 20;
const size_t sizeNumber = 7;
const size_t sizeMarka = 10;

struct T1_elem // структура элемента таблицы 1
{
	char number[sizeNumber] = "",
		mark[sizeMarka] = "",
		owner_name[arrayMax] = "",
		owner_lastname[arrayMax] = "", 
		owner_patronymic[arrayMax] = "";
};

struct table // структура таблицы 1
{
	T1_elem elem[N]; size_t n=0; 
};

struct T2_elem // пешеходы
{
	char owner_name[arrayMax]="", owner_lastname[arrayMax] = "", owner_patronymic[arrayMax] = "";
};

struct T3_elem // буфер для "аварии"
{
	char number[sizeNumber] = ""; char mark[sizeMarka] = "";
};

int main()
{
	setlocale(LC_ALL, "Russian");
	table table_1;
	FILE* fp, *file;

	fopen_s(&fp, "Текст1.txt", "r");
	fopen_s(&file, "Текст1.txt", "r");
	char array[sizeNumber] = "";

	if (fp != nullptr && file != nullptr)
	{
		if (fscanf_s(file, "%s", array, sizeNumber)==EOF) {
			cout << "Видимо у вас файле <<Авто>> нет информации о автомобилях!" << endl;
		}
		else {
			char buf[arrayMax] = "";
			char bufMARKA[sizeMarka] = "";
			char bufNUMBER[sizeNumber] = "";

			while (!feof(fp) && table_1.n < N) // пока не конец файла или не дошли до конца таблицы
			{
				fscanf_s(fp, "%s", bufNUMBER, sizeNumber); // взяли номер
				strcpy_s(table_1.elem[table_1.n].number, bufNUMBER);// поместить номер в таблицу

				fscanf_s(fp, "%s", bufMARKA, sizeMarka); // взяли марку
				strcpy_s(table_1.elem[table_1.n].mark, bufMARKA); // поместить марку в таблицу

				fscanf_s(fp, "%s", buf, arrayMax); // взяли имя
				strcpy_s(table_1.elem[table_1.n].owner_name, buf); // поместить имя в таблицу

				fscanf_s(fp, "%s", buf, arrayMax); // взяли фамилию
				strcpy_s(table_1.elem[table_1.n].owner_lastname, buf); // поместить фамилию в таблицу

				fscanf_s(fp, "%s", buf, arrayMax); // взяли отчество
				strcpy_s(table_1.elem[table_1.n].owner_patronymic, buf); // поместили отчество в таблицу

				table_1.n++;
			}


			for (int i = 0; i < table_1.n; i++) // вывод таблицы
			{
				printf("%s|%-10s|%-10s|%-10s|%-10s\n",
					table_1.elem[i].number,
					table_1.elem[i].mark,
					table_1.elem[i].owner_name,
					table_1.elem[i].owner_lastname,
					table_1.elem[i].owner_patronymic);
			}

			cout << endl;
			
			// таблица пешеходы
			fopen_s(&fp, "Текст.txt", "r");
			fopen_s(&file, "Текст.txt", "r");

			if (fp != nullptr&&file!=nullptr)
			{

				if (fscanf_s(file, "%s", array, sizeNumber) == EOF)
					cout << "В этом году аварий не было! Мои поздравления!" << endl;
				else {
					table table_2; // инициализация таблицы пешеходы
					T3_elem buf_1; // буфер для таблицы аварии
					fscanf_s(fp, "%s", bufNUMBER, sizeNumber); // взяли номер, берём до цикла для того, чтобы можно было в конце цикла перескочить на конец потока в fp

					while (!feof(fp))
					{
						strcpy_s(buf_1.number, bufNUMBER); // поместили в буфер
						fscanf_s(fp, "%s", bufMARKA, sizeMarka); // взяли марку
						strcpy_s(buf_1.mark, bufMARKA); // поместили в буфер
						int n = 0;

						for (int i = n; i < table_1.n; i++)
							if (strcmp(buf_1.number, table_1.elem[i].number) == 0)
							{
								strcpy_s(table_2.elem[table_2.n].owner_name, table_1.elem[i].owner_name);
								strcpy_s(table_2.elem[table_2.n].owner_lastname, table_1.elem[i].owner_lastname);
								strcpy_s(table_2.elem[table_2.n].owner_patronymic, table_1.elem[i].owner_patronymic);
								table_2.n++;
								n = i;
							}

						fscanf_s(fp, "%s", bufNUMBER, sizeNumber); // взяли номер
					}

					cout << "Таблица пешеходы" << endl;

					for (int i = 0; i < table_2.n; i++) // вывод таблицы
					{
						printf("%s|%-10s|%-10s\n",
							table_2.elem[i].owner_name,
							table_2.elem[i].owner_lastname,
							table_2.elem[i].owner_patronymic);
					}
				}
			}
		}
	
	}

	return 0;
}