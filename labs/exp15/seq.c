#include <stdio.h>

typedef struct {
	int sno;
	char name[30];
	int m1, m2, m3;
} STD;

int main() {
	int i, n, sno_key, opn, flg = 1;
	FILE *fp;

	printf("How many records? ");
	scanf("%d", &n);

	fp = fopen("stud.txt", "w");
	
	for(i = 0; i < n; i++) {
		printf("Enter the student information: %d (sno, Name, M1, M2, M3): ", i + 1);
		STD s;
		scanf("%d %s %d %d %d", &s.sno, &(s.name), &s.m1, &s.m2, &s.m3);
		fwrite(&s, sizeof(STD), 1, fp);
	}

	fclose(fp);

	fp = open("stud.txt", "r");
	
	do {
		printf("1-DISPLAY\n2-SEARCH\n3-EXIT\nYOUR OPTION: ");
		scanf("%d", &opn);
		switch (opn) {
			case 1:
				printf("\nStudent Records in the file\n");
				STD st;
				while (fread(&st, sizeof(STD), 1, fp) )
					printf("%d\t%s\t%d\t%d\t%d\n", st.sno, st.name, st.m1, st.m2, st.m3);
				break;
			case 2:
				printf("\nEnter serial number of student to search: ");
				scanf("%d", &sno_key);
				STD std;
				int fnd = 0;
				while (fread(&std, sizeof(STD), 1, fp) )
					if (std.sno == sno_key) {
						fnd = 1;
						break;
					}

				if (fnd == 1) {
					printf("%d - FOUND in record\n", sno_key);
					printf("%d\t%s\t%d\t%d\t%d\n", std.sno, std.name, std.m1, std.m2, std.m3);
				} else {
					printf("Record not FOUND - %d\n", sno_key);
				}
				break;
			case 3:
				printf("EXIT Program!\n");
				flg = 0;
				break;
			default:
				printf("Invalid option! TRY AGAIN\n\n");
				break;
		}
	} while (flg != 0);
	
	fclose(fp);

	return 0;
}

