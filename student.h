#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
}SLL;

void add_record(SLL **head);
void delete_record(SLL **head);
void show_records(SLL *head);
void modify_record(SLL *head);
void save_records(SLL *head);
void load_records(SLL **head);
void sort_records(SLL **head);
void delete_all(SLL **head);
void reverse_list(SLL **head);

int roll_exists(SLL *head, int rollno);
int new_roll(SLL *head);
void print_one_record(SLL *p);

#endif
