#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

int scanint(void) {
	char in[60];
	scanf("%s", &in);
	if(isdigit(in[0]))
		return in[0]-48;
	else
		return 0;
}

int reverse(int n){
          int num=0;
          while(n){
                    num = num*10 + (n%10);
                    n/=10;
          }
          return num;

}

void inventory(int keys, int lab, int books, int scalpel, int error, int obj){
          system("cls");

          if(keys + lab + books + scalpel >=1){ //Prints the inventory to the screen
                    printf("Inventory: ");
                    if(scalpel)
                              printf("|Scalpel: %d\t", scalpel);
                    if(books)
                              printf("|Books: %d\t", books);
                    if(keys)
                              printf("|Keys: %d\t", keys);
                    if(lab)
                              printf("|Lab coat: %d\t", lab);
                    printf("\n\n");
          }
          int new_obj = obj;
          new_obj = reverse(new_obj);

          printf("Current Objective:\n");
          if(new_obj == 0){
          printf("\t\t\tGo and explore the hospital. Find the prototype!\n");
          }else
          while(new_obj){

          switch(new_obj % 10){
          case 1: printf("\t\t\tFind the science book, to defeat the antivaxxers!\n");break;
          case 2: printf("\t\t\tFind the passcode!\n"); break;
          case 3: printf("\t\t\tOpen the locked drawer!\n"); break;
          case 4: printf("\t\t\tFind the key to the laboratory!\n"); break;
          case 5: printf("\t\t\tFind the scalpel!\n"); break;
          case 6: printf("\t\t\tFind the lab coat!\n"); break;
          }
          new_obj/=10;
          }
          printf("\n");
          if(error){
                    printf("!!Oh, not quite right! You need to type a number that makes sense! Try again!\n\n");
          }
}

