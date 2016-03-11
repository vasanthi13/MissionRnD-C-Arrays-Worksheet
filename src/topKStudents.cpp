/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if(students==NULL) return NULL;
	if (len < 0) return NULL;
	if (K <= 0) return NULL;
	if (K >= len) return &students;
	int max,i,pos=0,j=0;
	student *s1 = (student *)malloc(sizeof(student)*K);
	max = students[0].score;
	while (K != 0)
	{
		for (i = 0; i < len; i++)
		{
			if (max < students[i].score)
			{
				max = students[i].score;
				pos = i;
			}
		}
		K--;
		s1[j] = students[pos];
		j++;
		students[pos].score = 0;
	}
	return &s1;
}