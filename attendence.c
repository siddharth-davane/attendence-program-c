#include<stdio.h>

int detectUnassignedNums(short int array[], int checkUpto);

int main(){
  printf("Attendance Counter V1.2\ncontrols:\ny: Present\nn: Absent\n");
  printf("j/J: jump to roll.no\n!: Finish\n Max students: 100");

  short int presenty[100] ={0};// fill array with 0, removes old unknown values in the memory
  const int MAX_PRESENTY= 99;
  int jump_no, highest_rollno_reached=0, current_rollno = 0, outputFormat, invalidRollNumbersFound = 0;
  char command, saveToDisk, filename[128];


  while (current_rollno<=MAX_PRESENTY){
    printf("\nIs Roll.no %d present?: ",current_rollno+1);
    scanf(" %c", &command);// space before %c tells scanf to ignore whitespace

    //logic here
    if(command == '!'){
      //remove 1 from highest rollno because its invalid
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
      //or invalid(0)
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

  printf("\nChoose output format: \n1. List \n2. Table (Present only)\n3. Table(All)\nOption: ");
  
  scanf("%d",&outputFormat);
  

  invalidRollNumbersFound = detectUnassignedNums(presenty, highest_rollno_reached);


  // Output Printing logic
  printf("\n\nResults :  \n------------------\n\n");

  switch(outputFormat){
    case 1:
    //list format
    for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
      if(presenty[current_rollno] == 1){
        printf("Roll no %d: Present\n", current_rollno+1);
      }
      else if(presenty[current_rollno] == 2) {
        printf("Roll no %d: Absent\n", current_rollno+1);
      }
      else{
        // keep rollnumbers with invalid or unassigned state in output
        printf("Roll no %d: invalid\n", current_rollno+1);
      }
    }
    break;
    //end of list format

    case 2:
    case 3:
    // Table Format
    printf("\n|Present:------------------------|\n| ");
    for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
      if(presenty[current_rollno] ==1){
        printf(" %2d", current_rollno+1);
      }
      else{printf("   ");}
      if((current_rollno+1)%10==0){
        printf(" |\n| "); //newline every 10 numbers
      }
    }

    if(outputFormat==2)
      break;//end of group (present only) format

    // Table (All) Format, extends format 2
    printf("\n|Absent:-------------------------|\n| ");
    for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
      if(presenty[current_rollno] ==2){
        printf(" %2d", current_rollno+1);
      }
      else{printf("   ");}
      if((current_rollno+1)%10==0){
        printf(" |\n| "); //newline every 10 numbers
      }
    }
    if(invalidRollNumbersFound==1){
      printf("\n|Unassigned:---------------------|\n| ");
      for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
        if(presenty[current_rollno] !=1 && presenty[current_rollno] !=2){
          printf(" %2d", current_rollno+1);
        }
        else{printf("   ");}
        if((current_rollno+1)%10==0){
          printf(" |\n| "); //newline every 10 numbers
        }
      }
    }
    printf("\n");//newline after output ends

    break;

    default:
      printf("\nInvalid output format, no output generated");
  }
  if(invalidRollNumbersFound==1)
    printf("WARNING: Found invalid roll numbers\n");



  printf("\nSave this output to Disk? (y/n):");
  scanf(" %c",&saveToDisk);
  //Write to file if asked to.
  //this is just same of the above program
  //just replaced printf to file output
  if(saveToDisk=='y'||saveToDisk=='Y'){
    printf("\nEnter file name:");
    scanf("%127s",filename);
    FILE *output;
    output = fopen(filename,"w");

    // output printing logic
    fprintf(output,"\n\nResults :  \n------------------\n\n");

  switch(outputFormat){
    case 1:
    //list format
    for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
      if(presenty[current_rollno] == 1){
        fprintf(output,"Roll no %d: Present\n", current_rollno+1);
      }
      else if(presenty[current_rollno] == 2) {
        fprintf(output,"Roll no %d: Absent\n", current_rollno+1);
      }
      else{
        // keep rollnumbers with invalid or unassigned state in output
        fprintf(output,"Roll no %d: invalid\n", current_rollno+1);
      }
    }
    break;
    //end of list format

    case 2:
    case 3:
    // Table Format
    fprintf(output,"\n|Present:------------------------|\n| ");
    for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
      if(presenty[current_rollno] ==1){
        fprintf(output," %2d", current_rollno+1);
      }
      else{fprintf(output,"   ");}
      if((current_rollno+1)%10==0){
        fprintf(output," |\n| "); //newline every 10 numbers
      }
    }

    if(outputFormat==2)
      break;//end of group (present only) format

    // Table (All) Format, extends format 2
    fprintf(output,"\n|Absent:-------------------------|\n| ");
    for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
      if(presenty[current_rollno] ==2){
        fprintf(output," %2d", current_rollno+1);
      }
      else{fprintf(output,"   ");}
      if((current_rollno+1)%10==0){
        fprintf(output," |\n| "); //newline every 10 numbers
      }
    }
    if(invalidRollNumbersFound==1){
      fprintf(output,"\n|Unassigned:---------------------|\n| ");
      for(current_rollno=0; current_rollno<=highest_rollno_reached; current_rollno++){
        if(presenty[current_rollno] !=1 && presenty[current_rollno] !=2){
          fprintf(output," %2d", current_rollno+1);
        }
        else{fprintf(output,"   ");}
        if((current_rollno+1)%10==0){
          fprintf(output," |\n| "); //newline every 10 numbers
        }
      }
    }
    fprintf(output,"\n");//newline after output ends

    break;

    default:
      fprintf(output,"\nInvalid output format, no output generated");
  }
  if(invalidRollNumbersFound==1)
    fprintf(output,"WARNING: Found invalid roll numbers\n");


    fclose(output);
    printf("Save Successful\n\n");

  }

  return 0;
}

int detectUnassignedNums(short int array[], int checkUpto){
  int i;
  for(i=0;i<=checkUpto;i++){
    if(array[i] != 1 && array[i] !=2){
      return 1;
    }

  }
  return 0;
}


