#ifndef DEF_PERSON
#define DEF_PERSON

typedef struct Person Person;
struct Person {
  char firstName[100];
  char lastName[100];
  char address[1000];
  int age;
  int sex;
};

void init_person()

#endif
