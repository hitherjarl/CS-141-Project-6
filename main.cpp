#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include<string>
using namespace std;
/*
 Program 6: Wumpus
 Author: Mohamed Imran Mohamed Siddique
 Machine: Mac/Xcode
 date: 04/21/16
 Lab: tue @ 9AM
 
       ______18_______
      /      |        \
     /      _9__       \
    /      /    \       \
   /      /      \       \
  17     8        10     19
  | \   / \      /  \   / |
  |  \ /   \    /    \ /  |
  |   7     1---2     11  |
  |   |    /     \    |   |
  |   6—---5     3---12   |
  |   |     \   /     |   |
  |   \       4      /    |
  |    \      |     /     |
  \     15---14---13     /
   \   /            \   /
    \ /              \ /
    16---------------20
 
 */



struct Node
{
    int caveNumber; // keeps track of which room it is
    int womp,bats,hole;
    Node* pathway1; // keeps track of first adjacent room
    Node* pathway2; // keeps track of 2nd adjacent room
    Node* pathway3; // keeps track of 3rd adjacent room
    
};
struct Undo
{
    int caveNumber; // keeps track of which room it is
    int womp,bats,hole;
    struct Node *next;
    
};

void placeWompus(Node *topNode){
    //Node *currNode = topNode;
    topNode->womp=1;

}
void placebats(Node *topNode){
    //Node *currNode = topNode;
    topNode->bats=1;
    
}
void placePits(Node *topNode){
    //Node *currNode = topNode;
    topNode->hole=1;
    
}






void printTraversalFromTop(Node *topNode, int count){
    
    
    
    Node *currNode = topNode;
    
    
    
    printf("%d. You are in room ", count);
    cout << currNode->caveNumber;
    printf(". Tunnels lead to");
    printf(" ");
    //print out adjacent cave #1
    topNode = currNode->pathway1;
    cout << topNode->caveNumber;
    printf(" ");
    //print out adjacent cave #2
    topNode = currNode->pathway2;
    cout << topNode->caveNumber;
    printf(" ");
    //print out adjacent cave #3
    topNode = currNode->pathway3;
    cout << topNode->caveNumber;
    printf(" ");
    
    if((currNode->pathway1->womp==1)||(currNode->pathway2->womp==1)||(currNode->pathway3->womp==1)){
        printf("\n   A smell");
    }
    if(currNode->womp==1){
    printf("\n   The Wompus has killed you.\n");
        exit(0);    }
    if((currNode->pathway1->bats==1)||(currNode->pathway2->bats==1)||(currNode->pathway3->bats==1)){
        printf("\n   A flapping sound");
    }
    if(currNode->bats==1){
        printf("\n   The bats have grabbed you\n");
        printf("\n   dropping you in a random cave\n");
        return;
    }
    if((currNode->pathway1->hole==1)||(currNode->pathway2->hole==1)||(currNode->pathway3->hole==1)){
        printf("\n   A draft");
    }
    if(currNode->hole==1){
        printf("\n   You've fallen in the pit\n");
        exit(0);
        
    }
    
    
    
    return;
    }

    //}

void placeRandomguy(Node *topNode, int count){
    
    // Prints the traversal from the top of the graph
    // The result of this traversal for the given example would be "works"
    
    
    Node *currNode = topNode;
    
    printf("%d. You are in room ", count);
    cout << currNode->caveNumber;
    printf(". Tunnels lead to");
    printf(" ");
    //print out adjacent cave #1
    topNode = currNode->pathway1;
    cout << topNode->caveNumber;
    printf(" ");
    //print out adjacent cave #2
    topNode = currNode->pathway2;
    cout << topNode->caveNumber;
    printf(" ");
    //print out adjacent cave #3
    topNode = currNode->pathway3;
    cout << topNode->caveNumber;
    printf(" ");
    
    
    
    return;
    
    
    
    
    
}



