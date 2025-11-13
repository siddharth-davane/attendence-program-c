#include<stdio.h>
int main(){
  printf("Attendance Counter\ncontrols:\ny: Present\nn: Absent\n");
  printf("j/J: jump to roll.no\n!: Finish\n");

  short int presenty[100] ={0};// fill array with 0, removes old unknown values in the memory
  const int MAX_PRESENTY= 99;
  int highest_rollno_reached, current_rollno, jump_no;
  char command;


  for(current_rollno=0; current_rollno<=MAX_PRESENTY; current_rollno++){
    printf("\nIs Roll.no %d present?: ",current_rollno+1);
    scanf(" %c", &command);// space before %c tells scanf to ignore whitespace
    if(command == '!'){
      //start exiting program
      return 0;
    }
    else if (command == 'j' || command =='J'){
      printf("Enter Roll.no to jump to :");
      scanf("%d",&jump_no);
      current_rollno=jump_no -2; //-1 for index correction, -1 because increments on loop end
    }
  }

  return 0;
}
