#include <stdio.h>

void towerofhanoi(int disk, char source, char dest, char aux) {
    if (disk == 1)
        printf("Move disk 1 from %c to %c\n", source, dest);
    else {
        towerofhanoi(disk - 1, source, aux, dest);
        printf("Move disk %d from %c to %c\n", disk, source, dest);
        towerofhanoi(disk - 1, aux, dest, source);
    }
}

int main() {
    int disk;//3
    printf("Enter the number of disks: ");
    scanf("%d", &disk);

    towerofhanoi(disk, 'A', 'C', 'B');
    return 0;
}