int main()
{
    int room;
    int room1, room2;
    int i;
    int randomCave;
    int randomCave1;
    int randomCave2;
    int randomCave3;
    int randomCave4;
    int randomCave5;
    int randomCave6;
    int randMove;
    int randWomp;
    char task;
    Node rooms[20];
    int go;

    int count=1;
    srand((unsigned int)time(NULL));

    
    for (i=0; i<=20; i++){
        rooms[i] = *new Node();
        rooms[i].caveNumber=i+1;
        rooms[i].womp=0;
        
    }
    

    // assign the adjacent rooms
    // cave 1
    rooms[0].pathway1=&rooms[1];
    rooms[0].pathway2=&rooms[4];
    rooms[0].pathway3=&rooms[7];
    // cave 2
    rooms[1].pathway1=&rooms[0];
    rooms[1].pathway2=&rooms[2];
    rooms[1].pathway3=&rooms[9];
    // cave 3
    rooms[2].pathway1=&rooms[1];
    rooms[2].pathway2=&rooms[3];
    rooms[2].pathway3=&rooms[11];
    // cave 4
    rooms[3].pathway1=&rooms[2];
    rooms[3].pathway2=&rooms[4];
    rooms[3].pathway3=&rooms[13];
    // cave 5
    rooms[4].pathway1=&rooms[0];
    rooms[4].pathway2=&rooms[3];
    rooms[4].pathway3=&rooms[5];
    // cave 6
    rooms[5].pathway1=&rooms[4];
    rooms[5].pathway2=&rooms[6];
    rooms[5].pathway3=&rooms[14];
    // cave 7
    rooms[6].pathway1=&rooms[5];
    rooms[6].pathway2=&rooms[7];
    rooms[6].pathway3=&rooms[16];
    // cave 8
    rooms[7].pathway1=&rooms[0];
    rooms[7].pathway2=&rooms[6];
    rooms[7].pathway3=&rooms[8];
    // cave 9
    rooms[8].pathway1=&rooms[7];
    rooms[8].pathway2=&rooms[9];
    rooms[8].pathway3=&rooms[17];
    // cave 10
    rooms[9].pathway1=&rooms[1];
    rooms[9].pathway2=&rooms[8];
    rooms[9].pathway3=&rooms[10];
    // cave 11
    rooms[10].pathway1=&rooms[9];
    rooms[10].pathway2=&rooms[11];
    rooms[10].pathway3=&rooms[18];
    // cave 12
    rooms[11].pathway1=&rooms[2];
    rooms[11].pathway2=&rooms[10];
    rooms[11].pathway3=&rooms[12];
    // cave 13
    rooms[12].pathway1=&rooms[11];
    rooms[12].pathway2=&rooms[13];
    rooms[12].pathway3=&rooms[19];
    // cave 14
    rooms[13].pathway1=&rooms[3];
    rooms[13].pathway2=&rooms[12];
    rooms[13].pathway3=&rooms[14];
    // cave 15
    rooms[14].pathway1=&rooms[5];
    rooms[14].pathway2=&rooms[13];
    rooms[14].pathway3=&rooms[15];
    // cave 16
    rooms[15].pathway1=&rooms[14];
    rooms[15].pathway2=&rooms[16];
    rooms[15].pathway3=&rooms[19];
    // cave 17
    rooms[16].pathway1=&rooms[6];
    rooms[16].pathway2=&rooms[15];
    rooms[16].pathway3=&rooms[17];
    // cave 18
    rooms[17].pathway1=&rooms[8];
    rooms[17].pathway2=&rooms[16];
    rooms[17].pathway3=&rooms[18];
    // cave 19
    rooms[18].pathway1=&rooms[10];
    rooms[18].pathway2=&rooms[17];
    rooms[18].pathway3=&rooms[19];
    // cave 20
    rooms[19].pathway1=&rooms[12];
    rooms[19].pathway2=&rooms[15];
    rooms[19].pathway3=&rooms[18];
    
    //-------beginnig of the program output------//
    
   
    //generates a random cave to place the wompus into
    randomCave1=rand()%20;
    placeWompus(&rooms[randomCave1]);
    //Generates two different random caves and places the superbats in there.
    randomCave2=rand()%20;
    placebats(&rooms[randomCave2]);
    randomCave3=rand()%20;
    placebats(&rooms[randomCave3]);
    //Generates two different random caves and places the pits in there.
    randomCave4=rand()%20;
    placePits(&rooms[randomCave4]);
    randomCave5=rand()%20;
    placePits(&rooms[randomCave5]);
    printf("Author: Mohamed Imran Mohamed Siddique \nCS 141 Program #6: Wumpus \nLab: T 9:00 AM    \nApril 21, 2016    \nSystem: XCode on Mac \n\n\n\n");
    

    
        count=1;
        //generates a random cave and sets the person in there
        randomCave=rand()%20;
        placeRandomguy(&rooms[randomCave], count);
        count=2;
    leap:
    printf("\nChoose the task || M for move || S for shoot || C for cheats || U to undo\n");
    scanf("%s", &task);
    
    if (task=='m' || task=='M'){
    while(go!=1){
    jump:
    printf("\n");
    printf("   ");
    printf("Your move: ");
    scanf("%d", &room);
    printf("\n\n");
        
        
    //if the room number input is less than 0 or greater than 21, the program exits
    while (room<=0 || room>=21){
        printf("   Try again\n ");
        printf("  Your move: ");
        scanf("%d", &room);
    }
    //CheckForDisplayedCaves(&rooms[room-1]);
    printTraversalFromTop(&rooms[room-1], count);
        
    //if you go to a cave with bats, they will move you to a random cave
    if(rooms[room-1].bats==1){
        randomCave6=rand()%20;
        printf("\n");
        printTraversalFromTop(&rooms[randomCave6], count+1);
        randomCave2=rand()%20;
        placebats(&rooms[randomCave2]);
        randomCave3=rand()%20;
        placebats(&rooms[randomCave3]);
    }
    
    count++;
        

        
        
     
    


        cout << "\n";
        goto leap;
        }
        }
    
        else if ((task=='s') || (task=='S') ){
            printf("Enter caves: ");
            scanf("%d %d %d" ,&room, &room1, &room2);
            if (rooms[room-1].womp==1){
                printf("Wumpus just got whomped. You win!\n");
            }
            else if (rooms[room1-1].womp==1){
                printf("Wumpus just got whomped. You win!\n");
            }
            else if (rooms[room2-1].womp==1){
                printf("Wumpus just got whomped. You win!\n");
            }
            else{
                //75% moves and 25% satys and kills you
                randMove=rand()%100+1;
                if ((randMove >= 0 ) && (randMove<=75)){
                    randWomp=rand()%20;
                    placeWompus(&rooms[randWomp]);
                    printf("%d. Wumpus has moved.\n", count);
                    count=count+1;
                    
                    goto leap;
                    return count;
                }else {printf("Wumpus has killed you");}
            }
            
            
        }

    
    
    
    else if (task=='c' || task=='C'){
        printf("The count is: %d\n", count);
        //displays the cave that the wompus is in
        printf("The Wumpus is in cave: ");
        cout << rooms[randomCave1].caveNumber;
        printf("\n");
        //displays the cave that the superbats are located at
        printf("The super-bats are in cave: ");
        cout << rooms[randomCave2].caveNumber;
        printf(" ");
        cout << rooms[randomCave3].caveNumber;
        printf("\n");
        //displays the cave that the pits are located at
        printf("The pits are in cave: ");
        cout << rooms[randomCave4].caveNumber;
        printf(" ");
        cout << rooms[randomCave5].caveNumber;
        printf("\n");
        goto leap;
        
    }
    else if (task=='u' || task=='U'){
        if(count==2){
            printf("you cannot undo at the first move");
        }

        goto leap;
        
    }
    exit(0);

}