#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[50];
  char firstPlaceRaceCarColor[20];
};
struct RaceCar {
  char driverName[50];
  char raceCarColor[20];
  int totalLapTime;
};
// Print functions section
void printIntro(){
  printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");
};

void printCountDown(){
  printf("Racers Ready! In...\n");
  for (int i=5; i > 0; i--) {
    printf("%d\n", i);
  }
};

void printFirstPlaceAfterLap(struct Race race){
  printf("After lap %d\nFirst Place is: %s in the %s race car!\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
};

void printCongratulation(struct Race race){
  printf("Let's all congratulate %s in the %s race car for an amazing performance!/n It truly was a great race and everybody have a good night!", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
};

// Logic functions section
int calculateTimeToCompleteLap(){
  int speed;
  int acceleration;
  int nerves;

  speed = rand() % (3 + 1 - 1) + 0;
  acceleration =  rand() % (3 + 1 - 1) + 0;
  nerves = rand() % (3 + 1 - 1) + 0;

  return speed + acceleration + nerves;
};

void updateRaceCar(struct RaceCar *raceCar){
  raceCar ->totalLapTime = calculateTimeToCompleteLap();
};

void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2){
  if (raceCar1 ->totalLapTime <= raceCar2 ->totalLapTime){
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race ->firstPlaceRaceCarColor, raceCar1 ->raceCarColor);
  } else {
    strcpy(race ->firstPlaceDriverName, raceCar2 ->driverName);
    strcpy(race ->firstPlaceRaceCarColor, raceCar2 ->raceCarColor);
  };
};

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2){
  struct Race race = {5, 1,"",""};
  for (int i=0; i < race.numberOfLaps; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap += 1;
  };
  printf("Congratulations to our first place winner %s!", race.firstPlaceDriverName);
};

int main() {
	srand(time(0));
  struct RaceCar raceCar = {"Charlie", "Blue", 0};
  struct RaceCar raceCar2 = {"Monica", "Red", 0};
  printIntro();
  printCountDown();
  startRace(&raceCar, &raceCar2);
};