int main(){
          //Basic variables
          int choice = 0, game = 0, crtLevel, janitor = 0, nurse = 0, elevator = 0, passcode = 77853, code;
          //Inventory
          int keys = 0, lab = 0, books = 0, scalpel = 0, error = 0, obj = 0;
          char name[60];

          //Intro
          printf("Hello and welcome to\n\t*`*Prototype resque*`*\nThere's a major outbreak of a very contagious virus (hard to imagine, I know). The health system was near to collapsing, when all of the medical staff went on strike and quit their jobs. Now, hospitals are deserted and the number of deceased is growing rapidly.\nYou've received information about a vaccine prototype \
located somewhere in Berlin's St. Benedict Hospital. You must go there and resque the prototype.\n\nBut first, what is your name?\n");
          fgets(name, 60, stdin);
          name[strcspn(name, "\n")] = '\0';
          printf("\nNice to meet you, %s! You are standing in front of the St Benedict Hospital.\nYou can now enter and start looking for the life saving vaccine prototype.\nPress 1 - Start game\n", name);
          choice = scanint();
          while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Start game\n");
				choice = scanint();
			}
          crtLevel = 1;

          while(game == 0){
          //Level 1: central hall, 1st floor
          while(crtLevel == 1){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("You entered the hospital and are now standing in the central hall. You can go to the second floor, but you have 2 choices. What do you do?\n");
                    printf("1 - Go to the East Wing\n");
                    printf("2 - Go to the West Wing\n");
                    choice = scanint();

                    switch(choice){
                    case 1: crtLevel = 2; break;

                    case 2: crtLevel = 3; break;

                    default: error = 1; break;
                    }
          }
          //Level 2: 2nd floor, East Wing
          while(crtLevel == 2){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("So, you've gotten to the second floor of the East Wing.\n");
                    printf("1 - Go to the third floor\n");
                    printf("2 - Go to the first floor\n");
                    printf("3 - Go to the elevator\n");
                    choice = scanint();

                    switch(choice){
                    case 1: crtLevel = 4; break;

                    case 2: crtLevel = 1; break;

                    case 3: if(elevator){
                              printf("The elevator is broken! You broke it, remember?\n");
                              printf("1 - Make another choice\n");
                              choice = scanint();

                              while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Make another choice\n");
				choice = scanint();
			}
                    crtLevel = 2; break;
                    }else{
                    crtLevel = 5; break;
                    }

                    default: error = 1; break;
                    }
          }
          //Level 3: 2nd floor, West Wing
          while(crtLevel == 3){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("Welcome to the West Wing of this hospital. You are now on the second floor.\nThere's not much around, except for a drawer that needs a passcode to be unlocked.\n");
                    printf("1 - Go to the third floor\n");
                    printf("2 - Go to the first floor\n");
                    printf("3 - Open the drawer\n");
                    choice = scanint();

                    switch(choice){
                    case 1: crtLevel = 9; break;

                    case 2: crtLevel = 1; break;

                    case 3: if(nurse){
                              printf("You need to enter the passcode!\n");
                              printf("passcode: ");
                              scanf("%d", &code);

                              while(code!=passcode){
                                        printf("1 - Wrong password. Give it another go\n");
                                        printf("2 - Go back to the nurse and get the passcode\n");
                                        choice = scanint();

                                        if(choice == 1){
                                                  printf("passcode: ");
                                                  scanf("%d", &code);
                                        }
                                        else if(choice == 2){
                                                  crtLevel = 3;
                                                  break;
                                        }
                                        else{
                                                  while (choice != 1 && choice != 2) {
                                                  printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
                                                  printf("1 - Wrong password. Give it another go\n");
                                                  printf("2 - Go back to the nurse and get the passcode\n");
				          choice = scanint();
				}
                                        }
                                        }
                              printf("Alright! You open the drawer and inside it you find a lab coat! Maybe it'll help.\n");
                              printf("1 - Go back\n");
                                        choice = scanint();

                                        while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Go back\n");
				choice = scanint();
			}
                              lab = 1;
                              //objective change: found the lab coat
                              switch(obj){
                              case 3: obj = 0; break;

                              case 6: obj = 0; break;

                              case 36: obj = 0; break;

                              case 63: obj = 0; break;
                              }

                              }else{
                                        printf("You have to find the passcode first!\n");
                                        printf("1 - Go back\n");
                                        choice = scanint();

                                        while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Go back\n");
				choice = scanint();
			}
                                        //new objective: find the passcode
                                        switch(obj){
                                        case 0: obj = 2; break;

                                        case 1: obj = 12; break;

                                        case 4: obj = 42; break;

                                        case 5: obj = 52; break;

                                        case 51: obj = 512; break;

                                        case 6: obj = 62; break;
                                        }
                                        crtLevel = 3;
                              }
                              break;

                    default: error = 1; break;
                    }
          }
          //Level 4: 3rd floor, EW
          while(crtLevel == 4){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;

                    if(!scalpel){
                              printf("You enter an operating room and see a scalpel. You grab it, who knows what you will encounter around here.\n");
                              scalpel = 1;
                    }

                    else{
                              printf("You are on the third floor of the East Wing.\n");
                    }

                    printf("1 - Go to the fourth floor\n");
                    printf("2 - Go to the second floor\n");
                    printf("3 - Go to the elevator\n");
                    printf("4 - Talk to the janitor\n");
                    choice = scanint();

                    switch(choice){
                    case 1: crtLevel = 7; break;

                    case 2: crtLevel = 2; break;

                    case 3: if(elevator){
                              printf("The elevator is broken! You broke it, remember?\n");
                              printf("1 - Make another choice\n");
                              choice = scanint();

                              while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Make another choice\n");
				choice = scanint();
			}
                    crtLevel = 4; break;
                    }else{
                    crtLevel = 5; break;
                    }

                    case 4: crtLevel = 6; janitor = 1; break;

                    default: error = 1; break;
                    }
                    //objective change: found the scalpel
                    switch(obj){
                    case 5: obj = 0; break;

                    case 125: obj = 12; break;
                    case 15: obj = 1; break;
                    case 135: obj = 13; break;

                    case 215: obj = 21; break;
                    case 25: obj = 2; break;
                    case 251: obj = 21; break;

                    case 315: obj = 31; break;
                    case 35: obj = 3; break;
                    case 351: obj = 31; break;

                    case 51: obj = 1; break;
                    case 512: obj = 12; break;
                    case 52: obj = 2; break;
                    case 521: obj = 21; break;
                    case 53: obj = 3; break;
                    case 531: obj = 31; break;
                    }
          }
          //Level 5: elevator
          while(crtLevel == 5){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("You enter the elevator and the doors close really fast.\nYou try to push the button for the doors to open, but nothing happens.\nProblem is, the other buttons don't work either, except for the one for the 5th floor, \
which you notice that it has a circle drawn around it.\nSeems like you have no choice but to go to the fifth floor.\n");
                    printf("1 - Go to the fifth floor\n");
                    choice = scanint();

                    switch(choice){
                    case 1: elevator = 1; crtLevel = 8; break;

                    default: error = 1; break;
                    }
          }
          //Level 6: Janitor
          while(crtLevel == 6){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("Why, hello, %s! I'm surprised you've gotten this far. How do I know your name, you wonder. I know everything.\nI know you should go home. \
Many like you have tried to be the hero, resque the prototype, but have failed terribly. Be wiser, young one, and go home!\n", name);
                    printf("1 - Listen to the Janitor and go home\n");
                    printf("2 - Go to the fourth floor\n");
                    printf("3 - Go to the elevator\n");
                    choice = scanint();

                    switch(choice){
                    case 1: game = 1; crtLevel = 0; printf("\t\tGame over!\nYour cowardliness made millions of people die.\n"); break;

                    case 2: crtLevel = 7; break;

                    case 3: if(elevator){
                              printf("The elevator is broken! You broke it, remember?\n");
                              printf("1 - Make another choice\n");
                              choice = scanint();

                              while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Make another choice\n");
				choice = scanint();
			}
                    crtLevel = 6; break;
                    }else{
                    crtLevel = 5; break;
                    }
                    default: error = 1; break;
                    }
          }
          //Level 7: 4th floor, EW
          while(crtLevel == 7){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    if(janitor){ //if you talked to the janitor
                              printf("Congratulations! You didn't listen to the janitor and decided to continue your journey. It takes lots of courage and that's impressive.\nYou are now situated in a doctor's lounge and you see an anatomy book on the table. You take it, maybe it will come in handy!\n");
                              books = 1;
                              inventory(keys, lab, books, scalpel, error, obj);
                              printf("Congratulations! You didn't listen to the janitor and decided to continue your journey. It takes lots of courage and that's impressive.\nYou are now situated in a doctor's lounge and you see an anatomy book on the table. You take it, maybe it will come in handy!\n");
                    }

                    if(!books){
                              printf("You are now situated in a doctor's lounge and you see an anatomy book on the table. You take it, maybe it will come in handy!\n");
                              books = 1;
                              //objective change: found the science book
                              switch(obj){
                              case 1: obj = 0; break;
                              case 12: obj = 2; break;
                              case 124: obj = 24; break;
                              case 125: obj = 25; break;
                              case 13: obj = 3; break;
                              case 134: obj = 34; break;
                              case 135: obj = 35; break;
                              case 14: obj = 4; break;
                              case 15: obj = 5; break;

                              case 21: obj = 2; break;
                              case 214: obj = 24; break;
                              case 215: obj = 25; break;
                              case 241: obj = 24; break;
                              case 251: obj = 25; break;

                              case 31: obj = 3; break;
                              case 314: obj = 34; break;
                              case 315: obj = 35; break;
                              case 341: obj = 34; break;
                              case 351: obj = 35; break;

                              case 41: obj = 4; break;
                              case 421: obj = 42; break;
                              case 431: obj = 43; break;

                              case 51: obj = 5; break;
                              case 512: obj = 52; break;
                              case 521: obj = 52; break;
                              case 531: obj = 53; break;
                              }

                              inventory(keys, lab, books, scalpel, error, obj);
                              printf("You are now situated in a doctor's lounge and you see an anatomy book on the table. You take it, maybe it will come in handy!\n");
                    }

                    else{
                              printf("You are on the fourth floor of the East Wing.\n");
                    }

                    printf("1 - Go to the fifth floor\n");
                    printf("2 - Go to the third floor\n");
                    printf("3 - Go to the elevator\n");
                    choice = scanint();

                    switch(choice){
                    case 1: crtLevel = 8; break;

                    case 2: crtLevel = 4; break;

                    case 3: if(elevator){
                              printf("The elevator is broken! You broke it, remember?\n");
                              printf("1 - Make another choice\n");
                              choice = scanint();

                              while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Make another choice\n");
				choice = scanint();
			}
                    crtLevel = 4; break;
                    }else{
                    crtLevel = 5; break;
                    }
                    default: error = 1; break;
                    }
          }
          //Level 8: 5th floor, EW
          while(crtLevel == 8){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    if(elevator == 1){
                              printf("The elevator goes up with high speed and stops with a stump. The doors barely open, but you manage to sneak through them.\n");
                              elevator++;
                    }

                    printf("It's the fifth and last floor of the East Wing and you see a key on a nightstand in a pacient room.\nBut, oh no! Antivaxxers!! Do you have your science book on you?\n");
                    if(books){
                              printf("Phew! Luckily, you have it. You take it out and the antivaxxers dissolve. You take the key and see that it's the one for the laboratory.\nYou've gotta find the lab, but the elevator is broken...\n");
                              keys = 1;
                              switch(obj){
                              case 4: obj = 0; break;

                              case 214: obj = 21; break;
                              case 24: obj = 2; break;
                              case 241: obj = 21; break;

                              case 314: obj = 31; break;
                              case 34: obj = 3; break;
                              case 341: obj = 31; break;

                              case 42: obj = 2; break;
                              case 421: obj = 21; break;
                              case 43: obj = 3; break;
                              case 431: obj = 31; break;
                              }
                    }
                    else{
                              printf("You don't have it. And the elevator is broken... Go find the science book, and hurry!\n");
                              //a new objective: find the science book
                              switch(obj){
                              case 0: obj = 1; break;

                              case 2: obj = 21; break;
                              case 24: obj = 241; break;
                              case 25: obj = 251; break;

                              case 3: obj = 31; break;
                              case 34: obj = 341; break;
                              case 35: obj = 351; break;

                              case 4: obj = 41; break;
                              case 42: obj = 421; break;
                              case 43: obj = 431; break;

                              case 5: obj = 51; break;
                              case 52: obj = 521; break;
                              case 53: obj = 531; break;
                              }
                    }
                    printf("1 - Go to the first floor\n");
                    printf("2 - Go to the second floor\n");
                    printf("3 - Go to the third floor\n");
                    printf("4 - Go to the fourth floor\n");
                    choice = scanint();

                    switch(choice){
                    case 1: crtLevel = 1; break;

                    case 2: crtLevel = 2; break;

                    case 3: crtLevel = 4; break;

                    case 4: crtLevel = 7; break;

                    default: error = 1; break;
                    }
          }
          //Level 9: 3rd floor, WW
          while(crtLevel == 9){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("You get to the third floor and you see a nurse sitting on a chair, sleeping. She has to know the passcode.\n");
                    printf("1 - Go to the fourth floor\n");
                    printf("2 - Go to the second floor\n");
                    printf("3 - Wake up the nurse and talk to her\n");
                    choice = scanint();

                    switch(choice){
                    case 1: crtLevel = 10; break;

                    case 2: crtLevel = 3; break;

                    case 3: crtLevel = 11; break;

                    default: error = 1; break;
                    }
          }
          //Level 10: 4th floor, WW
          while(crtLevel == 10){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("The laboratory! But, in front of it, the chief of Medicine...\n\n");
                    printf("-No! You can't take this! If you do, all my life's work is ruined! I will be ruined, you hear me!\n\n");
                    printf("-Give it to the people, then! You say\n\n");
                    printf("-I can't, yet. I must wait for the biggest profit.\n\n");
                    printf("-People are dying! You plead.\n\n");
                    printf("-Ah, people are always dying! says the chief of Medicine with a smirk.\n\n");

                    printf("Do you have the scalpel? If you do, you could persuade him more easily.\n\n");
                    if(scalpel){
                              printf("You do! Perfect, the chief stands back while you go to open the laboratory door.\n\n");
                              if(keys){
                                        if(lab){
                                        printf("\nAnd your lab coat? Yes, perfect! Everything is here.\n");
                                        printf("1-Enter the laboratory.\n");
                                        printf("2-Go back.\n");
                                        choice = scanint();

                                        while(choice != 1 && choice != 2){
                                                            printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
                                                            printf("1-Enter the laboratory.\n");
                                                            printf("2-Go back.\n");
                                                            choice = scanint();

                                        }

                                        switch(choice){
                                        case 1: crtLevel = 12; break;

                                        case 2: crtLevel = 9; break;
                                        }

                                        }
                                        else{
                                                  printf("The lab coat! You really need it. Go and find it!\n");
                                                  //new objective: find the lab coat
                                                  switch(obj){
                                                  case 0: obj = 6; break;

                                                  case 2: obj = 26; break;

                                                  case 3: obj = 36; break;
                                                  }

                                                  printf("1 - Go back to the first floor\n");
                                                  choice = scanint();

                              while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Go back to the first floor\n");
				choice = scanint();
			}
                                        crtLevel = 1;
                                        }
                              }else{
                                                  printf("So close! You don't have the key, you must return and find the key to the laboratory\n");
                                                  //new objective: find the key to the lab
                                                  switch(obj){
                                                  case 0: obj = 4; break;

                                                  case 1: obj = 14; break;
                                                  case 12: obj = 124; break;
                                                  case 13: obj = 134; break;

                                                  case 2: obj = 24; break;
                                                  case 21: obj = 214; break;

                                                  case 3: obj = 34; break;
                                                  case 31: obj = 314; break;
                                                  }

                                                  printf("1 - Go back to the first floor\n");
                                                  choice = scanint();

                              while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Go back to the first floor\n");
				choice = scanint();
			}
			crtLevel = 1;
			break;
                              }
                    }else{
                    printf("You don't! Go back and find the scalpel!\n");
                    //new objective: find the scalpel
                    switch(obj){
                    case 0: obj = 5; break;

                    case 1: obj = 15; break;
                    case 12: obj = 125; break;
                    case 13: obj = 135; break;

                    case 2: obj = 25; break;
                    case 21: obj = 215; break;

                    case 3: obj = 35; break;
                    case 31: obj = 315; break;
                    }

                    printf("1 - Go back to the first floor\n");
                              choice = scanint();

                              while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Go back to the first floor\n");
				choice = scanint();
			}
			crtLevel = 1;
			break;
                    }

          }
          //Level 11: Nurse
          while(crtLevel == 11){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("Zzz.. ah! Who are you? Why did you wake me? I want to sleep away my days. Leave me alone!\n");
                    printf("1 - Insist that she should help you\n");
                    printf("2 - Sing her a song to improve her mood\n");
                    printf("3 - Quit talking to the nurse\n");
                    choice = scanint();

                    switch(choice){
                    case 1:   printf("\n-The world is dying and all you want to do is sleep? That's selfish and you know it. If you care a bit about anyone, you will tell me the passcode!\n\n");
                              printf("-Such insolence! But you might be right... Ok, I'll tell you, if I must. The passcode is simple: 77853\n\n");

                              printf("1 - Stop talking to the nurse\n");
                              choice = scanint();

                                        while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Start game\n");
				choice = scanint();
			}

                              crtLevel = 9;
                              nurse = 1;
                              //new objective: open the locked drawer
                              switch(obj){
                              case 0: obj = 3; break;
                              case 2: obj = 3; break;

                              case 12: obj = 1; break;
                              case 14: obj = 143; break;
                              case 15: obj = 153; break;
                              case 124: obj = 143; break;
                              case 125: obj = 153; break;

                              case 21: obj = 13; break;
                              case 214: obj = 143; break;
                              case 215: obj = 153; break;
                              case 24: obj = 43; break;
                              case 241: obj = 413; break;
                              case 25: obj = 53; break;
                              case 251: obj = 513; break;
                              case 26: obj = 63; break;

                              case 4: obj = 43; break;
                              case 41: obj = 413; break;
                              case 42: obj = 43; break;
                              case 421: obj = 413; break;

                              case 5: obj = 53; break;
                              case 51: obj = 513; break;
                              case 512: obj = 513; break;
                              case 52: obj = 53; break;
                              case 521: obj = 513; break;

                              case 6: obj = 63; break;
                              case 62: obj = 63; break;
                              }
                              break;

                    case 2:   printf("\n||:She can cure with a smile, she can heal with her hands\n\
And she can ruin your high with 0.2 of Narcan\n\
And she only sips Snapple where JCAHO can't see\n\
She's wise like a doc but she's always a nurse to me... :||\n\n");
                              printf("-AAA, please, stop! Your singing is terrible, I'll give you the passcode, just stop singing!\nThe passcode is: 77853\n\n");

                              printf("1 - Stop talking to the nurse\n");
                              choice = scanint();

                                        while (choice != 1) {
				printf("Oh, not quite right! You need to type a number that makes sense! Try again!\n");
				printf("1 - Stop talking to the nurse\n");
				choice = scanint();
			}

                              crtLevel = 9;
                              nurse = 1;
                              //new objective: open the locked drawer
                              switch(obj){
                              case 0: obj = 3; break;
                              case 2: obj = 3; break;

                              case 12: obj = 1; break;
                              case 14: obj = 143; break;
                              case 15: obj = 153; break;
                              case 124: obj = 143; break;
                              case 125: obj = 153; break;

                              case 21: obj = 13; break;
                              case 214: obj = 143; break;
                              case 215: obj = 153; break;
                              case 24: obj = 43; break;
                              case 241: obj = 413; break;
                              case 25: obj = 53; break;
                              case 251: obj = 513; break;
                              case 26: obj = 63; break;

                              case 4: obj = 43; break;
                              case 41: obj = 413; break;
                              case 42: obj = 43; break;
                              case 421: obj = 413; break;

                              case 5: obj = 53; break;
                              case 51: obj = 513; break;
                              case 512: obj = 513; break;
                              case 52: obj = 53; break;
                              case 521: obj = 513; break;

                              case 6: obj = 63; break;
                              case 62: obj = 63; break;
                              }
                              break;

                    case 3: crtLevel = 9; nurse = 1; break;

                    default: error = 1; break;
                    }

          }
          //Level 12: Laboratory
          while(crtLevel == 12){
                    inventory(keys, lab, books, scalpel, error, obj);
                    error = 0;
                    printf("You enter the laboratory and hear a voice booming:\n\"There is no pandemic! This was all a simulation, %s, and you've passed! The world can be safe with you!\"\n", name);


                    printf("1-Finish game!\n");
                    printf("2-Go back.\n");
                    choice = scanint();

                    switch(choice){
                    case 1: return 0;

                    case 2: crtLevel = 9; break;

                    default: error = 1; break;
                    }
          }
          }

}

