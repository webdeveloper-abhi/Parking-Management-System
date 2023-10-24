//                                                       CAR PARKING SYSTEM

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int earning = 0;

struct VehicleInfo {
    char Ownername[20];
    char vehicleNumber[30];
    char date[20];
    int vehicleType; // 1 for Car, 2 for Bike, 3 for Bus, 4 for Auto
};

struct Node {
    struct VehicleInfo data;
    struct Node* next;
};

struct Node* head = NULL; // Initialize the linked list

void displayParkingInformation() {
    printf("************Welcome to Abhijeet Parking Stand**********\n\n");
    printf("This is the Parking Rate of an hour:\n");
    printf("Car fees: 50?              Bike fees: 20?\n");
    printf("Bus fees: 80?              Auto fees: 15?\n\n");
}

void parkVehicle() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    
    printf("Select vehicle type (1 for Car, 2 for Bike, 3 for Bus, 4 for Auto): ");
    scanf("%d", &newNode->data.vehicleType);

    printf("\nFill the information to Park the Vehicle\n");
    printf("Owner name: ");
    scanf("%s", newNode->data.Ownername);
    printf("Enter Vehicle Number: ");
    scanf("%s", newNode->data.vehicleNumber);
    printf("Enter Date: ");
    scanf("%s", newNode->data.date);
 
    switch (newNode->data.vehicleType) {
        case 1:
            earning += 50;
            break;
        case 2:
            earning += 20;
            break;
        case 3:
            earning += 80;
            break;
        case 4:
            earning += 15;
            break;
        default:
            printf("Invalid vehicle type\n");
            return;
    }

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Vehicle parked successfully.\n");
}

void removeParking() {
    if (head == NULL) {
        printf("No vehicles in the parking lot.\n");
        return;
    }

    char ownername[20], vehiclenumber[30];
    printf("Owner name: ");
    scanf("%s", ownername);
    printf("Vehicle Number: ");
    scanf("%s", vehiclenumber);

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data.Ownername, ownername) == 0 && strcmp(current->data.vehicleNumber, vehiclenumber) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            
            free(current);
            printf("Vehicle removed successfully.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Vehicle not found in the parking lot.\n");
}

void displayParkedVehicles() {
    if (head == NULL) {
        printf("No vehicles in the parking lot.\n");
        return;
    }

    printf("Parked Vehicles:\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("Owner: %s, Vehicle Number: %s, Date: %s\n", current->data.Ownername, current->data.vehicleNumber, current->data.date);
        current = current->next;
    }
}

void checkEarning() {
    printf("\nTotal Earnings: %d?\n", earning);
}

int main() {
    displayParkingInformation();
    int choice;

    while (1) {
        printf("Select Option:\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Parked Vehicles\n");
        printf("4. Check Earnings\n");
        printf("5. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                parkVehicle();
                break;
            case 2:
                removeParking();
                break;
            case 3:
                displayParkedVehicles();
                break;
            case 4:
                checkEarning();
                break;
            case 5:
                printf("Thank you for visiting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

