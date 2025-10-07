#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    char description[256];
    struct Node* choice1;
    struct Node* choice2;
    struct Node* choice3;
    int visited;
} scene;

scene* array[100]; //scene

#define NUM_SCENES 24
#define MAX_TEXT 2000

char arr[NUM_SCENES][MAX_TEXT] = {
    "Shadows over Anthea\nAnthea is a vibrant, bustling city with a rich history. Queen Anthea rules with wisdom, but now a dangerous secret group called The Shadows is plotting to take over. The city is safety depends on two brave soldiers - Valkyrie and Orion - who must uncover and stop these threats. Are you ready to begin your adventure?\nContinue\nExit",
    
    "Character Selection\nChoose your hero:\n1. Valkyrie - A fearless soldier with sharp mind and combat skills.\n2. Orion - A calm strategist and expert fighter.\nValkyrie\nOrion",
    
    "The Queen's Warning\nThe Queen has sent an urgent message. The Shadows plan to strike soon. Where do you want to start investigating?\n1. Old warehouse - Suspected hideout.\n2. City guards - Gather intelligence.",
    
    "Hidden Warehouse\nThe warehouse looks abandoned but might hide important clues.\n1. Search quietly for evidence.\n2. Set a trap and wait.",
    
    "Guards' Report\nA guard whispers that there might be a traitor working with The Shadows.\n1. Question the suspect directly.\n2. Follow the suspect secretly.",
    
    "Underground Tunnels\nThe tunnels are dark and filled with traps and enemies.\n1. Proceed carefully and look for signs.\n2. Light a fire to see better.",
    
    "The Evidence\nYou find clues pointing toward an impending attack.\n1. Alert the city guards.\n2. Search for the enemy's plan.",
    
    "Waiting Trap\nHours pass and no one appears. Your patience is tested.\n1. Keep waiting.\n2. Leave and report to the Queen.",
    
    "Direct Confrontation\nThe suspect is nervous but denies everything.\n1. Press for answers.\n2. Let go and watch.",
    
    "Secret Surveillance\nThe suspect leads you to a secret meeting of The Shadows.\n1. Interrupt now.\n2. Report and wait for backup.",
    
    "Careful Search\nYou find signs of recent activity in the tunnels.\n1. Follow the signs.\n2. Report to the Queen.",
    
    "Fire for Vision\nFire reveals enemies nearby. Battle is inevitable.\n1. Fight.\n2. Escape to regroup.",
    
    "Final Alert and Defense\nYou alert the city and prepare for battle as The Shadows advance.\n1. Lead the defense.\n2. Prepare a tactical retreat.",
    
    "Enemy's Plan\nYou uncover The Shadows' attack plan with times and locations.\n1. Intercept attackers early.\n2. Bolster city defenses.",
    
    "Confront The Shadows' Leader\nYou face the enemy leader in a decisive clash.\n1. Fight till end.\n2. Attempt negotiation.",
    
    "Victory or Loss\nThe clash with The Shadows reaches its peak. Your leadership has led to a fierce battle deciding the fate of Anthea.\n1. Celebrate the victory with your allies.\n2. Mourn the losses and vow to rebuild stronger.",
    
    "Tactical Retreat\nYou strategically retreat to save your people and gather strength for the next fight.\n1. Plan a counterattack.\n2. Seek allies in distant lands.",
    
    "Plan Counterattack\nYou mobilize your troops and plot a surprise strike against The Shadows.\n1. Launch the attack at dawn.\n2. Gather more intelligence before attacking.",
    
    "Seek Allies\nYour journey to find new allies brings you to ancient mountain tribes and mystical kingdoms willing to aid your cause.\n1. Visit the mountain tribes.\n2. Petition the Kingdom of Eldoria.",
    
    "Victory Celebration\nThe city of Anthea erupts in joy and celebration. Your bravery has restored peace.\n1. Restart adventure.\n2. Exit.",
    
    "Rebuild and Reflect\nThough the battle was costly, your leadership inspires hope. Together, Anthea begins healing and rebuilding.\n1. Restart.\n2. Exit.",
    
    "Intelligence Gathering\nYou gather new intelligence revealing weaknesses in The Shadows' plan.\n1. Move swiftly to attack.\n2. Strengthen defenses.",
    
    "Mountain Tribes\nThe mountain tribes welcome you as an ally. Their fierce warriors pledge loyalty.\n1. The story ends here with their support securing Anthea's safety.\n2. Restart or exit.",
    
    "Kingdom of Eldoria\nThe mystical kingdom of Eldoria grants your request for magical assistance.\n1. The story ends here with Eldoria's magical alliance ensuring hope.\n2. Restart or exit."
};

int n = 40; // No of scenes

 scene* create() {
    scene* temp;

    // Allocate and initialize
    for (int i = 0; i < NUM_SCENES; i++) {
        temp = (scene*)malloc(sizeof(scene));
        if (!temp) {
            fprintf(stderr, "malloc failed at scene %d\n", i);
            exit(EXIT_FAILURE);
        }
        // safe copy, ensure null-termination
        strncpy(temp->description, arr[i], sizeof(temp->description) - 1);
        temp->description[sizeof(temp->description) - 1] = '\0';

        // initialize pointers to NULL to avoid garbage
        temp->choice1 = NULL;
        temp->choice2 = NULL;
        temp->choice3 = NULL;
        temp->visited = 0;
        array[i] = temp;
    }

    // Now set up the pointers (unchanged except removing the self-loop)
    array[0]->choice1 = array[1];
    array[0]->choice2 = NULL;

    array[1]->choice1 = array[2];
    array[1]->choice2 = array[2];

    array[2]->choice1 = array[3];
    array[2]->choice2 = array[4];
    array[2]->choice3 = array[5];

    array[3]->choice1 = array[6];
    array[3]->choice2 = array[7];

    array[4]->choice1 = array[8];
    array[4]->choice2 = array[9];

    array[5]->choice1 = array[10];
    array[5]->choice2 = array[11];

    array[6]->choice1 = array[12];
    array[6]->choice2 = array[13];

    // --- Fix: avoid self-loop here. Point to scene 2 (Queen's Warning) or another scene.
    array[7]->choice1 = array[2];  // was array[7] -> caused infinite loop when chosen
    array[7]->choice2 = array[2];

    array[8]->choice1 = array[12];
    array[8]->choice2 = array[9];

    array[9]->choice1 = array[14];
    array[9]->choice2 = array[12];

    array[10]->choice1 = array[9];
    array[10]->choice2 = array[2];

    array[11]->choice1 = array[15];
    array[11]->choice2 = array[16];

    array[12]->choice1 = array[15];
    array[12]->choice2 = array[16];

    array[13]->choice1 = array[15];
    array[13]->choice2 = array[16];

    array[14]->choice1 = array[15];
    array[14]->choice2 = array[16];

    array[15]->choice1 = array[19];
    array[15]->choice2 = array[20];

    array[16]->choice1 = array[17];
    array[16]->choice2 = array[18];

    array[17]->choice1 = array[15];
    array[17]->choice2 = array[21];

    array[18]->choice1 = array[22];
    array[18]->choice2 = array[23];

    array[19]->choice1 = array[0];
    array[19]->choice2 = NULL;

    array[20]->choice1 = array[0];
    array[20]->choice2 = NULL;

    array[21]->choice1 = array[15];
    array[21]->choice2 = array[20];

    array[22]->choice1 = array[19];
    array[22]->choice2 = NULL;

    array[23]->choice1 = array[19];
    array[23]->choice2 = NULL;

    return array[0];
}
