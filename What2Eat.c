#include <stdio.h>

int people;
int threshold;
int foodCount = 5;

int findMaxValue(int points[5][2]) {
    int count = 0;
    int max = points[0][1];
    for (int i = 1; i < 5; ++i) {
        if (points[i][1] > max){
            max = points[i][1];
            count++;
        }
    }
    return (count +1);
}

void calculatePoint(int peoplePreferences[people][foodCount], int points[foodCount][2] ){

    for(int i = 0; i < people; ++i){

        for(int j = 0; j < foodCount; ++j ){

            if(peoplePreferences[i][j] == 1){

                points[0][1] += 5-j;
            }
            if(peoplePreferences[i][j] == 2){
                points[1][1] += 5-j;
            }
            if(peoplePreferences[i][j] == 3){
                points[2][1] += 5-j;
            }
            if(peoplePreferences[i][j] == 4){
                points[3][1] += 5-j;
            }
            if(peoplePreferences[i][j] == 5){
                points[4][1] += 5-j;
            }
        }
    }
}
void Preference(int peoplePreferences[people][foodCount]){
    for(int i = 0; i < people; ++i){
        printf("There are 5 choices 1-Kebab,  2-Burger,  3-Pasta,  4-Lahmacun,  5-Salad please write the numbers for your preference.\n");
        printf("%d. people's preference \n", i+1);

        for(int j = 0; j<foodCount; ++j ){
            printf("Write your %d.food number\n ", j+1);
            scanf("%d", &peoplePreferences[i][j]);
        }
    }
}
int main()
{
    printf("Hello this is What2Eat game please write how many people joining the game\n");
    scanf("%d", &people);
    threshold =  people*3;
    int peoplePreferences [people] [foodCount];
    int points [foodCount] [2];
    int aboveThreshold [foodCount][2];


    Preference(peoplePreferences);

    //initial points

    for(int i = 0; i < foodCount; ++i){

        points[i][0] = i+1;
    }
    for(int i = 0; i < foodCount; ++i){

        points[i][1] = 0;
    }

    calculatePoint(peoplePreferences,points);

    //aboveThreshold
    for(int i = 0; i < foodCount; ++i){

        aboveThreshold[i][0] = i+1;
    }
    for(int i = 0; i < foodCount; ++i){

        aboveThreshold[i][1] = 0;
    }

    int count = 0;


    for(int i = 0; i < foodCount; ++i){


        if(points[i][1] > threshold){
            aboveThreshold[i][1] = points[i][1] > threshold;
            count++;
        }
    }
    foodCount = count;

    // round2
    if(foodCount != 0){
        printf("We are starting now round 2 write your number of preference of foods which are above threshold \n");
        printf("Food Number        aboveThreshold \n" );
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 2; ++j ){
                printf("%d                ",aboveThreshold[i][j]);
            }
            printf("\n");
        }

        Preference(peoplePreferences);

        calculatePoint(peoplePreferences,points);

        printf("1-Kebab,  2-Burger,  3-Pasta,  4-Lahmacun,  5-Salad.\n");
        for(int i = 0; i < 5; ++i){


            for(int j = 0; j<2; ++j ){

                printf("%d ,",points[i][j]);

            }
            printf("\n");
        }

        printf("1-Kebab,  2-Burger,  3-Pasta,  4-Lahmacun,  5-Salad.\n");
        printf("You ordered %d \n",findMaxValue(points));

    }
    else
        printf("You are eating at home/dormtoday!");

    return 0;
}




