#include<stdio.h>
int main(){
  printf("Attendance Counter\ncontrols:\ny: Present\nn: Absent\n");
  printf("j/J: jump to roll.no\n!: Finish\n Max students: 100");

  short int presenty[100] ={0};// fill array with 0, removes old unknown values in the memory
  const int MAX_PRESENTY= 99;
  int jump_no, highest_rollno_reached=0, current_rollno = 0;
  char command;


  while (current_rollno<=MAX_PRESENTY){
    printf("\nIs Roll.no %d present?: ",current_rollno+1);
    scanf(" %c", &command);// space before %c tells scanf to ignore whitespace

    //logic here
    if(command == '!'){
      //remove 1 from highest rollno because its unassigned
      highest_rollno_reached--;
      break;
    }
    else if (command == 'j' || command =='J'){
      printf("\nEnter Roll.no to jump to :");
      scanf("%d",&jump_no);
      current_rollno=jump_no -1; //-1 for index correction
    }
    else{
      //Add an entry for presenty(1) or absent(2)
      //or unassigned(0)
      if (command=='y' || command=='Y'){
        presenty[current_rollno] = 1;
      }
      else if(command=='n' || command=='N'){
        presenty[current_rollno] =2;
      }
      current_rollno++;
    }

    // remember which roll no was highest
    if( current_rollno > highest_rollno_reached)
    {highest_rollno_reached=current_rollno;}

  }


  // Output Printing logic
  printf("\n\nResults :  \n------------------\n\n");

  for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
    if(presenty[current_rollno] == 1){
      printf("Roll no %d: Present\n", current_rollno+1);
    }
    else if(presenty[current_rollno] == 2) {
      printf("Roll no %d: Absent\n", current_rollno+1);
    }
    else{
      // keep rollnumbers with invalid or unassigned state in output
      printf("Roll no %d: unassigned\n", current_rollno+1);
    }
  }


  return 0;
}
