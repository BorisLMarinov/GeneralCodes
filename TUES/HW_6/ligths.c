#include <stdio.h>

void switchLights(unsigned char *state, int room) {
    if (room < 1 || room > 8) {
        printf("Invalid room number\n");
        return;
    }

    *state ^= (1 << (room - 1));
}

void printState(unsigned char state) {
    printf("The light is on in rooms:");

    for (int i = 0; i < 8; ++i) {
        if (state & (1 << i)) {
            printf(" %d,", i + 1);
        }
    }

    printf("\n");
}

int main() {
    unsigned char lightState = 0;

    while (1) {        
        int choice;
        printf("1.Turn light on/off\n2.Print lights states\n3.Exit");
        scanf("Choose operation: %d", &choice);

        switch (choice) {
            case 1:
                int room;
                scanf("%d", &room);
                switchLights(&lightState, room);
                break;

            case 2:
                printState(lightState);
                break;

            case 0:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
